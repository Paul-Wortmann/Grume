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

#include "player_manager.hpp"

std::uint32_t cPlayerManager::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    // action bar storage
    return_value = m_playerActionBar->initialize();
    m_playerActionBar->setStorageType(ePlayerStorageType::playerStorageTypeActionBar);
    m_playerActionBar->setStorageSize(12);
    m_playerActionBar->setStackColor(m_stackTextColor);
    m_playerActionBar->setSlot1(eComponentFunction::componentFunctionActionBarSlot_1);
    m_playerActionBar->setStack1(eComponentFunction::componentFunctionActionBarStack_1);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypePotion, 0);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypePotion, 1);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 2);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 3);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 4);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 5);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 6);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 7);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 8);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill, 9);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill,10);
    m_playerActionBar->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeSkill,11);

    // equipment storage
    return_value = m_playerEquipment->initialize();
    m_playerEquipment->setStorageType(ePlayerStorageType::playerStorageTypeEquipment);
    m_playerEquipment->setStorageSize(14);
    m_playerEquipment->setStackColor(m_stackTextColor);
    m_playerEquipment->setSlot1(eComponentFunction::componentFunctionEquipmentSlot_1);
    m_playerEquipment->setStack1(eComponentFunction::componentFunctionEquipmentStack_1);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeHelm, 0);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeWeapon, 1);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeArmor, 2);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeShield, 3);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeGloves, 4);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeBelt, 5);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeBoots, 6);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeAmulet, 7);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeAmulet, 8);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRing, 9);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRing,10);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRing,11);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRing,12);
    m_playerEquipment->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRing,13);

    // inventory storage
    return_value = m_playerInventory->initialize();
    m_playerInventory->setStorageType(ePlayerStorageType::playerStorageTypeInventory);
    m_playerInventory->setStorageSize(54);
    m_playerInventory->setStackColor(m_stackTextColor);
    m_playerInventory->setSlot1(eComponentFunction::componentFunctionInventorySlot_1);
    m_playerInventory->setStack1(eComponentFunction::componentFunctionInventoryStack_1);

    // vendor storage
    return_value = m_playerVendor->initialize();
    m_playerVendor->setStorageType(ePlayerStorageType::playerStorageTypeVendor);
    m_playerVendor->setStorageSize(54);
    m_playerVendor->setStackColor(m_stackTextColor);
    m_playerVendor->setSlot1(eComponentFunction::componentFunctionVendorSlot_1);
    m_playerVendor->setStack1(eComponentFunction::componentFunctionVendorStack_1);

    // waypoint
    return_value = m_playerWaypoints->initialize();
    m_playerWaypoints->setStorageType(ePlayerStorageType::playerStorageTypeWaypoints);
    m_playerWaypoints->setStorageSize(6);
    m_playerWaypoints->setStackColor(m_stackTextColor);
    m_playerWaypoints->setSlot1(eComponentFunction::componentFunctionWaypointsSlot_1);
    m_playerWaypoints->setStack1(eComponentFunction::componentFunctionWaypointsStack_1);
    m_playerWaypoints->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRune_1, 0);
    m_playerWaypoints->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRune_2, 1);
    m_playerWaypoints->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRune_3, 2);
    m_playerWaypoints->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRune_4, 3);
    m_playerWaypoints->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRune_5, 4);
    m_playerWaypoints->setSlotType(ePlayerStorageSlotType::playerStorageSlotTypeRune_6, 5);

    return return_value;
}

void cPlayerManager::terminate(void)
{
    // Player action bar storage
    m_playerActionBar->terminate();
    delete m_playerActionBar;
    m_playerActionBar = nullptr;

    // Player character storage
    m_playerEquipment->terminate();
    delete m_playerEquipment;
    m_playerEquipment = nullptr;

    // Player inventory storage
    m_playerInventory->terminate();
    delete m_playerInventory;
    m_playerInventory = nullptr;

    // Player vendor storage
    m_playerVendor->terminate();
    delete m_playerVendor;
    m_playerVendor = nullptr;

    // Player waypoint storage
    m_playerWaypoints->terminate();
    delete m_playerWaypoints;
    m_playerWaypoints = nullptr;
}

void cPlayerManager::setAudioEngine(cAudioEngine* _audioEngine)
{
    m_audioEngine = _audioEngine;
}

void cPlayerManager::setDatabaseManager(cDatabaseManager *_databaseManager)
{
    m_databaseManager = _databaseManager;
}

void cPlayerManager::setEntityManager(cEntityManager *_entityManager)
{
    m_entityManager = _entityManager;
    m_playerActionBar->setEntityManager(_entityManager);
    m_playerEquipment->setEntityManager(_entityManager);
    m_playerInventory->setEntityManager(_entityManager);
    m_playerVendor->setEntityManager(_entityManager);
    m_playerWaypoints->setEntityManager(_entityManager);
}

void cPlayerManager::setUIManager(cUIManager* _UIManager)
{
    m_UIManager = _UIManager;
    m_playerActionBar->setUIManager(_UIManager);
    m_playerEquipment->setUIManager(_UIManager);
    m_playerInventory->setUIManager(_UIManager);
    m_playerVendor->setUIManager(_UIManager);
    m_playerWaypoints->setUIManager(_UIManager);
}

void cPlayerManager::setMapPointer(sMap* _map)
{
    m_mapPointer = _map;
    m_playerActionBar->setMap(_map);
    m_playerEquipment->setMap(_map);
    m_playerInventory->setMap(_map);
    m_playerVendor->setMap(_map);
    m_playerWaypoints->setMap(_map);
}

void cPlayerManager::setResourceManagerPointer(cResourceManager* _resourceManager)
{
    m_resourceManager = _resourceManager;
    m_playerActionBar->setResourceManager(_resourceManager);
    m_playerEquipment->setResourceManager(_resourceManager);
    m_playerInventory->setResourceManager(_resourceManager);
    m_playerVendor->setResourceManager(_resourceManager);
    m_playerWaypoints->setResourceManager(_resourceManager);
}

void cPlayerManager::swapStorage(cPlayerStorage *&_sourceStorage, const std::uint32_t &_slot1, cPlayerStorage *&_destinationStorage, const std::uint32_t &_slot2)
{
    // pointers to the slots
    sPlayerStorageSlot* source = _sourceStorage->getStorageSlot(_slot1);
    sPlayerStorageSlot* destination = _destinationStorage->getStorageSlot(_slot2);

    // Stack-able items
    if ((source->occupied) &&
        (destination->occupied) &&
        (source->entity->item->type == destination->entity->item->type) &&
        (source->entity->item->stackMax > 1) &&
        (destination->entity->item->stackMax > 1))
    {
        // stack items
        destination->entity->item->stackSize += source->entity->item->stackSize;
        if (destination->entity->item->stackSize > destination->entity->item->stackMax)
        {
            source->entity->item->stackSize = (destination->entity->item->stackSize - destination->entity->item->stackMax);
            destination->entity->item->stackSize = destination->entity->item->stackMax;

            // Update stack label
            _sourceStorage->updateStackLabel(_slot1);
        }
        // source stack depleted, delete
        else
        {
            _sourceStorage->setUISlotEnabled(_slot1, false);
            _sourceStorage->purgeSlotEntity(_slot1);
            _sourceStorage->updateFreeSlotCount();
        }

        // Update stack label
        _destinationStorage->updateStackLabel(_slot2);
    }

    // Non stacked items
    else
    {
        // temp storage
        sPlayerStorageSlot tSlot = {};

        // Backup
        tSlot.data = source->data;
        tSlot.dragged = source->dragged;
        tSlot.entity = source->entity;
        tSlot.occupied = source->occupied;
        tSlot.stackLabel = source->stackLabel;

        // To source
        source->data = destination->data;
        source->dragged = destination->dragged;
        source->entity = destination->entity;
        source->occupied = destination->occupied;
        source->stackLabel = destination->stackLabel;

        // To destination
        destination->data = tSlot.data;
        destination->dragged = tSlot.dragged;
        destination->entity = tSlot.entity;
        destination->occupied = tSlot.occupied;
        destination->stackLabel = tSlot.stackLabel;

        // UI set slot state
        _sourceStorage->setUISlotEnabled(_slot1, source->occupied);
        _destinationStorage->setUISlotEnabled(_slot2, destination->occupied);

        // Update storage item counts
        updateFreeSlotCount();

        tSlot.entity = nullptr;
    }

    // Update player attributes if equipment
    if ((_sourceStorage->getStorageType() == ePlayerStorageType::playerStorageTypeEquipment) ||
        (_destinationStorage->getStorageType() == ePlayerStorageType::playerStorageTypeEquipment))
    {
        calculateAttributes();
    }
}

void cPlayerManager::unequip(const std::uint32_t &_slot)
{
    // move to inventory
    if (m_playerInventory->getFreeSlotCount() > 0)
    {
        std::uint32_t freeSlot = m_playerInventory->getFreeSlot();
        swapStorage(m_playerEquipment, _slot, m_playerInventory, freeSlot);
    }
    // drop on ground
    else
    {
        m_playerEquipment->dropItem(_slot);
    }

    // Update plater attributes
    calculateAttributes();
}

