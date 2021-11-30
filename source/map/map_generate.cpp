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

void cMapManager::generateMap(sMap*& _map)
{
    // Generate based on algorithm
    switch (_map->genData.algorithm)
    {
        case eAlgorithm::algorithm_T1: // Town 1
            m_generateMap_T1(_map);
        break;
        case eAlgorithm::algorithm_M1: // Maze 1
            m_generateMap_M1(_map);
        break;
        case eAlgorithm::algorithm_D2: // Dungeon 2
            m_generateMap_D2(_map);
        break;
        case eAlgorithm::algorithm_D1: // Dungeon 1
            m_generateMap_D1(_map);
        break;
        case eAlgorithm::algorithm_C2: // Cave 2
            m_generateMap_C2(_map);
        break;
        case eAlgorithm::algorithm_C1: // Cave 1
        default:
            m_generateMap_C1(_map);
        break;
    }
}

