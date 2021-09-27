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

    // Create a new emptyt map data structure
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
        std::string name          = xmlMapFile.getString("<name>");
        std::uint32_t      width         = xmlMapFile.getInteger("<width>");
        std::uint32_t      height        = xmlMapFile.getInteger("<height>");
        std::string biomeFile     = xmlMapFile.getString("<biome>");
        std::uint32_t      generate      = xmlMapFile.getInteger("<generate>");
        std::uint32_t      seed          = xmlMapFile.getInteger("<seed>");
        std::uint32_t      algorithm     = xmlMapFile.getInteger("<algorithm>");
        std::uint32_t      wall_width    = xmlMapFile.getInteger("<wall_width>");

        std::uint32_t      player_tile   = xmlMapFile.getInteger("<player_start_tile>");
        float32     player_rot    = xmlMapFile.getFloat("<player_start_rotation>");

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
        m_currentMap->genData.algorithm = static_cast<eAlgorithm>(algorithm);
        m_currentMap->genData.seed      = seed;
        m_currentMap->genData.wallSize  = wall_width;

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

        // Clean up
        xmlMapFile.free();
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
