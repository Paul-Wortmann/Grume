/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libRMG"
 *
 * "libRMG" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libRMG" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libRMG" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#include "libRMG_generator_C2.hpp"

static void _libRMG_generator_C2_internal(sLibRMGMapData &_data)
{
    uint32_t blobCount = _data.density * _data.maxItterations;
    for (uint32_t i = 0; i < _data.tile_count; i++)
        _data.tile[i].base = eBase::baseWall;
    _libRMG_utils_map_perimeter_walls(_data);
    for (uint32_t i = 0; i < blobCount; i++)
    {
        uint32_t r = (rand() % (_data.room_radius_max - _data.room_radius_min)) + _data.room_radius_min;

        uint32_t x = (rand() % (_data.tile_x - r - r)) + r;
        uint32_t y = (rand() % (_data.tile_y - r - r)) + r;

        _libRMG_room_genCircleRoom(_data, x, y, r);
    }

}


void _libRMG_generator_C2(sLibRMGMapData &_data)
{
    // make sure the map has been initialized
    // this also guarantees a new random seed is necessary
    _libRMG_utils_map_initialize(_data);
    if (!_data.genSeed)
    {
        _libRMG_generator_C2_internal(_data);
    }
    else
    {
        for (uint16_t i = 0; i < _data.maxItterations; i++)
        {
            _data.seed = time(NULL);
            srand (_data.seed);
            _libRMG_generator_C2_internal(_data);
            _libRMG_room_initRooms(_data);
            _libRMG_room_discardAllButLargest(_data);
            _libRMG_utils_map_remove_anomalies(_data);

            if (_libRMG_utils_map_get_floor_area(_data) > (_data.tile_count * (_data.floor_area_min / 100.0f)))
            {
                i = _data.maxItterations;
            }
        }
    }
    _libRMG_room_initRooms(_data);
    _libRMG_room_discardAllButLargest(_data);
    _libRMG_utils_map_remove_anomalies(_data);
}
