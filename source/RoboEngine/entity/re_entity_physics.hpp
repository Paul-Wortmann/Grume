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

#include <string>

namespace RoboEngine
{

    class re_cEntityPhysics
    {
        public:
            re_cEntityPhysics(void) {}
            ~re_cEntityPhysics(void) {}
            re_cEntityPhysics(const re_cEntityPhysics&) = default;
            re_cEntityPhysics& operator=(const re_cEntityPhysics& _rhs) {if (this == &_rhs) return *this; return *this;}

        protected:
        private:
    };

}

#endif // RE_ENTITY_PHYSICS_HPP
