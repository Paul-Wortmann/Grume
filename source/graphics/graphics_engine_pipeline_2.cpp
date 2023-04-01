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

void cGraphicsEngine::m_p2_createFBO(void)
{
    // Delete the FBOs if they already exists
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        // Delete the FBO
        if ((m_p2_fbo != nullptr) && (m_p2_fbo[i] != 0))
            glDeleteFramebuffers(1, &m_p2_fbo[i]);

        // Delete any textures attached to the FBO
        if (m_p2_depthCubemapID[i] != 0)
            glDeleteTextures(1, &m_p2_depthCubemapID[i]);
    }

    // Create FBOs
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        // Frame buffer Object
        glGenFramebuffers(1, &m_p2_fbo[i]);
        glBindFramebuffer(GL_FRAMEBUFFER, m_p2_fbo[i]);

        // Depth cube map texture
        glGenTextures(1, &m_p2_depthCubemapID[i]);
        glBindTexture(GL_TEXTURE_CUBE_MAP, m_p2_depthCubemapID[i]);
        for (std::uint32_t j = 0; j < 6; ++j) // Cube has 6 faces
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + j, 0, GL_DEPTH_COMPONENT, m_renderBufferSize_w, m_renderBufferSize_h, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
        }

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, m_p2_depthCubemapID[i], 0);
        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        checkOpenGLFrameBuffer();
    }
}

void cGraphicsEngine::m_p2_initialize(void)
{
    // Create the FBOs
    m_p2_createFBO();

    // Initialize shader
    m_p2_shader.initialize();
    m_p2_shader.load("2_pointShadow");
    glUseProgram(m_p2_shader.getID());
    m_p2_loc_modelMatrix       = m_p2_shader.getUniformLocation("modelMatrix");
    m_p2_loc_lightPosition     = m_p2_shader.getUniformLocation("lightPosition");
    m_p2_loc_farPlane          = m_p2_shader.getUniformLocation("farPlane");
    m_p2_loc_animationEnabled  = m_p2_shader.getUniformLocation("animationEnabled");

    m_p2_loc_time             = m_p2_shader.getUniformLocation("time");
    m_p2_loc_flexibility      = m_p2_shader.getUniformLocation("flexibility");

    // Bone transformation matrices
    for (std::uint32_t i = 0; i < MAX_BONES; ++i)
    {
        m_p2_loc_boneMatrix[i] = m_p2_shader.getUniformLocation("boneMatrix[" + std::to_string(i) + "]");
    }

    // Depth matrices
    for (std::uint32_t i = 0; i < 6; ++i)
    {
        m_p2_loc_depthMatrix[i] = m_p2_shader.getUniformLocation("depthMatrix[" + std::to_string(i) + "]");
    }
};

void cGraphicsEngine::m_p2_terminate(void)
{
    // Terminate the shader
    m_p2_shader.terminate();

    // Delete the FBOs if they exists
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        // Delete the FBO
        if ((m_p2_fbo != nullptr) && (m_p2_fbo[i] != 0))
            glDeleteFramebuffers(1, &m_p2_fbo[i]);

        // Delete any textures attached to the FBO
        if (m_p2_depthCubemapID[i] != 0)
            glDeleteTextures(1, &m_p2_depthCubemapID[i]);
    }
};

