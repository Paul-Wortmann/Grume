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

#include "game_engine.hpp"

std::uint32_t cGameEngine::initialize(const std::uint32_t &_argc, char** _argv)
{
    // return value
    std::uint32_t return_value = EXIT_SUCCESS;

    // Clear the log
    gLogClear();

    // Log time and application details.
    std::chrono::system_clock::time_point currentSystemTime = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentSystemTime);

    gLogWrite(LOG_INFO, std::string(std::ctime(&currentTime)) + " " + std::string(__TIME__) + " - Starting Grume.", __FILE__, __LINE__, __FUNCTION__);
    std::string GRUMEVersion = std::to_string(GRUME_VERSION_MAJOR) + "." + std::to_string(GRUME_VERSION_MINOR) + "." + std::to_string(GRUME_VERSION_MICRO);
    gLogWrite(LOG_INFO, "Grume version: " + GRUMEVersion, __FILE__, __LINE__, __FUNCTION__);
    std::string GRUMECompile = __DATE__; GRUMECompile += " - "; GRUMECompile += __TIME__;
    gLogWrite(LOG_INFO, "Compile details: " + GRUMECompile, __FILE__, __LINE__, __FUNCTION__);

    gLogWrite(LOG_INFO, "Home path: " + std::string(std::getenv("HOME")), __FILE__, __LINE__, __FUNCTION__);

    // Load the configuration file
    m_gameConfig.load();

    // Process command line arguments
    for (std::uint32_t i = 1; i < _argc; i++)
    {
        std::string clString = _argv[i];
        if (clString.compare("--test") == 0)
        {
            std::cout << "Command line test arg passed" << std::endl;
        }
        else if (clString.compare("--help") == 0)
        {
            std::cout << "Command line help arg passed" << std::endl;
        }
    }

    // Apply pre-initialization configuration settings
    m_graphicsEngine.setWireframeRender(m_gameConfig.m_wireframeRender);
    m_graphicsEngine.setBasicRenderPath(m_gameConfig.m_basicRenderer);
    m_graphicsEngine.setDisplay(m_gameConfig.m_resolution_x, m_gameConfig.m_resolution_y, m_gameConfig.m_fullscreen);

    //Initialize IO
    m_IOManager.initialize();

    // Load database and initialize resource management
    return_value = (return_value == EXIT_SUCCESS) ? m_databaseManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_resourceManager.initialize() : return_value;

    // Initialize sub-systems
    return_value = (return_value == EXIT_SUCCESS) ? m_resourceManager.initializeFont() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_uiManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_graphicsEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_entityManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_lootManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_mapManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_playerManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_audioEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_particleEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_physicsEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_animationEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_npcManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_objectManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_questManager.initialize() : return_value;

    // Apply post-initialization configuration settings
    m_audioEngine.setVolumeMaster(m_gameConfig.m_volume_master);
    m_audioEngine.setVolumeMusic(m_gameConfig.m_volume_music);
    m_audioEngine.setVolumeSound(m_gameConfig.m_volume_sfx);

    // Seed the random number generator
    std::uint32_t gameSeed = 0;
    gRandSeed(gameSeed);

    // Set inter-system connections
    m_entityManager.setAudioEngine(&m_audioEngine);
    m_entityManager.setDatabaseManager(&m_databaseManager);
    m_entityManager.setResourceManager(&m_resourceManager);
    m_entityManager.setMapPointer(m_mapManager.getMapPointer());
    m_animationEngine.setEntityHead(m_entityManager.getHead());
    m_graphicsEngine.setEntityHead(m_entityManager.getHead());
    m_graphicsEngine.setGameConfigPointer(&m_gameConfig);
    m_graphicsEngine.setIOPointer(m_IOManager.getIOPointer());
    m_graphicsEngine.setUIPointer(&m_uiManager);
    m_graphicsEngine.setPlayerActionBarPointer(m_playerManager.getPlayerActionBar());
    m_graphicsEngine.setPlayerEquipmentPointer(m_playerManager.getPlayerEquipment());
    m_graphicsEngine.setPlayerInventoryPointer(m_playerManager.getPlayerInventory());
    m_graphicsEngine.setPlayerVendorPointer(m_playerManager.getPlayerVendor());
    m_graphicsEngine.setPlayerWaypointsPointer(m_playerManager.getPlayerWaypoints());
    m_graphicsEngine.setResourceManagerPointer(&m_resourceManager);
    m_graphicsEngine.setMapPointer(m_mapManager.getMapPointer());
    m_physicsEngine.setIOPointer(m_IOManager.getIOPointer());
    m_physicsEngine.setEntityHead(m_entityManager.getHead());
    m_physicsEngine.setEntityManager(&m_entityManager);
    m_physicsEngine.setMapPointer(m_mapManager.getMapPointer());
    m_particleEngine.setEntityHead(m_entityManager.getHead());
    m_particleEngine.setEntityManager(&m_entityManager);
    m_particleEngine.setMapPointer(m_mapManager.getMapPointer());
    m_particleEngine.setDatabaseManager(&m_databaseManager);
    m_particleEngine.setGraphicsEngine(&m_graphicsEngine);
    m_mapManager.setAudioEngine(&m_audioEngine);
    m_mapManager.setEntityManager(&m_entityManager);
    m_mapManager.setDatabaseManager(&m_databaseManager);
    m_mapManager.setGraphicsEngine(&m_graphicsEngine);
    m_mapManager.setAnimationEngine(&m_animationEngine);
    m_mapManager.setPlayerManager(&m_playerManager);
    m_mapManager.setQuestManager(&m_questManager);
    m_npcManager.setAudioEngine(&m_audioEngine);
    m_npcManager.setGraphicsEnginePointer(&m_graphicsEngine);
    m_npcManager.setEntityHead(m_entityManager.getHead());
    m_npcManager.setEntityManagerPointer(&m_entityManager);
    m_npcManager.setDatabaseManagerPointer(&m_databaseManager);
    m_npcManager.setLootManagerPointer(&m_lootManager);
    m_npcManager.setParticleEnginePointer(&m_particleEngine);
    m_npcManager.setResourceManagerPointer(&m_resourceManager);
    m_npcManager.setQuestManager(&m_questManager);
    m_npcManager.setIOPointer(m_IOManager.getIOPointer());
    m_objectManager.setAudioEngine(&m_audioEngine);
    m_objectManager.setEntityHead(m_entityManager.getHead());
    m_objectManager.setEntityManagerPointer(&m_entityManager);
    m_objectManager.setLootManagerPointer(&m_lootManager);
    m_objectManager.setParticleEnginePointer(&m_particleEngine);
    m_objectManager.setPlayerManager(&m_playerManager);
    m_objectManager.setResourceManagerPointer(&m_resourceManager);
    m_objectManager.setIOPointer(m_IOManager.getIOPointer());
    m_playerManager.setAudioEngine(&m_audioEngine);
    m_playerManager.setEntityManager(&m_entityManager);
    m_playerManager.setDatabaseManager(&m_databaseManager);
    m_playerManager.setMapPointer(m_mapManager.getMapPointer());
    m_playerManager.setUIManager(&m_uiManager);
    m_playerManager.setResourceManagerPointer(&m_resourceManager);
    m_uiManager.setIOPointer(m_IOManager.getIOPointer());
    m_uiManager.setAudioEngine(&m_audioEngine);
    m_uiManager.setDatabaseManager(&m_databaseManager);
    m_uiManager.setResourceManager(&m_resourceManager);
    m_uiManager.setWindowSize(m_graphicsEngine.getWindow_w(), m_graphicsEngine.getWindow_h());
    m_uiManager.setGold(0);

    // Display loading screen
    m_graphicsEngine.process(0);

    // Setup sub-systems
    if (return_value == EXIT_SUCCESS)
    {

        // Load data
        return_value = m_game_load();
    }

    //

    // Start the game engine timer.
    m_timer.initialize();

    // Set engine state
    m_engineState = (return_value == EXIT_SUCCESS) ? eEngineState::engineStateProc : eEngineState::engineStateTerm;
    return return_value;
}

