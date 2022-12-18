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

void cMapManager::m_applyPrefab(const std::string &_fileName, const std::uint32_t &_r)
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

    // Open the prefab database file
    cXML xmlMapPrefabFile;
    xmlMapPrefabFile.load(FILE_PATH_MAP_PREFAB + _fileName);
    if (xmlMapPrefabFile.lineCount() > 0)
    {
        // Prefab position delta
        std::uint32_t dx = m_map->room[_r].x - (m_map->room[_r].w / 2); // Start x position on the map
        std::uint32_t dy = m_map->room[_r].y - (m_map->room[_r].h / 2); // Start y position on the map

        // load the tile data from the prefab
        std::uint32_t* pTiles = new std::uint32_t[m_map->room[_r].w * m_map->room[_r].h];
        std::uint32_t  currentTile = 0;
        std::uint32_t  tileKeyCount = xmlMapPrefabFile.getInstanceCount("<tiles>");
        for (std::uint32_t i = 0; i < tileKeyCount; ++i)
        {
            std::string tPTiles = xmlMapPrefabFile.getString("<tiles>", i + 1);
            tPTiles += " ";
            std::uint64_t tPTilesLength = tPTiles.length();
            std::string   tString = "";
            std::uint32_t tileCount = 0;
            if (tPTilesLength > 1)
            {
                for (std::uint64_t j = 0; j < tPTilesLength; ++j)
                {
                    if (tPTiles[j] == ',')
                    {
                        pTiles[currentTile] = std::stoi(tString);
                        currentTile++;
                        tString = "";
                        tileCount++;
                        if (tileCount == m_map->room[_r].w)
                        {
                            j = tPTilesLength;
                        }
                    }
                    else
                    {
                        tString += tPTiles[j];
                    }
                }
            }
        }

        // Write the prefab tile data to the map
        for (std::uint32_t y = 0; y < m_map->room[_r].h; ++y)
        {
            for (std::uint32_t x = 0; x < m_map->room[_r].w; ++x)
            {
                m_map->tile[((dy + y) * m_map->info.size_x) + dx + x].type = static_cast<eTileType>(pTiles[(y * m_map->room[_r].w) + x]);
            }
        }

        // Write the prefab object data to the map
        std::uint32_t mapObjectCount = xmlMapPrefabFile.getInstanceCount("<object>");

        if (mapObjectCount > 0)
        {
            // expand and add objects to the map object array?
            // this would be unnecessary, as pcg

            // Data parsing
            std::string   dataString       = {};
            std::uint64_t dataStringLength = 0;
            std::uint32_t tStringNum       = 0;
            std::string   tString          = {};
            bool          biomeObject      = false;

            // Temporary data
            sEntity*      tEntity                = nullptr;
            std::string   databaseName           = {};
            std::uint32_t databaseNumber         = 0;
            std::uint32_t object_tile_x          = 0;
            std::uint32_t object_tile_y          = 0;
            float         object_scale_x         = 0.0;
            float         object_scale_y         = 0.0;
            float         object_scale_z         = 0.0;
            float         object_rotation_x      = 0.0;
            float         object_rotation_y      = 0.0;
            float         object_rotation_z      = 0.0;
            std::uint32_t object_trigger_tile_x  = 0;
            std::uint32_t object_trigger_tile_y  = 0;
            std::uint32_t object_triggerEvent    = 0;
            std::uint32_t object_tile            = 0;
            std::uint32_t object_triggerTile     = 0;

            std::string   entity_fileName        = {};

            // Get and process each event entry
            for (std::uint32_t i = 0; i < mapObjectCount; ++i)
            {
                // Get data
                dataString  = xmlMapPrefabFile.getString("<object>", i + 1);
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
                    for (std::uint64_t j = 0; j < dataStringLength; ++j)
                    {
                        if (dataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                databaseName = tString; // database name
                            }
                            else if (tStringNum == 1)
                            {
                                databaseNumber = std::stoi(tString); // database name
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
                                object_scale_x = std::stof(tString); // Object scale x
                            }
                            else if (tStringNum == 5)
                            {
                                object_scale_y = std::stof(tString); // Object scale y
                            }
                            else if (tStringNum == 6)
                            {
                                object_scale_z = std::stof(tString); // Object scale z
                            }
                            else if (tStringNum == 7)
                            {
                                object_rotation_x = std::stof(tString); // Object rotation x
                            }
                            else if (tStringNum == 8)
                            {
                                object_rotation_y = std::stof(tString); // Object rotation y
                            }
                            else if (tStringNum == 9)
                            {
                                object_rotation_z = std::stof(tString); // Object rotation z
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
                                object_triggerEvent = std::stoi(tString); // trigger event number
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += dataString[j];
                        }

                        object_tile        = ((object_tile_y + dy) * m_map->info.size_x) + (object_tile_x + dx);
                        object_triggerTile = ((object_trigger_tile_y + dy) * m_map->info.size_x) + (object_trigger_tile_x + dx);
                    }
                }

                // Only place the object if the map tile is free
                if (m_map->tile[object_tile].entity.type == eTileEntityType::tileEntityNone)
                {
                    // Biome object load
                    if (biomeObject)
                    {
                        tEntity = m_entityManager->load(biomeFile.getString("<" + databaseName + ">"));
                    }
                    // Object database object load
                    else
                    {
                        // Retrieve the object filename from the database
                        entity_fileName = m_databaseManager->getDatabaseEntryFileName(databaseName, databaseNumber, eDatabaseType::databaseTypeObject);

                        // Load the entity
                        tEntity = m_entityManager->load(entity_fileName);
                    }

                    // Only place the object if the entity was loaded
                    if (tEntity != nullptr)
                    {
                        // Map tile position
                        tEntity->base.tileOnMap = object_tile;
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
                        tEntity->base.scale    += glm::vec3(object_scale_x, object_scale_y, object_scale_z);
                        tEntity->base.rotation += glm::vec3(object_rotation_x, object_rotation_y, object_rotation_z);

                        // position relative to tile
                        glm::vec3 tilePosition = gMapTileToPosition(m_map, object_tile);
                        tEntity->base.position.x += tilePosition.x;
                        tEntity->base.position.y += m_map->info.terrainHeight;
                        tEntity->base.position.z += tilePosition.z;

                        // update model matrix
                        m_entityManager->updateModelMatrix(tEntity);

                        // Process collision data
                        m_addCollisionData(m_map, tEntity, object_rotation_y);

                        // Add trigger events
                        if ((object_triggerEvent != 0) || (object_triggerTile != 0))
                        {
                            if (tEntity->interaction == nullptr)
                            {
                                tEntity->interaction = new sEntityInteraction;
                            }
                            //tEntity->interaction->type
                            tEntity->interaction->triggerEvent = object_triggerEvent;
                            tEntity->interaction->triggerTile  = object_triggerTile;
                        }
                    }
                }
            }
        }

        // Clean up
        xmlMapPrefabFile.free();
        biomeFile.free();

        if (pTiles != nullptr)
        {
            delete[] pTiles;
            pTiles = nullptr;
        }
    }

}

