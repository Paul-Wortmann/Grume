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

std::uint32_t cMapManager::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    if (m_map == nullptr)
        m_map = new sMap;

    return return_value;
}

void cMapManager::terminate(void)
{
    if (m_map != nullptr)
    {
        m_freeData(m_map);
        delete m_map;
        m_map = nullptr;
    }
}

void cMapManager::m_freeData(sMap*& _map)
{
    // Return if nullptr
    if (_map == nullptr)
    {
        return;
    }

    // Delete condition data
    if (_map->condition != nullptr)
    {
        delete [] _map->condition;
        _map->condition    = nullptr;
        _map->numCondition = 0;
    }

    // Delete debris data
    if (_map->debris != nullptr)
    {
        delete [] _map->debris;
        _map->debris    = nullptr;
        _map->numDebris = 0;
    }

    // Delete event data
    if (_map->event != nullptr)
    {
        delete [] _map->event;
        _map->event    = nullptr;
        _map->numEvent = 0;
    }

    // Delete generation data
    if (_map->generate != nullptr)
    {
        delete _map->generate;
        _map->generate = nullptr;
    }

    // Delete NPC data
    if (_map->npc != nullptr)
    {
        delete [] _map->npc;
        _map->npc    = nullptr;
        _map->numNPC = 0;
    }

    // Delete object data
    if (_map->object != nullptr)
    {
        delete [] _map->object;
        _map->object    = nullptr;
        _map->numObject = 0;
    }

    // Delete portal data
    if (_map->portal != nullptr)
    {
        delete [] _map->portal;
        _map->portal    = nullptr;
        _map->numPortal = 0;
    }

    // Delete room data
    if (_map->room != nullptr)
    {
        delete [] _map->room;
        _map->room    = nullptr;
        _map->numRoom = 0;
    }

    // Delete tile data
    if (_map->tile != nullptr)
    {
        delete [] _map->tile;
        _map->tile = nullptr;
        _map->numTiles = 0;
    }

    _map->info.currentNumMob = 0;
}

