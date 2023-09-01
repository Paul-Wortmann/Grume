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

void cGameEngine::m_process_play(std::int64_t _dt)
{
        // Process systems
        m_networkEngine.process(_dt);
        m_uiManager.process();
        m_physicsEngine.setMouseOverMenu(m_uiManager.getMouseOverMenu());
        m_graphicsEngine.setPlayerLightPosition(m_playerManager.getPosition());
        m_graphicsEngine.process(_dt);
        m_animationEngine.process(_dt);
        m_mapManager.process(_dt);

        if (m_engineState != eEngineState::engineStatePause)
        {
            m_physicsEngine.setCameraPosition(m_graphicsEngine.getCameraPosition());
            m_physicsEngine.setCameraDirection(m_graphicsEngine.getCameraDirection());
            m_physicsEngine.process(_dt);
            m_particleEngine.process(_dt);
            m_entityManager.process(_dt);
            m_npcManager.process(_dt);
            m_objectManager.process(_dt);
            m_playerManager.process(_dt);
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

                // Stop player movement
                m_playerManager.targetHalt();
            }

            // Player type event
            else if (tEvent->type == eNPCEventType::NPCEventType_player)
            {
                // Level up event
                if (tEvent->data == eNPCEventData::NPCEventData_levelUp)
                {
                    // Player level up
                    m_playerManager.levelUp();
                    m_uiManager.setTextPoints(m_playerManager.getAttributePoints());
                }
            }

            // Cleanup
            delete tEvent;
        }

        // Process object manager events
        for (sObjectManagerEvent* tEvent = m_objectManager.getEvent(); tEvent != nullptr; tEvent = m_objectManager.getEvent())
        {
            // Gold change event
            if (tEvent->type == eObjectEventType::objectEventType_gold)
            {
                // UI manager update gold
                m_uiManager.setTextGold(tEvent->data);
            }

            // Cleanup
            delete tEvent;
        }

        // Player
        m_playerManager.setUIdrag(m_IOManager.getmouseDrag());
        m_playerManager.setActiveWindowCount(m_uiManager.getActiveWindowCount());

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
                    m_gameConfig.m_fullscreen = !m_gameConfig.m_fullscreen;
                    m_graphicsEngine.setFullscreen(m_gameConfig.m_fullscreen);
                    m_uiManager.setMenuComponentActivated(eComponentFunction::componentFunctionFullscreenModified, m_gameConfig.m_fullscreen);
                }

                // Lighting modified
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_lightingModified)
                {
                    m_gameConfig.m_basicRenderer = !m_gameConfig.m_basicRenderer;
                    m_graphicsEngine.setBasicRenderPath(m_gameConfig.m_basicRenderer);
                    m_uiManager.setMenuComponentActivated(eComponentFunction::componentFunctionLightingModified, !m_gameConfig.m_basicRenderer);
                }

                // Strength attribute modified
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_plusStrength)
                {
                    std::uint32_t points = m_playerManager.getAttributePoints();
                    if (points > 0)
                    {
                        points--;
                        m_playerManager.setAttributePoints(points);
                        m_uiManager.setTextPoints(points);
                        std::uint32_t strength = m_playerManager.getAttributeStrength();
                        strength++;
                        m_playerManager.setAttributeStrength(strength);
                        m_uiManager.setTextStrength(strength);
                        m_playerManager.calculateAttributes();
                    }
                }

                // Dexterity attribute modified
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_plusDexterity)
                {
                    std::uint32_t points = m_playerManager.getAttributePoints();
                    if (points > 0)
                    {
                        points--;
                        m_playerManager.setAttributePoints(points);
                        m_uiManager.setTextPoints(points);
                        std::uint32_t dexterity = m_playerManager.getAttributeDexterity();
                        dexterity++;
                        m_playerManager.setAttributeDexterity(dexterity);
                        m_uiManager.setTextDexterity(dexterity);
                        m_playerManager.calculateAttributes();
                    }
                }

                // Energy attribute modified
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_plusEnergy)
                {
                    std::uint32_t points = m_playerManager.getAttributePoints();
                    if (points > 0)
                    {
                        points--;
                        m_playerManager.setAttributePoints(points);
                        m_uiManager.setTextPoints(points);
                        std::uint32_t energy = m_playerManager.getAttributeEnergy();
                        energy++;
                        m_playerManager.setAttributeEnergy(energy);
                        m_uiManager.setTextEnergy(energy);
                        m_playerManager.calculateAttributes();
                    }
                }

                // Vitality attribute modified
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_plusVitality)
                {
                    std::uint32_t points = m_playerManager.getAttributePoints();
                    if (points > 0)
                    {
                        points--;
                        m_playerManager.setAttributePoints(points);
                        m_uiManager.setTextPoints(points);
                        std::uint32_t vitality = m_playerManager.getAttributeVitality();
                        vitality++;
                        m_playerManager.setAttributeVitality(vitality);
                        m_uiManager.setTextVitality(vitality);
                        m_playerManager.calculateAttributes();
                    }
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
/*
                // Vendor drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_vendor)
                {
                    m_playerManager.vendorSetDrag(tEvent->data_1, false);
                    m_playerManager.vendorDrop(tEvent->data_1);
                }
*/
                // Waypoints drop
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_waypoints)
                {
                    m_playerManager.waypointsSetDrag(tEvent->data_1, false);
                    m_playerManager.waypointsDrop(tEvent->data_1);
                }
            }

            // Component buy item
            else if (tEvent->type == eUIEventType::UIEventType_buyItem)
            {
                // Inventory
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_vendor)
                {
                    m_playerManager.buyVendorSlot(tEvent->data_1);
                }
            }

            // Component sell item
            else if (tEvent->type == eUIEventType::UIEventType_sellItem)
            {
                // Inventory
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_inventory)
                {
                    m_playerManager.sellInventorySlot(tEvent->data_1);
                }
            }

            // Component equip item
            else if (tEvent->type == eUIEventType::UIEventType_equipItem)
            {
                // Inventory
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_inventory)
                {
                    m_playerManager.equipInventorySlot(tEvent->data_1);
                }
            }

            // Component unequip item
            else if (tEvent->type == eUIEventType::UIEventType_unequipItem)
            {
                // Equipment menu
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_equipment)
                {
                    m_playerManager.unequip(tEvent->data_1);
                }
            }

            // Component drop menu
            else if (tEvent->type == eUIEventType::UIEventType_dropMenu)
            {
                // default source + destination states
                ePlayerStorageType source = ePlayerStorageType::playerStorageTypeNone;
                ePlayerStorageType destination = ePlayerStorageType::playerStorageTypeNone;

                // convert from eUIEventFunction to ePlayerStorageType -> source
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_actionBar)
                    source = ePlayerStorageType::playerStorageTypeActionBar;
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_equipment)
                    source = ePlayerStorageType::playerStorageTypeEquipment;
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_inventory)
                    source = ePlayerStorageType::playerStorageTypeInventory;
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_vendor)
                    source = ePlayerStorageType::playerStorageTypeVendor;
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_waypoints)
                    source = ePlayerStorageType::playerStorageTypeWaypoints;

                // convert from eUIEventFunction to ePlayerStorageType -> destination
                if (tEvent->function_2 == eUIEventFunction::UIEventFunction_actionBar)
                    destination = ePlayerStorageType::playerStorageTypeActionBar;
                else if (tEvent->function_2 == eUIEventFunction::UIEventFunction_equipment)
                    destination = ePlayerStorageType::playerStorageTypeEquipment;
                else if (tEvent->function_2 == eUIEventFunction::UIEventFunction_inventory)
                    destination = ePlayerStorageType::playerStorageTypeInventory;
                else if (tEvent->function_2 == eUIEventFunction::UIEventFunction_vendor)
                    destination = ePlayerStorageType::playerStorageTypeVendor;
                else if (tEvent->function_2 == eUIEventFunction::UIEventFunction_waypoints)
                    destination = ePlayerStorageType::playerStorageTypeWaypoints;

                // Storage move / swap
                m_playerManager.moveStorage(source, tEvent->data_1, destination, tEvent->data_2);
            }

            // Equipment change
            else if (tEvent->type == eUIEventType::UIEventType_equipmentChange)
            {
                // Have the player manager re-calculate player attributes
                m_playerManager.calculateAttributes();
            }

            // Unhandled event
            else
            {
                std::cout << "Unhandled ui event: " << static_cast<std::uint32_t>(tEvent->type) << std::endl;
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
                m_playerManager.targetHalt();
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
                m_playerManager.targetHalt();
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
                m_playerManager.targetHalt();
                m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
            }
        }

        // Pause game - GLFW_KEY_P
        if (m_IOManager.getKeyReadyState(GLFW_KEY_P))
        {
            m_IOManager.setKeyReadyState(GLFW_KEY_P, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_engineState = (m_engineState == eEngineState::engineStatePause) ? eEngineState::engineStateProc : eEngineState::engineStatePause;
            m_playerManager.targetHalt();
        }

        // Reload current map - GLFW_KEY_R
        if (m_IOManager.getKeyReadyState(GLFW_KEY_R))
        {
            m_IOManager.setKeyReadyState(GLFW_KEY_R, false);
            m_IOManager.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
            m_mapManager.reloadMap();
            m_playerManager.targetHalt();
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
                m_playerManager.targetHalt();
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
            if (menuState == true)
            {
                m_playerManager.targetHalt();
            }
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
            m_engineState = eEngineState::engineStateTerm;
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
}
