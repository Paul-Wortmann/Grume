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

void cMapManager::m_addNPC_mobs(void)
{
    // Map file
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + m_map->info.fileName);
    if (mapFile.isValid())
    {
        // Map Objects
        m_map->numNPCmob = mapFile.getInstanceCount("<npc_mob>");
        if (m_map->numNPCmob > 0)
        {
            // Allocate memory for object data
            m_map->npcMob = new sMapNPCMob[m_map->numNPCmob];

            // Data parsing
            std::string   dataString       = {};
            std::uint32_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};

            // Temporary data
            sEntity*      tEntity          = nullptr;

            std::string   entity_fileName  = {};

            // Get and process each event entry
            for (std::uint32_t i = 0; i < m_map->numNPCmob; ++i)
            {
                // Get data
                dataString  = mapFile.getString("<npc_mob>", i + 1);
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";

                // Scale
                float scaleMin = 1.0;
                float scaleMax = 1.0;

                // Process data
                /// # database name, database number, frequency
                if (dataStringLength > 4)
                {
                    for (std::uint32_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_map->npcMob[i].databaseName = tString; // database name
                            }
                            else if (tStringNum == 1)
                            {
                                m_map->npcMob[i].databaseNumber = std::stoi(tString); // database number
                            }
                            else if (tStringNum == 2)
                            {
                                scaleMin = std::stof(tString); // scale min
                            }
                            else if (tStringNum == 3)
                            {
                                scaleMax = std::stof(tString); // scale max
                            }
                            else if (tStringNum == 4)
                            {
                                m_map->npcMob[i].prevalence = std::stoi(tString); // prevalence
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }
                    }
                }

                // Try to place npc_mob
                for (std::uint32_t i = 0; i < m_map->numNPCmob; ++i)
                {
                    for (std::uint32_t j = 0; j < m_map->npcMob[i].prevalence; ++j)
                    {
                        // position
                        std::uint32_t tileNumber = rand() % m_map->numTiles;

                        // Only place the object if the map tile is free
                        if ((m_map->tile[tileNumber].entity.type == eTileEntityType::tileEntityNone) &&
                            (m_map->tile[tileNumber].type == eTileType::tileFloor))
                        {
                            // Retrieve an npc filename from the database
                            entity_fileName = m_databaseManager->getDatabaseEntryFileName(m_map->npcMob[i].databaseName, m_map->npcMob[i].databaseNumber, eDatabaseType::databaseTypeNpc);

                            // Load the entity
                            tEntity = m_entityManager->load(entity_fileName);

                            // Only place the object if the entity was loaded
                            if (tEntity != nullptr)
                            {
                                // Map tile position
                                tEntity->base.tileOnMap = tileNumber;
                                m_map->tile[tEntity->base.tileOnMap].entity.UID = tEntity->UID;
                                m_map->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityNPC;

                                // Ownership
                                tEntity->base.owner = eEntityOwner::entityOwner_map;

                                // position relative to tile
                                glm::vec3 tilePosition = gMapTileToPosition(m_map, tileNumber);
                                tEntity->base.position.x += tilePosition.x;
                                tEntity->base.position.y += m_map->info.terrainHeight;
                                tEntity->base.position.z += tilePosition.z;

                                // Determine scale
                                float scale = gRandFloatMinMax(scaleMin, scaleMax);
                                tEntity->base.scale.x *= scale;
                                tEntity->base.scale.y *= scale;
                                tEntity->base.scale.z *= scale;

                                // update model matrix
                                m_entityManager->updateModelMatrix(tEntity);

                                // Process collision data
                                m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                                // Update map mob count
                                m_map->info.currentNumMob++;
                            }
                        }
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
