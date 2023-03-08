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
}

void cPlayerManager::equip(sEntity* &_entity)
{

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
    m_player->character->attribute.health.current += (m_player->character->attribute.health.regen * frameDelta);
    if (m_player->character->attribute.health.current > m_player->character->attribute.health.max)
        m_player->character->attribute.health.current = m_player->character->attribute.health.max;

    // Mana regeneration
    m_player->character->attribute.mana.current += (m_player->character->attribute.mana.regen * frameDelta);
    if (m_player->character->attribute.mana.current > m_player->character->attribute.mana.max)
        m_player->character->attribute.mana.current = m_player->character->attribute.mana.max;

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
    m_player->character->attribute.health.current = m_player->character->attribute.health.max;
    m_player->character->attribute.mana.current = m_player->character->attribute.mana.max;

    // Set entity state : levelUp
    m_entityManager->stateSet(m_player, eEntityState::entityState_levelUp);
}

void cPlayerManager::calculateAttributes(void)
{
    // Variables for totals
    std::uint32_t totalStrength  = m_player->character->attribute.strength;
    std::uint32_t totalDexterity = m_player->character->attribute.dexterity;
    std::uint32_t totalVitality  = m_player->character->attribute.vitality;
    std::uint32_t totalEnergy    = m_player->character->attribute.energy;

    // Aggregate data from equipment
    for (std::uint32_t i = 0; i < m_playerEquipment->getStorageSize(); ++i)
    {
        sEntity* tEntity = m_playerEquipment->getStorageSlot(i)->entity;
        if (tEntity != nullptr)
        {
            totalStrength  += tEntity->item->attribute.strength;
            totalDexterity += tEntity->item->attribute.dexterity;
            totalVitality  += tEntity->item->attribute.vitality;
            totalEnergy    += tEntity->item->attribute.energy;
        }

    }

std::cout << "-----------------------------------------------------" << std::endl;
std::cout << "Player level: " << m_player->character->level.current << std::endl;

    // Health
    // HP = baseHP + (level * 50%) + ((level * 250%) * vitality)
    m_player->character->attribute.health.max = m_player->character->attribute.health.base +
                                                (m_player->character->level.current * 0.5) +
                                                ((m_player->character->level.current * 2.5) *
                                                 totalVitality);
std::cout << "HP: " << m_player->character->attribute.health.max << std::endl;

    // HP regen = baseHPregen + (level * 50%) + ((level * 250%) * vitality)
    m_player->character->attribute.health.regen = m_player->character->attribute.health.regenBase +
                                                  (m_player->character->level.current * 0.005) +
                                                  ((m_player->character->level.current * 0.0025) *
                                                   totalVitality);
std::cout << "HP Regen: " << m_player->character->attribute.health.regen << std::endl;

    // Mana
    // MP = baseMP + (level * 50%) + ((level * 250%) * energy)
    m_player->character->attribute.mana.max = m_player->character->attribute.mana.base +
                                              (m_player->character->level.current * 0.5) +
                                              ((m_player->character->level.current * 2.5) *
                                               totalEnergy);
std::cout << "MP: " << m_player->character->attribute.mana.max << std::endl;

    // MP regen = baseMPregen + (level * 50%) + ((level * 250%) * energy)
    m_player->character->attribute.mana.regen = m_player->character->attribute.mana.regenBase +
                                                (m_player->character->level.current * 0.005) +
                                                ((m_player->character->level.current * 0.0025) *
                                                 totalEnergy);
std::cout << "MP Regen: " << m_player->character->attribute.mana.regen << std::endl;

    // --- Set to base values ---

    // Damage
    m_player->character->attribute.damagePhysical.base = 1.0f + totalStrength;
    m_player->character->attribute.damagePhysical.critChance = 1.0f;
    m_player->character->attribute.damagePhysical.critMultiplier = 0.25f;
    m_player->character->attribute.damageFire.base = 1.0f + totalEnergy;
    m_player->character->attribute.damageFire.critChance = 1.0f;
    m_player->character->attribute.damageFire.critMultiplier = 0.25f;
    m_player->character->attribute.damageIce.base = 1.0f + totalEnergy;
    m_player->character->attribute.damageIce.critChance = 1.0f;
    m_player->character->attribute.damageIce.critMultiplier = 0.25f;
    m_player->character->attribute.damageLightning.base = 1.0f + totalEnergy;
    m_player->character->attribute.damageLightning.critChance = 1.0f;
    m_player->character->attribute.damageLightning.critMultiplier = 0.25f;

    // Armor
    m_player->character->attribute.armorPhysical.base = totalDexterity;

    // Resistance
    m_player->character->attribute.resistanceFire.base = totalDexterity;
    m_player->character->attribute.resistanceIce.base = totalDexterity;
    m_player->character->attribute.resistanceLightning.base = totalDexterity;

    // Adjust values based on equipment
}

//melee damage
//armor class
//crit-multiplier
//crit-change



