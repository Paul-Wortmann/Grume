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

#include "re_texture_atlas.hpp"

namespace RoboEngine
{

    re_sGenTAV* re_genTAV(uint32_t _width, uint32_t _height)
    {
        if (_width == 0 || _height == 0)
            return nullptr;
        re_sGenTAV *tempTAV = new re_sGenTAV;
        tempTAV->indexCount = _width * _height * 6;
        tempTAV->index = new v2_f[tempTAV->indexCount];
        uint32_t tavIndex = 0;
        float _spacingW = 1.0f / _width;
        float _spacingH = 1.0f / _height;
        for (uint32_t i = 0; i < _height; i++)
        {
            for (uint32_t j = 0; j < _width; j++)
            {
                tempTAV->index[(i * _height) + j + tavIndex + 0].x = (j * _spacingW);
                tempTAV->index[(i * _height) + j + tavIndex + 0].y = (i * _spacingH) + _spacingH;
                tempTAV->index[(i * _height) + j + tavIndex + 1].x = (j * _spacingW) + _spacingW;
                tempTAV->index[(i * _height) + j + tavIndex + 1].y = (i * _spacingH);
                tempTAV->index[(i * _height) + j + tavIndex + 2].x = (j * _spacingW);
                tempTAV->index[(i * _height) + j + tavIndex + 2].y = (i * _spacingH);

                tempTAV->index[(i * _height) + j + tavIndex + 3].x = (j * _spacingW);
                tempTAV->index[(i * _height) + j + tavIndex + 3].y = (i * _spacingH) + _spacingH;
                tempTAV->index[(i * _height) + j + tavIndex + 4].x = (j * _spacingW) + _spacingW;
                tempTAV->index[(i * _height) + j + tavIndex + 4].y = (i * _spacingH) + _spacingH;
                tempTAV->index[(i * _height) + j + tavIndex + 5].x = (j * _spacingW) + _spacingW;
                tempTAV->index[(i * _height) + j + tavIndex + 5].y = (i * _spacingH);
            }
            tavIndex += 6;
        }
        return tempTAV;
    }

}
