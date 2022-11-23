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
 * @date    2011-11-11
 */

#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "entity_define.hpp"
#include "entity_manager_defines.hpp"
#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../map/map_define.hpp"
#include "../map/map_utils.hpp"
#include "../resource/database_manager.hpp"
#include "../resource/resource_manager.hpp"

class cEntityManager : public tcLinkedList<sEntity>
{
    public:
        std::uint32_t        initialize(void);
        void                 terminate(void);
        void                 process(const float &_dt);
        sEntityManagerEvent* getEvent(void) { return m_event.pop(); }

        void                 setMapPointer(sMap* _map) { m_mapPointer = _map; };
        void                 setAudioEngine(cAudioEngine* _audioEngine) { m_audioEngine = _audioEngine; }
        void                 setDatabaseManager(cDatabaseManager* _databaseManager) { m_databaseManager = _databaseManager; }
        void                 setResourceManager(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; }
        void                 updateModelMatrix(sEntity*& _entity);
        sEntity*             load(const std::string &_fileName);
        sEntity*             getEntity(const std::uint32_t &_ID);
        sEntity*             getEntityOnTile(const std::uint32_t &_tile);
        void                 deleteEntity(sEntity*& _pointer);
        void                 setPlayerEntity(sEntity* _pointer) { m_playerEntity = _pointer; };
        sEntity*             spawnEntity(const std::string &_name, const std::uint32_t &_number, const eDatabaseType &_type, const glm::vec3 &_position);
        void                 spawnMinionEntities(void);
        void                 stateSet(sEntity*& _entity, const eEntityState &_state_1);
        void                 stateToggle(sEntity*& _entity, const eEntityState &_state_1, const eEntityState &_state_2);
        void                 stateActivate(sEntity*& _entity, const eEntityState &_state_1);
        void                 triggerEntity(sEntity*& _entity) { m_triggerEntity(_entity); };
        void                 resetRangeTimer(void) { m_rangeUpdateTime = m_rangeUpdateMax; };

    protected:

    private:
        void freeData(sEntity*& _pointer) override;
        void m_setAnimationState(sEntity*& _entity, const glm::vec3& _animation);
        void m_physicsState(sEntity*& _entity, const ePhysicsType& _physicsType);
        void m_tileCollisionState(sEntity*& _entity, const bool& _tilecollision);
        void m_triggerEntity(sEntity*& _entity);

        cAudioEngine*     m_audioEngine     = nullptr;
        cDatabaseManager* m_databaseManager = nullptr;
        cResourceManager* m_resourceManager = nullptr;
        sMap*             m_mapPointer      = nullptr;
        sEntity*          m_playerEntity    = nullptr;

        float             m_range_x_min     = -28.0f;
        float             m_range_x_max     =  14.0f;
        float             m_range_z_min     = -28.0f;
        float             m_range_z_max     =  14.0f;
        float             m_rangeUpdateTime =  0.0f; // accumulated time
        float             m_rangeUpdateMax  =  512.0f; // time required for a range check update ( frame time * frames = 16 * 32 = 512)

        // Event
        tcQueue<sEntityManagerEvent> m_event = {};

        // Internal functions
        std::uint32_t m_nearestFreeTile(const std::uint32_t &_tile);
};

#endif //ENTITY_MANAGER_HPP
