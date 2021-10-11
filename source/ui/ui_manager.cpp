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

void cUIManager::initialize(cEntityManager* _entityManager)
{
    m_entityManager = _entityManager;
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

void cUIManager::process(const std::uint32_t &_dt)
{
    //if mouse over a menu?
    if (m_menu != nullptr)
    {
        m_mouseOverMenu = false;
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            if (m_menu[m].enabled)
            {
                if ((m_menu[m].positionMin.x < m_mousePosition.x) &&
                    (m_menu[m].positionMax.x > m_mousePosition.x) &&
                    (m_menu[m].positionMin.y < m_mousePosition.y) &&
                    (m_menu[m].positionMax.y > m_mousePosition.y))
                {
                    m_mouseOverMenu = true;
                    for (std::uint32_t c = 0; c < m_menu[m].numComponent; ++c)
                    {
                        if ((m_menu[m].component[c].positionMin.x < m_mousePosition.x) &&
                            (m_menu[m].component[c].positionMax.x > m_mousePosition.x) &&
                            (m_menu[m].component[c].positionMin.y < m_mousePosition.y) &&
                            (m_menu[m].component[c].positionMax.y > m_mousePosition.y))
                        {
                            m_menu[m].component[c].state = eComponentState::componentHover;
                            
                            // Mouse click
                            if (m_mouseClicked)
                            {
                                if (m_menu[m].component[c].function == eComponentFunction::componentFunctionGameQuit)
                                {
                                    
                                }
                                else if (m_menu[m].component[c].function == eComponentFunction::componentFunctionCloseMenu)
                                {
                                    std::cout << "Close clicked!" << std::endl;
                                    m_menu[m].enabled = false;
                                    m_mouseOverMenu = false;
                                    m_menuActive = false;
                                }
                                else
                                {
                                    // Do nothing
                                }
                                m_mouseClicked = false;
                            }
                        }
                        else
                        {
                            m_menu[m].component[c].state = eComponentState::componentNormal;
                        }
                    }
                }
            }
        }
    }
}