void cMapManager::process(const std::int64_t &_dt)
{
    // Reset frame trigger flag, and look for non tile events
    for (std::uint32_t i = 0; i < m_map->numEvent; ++i)
    {
        // map warp events
        if (m_map->event[i].triggered)
        {
            // Trigger tile
            if (m_map->event[i].type == eMapEventType::eventTypeTriggerTile)
            {
            }
            // Map warp
            else if (m_map->event[i].type == eMapEventType::eventTypeMapWarp)
            {
                // Create events
                sMapManagerEvent* event = new sMapManagerEvent;
                event->type = sMapManagerEventType::sMapManagerEventType_mapWarp;
                event->data = m_map->event[i].tile;
                event->text = m_map->event[i].trigger_name;
                m_event.push(event);
            }
            // Quest set
            else if (m_map->event[i].type == eMapEventType::eventTypeMapQuestSet)
            {
            }
            // Activate menu
            else if (m_map->event[i].type == eMapEventType::eventTypeMenuActivate)
            {
                // Create events
                sMapManagerEvent* event = new sMapManagerEvent;
                event->type = sMapManagerEventType::sMapManagerEventType_menuActivate;
                event->text = m_map->event[i].trigger_name;
                m_event.push(event);
            }
            // Shrine
            else if (m_map->event[i].type == eMapEventType::eventTypeMapShrine)
            {
            }
        }

        // Reset frame trigger
        m_map->event[i].thisFrame = false;
    }

    // Process entity initiated tile events
    for (sEntity* tEntity = m_entityManager->getHead(); tEntity != nullptr; tEntity = tEntity->next)
    {
        // Only dynamic entities
        if ((tEntity->base.type == eEntityType::entityType_player) ||
            (tEntity->base.type == eEntityType::entityType_npc) ||
            (tEntity->base.type == eEntityType::entityType_objectDynamic))
        {
            std::uint32_t entityTile = tEntity->base.tileOnMap;
            for (std::uint32_t i = 0; i < m_map->numEvent; ++i)
            {
                if ((m_map->event[i].type == eMapEventType::eventTypeTriggerTile) && (m_map->event[i].tile == entityTile) && (m_map->event[i].thisFrame == false))
                {
                    m_map->event[i].thisFrame = true;
                    if (m_map->event[i].triggered == false)
                    {
                        m_map->event[i].triggered = true;
                        sEntity* tEntityTile = m_entityManager->getEntityOnTile(m_map->event[i].trigger_tile);
                        m_entityManager->triggerEntity(tEntityTile);
                    }
                }
            }
        }
    }

    // Reset trigger flag if event not triggered this frame
    for (std::uint32_t i = 0; i < m_map->numEvent; ++i)
    {
        m_map->event[i].triggered = m_map->event[i].thisFrame;
    }



/*
/// legacy cruft below...


    for (sEntity* tEntity2 = m_entityManager->getHead(); tEntity2 != nullptr; tEntity2 = tEntity2->next)
    {
        tEntity2->base.hasFunction = false;
    }

    // Reset entities
    for (sEntity* tEntity = m_entityManager->getHead(); tEntity != nullptr; tEntity = tEntity->next)
    {
        // Only dynamic entities
        if ((tEntity->base.type == eEntityType::entityType_player) ||
            (tEntity->base.type == eEntityType::entityType_npc) ||
            (tEntity->base.type == eEntityType::entityType_objectDynamic))
        {

            // find the corresponding floor tile entity
            for (sEntity* tEntity2 = m_entityManager->getHead(); tEntity2 != nullptr; tEntity2 = tEntity2->next)
            {
                if (tEntity2->base.type == eEntityType::entityType_floor)
                {
                    std::uint32_t floorTile = gMapPositionToTile(m_map, tEntity2->base.position);
                    if (floorTile == tEntity->base.tileOnMap)
                    {
                        tEntity2->base.hasFunction = true;
                    }
                }
            }
         }
    }
*/
}

void cMapManager::m_playMapMusic(void)
{
    std::string musicFileName = m_databaseManager->getDatabaseEntryFileName(m_map->info.musicName, m_map->info.musicNumber, eDatabaseType::databaseTypeMusic);
    if (m_currentMusicFile.compare(musicFileName) != 0)
    {
        if (musicFileName.length() < 4)
            return;

        m_currentMusicFile = musicFileName;

        m_audioEngine->loadMusic(m_currentMusicFile);
        m_audioEngine->playMusic();
    }
}

void cMapManager::m_unloadMap(void)
{
    // If nullptr return
    if (m_map == nullptr)
    {
        return;
    }

    // Free the map and its data
    m_freeData(m_map);
    m_map->info.name = "";

    // Free all entities associated with the map
    for (sEntity* tEntity = m_entityManager->getHead(); tEntity != nullptr; tEntity = tEntity->next)
    {
        if ((tEntity->base.owner == eEntityOwner::entityOwner_map) ||
            (tEntity->base.owner == eEntityOwner::entityOwner_particle))
        {
            m_entityManager->deleteEntity(tEntity);
        }
    }
}

