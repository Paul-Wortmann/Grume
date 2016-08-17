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

#include "re_entity_render.hpp"
#include "re_entity_physics.hpp"
#include "../resource/re_manager_mesh.hpp"
#include "../resource/re_manager_shader.hpp"
#include "../resource/re_manager_texture.hpp"

namespace RoboEngine
{

    struct re_sEntity
    {
        re_sEntityRender *render = nullptr;
        re_sEntityPhysics *physics = nullptr;
        re_sEntity *next = nullptr;
    };

    class re_cEntityManager
    {
        public:
            re_cEntityManager(void) {}
            ~re_cEntityManager(void) {}
            inline re_cEntityManager(const re_cEntityManager&) = default;
            inline re_cEntityManager& operator=(const re_cEntityManager& _rhs) {if (this == &_rhs) return *this; return *this;}
            inline void addPhysics(re_sEntity *_entity) {_entity->physics =m_entityPhysicsManager.getNew();}
            inline void addRender(re_sEntity *_entity) {_entity->render =m_entityRenderManager.getNew();}
            inline const re_sEntity *getHead(void) {return m_head;}
            inline const re_sEntity *getTail(void) {return m_tail;}
            void freeAll(void);
            re_sEntity *getNew(void);
            void addMesh(re_sEntity *_entity, std::string _fileName);
            void addShader(re_sEntity *_entity, std::string _fileName);
            void addTexture(re_sEntity *_entity, std::string _fileName);

        protected:
        private:
            re_cEntityRenderManager m_entityRenderManager = {};
            re_cEntityPhysicsManager m_entityPhysicsManager = {};
            re_cManagerMesh m_managerMesh = {};
            re_cManagerShader m_managerShader = {};
            re_cManagerTexture m_managerTexture = {};
            void freeEntities(void);
            re_sEntity *m_head = nullptr;
            re_sEntity *m_tail = nullptr;
    };

}

#endif // RE_ENTITY_HPP
