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

void cMapManager::m_addEvents(void)
{
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + m_map->info.fileName);
    if (mapFile.isValid())
    {
        // Map Events
        m_map->numEvent = mapFile.getInstanceCount("<event>");
        if (m_map->numEvent > 0)
        {
            // Allocate memory for event data
            m_map->event = new sMapEvent[m_map->numEvent];

            // Data parsing
            std::string   dataString       = {};
            std::uint64_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};

            // Temporary data
            std::uint32_t tile_x = 0;
            std::uint32_t tile_y = 0;
            std::uint32_t triggerTile_x = 0;
            std::uint32_t triggerTile_y = 0;

            // Get and process each event entry
            for (std::uint32_t i = 0; i < m_map->numEvent; ++i)
            {
                // Get data
                dataString  = mapFile.getString("<event>", i + 1);
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";

                // Process data
                /// # Event number, type, tile x, y, trigger tile x, y, database map name, repeat
                if (dataStringLength > 4)
                {
                    for (std::uint64_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                ; // Event number
                            }
                            else if (tStringNum == 1)
                            {
                                m_map->event[i].type = static_cast<eMapEventType>(std::stoi(tString)); // event type
                            }
                            else if (tStringNum == 2)
                            {
                                tile_x = std::stoi(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                tile_y = std::stoi(tString);
                            }
                            else if (tStringNum == 4)
                            {
                                triggerTile_x = std::stoi(tString);
                            }
                            else if (tStringNum == 5)
                            {
                                triggerTile_y = std::stoi(tString);
                            }
                            else if (tStringNum == 6)
                            {
                                m_map->event[i].trigger_name = tString; // map name
                            }
                            else if (tStringNum == 7)
                            {
                                m_map->event[i].repeat = (std::stoi(tString) > 0); // repeat
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }
                        m_map->event[i].tile         = (tile_y * m_map->info.size_x) + tile_x;
                        m_map->event[i].trigger_tile = (triggerTile_y * m_map->info.size_x) + triggerTile_x;
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

