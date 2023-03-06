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



#ifndef PHYSICS_ENGINE_HPP
#define PHYSICS_ENGINE_HPP

#include "physics_engine_defines.hpp"
#include "../entity/entity_define.hpp"
#include "../entity/entity_manager.hpp"
#include "../map/map_manager_defines.hpp"

class cPhysicsEngine :tcTemplateEngine
{
    public:
        std::uint32_t   initialize(void) override;
        void            terminate(void) override;
        void            process(const std::int64_t &_dt) override;
        sPhysicsEvent*  getEvent(void) { return m_event.pop(); }
        void            setEntityHead(sEntity* _entity) { m_entityHead = _entity; }
        void            setEntityManager(cEntityManager* _entityManager) { m_entityManager = _entityManager; }
        void            setMapPointer(sMap* _map) { m_mapPointer = _map; };
        void            setIOPointer(sIO* _io) { m_io = _io; }

        // Camera
        void            setCameraPosition(const glm::vec3 &_position) { m_cameraPosition = _position; }
        void            setCameraDirection(const glm::vec3 &_direction) { m_cameraDirection = _direction; }

        // UI
        void            setMouseOverMenu(const bool &_state) { m_mouseOverMenu = _state; }

    protected:

    private:
        const float            m_timeStep        = 16.0f; // Simulation time step in ms

        sEntity*               m_entityHead      = nullptr;
        cEntityManager*        m_entityManager   = nullptr;
        sMap*                  m_mapPointer      = nullptr;
        tcQueue<sPhysicsEvent> m_event           = {};

        // IO
        sIO*                   m_io              = nullptr;

        // Camera
        glm::vec3              m_cameraPosition  = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3              m_cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f);

        // UI
        bool                   m_mouseOverMenu   = false;
};

#endif // PHYSICS_ENGINE_HPP