void cPlayerManager::equip(sEntity* &_entity)
{

}

void cPlayerManager::equipInventorySlot(const std::uint32_t &_slot)
{

}

void cPlayerManager::sellInventorySlot(const std::uint32_t &_slot)
{
    // Get a pointer to the inventory item
    sEntity* sourceEntity = getInventoryEntity(_slot);

    // Pointer to the vendor item
    sEntity* destinationEntity = nullptr;

    // Item added to the vendor
    bool itemAdded = false;

    // Gold value
    std::uint32_t goldValue = 0;

    // If stackable
    if (sourceEntity->item->stackMax > 1)
    {
        // Find the first stack that we can add to, if there are any
        for (std::uint32_t i = 0; i < m_playerVendor->getStorageSize(); ++i)
        {
            destinationEntity = getVendorEntity(i);
            if ((itemAdded == false) &&
                (destinationEntity != nullptr) &&
                (destinationEntity->item->type == sourceEntity->item->type) &&
                ((destinationEntity->item->stackSize + sourceEntity->item->stackSize - 1) < destinationEntity->item->stackMax))
            {
                // Modify quantities
                destinationEntity->item->stackSize++;
                sourceEntity->item->stackSize--;

                // Update stack label
                m_playerInventory->updateStackLabel(i);
                m_playerVendor->updateStackLabel(_slot);

                // Determine gold value
                goldValue = sourceEntity->item->goldValue * sourceEntity->item->stackSize;

                // Update itemAdded flag, set i to a loop exit value
                itemAdded = true;
                i = m_playerVendor->getStorageSize();
            }
        }
    }

    // Else non-stackable
    else
    {
        // If there is a free slot
        if (m_playerVendor->getFreeSlotCount() > 0)
        {
            // Add to vendor storage
            std::uint32_t slotNum = m_playerVendor->getFreeSlot();
            sPlayerStorageSlot* slot = m_playerVendor->getStorageSlot(slotNum);
            slot->entity = sourceEntity;
            slot->occupied = true;
            slot->dragged = false;
            m_playerVendor->setFreeSlotCount(m_playerVendor->getFreeSlotCount() - 1);

            // Determine gold value
            goldValue = sourceEntity->item->goldValue;

            // Enable the UI Storage slot
            m_UIManager->setMenuComponentEnabled(static_cast<eComponentFunction>(static_cast<std::uint32_t>(eComponentFunction::componentFunctionVendorSlot_1) + slotNum), true);
            itemAdded = true;
        }
    }

    // if item added remove from the inventory if the stack size is 0 or non-stackable
    if (itemAdded)
    {
        if ((sourceEntity->item->stackMax == 1) ||
            (sourceEntity->item->stackSize == 0))
        {
            // Update player gold
            m_player->character->gold += goldValue;
            m_UIManager->setTextGold(m_player->character->gold);

            // Remove item from inventory
            m_playerInventory->purgeSlotEntity(_slot);
        }

        // Update free slot counts
        m_playerInventory->updateFreeSlotCount();
        m_playerVendor->updateFreeSlotCount();
    }
}

void cPlayerManager::buyVendorSlot(const std::uint32_t &_slot)
{
    // Get a pointer to the vendor item
    sEntity* sourceEntity = getVendorEntity(_slot);

    // If the player doesn't have enough coin, early exit
    if (m_player->character->gold < sourceEntity->item->goldValue)
        return;

    // Pointer to the inventory item
    sEntity* destinationEntity = nullptr;

    // Item added to the inventory
    bool itemAdded = false;

    // Gold value
    std::uint32_t goldValue = 0;

    // If stackable
    if (sourceEntity->item->stackMax > 1)
    {
        // Find the first stack that we can add to, if there are any
        for (std::uint32_t i = 0; i < m_playerInventory->getStorageSize(); ++i)
        {
            //std::cout << "Count: " << i << ((m_playerInventory->isOccupied(i)) ? "occupied" : "not occupied") << std::endl;
            destinationEntity = (m_playerInventory->isOccupied(i)) ? getInventoryEntity(i) : nullptr;
            if ((itemAdded == false) &&
                (destinationEntity != nullptr) &&
                (destinationEntity->item->type == sourceEntity->item->type) &&
                (destinationEntity->item->stackSize < destinationEntity->item->stackMax))
            {
                // Modify quantities
                destinationEntity->item->stackSize++;
                sourceEntity->item->stackSize--;

                // Update stack label
                m_playerInventory->updateStackLabel(i);
                m_playerVendor->updateStackLabel(_slot);

                // Determine gold value
                goldValue = sourceEntity->item->goldValue;// * sourceEntity->item->stackSize;

                // Update itemAdded flag, set i to a loop exit value
                itemAdded = true;
                i = m_playerInventory->getStorageSize();
            }
        }

        // If no available stack found, and a free slot is available
        if ((!itemAdded) && (m_playerInventory->getFreeSlotCount() > 0))
        {
            // Duplicate source entity
            destinationEntity = m_entityManager->duplicateEntity(sourceEntity);

            // Modify quantities
            destinationEntity->item->stackSize = 1;
            sourceEntity->item->stackSize--;

            // Add to inventory slot
            std::uint32_t slotNum = m_playerInventory->getFreeSlot();
            sPlayerStorageSlot* slot = m_playerInventory->getStorageSlot(slotNum);
            slot->entity = destinationEntity;
            slot->occupied = true;
            slot->dragged = false;
            m_playerInventory->setFreeSlotCount(m_playerInventory->getFreeSlotCount() - 1);

            // Determine gold value
            goldValue = destinationEntity->item->goldValue;

            // Enable the Imventory Storage slot
            m_playerInventory->setUISlotEnabled(slotNum, true);

            // Update stack label
            m_playerInventory->updateStackLabel(slotNum);
            m_playerVendor->updateStackLabel(_slot);

            // Determine gold value
            goldValue = sourceEntity->item->goldValue;

            // Update itemAdded flag, set i to a loop exit value
            itemAdded = true;
        }
    }

    // Else non-stackable
    else
    {
        // If there is a free slot
        if (m_playerInventory->getFreeSlotCount() > 0)
        {
            // Add to inventory slot
            std::uint32_t slotNum = m_playerInventory->getFreeSlot();
            sPlayerStorageSlot* slot = m_playerInventory->getStorageSlot(slotNum);
            slot->entity = sourceEntity;
            slot->occupied = true;
            slot->dragged = false;
            m_playerInventory->setFreeSlotCount(m_playerInventory->getFreeSlotCount() - 1);

            // Determine gold value
            goldValue = sourceEntity->item->goldValue;

            // Enable the UI Storage slot
            m_playerInventory->setUISlotEnabled(slotNum, true);
            itemAdded = true;
        }
    }

    // if item added remove from the vendor if the stack size is 0 or non-stackable
    if (itemAdded)
    {
        // Update player gold
        m_player->character->gold -= goldValue;
        m_UIManager->setTextGold(m_player->character->gold);

        if ((sourceEntity->item->stackMax == 1) ||
            (sourceEntity->item->stackSize == 0))
        {
            m_playerVendor->purgeSlotEntity(_slot);
        }

        // Update free slot counts
        m_playerInventory->updateFreeSlotCount();
        m_playerVendor->updateFreeSlotCount();
    }
}

