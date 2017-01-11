/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef RE_PHYSICS_ENGINE_HPP
#define RE_PHYSICS_ENGINE_HPP

#include "../core/re_platform_headers.hpp"

#include <cstdlib>
#include <cstdint>
#include <string>
#include <thread>
#include <chrono>
#include "../entity/re_entity.hpp"
#include "../system/re_log.hpp"
#include "re_physics.hpp"

namespace RoboEngine
{

    class re_cPhysicsEngine
    {
        public:
            re_cPhysicsEngine(void) {}
            virtual ~re_cPhysicsEngine(void) {}
            re_cPhysicsEngine(const re_cPhysicsEngine&) = default;
            re_cPhysicsEngine& operator=(const re_cPhysicsEngine& rhs) {if (this == &rhs) return *this; return *this;}
            uint32_t initialize(void);
            void terminate(void);
            bool collision2D(const re_sEntity &_entity1, const re_sEntity &_entity2);
            uint32_t process(int64_t _dt);
            inline void setEntity(re_sEntity *_entityHead) {m_entityHead = _entityHead;  m_entity = _entityHead;}
        private:
            re_sEntity *m_entityHead = nullptr;
            re_sEntity *m_entity = nullptr;
    };

}
#endif // RE_PHYSICS_ENGINE_HPP

