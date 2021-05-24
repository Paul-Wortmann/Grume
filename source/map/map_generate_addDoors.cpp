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

// Generate door entities
void cMapManager::m_addDoorEntities(sMap*& _map)
{
    // Reset tile processed flags
    for (std::size_t i = 0; i < _map->numTiles; ++i)
    {
        _map->tile[i].processed = false;
    }

    // Map floor position on the y axis
    float32 y_pos = -1.0f;
    
    // Load the biome wallset file (includes doors)
    cXML xmlFile;
    xmlFile.load(FILE_PATH_BIOME + _map->biome->WallSet.fileName);
    
    // Only contine if we can load the biome wallset file
    if (xmlFile.lineCount() > 0)
    {
        // Get a count for door type
        std::uint32_t door_1td_count = xmlFile.getInteger("<door_1td_count>", 1); // Doors, length 3
        std::uint32_t door_2td_count = xmlFile.getInteger("<door_2td_count>", 1); // Doors, length 2
        std::uint32_t door_3td_count = xmlFile.getInteger("<door_3td_count>", 1); // Doors, length 1

        // Width and height offset, used to center the doors
        uint32  xo = _map->width  / 2;
        uint32  yo = _map->height / 2;
        float32 tp = 1.0f / 2.0f; // tile center positioning ( half tile width)

        // Doors of length 3 ----------------------------------------------------------------------------------
        for (uint32 h = 1; h < _map->height - 1; ++h)
        {
            for (uint32 w = 1; w < _map->width - 1; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                if ((m_isDoor(_map, t)) && (!_map->tile[t].processed) && (_map->tile[t].object == 0))
                {
                    // Create a temporary entity pointer
                    sEntity* tEntity = nullptr;

                    // F F F
                    // D - D
                    // F F F
                    if     ((m_isDoor (_map, t + 1)) &&
                            (m_isDoor (_map, t - 1)) &&
                            (m_isFloor(_map, t + _map->width)) &&
                            (m_isFloor(_map, t + _map->width + 1)) &&
                            (m_isFloor(_map, t + _map->width - 1)) &&
                            (m_isFloor(_map, t - _map->width)) &&
                            (m_isFloor(_map, t - _map->width + 1)) &&
                            (m_isFloor(_map, t - _map->width - 1)))
                            {
                                tEntity = m_entityManager->load(xmlFile.getString("<door_3td_entity>", 1 + (rand() % door_3td_count)));
                                if (tEntity != nullptr)
                                {
                                    _map->tile[t].object = tEntity->UID;
                                    tEntity->owner = eEntityOwner::ownerMap;
                                    tEntity->type  = eEntityType::entityTypeObject;
                                    tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                    tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                                    m_entityManager->updateModelMatrix(tEntity);
                                    
                                    _map->tile[t].processed = true;
                                    _map->tile[t + 1].processed = true;
                                    _map->tile[t - 1].processed = true;

                                    m_addMapEvent(_map, t + _map->width + 0, 2, t, 1, 0);
                                    m_addMapEvent(_map, t + _map->width + 1, 2, t, 1, 0);
                                    m_addMapEvent(_map, t + _map->width - 1, 2, t, 1, 0);
                                    m_addMapEvent(_map, t - _map->width + 0, 2, t, 1, 0);
                                    m_addMapEvent(_map, t - _map->width + 1, 2, t, 1, 0);
                                    m_addMapEvent(_map, t - _map->width - 1, 2, t, 1, 0);
                                }
                            }
                            
                    // F D F
                    // F - F
                    // F D F
                    else if ((m_isFloor(_map, t + 1)) &&
                            (m_isFloor(_map, t - 1)) &&
                            (m_isDoor (_map, t + _map->width)) &&
                            (m_isFloor(_map, t + _map->width + 1)) &&
                            (m_isFloor(_map, t + _map->width - 1)) &&
                            (m_isDoor (_map, t - _map->width)) &&
                            (m_isFloor(_map, t - _map->width + 1)) &&
                            (m_isFloor(_map, t - _map->width - 1)))
                            {
                                tEntity = m_entityManager->load(xmlFile.getString("<door_3td_entity>", 1 + (rand() % door_3td_count)));
                                if (tEntity != nullptr)
                                {
                                    _map->tile[t].object = tEntity->UID;
                                    tEntity->owner = eEntityOwner::ownerMap;
                                    tEntity->type  = eEntityType::entityTypeObject;
                                    tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                    tEntity->rotation += glm::vec3(0.0f, 0.0f, 0.0f);
                                    m_entityManager->updateModelMatrix(tEntity);
                                    
                                    _map->tile[t].processed = true;
                                    _map->tile[t + _map->width].processed = true;
                                    _map->tile[t - _map->width].processed = true;

                                    m_addMapEvent(_map, t + 1              , 2, t, 1, 0);
                                    m_addMapEvent(_map, t + _map->width + 1, 2, t, 1, 0);
                                    m_addMapEvent(_map, t + _map->width - 1, 2, t, 1, 0);
                                    m_addMapEvent(_map, t - 1              , 2, t, 1, 0);
                                    m_addMapEvent(_map, t - _map->width + 1, 2, t, 1, 0);
                                    m_addMapEvent(_map, t - _map->width - 1, 2, t, 1, 0);
                                }
                            }
                }
            }
        }

        // Doors of length 2 ----------------------------------------------------------------------------------
        // Doors of length 1 --------------------------------------------------------------------------------------------
 
        // Clean up
        xmlFile.free();
    }
}
