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

// Generate torch entities
void cMapManager::m_addTorchEntities(sMap*& _map)
{
    // Reset tile processed flags
    for (std::uint32_t i = 0; i < _map->numTiles; ++i)
    {
        _map->tile[i].processed = false;
    }
    
    // Load the biome wallset file (includes torches)
    cXML xmlFile;
    xmlFile.load(FILE_PATH_BIOME + _map->biome->WallSet.fileName);
    
    // Only contine if we can load the biome wallset file
    if (xmlFile.lineCount() > 0)
    {
        // Get a count for torch type
        std::uint32_t torch_1td_count = xmlFile.getInteger("<torch_1td_count>", 1); // Torch

        // Width and height offset, used to center the torches
        float xo = static_cast<float>(_map->width  / 2);
        float yo = static_cast<float>(_map->height / 2);

        // Doors of length 1 --------------------------------------------------------------------------------------------
        for (std::uint32_t h = 1; h < _map->height - 1; ++h)
        {
            for (std::uint32_t w = 1; w < _map->width - 1; ++w)
            {
                // Random placement
                if ((rand() % 100) < 20) // 20% chance
                {

                    // Calculate the tile number
                    std::uint32_t t = (h * _map->width) + w;

                    if ((m_isWall(_map, t)) && 
                        (!_map->tile[t].processed) && 
                        (_map->tile[t + 1].object == 0) && 
                        (_map->tile[t - 1].object == 0) && 
                        (_map->tile[t + _map->width].object == 0) && 
                        (_map->tile[t - _map->width].object == 0))
                    {
                        // Create temporary entity pointers
                        sEntity* tEntity_1 = nullptr;
                        sEntity* tEntity_2 = nullptr;

                        // ? F ?
                        // W - W
                        // ? F ?
                        if     ((m_isWall (_map, t + 1)) &&
                                (m_isWall (_map, t - 1)) &&
                                (m_isFloor(_map, t + _map->width)) &&
                                (m_isFloor(_map, t - _map->width)))
                        {
                            tEntity_1 = m_entityManager->load(xmlFile.getString("<torch_1td_entity>", 1 + (rand() % torch_1td_count)));
                            tEntity_2 = m_entityManager->load(xmlFile.getString("<torch_1td_entity>", 1 + (rand() % torch_1td_count)));
                            if ((tEntity_1 != nullptr) && (tEntity_2 != nullptr))
                            {
                                // Tile entity occupies
                                tEntity_1->tile = t + _map->width;
                                tEntity_2->tile = t - _map->width;

                                // Set object UID on relevant map tiles
                                _map->tile[tEntity_1->tile].object     = tEntity_1->UID;
                                _map->tile[tEntity_2->tile].object     = tEntity_2->UID;

                                // Set base tile to relevant collision enum
                                //_map->tile[tEntity_1->tile].base     = eTileBase::tileFloorNoGo;
                                //_map->tile[tEntity_2->tile].base     = eTileBase::tileFloorNoGo;

                                // Torch 1 placement
                                tEntity_1->owner = eEntityOwner::ownerMap;
                                tEntity_1->type  = eEntityType::entityTypeObject;
                                tEntity_1->position += glm::vec3(static_cast<float>(w) + tp - xo, y_pos, static_cast<float>(h + 1) + tp - yo);
                                tEntity_1->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_1);

                                // Torch 2 placement
                                tEntity_2->owner = eEntityOwner::ownerMap;
                                tEntity_2->type  = eEntityType::entityTypeObject;
                                tEntity_2->position += glm::vec3(static_cast<float>(w) + tp - xo, y_pos, static_cast<float>(h - 1) + tp - yo);
                                tEntity_2->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_2);
                                
                                // Set processed flags
                                _map->tile[t].processed = true;
                            }
                        }
                                
                        // ? W ?
                        // F - F
                        // ? W ?
                        else if ((m_isFloor(_map, t + 1)) &&
                                (m_isFloor(_map, t - 1)) &&
                                (m_isWall (_map, t + _map->width)) &&
                                (m_isWall (_map, t - _map->width)))
                        {
                            tEntity_1 = m_entityManager->load(xmlFile.getString("<torch_1td_entity>", 1 + (rand() % torch_1td_count)));
                            tEntity_2 = m_entityManager->load(xmlFile.getString("<torch_1td_entity>", 1 + (rand() % torch_1td_count)));
                            if ((tEntity_1 != nullptr) && (tEntity_2 != nullptr))
                            {
                                // Tile entity occupies
                                tEntity_1->tile = t + 1;
                                tEntity_2->tile = t - 1;

                                // Set object UID on relevant map tiles
                                _map->tile[tEntity_1->tile].object     = tEntity_1->UID;
                                _map->tile[tEntity_2->tile].object     = tEntity_2->UID;

                                // Set base tile to relevant collision enum
                                //_map->tile[tEntity_1->tile].base     = eTileBase::tileFloorNoGo;
                                //_map->tile[tEntity_2->tile].base     = eTileBase::tileFloorNoGo;

                                // Torch 1 placement
                                tEntity_1->owner = eEntityOwner::ownerMap;
                                tEntity_1->type  = eEntityType::entityTypeObject;
                                tEntity_1->position += glm::vec3(static_cast<float>(w + 1) + tp - xo, y_pos, static_cast<float>(h) + tp - yo);
                                tEntity_1->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_1);

                                // Torch 2 placement
                                tEntity_2->owner = eEntityOwner::ownerMap;
                                tEntity_2->type  = eEntityType::entityTypeObject;
                                tEntity_2->position += glm::vec3(static_cast<float>(w - 1) + tp - xo, y_pos, static_cast<float>(h) + tp - yo);
                                tEntity_2->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_2);
                                
                                // Set processed flags
                                _map->tile[t].processed = true;
                            }
                        }
                    }
                }
            }
        }

        // Clean up
        xmlFile.free();
    }
}
