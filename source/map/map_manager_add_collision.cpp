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

void cMapManager::m_addCollisionData(sMap*& _map, sEntity*& _entity, const float &_rotation)
{
    if ((_entity->tileCollision != nullptr) && (_entity->tileCollision->data != nullptr))
    {
        // Rotation
        if (_rotation > 4.0f)      // 4.71239 == 270
        {
            m_mapTilesRotate270(_entity->tileCollision->data, _entity->tileCollision->size, _entity->tileCollision->size);
        }
        else if (_rotation > 3.0f) // 3.14159 == 180
        {
            m_mapTilesRotate180(_entity->tileCollision->data, _entity->tileCollision->size, _entity->tileCollision->size);
        }
        else if (_rotation > 1.0f) // 1.5708  == 90
        {
            m_mapTilesRotate90(_entity->tileCollision->data, _entity->tileCollision->size, _entity->tileCollision->size);
        }

        // Calculate half width and half height
        std::uint32_t r = _entity->tileCollision->size / 2;

        // Transfer tile collision data to the map
        for (std::uint32_t h = 0; h < _entity->tileCollision->size; ++h)
        {
            for (std::uint32_t w = 0; w < _entity->tileCollision->size; ++w)
            {
                if (_entity->tileCollision->data[(h * _entity->tileCollision->size) + w] > 0)
                {
                    std::uint32_t tileNum = _entity->base.tileOnMap + ((h - r) * _map->info.size_x) + (w - r);

                    // Add default tile object data to the map
                    if (_map->tile[tileNum].type == eTileType::tileFloor)
                        _map->tile[tileNum].type = eTileType::tileFloorNoGo;
                    else if (_map->tile[tileNum].type == eTileType::tilePath)
                        _map->tile[tileNum].type = eTileType::tilePathNoGo;
                    else if (_map->tile[tileNum].type == eTileType::tileDoorway)
                        _map->tile[tileNum].type = eTileType::tileDoorwayNoGo;
                }
            }
        }
    }
    else
    {
        if (_entity->base.type != eEntityType::entityType_none)
        {
            // Add default tile object data to the map
            if (_map->tile[_entity->base.tileOnMap].type == eTileType::tileFloor)
                _map->tile[_entity->base.tileOnMap].type = eTileType::tileFloorNoGo;
            else if (_map->tile[_entity->base.tileOnMap].type == eTileType::tilePath)
                _map->tile[_entity->base.tileOnMap].type = eTileType::tilePathNoGo;
            else if (_map->tile[_entity->base.tileOnMap].type == eTileType::tileDoorway)
                _map->tile[_entity->base.tileOnMap].type = eTileType::tileDoorwayNoGo;
        }
    }
}
