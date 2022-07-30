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

#ifndef DATABASE_DEFINE_HPP
#define DATABASE_DEFINE_HPP

// Includes
#include "../core/includes.hpp"

enum eDatabaseType : std::uint32_t {databaseTypeNone      = 0,
                                    databaseTypeBiome     = 1,
                                    databaseTypeItem      = 2,
                                    databaseTypeMap       = 3,
                                    databaseTypeMapPrefab = 4,
                                    databaseTypeMusic     = 5,
                                    databaseTypeNpc       = 6,
                                    databaseTypeObject    = 7,
                                    databaseTypeParticle  = 8,
                                    databaseTypeSound     = 9};

struct sDatabaseEntry
{
    std::string   category = {};
    std::string   fileName = {};
};

struct sDatabase
{
    std::string     fileName     = {};
    sDatabaseEntry* entry        = nullptr;
    std::uint32_t   numEntry     = 0;
};

struct sPrefabData
{
    std::string     fileName     = {};
    std::uint32_t   roomType     = 0;
    std::uint32_t   roomSize_x   = 0;
    std::uint32_t   roomSize_y   = 0;
};

#endif // DATABASE_DEFINE_HPP
