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

    // equipment storage
    return_value = m_playerEquipment->initialize();
    m_playerEquipment->setStorageType(ePlayerStorageType::playerStorageTypeEquipment);
    m_playerEquipment->setStorageSize(14);
    m_playerEquipment->setStackColor(m_stackTextColor);
    m_playerEquipment->setSlot1(eComponentFunction::componentFunctionEquipmentSlot_1);
    m_playerEquipment->setStack1(eComponentFunction::componentFunctionEquipmentStack_1);

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
        sPlayerStorageSlot* source = _sourceStorage->getStorageSlot(_slot1);
        sPlayerStorageSlot* destination = _destinationStorage->getStorageSlot(_slot2);
        sPlayerStorageSlot tSlot = {};

        // Backup
        tSlot.data = source->data;
        tSlot.dragged = source->dragged;
        tSlot.entity = source->entity;
        tSlot.occupied = source->occupied;
        tSlot.stackLabel = source->stackLabel;
        tSlot.type = source->type;

        // To source
        source->data = destination->data;
        source->dragged = destination->dragged;
        source->entity = destination->entity;
        source->occupied = destination->occupied;
        source->stackLabel = destination->stackLabel;
        source->type = destination->type;

        // To destination
        destination->data = tSlot.data;
        destination->dragged = tSlot.dragged;
        destination->entity = tSlot.entity;
        destination->occupied = tSlot.occupied;
        destination->stackLabel = tSlot.stackLabel;
        destination->type = tSlot.type;

        // UI set slot state
        _sourceStorage->setUISlotEnabled(_slot1, source->occupied);
        _destinationStorage->setUISlotEnabled(_slot2, destination->occupied);

        tSlot.entity = nullptr;
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

    // Inventory to vendor -> sell item
    if ((_type1 == ePlayerStorageType::playerStorageTypeInventory) &&
        (_type2 == ePlayerStorageType::playerStorageTypeVendor))
    {
        swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
    }

    // Vendor to Inventory -> buy item
    else if ((_type1 == ePlayerStorageType::playerStorageTypeVendor) &&
             (_type2 == ePlayerStorageType::playerStorageTypeInventory))
    {
        swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
    }

    // Swap if same storage
    //if (sourceStorage == destinationStorage)
    else
    {
        swapStorage(sourceStorage, _slot1, destinationStorage, _slot2);
    }
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
    // If no object and no NPC, then path find to tile
    //if ((m_mapPointer->tile[_tile].object == 0) && (m_mapPointer->tile[_tile].npc == 0))
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
                m_entityManager->stateSet(m_player, eEntityState::entityState_move);
            }
        }
    }

    if (m_player->movement->mapPath.pathLength == 0)
    {
        m_player->movement->pathing = false;

        // Set entity state : idle
        m_entityManager->stateSet(m_player, eEntityState::entityState_idle);
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
