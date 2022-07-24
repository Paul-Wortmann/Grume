
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

bool cMapManager::m_isPathConfig(const std::uint32_t &_tile,
                                  const std::uint32_t &_tile_00, const std::uint32_t &_tile_10, const std::uint32_t &_tile_20,
                                  const std::uint32_t &_tile_01, const std::uint32_t &_tile_11, const std::uint32_t &_tile_21,
                                  const std::uint32_t &_tile_02, const std::uint32_t &_tile_12, const std::uint32_t &_tile_22)
{

    // Tile position
    const std::int32_t tile_x = _tile % m_map->info.size_x;
    const std::int32_t tile_y = _tile / m_map->info.size_x;

    // Flags
    const std::uint32_t path     = 0;
    const std::uint32_t other    = 1;
    const std::uint32_t wildCard = 2;

    // Tiles
    // 00 10 20
    // 01 11 21
    // 02 12 22
    std::uint32_t t00 = other;
    std::uint32_t t10 = other;
    std::uint32_t t20 = other;
    std::uint32_t t01 = other;
    std::uint32_t t11 = other;
    std::uint32_t t21 = other;
    std::uint32_t t02 = other;
    std::uint32_t t12 = other;
    std::uint32_t t22 = other;

    /// Tile 00
    t00 = (m_isPath(tile_x - 1, tile_y - 1)) ? path : t00;
    t00 = (_tile_00 == wildCard) ? _tile_00 : t00;

    /// Tile 10
    t10 = (m_isPath(tile_x, tile_y - 1)) ? path : t10;
    t10 = (_tile_10 == wildCard) ? _tile_10 : t10;

    /// Tile 20
    t20 = (m_isPath(tile_x + 1, tile_y - 1)) ? path : t20;
    t20 = (_tile_20 == wildCard) ? _tile_20 : t20;

    /// Tile 01
    t01 = (m_isPath(tile_x - 1, tile_y)) ? path : t01;
    t01 = (_tile_01 == wildCard) ? _tile_01 : t01;

    /// Tile 11
    t11 = (m_isPath(tile_x, tile_y)) ? path : t11;
    t11 = (_tile_11 == wildCard) ? _tile_11 : t11;

    /// Tile 21
    t21 = (m_isPath(tile_x + 1, tile_y)) ? path : t21;
    t21 = (_tile_21 == wildCard) ? _tile_21 : t21;

    /// Tile 02
    t02 = (m_isPath(tile_x - 1, tile_y + 1)) ? path : t02;
    t02 = (_tile_02 == wildCard) ? _tile_02 : t02;

    /// Tile 12
    t12 = (m_isPath(tile_x, tile_y + 1)) ? path : t12;
    t12 = (_tile_12 == wildCard) ? _tile_12 : t12;

    /// Tile 22
    t22 = (m_isPath(tile_x + 1, tile_y + 1)) ? path : t22;
    t22 = (_tile_22 == wildCard) ? _tile_22 : t22;

    // Return result
    return ((t00 == _tile_00) && (t10 == _tile_10) && (t20 == _tile_20) &&
            (t01 == _tile_01) && (t11 == _tile_11) && (t21 == _tile_21) &&
            (t02 == _tile_02) && (t12 == _tile_12) && (t22 == _tile_22));
}

void cMapManager::m_pathTypeOrientation(const std::uint32_t &_tile, ePathType &_type, float &_orientation)
{
    // Early exit if not a path
    if ((m_map->tile[_tile].type != eTileType::tilePath) &&
        (m_map->tile[_tile].type != eTileType::tilePathNoGo))
        return;

    // Stand alone path tile
    if (m_isPathConfig(_tile,
                       1, 1, 1,
                       1, 0, 1,
                       1, 1, 1))
    {
        _type = ePathType::pathTypeFour;
        _orientation = rot000;
    }
    // Inner corner: quad
    else if (m_isPathConfig(_tile,
                       1, 0, 1,
                       0, 0, 0,
                       1, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerQuad;
        _orientation = rot000;
    }
    // Inner corner: triple
    else if (m_isPathConfig(_tile,
                            1, 0, 1,
                            0, 0, 0,
                            2, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerTriple;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 1,
                            0, 0, 0,
                            1, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerTriple;
        _orientation = rot000;
    }
    else if (m_isPathConfig(_tile,
                            1, 0, 2,
                            0, 0, 0,
                            1, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerTriple;
        _orientation = rot270;
    }
    else if (m_isPathConfig(_tile,
                            1, 0, 1,
                            0, 0, 0,
                            1, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerTriple;
        _orientation = rot180;
    }
    // Inner corner: opposite
    else if (m_isPathConfig(_tile,
                            1, 0, 2,
                            0, 0, 0,
                            2, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerOpposite;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 1,
                            0, 0, 0,
                            1, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerOpposite;
        _orientation = rot000;
    }
    // Inner corner: double
    else if (m_isPathConfig(_tile,
                            1, 0, 1,
                            0, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerDouble;
        _orientation = rot180;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 1,
                            0, 0, 0,
                            2, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerDouble;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 0,
                            1, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerDouble;
        _orientation = rot000;
    }
    else if (m_isPathConfig(_tile,
                            1, 0, 2,
                            0, 0, 0,
                            1, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerDouble;
        _orientation = rot270;
    }
    // Inner corner: single
    else if (m_isPathConfig(_tile,
                            1, 0, 2,
                            0, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerSingle;
        _orientation = rot270;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 1,
                            0, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerSingle;
        _orientation = rot180;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 0,
                            2, 0, 1))
    {
        _type = ePathType::pathTypeInnerCornerSingle;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 0,
                            1, 0, 2))
    {
        _type = ePathType::pathTypeInnerCornerSingle;
        _orientation = rot000;
    }
    // Stand alone path tile
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeMain;
        _orientation = rot000;
    }
    // triple sided
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            1, 0, 1,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeTriple;
        _orientation = rot000;
    }
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            1, 0, 1,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeTriple;
        _orientation = rot180;
    }
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            0, 0, 1,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeTriple;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            1, 0, 0,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeTriple;
        _orientation = rot270;
    }
    // corner
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            1, 0, 0,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeCorner;
        _orientation = rot000;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 1,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeCorner;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            0, 0, 1,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeCorner;
        _orientation = rot180;
    }
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            1, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeCorner;
        _orientation = rot270;
    }
    // Single sided
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 0,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeSingle;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            0, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeSingle;
        _orientation = rot270;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            0, 0, 1,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeSingle;
        _orientation = rot180;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            1, 0, 0,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeSingle;
        _orientation = rot000;
    }
    // Double sided
    else if (m_isPathConfig(_tile,
                            2, 1, 2,
                            0, 0, 0,
                            2, 1, 2))
    {
        _type = ePathType::pathTypeDouble;
        _orientation = rot090;
    }
    else if (m_isPathConfig(_tile,
                            2, 0, 2,
                            1, 0, 1,
                            2, 0, 2))
    {
        _type = ePathType::pathTypeDouble;
        _orientation = rot000;
    }
}

