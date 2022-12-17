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

#ifndef PARTICLE_ENGINE_HPP
#define PARTICLE_ENGINE_HPP

#include "particle_engine_defines.hpp"

class cParticleEngine :tcTemplateEngine
{
    public:
        std::uint32_t initialize(void) override;
        void          terminate(void) override;
        void          process(const std::int64_t &_dt) override;
        void          spawnParticles(const std::uint32_t &_type, const std::uint32_t &_amount, const glm::vec3 &_position);
        void          setEntityHead(sEntity* _entity) { m_entityHead = _entity; }
        void          setEntityManager(cEntityManager *_entityManager) { m_entityManager = _entityManager; }
        void          setDatabaseManager(cDatabaseManager *_databaseManager) { m_databaseManager = _databaseManager; }
        void          setGraphicsEngine(cGraphicsEngine *_graphicsEngine) { m_graphicsEngine = _graphicsEngine; }
        void          setMapPointer(sMap* _map) { m_mapPointer = _map; };
        sEntity*      spawnEntity(const std::string &_name, const std::uint32_t &_number, const eDatabaseType &_type, const glm::vec3 &_position) { return m_entityManager->spawnEntity(_name, _number, _type, _position); }
        void          deleteEntity(sEntity*& _pointer) { m_entityManager->deleteEntity(_pointer); };

    protected:

    private:
        std::uint32_t       m_maxParticles         = 256;    // Maximum number of particles allowed to exist concurrently
        std::uint32_t       m_activeParticles      = 0;     // Number of currently active particles
        const float         m_timeStep             = 16.0f; // Simulation time step in ms

        void                m_sortParticles(std::uint32_t _maxIterations);

        sEntity*            m_entityHead           = nullptr;
        cEntityManager*     m_entityManager        = nullptr;
        cDatabaseManager*   m_databaseManager      = nullptr;
        cGraphicsEngine*    m_graphicsEngine       = nullptr;
        sMap*               m_mapPointer           = nullptr;
};

#endif // PARTICLE_ENGINE_HPP
