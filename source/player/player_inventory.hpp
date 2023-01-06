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
#include "../ui/ui_manager.hpp"

// Player inventory slot struct
struct sPlayerInventorySlot
{
    bool               occupied = false;
    sEntity*           entity   = nullptr;
    std::uint32_t      data     = 0;
};

// Player inventory struct
struct sPlayerInventory
{
    std::uint32_t         width       = 6;
    std::uint32_t         height      = 9;
    std::uint32_t         numSlot     = 0;
    std::uint32_t         numFreeSlot = 0;
    sPlayerInventorySlot* slot        = nullptr;
};

class cPlayerInventory
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        void          freeData(void);

        // Set pointers
        void          setUIManager(cUIManager* _UIManager) { m_UIManager = _UIManager; };
        void          setPlayerEntity(sEntity* _entity) { m_playerEntity = _entity; }

        sEntity*      getEntity(const std::uint32_t _slot) { return m_inventory.slot[_slot].entity; };
        void          setInventorySize(const std::uint32_t &_width, const std::uint32_t &_height);
        std::uint32_t freeSlotCount(void) { return m_inventory.numFreeSlot; };
        bool          pickupItem(sEntity* &_entity);
        bool          dropItem(sEntity* &_entity);
        void          dropItem(const std::uint32_t &_slot);

    protected:
    private:
        // Pointers
        sEntity*          m_playerEntity    = nullptr;
        cEntityManager*   m_entityManager   = nullptr;
        cUIManager*       m_UIManager       = nullptr;

        // Data
        sPlayerInventory m_inventory        = {};
};

#endif // PLAYER_INVENTORY_HPP
