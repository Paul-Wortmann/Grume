/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"

void cMapManager::m_mapPrefabRooms(sMap*& _map)
{
    // Open the prefab database file
    std::uint32_t prefabCount = 0;
    
    cXML xmlMapPrefabDatabaseFile;
    xmlMapPrefabDatabaseFile.load(FILE_PATH_BIOME + _map->biome->allMapPrefabList.fileName);
    if (xmlMapPrefabDatabaseFile.lineCount() > 0)
    {
        // Get the data from the XML file
        prefabCount      = xmlMapPrefabDatabaseFile.getInstanceCount("<prefab>");

        gLogWrite(LOG_INFO, "Prefab count: " + std::to_string(prefabCount), __FILE__, __LINE__, __FUNCTION__);

        // loop through each room in the map
        for (std::uint32_t r = 0; r < _map->roomCount; ++r)
        {
            // loop through each prefab
            for (std::uint32_t p = 0; p < prefabCount; ++p)
            {
                std::string tPrefabString = xmlMapPrefabDatabaseFile.getString("<prefab>", p + 1);
                tPrefabString += "    ";
                std::uint32_t tPrefabStringLength = tPrefabString.length();
                std::uint32_t tPrefabRoomType   = 0;
                std::uint32_t tPrefabRoomWidth  = 0;
                std::uint32_t tPrefabRoomHeight = 0;
                std::string   tPrefabFileName   = 0;
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tPrefabStringLength > 6)
                {
                    for (std::uint32_t j = 0; j < tPrefabStringLength; ++j)
                    {
                        if (tPrefabString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                tPrefabRoomType = std::stoi(tString);
                            }
                            else if (tStringNum == 1)
                            {
                                tPrefabRoomWidth = std::stoi(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                tPrefabRoomHeight = std::stoi(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                tPrefabFileName = std::string(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tPrefabString[j];
                        }
                    }
                }
                // look for a match and apply the prefab
                if ((_map->room[r].w == tPrefabRoomWidth) &&
                    (_map->room[r].h == tPrefabRoomHeight) &&
                    ((_map->room[r].type == eMapRoomType::roomTypeNone) || 
                     (_map->room[r].type == static_cast<eMapRoomType>(tPrefabRoomType))))
                {
                    m_mapApplyPrefab(_map, tPrefabFileName, r);
                    p = prefabCount;
                }
            }
            
        }

        // Clean up
        xmlMapPrefabDatabaseFile.free();
    }
}

void cMapManager::m_mapApplyPrefab(sMap*& _map, const std::string &_fileName, const std::uint32_t &_r)
{
    
}