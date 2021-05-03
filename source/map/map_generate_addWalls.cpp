/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"

// Either generate thick walls or thin walls depending on map data
void cMapManager::m_addWallEntities(sMap*& _map)
{
    if (_map->genData.wallSize == 0)
    {
        m_addWallWideEntities(_map);
    }
    else
    {
        m_addWallThinEntities(_map);
    }
}

// Is the queried tile a tile of type: None or Floor?
bool cMapManager::m_isFlat(sMap*& _map, const uint32 &_tile)
{
    return ((_map->tile[_tile].base == eTileBase::tileFloor) ||
            (_map->tile[_tile].base == eTileBase::tileNone));
}

// Is the queried tile a tile of type: None?
bool cMapManager::m_isNone(sMap*& _map, const uint32 &_tile)
{
    return (_map->tile[_tile].base == eTileBase::tileNone);
}

// Is the queried tile a tile of type: Floor?
bool cMapManager::m_isFloor(sMap*& _map, const uint32 &_tile)
{
    return (_map->tile[_tile].base == eTileBase::tileFloor);
}

// Is the queried tile a tile of type: Wall?
bool cMapManager::m_isWall(sMap*& _map, const uint32 &_tile)
{
    return (_map->tile[_tile].base == eTileBase::tileWall);
}

// Is the queried tile a tile of type: Doorway or Wall?
bool cMapManager::m_isDWall(sMap*& _map, const uint32 &_tile)
{
    if (_map->tile[_tile].base == eTileBase::tileWall)
    {
        return true;
    }
    if (_map->tile[_tile].base == eTileBase::tileDoorway)
    {
        return true;
    }
    return false;
}

// Is the queried tile a tile of type: Doorway?
bool cMapManager::m_isDoor(sMap*& _map, const uint32 &_tile)
{
    return (_map->tile[_tile].base == eTileBase::tileDoorway);
}