void cPlayerManager::moveStorage(const ePlayerStorageType &_type1, const std::uint32_t &_slot1, const ePlayerStorageType &_type2, const std::uint32_t &_slot2)
{
    cPlayerStorage* sourceStorage = nullptr;
    cPlayerStorage* destinationStorage = nullptr;

    // Source
    if (_type1 == ePlayerStorageType::playerStorageTypeActionBar)
    {
        sourceStorage = m_playerActionBar;
        actionBarSetDrag(_slot1, false);
    }
    else if (_type1 == ePlayerStorageType::playerStorageTypeEquipment)
    {
        sourceStorage = m_playerEquipment;
        equipmentSetDrag(_slot1, false);
    }
    else if (_type1 == ePlayerStorageType::playerStorageTypeInventory)
    {
        sourceStorage = m_playerInventory;
        inventorySetDrag(_slot1, false);
    }
    else if (_type1 == ePlayerStorageType::playerStorageTypeVendor)
    {
        sourceStorage = m_playerVendor;
        vendorSetDrag(_slot1, false);
    }
    else if (_type1 == ePlayerStorageType::playerStorageTypeWaypoints)
    {
        sourceStorage = m_playerWaypoints;
        waypointsSetDrag(_slot1, false);
    }

    // Destination
    if (_type2 == ePlayerStorageType::playerStorageTypeActionBar)
    {
        destinationStorage = m_playerActionBar;
        actionBarSetDrag(_slot2, false);
    }
    else if (_type2 == ePlayerStorageType::playerStorageTypeEquipment)
    {
        destinationStorage = m_playerEquipment;
        equipmentSetDrag(_slot2, false);
    }
    else if (_type2 == ePlayerStorageType::playerStorageTypeInventory)
    {
        destinationStorage = m_playerInventory;
        inventorySetDrag(_slot2, false);
    }
    else if (_type2 == ePlayerStorageType::playerStorageTypeVendor)
    {
        destinationStorage = m_playerVendor;
        vendorSetDrag(_slot2, false);
    }
    else if (_type2 == ePlayerStorageType::playerStorageTypeWaypoints)
    {
        destinationStorage = m_playerWaypoints;
        waypointsSetDrag(_slot2, false);
    }

    // Action-bar to vendor -> sell item
    if ((_type1 == ePlayerStorageType::playerStorageTypeActionBar) &&
        (_type2 == ePlayerStorageType::playerStorageTypeVendor))
    {
        // Get slot storage
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);

        // pure sell
        if ((source->type == ePlayerStorageSlotType::playerStorageSlotTypePotion) &&
            (!destination->occupied))
        {
            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * source->entity->item->stackSize;

            m_player->character->gold += sellValue;
            m_UIManager->setTextGold(m_player->character->gold);
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }

        // sell identical, stack-able items
        else if ((source->type == ePlayerStorageSlotType::playerStorageSlotTypePotion) &&
                 (destination->occupied) &&
                 (source->entity->item->type == destination->entity->item->type))
        {
            // Determine sell quantity
            std::uint32_t sellNum = source->entity->item->stackSize;
            if ((destination->entity->item->stackSize + sellNum) > destination->entity->item->stackMax)
            {
                sellNum = destination->entity->item->stackMax - destination->entity->item->stackSize;
            }

            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * sellNum;
            m_player->character->gold += sellValue;
            m_UIManager->setTextGold(m_player->character->gold);

            // Swap -> merge stack
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }

        // buy and sell dissimilar items
        else if (((source->entity->item->type == eEntityItemType::entityItemType_potionHP) ||
                  (source->entity->item->type == eEntityItemType::entityItemType_potionMP)) &&
                 ((destination->entity->item->type == eEntityItemType::entityItemType_potionHP) ||
                  (destination->entity->item->type == eEntityItemType::entityItemType_potionMP)))
        {
            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * source->entity->item->stackSize;
            std::uint32_t buyValue = destination->entity->item->goldValue * destination->entity->item->stackSize;

            // If player has enough coin, proceed
            if (buyValue <= (m_player->character->gold + sellValue))
            {
                m_player->character->gold -= buyValue;
                m_player->character->gold += sellValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }
    }

    // Vendor to Action-bar -> buy item
    else if ((_type1 == ePlayerStorageType::playerStorageTypeVendor) &&
             (_type2 == ePlayerStorageType::playerStorageTypeActionBar))
    {
        // Get slot storage
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);

        // pure buy
        if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypePotion) &&
            (!destination->occupied))
        {
            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * source->entity->item->stackSize;

            // If player has enough coin, proceed
            if (m_player->character->gold >= buyValue)
            {
                m_player->character->gold -= buyValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }

        // buy identical, stack-able items
        else if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypePotion) &&
                 (destination->occupied) &&
                 (source->entity->item->type == destination->entity->item->type))
        {
            // Determine buy quantity
            std::uint32_t buyNum = source->entity->item->stackSize;
            if ((destination->entity->item->stackSize + buyNum) > destination->entity->item->stackMax)
            {
                buyNum = destination->entity->item->stackMax - destination->entity->item->stackSize;
            }

            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * buyNum;

            // If player has enough coin, proceed
            if (m_player->character->gold >= buyValue)
            {
                m_player->character->gold -= buyValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }

        // sell dissimilar items
        else if (((source->entity->item->type == eEntityItemType::entityItemType_potionHP) ||
                  (source->entity->item->type == eEntityItemType::entityItemType_potionMP)) &&
                 ((destination->entity->item->type == eEntityItemType::entityItemType_potionHP) ||
                  (destination->entity->item->type == eEntityItemType::entityItemType_potionMP)))
        {
            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * source->entity->item->stackSize;
            std::uint32_t sellValue = destination->entity->item->goldValue * destination->entity->item->stackSize;

            // If player has enough coin, proceed
            if (buyValue <= (m_player->character->gold + sellValue))
            {
                m_player->character->gold -= buyValue;
                m_player->character->gold += sellValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }
    }

    // Inventory to Action-bar
    else if ((_type1 == ePlayerStorageType::playerStorageTypeInventory) &&
             (_type2 == ePlayerStorageType::playerStorageTypeActionBar))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypePotion) &&
            ((source->entity->item->type == eEntityItemType::entityItemType_potionHP) ||
             (source->entity->item->type == eEntityItemType::entityItemType_potionMP)))

        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Action-bar to Inventory
    else if ((_type1 == ePlayerStorageType::playerStorageTypeActionBar) &&
             (_type2 == ePlayerStorageType::playerStorageTypeInventory))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        if ((source->type == ePlayerStorageSlotType::playerStorageSlotTypePotion) &&
            ((!destination->occupied) ||
            ((destination->occupied) &&
             ((destination->entity->item->type == eEntityItemType::entityItemType_potionHP) ||
              (destination->entity->item->type == eEntityItemType::entityItemType_potionMP)))))
        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Action-bar to Action-bar
    else if ((_type1 == ePlayerStorageType::playerStorageTypeActionBar) &&
             (_type2 == ePlayerStorageType::playerStorageTypeActionBar))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        if ((source->type == destination->type) &&
            (_slot1 != _slot2))
        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Inventory to Inventory
    else if ((_type1 == ePlayerStorageType::playerStorageTypeInventory) &&
             (_type2 == ePlayerStorageType::playerStorageTypeInventory))
    {
        if (_slot1 != _slot2)
        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Inventory to vendor -> sell item
    else if ((_type1 == ePlayerStorageType::playerStorageTypeInventory) &&
             (_type2 == ePlayerStorageType::playerStorageTypeVendor))
    {
        // Get slot storage
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);

        // pure sell
        if (!destination->occupied)
        {
            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * source->entity->item->stackSize;

            m_player->character->gold += sellValue;
            m_UIManager->setTextGold(m_player->character->gold);
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }

        // sell identical, stack-able items
        else if ((source->entity->item->type == destination->entity->item->type) &&
                 (source->entity->item->stackMax > 1) &&
                 (destination->entity->item->stackMax > 1))
        {
            // Determine sell quantity
            std::uint32_t sellNum = source->entity->item->stackSize;
            if ((destination->entity->item->stackSize + sellNum) > destination->entity->item->stackMax)
            {
                sellNum = destination->entity->item->stackMax - destination->entity->item->stackSize;
            }

            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * sellNum;
            m_player->character->gold += sellValue;
            m_UIManager->setTextGold(m_player->character->gold);

            // Swap -> merge stack
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }

        // buy and sell dissimilar items, and non stacked items
        else
        {
            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * source->entity->item->stackSize;
            std::uint32_t buyValue = destination->entity->item->goldValue * destination->entity->item->stackSize;

            // If player has enough coin, proceed
            if (buyValue <= (m_player->character->gold + sellValue))
            {
                m_player->character->gold -= buyValue;
                m_player->character->gold += sellValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }
    }

    // Vendor to Inventory -> buy item
    else if ((_type1 == ePlayerStorageType::playerStorageTypeVendor) &&
             (_type2 == ePlayerStorageType::playerStorageTypeInventory))
    {
        // Get slot storage
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);

        // pure buy
        if (!destination->occupied)
        {
            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * source->entity->item->stackSize;

            // If player has enough coin, proceed
            if (m_player->character->gold >= buyValue)
            {
                m_player->character->gold -= buyValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }

        // buy identical, stack-able items
        else if ((source->entity->item->type == destination->entity->item->type) &&
                 (source->entity->item->stackMax > 1) &&
                 (destination->entity->item->stackMax > 1))
        {
            // Determine buy quantity
            std::uint32_t buyNum = source->entity->item->stackSize;
            if ((destination->entity->item->stackSize + buyNum) > destination->entity->item->stackMax)
            {
                buyNum = destination->entity->item->stackMax - destination->entity->item->stackSize;
            }

            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * buyNum;

            // If player has enough coin, proceed
            if (m_player->character->gold >= buyValue)
            {
                m_player->character->gold -= buyValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }

        // sell dissimilar items, and non stacked items
        else
        {
            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * source->entity->item->stackSize;
            std::uint32_t sellValue = destination->entity->item->goldValue * destination->entity->item->stackSize;

            // If player has enough coin, proceed
            if (buyValue <= (m_player->character->gold + sellValue))
            {
                m_player->character->gold -= buyValue;
                m_player->character->gold += sellValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }
    }

    // Inventory to waypoints
    else if ((_type1 == ePlayerStorageType::playerStorageTypeInventory) &&
             (_type2 == ePlayerStorageType::playerStorageTypeWaypoints))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        if (!destination->occupied)
        {
            if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRune_1) && (source->entity->item->type == eEntityItemType::entityItemType_rune_1))
            {
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
                m_UIManager->setMenuComponentEnabled(eComponentFunction::componentFunctionLoadMapTown_1, true);
            }
            else if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRune_2) && (source->entity->item->type == eEntityItemType::entityItemType_rune_2))
            {
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
                m_UIManager->setMenuComponentEnabled(eComponentFunction::componentFunctionLoadMapTown_2, true);
            }
            else if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRune_3) && (source->entity->item->type == eEntityItemType::entityItemType_rune_3))
            {
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
                m_UIManager->setMenuComponentEnabled(eComponentFunction::componentFunctionLoadMapTown_3, true);
            }
            else if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRune_4) && (source->entity->item->type == eEntityItemType::entityItemType_rune_4))
            {
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
                m_UIManager->setMenuComponentEnabled(eComponentFunction::componentFunctionLoadMapTown_4, true);
            }
            else if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRune_5) && (source->entity->item->type == eEntityItemType::entityItemType_rune_5))
            {
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
                m_UIManager->setMenuComponentEnabled(eComponentFunction::componentFunctionLoadMapTown_5, true);
            }
            else if ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRune_6) && (source->entity->item->type == eEntityItemType::entityItemType_rune_6))
            {
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
                m_UIManager->setMenuComponentEnabled(eComponentFunction::componentFunctionLoadMapTown_6, true);
            }
         }
    }

    // Equipment to Equipment
    else if ((_type1 == ePlayerStorageType::playerStorageTypeEquipment) &&
             (_type2 == ePlayerStorageType::playerStorageTypeEquipment))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        if ((source->type == destination->type) &&
            (_slot1 != _slot2))
        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Equipment to Inventory
    else if ((_type1 == ePlayerStorageType::playerStorageTypeEquipment) &&
             (_type2 == ePlayerStorageType::playerStorageTypeInventory))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        if ((!destination->occupied) ||
            ((destination->occupied) &&
            ((source->entity->item->type == destination->entity->item->type))))
        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Inventory to Equipment
    else if ((_type1 == ePlayerStorageType::playerStorageTypeInventory) &&
             (_type2 == ePlayerStorageType::playerStorageTypeEquipment))
    {
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
        sPlayerStorageSlot* weaponSlot = destinationStorage->getStorageSlot(ePlayerStorageSlotType::playerStorageSlotTypeWeapon);
        sPlayerStorageSlot* shieldSlot = destinationStorage->getStorageSlot(ePlayerStorageSlotType::playerStorageSlotTypeShield);
        const std::uint32_t weaponSlotNumber = destinationStorage->getStorageSlotNumber(ePlayerStorageSlotType::playerStorageSlotTypeWeapon);
        const std::uint32_t shiledSlotNumber = destinationStorage->getStorageSlotNumber(ePlayerStorageSlotType::playerStorageSlotTypeShield);

        // Non weapon or shield slot
        if (((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeAmulet) && (source->entity->item->type == eEntityItemType::entityItemType_amulet)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeArmor) && (source->entity->item->type == eEntityItemType::entityItemType_armor)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeBelt) && (source->entity->item->type == eEntityItemType::entityItemType_belt)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeBoots) && (source->entity->item->type == eEntityItemType::entityItemType_boots)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeGloves) && (source->entity->item->type == eEntityItemType::entityItemType_gloves)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeHelm) && (source->entity->item->type == eEntityItemType::entityItemType_helmet)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRing) && (source->entity->item->type == eEntityItemType::entityItemType_ring)))
        {
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
        // one handed shield slot
        else if (((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeShield) && (source->entity->item->type == eEntityItemType::entityItemType_shield)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeShield) && (source->entity->item->type == eEntityItemType::entityItemType_grimoire)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeShield) && (source->entity->item->type == eEntityItemType::entityItemType_quiver)))
        {
            // shield
            if ((weaponSlot->occupied == true) &&
                (source->entity->item->type == eEntityItemType::entityItemType_shield) &&
               ((weaponSlot->entity->item->type == eEntityItemType::entityItemType_bow) ||
                (weaponSlot->entity->item->type == eEntityItemType::entityItemType_crossbow) ||
                (weaponSlot->entity->item->type == eEntityItemType::entityItemType_staff) ||
                (weaponSlot->entity->item->type == eEntityItemType::entityItemType_wand) ||
                (weaponSlot->entity->item->type == eEntityItemType::entityItemType_axe_two) ||
                (weaponSlot->entity->item->type == eEntityItemType::entityItemType_mace_two) ||
                (weaponSlot->entity->item->type == eEntityItemType::entityItemType_sword_two)))
            {
                unequip(weaponSlotNumber);
            }

            // grimoire
            else if (((weaponSlot->occupied == true) &&
                      (source->entity->item->type == eEntityItemType::entityItemType_grimoire) &&
                     ((weaponSlot->entity->item->type == eEntityItemType::entityItemType_bow) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_crossbow) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_staff) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_axe_one) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_mace_one) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_sword_one) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_axe_two) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_mace_two) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_sword_two))))
            {
                unequip(weaponSlotNumber);
            }

            // quiver
            else if (((weaponSlot->occupied == true) &&
                      (source->entity->item->type == eEntityItemType::entityItemType_quiver) &&
                     ((weaponSlot->entity->item->type == eEntityItemType::entityItemType_wand) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_staff) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_axe_one) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_mace_one) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_sword_one) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_axe_two) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_mace_two) ||
                      (weaponSlot->entity->item->type == eEntityItemType::entityItemType_sword_two))))
            {
                unequip(weaponSlotNumber);
            }

            // Swap
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
        // one handed weapon slot
        else if (((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_axe_one)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_bow)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_crossbow)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_dagger)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_mace_one)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_sword_one)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_wand)))
        {
            // bow / crossbow
            if ((shieldSlot->occupied == true) &&
                ((source->entity->item->type == eEntityItemType::entityItemType_bow) ||
                 (source->entity->item->type == eEntityItemType::entityItemType_crossbow)) &&
                (shieldSlot->entity->item->type != eEntityItemType::entityItemType_quiver))
            {
                unequip(shiledSlotNumber);
            }

            // wand
            else if ((shieldSlot->occupied == true) &&
                     ((source->entity->item->type == eEntityItemType::entityItemType_wand) ||
                      (source->entity->item->type == eEntityItemType::entityItemType_crossbow)) &&
                     (shieldSlot->entity->item->type != eEntityItemType::entityItemType_grimoire))
            {
                unequip(shiledSlotNumber);
            }

            // one handed melee
            else if ((shieldSlot->occupied == true) &&
                     ((source->entity->item->type == eEntityItemType::entityItemType_axe_one) ||
                      (source->entity->item->type == eEntityItemType::entityItemType_dagger) ||
                      (source->entity->item->type == eEntityItemType::entityItemType_mace_one) ||
                      (source->entity->item->type == eEntityItemType::entityItemType_sword_one)) &&
                     (shieldSlot->entity->item->type != eEntityItemType::entityItemType_shield))
            {
                unequip(shiledSlotNumber);
            }

            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
        // two handed weapon slot
        else if (((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_axe_two)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_mace_two)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_staff)) ||
                 ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeWeapon) && (source->entity->item->type == eEntityItemType::entityItemType_sword_two)))
        {
            // If shield slot occupied, unequip
            if (shieldSlot->occupied == true)
            {
                unequip(shiledSlotNumber);
            }

            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }
    }

    // Equipment to vendor -> sell item
    else if ((_type1 == ePlayerStorageType::playerStorageTypeEquipment) &&
             (_type2 == ePlayerStorageType::playerStorageTypeVendor))
    {
        // Get slot storage
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);

        // pure sell
        if (!destination->occupied)
        {
            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * source->entity->item->stackSize;

            m_player->character->gold += sellValue;
            m_UIManager->setTextGold(m_player->character->gold);
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }

        // sell identical items
        else if ((source->entity->item->type == destination->entity->item->type) &&
                 (source->entity->item->stackMax > 1) &&
                 (destination->entity->item->stackMax > 1))
        {
            // Determine sell quantity
            std::uint32_t sellNum = source->entity->item->stackSize;
            if ((destination->entity->item->stackSize + sellNum) > destination->entity->item->stackMax)
            {
                sellNum = destination->entity->item->stackMax - destination->entity->item->stackSize;
            }

            // Determine item value
            std::uint32_t sellValue = source->entity->item->goldValue * sellNum;
            m_player->character->gold += sellValue;
            m_UIManager->setTextGold(m_player->character->gold);

            // Swap -> merge stack
            swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
        }

    }

    // Vendor to Equipment -> buy item
    else if ((_type1 == ePlayerStorageType::playerStorageTypeVendor) &&
             (_type2 == ePlayerStorageType::playerStorageTypeEquipment))
    {
        // Get slot storage
        sPlayerStorageSlot* source = sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = destinationStorage->getStorageSlot(_slot2);
/*
        // Only proceed if there is a slot and item type match
        if (((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeAmulet) && (source->entity->item->type == eEntityItemType::entityItemType_amulet)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeArmor) && (source->entity->item->type == eEntityItemType::entityItemType_armor)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeBelt) && (source->entity->item->type == eEntityItemType::entityItemType_belt)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeBoots) && (source->entity->item->type == eEntityItemType::entityItemType_boots)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeGloves) && (source->entity->item->type == eEntityItemType::entityItemType_gloves)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeHelm) && (source->entity->item->type == eEntityItemType::entityItemType_helmet)) ||
            ((destination->type == ePlayerStorageSlotType::playerStorageSlotTypeRing) && (source->entity->item->type == eEntityItemType::entityItemType_ring)))
        {
*/
        // pure buy
        if (!destination->occupied)
        {
            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * source->entity->item->stackSize;

            // If player has enough coin, proceed
            if (m_player->character->gold >= buyValue)
            {
                m_player->character->gold -= buyValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }

        // buy identical, stack-able items
        else if ((source->entity->item->type == destination->entity->item->type) &&
                 (source->entity->item->stackMax > 1) &&
                 (destination->entity->item->stackMax > 1))
        {
            // Determine buy quantity
            std::uint32_t buyNum = source->entity->item->stackSize;
            if ((destination->entity->item->stackSize + buyNum) > destination->entity->item->stackMax)
            {
                buyNum = destination->entity->item->stackMax - destination->entity->item->stackSize;
            }

            // Determine item value
            std::uint32_t buyValue = source->entity->item->goldValue * buyNum;

            // If player has enough coin, proceed
            if (m_player->character->gold >= buyValue)
            {
                m_player->character->gold -= buyValue;
                m_UIManager->setTextGold(m_player->character->gold);
                swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
            }
        }

    }

}

