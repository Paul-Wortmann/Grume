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

void cMapManager::m_generateMap_npcs(sMap*& _map)
{
    // Get biome npcs from database
    
    for (std::uint32_t h = 1; h < _map->height-1; ++h)
    {
        for (std::uint32_t w = 1; w < _map->width-1; ++w)
        {
            std::uint32_t t = (h * _map->width) + w;
            if ((_map->tile[t].object == 0) && (_map->tile[t].base == eTileBase::tileFloor))
            {
                // WARNING!!!! This should be based on the biome npcs
                /*
                if ((rand() % 200) == 0)
                {
                    _map->tile[t].npc = 0;
                }
                else if ((rand() % 1000) == 0)
                {
                    _map->tile[t].npc = 0;
                }
                */
            }
        }
    }

}
