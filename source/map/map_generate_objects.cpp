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

void cMapManager::m_generateMap_objects(sMap*& _map)
{
    for (uint32 h = 1; h < _map->height-1; ++h)
    {
        for (uint32 w = 1; w < _map->width-1; ++w)
        {
            uint32 t = (h * _map->width) + w;
            if ((_map->tile[t].object == 0) && (_map->tile[t].base == eTileBase::tileFloor))
            {
                // WARNING!!!! This should be based on the biome objects
                /*
                if ((rand() % 200) == 0)
                {
                    _map->tile[t].object = 0;
                }
                else if ((rand() % 1000) == 0)
                {
                    _map->tile[t].object = 0;
                }
                */
            }
        }
    }

}
