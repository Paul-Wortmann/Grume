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

#include "ui_manager.hpp"

std::uint32_t cUIManager::initialize(void)
{
    return EXIT_SUCCESS;
}

void cUIManager::terminate(void)
{
    // free menu data
    if (m_menu != nullptr)
    {
        // free component data
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].component != nullptr)
            {
                // Delete components
                delete [] m_menu[m].component;
                m_menu[m].component = nullptr;
            }
        }

        // delete menus
        delete [] m_menu;
        m_menu = nullptr;
    }
}

bool cUIManager::getMenuEnabled(const std::string &_name)
{
    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].name.compare(_name) == 0)
            {
                return m_menu[m].enabled;
            }
        }
    }
    return false;
}

void cUIManager::setMenuEnabled(const std::string &_name, const bool &_state)
{
    // Avoid unintended mouse clicks
    m_mouseOverMenu = false;
    m_mouseClicked  = false;

    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].name.compare(_name) == 0)
            {
                m_menu[m].enabled = _state;
            }
        }
    }
}

void cUIManager::process(const float &_dt)
{
    // If menu data structure exists
    if (m_menu != nullptr)
    {
        // Reset state
        m_mouseOverMenu = false;
        m_activeWindowCount = 0;

        // Loop through all menus
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].enabled)
            {
                m_activeWindowCount++;

                // If mouse over window
                if ((m_menu[m].positionMin.x < m_mousePosition.x) &&
                    (m_menu[m].positionMax.x > m_mousePosition.x) &&
                    (m_menu[m].positionMin.y < m_mousePosition.y) &&
                    (m_menu[m].positionMax.y > m_mousePosition.y))
                {
                    m_mouseOverMenu = true;

                    // Loop through all menu components
                    for (std::uint32_t c = 0; c < m_menu[m].numComponent; ++c)
                    {
                        if (m_menu[m].component[c].enabled)
                        {
                            // If mouse over component
                            if ((m_menu[m].component[c].positionMin.x < m_mousePosition.x) &&
                                (m_menu[m].component[c].positionMax.x > m_mousePosition.x) &&
                                (m_menu[m].component[c].positionMin.y < m_mousePosition.y) &&
                                (m_menu[m].component[c].positionMax.y > m_mousePosition.y))
                            {
                                // Set mouse hover
                                m_menu[m].component[c].state = eComponentState::componentHover;

                                // Mouse click
                                if (m_mouseClicked)
                                {
                                    // Game quit
                                    if (m_menu[m].component[c].function == eComponentFunction::componentFunctionGameQuit)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                        m_menu[m].enabled = false;
                                        m_mouseOverMenu = false;
                                        m_activeWindowCount--;
                                    }
                                    // Close menu
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionCloseMenu)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                        m_menu[m].enabled = false;
                                        m_mouseOverMenu = false;
                                        m_activeWindowCount--;
                                    }
                                    // Game new
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionGameNew)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Game save
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionGameSave)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                        m_menu[m].enabled = false;
                                        m_mouseOverMenu = false;
                                        m_activeWindowCount--;
                                    }
                                    // Game load
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionGameLoad)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                        m_menu[m].enabled = false;
                                        m_mouseOverMenu = false;
                                        m_activeWindowCount--;
                                    }
                                    // Menu Options
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionMenuOptions)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                        m_mouseOverMenu = false;
                                    }
                                    // Fullscreen modified
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionFullscreenModified)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Load map waypoint town
                                    else if ((m_menu[m].component[c].function == eComponentFunction::componentFunctionLoadMapTown_1) ||
                                             (m_menu[m].component[c].function == eComponentFunction::componentFunctionLoadMapTown_2) ||
                                             (m_menu[m].component[c].function == eComponentFunction::componentFunctionLoadMapTown_3) ||
                                             (m_menu[m].component[c].function == eComponentFunction::componentFunctionLoadMapTown_4) ||
                                             (m_menu[m].component[c].function == eComponentFunction::componentFunctionLoadMapTown_5) ||
                                             (m_menu[m].component[c].function == eComponentFunction::componentFunctionLoadMapTown_6))
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                        m_menu[m].enabled = false;
                                        m_mouseOverMenu = false;
                                        m_activeWindowCount--;
                                    }
                                    else
                                    {
                                        // Do nothing
                                        m_uiEvent = eComponentFunction::componentFunctionNone;
                                    }
                                }

                                // Mouse pressed
                                if (m_mousePressed)
                                {
                                    // Music volume up
                                    if (m_menu[m].component[c].function == eComponentFunction::componentFunctionVolumeMusicUp)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Music volume down
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionVolumeMusicDown)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Sound volume up
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionVolumeSoundUp)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Sound volume down
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionVolumeSoundDown)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Master volume up
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionVolumeMasterUp)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                    // Master volume down
                                    else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionVolumeMasterDown)
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                }
                            }
                            else
                            {
                                // No hover or activate, mouse not over component
                                m_menu[m].component[c].state = eComponentState::componentNormal;
                            }
                        }
                    }
                }
            }
        }
        // Reset mouse clicked, as processed above
        m_mouseClicked = false;
    }
}

void cUIManager::setMapTitle(const std::string &_mapTitle)
{
    m_mapTitle = _mapTitle;
    m_mapTitleTexture = m_resourceManager->generateTexture(m_mapTitle, glm::vec4(230, 230, 230, 255));
}
