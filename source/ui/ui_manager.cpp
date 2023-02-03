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
    m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
    m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
    m_io->keyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;
    m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;

    m_mouseOverMenu = false;

    if (m_menu != nullptr)
    {
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].type == _type)
            {
                m_menu[m].enabled = _state;

                // Open menu audio
                if ((_state == true) && (m_menu[m].audio_open.sound != nullptr))
                {
                    m_audioEngine->playSound(m_menu[m].audio_open.sound->data);
                }
                // Close menu audio
                else if ((_state == false) && (m_menu[m].audio_close.sound != nullptr))
                {
                    m_audioEngine->playSound(m_menu[m].audio_close.sound->data);
                }
            }
        }
    }
}

void cUIManager::SetAllMenusDisabled(void)
{
    // Avoid unintended mouse clicks
    m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
    m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
    m_io->keyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;
    m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;

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
    // Reset state
    m_mouseOverMenu = false;
    m_mouseOverComponent = false;
    std::uint32_t menuNum = 0;
    std::uint32_t componentNum = 0;
    m_activeWindowCount = 0;

    // If menu data structure exists
    if (m_menu != nullptr)
    {
        // determine which menu and component the mouse is over
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if ((!m_mouseOverMenu) && (m_menu[m].enabled))
            {
                m_activeWindowCount++;

                // If mouse over window
                if ((m_menu[m].positionMin.x < m_io->mousePositionGL.x) &&
                    (m_menu[m].positionMax.x > m_io->mousePositionGL.x) &&
                    (m_menu[m].positionMin.y < m_io->mousePositionGL.y) &&
                    (m_menu[m].positionMax.y > m_io->mousePositionGL.y))
                {
                    m_mouseOverMenu = true;
                    menuNum = m;

                    // Loop through all menu components
                    for (std::uint32_t c = 0; c < m_menu[m].numComponent; ++c)
                    {
                        // If mouse over component
                        if ((m_menu[m].component[c].positionMin.x < m_io->mousePositionGL.x) &&
                            (m_menu[m].component[c].positionMax.x > m_io->mousePositionGL.x) &&
                            (m_menu[m].component[c].positionMin.y < m_io->mousePositionGL.y) &&
                            (m_menu[m].component[c].positionMax.y > m_io->mousePositionGL.y))
                        {
                            m_mouseOverComponent = true;
                            componentNum = c;

                            // Set mouse hover
                            if ((m_menu[m].component[c].enabled) &&
                                (m_menu[m].component[c].state != eComponentState::componentStateHover) &&
                                (m_menu[m].component[c].state != eComponentState::componentStateDragged))
                            {
                                m_menu[m].component[c].state = eComponentState::componentStateHover;

                                // Play hover component audio
                                if (m_menu[m].component[c].audio_hover.sound != nullptr)
                                {
                                    m_audioEngine->playSound(m_menu[m].component[c].audio_hover.sound->data);
                                }
                            }
                        }

                        // disable hover
                        else
                        {
                            // No hover as mouse not over component
                            if (m_menu[m].component[c].state != eComponentState::componentStateDragged)
                            {
                                m_menu[m].component[c].state = eComponentState::componentStateNormal;
                            }
                        }
                    }
                }
            }
        }

        // Drop item if dragged
        if ((m_io->mouseDrag) && (m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT]))
        {
            // event struct
            sUIEvent* event = nullptr;

            bool dropGround = false;
            bool dropMenu = false;

            if (!m_mouseOverMenu)
                dropGround = true;
            else if (m_mouseOverMenu && m_mouseOverComponent && (m_menu[menuNum].component[componentNum].type == eComponentType::componentTypeItem))
                dropMenu = true;

            // Drop ground
            if (dropGround || dropMenu)
            {
                // create event
                event = new sUIEvent;
                event->type = eUIEventType::UIEventType_dropGround;

                // Function 1
                if (m_menu[m_dragMenu].type == eMenuType::menuTypeActionBar)
                    event->function_1 = eUIEventFunction::UIEventFunction_actionBar;
                else if (m_menu[m_dragMenu].type == eMenuType::menuTypeEquipment)
                    event->function_1 = eUIEventFunction::UIEventFunction_equipment;
                else if (m_menu[m_dragMenu].type == eMenuType::menuTypeInventory)
                    event->function_1 = eUIEventFunction::UIEventFunction_inventory;
                else if (m_menu[m_dragMenu].type == eMenuType::menuTypeVendor)
                    event->function_1 = eUIEventFunction::UIEventFunction_vendor;
                else if (m_menu[m_dragMenu].type == eMenuType::menuTypeWayPoints)
                    event->function_1 = eUIEventFunction::UIEventFunction_waypoints;
                else
                    event->function_1 = eUIEventFunction::UIEventFunction_none;

                // Data 1
                event->data_1 = m_dragSlot;
            }

            // Drop menu
            if (dropMenu)
            {
                event->type = eUIEventType::UIEventType_dropMenu;

                m_dropMenu = menuNum;
                m_dropComponent = componentNum;

                // slot number (inventory)
                if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionInventorySlot_1) &&
                    (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionInventorySlot_54))
                {
                    m_dropSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionInventorySlot_1);
                    event->function_2 = eUIEventFunction::UIEventFunction_inventory;
                }
                // slot number (action bar)
                else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionActionBarSlot_1) &&
                         (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionActionBarSlot_12))
                {
                    m_dropSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarSlot_1);
                    event->function_2 = eUIEventFunction::UIEventFunction_actionBar;
                }
                // slot number (vendor)
                else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionVendorSlot_1) &&
                         (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionVendorSlot_54))
                {
                    m_dropSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionVendorSlot_1);
                    event->function_2 = eUIEventFunction::UIEventFunction_vendor;
                }
                // slot number (equipment)
                else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionEquipmentSlot_1) &&
                         (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionEquipmentSlot_14))
                {
                    m_dropSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionEquipmentSlot_1);
                    event->function_2 = eUIEventFunction::UIEventFunction_equipment;
                }
                // slot number (waypoints)
                else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionWaypointsSlot_1) &&
                         (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionWaypointsSlot_6))
                {
                    m_dropSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionWaypointsSlot_1);
                    event->function_2 = eUIEventFunction::UIEventFunction_waypoints;
                }

                // Data 2
                event->data_2 = m_dropSlot;

            }

            // Push event
            if (event != nullptr)
                m_event.push(event);

            m_menu[m_dragMenu].component[m_dragComponent].state = eComponentState::componentStateNormal;
            m_io->mouseDrag = false;
            if ((event != nullptr) && (event->type == eUIEventType::UIEventType_dropGround))
                std::cout << "Exiting mouse drag: drop ground." << std::endl;
            else if ((event != nullptr) && (event->type == eUIEventType::UIEventType_dropMenu))
                std::cout << "Exiting mouse drag: drop menu." << std::endl;
            else
                std::cout << "Exiting mouse drag" << std::endl;
        }

        // Handle mouse component interaction
        else if (m_menu[menuNum].component[componentNum].enabled && !m_io->mouseDrag)
        {
            // Mouse left click
            if (m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT])
            {
                // avoid double click
                m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;

                // activate component audio
                if (m_menu[menuNum].component[componentNum].audio_activate.sound != nullptr)
                {
                    m_audioEngine->playSound(m_menu[menuNum].component[componentNum].audio_activate.sound->data);
                }

                // Game quit
                if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionGameQuit)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_gameQuit;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                    m_menu[menuNum].enabled = false;
                    m_mouseOverMenu = false;
                    m_activeWindowCount--;
                }
                // Close menu
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionCloseMenu)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_closeMenu;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                    m_menu[menuNum].enabled = false;
                    m_mouseOverMenu = false;
                    m_activeWindowCount--;
                }
                // Game new
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionGameNew)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_gameNew;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                }
                // Game save
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionGameSave)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_gameSave;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                    m_menu[menuNum].enabled = false;
                    m_mouseOverMenu = false;
                    m_activeWindowCount--;
                }
                // Game load
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionGameLoad)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_gameLoad;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                    m_menu[menuNum].enabled = false;
                    m_mouseOverMenu = false;
                    m_activeWindowCount--;
                }
                // Menu Options
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionMenuOptions)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_menuOptions;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                    m_mouseOverMenu = false;
                }
                // Fullscreen modified
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionFullscreenModified)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_fullscreenModified;
                    event->data_1 = 0;
                    m_event.push(event);

                    // set data
                }
                // Load map waypoint town
                else if ((m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionLoadMapTown_1) ||
                         (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionLoadMapTown_2) ||
                         (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionLoadMapTown_3) ||
                         (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionLoadMapTown_4) ||
                         (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionLoadMapTown_5) ||
                         (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionLoadMapTown_6))
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_loadMapTown;
                    event->data_1 = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionLoadMapTown_1);
                    m_event.push(event);

                    // set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateNormal;
                    m_menu[menuNum].enabled = false;
                    m_mouseOverMenu = false;
                    m_activeWindowCount--;
                }
            }

            // Mouse right click
            if (m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT])
            {
                // avoid double click
                m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;

                // Inventory item drop
                if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionInventorySlot_1) &&
                    (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionInventorySlot_54))
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_dropGround;
                    event->function_1 = eUIEventFunction::UIEventFunction_inventory;
                    event->data_1 = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionInventorySlot_1);
                    m_event.push(event);
                }
            }

            // Mouse left pressed
            if (m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT])
            {

                // Enter mouse drag if item
                if ((!m_io->mouseDrag) && (m_menu[menuNum].component[componentNum].type == eComponentType::componentTypeItem))
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_drag;

                    // Set data
                    m_menu[menuNum].component[componentNum].state = eComponentState::componentStateDragged;
                    m_io->mouseDrag = true;
                    m_dragMenu = menuNum;
                    m_dragComponent = componentNum;

                    // slot number (inventory)
                    if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionInventorySlot_1) &&
                        (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionInventorySlot_54))
                    {
                        m_dragSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionInventorySlot_1);
                        event->function_1 = eUIEventFunction::UIEventFunction_inventory;
                    }
                    // slot number (action bar)
                    else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionActionBarSlot_1) &&
                             (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionActionBarSlot_12))
                    {
                        m_dragSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarSlot_1);
                        event->function_1 = eUIEventFunction::UIEventFunction_actionBar;
                    }
                    // slot number (vendor)
                    else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionVendorSlot_1) &&
                             (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionVendorSlot_54))
                    {
                        m_dragSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionVendorSlot_1);
                        event->function_1 = eUIEventFunction::UIEventFunction_vendor;
                    }
                    // slot number (equipment)
                    else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionEquipmentSlot_1) &&
                             (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionEquipmentSlot_14))
                    {
                        m_dragSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionEquipmentSlot_1);
                        event->function_1 = eUIEventFunction::UIEventFunction_equipment;
                    }
                    // slot number (waypoints)
                    else if ((m_menu[menuNum].component[componentNum].function >= eComponentFunction::componentFunctionWaypointsSlot_1) &&
                             (m_menu[menuNum].component[componentNum].function <= eComponentFunction::componentFunctionWaypointsSlot_6))
                    {
                        m_dragSlot = static_cast<std::uint32_t>(m_menu[menuNum].component[componentNum].function) - static_cast<std::uint32_t>(eComponentFunction::componentFunctionWaypointsSlot_1);
                        event->function_1 = eUIEventFunction::UIEventFunction_waypoints;
                    }

                    // push event
                    event->data_1 = m_dragSlot;
                    m_event.push(event);

                    std::cout << "Entering mouse drag." << std::endl;
                }

                // Music volume up
                if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionVolumeMusicUp)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_volumeMusicUp;
                    event->data_1 = 0;
                    m_event.push(event);
                }
                // Music volume down
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionVolumeMusicDown)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_volumeMusicDown;
                    event->data_1 = 0;
                    m_event.push(event);
                }
                // Sound volume up
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionVolumeSoundUp)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_volumeSoundUp;
                    event->data_1 = 0;
                    m_event.push(event);
                }
                // Sound volume down
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionVolumeSoundDown)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_volumeSoundDown;
                    event->data_1 = 0;
                    m_event.push(event);
                }
                // Master volume up
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionVolumeMasterUp)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_volumeMasterUp;
                    event->data_1 = 0;
                    m_event.push(event);
                }
                // Master volume down
                else if (m_menu[menuNum].component[componentNum].function == eComponentFunction::componentFunctionVolumeMasterDown)
                {
                    // create event
                    sUIEvent* event = new sUIEvent;
                    event->type = eUIEventType::UIEventType_click;
                    event->function_1 = eUIEventFunction::UIEventFunction_volumeMasterDown;
                    event->data_1 = 0;
                    m_event.push(event);
                }
            }

            // Mouse right presses
            if (m_io->keyMap[GLFW_MOUSE_BUTTON_RIGHT])
            {
            }

        }

        // avoid double click
        m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
        m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;
    }
}

void cUIManager::setMapTitle(const std::string &_mapTitle)
{
    m_mapTitle = _mapTitle;
    m_mapTitleTexture = m_resourceManager->generateTexture(m_mapTitle, glm::ivec4(230, 230, 230, 255));
}
