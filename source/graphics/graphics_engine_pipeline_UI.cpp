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

#include "graphics_engine.hpp"

void cGraphicsEngine::m_pui_initialize(void)
{
    // Initialize shader
    m_pui_shader.initialize();
    m_pui_shader.load("ui_last");
    m_pui_loc_diffuseMap = m_pui_shader.getUniformLocation("diffuseMap");
    m_pui_loc_modelMatrix = m_pui_shader.getUniformLocation("modelMatrix");

    // setup quad
    float quadVertices[] = 
    {
        // pos.xyz + tex.uv
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f,

        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
    };

    // setup the VAO and VBO
    glGenVertexArrays(1, &m_pui_VAO);
    glGenBuffers(1, &m_pui_VBO);
    glBindVertexArray(m_pui_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_pui_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
};

void cGraphicsEngine::m_pui_terminate(void)
{
    m_pui_shader.terminate();
};

void cGraphicsEngine::m_pui_render(void)
{
    // Setup the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_pui_fbo);
    glViewport(0, 0, m_framebufferSize_w, m_framebufferSize_h);
    // Dont clear the buffers, just draw the UI on top.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup shader, uniforms
    glUseProgram(m_pui_shader.getID());

    // Shader uniforms
    m_pui_modelMatrix = glm::mat4(1);
    glUniformMatrix4fv(m_pui_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pui_modelMatrix));

    // Texture locations
    glUniform1i(m_pui_loc_diffuseMap, GL_TEXTURE0);
    glActiveTexture(GL_TEXTURE0);

    // Render previous stage texture as background
    glBindTexture(GL_TEXTURE_2D, m_p3_renderTextureID);
    glBindVertexArray(m_pui_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);


    // menu
    sUIMenu* menu = m_UIManager->getMenu();
    glm::vec3 tPosition = glm::vec3(0.0f, 0.0f, -0.01f);

    // render each ui menu
    for (std::uint32_t m = 0; m < m_UIManager->getNumMenu(); ++m)
    {
        // render each ui menu's ui components
        for (std::uint32_t c = 0; c < menu[m].numComponent; ++c)
        {
            // Shader uniforms
            m_pui_modelMatrix = glm::mat4(1);
            m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, glm::vec3(menu[m].component[c].scale.x, menu[m].component[c].scale.y, 1.0f));
            m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, menu[m].component[c].position);
            glUniformMatrix4fv(m_pui_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pui_modelMatrix));

            if (m_pui_VAO != 0)
            {
                // Texture
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, menu[m].component[c].textureNormal->ID);

                // VAO
                glBindVertexArray(m_pui_VAO);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }
        }
    }

}
