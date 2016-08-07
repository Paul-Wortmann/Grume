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

#ifndef RE_ENTITY_HPP
#define RE_ENTITY_HPP

#include "re_entity_physics.hpp"

namespace RoboEngine
{

    struct re_sEntity
    {
        re_sEntityPhysics *physics = nullptr;
        re_sEntity *next = nullptr;
    };

    class re_cEntityManager
    {
        public:
            re_cEntityManager(void) {}
            ~re_cEntityManager(void) {}
            re_cEntityManager(const re_cEntityManager&) = default;
            re_cEntityManager& operator=(const re_cEntityManager& _rhs) {if (this == &_rhs) return *this; return *this;}
            void freeAllEntities(void);
            re_sEntity *newEntity(void);
            re_sEntity *getEntityRoot(void) {return m_root;}
        protected:
        private:
            re_sEntity *m_root = nullptr;
    };

}

#endif // RE_ENTITY_HPP
