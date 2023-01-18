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

#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../map/map_manager_defines.hpp"
#include "../physics/physics_collision.hpp"
#include "../resource/database_manager.hpp"
#include "../ui/ui_manager.hpp"

#include "player_character.hpp"
#include "player_inventory.hpp"
#include "player_stash.hpp"
#include "player_vendor.hpp"

// Event type enum
enum ePlayerEventType : std::uint32_t { playerEventType_none        = 0,    // null event
                                        playerEventType_newPosition = 1 };  // player has been repositioned

// Event struct
struct sPlayerEvent
{
    sPlayerEvent*      next = nullptr;
    ePlayerEventType   type = ePlayerEventType::playerEventType_none;
    std::uint32_t      data = 0;
};

class cPlayerManager :tcTemplateEngine
{
    public:
        std::uint32_t     initialize(void) override;
        void              terminate(void) override;
        void              process(const std::int64_t &_dt) override;
        sPlayerEvent*     getEvent(void) { return m_event.pop(); }
        cPlayerInventory* getPlayerInventory(void) { return m_playerInventory; }

        // Player Inventory
        sEntity*      getInventoryEntity(const std::uint32_t _slot) { return m_playerInventory->getSlotEntity(_slot); }
        void          setInventoryEntity(const std::uint32_t _slot, sEntity* &_entity) { m_playerInventory->setSlotEntity(_slot, _entity); };
        std::uint32_t getInventorySize(void) { return m_playerInventory->getInventorySize(); }
        std::uint32_t getInventoryFreeSlotNum(void) { return m_playerInventory->freeSlotCount(); }
        bool          pickupItem(sEntity* &_entity) { return m_playerInventory->pickupItem(_entity); }
        bool          dropItem(sEntity* &_entity) { return m_playerInventory->dropItem(_entity); }
        void          inventoryDrop(const std::uint32_t &_slot) { m_playerInventory->dropItem(_slot); }

        // Set pointers
        void          setAudioEngine(cAudioEngine* _audioEngine) { m_audioEngine = _audioEngine; }
        void          setEntityManager(cEntityManager *_entityManager) { m_entityManager = _entityManager; m_playerInventory->setEntityManager(_entityManager); }
        void          setDatabaseManager(cDatabaseManager *_databaseManager) { m_databaseManager = _databaseManager; }
        void          setResourceManagerPointer(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; m_playerInventory->setResourceManagerPointer(_resourceManager); }
        void          setMapPointer(sMap* _map) { m_mapPointer = _map; m_playerInventory->setMapPointer(_map); }
        void          setInventoryUIManager(cUIManager* _UIManager) { m_playerInventory->setUIManager(_UIManager); }
        sEntity*      getEntityPlayer(void) { return m_player; }

        void          setMapPlayer(void);
        std::uint32_t getPlayerID(void) { return m_player->UID; }
        glm::vec3     getPosition(void) { return m_player->base.position; }
        std::uint32_t getCurrentTile(void) { return m_player->movement->mapPath.currentTile; }
        std::uint32_t load(const std::string &_fileName);
        void          targetTile(const std::uint32_t &_tile);
        void          setTileClicked(const std::uint32_t &_tile) { m_tileClicked = _tile; }
        void          setObjectClicked(const std::uint32_t &_object) { m_objectClicked = _object; }
        bool          getMoved(void) { return m_player->movement->pathing; }

        void          setPlayerPosition(const std::uint32_t &_tile, const float &_rotation);
        void          setPlayerPosition(const glm::vec3 &_position, const float &_rotation);

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
        cPlayerInventory* m_playerInventory = new cPlayerInventory;

        // Data
        std::uint32_t     m_tileClicked     = 0;
        std::uint32_t     m_objectClicked   = 0;
};

#endif // PLAYER_MANAGER_HPP
