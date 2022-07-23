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

#ifndef LOOT_MANAGER_HPP
#define LOOT_MANAGER_HPP

#include "../core/includes.hpp"
#include "loot_define.hpp"

class cLootManager
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        void          process(const float &_dt);
        std::uint32_t loadLootTable(const std::string &_fileName);
        void          getLoot(std::uint32_t &_itemID, std::string &_databaseName, std::uint32_t &_databaseNumber);

    protected:

    private:
        sLootTable    m_lootTable    = {};
};

#endif //LOOT_MANAGER_HPP
