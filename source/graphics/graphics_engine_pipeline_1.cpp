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

#include "graphics_engine.hpp"

void cGraphicsEngine::m_p1_initialize(void)
{
    // Initialize shader
    m_p1_shader.initialize();
    m_p1_shader.load("1_directionalShadow");
    glUseProgram(m_p1_shader.getID());
    m_p1_loc_modelMatrix      = m_p1_shader.getUniformLocation("modelMatrix");
    m_p1_loc_lightMatrix      = m_p1_shader.getUniformLocation("lightMatrix");
    m_p1_loc_animationEnabled = m_p1_shader.getUniformLocation("animationEnabled");

    // Bone transformation matrices
    for (uint32 i = 0; i < MAX_BONES; ++i)
    {
        m_p1_loc_boneMatrix[i] = m_p1_shader.getUniformLocation("boneMatrix[" + std::to_string(i) + "]");
    }
    
    m_p1_projectionMatrix = glm::ortho(-25.0f, 25.0f, -25.0f, 25.0f, -1.0f, 25.0f);
    m_p1_viewMatrix = glm::lookAt(m_camera.getPosition(), m_camera.getTarget(), m_camera.getOrientation());
    //glm::mat4 lightView = glm::lookAt(m_lightManager.directionalLight.direction, m_camera.getTarget(), m_camera.getOrientation());
    //glm::mat4 lightView = glm::mat4(1);
    m_p1_lightMatrix = m_p1_projectionMatrix * m_p1_viewMatrix; 

    // Frame buffer Object
    glGenFramebuffers(1, &m_p1_fbo);
    
    // Depth map texture
    glGenTextures(1, &m_p1_depthMapID);
    glBindTexture(GL_TEXTURE_2D, m_p1_depthMapID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, m_renderBufferSize_w, m_renderBufferSize_h, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float32 borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    
    // Attach the shadow map to the frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_p1_fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_p1_depthMapID, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
};

void cGraphicsEngine::m_p1_terminate(void)
{
    m_p1_shader.terminate();
    glDeleteFramebuffers(1, &m_p1_fbo);
};

void cGraphicsEngine::m_p1_render(void)
{
    // Setup the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_p1_fbo);
    glViewport(0, 0, m_renderBufferSize_w, m_renderBufferSize_h);
    glClear(GL_DEPTH_BUFFER_BIT);
    glCullFace(GL_FRONT);

    // Setup shader, uniforms
    glUseProgram(m_p1_shader.getID());

    // Setup the light view matrix
    //glm::vec3 lightInverseDirection = m_lightManager.directionalLight.direction * glm::vec3(-1.0f, -1.0f, -1.0f);
    glm::vec3 lightInverseDirection = m_lightManager.directionalLight.direction;
    m_p1_viewMatrix = glm::lookAt(lightInverseDirection, glm::vec3(0.0f, 0.0f, 0.0f), m_camera.getOrientation());
    m_p1_lightMatrix = m_p1_projectionMatrix * m_p1_viewMatrix; 
    glUniformMatrix4fv(m_p1_loc_lightMatrix, 1, GL_FALSE, glm::value_ptr(m_p1_lightMatrix));

    // Textures
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_p1_depthMapID);
    
    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityTemp->model != nullptr))
        {
            // Shader uniforms
            glUniformMatrix4fv(m_p1_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_entityTemp->modelMatrix));

            // skeletal animation uniforms for dynamic models
            if (m_entityTemp->model->numBones > 0)
            {
                // enable skinning
                glUniform1i(m_p1_loc_animationEnabled, 1);

                // bone transforms
                if (m_entityTemp->animationIndependent)
                {
                    for (std::size_t i = 0; i < m_entityTemp->numBones; ++i)
                    {
                        glUniformMatrix4fv(m_p1_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->boneTransform[i]));
                    }
                }
                else
                {
                    for (std::size_t i = 0; i < m_entityTemp->model->numBones; ++i)
                    {
                        glUniformMatrix4fv(m_p1_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->model->bone[i].transformFinal));
                    }
                }
            }
            else // no bones
            {
                // disable skinning
                glUniform1i(m_p1_loc_animationEnabled, 0);
            }

            // Model
            for (uint32 j = 0; j < m_entityTemp->model->numMesh; ++j)
            {
                if (m_entityTemp->model->mesh[j].VAO != 0)
                {
                    // Texture
                    //glActiveTexture(GL_TEXTURE0);
                    
                    // VAO
                    glBindVertexArray(m_entityTemp->model->mesh[j].VAO);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->model->mesh[j].numIndex, GL_UNSIGNED_INT, nullptr);
                }
            }
        }
    }
    glCullFace(GL_BACK);
};