void cMapManager::m_addPrefabs(void)
{
    // Get the prefab data
    sPrefabData*  prefabData = m_databaseManager->getPrefabDataPointer();
    std::uint32_t numPrefabData = m_databaseManager->getNumPrefabData();

    // loop through each room in the map
    for (std::uint32_t r = 0; r < m_map->numRoom; ++r)
    {
        // loop through each prefab, count number compatible
        std::uint32_t numCompatible = 0;
        for (std::uint32_t p = 0; p < numPrefabData; ++p)
        {
            // look for a match
            if ((m_map->room[r].w == prefabData[p].roomSize_x) &&
                (m_map->room[r].h == prefabData[p].roomSize_y) &&
                ((m_map->room[r].type == eMapRoomType::roomTypeNone) ||
                 (m_map->room[r].type == static_cast<eMapRoomType>(prefabData[p].roomType))))
            {
                numCompatible++;
            }
        }

        // Select one at random and apply it.
        if (numCompatible > 0)
        {
            std::uint32_t prefabNum = 0;

            // Generate random number
            std::uint32_t rndPrefab = rand() % numCompatible;

            // Generate random number
            for (std::uint32_t p = 0; p < numPrefabData; ++p)
            {
                // look for a match and apply the prefab
                if ((m_map->room[r].w == prefabData[p].roomSize_x) &&
                    (m_map->room[r].h == prefabData[p].roomSize_y) &&
                    ((m_map->room[r].type == eMapRoomType::roomTypeNone) ||
                     (m_map->room[r].type == static_cast<eMapRoomType>(prefabData[p].roomType))))
                {
                    if (prefabNum == rndPrefab)
                    {
                        m_applyPrefab(prefabData[p].fileName, r);
                        m_map->room[r].type = static_cast<eMapRoomType>(prefabData[p].roomType);
                    }
                    prefabNum++;
                }
            }
        }
    }
}