void cGameEngine::terminate(void)
{
    // save the map
    //m_mapManager.save("map_data.txt");

    // Save the configuration file
    m_gameConfig.m_volume_master = m_audioEngine.getVolumeMaster();
    m_gameConfig.m_volume_music  = m_audioEngine.getVolumeMusic();
    m_gameConfig.m_volume_sfx    = m_audioEngine.getVolumeSound();
    m_gameConfig.save();

    // Terminate systems
    m_graphicsEngine.terminate();
    m_audioEngine.terminate();
    m_animationEngine.terminate();
    m_particleEngine.terminate();
    m_physicsEngine.terminate();

    // Terminate managers
    m_questManager.terminate();
    m_npcManager.terminate();
    m_objectManager.terminate();
    m_lootManager.terminate();
    m_resourceManager.terminate();
    m_databaseManager.terminate();
    m_playerManager.terminate();
    m_mapManager.terminate();
    m_uiManager.terminate();
    m_entityManager.terminate();
    m_IOManager.terminate();

    // Set engine state
    m_engineState = eEngineState::engineStateNone;
}

void cGameEngine::process(void)
{
    m_timer.process(); // Called first in the main loop

    // Process if timer ready
    if (m_timer.ready())
    {
        // Get the delta time
        std::int64_t dt = m_timer.get_frameTime();

        // Process systems
        m_uiManager.process();
        m_physicsEngine.setMouseOverMenu(m_uiManager.getMouseOverMenu());
        m_graphicsEngine.setPlayerLightPosition(m_playerManager.getPosition());
        m_graphicsEngine.process(dt);
        m_animationEngine.process(dt);
        m_mapManager.process(dt);

        if (m_engineState != eEngineState::engineStatePause)
        {
            m_physicsEngine.setCameraPosition(m_graphicsEngine.getCameraPosition());
            m_physicsEngine.setCameraDirection(m_graphicsEngine.getCameraDirection());
            m_physicsEngine.process(dt);
            m_particleEngine.process(dt);
            m_entityManager.process(dt);
            m_npcManager.process(dt);
            m_objectManager.process(dt);
            m_playerManager.process(dt);
        }

        // Process physics events
        for (sPhysicsEvent* tEvent = m_physicsEngine.getEvent(); tEvent != nullptr; tEvent = m_physicsEngine.getEvent())
        {
            // Object clicked
            if (tEvent->type == ePhysicsEventType::physicsEventType_objectClick)
            {
                //std::cout << "Physics event object clicked: " << tEvent->data << std::endl;
                m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            }
            // Tile clicked
            else if (tEvent->type == ePhysicsEventType::physicsEventType_tileClick)
            {
                //std::cout << "Physics event tile clicked: " << tEvent->data << std::endl;
                m_playerManager.targetTile(tEvent->data);
                //m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            }
            // Collision detected
            else if (tEvent->type == ePhysicsEventType::physicsEventType_collision)
            {

                // *** set entity to require a path update ***
                //std::cout << "Physics event collision: " << tEvent->data << std::endl;
            }
            else
            {
                std::cout << "Unhandled physics event: " << tEvent->data << std::endl;
            }

            delete tEvent;
        }

        // Process graphics events
        for (sGraphicsEvent* tEvent = m_graphicsEngine.getEvent(); tEvent != nullptr; tEvent = m_graphicsEngine.getEvent())
        {
            std::cout << "Graphics event data: " << tEvent->data << std::endl;

            if ((tEvent->type == eGraphicsEventType::graphicsEventType_windowClose) &&  (tEvent->data == 1))
            {
                m_engineState = eEngineState::engineStateTerm;
            }

            delete tEvent;
        }

        // Process entity manager events
        for (sEntityManagerEvent* tEvent = m_entityManager.getEvent(); tEvent != nullptr; tEvent = m_entityManager.getEvent())
        {
            // Entity spawned
            if (tEvent->type == sEntityManagerEventType::entityManagerEventType_spawnEntity)
            {
                sEntity* tEntity = m_entityManager.getEntity(tEvent->data);
                m_graphicsEngine.initializeEntity(tEntity);
            }
            // Map collision data changed
            else if (tEvent->type == sEntityManagerEventType::entityManagerEventType_modCollisions)
            {
                m_npcManager.updatePaths();
            }

            // Cleanup
            delete tEvent;
        }

        // Process map manager events
        for (sMapManagerEvent* tEvent = m_mapManager.getEvent(); tEvent != nullptr; tEvent = m_mapManager.getEvent())
        {
            // Map warp event
            if (tEvent->type == sMapManagerEventType::sMapManagerEventType_mapWarp)
            {
                m_mapManager.setSpawnPortal(tEvent->data);
                m_mapManager.load(m_databaseManager.getDatabaseEntryFileName(tEvent->text, 1, eDatabaseType::databaseTypeMap));
                m_engineState = eEngineState::engineStateProc;
            }
            // Menu activated
            else if (tEvent->type == sMapManagerEventType::sMapManagerEventType_menuActivate)
            {
                m_uiManager.SetAllMenusDisabled();
                bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeWayPoints);
                m_uiManager.setMenuEnabled(eMenuType::menuTypeWayPoints, menuState);
                m_IOManager.setKeyReadyState(GLFW_KEY_W, false);
                m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
                m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
            }
            // Map loaded
            else if (tEvent->type == sMapManagerEventType::sMapManagerEventType_mapLoad)
            {
                m_uiManager.setMapTitle(tEvent->text);
            }

            // Cleanup
            delete tEvent;
        }

        // Process NPC manager events
        for (sNPCManagerEvent* tEvent = m_npcManager.getEvent(); tEvent != nullptr; tEvent = m_npcManager.getEvent())
        {
            // Menu activated
            if (tEvent->type == eNPCEventType::NPCEventType_menu)
            {
                if (tEvent->data == eNPCEventData::NPCEventData_menuCloseAll)
                {
                    // Close all menus
                    m_uiManager.SetAllMenusDisabled();
                    m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
                }
                else if (tEvent->data == eNPCEventData::NPCEventData_menuVendor)
                {
                    // Open vendor menu
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeVendor, true);
                    m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
                    m_engineState = eEngineState::engineStatePause;
                }
                else if (tEvent->data == eNPCEventData::NPCEventData_menuInventory)
                {
                    // Open inventory menu
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeInventory, true);
                    m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
                    m_engineState = eEngineState::engineStatePause;
                }
            }

            // Cleanup
            delete tEvent;
        }

        // Process object manager events
        for (sObjectManagerEvent* tEvent = m_objectManager.getEvent(); tEvent != nullptr; tEvent = m_objectManager.getEvent())
        {
            // Menu activated
            if (tEvent->type == eObjectEventType::objectEventType_gold)
            {
                // UI manager update gold
                m_uiManager.setGold(tEvent->data);
            }

            // Cleanup
            delete tEvent;
        }

        // Process player events
        for (sPlayerEvent* tEvent = m_playerManager.getEvent(); tEvent != nullptr; tEvent = m_playerManager.getEvent())
        {
            // Object clicked
            if (tEvent->type == ePlayerEventType::playerEventType_newPosition)
            {
                glm::vec3 position = m_playerManager.getPosition();
                m_graphicsEngine.moveCamera(position);
            }
            else
            {
                std::cout << "Unhandled player event: " << tEvent->data << std::endl;
            }

            // Cleanup
            delete tEvent;
        }

        // Process UI events
        for (sUIEvent* tEvent = m_uiManager.getEvent(); tEvent != nullptr; tEvent = m_uiManager.getEvent())
        {
            // Component clicked
            if (tEvent->type == eUIEventType::UIEventType_click)
            {
                // Close menu
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_closeMenu)
                {
                    m_engineState = (m_uiManager.getActiveWindowCount() < 2) ? eEngineState::engineStateProc : m_engineState;
                }

                // Game quit
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_gameQuit)
                {
                    m_engineState = eEngineState::engineStateTerm;
                }

                // Game new
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_gameNew)
                {
                    m_engineState = eEngineState::engineStateProc;
                    cGameEngine::m_game_new();
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
                    //m_mapManager.setLoading(false);
                }

                // Game load
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_gameLoad)
                {
                    m_engineState = (m_uiManager.getActiveWindowCount() < 2) ? eEngineState::engineStateProc : m_engineState;
                    cGameEngine::m_game_load(1);
                    //m_mapManager.setLoading(false);
                }

                // Game save
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_gameSave)
                {
                    m_engineState = (m_uiManager.getActiveWindowCount() < 2) ? eEngineState::engineStateProc : m_engineState;
                    cGameEngine::m_game_save(1);
                }

                // options menu
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_menuOptions)
                {
                    m_engineState = eEngineState::engineStatePause;
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeOptions, true);
                }

                // Master volume up
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_volumeMasterUp)
                {
                    m_audioEngine.setVolumeMasterUp();
                    m_gameConfig.m_volume_master = m_audioEngine.getVolumeMaster();
                }

                // Master volume down
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_volumeMasterDown)
                {
                    m_audioEngine.setVolumeMasterDown();
                    m_gameConfig.m_volume_master = m_audioEngine.getVolumeMaster();
                }

                // Music volume up
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_volumeMusicUp)
                {
                    m_audioEngine.setVolumeMusicUp();
                    m_gameConfig.m_volume_music = m_audioEngine.getVolumeMusic();
                }

                // Music volume down
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_volumeMusicDown)
                {
                    m_audioEngine.setVolumeMusicDown();
                    m_gameConfig.m_volume_music = m_audioEngine.getVolumeMusic();
                }

                // Sound volume up
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_volumeSoundUp)
                {
                    m_audioEngine.setVolumeSoundUp();
                    m_gameConfig.m_volume_sfx = m_audioEngine.getVolumeSound();
                }

                // Sound volume down
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_volumeSoundDown)
                {
                    m_audioEngine.setVolumeSoundDown();
                    m_gameConfig.m_volume_sfx = m_audioEngine.getVolumeSound();
                }

                // Fullscreen modified
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_fullscreenModified)
                {
                    // NA
                }

                // Way-point map load town
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_loadMapTown)
                {
                    std::string mapName = "town_" + std::to_string(tEvent->data_1) + "_001";
                    m_mapManager.setSpawnPortal(2);
                    m_mapManager.load(m_databaseManager.getDatabaseEntryFileName(mapName, 1, eDatabaseType::databaseTypeMap));
                    m_engineState = (m_engineState == eEngineState::engineStatePause) ? eEngineState::engineStateProc : eEngineState::engineStatePause;
                }

            }

            // Component drag
            else if (tEvent->type == eUIEventType::UIEventType_drag)
            {
                // Action-bar drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_actionBar)
                {
                    m_playerManager.actionBarSetDrag(tEvent->data_1, true);
                }
                // Equipment drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_equipment)
                {
                    m_playerManager.equipmentSetDrag(tEvent->data_1, true);
                }
                // Inventory drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_inventory)
                {
                    m_playerManager.inventorySetDrag(tEvent->data_1, true);
                }
                // Vendor drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_vendor)
                {
                    m_playerManager.vendorSetDrag(tEvent->data_1, true);
                }
                // Waypoints drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_waypoints)
                {
                    m_playerManager.waypointsSetDrag(tEvent->data_1, true);
                }
            }

            // Component drop ground
            else if (tEvent->type == eUIEventType::UIEventType_dropGround)
            {
                // Action-bar drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_actionBar)
                {
                    m_playerManager.actionBarSetDrag(tEvent->data_1, false);
                    m_playerManager.actionBarDrop(tEvent->data_1);
                }
                // Equipment drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_equipment)
                {
                    m_playerManager.equipmentSetDrag(tEvent->data_1, false);
                    m_playerManager.equipmentDrop(tEvent->data_1);
                }
                // Inventory drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_inventory)
                {
                    m_playerManager.inventorySetDrag(tEvent->data_1, false);
                    m_playerManager.inventoryDrop(tEvent->data_1);
                }
                // Vendor drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_vendor)
                {
                    m_playerManager.vendorSetDrag(tEvent->data_1, false);
                    m_playerManager.vendorDrop(tEvent->data_1);
                }
                // Waypoints drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_waypoints)
                {
                    m_playerManager.waypointsSetDrag(tEvent->data_1, false);
                    m_playerManager.waypointsDrop(tEvent->data_1);
                }

            }

            // Component drop menu
            else if (tEvent->type == eUIEventType::UIEventType_dropMenu)
            {
                // Storage swap


                // Action-bar drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_actionBar)
                {
                    m_playerManager.actionBarSetDrag(tEvent->data_1, false);
                    m_playerManager.actionBarDrop(tEvent->data_1);
                }
                // Equipment drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_equipment)
                {
                    m_playerManager.equipmentSetDrag(tEvent->data_1, false);
                    m_playerManager.equipmentDrop(tEvent->data_1);
                }
                // Inventory drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_inventory)
                {
                    m_playerManager.inventorySetDrag(tEvent->data_1, false);
                    m_playerManager.inventoryDrop(tEvent->data_1);
                }
                // Vendor drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_vendor)
                {
                    m_playerManager.vendorSetDrag(tEvent->data_1, false);
                    m_playerManager.vendorDrop(tEvent->data_1);
                }
                // Waypoints drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_waypoints)
                {
                    m_playerManager.waypointsSetDrag(tEvent->data_1, false);
                    m_playerManager.waypointsDrop(tEvent->data_1);
                }

            }

            else
            {
                std::cout << "Unhandled ui event: " << tEvent->data_1 << std::endl;
            }

            // Cleanup
            delete tEvent;
        }

        // User input handling
        // -----------------------------------------

        // Character - GLFW_KEY_C
        if (m_IOManager.getKeyReadyState(GLFW_KEY_C))
        {
            bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeCharacter);
            m_uiManager.setMenuEnabled(eMenuType::menuTypeCharacter, menuState);
            m_IOManager.setKeyReadyState(GLFW_KEY_C, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
            if (menuState == true)
            {
                m_uiManager.setMenuEnabled(eMenuType::menuTypeOptions, false);
                m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
            }
        }

        // Character - GLFW_KEY_E
        if (m_IOManager.getKeyReadyState(GLFW_KEY_E))
        {
            bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeEquipment);
            m_uiManager.setMenuEnabled(eMenuType::menuTypeEquipment, menuState);
            m_IOManager.setKeyReadyState(GLFW_KEY_E, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
            if (menuState == true)
            {
                m_uiManager.setMenuEnabled(eMenuType::menuTypeOptions, false);
                m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
            }
        }

        // Inventory - GLFW_KEY_I
        if (m_IOManager.getKeyReadyState(GLFW_KEY_I))
        {
            bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeInventory);
            m_uiManager.setMenuEnabled(eMenuType::menuTypeInventory, menuState);
            m_IOManager.setKeyReadyState(GLFW_KEY_I, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
            if (menuState == true)
            {
                m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
            }
        }

        // Pause game - GLFW_KEY_P
        if (m_IOManager.getKeyReadyState(GLFW_KEY_P))
        {
            m_IOManager.setKeyReadyState(GLFW_KEY_P, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (m_engineState == eEngineState::engineStatePause) ? eEngineState::engineStateProc : eEngineState::engineStatePause;
        }

        // Reload current map - GLFW_KEY_R
        if (m_IOManager.getKeyReadyState(GLFW_KEY_R))
        {
            m_IOManager.setKeyReadyState(GLFW_KEY_R, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_mapManager.reloadMap();
        }

        // Skills - GLFW_KEY_S
        if (m_IOManager.getKeyReadyState(GLFW_KEY_S))
        {
            bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeSkills);
            m_uiManager.setMenuEnabled(eMenuType::menuTypeSkills, menuState);
            m_IOManager.setKeyReadyState(GLFW_KEY_S, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
            if (menuState == true)
            {
                m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
            }
        }

        // Waypoints menu - GLFW_KEY_W
        if (m_IOManager.getKeyReadyState(GLFW_KEY_W))
        {
            bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeWayPoints);
            m_uiManager.SetAllMenusDisabled();
            m_uiManager.setMenuEnabled(eMenuType::menuTypeWayPoints, menuState);
            m_IOManager.setKeyReadyState(GLFW_KEY_W, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
        }

        // Main menu - GLFW_KEY_ESCAPE
        if (m_IOManager.getKeyReadyState(GLFW_KEY_ESCAPE))
        {
            bool menuState = !m_uiManager.getMenuEnabled(eMenuType::menuTypeMain);
            m_uiManager.SetAllMenusDisabled();
            m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, menuState);
            m_IOManager.setKeyState(GLFW_KEY_ESCAPE, false);
            m_IOManager.setKeyReadyState(GLFW_KEY_ESCAPE, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (menuState) ? eEngineState::engineStatePause : eEngineState::engineStateProc;
        }

        // Screenshot - GLFW_KEY_F12
        if (m_IOManager.getKeyReadyState(GLFW_KEY_F12))
        {
            m_resourceManager.savePNG("screenshot.png");
            m_IOManager.setKeyReadyState(GLFW_KEY_F12, false);
        }

        // -----------------------------------------

        // If player has moved update camera
        if ((m_engineState != eEngineState::engineStatePause) && (m_playerManager.getMoved()))
        {
            glm::vec3 position = m_playerManager.getPosition();
            m_graphicsEngine.moveCamera(position);
        }

        // -----------------------------------------
        // Advance the timer
        m_timer.advance_dt();
        //std::cout << "Frame time: " << m_timer.get_frameTime() << std::endl;
    }
}

std::uint32_t cGameEngine::run(const std::uint32_t &_argc, char** _argv)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    // Initialize
    m_engineState = eEngineState::engineStateInit;
    return_value = initialize(_argc, _argv);

    // Process
    while (m_engineState != eEngineState::engineStateTerm)
    {
        process();
    }

    // Terminate
    terminate();
    return return_value;
}
