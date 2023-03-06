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

#ifndef OBJECT_MANAGER_HPP
#define OBJECT_MANAGER_HPP

#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../loot/loot_manager.hpp"
#include "../map/map_define.hpp"
#include "../particles/particle_engine.hpp"
#include "../player/player_manager.hpp"
#include "../physics/physics_collision.hpp"
#include "../resource/resource_manager.hpp"

// Event type enum
enum eObjectEventType : std::uint32_t
{
    objectEventType_none = 0,    // null event
    objectEventType_gold = 1     // gold drop
};

// Event struct
struct sObjectManagerEvent
{
    sObjectManagerEvent* next = nullptr;
    eObjectEventType     type = eObjectEventType::objectEventType_none;
    std::uint64_t        data = 0;
};

class cObjectManager
{
    public:
        std::uint32_t        initialize(void);
        void                 terminate(void);
        sObjectManagerEvent* getEvent(void) { return m_event.pop(); }

        void          process(const std::int64_t &_dt);
        void          setEntityHead(sEntity* _entity) { m_entityHead = _entity; };
        void          setEntityPlayer(sEntity* _entity) { m_entityPlayer = _entity; };
        void          setMapPointer(sMap* _map) { m_mapPointer = _map; };
        void          setAudioEngine(cAudioEngine* _audioEngine) { m_audioEngine = _audioEngine; };
        void          setEntityManagerPointer(cEntityManager* _entityManager) { m_entityManager = _entityManager; };
        void          setParticleEnginePointer(cParticleEngine* _particleEngine) { m_particleEngine = _particleEngine; };
        void          setPlayerManager(cPlayerManager* _playerManager) { m_playerManager = _playerManager; };
        void          setResourceManagerPointer(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; };
        void          setLootManagerPointer(cLootManager* _lootManager) { m_lootManager = _lootManager; };
        void          setIOPointer(sIO* _io) { m_io = _io; }

    protected:

    private:
        // Entity management
        cEntityManager*   m_entityManager    = nullptr;
        cAudioEngine*     m_audioEngine      = nullptr;
        cLootManager*     m_lootManager      = nullptr;
        cParticleEngine*  m_particleEngine   = nullptr;
        cPlayerManager*   m_playerManager    = nullptr;
        cResourceManager* m_resourceManager  = nullptr;
        sEntity*          m_entityHead       = nullptr;
        sEntity*          m_entityTemp       = nullptr;
        sEntity*          m_entityPlayer     = nullptr;
        sMap*             m_mapPointer       = nullptr;

        // IO
        sIO*              m_io               = nullptr;

        tcQueue<sObjectManagerEvent> m_event = {};
};

#endif //OBJECT_MANAGER_HPP
