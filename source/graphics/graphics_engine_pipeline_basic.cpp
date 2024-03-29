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

void cGraphicsEngine::m_pb_createFBO(void)
{
    // Delete the FBO if it already exists
    if (m_pb_fbo != 0)
        glDeleteFramebuffers(1, &m_pb_fbo);

    // Delete any textures attached to the FBO
    if (m_pb_renderTextureID != 0)
        glDeleteTextures(1, &m_pb_renderTextureID);

    // Delete any buffers attached to the FBO
    if (m_pb_depthTextureID != 0)
        glDeleteRenderbuffers(1, &m_pb_depthTextureID);

    // Frame buffer Object
    glGenFramebuffers(1, &m_pb_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, m_pb_fbo);

    // Frame buffer color render texture
    glGenTextures(1, &m_pb_renderTextureID);
    glBindTexture(GL_TEXTURE_2D, m_pb_renderTextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_framebufferSize_w, m_framebufferSize_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_pb_renderTextureID, 0);

    // Frame buffer depth render texture
    glGenRenderbuffers(1, &m_pb_depthTextureID);
    glBindRenderbuffer(GL_RENDERBUFFER, m_pb_depthTextureID);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_framebufferSize_w, m_framebufferSize_h);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_pb_depthTextureID);

    // Set the list of draw buffers.
    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    // Unbind and check
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    checkOpenGLFrameBuffer();
}

void cGraphicsEngine::m_pb_initialize(void)
{
    // Create FBO
    m_pb_createFBO();

    // Initialize shader
    m_pb_shader.initialize();
    m_pb_shader.load("0_basic");
    glUseProgram(m_pb_shader.getID());
    m_pb_loc_modelMatrix      = m_pb_shader.getUniformLocation("modelMatrix");
    m_pb_loc_viewMatrix       = m_pb_shader.getUniformLocation("viewMatrix");
    m_pb_loc_projectionMatrix = m_pb_shader.getUniformLocation("projectionMatrix");
    m_pb_loc_materialDiffuse  = m_pb_shader.getUniformLocation("diffuse");
    m_pb_loc_animationEnabled = m_pb_shader.getUniformLocation("animationEnabled");

    m_pb_loc_time             = m_pb_shader.getUniformLocation("time");
    m_pb_loc_flexibility      = m_pb_shader.getUniformLocation("flexibility");

    m_pb_loc_billboard        = m_pb_shader.getUniformLocation("billboard");
    m_pb_loc_collision        = m_pb_shader.getUniformLocation("collision");
    m_pb_loc_mouseOver        = m_pb_shader.getUniformLocation("mouseOver");
    m_pb_loc_hasFunction      = m_pb_shader.getUniformLocation("hasFunction");
    m_pb_loc_isText           = m_pb_shader.getUniformLocation("isText");
    m_pb_loc_textColor        = m_pb_shader.getUniformLocation("textColor");

    // Bone transformation matrices
    for (std::uint32_t i = 0; i < MAX_BONES; ++i)
    {
        m_pb_loc_boneMatrix[i] = m_pb_shader.getUniformLocation("boneMatrix[" + std::to_string(i) + "]");
    }
};

void cGraphicsEngine::m_pb_terminate(void)
{
    // Terminate the shader
    m_pb_shader.terminate();

    // Delete the FBO if it exists
    if (m_pb_fbo != 0)
        glDeleteFramebuffers(1, &m_pb_fbo);

    // Delete any textures attached to the FBO
    if (m_pb_renderTextureID != 0)
        glDeleteTextures(1, &m_pb_renderTextureID);

    // Delete any buffers attached to the FBO
    if (m_pb_depthTextureID != 0)
        glDeleteRenderbuffers(1, &m_pb_depthTextureID);
};