void cGraphicsEngine::m_p2_render(void)
{
    // Process point lights
    if (m_lightManager.getCount() > 0)
    {
        std::uint32_t lightCount = 0;
        for(sGraphicsEnginePointLight* tLight = m_lightManager.getHead(); tLight != nullptr; tLight = tLight->next)
        {
            if (tLight->enabled > 0)
            {
                // Setup the framebuffer
                glViewport(0, 0, m_renderBufferSize_w, m_renderBufferSize_h);
                glBindFramebuffer(GL_FRAMEBUFFER, m_p2_fbo[lightCount]);
                glClear(GL_DEPTH_BUFFER_BIT);

                // Use shader
                glUseProgram(m_p2_shader.getID());

                // Time
                glUniform1f(m_p2_loc_time, m_time);

                // Light transform matrices
                m_p2_lightPosition = tLight->position;
                m_p2_depthProjectionMatrix = glm::perspective(glm::radians(90.0f), m_p2_aspectRatio, m_p2_nearPlane, m_p2_farPlane);

                m_p2_depthMatrix[0] = (m_p2_depthProjectionMatrix * glm::lookAt(m_p2_lightPosition, m_p2_lightPosition + glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3( 0.0f, -1.0f,  0.0f)));
                m_p2_depthMatrix[1] = (m_p2_depthProjectionMatrix * glm::lookAt(m_p2_lightPosition, m_p2_lightPosition + glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3( 0.0f, -1.0f,  0.0f)));
                m_p2_depthMatrix[2] = (m_p2_depthProjectionMatrix * glm::lookAt(m_p2_lightPosition, m_p2_lightPosition + glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec3( 0.0f,  0.0f,  1.0f)));
                m_p2_depthMatrix[3] = (m_p2_depthProjectionMatrix * glm::lookAt(m_p2_lightPosition, m_p2_lightPosition + glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3( 0.0f,  0.0f, -1.0f)));
                m_p2_depthMatrix[4] = (m_p2_depthProjectionMatrix * glm::lookAt(m_p2_lightPosition, m_p2_lightPosition + glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3( 0.0f, -1.0f,  0.0f)));
                m_p2_depthMatrix[5] = (m_p2_depthProjectionMatrix * glm::lookAt(m_p2_lightPosition, m_p2_lightPosition + glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3( 0.0f, -1.0f,  0.0f)));

                for (std::uint32_t i = 0; i < 6; ++i)
                {
                    glUniformMatrix4fv(m_p2_loc_depthMatrix[i], 1, GL_FALSE, glm::value_ptr(m_p2_depthMatrix[i]));
                }

                // Set uniform locations
                glUniform1f(m_p2_loc_farPlane, m_p2_farPlane);

                glUniform3fv(m_p2_loc_lightPosition, 1, glm::value_ptr(m_p2_lightPosition));

                // Textures
                //glActiveTexture(GL_TEXTURE0);
                //glBindTexture(GL_TEXTURE_CUBE_MAP, m_p2_depthCubemapID);

                lightCount++;

                // Entities
                for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
                {
                    if ((m_entityTemp != nullptr) && (m_entityTemp->base.inRnge) && (m_entityTemp->base.enabled) && (m_entityTemp->graphics != nullptr) && (m_entityTemp->graphics->model != nullptr) && (m_entityTemp->graphics->billboard == false))
                    {
                        if ((lightCount == 1) && (m_entityTemp->base.name.compare("player") == 0));
                        else
                        {
                            // Shader uniforms
                            glUniformMatrix4fv(m_p2_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_entityTemp->graphics->modelMatrix));

                            // Flexibility
                            glUniform1f(m_p2_loc_flexibility, m_entityTemp->base.flexibility * m_map->info.windSpeed);

                            // skeletal animation uniforms for dynamic models
                            if (m_entityTemp->graphics->model->numBones > 0)
                            {
                                // enable skinning
                                glUniform1i(m_p2_loc_animationEnabled, 1);

                                // bone transforms
                                if ((m_entityTemp->animation != nullptr) && (m_entityTemp->animation->animationIndependent))
                                {
                                    for (std::size_t i = 0; i < m_entityTemp->animation->numBones; ++i)
                                    {
                                        glUniformMatrix4fv(m_p2_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->animation->boneTransform[i]));
                                    }
                                }
                                else
                                {
                                    for (std::size_t i = 0; i < m_entityTemp->graphics->model->numBones; ++i)
                                    {
                                        glUniformMatrix4fv(m_p2_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->graphics->model->bone[i].transformFinal));
                                    }
                                }
                            }
                            else // no bones
                            {
                                // disable skinning
                                glUniform1i(m_p2_loc_animationEnabled, 0);
                            }

                            // Model
                            for (std::uint32_t j = 0; j < m_entityTemp->graphics->model->numMesh; ++j)
                            {
                                if ((m_entityTemp->graphics->model->mesh[j].enabled) &&
                                    (m_entityTemp->graphics->model->mesh[j].VAO != 0))
                                {
                                    // Texture
                                    //glActiveTexture(GL_TEXTURE0);

                                    // VAO
                                    glBindVertexArray(m_entityTemp->graphics->model->mesh[j].VAO);
                                    glDrawElements(GL_TRIANGLES, m_entityTemp->graphics->model->mesh[j].numIndex, GL_UNSIGNED_INT, nullptr);
                                }
                            }
                        }
                    }
                }
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
            }
        }
    }
};
