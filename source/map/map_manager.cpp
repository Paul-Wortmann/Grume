/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
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
    m_entityManager = _entityManager;
    m_biomeManager.initialize(m_entityManager);

    // Create a new empty map data structure
    if (m_currentMap == nullptr)
    {
        m_currentMap = getNew();
    }
}

void cMapManager::terminate(void)
{
    m_biomeManager.terminate();
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
    if (_map->portal != nullptr)
    { 
        delete [] _map->portal;
        _map->portal = nullptr;
        _map->portalCount = 0;
    }
    
    // Delete room data
    if (_map->room != nullptr)
    { 
        delete [] _map->room;
        _map->room = nullptr;
        _map->roomCount = 0;
    }
    
    // Delete object data
    if (_map->object != nullptr)
    { 
        delete [] _map->object;
        _map->object = nullptr;
        _map->objectCount = 0;
    }
    
    // Delete debris data
    if (_map->debris != nullptr)
    { 
        delete [] _map->debris;
        _map->debris = nullptr;
        _map->debrisCount = 0;
    }
    
    // Delete npcMob data
    if (_map->npcMob != nullptr)
    { 
        delete [] _map->npcMob;
        _map->npcMob = nullptr;
        _map->npcMobCount = 0;
    }
    
    // Delete npc data
    if (_map->npc != nullptr)
    { 
        delete [] _map->npc;
        _map->npc = nullptr;
        _map->npcCount = 0;
    }
}

