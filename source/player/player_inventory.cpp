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
    // free all data
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

        bool stacked = false;

        // If stackable item
        if (_entity->item->stackMax > 1)
        {
            for (std::uint32_t i = 0; i < m_inventory.numSlot; ++i)
            {
                if ((m_inventory.slot[i].occupied == true) &&
                    (m_inventory.slot[i].entity->item->type == _entity->item->type) &&
                    (m_inventory.slot[i].entity->item->stackMax > 1) &&
                    (m_inventory.slot[i].entity->item->stackSize < m_inventory.slot[i].entity->item->stackMax))
                {
                    m_inventory.slot[i].entity->item->stackSize++;
                    _entity->base.dying = true;
                    m_entityManager->deleteEntity(_entity);

                    return true;
                }
            }
        }

        if (stacked == false)
        {
            for (std::uint32_t i = 0; i < m_inventory.numSlot; ++i)
            {
                // Add the entity to a free slot
                if (m_inventory.slot[i].occupied == false)
                {
                    m_inventory.slot[i].entity = _entity;
                    m_inventory.slot[i].occupied = true;
                    m_inventory.numFreeSlot--;

                    // Enable the UI Inventory slot
                    m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionInventorySlot_1) + i), true);

                    return true;
                }
            }
        }
    }

    return false;
}

bool cPlayerInventory::dropItem(sEntity* &_entity)
{
    for (std::uint32_t i = 0; i < m_inventory.numSlot; ++i)
    {
        // Remove the entity from it's occupied slot
        if ((m_inventory.slot[i].occupied == true) && (m_inventory.slot[i].entity == _entity))
        {
            dropItem(i);
            return true;
        }
    }
    return false;
}

void cPlayerInventory::dropItem(const std::uint32_t &_slot)
{
    // Get the entity pointer first
    sEntity* entity = m_inventory.slot[_slot].entity;

    bool duplicated = false;

    // If stacked item, duplicate if > 1
    if (entity->item->stackSize > 1)
    {
        // No need to remove later from the inventory if a duplicate
        duplicated = true;

        // backup original entity, reduce stack count
        sEntity* originalEntity = entity;
        originalEntity->item->stackSize--;

        // Duplicate entity and set stack size
        entity = m_entityManager->duplicateEntity(originalEntity);
        entity->item->stackSize = 1;
        entity->base.position.y = originalEntity->base.position.y;

        // text tooltip
        entity->base.textActive  = true;
        entity->base.collectable = true;

        // Add loot component
        if (entity->loot == nullptr)
        {
            entity->loot = new sEntityLoot;
        }
    }

    // Set the entity visible and change ownership
    entity->base.visible = true;
    entity->base.inRnge = true;
    entity->base.owner = eEntityOwner::entityOwner_map;

    // Position
    std::uint32_t tile = gMapPositionToTile(m_map, m_playerEntity->base.position);
    //tile = gClosestFreeTile(m_map, tile); // Closest free tile tends to throw the item too far....
    glm::vec3 position = gMapTileToPosition(m_map, tile);
    float positionOffset = 1.0f - (gRandFloatNormalized() * 2.0f);
    entity->base.position.x = position.x + positionOffset;
    positionOffset = 1.0f - (gRandFloatNormalized() * 2.0f);
    entity->base.position.z = position.z + positionOffset;

    // rotation
    float rotation = gRandFloatNormalized() * static_cast<float>(M_PI) * 2.0f;
    entity->base.rotation.x = rotation * entity->base.rotationAxis.x;
    entity->base.rotation.y = rotation * entity->base.rotationAxis.y;
    entity->base.rotation.z = rotation * entity->base.rotationAxis.z;

    // Update the model matrix
    m_entityManager->updateModelMatrix(entity);

    // Set entity state
    m_entityManager->stateSet(entity, eEntityState::entityState_interact);

    // Last in the stack remove
    if (duplicated == false)
    {
        // Remove the entity from it's occupied slot
        m_inventory.slot[_slot].entity = nullptr;
        m_inventory.slot[_slot].occupied = false;
        m_inventory.numFreeSlot++;

        // Disable the UI Inventory slot
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionInventorySlot_1) + _slot), false);
    }
}
