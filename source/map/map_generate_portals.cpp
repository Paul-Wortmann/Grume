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

void cMapManager::m_generatePortals(sMap*& _map)
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

    // Temporary entity pointer
    sEntity* tEntity = nullptr;

    // For each portal
    for (std::uint32_t p = 0; p < _map->numPortal; ++p)
    {

        // Load entity
        if (p == 0)
        {
            tEntity = m_entityManager->load(biomeFile.getString("<portal_stairs_up_single>"));
        }
        else
        {
            tEntity = m_entityManager->load(biomeFile.getString("<portal_stairs_down_single>"));
        }

        // Only place the object if the entity was loaded
        if (tEntity != nullptr)
        {
            std::uint32_t locationCount = m_mapGetFootprintCount(_map, tEntity);
            if (locationCount > 0)
            {
                std::uint32_t locationNum   = rand() % m_mapGetFootprintCount(_map, tEntity);
                std::uint32_t locationX     = 0;
                std::uint32_t locationY     = 0;
                std::uint32_t locationTile  = 0;

                if (m_mapGetFootprint(_map, tEntity, locationNum, locationX, locationY))
                {
                    locationX += static_cast<std::uint32_t>(tEntity->physics->halfDimentions.x);
                    locationY += static_cast<std::uint32_t>(tEntity->physics->halfDimentions.y);
                    locationTile = (locationY * _map->info.size_x) + locationX;

                    // Portal tile
                    m_map->portal[p].tile = locationTile + (_map->info.size_x * (tEntity->footprint->size_y / 2));
                    m_map->portal[p].rotation = rot180;

                    // Map tile position
                    tEntity->base.tileOnMap = locationTile;
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

                    // position relative to tile
                    glm::vec3 tilePosition = gMapTileToPosition(m_map, locationTile);
                    tEntity->base.position.x += tilePosition.x;
                    tEntity->base.position.y += m_map->info.terrainHeight;
                    tEntity->base.position.z += tilePosition.z;

                    // update model matrix
                    m_entityManager->updateModelMatrix(tEntity);

                    // Process collision data
                    m_addCollisionData(m_map, tEntity, tEntity->base.rotation.y);

                    // Add map events
                    tEntity->interaction->triggerEvent = p + 1; // non zero indexed array

                }
            }
            else
            // Try rotate the footprint and try again
            {

            }
        }
    }

    // pattern match entities footprint with map, find number of possible locations, choose 1 randomly
    // place object
    // set room to stairwell / portal type



    // Clean up
    biomeFile.free();
}
