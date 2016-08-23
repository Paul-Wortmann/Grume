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
#include "../wrappers/re_glew.hpp"
#include "../wrappers/re_opengl.hpp"
#include "../wrappers/re_sdl.hpp"
#include "../wrappers/re_sdl_graphics.hpp"

namespace RoboEngine
{

    void re_cGraphicsEngine::initialize(void)
    {
        RE_GL_SetAttribute(RE_GL_CONTEXT_MAJOR_VERSION, RE_RENDERER_CONTEXT_MAJOR);
        RE_GL_SetAttribute(RE_GL_CONTEXT_MINOR_VERSION, RE_RENDERER_CONTEXT_MINOR);
        RE_GL_SetAttribute(RE_GL_CONTEXT_PROFILE_MASK, RE_GL_CONTEXT_PROFILE_CORE);
        RE_GL_SetAttribute(RE_GL_DOUBLEBUFFER, 1);
        RE_GL_SetAttribute(RE_GL_DEPTH_SIZE, 24);
        RE_GL_SetSwapInterval(1);
        m_currentDisplay = 0;
        m_currentDisplayMode = 0;
        m_numberDisplays = RE_GetNumVideoDisplays();
        m_numberDisplayModes = RE_GetNumDisplayModes(m_currentDisplay);
        // todo: create list of available display modes, if full screen flag, set to optimal full screen resolution.

        if (m_displayFullscreen)
            m_displayFlags |= RE_WINDOW_FULLSCREEN_DESKTOP;
        m_window = RE_CreateWindow("Frost and Flame", m_displayX, m_displayY, m_displayFlags);
        if (m_window == nullptr)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Non fatal warning - Unable to create a window.");
        else
        {
            m_glcontext = RE_GL_CreateContext(m_window);
            RE_glewExperimental(true);
            RE_GLenum glewStatus =RE_glewInit();
            if (glewStatus != RE_GLEW_OK)
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Unable to initialize GLEW.");
            else
            {
                int32_t GL_MajorVersion = 0;
                int32_t GL_MinorVersion = 0;
                RE_GL_GetAttribute(RE_GL_CONTEXT_MAJOR_VERSION, &GL_MajorVersion);
                RE_GL_GetAttribute(RE_GL_CONTEXT_MINOR_VERSION, &GL_MinorVersion);
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "OpenGL Context Version: " + std::to_string(GL_MajorVersion) +  "." + std::to_string(GL_MinorVersion));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_VERSION)));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_VENDOR)));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_RENDERER)));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_SHADING_LANGUAGE_VERSION)));


                RE_glClearColor(0.1f,0.1f,0.4f,1);
                RE_glClearDepth(1.0);

            }
        }
    }

    void re_cGraphicsEngine::deinitialize(void)
    {
        RE_DestroyWindow(m_window);
        RE_GL_DeleteContext(m_glcontext);
    }

    void re_cGraphicsEngine::render(void)
    {
        RE_glClear(RE_GL_COLOR_BUFFER_BIT | RE_GL_DEPTH_BUFFER_BIT);
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
                            RE_glUseProgram(0);
                            for (uint16_t i = 0; i < m_entity->render->shader->numAttributes; i++)
                                RE_glDisableVertexAttribArray(i);
                            m_currentShader = 0;
                        }
                        if (m_currentShader == 0)
                        {
                            m_currentShader = m_entity->render->shader->ID;
                            RE_glUseProgram(m_entity->render->shader->ID);
                            for (uint16_t i = 0; i < m_entity->render->shader->numAttributes; i++)
                                RE_glEnableVertexAttribArray(i);
                        }
                        // initialize mesh
                        if (m_entity->render->shader->ID == 0)
                        {
                            RE_glGenBuffers(1, &m_entity->render->shader->ID);
                            RE_glBindBuffer(RE_GL_ARRAY_BUFFER, m_entity->render->shader->ID);
                            RE_glBufferData(RE_GL_ARRAY_BUFFER, sizeof(m_entity->render->mesh->index), m_entity->render->mesh->index, RE_GL_STATIC_DRAW);
                            RE_glBindBuffer(RE_GL_ARRAY_BUFFER, 0);
                        }
                        // render mesh
                        if (m_entity->render->shader->ID != 0)
                        {
                            RE_glBindBuffer(RE_GL_ARRAY_BUFFER, m_entity->render->shader->ID);
                            RE_glEnableVertexAttribArray(0);

                            RE_glVertexAttribPointer(0, 3, RE_GL_FLOAT, RE_GL_FALSE, sizeof(v8_f), (void*)offsetof(v8_f, x));
                            RE_glVertexAttribPointer(1, 3, RE_GL_FLOAT, RE_GL_FALSE, sizeof(v8_f), (void*)offsetof(v8_f, nx));
                            RE_glVertexAttribPointer(2, 2, RE_GL_FLOAT, RE_GL_FALSE, sizeof(v8_f), (void*)offsetof(v8_f, s));

                            RE_glDrawArrays(RE_GL_TRIANGLES, 0, (m_entity->render->mesh->indexCount/3));

                            RE_glEnableVertexAttribArray(0);
                            RE_glBindBuffer(RE_GL_ARRAY_BUFFER, 0);
                        }
                    }

                }
                m_entity = m_entity->next;
            }
        }
        RE_GL_SwapWindow(m_window);
    }

}