void cMapManager::m_addPaths(void)
{
    sEntity*      tEntity        = nullptr;
    ePathType     pathType       = ePathType::pathTypeNone;
    float         orientation    = 0.0f;

    // Load the biome file
    std::string biomeFileName = m_databaseManager->getDatabaseEntryFileName(m_map->info.biome, 1, eDatabaseType::databaseTypeBiome);
    cXML biomeFile;
    biomeFile.load(std::string(FILE_PATH_BIOME) + biomeFileName);
    if (!biomeFile.isValid())
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }

    // Reset processing flags
    for (std::uint32_t i = 0; i < m_map->numTiles; ++i)
    {
        m_map->tile[i].processed = false;
    }

    // Iterate over the data and add tiles accordingly
    for (std::uint32_t z = 0; z < m_map->info.size_y; ++z)
    {
        for (std::uint32_t x = 0; x < m_map->info.size_x; ++x)
        {
            tEntity     = nullptr;
            orientation = 0.0f;
            pathType    = ePathType::pathTypeNone;
            std::uint32_t tile = (z * m_map->info.size_x) + x;
            if (m_map->tile[tile].processed == false)
            {
                // Determine path type
                m_pathTypeOrientation(tile, pathType, orientation);

                // Path tile: corner
                if (pathType == ePathType::pathTypeCorner)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_corner>"));
                }
                // Path tile: double sided
                else if (pathType == ePathType::pathTypeDouble)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_double_sided>"));
                }
                // Path tile: four sided / quad sided
                else if (pathType == ePathType::pathTypeFour)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_four_sided>"));
                }
                // Path tile: Main
                else if (pathType == ePathType::pathTypeMain)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_main>"));
                }
                // Path tile: single sided
                else if (pathType == ePathType::pathTypeSingle)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_single_sided>"));
                }
                // Path tile: triple sided / t-junction
                else if (pathType == ePathType::pathTypeTriple)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_triple_sided>"));
                }
                // Path tile: inner corner single
                else if (pathType == ePathType::pathTypeInnerCornerSingle)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_inner_corner_single>"));
                }
                // Path tile: inner corner double
                else if (pathType == ePathType::pathTypeInnerCornerDouble)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_inner_corner_double>"));
                }
                // Path tile: inner corner opposite
                else if (pathType == ePathType::pathTypeInnerCornerOpposite)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_inner_corner_opposite>"));
                }
                // Path tile: inner corner triple
                else if (pathType == ePathType::pathTypeInnerCornerTriple)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_inner_corner_triple>"));
                }
                // Path tile: inner corner quad
                else if (pathType == ePathType::pathTypeInnerCornerQuad)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<path_inner_corner_quad>"));
                }
            }

            // Only initialize an entity if loaded
            if (tEntity != nullptr)
            {
                glm::vec3 tilePosition = gMapTileToPosition(m_map, tile);
                tEntity->base.position.x += tilePosition.x;
                tEntity->base.position.y += m_map->info.terrainHeight;
                tEntity->base.position.z += tilePosition.z;
                tEntity->base.rotation.y += orientation;
                tEntity->base.tileOnMap = tile;
                m_map->tile[tEntity->base.tileOnMap].processed = true;
                m_entityManager->updateModelMatrix(tEntity);
                tEntity->base.type     = eEntityType::entityType_floor;
                tEntity->base.owner    = eEntityOwner::entityOwner_map;
            }
        }
    }

    // Cleanup
    biomeFile.free();
}
