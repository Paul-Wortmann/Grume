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

void cMapManager::m_addCollisionData(sMap*& _map, sEntity*& _entity, const std::uint32_t &_tile, const float32 &_rotation)
{
    if ((_entity->collision != nullptr) && (_entity->collision->data != nullptr))
    {
        /*
        std::cout << "Adding collision for: " << _entity->name << std::endl;
        for (std::uint32_t h = 0; h < _entity->collision->size; ++h)
            for (std::uint32_t w = 0; w < _entity->collision->size; ++w)
                std::cout << (_entity->collision->data[(h * _entity->collision->size) + w]) << " ";
        std::cout << std::endl;
        std::cout << "Rotation: " << _rotation << std::endl;
        */
        
        // Rotation
        if (_rotation > 4.0f)      // 4.71239 == 270
        {
            m_mapTilesRotate270(_entity->collision->data, _entity->collision->size, _entity->collision->size);
        }
        else if (_rotation > 3.0f) // 3.14159 == 180
        {
            m_mapTilesRotate180(_entity->collision->data, _entity->collision->size, _entity->collision->size);
        }
        else if (_rotation > 1.0f) // 1.5708  == 90
        {
            m_mapTilesRotate90(_entity->collision->data, _entity->collision->size, _entity->collision->size);
        }
        
        // Calculate radius
        std::uint32_t r = _entity->collision->size / 2;
        
        // Transfer tile collision data to the map
        for (std::uint32_t h = 0; h < _entity->collision->size; ++h)
        {
            for (std::uint32_t w = 0; w < _entity->collision->size; ++w)
            {
                if (_entity->collision->data[(h * _entity->collision->size) + w] > 0)
                {
                    std::uint32_t tileNum = _tile + ((h - r) * _map->width) + (w - r);
                    _map->tile[tileNum].object = _entity->UID;

                    if (_map->tile[tileNum].base == eTileBase::tileFloor)
                    {
                        _map->tile[tileNum].base = eTileBase::tileFloorNoGo;
                    }
                    else if (_map->tile[tileNum].base == eTileBase::tileFloorPath)
                    {
                        _map->tile[tileNum].base = eTileBase::tilePathNoGo;
                    }
                    else if (_map->tile[tileNum].base == eTileBase::tileNone)
                    {
                        // Do not change, this tile is alread inaccessible
                    }
                    else
                    {
                        _map->tile[tileNum].base = eTileBase::tileFloorNoGo;
                    }
                }
            }
        }
        /*
        for (std::uint32_t h = 0; h < _entity->collision->size; ++h)
            for (std::uint32_t w = 0; w < _entity->collision->size; ++w)
                std::cout << (_tile + ((h - r) * _map->width) + (w - r)) << " ";
        std::cout << std::endl;
        for (std::uint32_t h = 0; h < _entity->collision->size; ++h)
            for (std::uint32_t w = 0; w < _entity->collision->size; ++w)
                std::cout << (_entity->collision->data[(h * _entity->collision->size) + w]) << " ";
        std::cout << std::endl;
        std::cout << "Tile: " << _tile << std::endl;
        */
    }
    else
    {
        // Add default tile object data to the map
        //_map->tile[_tile].base   = eTileBase::tileFloorNoGo;
        _map->tile[_tile].object = _entity->UID;
    }
}