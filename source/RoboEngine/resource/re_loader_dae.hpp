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

#ifndef RE_LOADER_DAE_HPP
#define RE_LOADER_DAE_HPP

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "../core/re_types.hpp"
#include "../core/re_log.hpp"
#include "re_parser_xml.hpp"

namespace RoboEngine
{

    struct re_sdaeData
    {
        std::string name = "";
        uint64_t vertex_count = 0;
        uint64_t vertex_texture_count = 0;
        uint64_t vertex_normal_count = 0;
        uint64_t face_count = 0;
        v3_f* vertex = nullptr;
        v2_f* vertex_texture = nullptr;
        v3_f* vertex_normal = nullptr;
        v8_f* face = nullptr;
    };

    void daeDelete(re_sdaeData *&_daeData);
    void daeImport(const std::string &_daeFile, re_sdaeData *&_daeData);
    void daeExport(const std::string &_daeFile, const re_sdaeData &_daeData);

}

#endif // RE_LOADER_DAE_HPP



