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
    if (m_basicRender)
    {
        glBindTexture(GL_TEXTURE_2D, m_pb_renderTextureID);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, m_p3_renderTextureID);
    }
    glBindVertexArray(m_pui_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);


    // menu
    sUIMenu* menu = m_UIManager->getMenu();

    // render each ui menu
    for (std::uint32_t m = 0; m < m_UIManager->getNumMenu(); ++m)
    {
        if (menu[m].enabled)
        {
            // Shader uniforms
            m_pui_modelMatrix = glm::mat4(1);
            m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, menu[m].position);
            m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, glm::vec3(menu[m].scale.x, menu[m].scale.y, 1.0f));
            glUniformMatrix4fv(m_pui_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pui_modelMatrix));

            if (m_pui_VAO != 0)
            {
                // Texture
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, menu[m].textureNormal->ID);

                // VAO
                glBindVertexArray(m_pui_VAO);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }

            // render each ui menu's ui components
            for (std::uint32_t c = 0; c < menu[m].numComponent; ++c)
            {
                // Shader uniforms
                m_pui_modelMatrix = glm::mat4(1);
                // Health bar
                if (menu[m].component[c].function == eComponentFunction::componentFunctionBarHealth)
                {
                    float     percent  = static_cast<float>(m_entityPlayer->character->attributes.health.current) / static_cast<float>(m_entityPlayer->character->attributes.health.max);
                    glm::vec3 scaleVec = glm::vec3(menu[m].component[c].scale.x * percent, menu[m].component[c].scale.y, 1.0f);
                    glm::vec3 position = menu[m].component[c].position;
                    position.x -= menu[m].component[c].size.x * (1.0f - percent);
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, scaleVec);
                }
                // Mana bar
                else if (menu[m].component[c].function == eComponentFunction::componentFunctionBarMana)
                {
                    float     percent  = static_cast<float>(m_entityPlayer->character->attributes.mana.current) / static_cast<float>(m_entityPlayer->character->attributes.mana.max);
                    glm::vec3 scaleVec = glm::vec3(menu[m].component[c].scale.x * percent, menu[m].component[c].scale.y, 1.0f);
                    glm::vec3 position = menu[m].component[c].position;
                    position.x += menu[m].component[c].size.x * (1.0f - percent);
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, scaleVec);
                }
                // Experience bar
                else if (menu[m].component[c].function == eComponentFunction::componentFunctionBarExp)
                {
                    float     percent  = static_cast<float>(m_entityPlayer->character->level.exp) / static_cast<float>(m_entityPlayer->character->level.expNext);
                    glm::vec3 scaleVec = glm::vec3(menu[m].component[c].scale.x * percent, menu[m].component[c].scale.y, 1.0f);
                    glm::vec3 position = menu[m].component[c].position;
                    position.x -= menu[m].component[c].size.x * (1.0f - percent);
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, scaleVec);
                }
                // Volume master bar
                else if (menu[m].component[c].function == eComponentFunction::componentFunctionVolumeMasterBar)
                {
                    float     percent  = static_cast<float>(m_GameConfig->m_volume_master) / static_cast<float>(m_GameConfig->m_volume_max);
                    glm::vec3 scaleVec = glm::vec3(menu[m].component[c].scale.x * percent, menu[m].component[c].scale.y, 1.0f);
                    glm::vec3 position = menu[m].component[c].position;
                    position.x -= menu[m].component[c].size.x * (1.0f - percent);
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, scaleVec);
                }
                // Volume music bar
                else if (menu[m].component[c].function == eComponentFunction::componentFunctionVolumeMusicBar)
                {
                    float     percent  = static_cast<float>(m_GameConfig->m_volume_music) / static_cast<float>(m_GameConfig->m_volume_max);
                    glm::vec3 scaleVec = glm::vec3(menu[m].component[c].scale.x * percent, menu[m].component[c].scale.y, 1.0f);
                    glm::vec3 position = menu[m].component[c].position;
                    position.x -= menu[m].component[c].size.x * (1.0f - percent);
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, scaleVec);
                }
                // Volume sound bar
                else if (menu[m].component[c].function == eComponentFunction::componentFunctionVolumeSoundBar)
                {
                    float     percent  = static_cast<float>(m_GameConfig->m_volume_sfx) / static_cast<float>(m_GameConfig->m_volume_max);
                    glm::vec3 scaleVec = glm::vec3(menu[m].component[c].scale.x * percent, menu[m].component[c].scale.y, 1.0f);
                    glm::vec3 position = menu[m].component[c].position;
                    position.x -= menu[m].component[c].size.x * (1.0f - percent);
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, scaleVec);
                }
                else
                {
                    m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, menu[m].component[c].position);
                    m_pui_modelMatrix = glm::scale(m_pui_modelMatrix, glm::vec3(menu[m].component[c].scale.x, menu[m].component[c].scale.y, 1.0f));
                }
                glUniformMatrix4fv(m_pui_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pui_modelMatrix));

                if (m_pui_VAO != 0)
                {
                    // Texture
                    glActiveTexture(GL_TEXTURE0);
                    
                    if (menu[m].component[c].state == eComponentState::componentActivated)
                    {
                        glBindTexture(GL_TEXTURE_2D, menu[m].component[c].textureActive->ID);
                    }
                    else if (menu[m].component[c].state == eComponentState::componentHover)
                    {
                        glBindTexture(GL_TEXTURE_2D, menu[m].component[c].textureHover->ID);
                    }
                    else
                    {
                        glBindTexture(GL_TEXTURE_2D, menu[m].component[c].textureNormal->ID);
                    }

                    // VAO
                    glBindVertexArray(m_pui_VAO);
                    glDrawArrays(GL_TRIANGLES, 0, 6);
                }
            }
        }
    }
}
