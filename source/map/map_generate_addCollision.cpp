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

void cMapManager::m_addCollisionData(sMap*& _map, sEntity*& _entity, const std::uint32_t &_tile, const float32 &_rotation)
{
    if (_entity->collision != nullptr)
    {
        std::uint32_t r = _entity->collision->radius / 2; // radius
        std::uint32_t o = (_entity->collision->radius * r) + r; // offset
        for (std::uint32_t h = 0; h < _entity->collision->radius; ++h)
        {
            for (std::uint32_t w = 0; w < _entity->collision->radius; ++w)
            {
                std::uint32_t tileNum = (h * _entity->collision->radius) + w;
                _map->tile[_tile - o + tileNum].object = _entity->UID;
            }
        }
    }
    else
    {
        _map->tile[_tile].object = _entity->UID;
    }
}
