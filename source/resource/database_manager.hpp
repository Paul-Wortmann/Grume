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

#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

// Includes
#include "../core/includes.hpp"
#include "database_define.hpp"

class cDatabaseManager
{
    public:
        std::uint32_t initialize(void);
        std::uint32_t load(const std::string &_fileName);
        void          terminate(void);
        std::string   getDatabaseEntryFileName(const std::string &_catagory, const std::uint32_t &_number, const eDatabaseType &_type);
        std::uint32_t getDatabaseEntryCount(const std::string &_catagory, const eDatabaseType &_type);
        sPrefabData*  getPrefabDataPointer(void) { return m_prefabData; };
        std::uint32_t getNumPrefabData(void) { return m_numPrefabData; };

    protected:
    private:
        std::uint32_t m_load(const std::string &_fileName);
        std::uint32_t m_buildPrefabDatabase(void);

        // Resource databases
        sDatabase m_biome_database      = {};
        sDatabase m_item_database       = {};
        sDatabase m_map_database        = {};
        sDatabase m_map_prefab_database = {};
        sDatabase m_music_database      = {};
        sDatabase m_npc_database        = {};
        sDatabase m_object_database     = {};
        sDatabase m_particle_database   = {};
        sDatabase m_sound_database      = {};

        // Prefab data
        sPrefabData*  m_prefabData    = nullptr;
        std::uint32_t m_numPrefabData = 0;
};

#endif // DATABASE_MANAGER_HPP

