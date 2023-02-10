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

#include "player_storage.hpp"

std::uint32_t cPlayerStorage::initialize(void)
{
    // set storage to default size 6 x 9
    setStorageSize(m_storage.numSlot);

    // Return
    return EXIT_SUCCESS;
}

void cPlayerStorage::terminate(void)
{
    // free all data
    freeData();
}

void cPlayerStorage::freeData(void)
{
    // free if it exists
    if (m_storage.slot != nullptr)
    {
        delete[] m_storage.slot;
        m_storage.slot = nullptr;
    }
    m_storage.numSlot = 0;
    m_storage.numFreeSlot = 0;
}

void cPlayerStorage::setStorageSize(const std::uint32_t &_size)
{
    // No size change, early exit
    if (_size == m_storage.numSlot)
        return;

    // free data if necessary
    freeData();

    // allocate new storage array
    m_storage.numSlot = _size;
    m_storage.numFreeSlot = m_storage.numSlot;
    m_storage.slot = new sPlayerStorageSlot[m_storage.numSlot];
}

void cPlayerStorage::setSlotEntity(const std::uint32_t _slot, sEntity* &_entity)
{
    // Add the entity to the slot
    m_storage.slot[_slot].entity = _entity;
    m_storage.slot[_slot].occupied = true;
    m_storage.slot[_slot].dragged = false;
    m_storage.numFreeSlot--;

    // Enable the UI Storage slot
    m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_slot_1) + _slot), true);

    // Ensure relevant fields are populated
    // text tooltip
    _entity->base.textActive  = true;
    _entity->base.collectable = true;

    // Stack label
    if (_entity->item->stackSize > 1)
    {
        // Enable the UI Storage slot stack text
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_stack_1) + _slot), true);

        // Generate text label
        if (m_storage.slot[_slot].stackLabel != nullptr)
        {
            m_resourceManager->freeTexture(m_storage.slot[_slot].stackLabel);
        }
        m_storage.slot[_slot].stackLabel = m_resourceManager->generateTexture(std::to_string(m_storage.slot[_slot].entity->item->stackSize), m_stackTextColor);
    }

    // Add loot component
    if (_entity->loot == nullptr)
    {
        _entity->loot = new sEntityLoot;
    }
}

void cPlayerStorage::setUISlotEnabled(const std::uint32_t &_slot, const bool &_state)
{
    // set slot
    m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_slot_1) + _slot), _state);

    // set stack
    if ((_state == true) && (m_storage.slot[_slot].entity != nullptr) && (m_storage.slot[_slot].entity->item->stackSize > 1))
    {
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_stack_1) + _slot), true);
    }
    else
    {
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_stack_1) + _slot), false);
    }
}

void cPlayerStorage::purgeSlotEntity(const std::uint32_t _slot)
{
    // slot empty, early exit
    if (m_storage.slot[_slot].occupied != true)
        return;

    // set slot fields
    m_storage.slot[_slot].occupied = false;
    m_storage.slot[_slot].dragged = false;
    m_resourceManager->freeTexture(m_storage.slot[_slot].stackLabel);

    // Free the entity
    if (m_storage.slot[_slot].entity != nullptr)
    {
        m_entityManager->deleteEntity(m_storage.slot[_slot].entity);
    }
}

bool cPlayerStorage::pickupItem(sEntity* &_entity)
{
    // If possible first add the item to a stack
    if (_entity->item->stackMax > 1)
    {
        for (std::uint32_t i = 0; i < m_storage.numSlot; ++i)
        {
            if ((m_storage.slot[i].occupied == true) &&
                (m_storage.slot[i].entity->item->type == _entity->item->type) &&
                (m_storage.slot[i].entity->item->stackMax > 1) &&
                (m_storage.slot[i].entity->item->stackSize < m_storage.slot[i].entity->item->stackMax))
            {
                m_storage.slot[i].entity->item->stackSize++;
                _entity->base.dying = true;
                m_entityManager->deleteEntity(_entity);

                // Enable the UI Storage slot stack text
                m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_stack_1) + i), true);

                // Generate text label
                if (m_storage.slot[i].stackLabel != nullptr)
                {
                    m_resourceManager->freeTexture(m_storage.slot[i].stackLabel);
                }
                m_storage.slot[i].stackLabel = m_resourceManager->generateTexture(std::to_string(m_storage.slot[i].entity->item->stackSize), m_stackTextColor);

                // Set the entity invisible and change ownership
                _entity->base.visible = false;
                _entity->base.inRnge = false;
                _entity->base.owner = eEntityOwner::entityOwner_inventory;

                // return if we stacked the item
                return true;
            }
        }
    }

    // If there is a free slot, add the item
    if (m_storage.numFreeSlot > 0)
    {
        for (std::uint32_t i = 0; i < m_storage.numSlot; ++i)
        {
            // Add the entity to a free slot
            if (m_storage.slot[i].occupied == false)
            {
                m_storage.slot[i].entity = _entity;
                m_storage.slot[i].occupied = true;
                m_storage.slot[i].dragged = false;
                m_storage.numFreeSlot--;

                // Enable the UI Storage slot
                m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_slot_1) + i), true);

                // Set the entity invisible and change ownership
                _entity->base.visible = false;
                _entity->base.inRnge = false;
                _entity->base.owner = eEntityOwner::entityOwner_inventory;

                // Return if we added the item
                return true;
            }
        }
    }

    // unable to stack or add the item
    return false;
}

bool cPlayerStorage::dropItem(sEntity* &_entity)
{
    for (std::uint32_t i = 0; i < m_storage.numSlot; ++i)
    {
        // Remove the entity from it's occupied slot
        if ((m_storage.slot[i].occupied == true) && (m_storage.slot[i].entity == _entity))
        {
            dropItem(i);
            return true;
        }
    }
    return false;
}

void cPlayerStorage::dropItem(const std::uint32_t &_slot)
{
    // Get the entity pointer first
    sEntity* entity = m_storage.slot[_slot].entity;

    bool duplicated = false;

    // If stacked item, duplicate if > 1
    if (entity->item->stackSize > 1)
    {
        // No need to remove later from the storage if a duplicate
        duplicated = true;

        // backup original entity, reduce stack count
        sEntity* originalEntity = entity;
        originalEntity->item->stackSize--;

        // Set the UI Storage slot stack text
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_stack_1) + _slot), (originalEntity->item->stackSize > 1));

        // generate text label
        if (m_storage.slot[_slot].stackLabel != nullptr)
        {
            m_resourceManager->freeTexture(m_storage.slot[_slot].stackLabel);
        }
        m_storage.slot[_slot].stackLabel = m_resourceManager->generateTexture(std::to_string(originalEntity->item->stackSize), m_stackTextColor);

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
        m_storage.slot[_slot].entity = nullptr;
        m_storage.slot[_slot].occupied = false;
        m_storage.slot[_slot].dragged = false;
        m_storage.numFreeSlot++;

        // Disable the UI Storage slot
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(m_slot_1) + _slot), false);
    }
}

sPlayerStorageSlot* cPlayerStorage::getStorageSlot(const ePlayerStorageSlotType _type)
{
    return nullptr;
}
