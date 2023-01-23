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

#include "player_action_bar.hpp"

std::uint32_t cPlayerActionBar::initialize(void)
{
    // set action bar to default size 6 x 9
    setActionBarSize(m_actionBar.width, m_actionBar.height);
    m_actionBar.numSlot = m_actionBar.width * m_actionBar.height;

    // Return
    return EXIT_SUCCESS;
}

void cPlayerActionBar::terminate(void)
{
    // free all data
    freeData();
}

void cPlayerActionBar::freeData(void)
{
    // free if it exists
    if (m_actionBar.slot != nullptr)
    {
        delete[] m_actionBar.slot;
        m_actionBar.slot = nullptr;
    }
    m_actionBar.numSlot = 0;
    m_actionBar.numFreeSlot = 0;
}

void cPlayerActionBar::setActionBarSize(const std::uint32_t &_width, const std::uint32_t &_height)
{
    // update action bar size
    m_actionBar.width  = _width;
    m_actionBar.height = _height;

    // free data if necessary
    freeData();

    // allocate new action bar array
    m_actionBar.numSlot = m_actionBar.width * m_actionBar.height;
    m_actionBar.numFreeSlot = m_actionBar.numSlot;
    m_actionBar.slot = new sPlayerActionBarSlot[m_actionBar.numSlot];
}

void cPlayerActionBar::setSlotEntity(const std::uint32_t _slot, sEntity* &_entity)
{
    // Add the entity to the slot
    m_actionBar.slot[_slot].entity = _entity;
    m_actionBar.slot[_slot].occupied = true;
    m_actionBar.numFreeSlot--;

    // Enable the UI ActionBar slot
    m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarSlot_1) + _slot), true);

    // Ensure relevant fields are populated
    // text tooltip
    _entity->base.textActive  = true;
    _entity->base.collectable = true;

    // Stack label
    if (_entity->item->stackSize > 1)
    {
        // Enable the UI ActionBar slot stack text
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarStack_1) + _slot), true);

        // Generate text label
        if (m_actionBar.slot[_slot].stackLabel != nullptr)
        {
            m_resourceManager->freeTexture(m_actionBar.slot[_slot].stackLabel);
        }
        m_actionBar.slot[_slot].stackLabel = m_resourceManager->generateTexture(std::to_string(m_actionBar.slot[_slot].entity->item->stackSize), m_stackTextColor);
    }

    // Add loot component
    if (_entity->loot == nullptr)
    {
        _entity->loot = new sEntityLoot;
    }
};

bool cPlayerActionBar::pickupItem(sEntity* &_entity)
{
    // If possible first add the item to a stack
    if (_entity->item->stackMax > 1)
    {
        for (std::uint32_t i = 0; i < m_actionBar.numSlot; ++i)
        {
            if ((m_actionBar.slot[i].occupied == true) &&
                (m_actionBar.slot[i].entity->item->type == _entity->item->type) &&
                (m_actionBar.slot[i].entity->item->stackMax > 1) &&
                (m_actionBar.slot[i].entity->item->stackSize < m_actionBar.slot[i].entity->item->stackMax))
            {
                m_actionBar.slot[i].entity->item->stackSize++;
                _entity->base.dying = true;
                m_entityManager->deleteEntity(_entity);

                // Enable the UI ActionBar slot stack text
                m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarStack_1) + i), true);

                // Generate text label
                if (m_actionBar.slot[i].stackLabel != nullptr)
                {
                    m_resourceManager->freeTexture(m_actionBar.slot[i].stackLabel);
                }
                m_actionBar.slot[i].stackLabel = m_resourceManager->generateTexture(std::to_string(m_actionBar.slot[i].entity->item->stackSize), m_stackTextColor);

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
    if (m_actionBar.numFreeSlot > 0)
    {
        for (std::uint32_t i = 0; i < m_actionBar.numSlot; ++i)
        {
            // Add the entity to a free slot
            if (m_actionBar.slot[i].occupied == false)
            {
                m_actionBar.slot[i].entity = _entity;
                m_actionBar.slot[i].occupied = true;
                m_actionBar.numFreeSlot--;

                // Enable the UI ActionBar slot
                m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarSlot_1) + i), true);

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

bool cPlayerActionBar::dropItem(sEntity* &_entity)
{
    for (std::uint32_t i = 0; i < m_actionBar.numSlot; ++i)
    {
        // Remove the entity from it's occupied slot
        if ((m_actionBar.slot[i].occupied == true) && (m_actionBar.slot[i].entity == _entity))
        {
            dropItem(i);
            return true;
        }
    }
    return false;
}

void cPlayerActionBar::dropItem(const std::uint32_t &_slot)
{
    // Get the entity pointer first
    sEntity* entity = m_actionBar.slot[_slot].entity;

    bool duplicated = false;

    // If stacked item, duplicate if > 1
    if (entity->item->stackSize > 1)
    {
        // No need to remove later from the action bar if a duplicate
        duplicated = true;

        // backup original entity, reduce stack count
        sEntity* originalEntity = entity;
        originalEntity->item->stackSize--;

        // Set the UI ActionBar slot stack text
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarStack_1) + _slot), (originalEntity->item->stackSize > 1));

        // generate text label
        if (m_actionBar.slot[_slot].stackLabel != nullptr)
        {
            m_resourceManager->freeTexture(m_actionBar.slot[_slot].stackLabel);
        }
        m_actionBar.slot[_slot].stackLabel = m_resourceManager->generateTexture(std::to_string(originalEntity->item->stackSize), m_stackTextColor);

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
        m_actionBar.slot[_slot].entity = nullptr;
        m_actionBar.slot[_slot].occupied = false;
        m_actionBar.numFreeSlot++;

        // Disable the UI ActionBar slot
        m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionActionBarSlot_1) + _slot), false);
    }
}
