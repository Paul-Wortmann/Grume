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

#include <GL/glew.h>
#include "re_graphics_engine.hpp"

namespace RoboEngine
{

            void re_cGraphicsEngine::initialize(void)
            {
                m_window = RE_CreateWindow("Frost and Flame", 640, 480, RE_WINDOW_OPENGL);
                m_glcontext = SDL_GL_CreateContext(m_window);
                glClearColor(0,0,255,1);
            }

            void re_cGraphicsEngine::deinitialize(void)
            {
                RE_DestroyWindow(m_window);
                RE_GL_DeleteContext(m_glcontext);
            }

            void re_cGraphicsEngine::render(void)
            {
                int64_t _dt = 16;
                std::this_thread::sleep_for(std::chrono::milliseconds(_dt));
                glClear(GL_COLOR_BUFFER_BIT);
                RE_GL_SwapWindow(m_window);
                //std::cout << "FPS: " << 1000 / _dt << std::endl;
            }

}
