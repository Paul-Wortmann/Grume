
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

void cMapManager::m_addTorches(void)
{
    // Reset tile processed flags
    for (std::uint32_t i = 0; i < m_map->numTiles; ++i)
    {
        m_map->tile[i].processed = false;
    }

    // Load the biome file (includes torches)
    std::string biomeFileName = m_databaseManager->getDatabaseEntryFileName(m_map->info.biome, 1, eDatabaseType::databaseTypeBiome);
    cXML biomeFile;
    biomeFile.load(std::string(FILE_PATH_BIOME) + biomeFileName);

    // If biome file invalid, early exit
    if (!biomeFile.isValid())
    {
        gLogWrite(LOG_ERROR, "Failed to load file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }


    // Only continue if we can load the biome file
    if (biomeFile.lineCount() > 0)
    {
        // Get a count for torch type
        std::uint32_t torch_1td_count = biomeFile.getInstanceCount("<torch_1td>"); // Torch

        // If biome file does not specify an entity file for a torch, early exit
        if (torch_1td_count <= 0)
        {
            gLogWrite(LOG_WARNING, "<torch_1td> not found in biome file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
            biomeFile.free();
            return;
        }

        // Width and height offset, used to center the torches
        float xo = static_cast<float>(m_map->info.size_x  / 2);
        float yo = static_cast<float>(m_map->info.size_y / 2);

        const float y_pos = m_map->info.terrainHeight; // Map floor position on the y axis
        const float tp    = 1.0f / 2.0f; // Tile center positioning ( half model dimension)

        for (std::uint32_t y = 1; y < m_map->info.size_y - 1; ++y)
        {
            for (std::uint32_t x = 1; x < m_map->info.size_x - 1; ++x)
            {
                // Random placement
                if ((rand() % 100) < 20) // 20% chance
                {

                    // Calculate the tile number
                    std::uint32_t t = (y * m_map->info.size_x) + x;

                    if ((m_isWall(x, y)) &&
                        (!m_map->tile[t].processed) &&
                        (m_map->tile[t].entity.UID == 0) &&
                        (m_map->tile[t + 1].entity.UID == 0) &&
                        (m_map->tile[t - 1].entity.UID == 0) &&
                        (m_map->tile[t + m_map->info.size_x].entity.UID == 0) &&
                        (m_map->tile[t - m_map->info.size_x].entity.UID == 0) &&
                        (m_map->tile[t + m_map->info.size_x + 1].entity.UID == 0) &&
                        (m_map->tile[t + m_map->info.size_x - 1].entity.UID == 0) &&
                        (m_map->tile[t - m_map->info.size_x + 1].entity.UID == 0) &&
                        (m_map->tile[t - m_map->info.size_x - 1].entity.UID == 0))
                    {
                        // Create temporary entity pointers
                        sEntity* tEntity_1 = nullptr;
                        sEntity* tEntity_2 = nullptr;

                        // ? F ?
                        // W - W
                        // ? F ?
                        if     ((m_isFullWall(x + 1, y)) &&
                                (m_isFullWall(x - 1, y)) &&
                                (m_isFloor(x, y + 1)) &&
                                (m_isFloor(x, y - 1)))
                        {
                            tEntity_1 = m_entityManager->load(biomeFile.getString("<torch_1td>", 1 + (rand() % torch_1td_count)));
                            tEntity_2 = m_entityManager->load(biomeFile.getString("<torch_1td>", 1 + (rand() % torch_1td_count)));
                            if ((tEntity_1 != nullptr) && (tEntity_2 != nullptr))
                            {
                                // Tile entity occupies
                                tEntity_1->base.tileOnMap = ((y + 1) * m_map->info.size_x) + x;
                                tEntity_2->base.tileOnMap = ((y - 1) * m_map->info.size_x) + x;

                                // Set object UID on relevant map tiles
                                m_map->tile[tEntity_1->base.tileOnMap].entity.UID  = tEntity_1->UID;
                                m_map->tile[tEntity_2->base.tileOnMap].entity.UID  = tEntity_2->UID;

                                // Set base tile to relevant collision enum
                                //m_map->tile[tEntity_1->tile].base     = eTileBase::tileFloorNoGo;
                                //m_map->tile[tEntity_2->tile].base     = eTileBase::tileFloorNoGo;

                                // Torch 1 placement
                                tEntity_1->base.owner = eEntityOwner::entityOwner_map;
                                tEntity_1->base.type  = eEntityType::entityType_none;
                                tEntity_1->base.position += glm::vec3(static_cast<float>(x) + tp - xo, y_pos, static_cast<float>(y + 1) - tp - yo);
                                tEntity_1->base.rotation += glm::vec3(0.0f, rot000, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_1);

                                // Torch 2 placement
                                tEntity_2->base.owner = eEntityOwner::entityOwner_map;
                                tEntity_2->base.type  = eEntityType::entityType_none;
                                tEntity_2->base.position += glm::vec3(static_cast<float>(x) + tp - xo, y_pos, static_cast<float>(y - 1) + tp - yo);
                                tEntity_2->base.rotation += glm::vec3(0.0f, rot180, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_2);

                                // Set processed flags
                                m_map->tile[t].processed = true;
                            }
                        }

                        // ? W ?
                        // F - F
                        // ? W ?
                        else if ((m_isFloor(x + 1, y)) &&
                                 (m_isFloor(x - 1, y)) &&
                                 (m_isFullWall(x, y + 1)) &&
                                 (m_isFullWall(x, y - 1)))
                        {
                            tEntity_1 = m_entityManager->load(biomeFile.getString("<torch_1td>", 1 + (rand() % torch_1td_count)));
                            tEntity_2 = m_entityManager->load(biomeFile.getString("<torch_1td>", 1 + (rand() % torch_1td_count)));
                            if ((tEntity_1 != nullptr) && (tEntity_2 != nullptr))
                            {
                                // Tile entity occupies
                                tEntity_1->base.tileOnMap = (y * m_map->info.size_x) + x + 1;
                                tEntity_2->base.tileOnMap = (y * m_map->info.size_x) + x - 1;

                                // Set object UID on relevant map tiles
                                m_map->tile[tEntity_1->base.tileOnMap].entity.UID  = tEntity_1->UID;
                                m_map->tile[tEntity_2->base.tileOnMap].entity.UID  = tEntity_2->UID;


                                // Set base tile to relevant collision enum
                                //m_map->tile[tEntity_1->tile].base     = eTileBase::tileFloorNoGo;
                                //m_map->tile[tEntity_2->tile].base     = eTileBase::tileFloorNoGo;

                                // Torch 1 placement
                                tEntity_1->base.owner = eEntityOwner::entityOwner_map;
                                tEntity_1->base.type  = eEntityType::entityType_none;
                                tEntity_1->base.position += glm::vec3(static_cast<float>(x + 1) - tp - xo, y_pos, static_cast<float>(y) + tp - yo);
                                tEntity_1->base.rotation += glm::vec3(0.0f, rot090, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_1);

                                // Torch 2 placement
                                tEntity_2->base.owner = eEntityOwner::entityOwner_map;
                                tEntity_2->base.type  = eEntityType::entityType_none;
                                tEntity_2->base.position += glm::vec3(static_cast<float>(x - 1) + tp - xo, y_pos, static_cast<float>(y) + tp - yo);
                                tEntity_2->base.rotation += glm::vec3(0.0f, rot270, 0.0f);
                                m_entityManager->updateModelMatrix(tEntity_2);

                                // Set processed flags
                                m_map->tile[t].processed = true;
                            }
                        }
                    }
                }
            }
        }

        // Clean up
        biomeFile.free();
    }
}

