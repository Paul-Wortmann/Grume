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

#ifndef PLAYER_MANAGER_HPP
#define PLAYER_MANAGER_HPP

#include "player_manager_defines.hpp"
#include "player_storage.hpp"

class cPlayerManager :tcTemplateEngine
{
    public:
        std::uint32_t     initialize(void) override;
        void              terminate(void) override;
        void              process(const std::int64_t &_dt) override;
        sPlayerEvent*     getEvent(void) { return m_event.pop(); }

        // Player Action bar
        cPlayerStorage*   getPlayerActionBar(void) { return m_playerActionBar; }
        sEntity*          getActionBarEntity(const std::uint32_t _slot) { return m_playerActionBar->getSlotEntity(_slot); }
        void              setActionBarEntity(const std::uint32_t _slot, sEntity* &_entity) { m_playerActionBar->setSlotEntity(_slot, _entity); };
        std::uint32_t     getActionBarSize(void) { return m_playerActionBar->getStorageSize(); }
        std::uint32_t     getActionBarFreeSlotNum(void) { return m_playerActionBar->freeSlotCount(); }
        bool              actionBarPickupItem(sEntity* &_entity) { return m_playerActionBar->pickupItem(_entity); }
        bool              actionBarDropItem(sEntity* &_entity) { return m_playerActionBar->dropItem(_entity); }
        void              actionBarDrop(const std::uint32_t &_slot) { m_playerActionBar->dropItem(_slot); }

        // Player Inventory
        cPlayerStorage*   getPlayerInventory(void) { return m_playerInventory; }
        sEntity*          getInventoryEntity(const std::uint32_t _slot) { return m_playerInventory->getSlotEntity(_slot); }
        void              setInventoryEntity(const std::uint32_t _slot, sEntity* &_entity) { m_playerInventory->setSlotEntity(_slot, _entity); };
        std::uint32_t     getInventorySize(void) { return m_playerInventory->getStorageSize(); }
        std::uint32_t     getInventoryFreeSlotNum(void) { return m_playerInventory->freeSlotCount(); }
        bool              inventoryPickupItem(sEntity* &_entity) { return m_playerInventory->pickupItem(_entity); }
        bool              inventoryDropItem(sEntity* &_entity) { return m_playerInventory->dropItem(_entity); }
        void              inventoryDrop(const std::uint32_t &_slot) { m_playerInventory->dropItem(_slot); }

        // Player Vendor
        cPlayerStorage*   getPlayerVendor(void) { return m_playerVendor; }
        sEntity*          getVendorEntity(const std::uint32_t _slot) { return m_playerVendor->getSlotEntity(_slot); }
        void              setVendorEntity(const std::uint32_t _slot, sEntity* &_entity) { m_playerVendor->setSlotEntity(_slot, _entity); };
        std::uint32_t     getVendorSize(void) { return m_playerVendor->getStorageSize(); }
        std::uint32_t     getVendorFreeSlotNum(void) { return m_playerVendor->freeSlotCount(); }
        bool              vendorPickupItem(sEntity* &_entity) { return m_playerVendor->pickupItem(_entity); }
        bool              vendorDropItem(sEntity* &_entity) { return m_playerVendor->dropItem(_entity); }
        void              vendorDrop(const std::uint32_t &_slot) { m_playerVendor->dropItem(_slot); }

        // Set pointers
        void              setAudioEngine(cAudioEngine* _audioEngine);
        void              setEntityManager(cEntityManager *_entityManager);
        void              setDatabaseManager(cDatabaseManager *_databaseManager);
        void              setResourceManagerPointer(cResourceManager* _resourceManager);
        void              setMapPointer(sMap* _map);
        void              setUIManager(cUIManager* _UIManager);
        sEntity*          getEntityPlayer(void) { return m_player; }

        void              setMapPlayer(void);
        std::uint32_t     getPlayerID(void) { return m_player->UID; }
        glm::vec3         getPosition(void) { return m_player->base.position; }
        std::uint32_t     getCurrentTile(void) { return m_player->movement->mapPath.currentTile; }
        std::uint32_t     load(const std::string &_fileName);
        void              targetTile(const std::uint32_t &_tile);
        void              setTileClicked(const std::uint32_t &_tile) { m_tileClicked = _tile; }
        void              setObjectClicked(const std::uint32_t &_object) { m_objectClicked = _object; }
        bool              getMoved(void) { return m_player->movement->pathing; }

        void              setPlayerPosition(const std::uint32_t &_tile, const float &_rotation);
        void              setPlayerPosition(const glm::vec3 &_position, const float &_rotation);

    protected:
    private:
        // Event
        tcQueue<sPlayerEvent> m_event       = {};

        // Pointers
        cAudioEngine*     m_audioEngine     = nullptr;
        cDatabaseManager* m_databaseManager = nullptr;
        cResourceManager* m_resourceManager = nullptr;
        cEntityManager*   m_entityManager   = nullptr;
        sEntity*          m_player          = nullptr;
        sMap*             m_mapPointer      = nullptr;

        // systems
        cPlayerStorage*   m_playerActionBar = new cPlayerStorage;
        cPlayerStorage*   m_playerInventory = new cPlayerStorage;
        cPlayerStorage*   m_playerVendor    = new cPlayerStorage;

        // Data
        std::uint32_t     m_tileClicked     = 0;
        std::uint32_t     m_objectClicked   = 0;

        const glm::uvec4  m_stackTextColor  = glm::uvec4(200, 200, 200, 255);
};

#endif // PLAYER_MANAGER_HPP