std::uint32_t cMapManager::load(const std::string &_fileName)
{
    // Return value
    std::uint32_t return_value = EXIT_SUCCESS;

    // Try to load the map file
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + _fileName);
    if (mapFile.isValid())
    {
        std::cout << "loading map: " << _fileName << std::endl;

        // Set player state idle
        if (m_entityPlayer != nullptr)
        {
            m_entityManager->stateSet(m_entityPlayer, eEntityState::entityState_idle);
            m_entityPlayer->movement->pathing = false;
        }

        // Reset the entity range check timer
        m_entityManager->resetRangeTimer();

        // Set loading screen
        m_graphicsEngine->setLoading(true);
        m_graphicsEngine->process(0);

        // Unload previous map data
        m_unloadMap();

        // Data parsing
        std::string   dataString       = {};
        std::uint32_t dataStringLength = 0;
        std::string   tString          = "";

        // Map conditions
        //# Condition number, state
        m_map->numCondition = mapFile.getInstanceCount("<condition>");
        if (m_map->numCondition > 0)
        {
            m_map->condition = new sMapCondition[m_map->numCondition];
            for (std::uint32_t c = 0; c < m_map->numCondition; ++c)
            {
                tString = mapFile.getString("<condition>", c + 1);
            }
        }

        // Map generation
        if (m_map->generate == nullptr)
        {
            m_map->generate = new sMapGenerate;
        }
        if (mapFile.getInstanceCount("<generation_enabled>") > 0)
            m_map->generate->generate = (mapFile.getInteger("<generation_enabled>") > 0);
        if (mapFile.getInstanceCount("<generation_algorithm>") > 0)
            m_map->generate->algorithm = static_cast<eAlgorithm>(mapFile.getInteger("<generation_algorithm>"));
        if (mapFile.getInstanceCount("<generation_wall_size>") > 0)
            m_map->generate->wallSize = mapFile.getInteger("<generation_wall_size>");
        if (mapFile.getInstanceCount("<generation_density>") > 0)
            m_map->generate->density = mapFile.getInteger("<generation_density>");
        if (mapFile.getInstanceCount("<generation_room_min>") > 0)
            m_map->generate->roomMin = mapFile.getInteger("<generation_room_min>");
        if (mapFile.getInstanceCount("<generation_room_max>") > 0)
            m_map->generate->roomMax = mapFile.getInteger("<generation_room_max>");
        if (mapFile.getInstanceCount("<generation_room_radius_min>") > 0)
            m_map->generate->roomRadiusMin = mapFile.getInteger("<generation_room_radius_min>");
        if (mapFile.getInstanceCount("<generation_room_radius_max>") > 0)
            m_map->generate->roomRadiusMax = mapFile.getInteger("<generation_room_radius_max>");
        if (mapFile.getInstanceCount("<generation_room_border>") > 0)
            m_map->generate->roomBorder = mapFile.getInteger("<generation_room_border>");
        if (mapFile.getInstanceCount("<generation_room_shape>") > 0)
            m_map->generate->roomShape = static_cast<eRoomShape>(mapFile.getInteger("<generation_room_shape>"));
        if (mapFile.getInstanceCount("<generation_floor_area_min>") > 0)
            m_map->generate->floorAreaMin = mapFile.getInteger("<generation_floor_area_min>");
        if (mapFile.getInstanceCount("<generation_connectivity_algorithm>") > 0)
            m_map->generate->connectivityAlgorithm = static_cast<eConnectAlgo>(mapFile.getInteger("<generation_connectivity_algorithm>"));
        if (mapFile.getInstanceCount("<generation_connectivity_complexity>") > 0)
            m_map->generate->connectivityComplexity = mapFile.getInteger("<generation_connectivity_complexity>");
        if (mapFile.getInstanceCount("<generation_connectivity_padding>") > 0)
            m_map->generate->connectivityPadding = mapFile.getInteger("<generation_connectivity_padding>");
        if (mapFile.getInstanceCount("<generation_direction_bias>") > 0)
            m_map->generate->directionBias = static_cast<eDirectionBias>(mapFile.getInteger("<generation_direction_bias>"));
        if (mapFile.getInstanceCount("<generation_direction_bias_strength>") > 0)
            m_map->generate->directionBiasStrength = mapFile.getInteger("<generation_direction_bias_strength>");

        // Map information
        m_map->info.fileName    = _fileName;
        m_map->info.name        = mapFile.getString("<map_name>");
        m_map->info.biome       = mapFile.getString("<map_biome>");
        m_map->info.musicName   = mapFile.getString("<map_music_name>");
        m_map->info.musicNumber = mapFile.getInteger("<map_music_number>");
        m_map->info.size_x      = mapFile.getInteger("<map_tiles_x>");
        m_map->info.size_y      = mapFile.getInteger("<map_tiles_y>");

        if (mapFile.getInstanceCount("<map_enable_walls>") > 0)
            m_map->info.enableWalls = (mapFile.getInteger("<map_enable_walls>") > 0);
        if (mapFile.getInstanceCount("<map_enable_floors>") > 0)
            m_map->info.enableFloors = (mapFile.getInteger("<map_enable_floors>") > 0);
        if (mapFile.getInstanceCount("<map_enable_rooms>") > 0)
            m_map->info.enableRooms = (mapFile.getInteger("<map_enable_rooms>") > 0);
        if (mapFile.getInstanceCount("<map_enable_doors>") > 0)
            m_map->info.enableDoors = (mapFile.getInteger("<map_enable_doors>") > 0);
        if (mapFile.getInstanceCount("<map_enable_torches>") > 0)
            m_map->info.enableTorches = (mapFile.getInteger("<map_enable_torches>") > 0);
        if (mapFile.getInstanceCount("<map_enable_chests>") > 0)
            m_map->info.enableChests = (mapFile.getInteger("<map_enable_chests>") > 0);
        if (mapFile.getInstanceCount("<map_enable_objects>") > 0)
            m_map->info.enableObjects = (mapFile.getInteger("<map_enable_objects>") > 0);
        if (mapFile.getInstanceCount("<map_enable_npcs>") > 0)
            m_map->info.enableNpcs = (mapFile.getInteger("<map_enable_npcs>") > 0);

        // Tiles
        m_map->numTiles    = m_map->info.size_x * m_map->info.size_y;
        m_map->tile        = new sMapTile[m_map->numTiles];

        // Player information
        float      playerStartRotation  = mapFile.getFloat("<player_start_rotation>");
        glm::ivec2 playerStartTile      = mapFile.getIVec2("<player_start_tile>");

        // Re-spawn town name
        if (mapFile.getInstanceCount("<set_town>") > 0)
            mapTown = mapFile.getString("<set_town>");

        // Wind speed multiplier
        if (mapFile.getInstanceCount("<map_wind>") > 0)
            m_map->info.windSpeed = mapFile.getFloat("<map_wind>");

        // Seed
        m_map->info.seed = mapFile.getInteger("<map_seed>");

        // If a seed already exists for the map, use it instead
        std::map<std::string, std::uint32_t>::iterator it;
        it = mapList.find(m_map->info.name);
        if (it != mapList.end())
        {
            m_map->info.seed = mapList[m_map->info.name];
        }

        // If the map does not have a seed, generate one
        if (m_map->info.seed == 0)
        {
            m_map->info.seed = rand();
            mapList[m_map->info.name] = m_map->info.seed;
        }

        // Use the seed
        srand(m_map->info.seed);

        // If PCG map, generate map
        if ((m_map->generate != nullptr) && m_map->generate->generate)
        {
            m_generateMap(m_map);
        }
        // If non PCG map, load and initialize data
        else
        {

            // Map tiles
            std::uint32_t x                = 0;
            std::uint32_t instanceCount    = mapFile.getInstanceCount("<tiles>");
            for (std::uint32_t y = 0; y < instanceCount; ++y)
            {
                x = 0;
                dataString = mapFile.getString("<tiles>", y + 1);
                dataStringLength = dataString.length();
                for (std::uint32_t i = 0; i < dataStringLength; ++i)
                {
                    if (dataString[i] != ',')
                    {
                        m_map->tile[(y * m_map->info.size_x) + x].type = static_cast<eTileType>(std::stoi(&dataString[i]));
                        x++;
                    }
                }
            }

            // Initialize data
            m_playMapMusic();
            if (m_map->info.enableWalls)
                m_addWalls();
            if (m_map->info.enableFloors)
                m_addFloors();
            if (m_map->info.enableFloors)
                m_addPaths();
            m_addEvents();
            m_addPortals();
            if (m_map->info.enableRooms)
                m_addRooms();
            if (m_map->info.enableRooms)
                m_addPrefabs();
            if (m_map->info.enableDoors)
                m_addDoors();
            if (m_map->info.enableTorches)
                m_addTorches();
            if (m_map->info.enableObjects)
                m_addObjects();
            if (m_map->info.enableNpcs)
                m_addNPCs();
            if (m_map->info.enableChests)
                m_addChests();
            if (m_map->info.enableObjects)
                m_addDebris();
            if (m_map->info.enableNpcs)
                m_addNPC_mobs();
        }

        // Player spawn position
        if (m_spawnPortal == 0)
        {
            std::uint32_t playerTile = (playerStartTile.y * m_map->info.size_x) + playerStartTile.x;
            playerTile = gClosestFreeTile(m_map, playerTile);
            m_playerManager->setPlayerPosition(playerTile, playerStartRotation);
        }
        else
        {
            playerStartRotation = m_map->portal[m_spawnPortal - 1].rotation;
            std::uint32_t playerTile = m_map->portal[m_spawnPortal - 1].tile;
            playerTile = gClosestFreeTile(m_map, playerTile);
            m_playerManager->setPlayerPosition(playerTile, playerStartRotation);
        }
        m_spawnPortal = 0;

        // Initialize data
        m_graphicsEngine->initializeEntities();
        m_animationEngine->initializeEntities();

        // Map process after placing entities
        m_entityManager->spawnMinionEntities();
        process(16); // 60 fps, 1 frame

        // Create map load event
        sMapManagerEvent* event = new sMapManagerEvent;
        event->type = sMapManagerEventType::sMapManagerEventType_mapLoad;
        event->text = m_map->info.name;
        m_event.push(event);

        // Load finished
        m_graphicsEngine->setLoading(false);
    }
    else
    {
        return_value = EXIT_FAILURE;
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    // Cleanup
    mapFile.free();
    return return_value;
}

