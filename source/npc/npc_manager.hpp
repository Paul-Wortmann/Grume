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

#ifndef NPC_MANAGER_HPP
#define NPC_MANAGER_HPP

#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../loot/loot_manager.hpp"
#include "../map/map_define.hpp"
#include "../map/map_line_of_sight.hpp"
#include "../map/map_path_a_star.hpp"
#include "../particles/particle_engine.hpp"
#include "../physics/physics_collision.hpp"
#include "../resource/database_manager.hpp"
#include "../resource/resource_manager.hpp"

class cNPCManager
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        void          process(const float &_dt);
        void          setEntityHead(sEntity* _entity) { m_entityHead = _entity; }
        void          setEntityPlayer(sEntity* _entity) { m_entityPlayer = _entity; }
        void          setMapPointer(sMap* _map) { m_mapPointer = _map; };
        void          setAudioEngine(cAudioEngine* _audioEngine) { m_audioEngine = _audioEngine; };
        void          setDatabaseManagerPointer(cDatabaseManager* _databaseManager) { m_databaseManager = _databaseManager; };
        void          setEntityManagerPointer(cEntityManager* _entityManager) { m_entityManager = _entityManager; };
        void          setLootManagerPointer(cLootManager* _lootManager) { m_lootManager = _lootManager; };
        void          setParticleEnginePointer(cParticleEngine* _particleEngine) { m_particleEngine = _particleEngine; };
        void          setResourceManagerPointer(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; };
        void          setGraphicsEnginePointer(cGraphicsEngine* _graphicsEngine) { m_graphicsEngine = _graphicsEngine; };
        void          setQuestManager(cQuestManager* _questManager) { m_questManager = _questManager; };
        void          updatePaths(void) { m_updatePaths = true; };

    protected:

    private:
        // external pointers
        cAudioEngine*     m_audioEngine       = nullptr;
        cDatabaseManager* m_databaseManager   = nullptr;
        cEntityManager*   m_entityManager     = nullptr;
        cGraphicsEngine*  m_graphicsEngine    = nullptr;
        cLootManager*     m_lootManager       = nullptr;
        cParticleEngine*  m_particleEngine    = nullptr;
        cQuestManager*    m_questManager      = nullptr;
        cResourceManager* m_resourceManager   = nullptr;
        sEntity*          m_entityHead        = nullptr;
        sEntity*          m_entityTemp        = nullptr;
        sEntity*          m_entityPlayer      = nullptr;
        sMap*             m_mapPointer        = nullptr;

        bool              m_updatePaths       = false;

        float             m_updateAIFrequency = 50.0f; // milliseconds
        float             m_updateAICounter   = 0.0f;

        void              m_generateWaypoints(sEntity*& _entity);
        void              m_entityDeath(sEntity*& _entity);
        void              m_entityRevive(sEntity*& _entity);
};

#endif //NPC_MANAGER_HPP
