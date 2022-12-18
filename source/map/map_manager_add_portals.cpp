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

void cMapManager::m_addPortals(void)
{
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + m_map->info.fileName);
    if (mapFile.isValid())
    {
        // Map portals
        m_map->numPortal = mapFile.getInstanceCount("<portal>");
        if (m_map->numPortal > 0)
        {
            // Allocate memory for portal data
            m_map->portal = new sMapPortal[m_map->numPortal];

            // Data parsing
            std::string   dataString       = {};
            std::uint64_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};

            // Temporary data
            std::uint32_t tile_x = 0;
            std::uint32_t tile_y = 0;

            // Get and process each portal entry
            for (std::uint32_t i = 0; i < m_map->numPortal; ++i)
            {
                // Get data
                dataString  = mapFile.getString("<portal>", i + 1);
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";

                // Process data
                /// # Portal number, map from database name, and portal, tile location x, y, player face direction
                if (dataStringLength > 4)
                {
                    for (std::uint64_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                ; // Portal number
                            }
                            else if (tStringNum == 1)
                            {
                                m_map->portal[i].mapFrom = tString; // name of map we are coming from
                            }
                            else if (tStringNum == 2)
                            {
                                m_map->portal[i].portalFrom = std::stoi(tString); // portal number of map we are coming from
                            }
                            else if (tStringNum == 3)
                            {
                                tile_x = std::stoi(tString);
                            }
                            else if (tStringNum == 4)
                            {
                                tile_y = std::stoi(tString);
                            }
                            else if (tStringNum == 5)
                            {
                                m_map->portal[i].rotation = std::stof(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }
                        m_map->portal[i].tile = (tile_y * m_map->info.size_x) + tile_x;
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_map->info.fileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    mapFile.free();
}

