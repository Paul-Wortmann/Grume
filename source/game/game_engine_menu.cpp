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

void cGameEngine::m_process_menu(std::int64_t _dt)
{
        // Process systems
        m_uiManager.process();
        m_physicsEngine.setMouseOverMenu(m_uiManager.getMouseOverMenu());
        m_graphicsEngine.process(_dt);

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

        // Process UI events
        for (sUIEvent* tEvent = m_uiManager.getEvent(); tEvent != nullptr; tEvent = m_uiManager.getEvent())
        {
            // Component clicked
            if (tEvent->type == eUIEventType::UIEventType_click)
            {
                // Close menu
                if (tEvent->function_1 == eUIEventFunction::UIEventFunction_closeMenu)
                {
                    // close options menu
                    if (tEvent->menuType == eMenuType::menuTypeOptions)
                    {
                        m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, true);
                        m_uiManager.setMenuEnabled(eMenuType::menuTypeOptions, false);
                    }
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
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeActionBar, true);
                    m_uiManager.setMenuComponentEnabled(eComponentFunction::componentFunctionGameSave ,true);
                    //m_mapManager.setLoading(false);
                }

                // Game load
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_gameLoad)
                {
                    m_engineState = (m_uiManager.getActiveWindowCount() < 2) ? eEngineState::engineStateProc : m_engineState;
                    cGameEngine::m_game_load(1);
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, false);
                    m_uiManager.setMenuEnabled(eMenuType::menuTypeActionBar, true);
                    m_uiManager.setMenuComponentEnabled(eComponentFunction::componentFunctionGameSave ,true);
                    //m_mapManager.setLoading(false);
                }

                // Game save
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_gameSave)
                {
                    //m_engineState = (m_uiManager.getActiveWindowCount() < 2) ? eEngineState::engineStateProc : m_engineState;
                    //cGameEngine::m_game_save(1);
                }

                // options menu
                else if (tEvent->function_1 == eUIEventFunction::UIEventFunction_menuOptions)
                {
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
}
