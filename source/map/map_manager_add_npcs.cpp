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

void cMapManager::m_addNPCs(void)
{
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + m_map->info.fileName);
    if (mapFile.isValid())
    {
        // Map NPCs
        m_map->numNPC = mapFile.getInstanceCount("<npc>");
        if (m_map->numNPC > 0)
        {
            // Allocate memory for npc data
            m_map->npc = new sMapNPC[m_map->numNPC];

            // Data parsing
            std::string   dataString       = {};
            std::uint32_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};

            // Temporary data
            sEntity*      tEntity             = nullptr;

            std::uint32_t npc_tile_x          = 0;
            std::uint32_t npc_tile_y          = 0;

            std::string   entity_fileName     = {};

            // Get and process each npc entry
            for (std::uint32_t i = 0; i < m_map->numNPC; ++i)
            {
                // Get data
                dataString  = mapFile.getString("<npc>", i + 1);
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";

                // Process data
                /// # database name, number, tile x, y, scale x, y, z, rotation x, y, z, quest name, quest required state
                if (dataStringLength > 4)
                {
                    for (std::uint32_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_map->npc[i].databaseName = tString; // database name
                            }
                            else if (tStringNum == 1)
                            {
                                m_map->npc[i].databaseNumber = std::stoi(tString); // database name
                            }
                            else if (tStringNum == 2)
                            {
                                npc_tile_x = std::stoi(tString); // npc_tile_x
                            }
                            else if (tStringNum == 3)
                            {
                                npc_tile_y = std::stoi(tString); // npc_tile_y
                            }
                            else if (tStringNum == 4)
                            {
                                m_map->npc[i].scale.x = std::stof(tString); // Object scale x
                            }
                            else if (tStringNum == 5)
                            {
                                m_map->npc[i].scale.y = std::stof(tString); // Object scale y
                            }
                            else if (tStringNum == 6)
                            {
                                m_map->npc[i].scale.z = std::stof(tString); // Object scale z
                            }
                            else if (tStringNum == 7)
                            {
                                m_map->npc[i].rotation.x = std::stof(tString); // Object rotation x
                            }
                            else if (tStringNum == 8)
                            {
                                m_map->npc[i].rotation.y = std::stof(tString); // Object rotation y
                            }
                            else if (tStringNum == 9)
                            {
                                m_map->npc[i].rotation.z = std::stof(tString); // Object rotation z
                            }
                            else if (tStringNum == 10)
                            {
                                m_map->npc[i].questName = tString; // quest name
                            }
                            else if (tStringNum == 11)
                            {
                                m_map->npc[i].questStateReq = std::stoi(tString); // quest required state
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }
                        m_map->npc[i].tile = (npc_tile_y * m_map->info.size_x) + npc_tile_x;
                    }
                }

                // Only load the NPC if destination tile is free and quest condition met
                if ((m_map->tile[m_map->npc[i].tile].entity.type == eTileEntityType::tileEntityNone) &&
                    (m_questManager->getQuest(m_map->npc[i].questName) == m_map->npc[i].questStateReq))
                {
                    // Retrieve the npc filename from the database
                    entity_fileName = m_databaseManager->getDatabaseEntryFileName(m_map->npc[i].databaseName, m_map->npc[i].databaseNumber, eDatabaseType::databaseTypeNpc);

                    // Load the entity
                    tEntity = m_entityManager->load(entity_fileName);

                    // Only place the npc if the entity was loaded
                    if (tEntity != nullptr)
                    {
                        // Add character component
                        if (tEntity->character == nullptr)
                        {
                            tEntity->character = new sEntityCharacter;
                        }

                        // Map tile position
                        tEntity->base.tileOnMap = m_map->npc[i].tile;
                        m_map->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityNPC;
                        m_map->tile[tEntity->base.tileOnMap].entity.UID = tEntity->UID;

                        // Ownership
                        tEntity->base.owner    = eEntityOwner::entityOwner_map;

                        // Scale and rotation
                        tEntity->base.scale    += m_map->npc[i].scale;
                        tEntity->base.rotation += m_map->npc[i].rotation;

                        // position relative to tile
                        glm::vec3 tilePosition = gMapTileToPosition(m_map, m_map->npc[i].tile);
                        tEntity->base.position.x += tilePosition.x;
                        tEntity->base.position.y += m_map->info.terrainHeight;
                        tEntity->base.position.z += tilePosition.z;

                        // update model matrix
                        m_entityManager->updateModelMatrix(tEntity);

                        // AI
                        if (tEntity->ai != nullptr)
                        {
                            tEntity->ai->spawnTile = tEntity->base.tileOnMap;
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
