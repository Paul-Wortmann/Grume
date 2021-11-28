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

#include "../core/includes.hpp"
#include "../entity/entity_define.hpp"

#include "physics_define.hpp"

class cPhysicsEngine : public tcLinkedList<sPhysicsObject>
{
    public:
        uint32 initialize(void);
        void   terminate(void);
        void   process(const float32 &_dt);
        void   setEntityHead(sEntity* _entity) { m_entityHead = _entity; }

    protected:
        
    private:
        void freeData(sPhysicsObject*& _object);

        // Entity management
        sEntity*           m_entityHead         = nullptr;

};

#endif //PHYSICS_ENGINE_HPP
