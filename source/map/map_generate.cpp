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

void cMapManager::generateMap(sMap*& _map)
{
    // Seed
    (_map->genData.seed == 0) ? srand(time(nullptr)) : srand(_map->genData.seed);

    // Generate based on algorithm
    switch (_map->genData.algorithm)
    {
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
