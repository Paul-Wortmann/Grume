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

#ifndef RE_TEXTURE_ATLAS_HPP
#define RE_TEXTURE_ATLAS_HPP

#include "../core/re_types.hpp"

namespace RoboEngine
{

    // Generate texture atlas vertices
    struct re_sGenTAV
    {
        uint32_t indexCount = 0;
        v2_f* index = nullptr;
    };

    re_sGenTAV* re_genTAV(uint32_t _width, uint32_t _height);
    re_sGenTAV* re_genTAV(uint32_t _size);

}

#endif // RE_TEXTURE_ATLAS_HPP

