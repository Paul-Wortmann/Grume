/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"

void cMapManager::initialize(cEntityManager* _entityManager)
{
    entityManager = _entityManager;
    biomeManager.initialize(entityManager);
}

void cMapManager::terminate(void)
{
    biomeManager.terminate();
    m_freeAll();
}

void cMapManager::m_freeData(sMap*& _map)
{
    // Return if nullptr
    if (_map == nullptr)
    {
        return;
    }
    
    // Delete tile data
    if ((_map->tile != nullptr) && (_map->numTiles != 0))
    { 
        delete [] _map->tile;
        _map->tile = nullptr;
        _map->numTiles = 0;
    }
    
    // Delete floor model data
    if (_map->floor != nullptr)
    {
        // Cleanup previous floor model data
        if (_map->floor->model != nullptr)
        {
            if (_map->floor->model->mesh != nullptr)
            {
                for (std::uint32_t i = 0; i < _map->floor->model->numMesh; ++i)
                {
                    // Cleanup vertex data
                    if (_map->floor->model->mesh[i].vertex != nullptr)
                    {
                        delete [] _map->floor->model->mesh[i].vertex;
                        _map->floor->model->mesh[i].vertex = nullptr;
                    }
                    
                    // Cleanup index data
                    if (_map->floor->model->mesh[i].index != nullptr)
                    {
                        delete [] _map->floor->model->mesh[i].index;
                        _map->floor->model->mesh[i].index = nullptr;
                    }
                    
                }

                // Cleanup mesh data
                delete [] _map->floor->model->mesh;
                _map->floor->model->mesh = nullptr;
            }
        }
    }
    
    // Delete event data
    if (_map->event != nullptr)
    { 
        delete [] _map->event;
        _map->event = nullptr;
        _map->eventCount = 0;
    }    
    // Delete portal data
    if ((_map->tile != nullptr) && (_map->numTiles != 0))
    { 
        delete [] _map->portal;
        _map->portal = nullptr;
        _map->portalCount = 0;
    }
    
}

