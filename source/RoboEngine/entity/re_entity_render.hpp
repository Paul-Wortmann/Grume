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

#ifndef RE_ENTITY_RENDER_HPP
#define RE_ENTITY_RENDER_HPP

#include "../resource/re_manager_mesh.hpp"
#include "../resource/re_manager_shader.hpp"
#include "../resource/re_manager_texture.hpp"

#include "../wrappers/re_opengl.hpp"

namespace RoboEngine
{

    struct re_sEntityRender
    {
      uint32_t VBO_ID = 0;
      re_sMesh *mesh = nullptr;
      re_sTexture *texture = nullptr;
      re_sShader *shader = nullptr;
      re_sEntityRender *next = nullptr;
    };

    class re_cEntityRenderManager
    {
      public:
         re_cEntityRenderManager(void) {}
         ~re_cEntityRenderManager(void) {}
         inline re_cEntityRenderManager(const re_cEntityRenderManager&) = default;
         inline re_cEntityRenderManager& operator=(const re_cEntityRenderManager& _rhs) {if (this == &_rhs) return *this; return *this;}
         inline const re_sEntityRender *getHead(void) {return m_head;}
         inline const re_sEntityRender *getTail(void) {return m_tail;}
         void freeAll(void);
         re_sEntityRender *getNew(void);
      protected:
      private:
         re_sEntityRender *m_head = nullptr;
         re_sEntityRender *m_tail = nullptr;
    };
}

#endif // RE_ENTITY_RENDER_HPP
