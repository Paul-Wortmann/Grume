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

#ifndef GAME_DATABASE_HPP
#define GAME_DATABASE_HPP

#define DATABASE_FILE "database.txt" // Default database file name.

#include "includes.hpp"
#include "../utils/xml_parser.hpp"

struct sGameDatabaseData
{
    string fileName = "";
};

class cGameDatabase
{
    public:
        void load(const string &_fileName = DATABASE_FILE);

    protected:

    private:
    public:
        sGameDatabaseData biome      = {};
        sGameDatabaseData map        = {};
        sGameDatabaseData map_prefab = {};
        sGameDatabaseData music      = {};
        sGameDatabaseData npc        = {};
        sGameDatabaseData object     = {};
        sGameDatabaseData skills     = {};
        sGameDatabaseData sound      = {};
        sGameDatabaseData ui         = {};
};

#endif // GAME_DATABASE_HPP

