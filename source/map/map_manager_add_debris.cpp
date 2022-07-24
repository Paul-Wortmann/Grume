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

void cMapManager::m_addDebris(void)
{
    // Map file
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + m_map->info.fileName);
    if (mapFile.isValid())
    {
        // Map Objects
        m_map->numDebris = mapFile.getInstanceCount("<debris>");
        if (m_map->numDebris > 0)
        {
            // Allocate memory for object data
            m_map->debris = new sMapDebris[m_map->numDebris];

            // Data parsing
            std::string   dataString       = {};
            std::uint32_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};

            // Temporary data
            sEntity*      tEntity                = nullptr;

            std::string   entity_fileName        = {};

            // Get and process each event entry
            for (std::uint32_t i = 0; i < m_map->numDebris; ++i)
            {
                // Get data
                dataString  = mapFile.getString("<debris>", i + 1);
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";

                // Process data
                /// # database name, scale min, scale max, frequency
                if (dataStringLength > 4)
                {
                    for (std::uint32_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_map->debris[i].databaseName = tString; // database name
                            }
                            else if (tStringNum == 1)
                            {
                                m_map->debris[i].scaleMin = std::stof(tString); // scale min
                            }
                            else if (tStringNum == 2)
                            {
                                m_map->debris[i].scaleMax = std::stof(tString); // scale max
                            }
                            else if (tStringNum == 3)
                            {
                                m_map->debris[i].prevalence = std::stoi(tString); // prevalence
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

                // Try to place debris
                for (std::uint32_t i = 0; i < m_map->numDebris; ++i)
                {
                    for (std::uint32_t j = 0; j < m_map->debris[i].prevalence; ++j)
                    {
                        // position
                        std::uint32_t tileNumber = rand() % m_map->numTiles;

                        // Only place the object if the map tile is free
                        if ((m_map->tile[tileNumber].entity.type == eTileEntityType::tileEntityNone) &&
                            (m_map->tile[tileNumber].type == eTileType::tileFloor))
                        {
                            // Retrieve a random object filename from the database
                            entity_fileName = m_databaseManager->getDatabaseEntryFileName(m_map->debris[i].databaseName, 0, eDatabaseType::databaseTypeObject);

                            // Load the entity
                            tEntity = m_entityManager->load(entity_fileName);

                            // Only place the object if the entity was loaded
                            if (tEntity != nullptr)
                            {
                                // Map tile position
                                tEntity->base.tileOnMap = tileNumber;
                                m_map->tile[tEntity->base.tileOnMap].entity.UID = tEntity->UID;

                                // Tile entity data
                                if ((tEntity->physics != nullptr) && (tEntity->physics->type == ePhysicsType::physicsTypeDynamic))
                                {
                                    m_map->tile[tEntity->base.tileOnMap].entity.type = (tEntity->base.flyOver) ? eTileEntityType::tileEntityObjectDynamicLow : eTileEntityType::tileEntityObjectDynamic;
                                    tEntity->base.type = (tEntity->base.flyOver) ? eEntityType::entityType_objectDynamicLow : eEntityType::entityType_objectDynamic;
                                }
                                else if ((tEntity->physics != nullptr) && (tEntity->physics->type == ePhysicsType::physicsTypeStatic))
                                {
                                    m_map->tile[tEntity->base.tileOnMap].entity.type = (tEntity->base.flyOver) ? eTileEntityType::tileEntityObjectStaticLow : eTileEntityType::tileEntityObjectStatic;
                                    tEntity->base.type = (tEntity->base.flyOver) ? eEntityType::entityType_objectStaticLow : eEntityType::entityType_objectStatic;
                                }
                                else
                                {
                                    m_map->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;
                                    tEntity->base.type = eEntityType::entityType_none;
                                }

                                // Ownership
                                tEntity->base.owner = eEntityOwner::entityOwner_map;

                                // Scale
                                float scale = m_map->debris[i].scaleMin + (gRandFloatNormalized() * (m_map->debris[i].scaleMax - m_map->debris[i].scaleMin));
                                tEntity->base.scale *= scale;

                                // rotation
                                float rotation = gRandFloatNormalized() * M_PI * 2;
                                tEntity->base.rotation.x = rotation * tEntity->base.rotationAxis.x;
                                tEntity->base.rotation.y = rotation * tEntity->base.rotationAxis.y;
                                tEntity->base.rotation.z = rotation * tEntity->base.rotationAxis.z;

                                // position relative to tile
                                glm::vec3 tilePosition = gMapTileToPosition(m_map, tileNumber);
                                tEntity->base.position.x += tilePosition.x;
                                tEntity->base.position.y += m_map->info.terrainHeight;
                                tEntity->base.position.z += tilePosition.z;

                                // update model matrix
                                m_entityManager->updateModelMatrix(tEntity);

                                // Process collision data
                                m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

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