std::uint32_t cMapManager::reloadMap(void)
{
    std::string mapName  = m_map->info.name;
    std::string fileName = m_databaseManager->getDatabaseEntryFileName(mapName, 1, eDatabaseType::databaseTypeMap);
    return load(fileName);
}

void cMapManager::save(const std::string &_fileName)
{
    auto indent = [] (const std::uint32_t &_value)
    {
        if (_value == 0)
            return std::string("");
        const std::uint32_t tabWidth = 3;
        return std::string(_value * tabWidth, ' ');
    };

    std::ofstream mapFile;
    mapFile.open(_fileName, std::ofstream::out | std::ios_base::trunc);
    if (mapFile.is_open())
    {
        std::uint32_t iLevel = 0;
        mapFile << indent(iLevel) << "﻿<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;
        mapFile << indent(iLevel) << "<map>" << std::endl;
        mapFile << std::endl;

        /// Information
        iLevel++;
        mapFile << indent(iLevel) << "<information>" << std::endl;
        iLevel++;
        mapFile << indent(iLevel) << "<map_name>" << m_map->info.name << "</map_name>" << std::endl;
        mapFile << indent(iLevel) << "<map_biome>" << m_map->info.biome << "</map_biome>" << std::endl;
        mapFile << indent(iLevel) << "<map_tiles_x>" << m_map->info.size_x << "</map_tiles_x>" << std::endl;
        mapFile << indent(iLevel) << "<map_tiles_y>" << m_map->info.size_y << "</map_tiles_y>" << std::endl;
        mapFile << indent(iLevel) << "<map_seed>" << " m_map->seed " << "</map_seed>" << std::endl;
        mapFile << indent(iLevel) << "<world_orientation>" << "0 0 1" << "</world_orientation>" << std::endl;
        iLevel--;
        mapFile << indent(iLevel) << "</information>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// Tile Data
        iLevel++;
        mapFile << indent(iLevel) << "<tile_data>" << std::endl;
        iLevel++;
        mapFile << indent(iLevel) << "# tileNone           = 0, // None" << std::endl;
        mapFile << indent(iLevel) << "# tileFloor          = 1, // Floor tile" << std::endl;
        mapFile << indent(iLevel) << "# tilePath           = 2, // Path tile" << std::endl;
        mapFile << indent(iLevel) << "# tileFloorNoGo      = 3, // Floor no go tile" << std::endl;
        mapFile << indent(iLevel) << "# tilePathNoGo       = 4, // Path no go tile" << std::endl;
        mapFile << indent(iLevel) << "# tileWallTall       = 5, // Wall tall tile" << std::endl;
        mapFile << indent(iLevel) << "# tileWallTallHole   = 6, // Wall tall tile - hole" << std::endl;
        mapFile << indent(iLevel) << "# tileWallShort      = 7, // Wall short tile" << std::endl;
        mapFile << indent(iLevel) << "# tileDoorWay        = 8, // DoorWay tile" << std::endl;
        mapFile << indent(iLevel) << "# tileMapPortal      = 9, // Map portal tile" << std::endl;
        mapFile << indent(iLevel) << "#" << std::endl;
        if (m_map->tile != nullptr)
        {
            for (std::uint32_t y = 0; y < m_map->info.size_y; ++y)
            {
                for (std::uint32_t x = 0; x < m_map->info.size_x; ++x)
                {
                    if (x == 0)
                        mapFile << indent(iLevel) << "<tiles>";
                    mapFile << static_cast<std::uint32_t>(m_map->tile[(y * m_map->info.size_x) + x].type);
                    if (x != m_map->info.size_x - 1)
                        mapFile << ",";
                }
                mapFile << std::endl;
            }
        }

        iLevel--;
        mapFile << indent(iLevel) << "</tile_data>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// Tile object collision Data
        iLevel++;
        mapFile << indent(iLevel) << "# Entity UID" << std::endl;
        mapFile << indent(iLevel) << "#" << std::endl;

        mapFile << indent(iLevel) << "<tile_collision_data>" << std::endl;
        iLevel++;
        for (std::uint32_t y = 0; y < m_map->info.size_y; ++y)
        {
            for (std::uint32_t x = 0; x < m_map->info.size_x; ++x)
            {
                if (x == 0)
                    mapFile << indent(iLevel) << "<collision_data>";
                mapFile << static_cast<std::uint32_t>(m_map->tile[(y * m_map->info.size_x) + x].entity.UID);
                if (x != m_map->info.size_x - 1)
                    mapFile << ",";
            }
            mapFile << std::endl;
        }

        iLevel--;
        mapFile << indent(iLevel) << "</tile_collision_data>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// Portal Data
        iLevel++;
        mapFile << indent(iLevel) << "<portal_data>" << std::endl;
        iLevel++;
        // Data
        iLevel--;
        mapFile << indent(iLevel) << "</portal_data>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// Event Data
        iLevel++;
        mapFile << indent(iLevel) << "<event_data>" << std::endl;
        iLevel++;
        // Data
        iLevel--;
        mapFile << indent(iLevel) << "</event_data>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// Room Data
        iLevel++;
        mapFile << indent(iLevel) << "<rooms>" << std::endl;
        iLevel++;
        for (std::uint32_t r = 0; r < m_map->numRoom; ++r)
        {
            mapFile << indent(iLevel) << "<room>" << std::endl;
            iLevel++;
            mapFile << indent(iLevel) << "<room_x>" << m_map->room[r].x << "</room_x>" << std::endl;
            mapFile << indent(iLevel) << "<room_y>" << m_map->room[r].y << "</room_y>" << std::endl;
            mapFile << indent(iLevel) << "<room_width>" << m_map->room[r].w << "</room_width>" << std::endl;
            mapFile << indent(iLevel) << "<room_height>" << m_map->room[r].h << "</room_height>" << std::endl;
            mapFile << indent(iLevel) << "<room_type>" << static_cast<std::uint32_t>(m_map->room[r].type) << "</room_type>" << std::endl;
            iLevel--;
            mapFile << indent(iLevel) << "</room>" << std::endl;
            mapFile << std::endl;
        }
        // Data
        iLevel--;
        mapFile << indent(iLevel) << "</rooms>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// NPC Mob Data
        iLevel++;
        mapFile << indent(iLevel) << "<npc_mob_data>" << std::endl;
        iLevel++;
        // Data
        iLevel--;
        mapFile << indent(iLevel) << "</npc_mob_data>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// Object Debris Data
        iLevel++;
        mapFile << indent(iLevel) << "<object_debris>" << std::endl;
        iLevel++;
        mapFile << indent(iLevel) << "<object_debris_name>" << " sphere " << "</object_debris_name>" << std::endl;
        mapFile << indent(iLevel) << "<object_debris_frequency>" << " 10 " << "</object_debris_frequency>" << std::endl;
        iLevel--;
        mapFile << indent(iLevel) << "</object_debris>" << std::endl;
        mapFile << std::endl;
        iLevel--;

        /// NPCs and Objects
        for (sEntity* tEntity = m_entityManager->getHead(); tEntity != nullptr; tEntity = tEntity->next)
        {
            if (tEntity->base.type == eEntityType::entityType_npc)
            {
                iLevel++;
                mapFile << indent(iLevel) << "<npc>" << std::endl;
                iLevel++;
                mapFile << indent(iLevel) << "<npc_catagory>" << tEntity->base.name << "</npc_catagory>" << std::endl;
                mapFile << indent(iLevel) << "<npc_number>" << "1" << "</npc_number>" << std::endl;
                mapFile << indent(iLevel) << "<npc_tile_x>" << tEntity->base.tileOnMap % m_map->info.size_x << "</npc_tile_x>" << std::endl;
                mapFile << indent(iLevel) << "<npc_tile_y>" << tEntity->base.tileOnMap / m_map->info.size_x << "</npc_tile_y>" << std::endl;
                mapFile << indent(iLevel) << "<npc_position>" << "0.0000 0.0000 0.0000" << "</npc_position>" << std::endl;
                mapFile << indent(iLevel) << "<npc_scale>" << "0.0000 0.0000 0.0000" << "</npc_scale>" << std::endl;
                mapFile << indent(iLevel) << "<npc_rotation>" << "0.0000 0.0000 0.0000" << "</npc_rotation>" << std::endl;
                iLevel--;
                mapFile << indent(iLevel) << "</npc>" << std::endl;
                mapFile << std::endl;
                iLevel--;
            }
            else if ((tEntity->base.type == eEntityType::entityType_objectStatic) || (tEntity->base.type == eEntityType::entityType_objectDynamic))
            {
                iLevel++;
                mapFile << indent(iLevel) << "<object>" << std::endl;
                iLevel++;
                mapFile << indent(iLevel) << "<object_catagory>" << tEntity->base.name << "</object_catagory>" << std::endl;
                mapFile << indent(iLevel) << "<object_number>" << "1" << "</object_number>" << std::endl;
                mapFile << indent(iLevel) << "<object_tile_x>" << tEntity->base.tileOnMap % m_map->info.size_x << "</object_tile_x>" << std::endl;
                mapFile << indent(iLevel) << "<object_tile_y>" << tEntity->base.tileOnMap / m_map->info.size_x << "</object_tile_y>" << std::endl;
                mapFile << indent(iLevel) << "<object_position>" << "0.0000 0.0000 0.0000" << "</object_position>" << std::endl;
                mapFile << indent(iLevel) << "<object_scale>" << "0.0000 0.0000 0.0000" << "</object_scale>" << std::endl;
                mapFile << indent(iLevel) << "<object_rotation>" << "0.0000 0.0000 0.0000" << "</object_rotation>" << std::endl;
                iLevel--;
                mapFile << indent(iLevel) << "</object>" << std::endl;
                mapFile << std::endl;
                iLevel--;
            }
        }

        mapFile << indent(iLevel) << "</map>" << std::endl;
        mapFile << std::endl;

        mapFile.close();
    }
}
