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

#include "player_inventory.hpp"

std::uint32_t cPlayerInventory::initialize(void)
{
    // set inventory to default size 6 x 9
    setInventorySize(m_inventory.width, m_inventory.height);

    // Return
    return EXIT_SUCCESS;
}

void cPlayerInventory::terminate(void)
{
    // free if
    freeData();
}

void cPlayerInventory::freeData(void)
{
    // free if it exists
    if (m_inventory.slot != nullptr)
    {
        delete[] m_inventory.slot;
        m_inventory.slot = nullptr;
    }
    m_inventory.numSlot = 0;
    m_inventory.numFreeSlot = 0;
}

void cPlayerInventory::setInventorySize(const std::uint32_t &_width, const std::uint32_t &_height)
{
    // update inventory size
    m_inventory.width  = _width;
    m_inventory.height = _height;

    // free data if necessary
    freeData();

    // allocate new inventory array
    m_inventory.numSlot = m_inventory.width * m_inventory.height;
    m_inventory.numFreeSlot = m_inventory.numSlot;
    m_inventory.slot = new sPlayerInventorySlot[m_inventory.numSlot];
}

bool cPlayerInventory::pickupItem(sEntity* &_entity)
{
    if (m_inventory.numFreeSlot > 0)
    {
        // Set the entity invisible and change ownership
        _entity->base.visible = false;
        _entity->base.inRnge = false;
        _entity->base.owner = eEntityOwner::entityOwner_inventory;

        for (std::uint32_t i = 0; i < m_inventory.numSlot; ++i)
        {
            // Add the entity to a free slot
            if (m_inventory.slot[i].occupied == false)
            {
                m_inventory.slot[i].entity = _entity;
                m_inventory.slot[i].occupied = true;
                m_inventory.numFreeSlot--;
                return true;
            }
        }
    }

    return false;
}

bool cPlayerInventory::dropItem(sEntity* &_entity)
{
    // Set the entity visible and change ownership
    _entity->base.visible = true;
    _entity->base.inRnge = true;
    _entity->base.owner = eEntityOwner::entityOwner_map;

    for (std::uint32_t i = 0; i < m_inventory.numSlot; ++i)
    {
        // Remove the entity from it's occupied slot
        if ((m_inventory.slot[i].occupied == true) && (m_inventory.slot[i].entity == _entity))
        {
            m_inventory.slot[i].entity = nullptr;
            m_inventory.slot[i].occupied = false;
            m_inventory.numFreeSlot++;
            return true;
        }
    }
    return false;
}