void cPlayerManager::clearStorage(void)
{
    m_playerActionBar->clearStorage();
    m_playerEquipment->clearStorage();
    m_playerInventory->clearStorage();
    m_playerVendor->clearStorage();
    m_playerWaypoints->clearStorage();
}

void cPlayerManager::updateFreeSlotCount(void)
{
    m_playerActionBar->updateFreeSlotCount();
    m_playerEquipment->updateFreeSlotCount();
    m_playerInventory->updateFreeSlotCount();
    m_playerVendor->updateFreeSlotCount();
    m_playerWaypoints->updateFreeSlotCount();
}

std::uint32_t cPlayerManager::load(const std::string &_fileName)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    if (m_player != nullptr)
    {
        // already loaded
        return return_value;
    }
    m_player = m_entityManager->load(_fileName);
    if (m_player != nullptr)
    {
        if (m_player->movement == nullptr)
        {
            m_player->movement = new sEntityMovement;
        }
        m_player->base.position.y += m_mapPointer->info.terrainHeight;
        m_player->base.type  = eEntityType::entityType_player;
        m_player->base.owner = eEntityOwner::entityOwner_player;
        m_entityManager->updateModelMatrix(m_player);
        m_playerActionBar->setPlayerEntity(m_player);
        m_playerEquipment->setPlayerEntity(m_player);
        m_playerInventory->setPlayerEntity(m_player);
        m_playerVendor->setPlayerEntity(m_player);
        m_playerWaypoints->setPlayerEntity(m_player);
    }
    else
    {
        return_value = EXIT_FAILURE;
        gLogWrite(LOG_ERROR, "Error - Failed to load player entity: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    return return_value;
}

void cPlayerManager::setPlayerPosition(const std::uint32_t &_tile, const float &_rotation)
{
    // process input data
    std::uint32_t tile = _tile;
    glm::vec3 position = gMapTileToPosition(m_mapPointer, _tile);

    // Update map information
    m_player->base.tileOnMap = tile;
    m_mapPointer->tile[tile].entity.UID  = m_player->UID;
    m_mapPointer->tile[tile].entity.type = eTileEntityType::tileEntityPlayer;

    // Update player base
    m_player->base.rotation.y = _rotation;
    m_player->base.position.x = position.x;
    m_player->base.position.z = position.z;

    // Update player movement
    m_player->movement->pathing = false;
    m_player->movement->mapPath.currentTile     = tile;
    m_player->movement->mapPath.startTile       = tile;
    m_player->movement->mapPath.destinationTile = tile;
    m_player->movement->mapPath.currentPosition = 0;
    m_player->movement->mapPath.pathLength      = 0;

    // Update player matrix
    m_entityManager->updateModelMatrix(m_player);

    // Push event
    sPlayerEvent* event = new sPlayerEvent;
    event->type = ePlayerEventType::playerEventType_newPosition; // Player has been repositioned
    event->data = 1; // True
    m_event.push(event);
};

void cPlayerManager::setPlayerPosition(const glm::vec3 &_position, const float &_rotation)
{
    // process input data
    std::uint32_t tile = gMapPositionToTile(m_mapPointer, _position);
    glm::vec3 position = _position;

    // Update map information
    m_player->base.tileOnMap = tile;
    m_mapPointer->tile[tile].entity.UID  = m_player->UID;
    m_mapPointer->tile[tile].entity.type = eTileEntityType::tileEntityPlayer;

    // Update player base
    m_player->base.rotation.y = _rotation;
    m_player->base.position.x = position.x;
    m_player->base.position.z = position.z;

    // Update player movement
    m_player->movement->pathing = false;
    m_player->movement->mapPath.currentTile     = tile;
    m_player->movement->mapPath.startTile       = tile;
    m_player->movement->mapPath.destinationTile = tile;
    m_player->movement->mapPath.currentPosition = 0;
    m_player->movement->mapPath.pathLength      = 0;

    // Update player matrix
    m_entityManager->updateModelMatrix(m_player);

    // Push event
    sPlayerEvent* event = new sPlayerEvent;
    event->type = ePlayerEventType::playerEventType_newPosition; // Player has been repositioned
    event->data = 1; // True
    m_event.push(event);
}

// need to implement this, generate event for graphics engine to reposition camera. Call this on map / player load

void cPlayerManager::setMapPlayer(void)
{
    if (m_mapPointer != nullptr)
    {
        // set the map tile ownership
        m_player->base.tileOnMap = gMapPositionToTile(m_mapPointer, m_player->base.position);
        m_mapPointer->tile[m_player->base.tileOnMap].entity.UID  = m_player->UID;
        m_mapPointer->tile[m_player->base.tileOnMap].entity.type = eTileEntityType::tileEntityPlayer;
        m_entityManager->updateModelMatrix(m_player);
    }
}

void cPlayerManager::targetTile(const std::uint32_t &_tile)
{
    // Only path to new destination if it is different
    if (m_player->movement->mapPath.destinationTile != _tile)
    {
        m_player->movement->mapPath.destinationTile = _tile;
        m_player->movement->mapPath.currentTile     = gMapPositionToTile(m_mapPointer, m_player->base.position);
        m_player->movement->mapPath.startTile       = m_player->movement->mapPath.currentTile;
        gAStar(m_mapPointer, m_player->movement->mapPath, m_player->base.flying, m_player->base.overSize);

        if (m_player->movement->mapPath.pathLength > 0)
        {
            m_player->movement->mapPath.currentPosition = 1;
            m_player->movement->pathing = true;

            // Set entity state : move
            if (m_player->state->stateCurrent != eEntityState::entityState_move)
                m_entityManager->stateSet(m_player, eEntityState::entityState_move);
        }
    }

    if (m_player->movement->mapPath.pathLength == 0)
    {
        m_player->movement->pathing = false;

        // Set entity state : idle
        if (m_player->state->stateCurrent != eEntityState::entityState_idle)
            m_entityManager->stateSet(m_player, eEntityState::entityState_idle);
    }
}

void cPlayerManager::targetHalt(void)
{
    m_player->movement->mapPath.pathLength = 0;
    m_player->movement->pathing = false;

    // Set entity state : idle
    if (m_player->state->stateCurrent != eEntityState::entityState_idle)
        m_entityManager->stateSet(m_player, eEntityState::entityState_idle);
}

void cPlayerManager::setUIdrag(const bool &_state)
{
    // set flag
    m_UIdrag = _state;

    // stop moving if a drag is initiated
    if (_state)
    {
        targetHalt();
    }
}

void cPlayerManager::process(const std::int64_t &_dt)
{

    float frameDelta = static_cast<float>(_dt) / 16.0f; // 60 FPS == 16ms per frame

    // Health regeneration
    m_player->character->attribute.health.current.amount += (m_player->character->attribute.health.current.regen * frameDelta);
    if (m_player->character->attribute.health.current.amount > m_player->character->attribute.health.current.max)
        m_player->character->attribute.health.current.amount = m_player->character->attribute.health.current.max;

    // Mana regeneration
    m_player->character->attribute.mana.current.amount += (m_player->character->attribute.mana.current.regen * frameDelta);
    if (m_player->character->attribute.mana.current.amount > m_player->character->attribute.mana.current.max)
        m_player->character->attribute.mana.current.amount = m_player->character->attribute.mana.current.max;

    if (m_player->movement->pathing == true)
    {
        // If a UI active, halt movement
        if ((m_UIdrag == true) || (m_activeWindowCount > 1))
        {
            targetHalt();
            return;
        }

        std::uint32_t currentTile    = m_player->movement->mapPath.path[m_player->movement->mapPath.currentPosition];
        glm::vec3     currentTilePos = gMapTileToPosition(m_mapPointer, currentTile);

        // Get the distance to the destination tile
        float   distanceToTileSqr = ((m_player->base.position.x - currentTilePos.x) * (m_player->base.position.x - currentTilePos.x)) + ((m_player->base.position.z - currentTilePos.z) * (m_player->base.position.z - currentTilePos.z));

        float   distanceToTravelSqr = m_player->physics->acceleration;// * m_player->physics->acceleration;

        // Remove collision data from map
        eTileEntityType tileEntityType = m_mapPointer->tile[m_player->base.tileOnMap].entity.type;
        m_mapPointer->tile[m_player->base.tileOnMap].entity.UID  = 0;
        m_mapPointer->tile[m_player->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

        // Set tiles passable
        gSetTileCollision(m_mapPointer, m_player->base.tileOnMap, false);

        // if not center, move towards tile center
        if (distanceToTileSqr > distanceToTravelSqr)
        {
            if (m_player->base.position.x < currentTilePos.x)
            {
                m_player->base.position.x += m_player->physics->acceleration;
                m_player->physics->velocity.x = m_player->physics->acceleration;
            }
            if (m_player->base.position.x > currentTilePos.x)
            {
                m_player->base.position.x -= m_player->physics->acceleration;
                m_player->physics->velocity.x = m_player->physics->acceleration * -1;
            }
            if (m_player->base.position.z < currentTilePos.z)
            {
                m_player->base.position.z += m_player->physics->acceleration;
                m_player->physics->velocity.z = m_player->physics->acceleration;
            }
            if (m_player->base.position.z > currentTilePos.z)
            {
                m_player->base.position.z -= m_player->physics->acceleration;
                m_player->physics->velocity.z = m_player->physics->acceleration * -1;
            }

            // Turn to face direction moved
            m_player->base.rotation.y = 1.5f - gPhysicsAngleTwoPoints(m_player->base.position.x, m_player->base.position.z, currentTilePos.x, currentTilePos.z);
        }
        // move to tile center, set new tile in path
        else
        {
            m_player->base.position.x = currentTilePos.x;
            m_player->base.position.z = currentTilePos.z;
            m_player->movement->mapPath.currentPosition++;
            if (m_player->movement->mapPath.currentPosition > m_player->movement->mapPath.pathLength)
            {
                m_player->movement->pathing = false;

                // Set entity state : idle
                m_entityManager->stateSet(m_player, eEntityState::entityState_idle);
            }
        }

        // Add collision data to map
        m_player->base.tileOnMap = gMapPositionToTile(m_mapPointer, m_player->base.position);
        m_mapPointer->tile[m_player->base.tileOnMap].entity.UID  = m_player->UID;
        m_mapPointer->tile[m_player->base.tileOnMap].entity.type = tileEntityType;

        // Set tiles impassable
        gSetTileCollision(m_mapPointer, m_player->base.tileOnMap, true);

        m_player->movement->mapPath.currentTile = m_player->base.tileOnMap;
        m_entityManager->updateModelMatrix(m_player);
    }
}

void cPlayerManager::levelUp(void)
{
    // Adjust experience and level
    m_player->character->level.current++;
    m_player->character->level.exp -= m_player->character->level.expNext;
    m_player->character->level.expNext = static_cast<std::uint64_t>(static_cast<double>(m_player->character->level.expNext) * static_cast<double>(m_player->character->level.expMultiplier));

    // Increase attributes + skills
    m_player->character->attribute.pointsCurrent += m_player->character->attribute.pointsOnLevel;
    setAttributePoints(m_player->character->attribute.pointsCurrent);

    // Calculate player attributes
    calculateAttributes();

    // Set health and mana to max
    m_player->character->attribute.health.current.amount = m_player->character->attribute.health.current.max;
    m_player->character->attribute.mana.current.amount = m_player->character->attribute.mana.current.max;

    // Set entity state : levelUp
    m_entityManager->stateSet(m_player, eEntityState::entityState_levelUp);
}

void cPlayerManager::calculateAttributes(void)
{
    // Variables for totals
    std::uint32_t totalStrength   = m_player->character->attribute.strength;
    std::uint32_t totalDexterity  = m_player->character->attribute.dexterity;
    std::uint32_t totalVitality   = m_player->character->attribute.vitality;
    std::uint32_t totalEnergy     = m_player->character->attribute.energy;

    // Health / Mana
    float totalHealth      = 0.0f;
    float totalHealthRegen = 0.0f;

    float totalMana        = 0.0f;
    float totalManaRegen   = 0.0f;

    // Damage
    float physicalDamageTotal     = 0.0f;
    float physicalCritMultipTotal = 0.0f;
    float physicalCritChanceTotal = 0.0f;
    float physicalCritChanceMax   = 90.0f;

    float fireDamageTotal     = 0.0f;
    float fireCritMultipTotal = 0.0f;
    float fireCritChanceTotal = 0.0f;
    float fireCritChanceMax   = 90.0f;

    float iceDamageTotal     = 0.0f;
    float iceCritMultipTotal = 0.0f;
    float iceCritChanceTotal = 0.0f;
    float iceCritChanceMax   = 90.0f;

    float lightningDamageTotal     = 0.0f;
    float lightningCritMultipTotal = 0.0f;
    float lightningCritChanceTotal = 0.0f;
    float lightningCritChanceMax   = 90.0f;

    // Armor / resistance
    float physicalArmorTotal        = 0.0f;
    float physicalBlockChanceTotal  = 0.0f;
    float physicalBlockPercentTotal = 0.0f;
    float physicalBlockChanceMax    = 90.0f;

    float fireArmorTotal        = 0.0f;
    float fireBlockChanceTotal  = 0.0f;
    float fireBlockPercentTotal = 0.0f;
    float fireBlockChanceMax    = 90.0f;

    float iceArmorTotal        = 0.0f;
    float iceBlockChanceTotal  = 0.0f;
    float iceBlockPercentTotal = 0.0f;
    float iceBlockChanceMax    = 90.0f;

    float lightningArmorTotal        = 0.0f;
    float lightningBlockChanceTotal  = 0.0f;
    float lightningBlockPercentTotal = 0.0f;
    float lightningBlockChanceMax    = 90.0f;

    // Aggregate data from equipment
    for (std::uint32_t i = 0; i < m_playerEquipment->getStorageSize(); ++i)
    {
        sEntity* tEntity = m_playerEquipment->getStorageSlot(i)->entity;
        if ((tEntity != nullptr) &&
            (tEntity->character != nullptr) &&
            (tEntity->item != nullptr))
        {
            // Attributes
            totalStrength  += tEntity->character->attribute.strength;
            totalDexterity += tEntity->character->attribute.dexterity;
            totalVitality  += tEntity->character->attribute.vitality;
            totalEnergy    += tEntity->character->attribute.energy;

            // Health / Mana
            totalHealth      += tEntity->character->attribute.health.base.amount;
            totalHealthRegen += tEntity->character->attribute.health.base.regen;

            totalMana        += tEntity->character->attribute.mana.base.amount;
            totalManaRegen   += tEntity->character->attribute.mana.base.regen;

            // Damage
            physicalDamageTotal     += tEntity->character->attribute.damagePhysical.base.amount;
            physicalCritMultipTotal += tEntity->character->attribute.damagePhysical.base.critMultiplier;
            physicalCritChanceTotal += tEntity->character->attribute.damagePhysical.base.critChance;

            fireDamageTotal     += tEntity->character->attribute.damageFire.base.amount;
            fireCritMultipTotal += tEntity->character->attribute.damageFire.base.critMultiplier;
            fireCritChanceTotal += tEntity->character->attribute.damageFire.base.critChance;

            iceDamageTotal     += tEntity->character->attribute.damageIce.base.amount;
            iceCritMultipTotal += tEntity->character->attribute.damageIce.base.critMultiplier;
            iceCritChanceTotal += tEntity->character->attribute.damageIce.base.critChance;

            lightningDamageTotal     += tEntity->character->attribute.damageLightning.base.amount;
            lightningCritMultipTotal += tEntity->character->attribute.damageLightning.base.critMultiplier;
            lightningCritChanceTotal += tEntity->character->attribute.damageLightning.base.critChance;

            // Armor
            physicalArmorTotal        += tEntity->character->attribute.armorPhysical.base.amount;
            physicalBlockChanceTotal  += tEntity->character->attribute.armorPhysical.base.blockChance;
            physicalBlockPercentTotal += tEntity->character->attribute.armorPhysical.base.blockPercent;

            fireArmorTotal        += tEntity->character->attribute.resistanceFire.base.amount;
            fireBlockChanceTotal  += tEntity->character->attribute.resistanceFire.base.blockChance;
            fireBlockPercentTotal += tEntity->character->attribute.resistanceFire.base.blockPercent;

            iceArmorTotal        += tEntity->character->attribute.resistanceIce.base.amount;
            iceBlockChanceTotal  += tEntity->character->attribute.resistanceIce.base.blockChance;
            iceBlockPercentTotal += tEntity->character->attribute.resistanceIce.base.blockPercent;

            lightningArmorTotal        += tEntity->character->attribute.resistanceLightning.base.amount;
            lightningBlockChanceTotal  += tEntity->character->attribute.resistanceLightning.base.blockChance;
            lightningBlockPercentTotal += tEntity->character->attribute.resistanceLightning.base.blockPercent;
        }

    }

//std::cout << "-----------------------------------------------------" << std::endl;
//std::cout << "Player level: " << m_player->character->level.current << std::endl;

    // Health
    // HP = baseHP + (level * 50%) + ((level * 250%) * vitality)
    float HPBias_1 = 0.5f;
    float HPBias_2 = 2.5f;
    totalHealth += m_player->character->attribute.health.base.amount;
    totalHealth += (m_player->character->level.current * HPBias_1);
    totalHealth += ((m_player->character->level.current * HPBias_2) * totalVitality);
    m_player->character->attribute.health.current.max = totalHealth;

//std::cout << "HP: " << m_player->character->attribute.health.current.max << std::endl;

    // HP regen = baseHPregen + (level * 50%) + ((level * 250%) * vitality)
    float HPRegenBias_1 = 0.005f;
    float HPRegenBias_2 = 0.0025f;
    totalHealthRegen += m_player->character->attribute.health.base.regen;
    totalHealthRegen += (m_player->character->level.current * HPRegenBias_1);
    totalHealthRegen += ((m_player->character->level.current * HPRegenBias_2) * totalVitality);
    m_player->character->attribute.health.current.regen = totalHealthRegen;

//std::cout << "HP Regen: " << m_player->character->attribute.health.current.regen << std::endl;

    // Mana
    // MP = baseMP + (level * 50%) + ((level * 250%) * energy)
    float MPBias_1 = 0.5f;
    float MPBias_2 = 2.5f;
    totalMana += m_player->character->attribute.mana.base.amount;
    totalMana += (m_player->character->level.current * MPBias_1);
    totalMana += ((m_player->character->level.current * MPBias_2) * totalEnergy);
    m_player->character->attribute.mana.current.max = totalMana;

//std::cout << "MP: " << m_player->character->attribute.mana.current.max << std::endl;

    // MP regen = baseMPregen + (level * 50%) + ((level * 250%) * energy)
    float MPRegenBias_1 = 0.005f;
    float MPRegenBias_2 = 0.0025f;
    totalManaRegen += m_player->character->attribute.mana.base.regen;
    totalManaRegen += (m_player->character->level.current * MPRegenBias_1);
    totalManaRegen += ((m_player->character->level.current * MPRegenBias_2) * totalEnergy);
    m_player->character->attribute.mana.current.regen = totalManaRegen;

//std::cout << "MP Regen: " << m_player->character->attribute.mana.current.regen << std::endl;

    // Physical damage
    // Damage = (base x strength x bias_1) + (level x strength x bias_2)
    float damageBias_1 = 0.5f;
    float damageBias_2 = 0.25f;
    physicalDamageTotal += (m_player->character->attribute.damagePhysical.base.amount * totalStrength * damageBias_1);
    physicalDamageTotal += (m_player->character->level.current * totalStrength * damageBias_2);
    m_player->character->attribute.damagePhysical.current.amount = physicalDamageTotal;

//std::cout << "Physical damage amount: " << m_player->character->attribute.damagePhysical.current.amount << std::endl;

    // Physical damage crit multiplier
    float critMultiplierBias_1 = 0.05f;
    float critMultiplierBias_2 = 0.01f;
    physicalCritMultipTotal += m_player->character->attribute.damagePhysical.base.critMultiplier;
    physicalCritMultipTotal += totalStrength * critMultiplierBias_1;
    physicalCritMultipTotal += m_player->character->level.current * critMultiplierBias_2;
    m_player->character->attribute.damagePhysical.current.critMultiplier = physicalCritMultipTotal;

//std::cout << "Physical damage crit multiplier: " << m_player->character->attribute.damagePhysical.current.critMultiplier << std::endl;

    // Physical damage crit chance
    float critChanceBias_1 = 0.25f;
    float critChanceBias_2 = 0.01f;
    physicalCritChanceTotal += m_player->character->attribute.damagePhysical.base.critChance;
    physicalCritChanceTotal += totalStrength * critChanceBias_1;
    physicalCritChanceTotal += m_player->character->level.current * critChanceBias_2;
    if (physicalCritChanceTotal > physicalCritChanceMax)
        physicalCritChanceTotal = physicalCritChanceMax;
    m_player->character->attribute.damagePhysical.current.critChance = physicalCritChanceTotal;

//std::cout << "Physical damage crit chance: " << m_player->character->attribute.damagePhysical.current.critChance << std::endl;

    // Fire damage
    // Damage = (base x energy x bias_1) + (level x energy x bias_2)
    damageBias_1 = 0.5f;
    damageBias_2 = 0.25f;
    fireDamageTotal += (m_player->character->attribute.damageFire.base.amount * totalEnergy * damageBias_1);
    fireDamageTotal += (m_player->character->level.current * totalEnergy * damageBias_2);
    m_player->character->attribute.damageFire.current.amount = fireDamageTotal;

//std::cout << "Fire damage amount: " << m_player->character->attribute.damageFire.current.amount << std::endl;

    // Fire damage crit multiplier
    critMultiplierBias_1 = 0.05f;
    critMultiplierBias_2 = 0.01f;
    fireCritMultipTotal += m_player->character->attribute.damageFire.base.critMultiplier;
    fireCritMultipTotal += totalEnergy * critMultiplierBias_1;
    fireCritMultipTotal += m_player->character->level.current * critMultiplierBias_2;
    m_player->character->attribute.damageFire.current.critMultiplier = fireCritMultipTotal;

//std::cout << "Fire damage crit multiplier: " << m_player->character->attribute.damageFire.current.critMultiplier << std::endl;

    // Fire damage crit chance
    critChanceBias_1 = 0.25f;
    critChanceBias_2 = 0.01f;
    fireCritChanceTotal += m_player->character->attribute.damageFire.base.critChance;
    fireCritChanceTotal += totalEnergy * critChanceBias_1;
    fireCritChanceTotal += m_player->character->level.current * critChanceBias_2;
    if (fireCritChanceTotal > fireCritChanceMax)
        fireCritChanceTotal = fireCritChanceMax;
    m_player->character->attribute.damageFire.current.critChance = fireCritChanceTotal;

//std::cout << "Fire damage crit chance: " << m_player->character->attribute.damageFire.current.critChance << std::endl;

    // Ice damage
    // Damage = (base x energy x bias_1) + (level x energy x bias_2)
    damageBias_1 = 0.5f;
    damageBias_2 = 0.25f;
    iceDamageTotal += (m_player->character->attribute.damageIce.base.amount * totalEnergy * damageBias_1);
    iceDamageTotal += (m_player->character->level.current * totalEnergy * damageBias_2);
    m_player->character->attribute.damageIce.current.amount = iceDamageTotal;

//std::cout << "Ice damage amount: " << m_player->character->attribute.damageIce.current.amount << std::endl;

    // Ice damage crit multiplier
    critMultiplierBias_1 = 0.05f;
    critMultiplierBias_2 = 0.01f;
    iceCritMultipTotal += m_player->character->attribute.damageIce.base.critMultiplier;
    iceCritMultipTotal += totalEnergy * critMultiplierBias_1;
    iceCritMultipTotal += m_player->character->level.current * critMultiplierBias_2;
    m_player->character->attribute.damageIce.current.critMultiplier = iceCritMultipTotal;

//std::cout << "Ice damage crit multiplier: " << m_player->character->attribute.damageIce.current.critMultiplier << std::endl;

    // Ice damage crit chance
    critChanceBias_1 = 0.25f;
    critChanceBias_2 = 0.01f;
    iceCritChanceTotal += m_player->character->attribute.damageIce.base.critChance;
    iceCritChanceTotal += totalEnergy * critChanceBias_1;
    iceCritChanceTotal += m_player->character->level.current * critChanceBias_2;
    if (iceCritChanceTotal > iceCritChanceMax)
        iceCritChanceTotal = iceCritChanceMax;
    m_player->character->attribute.damageIce.current.critChance = iceCritChanceTotal;

//std::cout << "Ice damage crit chance: " << m_player->character->attribute.damageIce.current.critChance << std::endl;

    // Lightning damage
    // Damage = (base x energy x bias_1) + (level x energy x bias_2)
    damageBias_1 = 0.5f;
    damageBias_2 = 0.25f;
    lightningDamageTotal += (m_player->character->attribute.damageLightning.base.amount * totalEnergy * damageBias_1);
    lightningDamageTotal += (m_player->character->level.current * totalEnergy * damageBias_2);
    m_player->character->attribute.damageLightning.current.amount = lightningDamageTotal;

//std::cout << "Lightning damage amount: " << m_player->character->attribute.damageLightning.current.amount << std::endl;

    // Lightning damage crit multiplier
    critMultiplierBias_1 = 0.05f;
    critMultiplierBias_2 = 0.01f;
    lightningCritMultipTotal += m_player->character->attribute.damageLightning.base.critMultiplier;
    lightningCritMultipTotal += totalEnergy * critMultiplierBias_1;
    lightningCritMultipTotal += m_player->character->level.current * critMultiplierBias_2;
    m_player->character->attribute.damageLightning.current.critMultiplier = lightningCritMultipTotal;

//std::cout << "Lightning damage crit multiplier: " << m_player->character->attribute.damageLightning.current.critMultiplier << std::endl;

    // Lightning damage crit chance
    critChanceBias_1 = 0.25f;
    critChanceBias_2 = 0.01f;
    lightningCritChanceTotal += m_player->character->attribute.damageLightning.base.critChance;
    lightningCritChanceTotal += totalEnergy * critChanceBias_1;
    lightningCritChanceTotal += m_player->character->level.current * critChanceBias_2;
    if (lightningCritChanceTotal > lightningCritChanceMax)
        lightningCritChanceTotal = lightningCritChanceMax;
    m_player->character->attribute.damageLightning.current.critChance = lightningCritChanceTotal;

//std::cout << "Lightning damage crit chance: " << m_player->character->attribute.damageLightning.current.critChance << std::endl;

    // Physical armor
    // Armor = (base x dexterity x bias_1) + (level x dexterity x bias_2)
    float armorBias_1 = 0.5f;
    float armorBias_2 = 0.25f;
    physicalArmorTotal += (m_player->character->attribute.armorPhysical.base.amount * totalDexterity * armorBias_1);
    physicalArmorTotal += (m_player->character->level.current * totalDexterity * armorBias_2);
    m_player->character->attribute.armorPhysical.current.amount = physicalArmorTotal;

//std::cout << "Physical armor amount: " << m_player->character->attribute.armorPhysical.current.amount << std::endl;

    // Physical armor block chance
    float armorBlockChanceBias_1 = 0.025f;
    float armorBlockChanceBias_2 = 0.005f;
    physicalBlockChanceTotal += m_player->character->attribute.armorPhysical.base.blockChance;
    physicalBlockChanceTotal += totalDexterity * armorBlockChanceBias_1;
    physicalBlockChanceTotal += m_player->character->level.current * armorBlockChanceBias_2;
    if (physicalBlockChanceTotal > physicalBlockChanceMax)
        physicalBlockChanceTotal = physicalBlockChanceMax;
    m_player->character->attribute.armorPhysical.current.blockChance = physicalBlockChanceTotal;

//std::cout << "Physical armor block chance: " << m_player->character->attribute.armorPhysical.current.blockChance << std::endl;

    // Physical armor block percent
    float armorBlockPercentBias_1 = 0.125f;
    float armorBlockPercentBias_2 = 0.005f;
    physicalBlockPercentTotal += m_player->character->attribute.armorPhysical.base.blockPercent;
    physicalBlockPercentTotal += totalDexterity * armorBlockPercentBias_1;
    physicalBlockPercentTotal += m_player->character->level.current * armorBlockPercentBias_2;
    m_player->character->attribute.armorPhysical.current.blockPercent = physicalBlockPercentTotal;

//std::cout << "Physical armor block percent: " << m_player->character->attribute.armorPhysical.current.blockPercent << std::endl;

    // Fire resistance
    // Armor = (base x dexterity x bias_1) + (level x dexterity x bias_2)
    armorBias_1 = 0.5f;
    armorBias_2 = 0.25f;
    fireArmorTotal += (m_player->character->attribute.resistanceFire.base.amount * totalEnergy * armorBias_1);
    fireArmorTotal += (m_player->character->level.current * totalEnergy * armorBias_2);
    m_player->character->attribute.resistanceFire.current.amount = fireArmorTotal;

//std::cout << "Fire resistance amount: " << m_player->character->attribute.resistanceFire.current.amount << std::endl;

    // Fire resistance block chance
    armorBlockChanceBias_1 = 0.025f;
    armorBlockChanceBias_2 = 0.005f;
    fireBlockChanceTotal += m_player->character->attribute.resistanceFire.base.blockChance;
    fireBlockChanceTotal += totalEnergy * armorBlockChanceBias_1;
    fireBlockChanceTotal += m_player->character->level.current * armorBlockChanceBias_2;
    if (fireBlockChanceTotal > fireBlockChanceMax)
        fireBlockChanceTotal = fireBlockChanceMax;
    m_player->character->attribute.resistanceFire.current.blockChance = fireBlockChanceTotal;

//std::cout << "Fire resistance block chance: " << m_player->character->attribute.resistanceFire.current.blockChance << std::endl;

    // Fire resistance block percent
    armorBlockPercentBias_1 = 0.125f;
    armorBlockPercentBias_2 = 0.005f;
    fireBlockPercentTotal += m_player->character->attribute.resistanceFire.base.blockPercent;
    fireBlockPercentTotal += totalEnergy * armorBlockPercentBias_1;
    fireBlockPercentTotal += m_player->character->level.current * armorBlockPercentBias_2;
    m_player->character->attribute.resistanceFire.current.blockPercent = fireBlockPercentTotal;

//std::cout << "Fire resistance block percent: " << m_player->character->attribute.resistanceFire.current.blockPercent << std::endl;

    // Ice resistance
    // Armor = (base x dexterity x bias_1) + (level x dexterity x bias_2)
    armorBias_1 = 0.5f;
    armorBias_2 = 0.25f;
    iceArmorTotal += (m_player->character->attribute.resistanceIce.base.amount * totalEnergy * armorBias_1);
    iceArmorTotal += (m_player->character->level.current * totalEnergy * armorBias_2);
    m_player->character->attribute.resistanceIce.current.amount = iceArmorTotal;

//std::cout << "Ice resistance amount: " << m_player->character->attribute.resistanceIce.current.amount << std::endl;

    // Ice resistance block chance
    armorBlockChanceBias_1 = 0.025f;
    armorBlockChanceBias_2 = 0.005f;
    iceBlockChanceTotal += m_player->character->attribute.resistanceIce.base.blockChance;
    iceBlockChanceTotal += totalEnergy * armorBlockChanceBias_1;
    iceBlockChanceTotal += m_player->character->level.current * armorBlockChanceBias_2;
    if (iceBlockChanceTotal > iceBlockChanceMax)
        iceBlockChanceTotal = iceBlockChanceMax;
    m_player->character->attribute.resistanceIce.current.blockChance = iceBlockChanceTotal;

//std::cout << "Ice resistance block chance: " << m_player->character->attribute.resistanceIce.current.blockChance << std::endl;

    // Ice resistance block percent
    armorBlockPercentBias_1 = 0.125f;
    armorBlockPercentBias_2 = 0.005f;
    iceBlockPercentTotal += m_player->character->attribute.resistanceIce.base.blockPercent;
    iceBlockPercentTotal += totalEnergy * armorBlockPercentBias_1;
    iceBlockPercentTotal += m_player->character->level.current * armorBlockPercentBias_2;
    m_player->character->attribute.resistanceIce.current.blockPercent = iceBlockPercentTotal;

//std::cout << "Ice resistance block percent: " << m_player->character->attribute.resistanceIce.current.blockPercent << std::endl;

    // Lightning resistance
    // Armor = (base x dexterity x bias_1) + (level x dexterity x bias_2)
    armorBias_1 = 0.5f;
    armorBias_2 = 0.25f;
    lightningArmorTotal += (m_player->character->attribute.resistanceLightning.base.amount * totalEnergy * armorBias_1);
    lightningArmorTotal += (m_player->character->level.current * totalEnergy * armorBias_2);
    m_player->character->attribute.resistanceLightning.current.amount = lightningArmorTotal;

//std::cout << "Lightning resistance amount: " << m_player->character->attribute.resistanceLightning.current.amount << std::endl;

    // Lightning resistance block chance
    armorBlockChanceBias_1 = 0.025f;
    armorBlockChanceBias_2 = 0.005f;
    lightningBlockChanceTotal += m_player->character->attribute.resistanceLightning.base.blockChance;
    lightningBlockChanceTotal += totalEnergy * armorBlockChanceBias_1;
    lightningBlockChanceTotal += m_player->character->level.current * armorBlockChanceBias_2;
    if (lightningBlockChanceTotal > lightningBlockChanceMax)
        lightningBlockChanceTotal = lightningBlockChanceMax;
    m_player->character->attribute.resistanceLightning.current.blockChance = lightningBlockChanceTotal;

//std::cout << "Lightning resistance block chance: " << m_player->character->attribute.resistanceLightning.current.blockChance << std::endl;

    // Lightning resistance block percent
    armorBlockPercentBias_1 = 0.125f;
    armorBlockPercentBias_2 = 0.005f;
    lightningBlockPercentTotal += m_player->character->attribute.resistanceLightning.base.blockPercent;
    lightningBlockPercentTotal += totalEnergy * armorBlockPercentBias_1;
    lightningBlockPercentTotal += m_player->character->level.current * armorBlockPercentBias_2;
    m_player->character->attribute.resistanceLightning.current.blockPercent = lightningBlockPercentTotal;

//std::cout << "Lightning resistance block percent: " << m_player->character->attribute.resistanceLightning.current.blockPercent << std::endl;

}
