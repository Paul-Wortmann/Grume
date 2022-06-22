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

#ifndef MAP_DEFINE_NPC_HPP
#define MAP_DEFINE_NPC_HPP

struct sMapNPC
{
    std::uint32_t  tile                = 0;
    std::string    name                = {};
    std::uint32_t  index               = 0;
    float          scale               = 0.0f;
    float          yRot                = 0.0f;
};

#endif // MAP_DEFINE_NPC_HPP