void cGraphicsEngine::m_pb_render(void)
{
    // Setup the framebuffer
    glViewport(0, 0, m_framebufferSize_w, m_framebufferSize_h);
    glBindFramebuffer(GL_FRAMEBUFFER, m_pb_fbo);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup shader, uniforms
    glUseProgram(m_pb_shader.getID());
    glUniformMatrix4fv(m_pb_loc_viewMatrix,        1, GL_FALSE, glm::value_ptr(m_camera.getViewMatrix()));
    glUniformMatrix4fv(m_pb_loc_projectionMatrix,  1, GL_FALSE, glm::value_ptr(m_camera.getProjectionMatrix()));
    glUniform1i(m_pb_loc_materialDiffuse, 0);

    glUniform1f(m_pb_loc_time, m_time);

    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityTemp->base.inRnge) && (m_entityTemp->base.enabled) && (m_entityTemp->graphics != nullptr) && (m_entityTemp->graphics->model != nullptr))
        {
            // Shader uniforms
            glUniform1i(m_pb_loc_billboard, (m_entityTemp->graphics->billboard) ? 1 : 0);
            glUniform1f(m_pb_loc_flexibility, m_entityTemp->base.flexibility * m_map->info.windSpeed);

            // Mouse over
            if (m_entityTemp->physics != nullptr)
            {
                glUniform1i(m_pb_loc_mouseOver, (m_entityTemp->physics->mouseOver) ? 1 : 0);
            }
            else
            {
                glUniform1i(m_pb_loc_mouseOver, 0);
            }

            // Debug
            if ((m_entityTemp->physics != nullptr) && (m_renderDebug))
            {
                glUniform1i(m_pb_loc_collision, (m_entityTemp->physics->collision) ? 1 : 0);
                glUniform1i(m_pb_loc_hasFunction, (m_entityTemp->base.hasFunction) ? 1 : 0);
            }
            else
            {
                glUniform1i(m_pb_loc_collision, 0);
                glUniform1i(m_pb_loc_hasFunction, 0);
            }

            // Model matrix uniform
            glUniformMatrix4fv(m_pb_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_entityTemp->graphics->modelMatrix));

            // skeletal animation uniforms for dynamic models
            if ((m_entityTemp->graphics->model->numBones > 0) && (m_animation))
            {
                // enable skinning
                glUniform1i(m_pb_loc_animationEnabled, 1);

                // bone transforms
                if ((m_entityTemp->animation != nullptr) && (m_entityTemp->animation->animationIndependent))
                {
                    for (std::size_t i = 0; i < m_entityTemp->animation->numBones; ++i)
                    {
                        glUniformMatrix4fv(m_pb_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->animation->boneTransform[i]));
                    }
                }
                else
                {
                    for (std::size_t i = 0; i < m_entityTemp->graphics->model->numBones; ++i)
                    {
                        glUniformMatrix4fv(m_pb_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->graphics->model->bone[i].transformFinal));
                    }
                }
            }
            else // no bones
            {
                // disable skinning
                glUniform1i(m_pb_loc_animationEnabled, 0);
            }

            // Model
            for (std::uint32_t i = 0; i < m_entityTemp->graphics->model->numMesh; ++i)
            {
                if ((m_entityTemp->graphics->model->mesh[i].enabled) &&
                    (m_entityTemp->graphics->model->mesh[i].VAO != 0))
                {
                    // Use textures
                    if (m_entityTemp->graphics->material != nullptr)
                    {
                        glActiveTexture(GL_TEXTURE0);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->graphics->material[i % m_entityTemp->graphics->numMaterial]->diffuse->ID);
                    }

                    // VAO
                    glBindVertexArray(m_entityTemp->graphics->model->mesh[i].VAO);
                    if (m_wireframe)
                    {
                        glDrawElements(GL_LINE_LOOP, m_entityTemp->graphics->model->mesh[i].numIndex, GL_UNSIGNED_INT, nullptr);
                    }
                    else
                    {
                        //glDrawArrays(GL_TRIANGLES, 0, 3);
                        glDrawElements(GL_TRIANGLES, m_entityTemp->graphics->model->mesh[i].numIndex, GL_UNSIGNED_INT, nullptr);
                    }
                }
            }

            // Health bar