void cMapManager::m_freeAll(void)
{
    for (sMap* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

void cMapManager::load(const std::string &_fileName)
{
    // Only load a map if it is not already loaded
    // Unload the current map is need be
    if (m_currentMap != nullptr)
    {
        if (m_currentMap->fileName.compare(_fileName) == 0)
        {
            return;
        }
        unload();
    }
    
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _fileName);
    if (xmlMapFile.lineCount() > 0)
    {
        gLogWrite(LOG_INFO, "Loading map: " + xmlMapFile.getString("<name>"), __FILE__, __LINE__, __FUNCTION__);

        // Get the data from the XML file
        std::string name         = xmlMapFile.getString("<name>");
        uint32      width        = xmlMapFile.getInteger("<width>");
        uint32      height       = xmlMapFile.getInteger("<height>");
        std::string biomeFile    = xmlMapFile.getString("<biome>");
        uint32      generate     = xmlMapFile.getInteger("<generate>");
        uint32      seed         = xmlMapFile.getInteger("<seed>");
        uint32      algorithm    = xmlMapFile.getInteger("<algorithm>");
        uint32      wall_width   = xmlMapFile.getInteger("<wall_width>");

        uint32      player_tile  = xmlMapFile.getInteger("<player_start_tile>");
        uint32      player_rot   = xmlMapFile.getFloat("<player_start_rotation>");

        // Create and populate the map data structure with the loaded XML data
        if (m_currentMap == nullptr)
        {
            m_currentMap         = getNew();
        }
        
        // Generate tiles
        m_currentMap->fileName          = _fileName;
        m_currentMap->name              = name;
        m_currentMap->width             = width;
        m_currentMap->height            = height;
        m_currentMap->numTiles          = m_currentMap->width * m_currentMap->height;
        m_currentMap->tile              = new sMapTile[m_currentMap->numTiles];
        m_currentMap->playerStartTile   = player_tile;
        m_currentMap->playerStartDir    = player_rot;

        // Map generation data
        m_currentMap->genData.seed      = seed;
        m_currentMap->genData.algorithm = algorithm;
        m_currentMap->genData.wallSize  = wall_width;


        std::string tiles = "";
        // Generate tiles
        if (generate > 0)
        {
            tiles = "";
            generateMap(m_currentMap);
            for (uint32 i = 0; i < m_currentMap->numTiles; ++i)
            {
                tiles += std::to_string(static_cast<uint32>(m_currentMap->tile[i].base));
                tiles += " ";
            }
            tiles += "0";
            //std::cout << tiles << std::endl;
        }
        else
        {
            // Load tile data from file
            uint32 tilesInstanceCount = xmlMapFile.getInstanceCount("<tiles>");
            for (uint32 i = 0; i < tilesInstanceCount; ++i)
            {
                tiles += xmlMapFile.getString("<tiles>", i + 1);
                tiles += " ";
            }

            // Save the loaded tile data into the map data structure
            uint32 tileNum = 0;
            for (uint32 i = 0; i < tiles.size(); ++i)
            {
                switch (tiles[i])
                {
                    // Liquid
                    case '8':
                        m_currentMap->tile[tileNum].base = eTileBase::tileLiquid;
                        tileNum++;
                    break;
                    // Path (inaccessable, such as under buildings)
                    case '7':
                        m_currentMap->tile[tileNum].base = eTileBase::tilePathNoGo;
                        tileNum++;
                    break;
                    // Floor (inaccessable, such as under buildings)
                    case '6':
                        m_currentMap->tile[tileNum].base = eTileBase::tileFloorNoGo;
                        tileNum++;
                    break;
                    // Path
                    case '5':
                        m_currentMap->tile[tileNum].base = eTileBase::tileFloorPath;
                        tileNum++;
                    break;
                    // Wall - Short
                    case '4':
                        m_currentMap->tile[tileNum].base = eTileBase::tileWallShort;
                        tileNum++;
                    break;
                    // Doorway
                    case '3':
                        m_currentMap->tile[tileNum].base = eTileBase::tileDoorway;
                        tileNum++;
                    break;
                    // Wall
                    case '2':
                        m_currentMap->tile[tileNum].base = eTileBase::tileWall;
                        tileNum++;
                    break;
                    // Floor
                    case '1':
                        m_currentMap->tile[tileNum].base = eTileBase::tileFloor;
                        tileNum++;
                    break;
                    // None 
                    case '0':
                        m_currentMap->tile[tileNum].base = eTileBase::tileNone;
                        tileNum++;
                    break;
                    default:
                    break;
                }
            }
        }

        // Generate floor model
        m_currentMap->floor        = entityManager->getNew();
        m_currentMap->floor->name  = "Generated map floor.";
        m_currentMap->floor->owner = eEntityOwner::ownerMap;
        m_currentMap->floor->model = m_generateFloor(m_currentMap);

        // Create a model matrix
        m_currentMap->floor->position = glm::vec3(0.0f, 0.0f, 0.0f);
        m_currentMap->floor->scale    = glm::vec3(1.0f, 1.0f, 1.0f);
        m_currentMap->floor->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        entityManager->updateModelMatrix(m_currentMap->floor);

        // Load the biome from file
        if (biomeFile.length() > 3)
        {
            m_currentMap->biome = biomeManager.load(biomeFile);
        }

        // Load the material defined in the previously loaded biome
        if (m_currentMap->biome->floorSpritesheet.fileName.length() > 3)
        {
            m_currentMap->floor->material = entityManager->loadMaterial(m_currentMap->biome->floorSpritesheet.fileName);
        }

        // Load the music defined in the previously loaded biome
        if (m_currentMap->biome->MusicSet.fileName.length() > 3)
        {
            cXML xmlMusicFile;
            xmlMusicFile.load(FILE_PATH_BIOME + m_currentMap->biome->MusicSet.fileName);
            std::string   xmlKey = "<" + m_currentMap->biome->MusicTag.name + "_entity>";
            if (xmlMusicFile.lineCount() > 0)
            {
                std::uint32_t trackCount = xmlMusicFile.getInstanceCount(xmlKey);
                if (m_currentMap->biome->MusicTrack.no == 0)
                {
                    m_mapMusic = xmlMusicFile.getString(xmlKey, (rand() % trackCount) + 1);
                }
                else
                {
                    m_mapMusic = xmlMusicFile.getString(xmlKey, m_currentMap->biome->MusicTrack.no);
                }
            }
            xmlMusicFile.free();
        }

        // Load map event data
        m_currentMap->eventCount = xmlMapFile.getInstanceCount("<event>");
        m_currentMap->event = new sMapEvent[m_currentMap->eventCount];
        for (uint32 i = 0; i < m_currentMap->eventCount; ++i)
        {
            // Load the data from the map file
            std::string tEventString = xmlMapFile.getString("<event>", i + 1);
            tEventString += "    ";
            std::uint32_t tEventStringLength = tEventString.length();
            std::uint32_t tEventTileNum = 0;
            std::uint32_t tEventType    = 0;
            std::uint32_t tEventData1   = 0;
            std::uint32_t tEventData2   = 0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tEventStringLength > 6)
            {
                for (std::uint32_t j = 0; j < tEventStringLength; ++j)
                {
                    if (tEventString[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tEventTileNum = std::stoi(tString);
                        }
                        else if (tStringNum == 1)
                        {
                            tEventType = std::stoi(tString);
                        }
                        else if (tStringNum == 2)
                        {
                            tEventData1 = std::stoi(tString);
                        }
                        else if (tStringNum == 3)
                        {
                            tEventData2 = std::stoi(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tEventString[j];
                    }
                }
            }
            
            // Process the event data
            switch (tEventType)
            {
                // Warp to map + portal
                case '1':
                    m_currentMap->event[i].type   = eMapEventType::eventTypeWarp;
                break;
                // None 
                case '0':
                default:
                    m_currentMap->event[i].type = eMapEventType::eventTypeNone;
                break;
            }
            m_currentMap->event[i].tile   = tEventTileNum;
            m_currentMap->event[i].data_1 = tEventData1;
            m_currentMap->event[i].data_2 = tEventData2;
        }
        
        // Load map portal data
        m_currentMap->portalCount = xmlMapFile.getInstanceCount("<portal>");
        m_currentMap->portal = new sMapPortal[m_currentMap->portalCount];
        for (uint32 i = 0; i < m_currentMap->portalCount; ++i)
        {
            // Load the data from the map file
            std::string tPortalString = xmlMapFile.getString("<event>", i + 1);
            tPortalString += "    ";
            std::uint32_t tPortalStringLength = tPortalString.length();
            std::uint32_t tPortalNumber    = 0;
            std::uint32_t tPortalTileNum   = 0;
            std::uint32_t tPortalDirection = 0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tPortalStringLength > 6)
            {
                for (std::uint32_t j = 0; j < tPortalStringLength; ++j)
                {
                    if (tPortalString[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tPortalNumber = std::stoi(tString);
                        }
                        else if (tStringNum == 1)
                        {
                            tPortalTileNum = std::stoi(tString);
                        }
                        else if (tStringNum == 2)
                        {
                            tPortalDirection = std::stof(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tPortalString[j];
                    }
                }
            }
            
            // Process the portal data
            m_currentMap->portal[i].portalNo  = tPortalNumber;
            m_currentMap->portal[i].tile      = tPortalTileNum;
            m_currentMap->portal[i].direction = tPortalDirection;
        }
        
        // Populate the map with walls
        m_addWallEntities(m_currentMap);

        // Populate the map with objects
        m_addObjectEntities(m_currentMap);

        // Populate the map with NPCs
        m_addNPCEntities(m_currentMap);

        // Clean up
        xmlMapFile.free();
    }
}

void  cMapManager::unload(void)
{
    // If nullptr return
    if (m_currentMap == nullptr)
    {
        return;
    }
    
    // Free the map and its data
    m_freeData(m_currentMap);
    m_currentMap->name = "";
    m_currentMap->fileName = "";
    entityManager->removeModel(m_currentMap->floor->model);
    
    // Free all entities asociated with the map
    for (sEntity* entity = entityManager->getHead(); entity != nullptr; entity = entity->next)
    {
        if (entity->owner == eEntityOwner::ownerMap)
        {
            entityManager->remove(entity);
            entity = entityManager->getHead();
        }
    }
}
