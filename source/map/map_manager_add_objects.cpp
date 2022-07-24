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

void cMapManager::m_addObjects(void)
{
    // Load the biome file
    std::string biomeFileName = m_databaseManager->getDatabaseEntryFileName(m_map->info.biome, 1, eDatabaseType::databaseTypeBiome);
    cXML biomeFile;
    biomeFile.load(std::string(FILE_PATH_BIOME) + biomeFileName);
    if (!biomeFile.isValid())
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }

    // Map file
    cXML mapFile;
    mapFile.load(std::string(FILE_PATH_MAP) + m_map->info.fileName);
    if (mapFile.isValid())
    {
        // Map Objects
        m_map->numObject = mapFile.getInstanceCount("<object>");
        if (m_map->numObject > 0)
        {
            // Allocate memory for object data
            m_map->object = new sMapObject[m_map->numObject];

            // Data parsing
            std::string   dataString       = {};
            std::uint32_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};
            bool          biomeObject      = false;

            // Temporary data
            sEntity*      tEntity                = nullptr;
            std::uint32_t object_tile_x          = 0;
            std::uint32_t object_tile_y          = 0;
            std::uint32_t object_trigger_tile_x  = 0;
            std::uint32_t object_trigger_tile_y  = 0;

            std::string   entity_fileName        = {};

            // Get and process each event entry
            for (std::uint32_t i = 0; i < m_map->numObject; ++i)
            {
                // Get data
                dataString  = mapFile.getString("<object>", i + 1);
                dataString += " "; // end of string marker
                dataStringLength = dataString.length();
                tStringNum  = 0;
                tString     = "";
                biomeObject = false;

                // Skip these objects if found
                // These objects are biome specific

                // Stairs
                if (dataString.find("portal_stairs_down_single") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_stairs_up_single") != std::string::npos)
                    biomeObject = true;

                // Cave entrance
                if (dataString.find("portal_cave_single") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_cave_left") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_cave_right") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_cave_center") != std::string::npos)
                    biomeObject = true;

                // Map opening
                if (dataString.find("portal_opening_single") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_opening_left") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_opening_right") != std::string::npos)
                    biomeObject = true;
                if (dataString.find("portal_opening_center") != std::string::npos)
                    biomeObject = true;

                // Process data
                /// # database name, number, tile x, y, scale x, y, z, rotation x, y, z, trigger tile x, y, trigger event number
                if (dataStringLength > 4)
                {
                    for (std::uint32_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_map->object[i].databaseName = tString; // database name
                            }
                            else if (tStringNum == 1)
                            {
                                m_map->object[i].databaseNumber = std::stoi(tString); // database name
                            }
                            else if (tStringNum == 2)
                            {
                                object_tile_x = std::stoi(tString); // object_tile_x
                            }
                            else if (tStringNum == 3)
                            {
                                object_tile_y = std::stoi(tString); // object_tile_y
                            }
                            else if (tStringNum == 4)
                            {
                                m_map->object[i].scale.x = std::stof(tString); // Object scale x
                            }
                            else if (tStringNum == 5)
                            {
                                m_map->object[i].scale.y = std::stof(tString); // Object scale y
                            }
                            else if (tStringNum == 6)
                            {
                                m_map->object[i].scale.z = std::stof(tString); // Object scale z
                            }
                            else if (tStringNum == 7)
                            {
                                m_map->object[i].rotation.x = std::stof(tString); // Object rotation x
                            }
                            else if (tStringNum == 8)
                            {
                                m_map->object[i].rotation.y = std::stof(tString); // Object rotation y
                            }
                            else if (tStringNum == 9)
                            {
                                m_map->object[i].rotation.z = std::stof(tString); // Object rotation z
                            }
                            else if (tStringNum == 10)
                            {
                                object_trigger_tile_x = std::stoi(tString); // object_trigger_tile_x
                            }
                            else if (tStringNum == 11)
                            {
                                object_trigger_tile_y = std::stoi(tString); // object_trigger_tile_y
                            }
                            else if (tStringNum == 12)
                            {
                                m_map->object[i].triggerEvent = std::stoi(tString); // trigger event number
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }
                        m_map->object[i].tile        = (object_tile_y * m_map->info.size_x) + object_tile_x;
                        m_map->object[i].triggerTile = (object_trigger_tile_y * m_map->info.size_x) + object_trigger_tile_x;
                    }
                }

                // Only place the object if the map tile is free
                if (m_map->tile[m_map->object[i].tile].entity.type == eTileEntityType::tileEntityNone)
                {
                    // Biome object load
                    if (biomeObject)
                    {
                        tEntity = m_entityManager->load(biomeFile.getString("<" + m_map->object[i].databaseName + ">"));
                    }
                    // Object database object load
                    else
                    {
                        // Retrieve the object filename from the database
                        entity_fileName = m_databaseManager->getDatabaseEntryFileName(m_map->object[i].databaseName, m_map->object[i].databaseNumber, eDatabaseType::databaseTypeObject);

                        // Load the entity
                        tEntity = m_entityManager->load(entity_fileName);
                    }

                    // Only place the object if the entity was loaded
                    if (tEntity != nullptr)
                    {
                        // Map tile position
                        tEntity->base.tileOnMap = m_map->object[i].tile;
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

                        // Scale and rotation
                        tEntity->base.scale    += m_map->object[i].scale;
                        tEntity->base.rotation += m_map->object[i].rotation;

                        // position relative to tile
                        glm::vec3 tilePosition = gMapTileToPosition(m_map, m_map->object[i].tile);
                        tEntity->base.position.x += tilePosition.x;
                        tEntity->base.position.y += m_map->info.terrainHeight;
                        tEntity->base.position.z += tilePosition.z;

                        // update model matrix
                        m_entityManager->updateModelMatrix(tEntity);

                        // Process collision data
                        m_addCollisionData(m_map, tEntity, m_map->object[i].rotation.y);

                        // Add trigger events
                        if ((m_map->object[i].triggerEvent != 0) || (m_map->object[i].triggerTile != 0))
                        {
                            if (tEntity->interaction == nullptr)
                            {
                                tEntity->interaction = new sEntityInteraction;
                            }
                            //tEntity->interaction->type
                            tEntity->interaction->triggerEvent = m_map->object[i].triggerEvent;
                            tEntity->interaction->triggerTile  = m_map->object[i].triggerTile;
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
    biomeFile.free();
}
