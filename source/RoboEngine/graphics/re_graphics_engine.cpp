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
#include "../roboengine.hpp"

namespace RoboEngine
{

    uint32_t re_cGraphicsEngine::initialize(void)
    {
        uint32_t return_value = EXIT_SUCCESS;
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, RE_GL_CONTEXT_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, RE_GL_CONTEXT_MINOR);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        m_currentDisplay = 0;
        m_currentDisplayMode = 0;
        // todo: create list of available display modes, if full screen flag, set to optimal full screen resolution.

        if (m_fullscreen)
            m_window = glfwCreateWindow( m_width, m_height, m_title.c_str(), glfwGetPrimaryMonitor(), nullptr);
        else
            m_window = glfwCreateWindow( m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if( m_window == nullptr )
        {
            re_logWrite("Failed to open GLFW window.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            glfwTerminate();
            return EXIT_FAILURE;
        }

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(1);
        glewExperimental = true;
        if (glewInit() != GLEW_OK)
        {
            re_logWrite("Failed to initialize GLEW.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            return EXIT_FAILURE;
        }
        else
        {
            re_logWrite(reinterpret_cast<const char*>(glGetString(GL_VERSION)), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            re_logWrite(reinterpret_cast<const char*>(glGetString(GL_VENDOR)), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            re_logWrite(reinterpret_cast<const char*>(glGetString(GL_RENDERER)), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            re_logWrite(reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);

            m_camera.initialize(m_width, m_height, 45.0f);
            m_camera.setPosition(glm::vec3(0,0,-32), glm::vec3(0,0,0));

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_CULL_FACE);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glClearDepth(1.0);
            glClearColor(0.1f,0.1f,0.4f,1);
        }

        return return_value;
    }

    uint32_t re_cGraphicsEngine::terminate(void)
    {
        uint32_t return_value = EXIT_SUCCESS;
        glfwDestroyWindow(m_window);
        m_window = nullptr;
        return return_value;
    }

    void re_cGraphicsEngine::process(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_entity = m_entityHead;
        if (m_entity != nullptr)
        {
            while (m_entity  != nullptr)
            {
                if ((m_entity->enabled) && (m_entity->render != nullptr))
                {
                    // initialize render entity
                    if (m_entity->render->VAO_ID == 0)
                    {
                        glGenVertexArrays(1, &m_entity->render->VAO_ID);
                        glBindVertexArray(m_entity->render->VAO_ID);

                        glGenBuffers(VBO::COUNT, m_entity->render->VBO_ID);
                        glBindBuffer(GL_ARRAY_BUFFER, m_entity->render->VBO_ID[VBO::VERTEX]);
                        glBufferData(GL_ARRAY_BUFFER, m_entity->render->mesh->indexCount*sizeof(v8_f), &m_entity->render->mesh->index[0], GL_STATIC_DRAW);

                        glUseProgram(m_entity->render->shader->ID);

                        m_entity->render->MVP_ID = glGetUniformLocation(m_entity->render->shader->ID, "MVP");
                        glActiveTexture(GL_TEXTURE0);
                        glBindTexture(GL_TEXTURE_2D, m_entity->render->texture_diffuse->ID);
                        glUniform1i(getUniformLocation(m_entity->render->shader->ID, "diffuse"), 0);

                        /*
                        glActiveTexture(GL_TEXTURE1);
                        glBindTexture(GL_TEXTURE_2D, m_entity->render->texture_normal->ID);
                        glUniform1i(getUniformLocation(m_entity->render->shader->ID, "normal"), 0);
                        glActiveTexture(GL_TEXTURE2);
                        glBindTexture(GL_TEXTURE_2D, m_entity->render->texture_specular->ID);
                        glUniform1i(getUniformLocation(m_entity->render->shader->ID, "specular"), 0);
                        */

                        glEnableVertexAttribArray(0);
                        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(v8_f),(void*)nullptr);
                        glEnableVertexAttribArray(1);
                        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(v8_f),(void*)(sizeof(float)*3));
                        glEnableVertexAttribArray(2);
                        glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(v8_f),(void*)(sizeof(float)*6));

                        re_logWrite("Initializing vao: " + std::to_string(m_entity->render->VAO_ID), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
                    }
                    // Draw render entity
                    if (m_entity->render->VAO_ID != 0)
                    {
                        glBindVertexArray(m_entity->render->VAO_ID);
                        glActiveTexture(GL_TEXTURE0);
                        glBindTexture(GL_TEXTURE_2D, m_entity->render->texture_diffuse->ID);
                        glUniform1i(getUniformLocation(m_entity->render->shader->ID, "diffuse"), 0);
                        /*
                        glActiveTexture(GL_TEXTURE1);
                        glBindTexture(GL_TEXTURE_2D, m_entity->render->texture_normal->ID);
                        glUniform1i(getUniformLocation(m_entity->render->shader->ID, "normal"), 0);
                        glActiveTexture(GL_TEXTURE2);
                        glBindTexture(GL_TEXTURE_2D, m_entity->render->texture_specular->ID);
                        glUniform1i(getUniformLocation(m_entity->render->shader->ID, "specular"), 0);
                        */
                        glm::mat4 mvp = m_camera.getProjection() * m_camera.getView() * m_entity->render->Model;
                        glUniformMatrix4fv(m_entity->render->MVP_ID, 1, GL_FALSE, &mvp[0][0]);
                        glDrawArrays(GL_TRIANGLES, 0, m_entity->render->mesh->indexCount);
                    }
                }
                m_entity = m_entity->next;
            }
        }
        glfwSwapBuffers(m_window);
    }

}

