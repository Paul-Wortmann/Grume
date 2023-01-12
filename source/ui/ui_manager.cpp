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

void cUIManager::setGold(const std::uint64_t &_gold)
{
    glm::uvec4 goldColor = glm::uvec4(212, 175, 055, 255);
    if (m_textGold == nullptr)
    {
        m_textGold = m_resourceManager->generateTexture(std::to_string(_gold), goldColor);
    }
    else
    {
        m_resourceManager->freeTexture(m_textGold);
        m_textGold = m_resourceManager->generateTexture(std::to_string(_gold), goldColor);
    }
}

void cUIManager::m_calculateScale(void)
{
    m_UIScale.x = static_cast<float>(m_UIResolution.x) / static_cast<float>(m_window_w);
    m_UIScale.y = static_cast<float>(m_UIResolution.y) / static_cast<float>(m_window_h);
}

bool cUIManager::getMenuEnabled(const eMenuType &_type)
{
    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].type == _type)
            {
                return m_menu[m].enabled;
            }
        }
    }
    return false;
}

void cUIManager::setMenuEnabled(const eMenuType &_type, const bool &_state)
{
    // Avoid unintended mouse clicks
    m_mouseOverMenu = false;
    m_mouseLClicked = false;
    m_mouseRClicked = false;

    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].type == _type)
            {
                m_menu[m].enabled = _state;
            }
        }
    }
}

void cUIManager::SetAllMenusDisabled(void)
{
    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if ((&m_menu[m] != nullptr) && (m_menu[m].type != eMenuType::menuTypeActionBar))
            {
                m_menu[m].enabled = false;
            }
        }
    }
}

void cUIManager::setMenuComponentEnabled(const eComponentFunction &_componentFunction ,const bool &_state)
{
    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            for (std::uint32_t c = 0; c < m_menu[m].numComponent; ++c)
            {
                if (m_menu[m].component[c].function == _componentFunction)
                {
                    m_menu[m].component[c].enabled = _state;
                }
            }
        }
    }
}

void cUIManager::process(void)
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
                                m_menu[m].component[c].state = eComponentState::componentStateHover;

                                // Mouse left click
                                if (m_mouseLClicked)
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

                                // Mouse left pressed
                                if (m_mouseLPressed)
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

                                // Mouse right click
                                if (m_mouseRClicked)
                                {
                                    // Inventory item drop
                                    if ((m_menu[m].component[c].function >= eComponentFunction::componentFunctionInventorySlot_1) &&
                                        (m_menu[m].component[c].function <= eComponentFunction::componentFunctionInventorySlot_54))
                                    {
                                        m_uiEvent = m_menu[m].component[c].function;
                                    }
                                }

                            }
                            else
                            {
                                // No hover or activate, mouse not over component
                                m_menu[m].component[c].state = eComponentState::componentStateNormal;
                            }
                        }
                    }
                }
            }
        }
        // Reset mouse clicked, as processed above
        m_mouseLClicked = false;
        m_mouseRClicked = false;
    }
}

void cUIManager::setMapTitle(const std::string &_mapTitle)
{
    m_mapTitle = _mapTitle;
    m_mapTitleTexture = m_resourceManager->generateTexture(m_mapTitle, glm::ivec4(230, 230, 230, 255));
}