// Add wall entities based on the tile map (Large walls, such as in a cave)
void cMapManager::m_addWallWideEntities(sMap*& _map)
{
    // Reset tile processed flags
    for (std::size_t i = 0; i < _map->numTiles; ++i)
    {
        _map->tile[i].processed = false;
    }

    // Map floor position on the y axis
    float32 y_pos = -1.0f;
    
    // Load the map wall biome file
    cXML xmlFile;
    xmlFile.load(FILE_PATH_BIOME + _map->biome->WallSet.fileName);
    
    // Only contine if we can load the biome wallset file
    if (xmlFile.lineCount() > 0)
    {

        sEntity* tEntity = nullptr;

        // Width and height offset, used to center the walls
        uint32  xo = _map->width  / 2;
        uint32  yo = _map->height / 2;
        float32 tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

        // Perimeter --------------------------------------------------------------------------------------------
        // Corner [0,0]
        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
        tEntity->owner = eEntityOwner::ownerMap;
        tEntity->position = glm::vec3(static_cast<float32>(0) + tp - xo, y_pos, static_cast<float32>(0) + tp - yo);
        tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
        entityManager->updateModelMatrix(tEntity);
        _map->tile[0].processed = true;

        // Corner [max,0]
        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
        tEntity->owner = eEntityOwner::ownerMap;
        tEntity->position = glm::vec3(static_cast<float32>(_map->width-1) + tp - xo, y_pos, static_cast<float32>(0) + tp - yo);
        tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
        entityManager->updateModelMatrix(tEntity);
        _map->tile[_map->width - 1].processed = true;

        // Corner [max,max]
        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
        tEntity->owner = eEntityOwner::ownerMap;
        tEntity->position = glm::vec3(static_cast<float32>(_map->width-1) + tp - xo, y_pos, static_cast<float32>(_map->height-1) + tp - yo);
        tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
        entityManager->updateModelMatrix(tEntity);
        _map->tile[_map->numTiles - 1].processed = true;

        // Corner [0,max]
        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
        tEntity->owner = eEntityOwner::ownerMap;
        tEntity->position = glm::vec3(static_cast<float32>(0) + tp - xo, y_pos, static_cast<float32>(_map->height-1) + tp - yo);
        tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
        entityManager->updateModelMatrix(tEntity);
        _map->tile[_map->numTiles - _map->width].processed = true;

        // Sides - X
        for (uint32 w = 1; w < _map->width-1; ++w)
        {
            // Side [w,0]
            uint32 h = 0;
            uint32 t = (h * _map->width) + w;
            if (m_isDWall(_map, t + _map->width))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_wd_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[t + _map->width].processed = true;

            // Side [max - w, 0]
            h = _map->height-1;
            t = (h * _map->width) + w;
            if (m_isDWall(_map, t - _map->width))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_wd_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[t - _map->width].processed = true;
        }

        // Sides - Y
        for (uint32 h = 1; h < _map->height-1; ++h)
        {
            // Side [0,h]
            uint32 w = 0;
            uint32 t = (h * _map->width) + w;
            if (m_isDWall(_map, t + 1))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_wd_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[t + 1].processed = true;

            // Side [0,max - h]
            w = _map->width - 1;
            t = (h * _map->width) + w;
            if (m_isDWall(_map, t - 1))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_wd_entity>", 1));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[t - 1].processed = true;
        }

        // Non perimeter --------------------------------------------------------------------------------------------
        for (uint32 h = 1; h < _map->height-1; ++h)
        {
            for (uint32 w = 1; w < _map->width-1; ++w)
            {
                uint32 t = (h * _map->width) + w;
                if (_map->tile[t].base == eTileBase::tileWall)
                {
                    // used to determine if we have loaded a new entity
                    bool found = true;

                    // Top
                    // ? W ?
                    // W W W
                    // ? W ?
                    if ((m_isDWall(_map, t + 1)) &&
                        (m_isDWall(_map, t - 1)) &&
                        (m_isDWall(_map, t + _map->width)) &&
                        (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wt_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                    }

                    // Pillar
                    // ? F ?
                    // F W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wp_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                    }
                    // Double sided
                    // ? F ?
                    // W W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wd_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                    }
                    // ? W ?
                    // F W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wd_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                    }

                    // Single sided
                    // ? W ?
                    // W W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                    }
                    // ? W ?
                    // F W W
                    // ? W ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                    }
                    // ? F ?
                    // W W W
                    // ? W ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                    }
                    // ? W ?
                    // W W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_ws_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                    }

                    // End
                    // ? W ?
                    // F W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_we_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                    }
                    // ? F ?
                    // F W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_we_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                    }
                    // ? F ?
                    // F W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_we_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                    }
                    // ? F ?
                    // W W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_we_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                    }

                    // Corner
                    // ? W ?
                    // F W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                    }
                    // ? F ?
                    // F W W
                    // ? W ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                    }
                    // ? F ?
                    // W W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                    }
                    // ? W ?
                    // W W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wc_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                        tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                    }

/*
                    else
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_wp_entity>", 1));
                        tEntity->owner = eEntityOwner::ownerMap;
                    }
*/


                    else
                    {
                        found = false;
                    }
                    // If a pattern was found update the new entity's model matrix
                    if (found)
                    {
                        tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                        entityManager->updateModelMatrix(tEntity);
                        _map->tile[t].processed = true;
                    }

                }
            }
        }

        // Clean up
        xmlFile.free();
    }
}

// Add wall entities based on the tile map (Thin walls, such as in a dungeon)
// Generation order:
// 1. Entrances and Exits, these are high priority
// 2. Perimeter walls
// 3. Walls of length 3
// 4. Walls of length 2
// 5. Walls of length 1

void cMapManager::m_addWallThinEntities(sMap*& _map)
{
    // Reset tile processed flags
    for (std::size_t i = 0; i < _map->numTiles; ++i)
    {
        _map->tile[i].processed = false;
    }

    // Map floor position on the y axis
    float32 y_pos = -1.0f;
    
    // Load the biome wallset file
    cXML xmlFile;
    xmlFile.load(FILE_PATH_BIOME + _map->biome->WallSet.fileName);
    
    // Only contine if we can load the biome wallset file
    if (xmlFile.lineCount() > 0)
    {
        // Get a count for wall type
        // Length 3
        std::uint32_t wall_3tus_count = xmlFile.getInteger("<wall_3tus_count>", 1); // Up stairs, length 3
        std::uint32_t wall_3tds_count = xmlFile.getInteger("<wall_3tds_count>", 1); // Down stairs, length 3
        std::uint32_t wall_3td_count  = xmlFile.getInteger("<wall_3td_count>",  1); // Double sided wall, length 3

        // Length 2
        std::uint32_t wall_2tus_count = xmlFile.getInteger("<wall_2tus_count>", 1); // Up stairs, length 2
        std::uint32_t wall_2tds_count = xmlFile.getInteger("<wall_2tds_count>", 1); // Down stairs, length 2
        std::uint32_t wall_2td_count  = xmlFile.getInteger("<wall_2td_count>",  1); // Double sided wall, length 2

        // Length 1
        std::uint32_t wall_1tus_count = xmlFile.getInteger("<wall_1tus_count>", 1); // Up stairs, length 1
        std::uint32_t wall_1tds_count = xmlFile.getInteger("<wall_1tds_count>", 1); // Down stairs, length 1
        std::uint32_t wall_1tp_count  = xmlFile.getInteger("<wall_1tp_count>",  1); // pillar
        std::uint32_t wall_1te_count  = xmlFile.getInteger("<wall_1te_count>",  1); // wall end
        std::uint32_t wall_1td_count  = xmlFile.getInteger("<wall_1td_count>",  1); // double sided wall
        std::uint32_t wall_1tc_count  = xmlFile.getInteger("<wall_1tc_count>",  1); // c wall junction
        std::uint32_t wall_1tt_count  = xmlFile.getInteger("<wall_1tt_count>",  1); // t wall junction
        std::uint32_t wall_1tx_count  = xmlFile.getInteger("<wall_1tx_count>",  1); // x wall junction
        std::uint32_t wall_1ts_count  = xmlFile.getInteger("<wall_1ts_count>",  1); // small doorway
        std::uint32_t wall_1tl_count  = xmlFile.getInteger("<wall_1tl_count>",  1); // large doorway
        std::uint32_t wall_1ta_count  = xmlFile.getInteger("<wall_1ta_count>",  1); // arch cap

        // Create a temporary entity pointer
        sEntity* tEntity = nullptr;

        // Width and height offset, used to center the walls
        uint32  xo = _map->width  / 2;
        uint32  yo = _map->height / 2;
        float32 tp = 1.0f / 2.0f; // tile center positioning ( half tile width)

        // 1. Exits and Entrances ----------------------------------------------------------------------------------
        // Try to place length 3 first, then 2, then 1
        bool entrance_placed = false;
        bool exit_placed     = false;
        // Length 3
        for (uint32 h = 1; h < _map->height - 4; ++h) // We need up to 3 tiles in front of stairs
        {
            for (uint32 w = 2; w < _map->width - 2; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                // Entrance
                if ((!entrance_placed) && (wall_3tus_count > 0))
                {
                    if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                    {
                        // ? F F F ?
                        // W W - W W
                        // ? N N N ?
                        // ? N N N ?
                        // ? F F F ?
                        if      ((m_isFlat(_map, t - _map->width)) &&
                                 (m_isFlat(_map, t - _map->width + 1)) &&
                                 (m_isFlat(_map, t - _map->width - 1)) &&
                                 (m_isWall (_map, t + 1)) &&
                                 (m_isWall (_map, t - 1)) &&
                                 (m_isWall (_map, t + 2)) &&
                                 (m_isWall (_map, t - 2)) &&
                                 (m_isNone(_map, t + _map->width)) &&
                                 (m_isNone(_map, t + _map->width + 1)) &&
                                 (m_isNone(_map, t + _map->width - 1)) &&
                                 (m_isNone(_map, t + (2 * _map->width))) &&
                                 (m_isNone(_map, t + (2 * _map->width) + 1)) &&
                                 (m_isNone(_map, t + (2 * _map->width) - 1)) &&
                                 (m_isFlat(_map, t + (3 * _map->width))) &&
                                 (m_isFlat(_map, t + (3 * _map->width) + 1)) &&
                                 (m_isFlat(_map, t + (3 * _map->width) - 1)) &&
                                 (!_map->tile[t + 1].processed) &&
                                 (!_map->tile[t - 1].processed))
                        {
                            tEntity = entityManager->load(xmlFile.getString("<wall_3tus_entity>", 1 + (rand() % wall_3tus_count)));
                            tEntity->owner = eEntityOwner::ownerMap;
                            if (tEntity != nullptr)
                            {
                                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                entityManager->updateModelMatrix(tEntity);
                                _map->tile[t].processed = true;
                                _map->tile[t + 1].processed = true;
                                _map->tile[t - 1].processed = true;
                                _map->tile[t + _map->width].object = 0; // No object
                                _map->tile[t + _map->width + 1].object = 0; // No object
                                _map->tile[t + _map->width - 1].object = 0; // No object
                                _map->tile[t + (2 * _map->width)].object = 0; // No object
                                _map->tile[t + (2 * _map->width) + 1].object = 0; // No object
                                _map->tile[t + (2 * _map->width) - 1].object = 0; // No object
                                _map->tile[t + (3 * _map->width)].object = 0; // No object
                                _map->tile[t + (3 * _map->width) + 1].object = 0; // No object
                                _map->tile[t + (3 * _map->width) - 1].object = 0; // No object
                                entrance_placed = true;
                            }
                        }
                    }
                }

                // Exit
                if ((!exit_placed) && (wall_3tds_count > 0))
                {
                    if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                    {
                        // ? F F F ?
                        // W W - W W
                        // ? N N N ?
                        // ? N N N ?
                        // ? F F F ?
                        if      ((m_isFlat(_map, t - _map->width)) &&
                                 (m_isFlat(_map, t - _map->width + 1)) &&
                                 (m_isFlat(_map, t - _map->width - 1)) &&
                                 (m_isWall (_map, t + 1)) &&
                                 (m_isWall (_map, t - 1)) &&
                                 (m_isWall (_map, t + 2)) &&
                                 (m_isWall (_map, t - 2)) &&
                                 (m_isNone(_map, t + _map->width)) &&
                                 (m_isNone(_map, t + _map->width + 1)) &&
                                 (m_isNone(_map, t + _map->width - 1)) &&
                                 (m_isNone(_map, t + (2 * _map->width))) &&
                                 (m_isNone(_map, t + (2 * _map->width) + 1)) &&
                                 (m_isNone(_map, t + (2 * _map->width) - 1)) &&
                                 (m_isFlat(_map, t + (3 * _map->width))) &&
                                 (m_isFlat(_map, t + (3 * _map->width) + 1)) &&
                                 (m_isFlat(_map, t + (3 * _map->width) - 1)) &&
                                 (!_map->tile[t + 1].processed) &&
                                 (!_map->tile[t - 1].processed))
                        {
                            tEntity = entityManager->load(xmlFile.getString("<wall_3tds_entity>", 1 + (rand() % wall_3tds_count)));
                            tEntity->owner = eEntityOwner::ownerMap;
                            if (tEntity != nullptr)
                            {
                                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                entityManager->updateModelMatrix(tEntity);
                                _map->tile[t].processed = true;
                                _map->tile[t + 1].processed = true;
                                _map->tile[t - 1].processed = true;
                                _map->tile[t + _map->width].object = 0; // No object
                                _map->tile[t + _map->width + 1].object = 0; // No object
                                _map->tile[t + _map->width - 1].object = 0; // No object
                                _map->tile[t + (2 * _map->width)].object = 0; // No object
                                _map->tile[t + (2 * _map->width) + 1].object = 0; // No object
                                _map->tile[t + (2 * _map->width) - 1].object = 0; // No object
                                _map->tile[t + (3 * _map->width)].object = 0; // No object
                                _map->tile[t + (3 * _map->width) + 1].object = 0; // No object
                                _map->tile[t + (3 * _map->width) - 1].object = 0; // No object
                                exit_placed = true;
                            }
                        }
                    }
                }
            }
        }

        // Length 2
        for (uint32 h = 1; h < _map->height - 4; ++h) // We need up to 3 tiles in front of stairs
        {
            for (uint32 w = 2; w < _map->width - 2; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                // Entrance
                if ((!entrance_placed) && (wall_2tus_count > 0))
                {
                    if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                    {
                        // ? F F ?
                        // W - W W
                        // ? N N ?
                        // ? N N ?
                        // ? F F ?
                        if      ((m_isFlat(_map, t - _map->width)) &&
                                 (m_isFlat(_map, t - _map->width + 1)) &&
                                 (m_isWall (_map, t + 1)) &&
                                 (m_isWall (_map, t - 1)) &&
                                 (m_isWall (_map, t + 2)) &&
                                 (m_isNone(_map, t + _map->width)) &&
                                 (m_isNone(_map, t + _map->width + 1)) &&
                                 (m_isNone(_map, t + (2 * _map->width))) &&
                                 (m_isNone(_map, t + (2 * _map->width) + 1)) &&
                                 (m_isFlat(_map, t + (3 * _map->width))) &&
                                 (m_isFlat(_map, t + (3 * _map->width) + 1)) &&
                                 (!_map->tile[t + 1].processed))
                        {
                            tEntity = entityManager->load(xmlFile.getString("<wall_2tus_entity>", 1 + (rand() % wall_2tus_count)));
                            tEntity->owner = eEntityOwner::ownerMap;
                            if (tEntity != nullptr)
                            {
                                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                entityManager->updateModelMatrix(tEntity);
                                _map->tile[t].processed = true;
                                _map->tile[t + 1].processed = true;
                                _map->tile[t + _map->width].object = 0; // No object
                                _map->tile[t + _map->width + 1].object = 0; // No object
                                _map->tile[t + (2 * _map->width)].object = 0; // No object
                                _map->tile[t + (2 * _map->width) + 1].object = 0; // No object
                                _map->tile[t + (3 * _map->width)].object = 0; // No object
                                _map->tile[t + (3 * _map->width) + 1].object = 0; // No object
                                entrance_placed = true;
                            }
                        }
                    }
                }

                // Exit
                if ((!exit_placed) && (wall_2tds_count > 0))
                {
                    if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                    {
                        // ? F F ?
                        // W - W W
                        // ? N N ?
                        // ? N N ?
                        // ? F F ?
                        if      ((m_isFlat(_map, t - _map->width)) &&
                                 (m_isFlat(_map, t - _map->width + 1)) &&
                                 (m_isWall (_map, t + 1)) &&
                                 (m_isWall (_map, t - 1)) &&
                                 (m_isWall (_map, t + 2)) &&
                                 (m_isNone(_map, t + _map->width)) &&
                                 (m_isNone(_map, t + _map->width + 1)) &&
                                 (m_isNone(_map, t + (2 * _map->width))) &&
                                 (m_isNone(_map, t + (2 * _map->width) + 1)) &&
                                 (m_isFlat(_map, t + (3 * _map->width))) &&
                                 (m_isFlat(_map, t + (3 * _map->width) + 1)) &&
                                 (!_map->tile[t + 1].processed))
                        {
                            tEntity = entityManager->load(xmlFile.getString("<wall_2tds_entity>", 1 + (rand() % wall_2tds_count)));
                            tEntity->owner = eEntityOwner::ownerMap;
                            if (tEntity != nullptr)
                            {
                                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                entityManager->updateModelMatrix(tEntity);
                                _map->tile[t].processed = true;
                                _map->tile[t + 1].processed = true;
                                _map->tile[t + _map->width].object = 0; // No object
                                _map->tile[t + _map->width + 1].object = 0; // No object
                                _map->tile[t + (2 * _map->width)].object = 0; // No object
                                _map->tile[t + (2 * _map->width) + 1].object = 0; // No object
                                _map->tile[t + (3 * _map->width)].object = 0; // No object
                                _map->tile[t + (3 * _map->width) + 1].object = 0; // No object
                                exit_placed = true;
                            }
                        }
                    }
                }
            }
        }

        // Length 1
        for (uint32 h = 1; h < _map->height - 4; ++h) // We need up to 3 tiles in front of stairs
        {
            for (uint32 w = 2; w < _map->width - 2; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                // Entrance
                if ((!entrance_placed) && (wall_1tus_count > 0))
                {
                    if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                    {
                        // ? F ?
                        // W - W
                        // ? N ?
                        // ? N ?
                        // ? F ?
                        if      ((m_isFlat(_map, t - _map->width)) &&
                                 (m_isWall (_map, t + 1)) &&
                                 (m_isWall (_map, t - 1)) &&
                                 (m_isNone(_map, t + _map->width)) &&
                                 (m_isNone(_map, t + (2 * _map->width))) &&
                                 (m_isFlat(_map, t + (3 * _map->width))))
                        {
                            tEntity = entityManager->load(xmlFile.getString("<wall_1tus_entity>", 1 + (rand() % wall_1tus_count)));
                            tEntity->owner = eEntityOwner::ownerMap;
                            if (tEntity != nullptr)
                            {
                                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                entityManager->updateModelMatrix(tEntity);
                                _map->tile[t].processed = true;
                                _map->tile[t + _map->width].object = 0; // No object
                                _map->tile[t + (2 * _map->width)].object = 0; // No object
                                _map->tile[t + (3 * _map->width)].object = 0; // No object
                                entrance_placed = true;
                            }
                        }
                    }
                }

                // Exit
                if ((!exit_placed) && (wall_2tds_count > 0))
                {
                    if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                    {
                        // ? F ?
                        // W - W
                        // ? N ?
                        // ? N ?
                        // ? F ?
                        if      ((m_isFlat(_map, t - _map->width)) &&
                                 (m_isWall (_map, t + 1)) &&
                                 (m_isWall (_map, t - 1)) &&
                                 (m_isNone(_map, t + _map->width)) &&
                                 (m_isNone(_map, t + (2 * _map->width))) &&
                                 (m_isFlat(_map, t + (3 * _map->width))))
                        {
                            tEntity = entityManager->load(xmlFile.getString("<wall_1tds_entity>", 1 + (rand() % wall_1tds_count)));
                            tEntity->owner = eEntityOwner::ownerMap;
                            if (tEntity != nullptr)
                            {
                                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                                entityManager->updateModelMatrix(tEntity);
                                _map->tile[t].processed = true;
                                _map->tile[t + _map->width].object = 0; // No object
                                _map->tile[t + (2 * _map->width)].object = 0; // No object
                                _map->tile[t + (3 * _map->width)].object = 0; // No object
                                exit_placed = true;
                            }
                        }
                    }
                }
            }
        }

        // 2. Perimeter --------------------------------------------------------------------------------------------
        // Corner [0,0]
        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
        tEntity->owner = eEntityOwner::ownerMap;
        if (tEntity != nullptr)
        {
            tEntity->position = glm::vec3(static_cast<float32>(0) + tp - xo, y_pos, static_cast<float32>(0) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[0].processed = true;
        }
        // Corner [max,0]
        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
        tEntity->owner = eEntityOwner::ownerMap;
        if (tEntity != nullptr)
        {
            tEntity->position = glm::vec3(static_cast<float32>(_map->width-1) + tp - xo, y_pos, static_cast<float32>(0) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[_map->width - 1].processed = true;
        }

        // Corner [max,max]
        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
        tEntity->owner = eEntityOwner::ownerMap;
        if (tEntity != nullptr)
        {
            tEntity->position = glm::vec3(static_cast<float32>(_map->width-1) + tp - xo, y_pos, static_cast<float32>(_map->height-1) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[_map->numTiles - 1].processed = true;
        }

        // Corner [0,max]
        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
        tEntity->owner = eEntityOwner::ownerMap;
        if (tEntity != nullptr)
        {
            tEntity->position = glm::vec3(static_cast<float32>(0) + tp - xo, y_pos, static_cast<float32>(_map->height-1) + tp - yo);
            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
            entityManager->updateModelMatrix(tEntity);
            _map->tile[_map->numTiles - _map->width].processed = true;
        }

        // Sides - X
        for (uint32 w = 1; w < _map->width-1; ++w)
        {
            // Side [w,0]
            uint32 h = 0;
            uint32 t = (h * _map->width) + w;
            if (m_isDWall(_map, t + _map->width))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1td_entity>", 1 + (rand() % wall_1td_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            if (tEntity != nullptr)
            {
                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                entityManager->updateModelMatrix(tEntity);
                _map->tile[t].processed = true;
            }

            // Side [max - w, 0]
            h = _map->height-1;
            t = (h * _map->width) + w;
            if (m_isDWall(_map, t - _map->width))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1td_entity>", 1 + (rand() % wall_1td_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            if (tEntity != nullptr)
            {
                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                entityManager->updateModelMatrix(tEntity);
                _map->tile[t].processed = true;
            }
        }

        // Sides - Y
        for (uint32 h = 1; h < _map->height-1; ++h)
        {
            // Side [0,h]
            uint32 w = 0;
            uint32 t = (h * _map->width) + w;
            if (m_isDWall(_map, t + 1))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1td_entity>", 1 + (rand() % wall_1td_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            if (tEntity != nullptr)
            {
                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                entityManager->updateModelMatrix(tEntity);
                _map->tile[t].processed = true;
            }

            // Side [0,max - h]
            w = _map->width - 1;
            t = (h * _map->width) + w;
            if (m_isDWall(_map, t - 1))
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            else
            {
                tEntity = entityManager->load(xmlFile.getString("<wall_1td_entity>", 1 + (rand() % wall_1td_count)));
                tEntity->owner = eEntityOwner::ownerMap;
            }
            if (tEntity != nullptr)
            {
                tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                entityManager->updateModelMatrix(tEntity);
                _map->tile[t].processed = true;
            }
        }

        // 3. Walls of length 3 ----------------------------------------------------------------------------------
        for (uint32 h = 3; h < _map->height - 3; ++h) // We need up 2 tiles of padding on each side, and 1 for index from 0
        {
            for (uint32 w = 3; w < _map->width - 3; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                {
                    // ? F F F ?
                    // W W - W W
                    // ? F F F ?
                    if      ((m_isFlat(_map, t - _map->width)) &&
                             (m_isFlat(_map, t - _map->width + 1)) &&
                             (m_isFlat(_map, t - _map->width - 1)) &&
                             (m_isWall (_map, t + 1)) &&
                             (m_isWall (_map, t - 1)) &&
                             (m_isWall (_map, t + 2)) &&
                             (m_isWall (_map, t - 2)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t + _map->width + 1)) &&
                             (m_isFlat(_map, t + _map->width - 1)) &&
                             (!_map->tile[t + 1].processed) &&
                             (!_map->tile[t - 1].processed))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_3td_entity>", 1 + (rand() % wall_3td_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                            entityManager->updateModelMatrix(tEntity);
                            _map->tile[t].processed = true;
                            _map->tile[t + 1].processed = true;
                            _map->tile[t - 1].processed = true;
                        }
                    }
                    // ? W ?
                    // F W F
                    // F - F
                    // F W F
                    // ? W ?
                    else if ((m_isWall (_map, t + _map->width)) &&
                             (m_isWall (_map, t - _map->width)) &&
                             (m_isWall (_map, t + (2 * _map->width))) &&
                             (m_isWall (_map, t - (2 * _map->width))) &&
                             (m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width + 1)) &&
                             (m_isFlat(_map, t + _map->width - 1)) &&
                             (m_isFlat(_map, t - _map->width + 1)) &&
                             (m_isFlat(_map, t - _map->width - 1)) &&
                             (!_map->tile[t + _map->width].processed) &&
                             (!_map->tile[t - _map->width].processed))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_3td_entity>", 1 + (rand() % wall_3td_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                            entityManager->updateModelMatrix(tEntity);
                            _map->tile[t].processed = true;
                            _map->tile[t + _map->width].processed = true;
                            _map->tile[t - _map->width].processed = true;
                        }
                    }
                }
            }
        }

        // 4. Walls of length 2 ----------------------------------------------------------------------------------
        for (uint32 h = 2; h < _map->height - 2; ++h) // We need up 1 tiles of padding on each side, and 1 for index from 0
        {
            for (uint32 w = 2; w < _map->width - 2; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                {
                    // ? F F ?
                    // W - W W
                    // ? F F ?
                    if      ((wall_2td_count > 0) &&
                             (m_isFlat(_map, t - _map->width)) &&
                             (m_isFlat(_map, t - _map->width + 1)) &&
                             (m_isWall (_map, t + 1)) &&
                             (m_isWall (_map, t - 1)) &&
                             (m_isWall (_map, t + 2)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t + _map->width + 1)) &&
                             (!_map->tile[t + 1].processed))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_2td_entity>", 1 + (rand() % wall_2td_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                            entityManager->updateModelMatrix(tEntity);
                            _map->tile[t].processed = true;
                            _map->tile[t + 1].processed = true;
                        }
                    }
                    // ? W ?
                    // F - F
                    // F W F
                    // ? W ?
                    else if ((wall_2td_count > 0) &&
                             (m_isWall (_map, t + _map->width)) &&
                             (m_isWall (_map, t - _map->width)) &&
                             (m_isWall (_map, t + (2 * _map->width))) &&
                             (m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t + _map->width + 1)) &&
                             (m_isFlat(_map, t - _map->width + 1)) &&
                             (!_map->tile[t + _map->width].processed))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_2td_entity>", 1 + (rand() % wall_2td_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                            entityManager->updateModelMatrix(tEntity);
                            _map->tile[t].processed = true;
                            _map->tile[t + _map->width].processed = true;
                            _map->tile[t - _map->width].processed = true;
                        }
                    }
                }
            }
        }

        // 5. Walls of length 1 --------------------------------------------------------------------------------------------
        for (uint32 h = 1; h < _map->height-1; ++h)
        {
            for (uint32 w = 1; w < _map->width-1; ++w)
            {
                // Calculate the tile number
                uint32 t = (h * _map->width) + w;

                // used to determine if we have loaded a new entity
                bool found = true;

                // Door ways
                if ((m_isDoor (_map, t)) && (!_map->tile[t].processed))
                {
                    // Door - single tile
                    // ? W ?
                    // F D F
                    // ? W ?
                    if      ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isWall (_map, t + _map->width)) &&
                             (m_isWall (_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1ts_entity>", 1 + (rand() % wall_1ts_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }
                    // ? F ?
                    // W D W
                    // ? F ?
                    else if ((m_isWall (_map, t + 1)) &&
                             (m_isWall (_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1ts_entity>", 1 + (rand() % wall_1ts_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }

                    // Door - multiple tiles, ie. Large door
                    // ? D ?
                    // F D F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isWall (_map, t + _map->width)) &&
                             (m_isDoor (_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tl_entity>", 1 + (rand() % wall_1tl_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }
                    // ? W ?
                    // F D F
                    // ? D ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDoor (_map, t + _map->width)) &&
                             (m_isWall (_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tl_entity>", 1 + (rand() % wall_1tl_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                        }
                    }
                    // ? F ?
                    // W D D
                    // ? F ?
                    else if ((m_isDoor (_map, t + 1)) &&
                             (m_isWall (_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tl_entity>", 1 + (rand() % wall_1tl_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                        }
                    }
                    
                    // ? F ?
                    // D D W
                    // ? F ?
                    else if ((m_isWall (_map, t + 1)) &&
                             (m_isDoor (_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tl_entity>", 1 + (rand() % wall_1tl_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }

                    // Door arch top- single tile
                    // ? D ?
                    // F D F
                    // ? D ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDoor (_map, t + _map->width)) &&
                             (m_isDoor (_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1ta_entity>", 1 + (rand() % wall_1ta_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }
                    // ? F ?
                    // D D D
                    // ? F ?
                    else if ((m_isDoor (_map, t + 1)) &&
                             (m_isDoor (_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1ta_entity>", 1 + (rand() % wall_1ta_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }

                    else
                    {
                        found = false;
                    }
                }

                // Walls
                else if ((m_isWall (_map, t)) && (!_map->tile[t].processed))
                {
                    // X Junction
                    // ? W ?
                    // W W W
                    // ? W ?
                         if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tx_entity>", 1 + (rand() % wall_1tx_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                    }
                    // Pillar
                    // ? F ?
                    // F W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tp_entity>", 1 + (rand() % wall_1tp_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                    }

                    // Double sided
                    // ? F ?
                    // W W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1td_entity>", 1 + (rand() % wall_1td_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }
                    // ? W ?
                    // F W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1td_entity>", 1 + (rand() % wall_1td_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }

                    // T junction
                    // ? W ?
                    // W W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }
                    // ? W ?
                    // F W W
                    // ? W ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }
                    // ? F ?
                    // W W W
                    // ? W ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                        }
                    }
                    // ? W ?
                    // W W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tt_entity>", 1 + (rand() % wall_1tt_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                        }
                    }
                    // End
                    // ? W ?
                    // F W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1te_entity>", 1 + (rand() % wall_1te_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }
                    // ? F ?
                    // F W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1te_entity>", 1 + (rand() % wall_1te_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                        }
                    }
                    // ? F ?
                    // F W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1te_entity>", 1 + (rand() % wall_1te_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                        }
                    }
                    // ? F ?
                    // W W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1te_entity>", 1 + (rand() % wall_1te_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }
                    // Corner
                    // ? W ?
                    // F W W
                    // ? F ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_0, 0.0f);
                        }
                    }
                    // ? F ?
                    // F W W
                    // ? W ?
                    else if ((m_isDWall(_map, t + 1)) &&
                             (m_isFlat(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_270, 0.0f);
                        }
                    }
                    // ? F ?
                    // W W F
                    // ? W ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isDWall(_map, t + _map->width)) &&
                             (m_isFlat(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_180, 0.0f);
                        }
                    }
                    // ? W ?
                    // W W F
                    // ? F ?
                    else if ((m_isFlat(_map, t + 1)) &&
                             (m_isDWall(_map, t - 1)) &&
                             (m_isFlat(_map, t + _map->width)) &&
                             (m_isDWall(_map, t - _map->width)))
                    {
                        tEntity = entityManager->load(xmlFile.getString("<wall_1tc_entity>", 1 + (rand() % wall_1tc_count)));
                        tEntity->owner = eEntityOwner::ownerMap;
                        if (tEntity != nullptr)
                        {
                            tEntity->rotation += glm::vec3(0.0f, DTOR_90, 0.0f);
                        }
                    }

                    else
                    {
                        found = false;
                    }
                }

                else
                {
                    found = false;
                }
                // If a pattern was found update the new entity's model matrix
                if (found)
                {
                    if (tEntity != nullptr)
                    {
                        tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                        entityManager->updateModelMatrix(tEntity);
                        _map->tile[t].processed = true;
                    }
                }
            }
        }

        // Clean up
        xmlFile.free();
    }
}
