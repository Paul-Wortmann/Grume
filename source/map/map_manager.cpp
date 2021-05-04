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
    
    cXML xmlFile;
    xmlFile.load(FILE_PATH_MAP + _fileName);
    if (xmlFile.lineCount() > 0)
    {
        gLogWrite(LOG_INFO, "Loading map: " + xmlFile.getString("<name>"), __FILE__, __LINE__, __FUNCTION__);

        // Get the data from the XML file
        std::string name         = xmlFile.getString("<name>");
        uint32      width        = xmlFile.getInteger("<width>");
        uint32      height       = xmlFile.getInteger("<height>");
        std::string biomeFile    = xmlFile.getString("<biome>");
        uint32      generate     = xmlFile.getInteger("<generate>");
        uint32      seed         = xmlFile.getInteger("<seed>");
        uint32      algorithm    = xmlFile.getInteger("<algorithm>");
        uint32      wall_width   = xmlFile.getInteger("<wall_width>");

        uint32      player_tile  = xmlFile.getInteger("<player_start_tile>");
        uint32      player_rot   = xmlFile.getFloat("<player_start_rotation>");

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
            uint32 tilesInstanceCount = xmlFile.getInstanceCount("<tiles>");
            for (uint32 i = 0; i < tilesInstanceCount; ++i)
            {
                tiles += xmlFile.getString("<tiles>", i + 1);
                tiles += " ";
            }

            // Save the loaded tile data into the map data structure
            uint32 tileNum = 0;
            for (uint32 i = 0; i < tiles.size(); ++i)
            {
                switch (tiles[i])
                {
                    // Liquid
                    case '7':
                        m_currentMap->tile[tileNum].base = eTileBase::tileLiquid;
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
            std::string xmlKey = "<" + m_currentMap->biome->MusicTag.name + "_entity>";
            if (xmlMusicFile.lineCount() > 0)
            {
                std::uint32_t trackCount = xmlMusicFile.getInstanceCount(xmlKey);
                m_mapMusic = xmlMusicFile.getString(xmlKey, (rand() % trackCount) + 1);
            }
            xmlMusicFile.free();
        }

        // Populate the map with walls
        m_addWallEntities(m_currentMap);

        // Populate the map with objects
        m_addObjectEntities(m_currentMap);

        // Populate the map with NPCs
        m_addNPCEntities(m_currentMap);

        // Clean up
        xmlFile.free();
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
