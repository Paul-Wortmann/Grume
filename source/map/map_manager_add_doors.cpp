
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

void cMapManager::m_addDoors(void)
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
        // Get a count for door type
        std::uint32_t door_1td_count = biomeFile.getInstanceCount("<door_1td>"); // Door width 1
        std::uint32_t door_2td_count = biomeFile.getInstanceCount("<door_2td>"); // Door width 2
        std::uint32_t door_3td_count = biomeFile.getInstanceCount("<door_3td>"); // Door width 3

        // If biome file does not specify an entity file for a door, warning message
        if (door_1td_count == 0)
            gLogWrite(LOG_WARNING, "<door_1td> not found in biome file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
        if (door_2td_count == 0)
            gLogWrite(LOG_WARNING, "<door_2td> not found in biome file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
        if (door_3td_count == 0)
            gLogWrite(LOG_WARNING, "<door_3td> not found in biome file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);

        // Width and height offset, used to center the torches
        float xo = static_cast<float>(m_map->info.size_x  / 2);
        float yo = static_cast<float>(m_map->info.size_y / 2);

        const float y_pos = m_map->info.terrainHeight; // Map floor position on the y axis

        for (std::uint32_t y = 1; y < m_map->info.size_y - 1; ++y)
        {
            for (std::uint32_t x = 1; x < m_map->info.size_x - 1; ++x)
            {
                // Calculate the tile number
                std::uint32_t t = (y * m_map->info.size_x) + x;

                // Try to find doorways of size 3 and place doors in them
                if (door_3td_count > 0)
                {
                    // ? ? ?
                    // D D D
                    // ? ? ?
                    if ((m_isDoorway(x, y)) &&
                        (!m_map->tile[t].processed) &&
                        (m_isDoorway(x - 1, y)) &&
                        (!m_map->tile[t - 1].processed) &&
                        (m_isDoorway(x + 1, y)) &&
                        (!m_map->tile[t + 1].processed))// &&
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<door_3td>", 1 + (rand() % door_3td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot270, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + 1].processed = true;
                            m_map->tile[t - 1].processed = true;
                        }
                    }
                    // ? D ?
                    // ? D ?
                    // ? D ?
                    else if ((m_isDoorway(x, y)) &&
                             (!m_map->tile[t].processed) &&
                             (m_isDoorway(x, y - 1)) &&
                             (!m_map->tile[t - m_map->info.size_x].processed) &&
                             (m_isDoorway(x, y + 1)) &&
                             (!m_map->tile[t + m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<door_3td>", 1 + (rand() % door_3td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot000, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x].processed = true;
                        }
                    }
                }

                // Try to find doorways of size 2 and place doors in them
                if (door_2td_count > 0)
                {
                    // ? ? ?
                    // D D W
                    // ? ? ?
                    if ((m_isDoorway(x, y)) &&
                        (!m_map->tile[t].processed) &&
                        (m_isDoorway(x - 1, y)) &&
                        (!m_map->tile[t - 1].processed) &&
                        (m_isSolidWall(x + 1, y)) &&
                        (!m_map->tile[t + 1].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<door_2td>", 1 + (rand() % door_2td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x - 0.125) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot270, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + 1].processed = true;
                            m_map->tile[t - 1].processed = true;
                        }
                    }
                    // ? D ?
                    // ? D ?
                    // ? W ?
                    else if ((m_isDoorway(x, y)) &&
                             (!m_map->tile[t].processed) &&
                             (m_isDoorway(x, y - 1)) &&
                             (!m_map->tile[t - m_map->info.size_x].processed) &&
                             (m_isSolidWall(x, y + 1)) &&
                             (!m_map->tile[t + m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<door_2td>", 1 + (rand() % door_2td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y - 0.125) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot000, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x].processed = true;
                        }
                    }
                }

                // Try to find doorways of size 1 and place doors in them
                if (door_1td_count > 0)
                {
                    // ? ? ?
                    // W D W
                    // ? ? ?
                    if ((m_isDoorway(x, y)) &&
                        (!m_map->tile[t].processed) &&
                        (m_isSolidWall(x - 1, y)) &&
                        (!m_map->tile[t - 1].processed) &&
                        (m_isSolidWall(x + 1, y)) &&
                        (!m_map->tile[t + 1].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<door_1td>", 1 + (rand() % door_1td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot270, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + 1].processed = true;
                            m_map->tile[t - 1].processed = true;
                        }
                    }
                    // ? W ?
                    // ? D ?
                    // ? W ?
                    else if ((m_isDoorway(x, y)) &&
                             (!m_map->tile[t].processed) &&
                             (m_isSolidWall(x, y - 1)) &&
                             (!m_map->tile[t - m_map->info.size_x].processed) &&
                             (m_isSolidWall(x, y + 1)) &&
                             (!m_map->tile[t + m_map->info.size_x].processed))
                     {
                        // Create a temporary entity pointer
                        sEntity* tEntity = nullptr;

                        tEntity = m_entityManager->load(biomeFile.getString("<door_1td>", 1 + (rand() % door_1td_count)));
                        if (tEntity != nullptr)
                        {
                            // Tile entity occupies
                            tEntity->base.tileOnMap = t;

                            // Door placement
                            tEntity->base.owner = eEntityOwner::entityOwner_map;
                            tEntity->base.position += glm::vec3(static_cast<float>(x) - xo, y_pos, static_cast<float>(y) - yo);
                            tEntity->base.rotation += glm::vec3(0.0f, rot000, 0.0f);
                            m_entityManager->updateModelMatrix(tEntity);

                            // Process collision data
                            m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                            // Set processed flags
                            m_map->tile[t].processed = true;
                            m_map->tile[t + m_map->info.size_x].processed = true;
                            m_map->tile[t - m_map->info.size_x].processed = true;
                        }
                    }
                }
            }
        }

        // Clean up
        biomeFile.free();
    }
}

