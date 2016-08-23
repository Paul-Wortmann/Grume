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

#include "re_graphics_engine.hpp"
#include "../system/re_log.hpp"

namespace RoboEngine
{

    void re_cGraphicsEngine::initialize(void)
    {
        SDL_SetMainReady();
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, RE_RENDERER_CONTEXT_MAJOR);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, RE_RENDERER_CONTEXT_MINOR);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetSwapInterval(1);
        m_currentDisplay = 0;
        m_currentDisplayMode = 0;
        m_numberDisplays = SDL_GetNumVideoDisplays();
        m_numberDisplayModes = SDL_GetNumDisplayModes(m_currentDisplay);
        // todo: create list of available display modes, if full screen flag, set to optimal full screen resolution.

        if (m_displayFullscreen)
            m_displayFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        m_window = SDL_CreateWindow("Frost and Flame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_displayX, m_displayY, m_displayFlags);
        if (m_window == nullptr)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Non fatal warning - Unable to create a window.");
        else
        {
            m_glcontext = SDL_GL_CreateContext(m_window);
            glewExperimental = true;
            GLenum glewStatus =glewInit();
            if (glewStatus != GLEW_OK)
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Unable to initialize GLEW.");
            else
            {
                int32_t GL_MajorVersion = 0;
                int32_t GL_MinorVersion = 0;
                SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &GL_MajorVersion);
                SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &GL_MinorVersion);
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "OpenGL Context Version: " + std::to_string(GL_MajorVersion) +  "." + std::to_string(GL_MinorVersion));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(glGetString(GL_VERSION)));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));


                glClearColor(0.1f,0.1f,0.4f,1);
                glClearDepth(1.0);

            }
        }
    }

    void re_cGraphicsEngine::deinitialize(void)
    {
        SDL_DestroyWindow(m_window);
        SDL_GL_DeleteContext(m_glcontext);
    }

    void re_cGraphicsEngine::render(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_entity = m_entityHead;
        if (m_entity != nullptr)
        {
            while (m_entity  != nullptr)
            {
                if ((m_entity->enabled) && (m_entity->render != nullptr))
                {
                    //shader
                    if ((m_entity->render->shader != nullptr) && (m_entity->render->shader->ID != 0) && (m_currentShader != m_entity->render->shader->ID))
                    {
                        if (m_currentShader != m_entity->render->shader->ID)
                        {
                            glUseProgram(0);
                            for (uint16_t i = 0; i < m_entity->render->shader->numAttributes; i++)
                                glDisableVertexAttribArray(i);
                            m_currentShader = 0;
                        }
                        if (m_currentShader == 0)
                        {
                            m_currentShader = m_entity->render->shader->ID;
                            glUseProgram(m_entity->render->shader->ID);
                            for (uint16_t i = 0; i < m_entity->render->shader->numAttributes; i++)
                                glEnableVertexAttribArray(i);
                        }
                        // initialize mesh
                        if (m_entity->render->shader->ID == 0)
                        {
                            glGenBuffers(1, &m_entity->render->shader->ID);
                            glBindBuffer(GL_ARRAY_BUFFER, m_entity->render->shader->ID);
                            glBufferData(GL_ARRAY_BUFFER, sizeof(m_entity->render->mesh->index), m_entity->render->mesh->index, GL_STATIC_DRAW);
                            glBindBuffer(GL_ARRAY_BUFFER, 0);
                        }
                        // render mesh
                        if (m_entity->render->shader->ID != 0)
                        {
                            glBindBuffer(GL_ARRAY_BUFFER, m_entity->render->shader->ID);
                            glEnableVertexAttribArray(0);

                            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(v8_f), (void*)offsetof(v8_f, x));
                            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(v8_f), (void*)offsetof(v8_f, nx));
                            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(v8_f), (void*)offsetof(v8_f, s));

                            glDrawArrays(GL_TRIANGLES, 0, (m_entity->render->mesh->indexCount/3));

                            glEnableVertexAttribArray(0);
                            glBindBuffer(GL_ARRAY_BUFFER, 0);
                        }
                    }

                }
                m_entity = m_entity->next;
            }
        }
        SDL_GL_SwapWindow(m_window);
    }

}