void cMapManager::m_freeAll(void)
{
    for (sMap* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

void cMapManager::load(const std::string &_fileName)
{
    // Disable loading screen
    m_loadRequest = false;

    // Only load a map if it is not already loaded
    // Unload the current map if need be
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
        std::string name               = xmlMapFile.getString("<name>");
        std::uint32_t      width       = xmlMapFile.getInteger("<width>");
        std::uint32_t      height      = xmlMapFile.getInteger("<height>");
        std::string        biomeFile   = xmlMapFile.getString("<biome>");
        std::uint32_t      generate    = xmlMapFile.getInteger("<generate>");
        std::uint32_t      seed        = xmlMapFile.getInteger("<seed>");
        std::uint32_t      algorithm   = xmlMapFile.getInteger("<algorithm>");
        std::uint32_t      wall_width  = xmlMapFile.getInteger("<wall_width>");

        std::uint32_t      player_tile = xmlMapFile.getInteger("<player_start_tile>");
        float32            player_rot  = xmlMapFile.getFloat("<player_start_rotation>");

        // Create and populate the map data structure with the loaded XML data
        if (m_currentMap == nullptr)
        {
            m_currentMap = getNew();
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
        m_currentMap->genData.generate  = (generate > 0);
        m_currentMap->genData.algorithm = static_cast<eAlgorithm>(algorithm);
        m_currentMap->genData.seed      = seed;
        m_currentMap->genData.wallSize  = wall_width;

        // If a seed already exists for the map, use it instead
        std::map<std::string, std::uint32_t>::iterator it;
        it = mapList.find(m_currentMap->name);
        if (it != mapList.end())
        {
            m_currentMap->genData.seed = mapList[m_currentMap->name];
        }
        
        // Load the biome from file
        if (biomeFile.length() > 3)
        {
            m_currentMap->biome = m_biomeManager.load(biomeFile);
        }

        std::string tiles = "";
        // Generate tiles
        if (generate > 0)
        {
            tiles = "";
            generateMap(m_currentMap);
            for (std::uint32_t i = 0; i < m_currentMap->numTiles; ++i)
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
            std::uint32_t tilesInstanceCount = xmlMapFile.getInstanceCount("<tiles>");
            for (std::uint32_t i = 0; i < tilesInstanceCount; ++i)
            {
                tiles += xmlMapFile.getString("<tiles>", i + 1);
                tiles += " ";
            }

            // Save the loaded tile data into the map data structure
            std::uint32_t tileNum = 0;
            for (std::uint32_t i = 0; i < tiles.size(); ++i)
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

        // Load the music defined in the previously loaded biome
        if (m_gameDatabase->music.fileName.length() > 3)
        {
            cXML xmlMusicFile;
            xmlMusicFile.load(FILE_PATH_DATABASE + m_gameDatabase->music.fileName);
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

        // Handle non generated maps
        if (generate == 0)
        {
            // Load map event data
            m_currentMap->eventCount = xmlMapFile.getInstanceCount("<event>");
            m_currentMap->event = new sMapEvent[m_currentMap->eventCount];
            for (std::uint32_t i = 0; i < m_currentMap->eventCount; ++i)
            {
                // Load the data from the map file
                std::string tEventString = xmlMapFile.getString("<event>", i + 1);
                tEventString += "    ";
                std::uint64_t tEventStringLength = tEventString.length();
                std::uint32_t tEventTileNum = 0;
                std::uint32_t tEventType    = 0;
                std::uint32_t tEventData1   = 0;
                std::uint32_t tEventData2   = 0;
                std::uint32_t tEventData3   = 0;
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tEventStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tEventStringLength; ++j)
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
                            else if (tStringNum == 4)
                            {
                                tEventData3 = std::stoi(tString);
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
                    // Spawn entity
                    case 4:
                        m_currentMap->event[i].type = eMapEventType::eventTypeEntitySpawn;
                    break;
                    // Toggle entity state
                    case 3:
                        m_currentMap->event[i].type = eMapEventType::eventTypeEntityToggle;
                    break;
                    // Set entity state
                    case 2:
                        m_currentMap->event[i].type = eMapEventType::eventTypeEntitySet;
                    break;
                    // Warp to map + portal
                    case 1:
                        m_currentMap->event[i].type = eMapEventType::eventTypeWarp;
                    break;
                    // None 
                    case 0:
                    default:
                        m_currentMap->event[i].type = eMapEventType::eventTypeNone;
                    break;
                }
                m_currentMap->event[i].tile   = tEventTileNum;
                m_currentMap->event[i].data_1 = tEventData1;
                m_currentMap->event[i].data_2 = tEventData2;
                m_currentMap->event[i].data_3 = tEventData3;
            }

            // Load map portal data (for non generated maps)
            m_currentMap->portalCount = xmlMapFile.getInstanceCount("<portal>");
            m_currentMap->portal = new sMapPortal[m_currentMap->portalCount];
            for (std::uint32_t i = 0; i < m_currentMap->portalCount; ++i)
            {
                // Load the data from the map file
                std::string tPortalString = xmlMapFile.getString("<portal>", i + 1);
                tPortalString += "    ";
                std::uint64_t tPortalStringLength = tPortalString.length();
                std::uint32_t tPortalNumber    = 0;
                std::uint32_t tPortalTileNum   = 0;
                float32       tPortalDirection = 0.0f;
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tPortalStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tPortalStringLength; ++j)
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
        }
        
        // Load map object data
        m_currentMap->objectCount = xmlMapFile.getInstanceCount("<object>");
        if (m_currentMap->objectCount > 0)
        {
            m_currentMap->object = new sMapObject[m_currentMap->objectCount];
            for (std::uint32_t i = 0; i < m_currentMap->objectCount; ++i)
            {
                // Load the data from the map file
                std::string tObjectString = xmlMapFile.getString("<object>", i + 1);
                tObjectString += "    ";
                std::uint64_t tObjectStringLength = tObjectString.length();
                std::uint32_t tObjectTileNum   = 0;
                std::string   tObjectName      = "";
                float32       tObjectScale     = 0.0f;
                float32       tObjectRotation  = 0.0f;
                std::uint32_t tObjectObstacle  = 0;
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tObjectStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tObjectStringLength; ++j)
                    {
                        if (tObjectString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tObjectTileNum = std::stoi(tString);
                            }
                            else if (tStringNum == 1)
                            {
                                tObjectName = tString;
                            }
                            else if (tStringNum == 2)
                            {
                                tObjectScale = std::stof(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                tObjectRotation = std::stof(tString);
                            }
                            else if (tStringNum == 4)
                            {
                                tObjectObstacle = std::stoi(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tObjectString[j];
                        }
                    }
                }
                
                // Process the object data
                m_currentMap->object[i].tile       = tObjectTileNum;
                m_currentMap->object[i].name       = tObjectName;
                m_currentMap->object[i].scale      = tObjectScale;
                m_currentMap->object[i].yRot       = tObjectRotation;
                m_currentMap->object[i].obstacle   = tObjectObstacle;
            }
        }

        // Load map debris data
        m_currentMap->debrisCount = xmlMapFile.getInstanceCount("<debris>");
        if (m_currentMap->debrisCount > 0)
        {
            m_currentMap->debris = new sMapDebris[m_currentMap->debrisCount];
            for (std::uint32_t i = 0; i < m_currentMap->debrisCount; ++i)
            {
                // Load the data from the map file
                std::string tDebrisString = xmlMapFile.getString("<debris>", i + 1);
                tDebrisString += "    ";
                std::uint64_t tDebrisStringLength = tDebrisString.length();

                std::string   tDebrisName       = "";
                float32       tDebrisScaleMax   = 0.0f;
                float32       tDebrisScaleMin   = 0.0f;
                std::uint32_t tDebrisPrevalence = 0;
                std::uint32_t tDebrisObstacle   = 0;

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDebrisStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDebrisStringLength; ++j)
                    {
                        if (tDebrisString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tDebrisName = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                tDebrisScaleMax = std::stof(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                tDebrisScaleMin = std::stof(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                tDebrisPrevalence = std::stoi(tString);
                            }
                            else if (tStringNum == 4)
                            {
                                tDebrisObstacle = std::stoi(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tDebrisString[j];
                        }
                    }
                }
                
                // Process the debris data
                m_currentMap->debris[i].name       = tDebrisName;
                m_currentMap->debris[i].scaleMax   = tDebrisScaleMax;
                m_currentMap->debris[i].scaleMin   = tDebrisScaleMin;
                m_currentMap->debris[i].prevalence = tDebrisPrevalence;
                m_currentMap->debris[i].obstacle   = tDebrisObstacle;
            }
        }

        // Load map NPC Mob data
        m_currentMap->npcMobCount = xmlMapFile.getInstanceCount("<npc_mob>");
        if (m_currentMap->npcMobCount > 0)
        {
            m_currentMap->npcMob = new sMapNPCMob[m_currentMap->npcMobCount];
            for (std::uint32_t i = 0; i < m_currentMap->npcMobCount; ++i)
            {
                // Load the data from the map file
                std::string tNPCMobString = xmlMapFile.getString("<npc_mob>", i + 1);
                tNPCMobString += "    ";
                std::uint64_t tNPCMobStringLength = tNPCMobString.length();

                std::string   tNPCMobName       = "";
                float32       tNPCMobScaleMax   = 0.0f;
                float32       tNPCMobScaleMin   = 0.0f;
                std::uint32_t tNPCMobPrevalence = 0;

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tNPCMobStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tNPCMobStringLength; ++j)
                    {
                        if (tNPCMobString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tNPCMobName = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                tNPCMobScaleMax = std::stof(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                tNPCMobScaleMin = std::stof(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                tNPCMobPrevalence = std::stoi(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tNPCMobString[j];
                        }
                    }
                }
                
                // Process the object data
                m_currentMap->npcMob[i].name       = tNPCMobName;
                m_currentMap->npcMob[i].scaleMax   = tNPCMobScaleMax;
                m_currentMap->npcMob[i].scaleMin   = tNPCMobScaleMin;
                m_currentMap->npcMob[i].prevalence = tNPCMobPrevalence;
            }
        }

        // Load map NPC data
        m_currentMap->npcCount = xmlMapFile.getInstanceCount("<npc>");
        if (m_currentMap->npcCount > 0)
        {
            m_currentMap->npc = new sMapNPC[m_currentMap->npcCount];
            for (std::uint32_t i = 0; i < m_currentMap->npcCount; ++i)
            {
                // Load the data from the map file
                std::string tNPCString = xmlMapFile.getString("<npc>", i + 1);
                tNPCString += "    ";
                std::uint64_t tNPCStringLength = tNPCString.length();

                std::uint32_t tNPCTile     = 0;
                std::string   tNPCName     = "";
                std::uint32_t tNPCIndex    = 0;
                float32       tNPCScale    = 0.0f;
                float32       tNPCRotation = 0.0f;
        
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tNPCStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tNPCStringLength; ++j)
                    {
                        if (tNPCString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tNPCTile = std::stoi(tString);
                            }
                            else if (tStringNum == 1)
                            {
                                tNPCName = tString;
                            }
                            else if (tStringNum == 2)
                            {
                                tNPCIndex = std::stoi(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                tNPCScale = std::stof(tString);
                            }
                            else if (tStringNum == 4)
                            {
                                tNPCRotation = std::stof(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tNPCString[j];
                        }
                    }
                }
                
                // Process the npc data
                m_currentMap->npc[i].tile      = tNPCTile;
                m_currentMap->npc[i].name      = tNPCName;
                m_currentMap->npc[i].index     = tNPCIndex;
                m_currentMap->npc[i].scale     = tNPCScale;
                m_currentMap->npc[i].yRot      = tNPCRotation;
            }
        }
        
        // Determine start location
        if (m_currentMap->playerStartPortal != 0) // Coming from previous map
        {
            for (std::uint32_t i = 0; i < m_currentMap->portalCount; ++i)
            {
                if (m_currentMap->playerStartPortal == m_currentMap->portal[i].portalNo)
                {
                    m_currentMap->playerStartTile   = m_currentMap->portal[i].tile;
                    m_currentMap->playerStartDir    = m_currentMap->portal[i].direction;
                }
            }
        }
        else // Find a suitable start tile
        {
            // First try the center tile
            player_tile = (width * height / 2) + (width / 2);
            if ((m_currentMap->tile[player_tile].base == eTileBase::tileFloor) ||
                (m_currentMap->tile[player_tile].base == eTileBase::tileFloorPath))
            {
                m_currentMap->playerStartTile = player_tile;
            }
            else // Fine closest floor tile to the center
            {
                std::uint32_t center_x = width / 2;
                std::uint32_t center_y = height / 2;
                std::uint32_t pos_x = 0;
                std::uint32_t pos_y = 0;
                std::uint32_t max_s = (center_x > center_y) ? center_x : center_y;
                for (std::uint32_t i = 0; i < max_s; ++i)
                {
                    pos_x += 2;
                    pos_y += 2;
                    pos_x = (pos_x < (width - 2)) ? pos_x : (width - 2);
                    pos_y = (pos_y < (height - 2)) ? pos_y : (height - 2);
                    for (std::uint32_t y = 0; y < pos_y; ++y)
                    {
                        for (std::uint32_t x = 0; x < pos_x; ++x)
                        {
                            if (((y != 0) && (y != (pos_y - 1))) &&
                                ((x > 0) && (x < (pos_x - 1))))
                            {
                                // Do nothing, these tiles have already been tried
                            }
                            else
                            {
                                std::uint32_t tile_x = (center_x - (pos_x / 2) + x);
                                std::uint32_t tile_y = (center_y - (pos_y / 2) + y);
                                player_tile = (tile_y * width) + tile_x;
                                
                                if ((m_currentMap->tile[player_tile].base == eTileBase::tileFloor) ||
                                    (m_currentMap->tile[player_tile].base == eTileBase::tileFloorPath))
                                {
                                    m_currentMap->playerStartTile = player_tile;
                                    
                                    // Set to max to exit out of nested for loops
                                    x = pos_x;
                                    y = pos_y;
                                    i = max_s;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        // For non generated maps
        if (generate == 0)
        {
            // Identify rooms (no discard)
            m_mapInitRoomsND(m_currentMap);
            
            // If room types specifid in file, apply them
            std::uint32_t roomTypeSetCount = xmlMapFile.getInstanceCount("<room_type_set>");
            for (std::uint32_t i = 0; i < roomTypeSetCount; ++i)
            {
                // Load the data from the map file
                std::string troomTypeSetString = xmlMapFile.getString("<room_type_set>", i + 1);
                troomTypeSetString += "    ";
                std::uint64_t troomTypeSetStringLength = troomTypeSetString.length();
                std::uint32_t tRoomTile   = 0;
                std::uint32_t tRoomType   = 0;
                std::int32_t  tRoomIgnore = 0;
                std::uint32_t tStringNum  = 0;
                std::string   tString     = "";
                if (troomTypeSetStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < troomTypeSetStringLength; ++j)
                    {
                        if (troomTypeSetString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tRoomTile = std::stoi(tString);
                            }
                            else if (tStringNum == 1)
                            {
                                tRoomType = std::stoi(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                tRoomIgnore = std::stoi(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += troomTypeSetString[j];
                        }
                    }
                }
                
                // Set the room type
                int32_t roomNum = m_getRoomFromTile(m_currentMap, tRoomTile, tRoomIgnore);
                if (roomNum >= 0)
                {
                    m_currentMap->room[roomNum].type = static_cast<eMapRoomType>(tRoomType);
                }
            }

            // Room add prefab
            m_mapPrefabRooms(m_currentMap);
        }
        
        // Populate the map with walls
        m_addWallEntities(m_currentMap);
        
        // Populate the map with Doors
        m_addDoorEntities(m_currentMap);

        // Populate the map with objects
        m_addObjectEntities(m_currentMap);

        // Populate the map with torches
        m_addTorchEntities(m_currentMap);
        
        // Populate the map with Traps
        m_addTrapEntities(m_currentMap);
        
        // Populate the map with Chests
        m_addChestEntities(m_currentMap);

        // Populate the map with NPCs
        m_addNPCEntities(m_currentMap);

        // Generate floor model
        m_currentMap->floor        = m_entityManager->getNew();
        m_currentMap->floor->name  = "Generated map floor.";
        m_currentMap->floor->owner = eEntityOwner::ownerMap;
        m_currentMap->floor->model = m_generateFloor(m_currentMap);

        // Create a model matrix
        m_currentMap->floor->position = glm::vec3(0.0f, 0.0f, 0.0f);
        m_currentMap->floor->scale    = glm::vec3(1.0f, 1.0f, 1.0f);
        m_currentMap->floor->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        m_entityManager->updateModelMatrix(m_currentMap->floor);

        // Load the material defined in the previously loaded biome
        if (m_currentMap->biome->floorSpritesheet.fileName.length() > 3)
        {
            m_currentMap->floor->material = m_entityManager->loadMaterial(m_currentMap->biome->floorSpritesheet.fileName);
        }
        
        // Save map data to the list
        mapList[m_currentMap->name] = m_currentMap->genData.seed;

        // Clean up
        xmlMapFile.free();
        
        // Test map saving, DELETE once finished save function.
        //save("test_save_map.txt");
    }
}

void cMapManager::unload(void)
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
    
    if ((m_currentMap->floor != nullptr) && (m_currentMap->floor->model != nullptr))
    {
        m_entityManager->removeModel(m_currentMap->floor->model);
    }
    
    // Free all entities asociated with the map
    for (sEntity* entity = m_entityManager->getHead(); entity != nullptr; entity = entity->next)
    {
        if (entity->owner == eEntityOwner::ownerMap)
        {
            m_entityManager->freeData(entity);
            m_entityManager->remove(entity);
            entity = m_entityManager->getHead();
        }
    }
}

// Stop the music that is currently playing
void cMapManager::m_stopMusic(void)
{
    m_audioManager->stopSource(m_musicSourceID);
}

// Load and play the music defined in the previously loaded biome
void cMapManager::m_playMusic(void)
{
    if (m_mapMusic.length() > 3)
    {
        m_musicSourceID = m_audioManager->newAudioSource();
        m_audioManager->setAudioSourcePosition(m_musicSourceID, 0.0f, 0.0f, 0.0f);
        m_musicBufferID = m_audioManager->newAudioBuffer();
        m_audioManager->loadBufferOgg(m_musicBufferID, FILE_PATH_MUSIC + m_mapMusic);
        m_audioManager->setAudioBufferName(m_musicBufferID, m_mapMusic);
        m_audioManager->attachSourceBuffer(m_musicSourceID, m_musicBufferID);
        m_audioManager->setAudioSourceLooping(m_musicSourceID, true);
        m_audioManager->playSource(m_musicSourceID);
    }
}

void cMapManager::m_resetPlayerPosition(void)
{
    m_playerManager->setMapPointer(getMapPointer());
    m_playerManager->resetStartTile();
    m_playerManager->stopPathing();
    
    glm::vec3 playerPosition      = m_playerManager->getPosition();
    glm::vec3 cameraTarget        = m_graphicsEngine->getCameraTarget();
    glm::vec3 cameraPosition      = m_graphicsEngine->getCameraPosition();
    glm::vec3 playerLightPosition = m_graphicsEngine->getPlayerLightPosition();
    
    glm::vec3 delta = cameraPosition - cameraTarget;
    cameraTarget    = playerPosition;
    cameraPosition  = cameraTarget + delta;

    m_graphicsEngine->setPlayerLightPosition(glm::vec3(playerPosition.x, playerLightPosition.y, playerPosition.z));
    m_graphicsEngine->setCameraPosition(cameraPosition);
    m_graphicsEngine->setCameraTarget(cameraTarget);
}

void cMapManager::save(const std::string &_fileName)
{
    // Only proceed if there is map data
    if (m_currentMap != nullptr)
    {
        // Create a new map file, or overwrite its content if it does not exist
        std::ofstream mapFile;
        mapFile.open (FILE_PATH_MAP + _fileName, std::ios::trunc); 

        // Only proceed if there is map data
        if (mapFile.is_open())
        {
            std::uint32_t indent_width = 4;
            std::uint32_t indent_level = 0;
            
            // XML information
            mapFile << "<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;

            // Map tag open
            mapFile << "<map>" << std::endl;
            mapFile << std::endl;
            
            // Information
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<information>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<name>" << m_currentMap->name << "</name>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<width>" << m_currentMap->width << "</width>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<height>" << m_currentMap->height << "</height>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<biome>" << m_currentMap->biome->fileName << "</biome>" << std::endl;
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</information>" << std::endl;
            mapFile << std::endl;
            
            // Generation / Tile data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<generation>" << std::endl;
            indent_level++;
            for (std::uint32_t y = 0; y < m_currentMap->height; ++y)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<tiles>";
                for (std::uint32_t x = 0; x < m_currentMap->width; ++x)
                {
                    mapFile << static_cast<std::uint32_t>(m_currentMap->tile[(m_currentMap->width * y) + x].base);
                    mapFile << ' ';
                }
                mapFile << "</tiles>" << std::endl;
            }
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<generate>" << ((m_currentMap->genData.generate) ? 1 : 0) << "</generate>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<seed>" << m_currentMap->genData.seed << "</seed>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<algorithm>" << static_cast<std::uint32_t>(m_currentMap->genData.algorithm) << "</algorithm>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<wall_width>" << m_currentMap->genData.wallSize << "</wall_width>" << std::endl;
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</generation>" << std::endl;
            mapFile << std::endl;

            // Player data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<player>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# This is used when not warping from a prior map" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<player_start_tile>" << m_currentMap->playerStartTile << "</player_start_tile>" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<player_start_rotation>" << m_currentMap->playerStartDir << "</player_start_rotation>" << std::endl;
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</player>" << std::endl;
            mapFile << std::endl;

            // Portal data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<portals>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# These are used when warping from a prior map" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# Portal number, Tile location, player face direction" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# These are exit portals" << std::endl;
            for (std::uint32_t i = 0; i < m_currentMap->portalCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<portal>";
                mapFile << m_currentMap->portal[i].portalNo << " ";
                mapFile << m_currentMap->portal[i].tile << " ";
                mapFile << m_currentMap->portal[i].direction;
                mapFile << "</portal>" << std::endl;
            }
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</portals>" << std::endl;
            mapFile << std::endl;

            // Event data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<events>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# Tile location, type, data 1, data 2, data 3" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# Type 1 (Warp to map) : tile, event type, map number, portal number, NA" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# Type 2 (Set entity state, index from 1) : tile, event type, entity tile, state, NA" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# Type 3 (Toggle entity state, index from 1) : tile, event type, entity tile, state 1, state 2" << std::endl;
            for (std::uint32_t i = 0; i < m_currentMap->eventCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<event>";
                mapFile << m_currentMap->event[i].tile << " ";
                mapFile << static_cast<std::uint32_t>(m_currentMap->event[i].type) << " ";
                mapFile << m_currentMap->event[i].data_1 << " ";
                mapFile << m_currentMap->event[i].data_2 << " ";
                mapFile << m_currentMap->event[i].data_3;
                mapFile << "</event>" << std::endl;
            }
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</events>" << std::endl;
            mapFile << std::endl;

            // Room data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<rooms>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeNone         =  0, // None / empty" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeCell         =  1, // Prison Cell" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeSecret       =  2, // Secret room" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeStairwell    =  3, // Stairwell" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeStore        =  4, // Store" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeBlacksmith   =  5, // Blacksmith" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeCanteen      =  6, // Canteen" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeStorage      =  7, // Storage room" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeLibrary      =  8, // Library" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeAlchemyLab   =  9, // Alchemy Lab" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeLaboratory   = 10, // Laboratory" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "# roomTypeTorture      = 11  // Torture Chamber" << std::endl;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "#Tile (any within the room), type, ignore room number (use for the interconnecting route, -1 for none)" << std::endl;
            for (std::uint32_t i = 0; i < m_currentMap->roomCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<room>";
                mapFile << ((m_currentMap->room[i].y * m_currentMap->width) + m_currentMap->room[i].x) << " ";
                mapFile << static_cast<std::uint32_t>(m_currentMap->room[i].type) << " ";
                mapFile << -1;
                mapFile << "</room>" << std::endl;
            }
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</rooms>" << std::endl;
            mapFile << std::endl;

            // Debris data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<debris_objects>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "#object name, scale max, scale min, prevalence, obstacle" << std::endl;

            for (std::uint32_t i = 0; i < m_currentMap->debrisCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<debris>";
                mapFile << m_currentMap->debris[i].name << " ";
                mapFile << m_currentMap->debris[i].scaleMax << " ";
                mapFile << m_currentMap->debris[i].scaleMin << " ";
                mapFile << m_currentMap->debris[i].prevalence << " ";
                mapFile << m_currentMap->debris[i].obstacle;
                mapFile << "</debris>" << std::endl;
            }
            
            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</debris_objects>" << std::endl;
            mapFile << std::endl;

            // Object data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<objects>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "#tile number, object name, scale, y-rotation, obstacle" << std::endl;

            for (std::uint32_t i = 0; i < m_currentMap->objectCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<object>";
                mapFile << m_currentMap->object[i].tile << " ";
                mapFile << m_currentMap->object[i].name << " ";
                mapFile << m_currentMap->object[i].scale << " ";
                mapFile << m_currentMap->object[i].yRot << " ";
                mapFile << m_currentMap->object[i].obstacle;
                mapFile << "</object>" << std::endl;
            }

            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</objects>" << std::endl;
            mapFile << std::endl;

            // NPC mob data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<npc_mobs>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "#npc name, scale max, scale min, prevalence" << std::endl;

            for (std::uint32_t i = 0; i < m_currentMap->npcMobCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<npc_mobs>";
                mapFile << m_currentMap->npcMob[i].name << " ";
                mapFile << m_currentMap->npcMob[i].scaleMax << " ";
                mapFile << m_currentMap->npcMob[i].scaleMin << " ";
                mapFile << m_currentMap->npcMob[i].prevalence;
                mapFile << "</npc_mob>" << std::endl;
            }

            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</npc_mobs>" << std::endl;
            mapFile << std::endl;

            // NPC data
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "<npcs>" << std::endl;
            indent_level++;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "#tile number, npc name, index (0 == random), scale, y-rotation" << std::endl;

            for (std::uint32_t i = 0; i < m_currentMap->npcCount; ++i)
            {
                mapFile << std::string(indent_width * indent_level, ' ');
                mapFile << "<npc>";
                mapFile << m_currentMap->npc[i].tile << " ";
                mapFile << m_currentMap->npc[i].name << " ";
                mapFile << m_currentMap->npc[i].index << " ";
                mapFile << m_currentMap->npc[i].scale << " ";
                mapFile << m_currentMap->npc[i].yRot;
                mapFile << "</npc>" << std::endl;
            }

            indent_level--;
            mapFile << std::string(indent_width * indent_level, ' ');
            mapFile << "</npcs>" << std::endl;
            mapFile << std::endl;

            // Map tag close
            indent_level--;
            mapFile << "</map>" << std::endl;
            mapFile << std::endl;

            // Clean up
            mapFile.close();
        }
        else
        {
            // Log error, failed to save map file
            gLogWrite(LOG_ERROR, "Failed to save map file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        }
    }
}

void cMapManager::process(const float64 &_dt)
{
    std::uint32_t playerTile = m_playerManager->getCurrentTile();
    for (std::uint32_t i = 0; i < m_currentMap->eventCount; ++i)
    {
        if (m_currentMap->event[i].tile != playerTile)
        {
            m_currentMap->event[i].triggered = false;
        }
        else
        {
            if (m_currentMap->event[i].triggered == false)
            {
                // Warp to map (tile, type, map number, portal number)
                if (m_currentMap->event[i].type == eMapEventType::eventTypeWarp)
                {
                    if (m_loadRequest == false)
                    {
                        m_loadRequest = true;
                    }
                    else
                    {
                        m_currentMap->event[i].triggered = true;

                        // Set the destionation portal number
                        m_currentMap->playerStartPortal = m_currentMap->event[i].data_2;
                        
                        // Load the map warp data
                        std::string nextMapFileName = "";
                        cXML xmlAllMapFile;
                        xmlAllMapFile.load(FILE_PATH_DATABASE + m_gameDatabase->map.fileName);
                        std::uint32_t mapCount = xmlAllMapFile.getInstanceCount("<map>");
                        for (std::uint32_t j = 0; j < mapCount; ++j)
                        {
                            std::string   tMapString = xmlAllMapFile.getString("<map>", j + 1);
                            tMapString += "    ";
                            std::uint64_t tMapStringLength = tMapString.length();
                            std::uint32_t tMapNumber   = 0;
                            std::string   tMapFilename = "";
                            std::uint32_t tStringNum = 0;
                            std::string   tString = "";
                            if (tMapStringLength > 6)
                            {
                                for (std::uint64_t k = 0; k < tMapStringLength; ++k)
                                {
                                    if (tMapString[k] == ' ')
                                    {
                                        if (tStringNum == 0)
                                        {
                                            tMapNumber = std::stoi(tString);
                                        }
                                        else if (tStringNum == 1)
                                        {
                                            tMapFilename = tString;
                                        }
                                        tStringNum++;
                                        tString = "";
                                    }
                                    else
                                    {
                                        tString += tMapString[k];
                                    }
                                }
                            }
                            if (tMapNumber == m_currentMap->event[i].data_1)
                            {
                                nextMapFileName = tMapFilename;
                            }
                        }
                        xmlAllMapFile.free();
                        
                        // Free the old map && load the new map
                        m_stopMusic();
                        load(nextMapFileName);
                        m_resetPlayerPosition();
                        m_graphicsEngine->initializeEntities();
                        m_animationEngine->initializeEntities();
                        m_playMusic();
                        m_loadRequest = false;
                    }
                }
                // Entity set (tile, type, map number, portal number)
                else if (m_currentMap->event[i].type == eMapEventType::eventTypeEntitySet)
                {
                    m_currentMap->event[i].triggered = true;
                    std::uint32_t entityUID = m_currentMap->tile[m_currentMap->event[i].data_1].object;
                    m_entityManager->setState(entityUID, m_currentMap->event[i].data_2);
                }
                // Entity toggle
                else if (m_currentMap->event[i].type == eMapEventType::eventTypeEntityToggle)
                {
                    m_currentMap->event[i].triggered = true;
                    std::uint32_t entityUID = m_currentMap->tile[m_currentMap->event[i].data_1].object;
                    m_entityManager->toggleState(entityUID, m_currentMap->event[i].data_2, m_currentMap->event[i].data_3);
                }
                // Entity spawn
                else if (m_currentMap->event[i].type == eMapEventType::eventTypeEntitySpawn)
                {
                    m_currentMap->event[i].triggered = true;
                }
            }
        }
    }
}
