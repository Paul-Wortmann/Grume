
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

void cMapManager::m_addChests(void)
{
    // Reset tile processed flags
    for (std::uint32_t i = 0; i < m_map->numTiles; ++i)
    {
        m_map->tile[i].processed = false;
    }

    // Load the biome file (includes chest entity reference)
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
        // Get a count for chests
        std::uint32_t chest_1td_count = biomeFile.getInstanceCount("<chest_1td>"); // Chest with width 1

        // If biome file does not specify an entity file for a chest, warning message, and early exit
        if (chest_1td_count == 0)
        {
            gLogWrite(LOG_WARNING, "<chest_1td> not found in biome file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
            biomeFile.free();
            return;
        }

        // Width and height offset, used to center the torches
        float xo = static_cast<float>(m_map->info.size_x  / 2);
        float yo = static_cast<float>(m_map->info.size_y / 2);

        const float y_pos = m_map->info.terrainHeight; // Map floor position on the y axis
        const float tp    = 1.0f / 2.0f; // Tile center positioning (half model dimension)

        const std::uint32_t boundry_distance = 1;

        for (std::uint32_t y = boundry_distance; y < m_map->info.size_y - boundry_distance; ++y)
        {
            for (std::uint32_t x = boundry_distance; x < m_map->info.size_x - boundry_distance; ++x)
            {
                // Random placement
                if ((rand() % 1000) < 10) // 0.5% chance
                {
                    // Calculate the tile number
                    std::uint32_t t = (y * m_map->info.size_x) + x;

                    // Try to find a suitable location and then add a chest
                    // W W W W W
                    // F F C F F
                    // F F F F F
                    if ((m_isFloor(x, y)) &&
                        (!m_map->tile[t].processed) &&
                        (m_isFloor(x - 1, y)) &&
                        (!m_map->tile[t - 1].processed) &&
                        (m_isFloor(x + 1, y)) &&
                        (!m_map->tile[t + 1].processed) &&
                        (m_isFloor(x - 2, y)) &&
                        (!m_map->tile[t - 2].processed) &&
                        (m_isFloor(x + 2, y)) &&
                        (!m_map->tile[t + 2].processed) &&

                        (m_isFloor(x, y + 1)) &&
                        (!m_map->tile[t + m_map->info.size_x].processed) &&
                        (m_isFloor(x - 1, y + 1)) &&
                        (!m_map->tile[t - 1 + m_map->info.size_x].processed) &&
                        (m_isFloor(x + 1, y + 1)) &&
                        (!m_map->tile[t + 1 + m_map->info.size_x].processed) &&
                        (m_isFloor(x - 2, y + 1)) &&
                        (!m_map->tile[t - 2 + m_map->info.size_x].processed) &&
                        (m_isFloor(x + 2, y + 1)) &&
                        (!m_map->tile[t + 2 + m_map->info.size_x].processed) &&

                        (m_isSolidWall(x, y - 1)) &&
                        (!m_map->tile[t - m_map->info.size_x].processed) &&
                        (m_isSolidWall(x + 1, y - 1)) &&
                        (!m_map->tile[t + 1 - m_map->info.size_x].processed) &&
                        (m_isSolidWall(x - 1, y - 1)) &&
                        (!m_map->tile[t - 1 - m_map->info.size_x].processed) &&
                        (m_isSolidWall(x + 2, y - 1)) &&
                        (!m_map->tile[t + 2 - m_map->info.size_x].processed) &&
                        (m_isSolidWall(x - 2, y - 1)) &&
                        (!m_map->tile[t - 2 - m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<chest_1td>", 1 + (rand() % chest_1td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Add to map
                            m_map->tile[t].entity.UID = tEntity->UID;
                            m_map->tile[t].entity.type = eTileEntityType::tileEntityObjectStaticLow;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot000, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + 1].processed = true;
                            m_map->tile[t - 1].processed = true;
                            m_map->tile[t + 2].processed = true;
                            m_map->tile[t - 2].processed = true;
                            m_map->tile[t + m_map->info.size_x].processed = true;
                            m_map->tile[t + 1 + m_map->info.size_x].processed = true;
                            m_map->tile[t - 1 + m_map->info.size_x].processed = true;
                            m_map->tile[t + 2 + m_map->info.size_x].processed = true;
                            m_map->tile[t - 2 + m_map->info.size_x].processed = true;
                        }
                    }

                    // Try to find a suitable location and then add a chest
                    // W W W W W
                    // F F C F F
                    // F F F F F
                    else if ((m_isFloor(x, y)) &&
                             (!m_map->tile[t].processed) &&
                             (m_isFloor(x - 1, y)) &&
                             (!m_map->tile[t - 1].processed) &&
                             (m_isFloor(x + 1, y)) &&
                             (!m_map->tile[t + 1].processed) &&
                             (m_isFloor(x - 2, y)) &&
                             (!m_map->tile[t - 2].processed) &&
                             (m_isFloor(x + 2, y)) &&
                             (!m_map->tile[t + 2].processed) &&

                             (m_isSolidWall(x, y + 1)) &&
                             (!m_map->tile[t + m_map->info.size_x].processed) &&
                             (m_isSolidWall(x - 1, y + 1)) &&
                             (!m_map->tile[t - 1 + m_map->info.size_x].processed) &&
                             (m_isSolidWall(x + 1, y + 1)) &&
                             (!m_map->tile[t + 1 + m_map->info.size_x].processed) &&
                             (m_isSolidWall(x - 2, y + 1)) &&
                             (!m_map->tile[t - 2 + m_map->info.size_x].processed) &&
                             (m_isSolidWall(x + 2, y + 1)) &&
                             (!m_map->tile[t + 2 + m_map->info.size_x].processed) &&

                             (m_isFloor(x, y - 1)) &&
                             (!m_map->tile[t - m_map->info.size_x].processed) &&
                             (m_isFloor(x + 1, y - 1)) &&
                             (!m_map->tile[t + 1 - m_map->info.size_x].processed) &&
                             (m_isFloor(x - 1, y - 1)) &&
                             (!m_map->tile[t - 1 - m_map->info.size_x].processed) &&
                             (m_isFloor(x + 2, y - 1)) &&
                             (!m_map->tile[t + 2 - m_map->info.size_x].processed) &&
                             (m_isFloor(x - 2, y - 1)) &&
                             (!m_map->tile[t - 2 - m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<chest_1td>", 1 + (rand() % chest_1td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Add to map
                            m_map->tile[t].entity.UID = tEntity->UID;
                            m_map->tile[t].entity.type = eTileEntityType::tileEntityObjectStaticLow;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot180, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + 1].processed = true;
                            m_map->tile[t - 1].processed = true;
                            m_map->tile[t + 2].processed = true;
                            m_map->tile[t - 2].processed = true;
                            m_map->tile[t - m_map->info.size_x].processed = true;
                            m_map->tile[t + 1 - m_map->info.size_x].processed = true;
                            m_map->tile[t - 1 - m_map->info.size_x].processed = true;
                            m_map->tile[t + 2 - m_map->info.size_x].processed = true;
                            m_map->tile[t - 2 - m_map->info.size_x].processed = true;
                        }
                    }

                    // Try to find a suitable location and then add a chest
                    // W F F
                    // W F F
                    // W C F
                    // W F F
                    // W F F
                    else if ((m_isFloor(x, y)) &&
                             (!m_map->tile[t].processed) &&
                             (m_isFloor(x, y - 1)) &&
                             (!m_map->tile[t - m_map->info.size_x].processed) &&
                             (m_isFloor(x, y - 2)) &&
                             (!m_map->tile[t - m_map->info.size_x - m_map->info.size_x].processed) &&
                             (m_isFloor(x, y + 1)) &&
                             (!m_map->tile[t + m_map->info.size_x].processed) &&
                             (m_isFloor(x, y + 2)) &&
                             (!m_map->tile[t + m_map->info.size_x + m_map->info.size_x].processed) &&

                             (m_isSolidWall(x - 1, y)) &&
                             (!m_map->tile[t - 1].processed) &&
                             (m_isSolidWall(x - 1, y - 1)) &&
                             (!m_map->tile[t - 1 - m_map->info.size_x].processed) &&
                             (m_isSolidWall(x - 1, y - 2)) &&
                             (!m_map->tile[t - 1 - m_map->info.size_x - m_map->info.size_x].processed) &&
                             (m_isSolidWall(x - 1, y + 1)) &&
                             (!m_map->tile[t - 1 + m_map->info.size_x].processed) &&
                             (m_isSolidWall(x - 1, y + 2)) &&
                             (!m_map->tile[t - 1 + m_map->info.size_x + m_map->info.size_x].processed) &&

                             (m_isFloor(x + 1, y)) &&
                             (!m_map->tile[t + 1].processed) &&
                             (m_isFloor(x + 1, y - 1)) &&
                             (!m_map->tile[t + 1 - m_map->info.size_x].processed) &&
                             (m_isFloor(x + 1, y - 2)) &&
                             (!m_map->tile[t + 1 - m_map->info.size_x - m_map->info.size_x].processed) &&
                             (m_isFloor(x + 1, y + 1)) &&
                             (!m_map->tile[t + 1 + m_map->info.size_x].processed) &&
                             (m_isFloor(x + 1, y + 2)) &&
                             (!m_map->tile[t + 1 + m_map->info.size_x + m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<chest_1td>", 1 + (rand() % chest_1td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Add to map
                            m_map->tile[t].entity.UID = tEntity->UID;
                            m_map->tile[t].entity.type = eTileEntityType::tileEntityObjectStaticLow;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot090, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x].processed = true;
                            m_map->tile[t + m_map->info.size_x + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x - m_map->info.size_x].processed = true;

                            m_map->tile[t + 1].processed = true;
                            m_map->tile[t + 1 + m_map->info.size_x].processed = true;
                            m_map->tile[t + 1 - m_map->info.size_x].processed = true;
                            m_map->tile[t + 1 + m_map->info.size_x + m_map->info.size_x].processed = true;
                            m_map->tile[t + 1 - m_map->info.size_x - m_map->info.size_x].processed = true;
                        }
                    }

                    // Try to find a suitable location and then add a chest
                    // F F W
                    // F F W
                    // F C W
                    // F F W
                    // F F W
                    else if ((m_isFloor(x, y)) &&
                             (!m_map->tile[t].processed) &&
                             (m_isFloor(x, y - 1)) &&
                             (!m_map->tile[t - m_map->info.size_x].processed) &&
                             (m_isFloor(x, y - 2)) &&
                             (!m_map->tile[t - m_map->info.size_x - m_map->info.size_x].processed) &&
                             (m_isFloor(x, y + 1)) &&
                             (!m_map->tile[t + m_map->info.size_x].processed) &&
                             (m_isFloor(x, y + 2)) &&
                             (!m_map->tile[t + m_map->info.size_x + m_map->info.size_x].processed) &&

                             (m_isFloor(x - 1, y)) &&
                             (!m_map->tile[t - 1].processed) &&
                             (m_isFloor(x - 1, y - 1)) &&
                             (!m_map->tile[t - 1 - m_map->info.size_x].processed) &&
                             (m_isFloor(x - 1, y - 2)) &&
                             (!m_map->tile[t - 1 - m_map->info.size_x - m_map->info.size_x].processed) &&
                             (m_isFloor(x - 1, y + 1)) &&
                             (!m_map->tile[t - 1 + m_map->info.size_x].processed) &&
                             (m_isFloor(x - 1, y + 2)) &&
                             (!m_map->tile[t - 1 + m_map->info.size_x + m_map->info.size_x].processed) &&

                             (m_isSolidWall(x + 1, y)) &&
                             (!m_map->tile[t + 1].processed) &&
                             (m_isSolidWall(x + 1, y - 1)) &&
                             (!m_map->tile[t + 1 - m_map->info.size_x].processed) &&
                             (m_isSolidWall(x + 1, y - 2)) &&
                             (!m_map->tile[t + 1 - m_map->info.size_x - m_map->info.size_x].processed) &&
                             (m_isSolidWall(x + 1, y + 1)) &&
                             (!m_map->tile[t + 1 + m_map->info.size_x].processed) &&
                             (m_isSolidWall(x + 1, y + 2)) &&
                             (!m_map->tile[t + 1 + m_map->info.size_x + m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<chest_1td>", 1 + (rand() % chest_1td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Add to map
                            m_map->tile[t].entity.UID = tEntity->UID;
                            m_map->tile[t].entity.type = eTileEntityType::tileEntityObjectStaticLow;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot270, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x].processed = true;
                            m_map->tile[t + m_map->info.size_x + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x - m_map->info.size_x].processed = true;

                            m_map->tile[t - 1].processed = true;
                            m_map->tile[t - 1 + m_map->info.size_x].processed = true;
                            m_map->tile[t - 1 - m_map->info.size_x].processed = true;
                            m_map->tile[t - 1 + m_map->info.size_x + m_map->info.size_x].processed = true;
                            m_map->tile[t - 1 - m_map->info.size_x - m_map->info.size_x].processed = true;
                        }
                    }
                }
            }
        }

        // Clean up
        biomeFile.free();
    }
}
