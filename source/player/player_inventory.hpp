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

#ifndef PLAYER_INVENTORY_HPP
#define PLAYER_INVENTORY_HPP

#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"

// Player inventory slot struct
struct sPlayerInventorySlot
{
    sEntity*           entity = nullptr;
    std::uint32_t      data   = 0;
};

// Player inventory struct
struct sPlayerInventory
{
    std::uint32_t         width   = 6;
    std::uint32_t         height  = 9;
    std::uint32_t         numSlot = 0;
    sPlayerInventorySlot* slot    = nullptr;
};

class cPlayerInventory
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        void          setInventorySize(const std::uint32_t &_width, const std::uint32_t &_height);
        bool          pickupItem(const sEntity* &_entity);
        bool          dropItem(const sEntity* &_entity);

    protected:
    private:
        // Pointers
        cEntityManager*   m_entityManager   = nullptr;

        // Data
        sPlayerInventory m_inventory        = {};
};

#endif // PLAYER_INVENTORY_HPP