//            if ((m_entityTemp->physics->mouseOver) && (m_entityTemp->character != nullptr) && (m_entityTemp->character->healthBarModel != nullptr))
            if ((m_entityTemp->character != nullptr) && (m_entityTemp->character->healthBarModel != nullptr) && m_entityTemp->character->healthBarEnabled)
            {
                glUniform1i(m_pb_loc_billboard, 1);
                glUniform1i(m_pb_loc_collision, 0);
                glUniform1i(m_pb_loc_mouseOver, 0);
                glUniform1i(m_pb_loc_animationEnabled, 0);
                glUniform1i(m_pb_loc_isText, 0);

                // Model matrix uniform
                glm::mat4 billboardModelMatrix = glm::mat4(1);
                glm::mat4 billboardScaleMatrix = glm::mat4(1);
                glm::vec3 billboardPosition    = glm::vec3();
                glm::vec3 billboardScale       = glm::vec3();
                float billboardScaleRatio      = 0.865168539f;
                float billboardScaleRatioDiv   = 0.298333979f; // 0.865168539f / 2.9;

                // Model
                if (m_entityTemp->character->healthBarModel->mesh[0].VAO != 0)
                {
                    glBindVertexArray(m_entityTemp->character->healthBarModel->mesh[0].VAO);
                    glActiveTexture(GL_TEXTURE0);

                    // Health bar background
                    billboardPosition.x = m_entityTemp->base.position.x - 0.001f;
                    billboardPosition.y = m_entityTemp->base.position.y + m_entityTemp->character->healthBarOffset;
                    billboardPosition.z = m_entityTemp->base.position.z - 0.001f;
                    billboardModelMatrix = glm::translate(glm::mat4(1), billboardPosition);
                    billboardScale       = glm::vec3(billboardScaleRatio * m_entityTemp->character->healthBarScale.x, 1.0f * m_entityTemp->character->healthBarScale.y, 1.0f);
                    billboardScaleMatrix = glm::scale(glm::mat4(1), billboardScale);
                    billboardModelMatrix = billboardModelMatrix * billboardScaleMatrix;
                    glUniformMatrix4fv(m_pb_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(billboardModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, m_entityTemp->character->healthBarmaterial[0]->specular->ID);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->character->healthBarModel->mesh[0].numIndex, GL_UNSIGNED_INT, nullptr);

                    // Health bar
                    float factor = m_entityTemp->character->attribute.health.current.amount / m_entityTemp->character->attribute.health.current.max;
                    float offset = ((billboardScaleRatioDiv) * factor * m_entityTemp->character->healthBarScale.x) - (billboardScaleRatioDiv * m_entityTemp->character->healthBarScale.x);
                    billboardPosition.x = m_entityTemp->base.position.x + offset;
                    billboardPosition.y = m_entityTemp->base.position.y + m_entityTemp->character->healthBarOffset;
                    billboardPosition.z = m_entityTemp->base.position.z - offset;
                    billboardModelMatrix = glm::translate(glm::mat4(1), billboardPosition);
                    billboardScale       = glm::vec3(billboardScaleRatio * factor * m_entityTemp->character->healthBarScale.x, 1.0f * m_entityTemp->character->healthBarScale.y, 1.0f);
                    billboardScaleMatrix = glm::scale(glm::mat4(1), billboardScale);
                    billboardModelMatrix = billboardModelMatrix * billboardScaleMatrix;
                    glUniformMatrix4fv(m_pb_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(billboardModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, m_entityTemp->character->healthBarmaterial[0]->normal->ID);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->character->healthBarModel->mesh[0].numIndex, GL_UNSIGNED_INT, nullptr);

                    // Health bar cover
                    billboardPosition.x = m_entityTemp->base.position.x + 0.001f;
                    billboardPosition.y = m_entityTemp->base.position.y + m_entityTemp->character->healthBarOffset;
                    billboardPosition.z = m_entityTemp->base.position.z + 0.001f;
                    billboardModelMatrix = glm::translate(glm::mat4(1), billboardPosition);
                    billboardScale       = glm::vec3(1.0f * m_entityTemp->character->healthBarScale.x, 1.0f * m_entityTemp->character->healthBarScale.y, 1.0f);
                    billboardScaleMatrix = glm::scale(glm::mat4(1), billboardScale);
                    billboardModelMatrix = billboardModelMatrix * billboardScaleMatrix;
                    glUniformMatrix4fv(m_pb_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(billboardModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, m_entityTemp->character->healthBarmaterial[0]->diffuse->ID);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->character->healthBarModel->mesh[0].numIndex, GL_UNSIGNED_INT, nullptr);
                }
            }

            // Tooltip
            if ((m_entityTemp->base.textActive != 0) && (m_pc_bbq_VAO != 0))
            {
                if ((m_entityTemp->physics->mouseOver != 0) || (m_io->keyMap[GLFW_KEY_LEFT_ALT]))
                {
                    glEnable(GL_BLEND);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                    glUniform1i(m_pb_loc_billboard, 1);
                    glUniform1i(m_pb_loc_collision, 0);
                    glUniform1i(m_pb_loc_mouseOver, 0);
                    glUniform1i(m_pb_loc_animationEnabled, 0);
                    glUniform1i(m_pb_loc_isText, 1);

                    glUniform4f(m_pb_loc_textColor,
                                m_entityTemp->base.textColor.x,
                                m_entityTemp->base.textColor.y,
                                m_entityTemp->base.textColor.z,
                                1.0);

                    // Model matrix uniform
                    glm::mat4 tooltipModelMatrix = glm::mat4(1);
                    glm::mat4 tooltipScaleMatrix = glm::mat4(1);
                    glm::vec3 tooltipPosition    = glm::vec3(0.001f, 0.001f, 0.001f);

                    glBindVertexArray(m_pc_bbq_VAO);
                    glActiveTexture(GL_TEXTURE0);

                    sTexture* texture = m_resourceManager->generateTexture(m_entityTemp->base.textData);

                    // Scale
                    float scale  = 2.0f;
                    float scaleX = static_cast<float>(m_framebufferSize_w) / 1920.0f * static_cast<float>(texture->width) * scale / static_cast<float>(m_framebufferSize_w);
                    float scaleY = static_cast<float>(m_framebufferSize_h) / 1080.0f * static_cast<float>(texture->height) * scale / static_cast<float>(m_framebufferSize_h);

                    // position
                    tooltipPosition.x = m_entityTemp->base.position.x;
                    tooltipPosition.y = m_entityTemp->base.position.y + (m_entityTemp->physics->halfDimentions.y * 4);
                    tooltipPosition.z = m_entityTemp->base.position.z;
                    tooltipModelMatrix = glm::translate(glm::mat4(1), tooltipPosition);
                    tooltipScaleMatrix = glm::scale(glm::mat4(1), glm::vec3(scaleX, scaleY, 1.0f));
                    tooltipModelMatrix = tooltipModelMatrix * tooltipScaleMatrix;
                    glUniformMatrix4fv(m_pb_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(tooltipModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, texture->ID);
                    glDrawArrays(GL_TRIANGLES, 0, 6);

                    glUniform1i(m_pb_loc_isText, 0);
                }
            }
        }
    }
};
