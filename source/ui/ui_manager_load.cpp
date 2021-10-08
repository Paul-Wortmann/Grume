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

void cUIManager::load(const std::string &_fileName)
{
    // Load the ui database file
    cXML xmlUiFile;
    xmlUiFile.load(FILE_PATH_UI + _fileName);
    
    // If ui database file contains data:
    if (xmlUiFile.lineCount() > 0)
    {
        // used to index into the xml file for menu components
        std::uint32_t startComponent = 0;
        
        // get a count of ui menus
        m_numMenu = xmlUiFile.getInstanceCount("<menu>");
        m_menu = new sUIMenu[m_numMenu];

        // load each ui menu
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            // load menu data
            m_menu[m].name = xmlUiFile.getString("<menu_name>", m + 1);
            m_menu[m].enabled = (xmlUiFile.getInteger("<menu_enabled>", m + 1) != 0);
            m_menu[m].textureNormal = m_entityManager->loadTexture(xmlUiFile.getString("<menu_texture_normal>", m + 1));
            m_menu[m].position = xmlUiFile.getVec3("<menu_position>", m + 1);
            m_menu[m].size = xmlUiFile.getVec2("<menu_size>", m + 1);
            
            // Calculate scale
            m_menu[m].scale = glm::vec2(m_menu[m].size.x, m_menu[m].size.y);
            
            // Calculate menu size in pixels
            std::uint32_t menuSizePixels_x = (m_menu[m].size.x * m_window_w);
            std::uint32_t menuSizePixels_y = (m_menu[m].size.y * m_window_h);
            
            // Calculate menu position in pixels
            std::uint32_t menuPosPixels_x = (1 - m_menu[m].position.x) * m_window_w / 2;
            std::uint32_t menuPosPixels_y = (1 - m_menu[m].position.y) * m_window_h / 2;
            
            // Calculate menu bounds
            m_menu[m].positionMin.x = menuPosPixels_x - (menuSizePixels_x / 2);
            m_menu[m].positionMin.y = menuPosPixels_y - (menuSizePixels_y / 2);
            m_menu[m].positionMax.x = menuPosPixels_x + (menuSizePixels_x / 2);
            m_menu[m].positionMax.y = menuPosPixels_y + (menuSizePixels_y / 2);

            //std::cout << "Menu: " << m << std::endl;
            //std::cout << "Min x: " << m_menu[m].positionMin.x << " Max x: " << m_menu[m].positionMax.x << std::endl;
            //std::cout << "Min y: " << m_menu[m].positionMin.y << " Max y: " << m_menu[m].positionMax.y << std::endl;

            // get a count of ui components for the current menu
            m_menu[m].numComponent = xmlUiFile.getInteger("<menu_component_count>", m + 1);
            if (m_menu[m].numComponent > 0)
            {
                // Allocate memory
                m_menu[m].component = new sUIComponent[m_menu[m].numComponent];

                // load each ui component
                for (std::uint32_t c = 0; c < m_menu[m].numComponent; ++c)
                {
                    m_menu[m].component[c].name = xmlUiFile.getString("<component_name>", c + 1 + startComponent);
                    m_menu[m].component[c].textureNormal = m_entityManager->loadTexture(xmlUiFile.getString("<component_texture_normal>", c + 1 + startComponent));
                    m_menu[m].component[c].textureHover  = m_entityManager->loadTexture(xmlUiFile.getString("<component_texture_hover>", c + 1 + startComponent));
                    m_menu[m].component[c].textureActive = m_entityManager->loadTexture(xmlUiFile.getString("<component_texture_activated>", c + 1 + startComponent));
                    m_menu[m].component[c].position = xmlUiFile.getVec3("<component_position>", c + 1 + startComponent);
                    m_menu[m].component[c].size = xmlUiFile.getVec2("<component_size>", c + 1 + startComponent);
            
                    // Calculate scale
                    m_menu[m].component[c].scale = glm::vec2(m_menu[m].component[c].size.x, m_menu[m].component[c].size.y);

                    // Calculate menu size in pixels
                    std::uint32_t menuCompSizePixels_x = (m_menu[m].component[c].size.x * m_window_w);
                    std::uint32_t menuCompSizePixels_y = (m_menu[m].component[c].size.y * m_window_h);

                    // Calculate menu position in pixels
                    std::uint32_t menuCompPosPixels_x = (1 - m_menu[m].component[c].position.x) * m_window_w / 2;
                    std::uint32_t menuCompPosPixels_y = (1 - m_menu[m].component[c].position.y) * m_window_h / 2;

                    // Calculate menu bounds
                    m_menu[m].component[c].positionMin.x = menuCompPosPixels_x - (menuCompSizePixels_x / 2);
                    m_menu[m].component[c].positionMin.y = menuCompPosPixels_y - (menuCompSizePixels_y / 2);
                    m_menu[m].component[c].positionMax.x = menuCompPosPixels_x + (menuCompSizePixels_x / 2);
                    m_menu[m].component[c].positionMax.y = menuCompPosPixels_y + (menuCompSizePixels_y / 2);

                }
            }

            // Update the component start number for the following menu to be loaded
            startComponent += m_menu[m].numComponent;
        }
    }
    
    // Cleanup
    xmlUiFile.free();

}

