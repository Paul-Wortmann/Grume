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

#ifndef RE_ENTITY_PHYSICS_HPP
#define RE_ENTITY_PHYSICS_HPP

#include "../system/re_types.hpp"

namespace RoboEngine
{

    struct re_sEntityPhysics
    {
            v3_f position = {};
            re_sEntityPhysics *next = nullptr;
    };

    class re_cEntityPhysicsManager
    {
        public:
            re_cEntityPhysicsManager(void) {}
            ~re_cEntityPhysicsManager(void) {}
            inline re_cEntityPhysicsManager(const re_cEntityPhysicsManager&) = default;
            inline re_cEntityPhysicsManager& operator=(const re_cEntityPhysicsManager& _rhs) {if (this == &_rhs) return *this; return *this;}
            inline const re_sEntityPhysics *getHead(void) {return m_head;}
            inline const re_sEntityPhysics *getTail(void) {return m_tail;}
            void freeAll(void);
            re_sEntityPhysics *getNew(void);
        protected:
        private:
            re_sEntityPhysics *m_head = nullptr;
            re_sEntityPhysics *m_tail = nullptr;
    };
}

#endif // RE_ENTITY_PHYSICS_HPP
