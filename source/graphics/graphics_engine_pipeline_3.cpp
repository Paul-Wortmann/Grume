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

void cGraphicsEngine::m_p3_initialize(void)
{
    // Frame buffer Object
    glGenFramebuffers(1, &m_p3_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, m_p3_fbo);

    // Frame buffer color render texture
    glGenTextures(1, &m_p3_renderTextureID);
    glBindTexture(GL_TEXTURE_2D, m_p3_renderTextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_framebufferSize_w, m_framebufferSize_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_p3_renderTextureID, 0);

    // Frame buffer depth render texture
    glGenRenderbuffers(1, &m_p3_depthTextureID);
    glBindRenderbuffer(GL_RENDERBUFFER, m_p3_depthTextureID);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_framebufferSize_w, m_framebufferSize_h);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_p3_depthTextureID);

    // Set the list of draw buffers.
    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    // Unbind and check
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    checkOpenGLFrameBuffer();

    // Initialize shader
    m_p3_shader.initialize();
    m_p3_shader.load("3_lighting");
    glUseProgram(m_p3_shader.getID());

    // Shader uniforms -------------------------------
    m_p3_loc_billboard              = m_p3_shader.getUniformLocation("billboard");
    m_p3_loc_collision              = m_p3_shader.getUniformLocation("collision");
    m_p3_loc_mouseOver              = m_p3_shader.getUniformLocation("mouseOver");
    m_p3_loc_hasFunction            = m_p3_shader.getUniformLocation("hasFunction");
    m_p3_loc_isText                 = m_p3_shader.getUniformLocation("isText");
    m_p3_loc_textColor              = m_p3_shader.getUniformLocation("textColor");

    m_p3_loc_time                   = m_p3_shader.getUniformLocation("time");
    m_p3_loc_flexibility            = m_p3_shader.getUniformLocation("flexibility");

    // Vertex shader -----------------------------

    // View and transform
    m_p3_loc_projectionMatrix       = m_p3_shader.getUniformLocation("projectionMatrix");
    m_p3_loc_viewMatrix             = m_p3_shader.getUniformLocation("viewMatrix");
    m_p3_loc_modelMatrix            = m_p3_shader.getUniformLocation("modelMatrix");
    m_p3_loc_directionalLightMatrix = m_p3_shader.getUniformLocation("directionalLightMatrix");
    m_p3_loc_camera                 = m_p3_shader.getUniformLocation("cameraPosition");
    m_p3_loc_animationEnabled       = m_p3_shader.getUniformLocation("animationEnabled");

    // Lights
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        m_lightManager.uniformLocationPoint[i].position  = m_p3_shader.getUniformLocation("lightPosition[" + std::to_string(i) + "]");
    }

    // Bone transformation matrices
    for (std::uint32_t i = 0; i < MAX_BONES; ++i)
    {
        m_p3_loc_boneMatrix[i] = m_p3_shader.getUniformLocation("boneMatrix[" + std::to_string(i) + "]");
    }

    // Fragment shader -----------------------------

    // Shadow
    m_p3_loc_farPlane          = m_p3_shader.getUniformLocation("farPlane");

    // Material locations
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        m_p3_loc_materialDepthCube[i] = m_p3_shader.getUniformLocation("material.depthCube[" + std::to_string(i) + "]");
    }
    m_p3_loc_materialDepth     = m_p3_shader.getUniformLocation("material.depthMap");
    m_p3_loc_materialDiffuse   = m_p3_shader.getUniformLocation("material.diffuse");
    m_p3_loc_materialNormal    = m_p3_shader.getUniformLocation("material.normal");
    m_p3_loc_materialSpecular  = m_p3_shader.getUniformLocation("material.specular");
    m_p3_loc_materialShininess = m_p3_shader.getUniformLocation("material.shininess");

    // Directional light
    m_lightManager.uniformLocationDirectional.enabled   = m_p3_shader.getUniformLocation("directionalLight.enabled");

    m_lightManager.uniformLocationDirectional.ambient   = m_p3_shader.getUniformLocation("directionalLight.ambient");
    m_lightManager.uniformLocationDirectional.diffuse   = m_p3_shader.getUniformLocation("directionalLight.diffuse");
    m_lightManager.uniformLocationDirectional.specular  = m_p3_shader.getUniformLocation("directionalLight.specular");

    m_lightManager.uniformLocationDirectional.direction = m_p3_shader.getUniformLocation("directionalLight.direction");

    // Point Lights
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        m_lightManager.uniformLocationPoint[i].enabled   = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].enabled");

        m_lightManager.uniformLocationPoint[i].ambient   = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].ambient");
        m_lightManager.uniformLocationPoint[i].diffuse   = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].diffuse");
        m_lightManager.uniformLocationPoint[i].specular  = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].specular");

        m_lightManager.uniformLocationPoint[i].constant  = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].constant");
        m_lightManager.uniformLocationPoint[i].linear    = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].linear");
        m_lightManager.uniformLocationPoint[i].quadratic = m_p3_shader.getUniformLocation("pointLight[" + std::to_string(i) + "].quadratic");
    }
};

void cGraphicsEngine::m_p3_terminate(void)
{
    m_p3_shader.terminate();
};

void cGraphicsEngine::m_p3_setLightUniformLocations(void)
{
    // Texture locations
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        glUniform1i(m_p3_loc_materialDepthCube[i], i);
    }
    glUniform1i(m_p3_loc_materialDepth,     MAX_POINT_LIGHTS + 0);
    glUniform1i(m_p3_loc_materialDiffuse,   MAX_POINT_LIGHTS + 1);
    glUniform1i(m_p3_loc_materialNormal,    MAX_POINT_LIGHTS + 2);
    glUniform1i(m_p3_loc_materialSpecular,  MAX_POINT_LIGHTS + 3);

    // Shadow
    glUniform1f(m_p3_loc_farPlane, m_p2_farPlane);

    // Directional light
    glUniform1i (m_lightManager.uniformLocationDirectional.enabled     , m_lightManager.directionalLight.enabled);
    glUniform3fv(m_lightManager.uniformLocationDirectional.ambient,   1, glm::value_ptr(m_lightManager.directionalLight.ambient));
    glUniform3fv(m_lightManager.uniformLocationDirectional.diffuse,   1, glm::value_ptr(m_lightManager.directionalLight.diffuse));
    glUniform3fv(m_lightManager.uniformLocationDirectional.specular,  1, glm::value_ptr(m_lightManager.directionalLight.specular));
    glUniform3fv(m_lightManager.uniformLocationDirectional.direction, 1, glm::value_ptr(m_lightManager.directionalLight.direction));

    // Ensure all point lights are initially disabled
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        glUniform1i (m_lightManager.uniformLocationPoint[i].enabled, 0);
    }

    // Process point lights
    if (m_lightManager.getCount() > 0)
    {
        std::uint32_t lightCount = 0;
        for(sGraphicsEnginePointLight* tLight = m_lightManager.getHead(); tLight != nullptr; tLight = tLight->next)
        {
            if (tLight->enabled > 0)
            {
                glUniform1i(m_lightManager.uniformLocationPoint[lightCount].enabled , tLight->enabled);
                glUniform3f(m_lightManager.uniformLocationPoint[lightCount].position, tLight->position.x, tLight->position.y, tLight->position.z);

                glUniform1f(m_lightManager.uniformLocationPoint[lightCount].constant , tLight->constant);
                glUniform1f(m_lightManager.uniformLocationPoint[lightCount].linear   , tLight->linear);
                glUniform1f(m_lightManager.uniformLocationPoint[lightCount].quadratic, tLight->quadratic);

                glUniform3f(m_lightManager.uniformLocationPoint[lightCount].ambient  , tLight->ambient.x,  tLight->ambient.y,  tLight->ambient.z);
                glUniform3f(m_lightManager.uniformLocationPoint[lightCount].diffuse  , tLight->diffuse.x,  tLight->diffuse.y,  tLight->diffuse.z);
                glUniform3f(m_lightManager.uniformLocationPoint[lightCount].specular , tLight->specular.x, tLight->specular.y, tLight->specular.z);

                lightCount++;

                // Break out of the for loop if there are more lights in the linked list than are supported by the shader
                // Log as a warning
                if (lightCount >= MAX_POINT_LIGHTS)
                {
                    if (!m_lightManager.limitReached)
                    {
                        gLogWrite(LOG_WARNING, "There are more lights than supported.", __FILE__, __LINE__, __FUNCTION__);
                        m_lightManager.limitReached = true;
                    }
                    break;
                }
            }
        }
    }
}

void cGraphicsEngine::m_p3_render(void)
{
    // Setup the framebuffer
    glViewport(0, 0, m_framebufferSize_w, m_framebufferSize_h);
    glBindFramebuffer(GL_FRAMEBUFFER, m_p3_fbo);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup shader, uniforms
    glUseProgram(m_p3_shader.getID());

    // Light uniforms
    m_p3_setLightUniformLocations();

    // Time
    glUniform1f(m_p3_loc_time, m_time);

    // Shader uniforms
    glUniformMatrix4fv(m_p3_loc_viewMatrix,  1, GL_FALSE, glm::value_ptr(m_camera.getViewMatrix()));
    glUniformMatrix4fv(m_p3_loc_projectionMatrix,  1, GL_FALSE, glm::value_ptr(m_camera.getProjectionMatrix()));
    glUniformMatrix4fv(m_p3_loc_directionalLightMatrix,  1, GL_FALSE, glm::value_ptr(m_p1_lightMatrix));

    // Camera
    glUniform3fv(m_p3_loc_camera, 1, glm::value_ptr(m_camera.getPosition()));

    // Textures
    for (std::uint32_t i = 0; i < MAX_POINT_LIGHTS; ++i)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_CUBE_MAP, m_p2_depthCubemapID[i]);
    }
    glActiveTexture(GL_TEXTURE0 + MAX_POINT_LIGHTS + 0);
    glBindTexture(GL_TEXTURE_2D, m_p1_depthMapID);

    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityTemp->base.inRnge) && (m_entityTemp->base.enabled) && (m_entityTemp->graphics != nullptr) && (m_entityTemp->graphics->model != nullptr))
        {
            // Shader uniforms
            glUniform1i(m_p3_loc_billboard, (m_entityTemp->graphics->billboard) ? 1 : 0);

            // Flexibility
            glUniform1f(m_p3_loc_flexibility, m_entityTemp->base.flexibility * m_map->info.windSpeed);

            // Mouse over
            if (m_entityTemp->physics != nullptr)
            {
                glUniform1i(m_p3_loc_mouseOver, (m_entityTemp->physics->mouseOver) ? 1 : 0);
            }
            else
            {
                glUniform1i(m_p3_loc_mouseOver, 0);
            }

            // Debug
            if ((m_entityTemp->physics != nullptr) && (m_renderDebug))
            {
                glUniform1i(m_p3_loc_collision, (m_entityTemp->physics->collision) ? 1 : 0);
                glUniform1i(m_p3_loc_hasFunction, (m_entityTemp->base.hasFunction) ? 1 : 0);
            }
            else
            {
                glUniform1i(m_p3_loc_collision, 0);
                glUniform1i(m_p3_loc_hasFunction, 0);
            }

            glUniformMatrix4fv(m_p3_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_entityTemp->graphics->modelMatrix));

            // skeletal animation uniforms for dynamic models
            if (m_entityTemp->graphics->model->numBones > 0)
            {
                // enable skinning
                glUniform1i(m_p3_loc_animationEnabled, 1);

                // bone transforms
                if ((m_entityTemp->animation != nullptr) && (m_entityTemp->animation->animationIndependent))
                {
                    for (std::size_t i = 0; i < m_entityTemp->animation->numBones; ++i)
                    {
                        glUniformMatrix4fv(m_p3_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->animation->boneTransform[i]));
                    }
                }
                else
                {
                    for (std::size_t i = 0; i < m_entityTemp->graphics->model->numBones; ++i)
                    {
                        glUniformMatrix4fv(m_p3_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->graphics->model->bone[i].transformFinal));
                    }
                }
            }
            else // no bones
            {
                // disable skinning
                glUniform1i(m_p3_loc_animationEnabled, 0);
            }

            // Model
            for (std::uint32_t j = 0; j < m_entityTemp->graphics->model->numMesh; ++j)
            {
                if ((m_entityTemp->graphics->model->mesh[j].enabled) &&
                    (m_entityTemp->graphics->model->mesh[j].VAO != 0))
                {
                    // Use textures
                    if (m_entityTemp->graphics->material != nullptr)
                    {
                        glActiveTexture(GL_TEXTURE0 + MAX_POINT_LIGHTS + 1);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->graphics->material[j % m_entityTemp->graphics->numMaterial]->diffuse->ID);
                        glActiveTexture(GL_TEXTURE0 + MAX_POINT_LIGHTS + 2);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->graphics->material[j % m_entityTemp->graphics->numMaterial]->normal->ID);
                        glActiveTexture(GL_TEXTURE0 + MAX_POINT_LIGHTS + 3);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->graphics->material[j % m_entityTemp->graphics->numMaterial]->specular->ID);
                        glUniform1fv(m_p3_loc_materialShininess, 1, &m_entityTemp->graphics->material[j % m_entityTemp->graphics->numMaterial]->shininess);
                    }
                    // VAO
                    glBindVertexArray(m_entityTemp->graphics->model->mesh[j].VAO);
                    if (m_wireframe)
                    {
                        glDrawElements(GL_LINE_LOOP, m_entityTemp->graphics->model->mesh[j].numIndex, GL_UNSIGNED_INT, nullptr);
                    }
                    else
                    {
                        //glDrawArrays(GL_TRIANGLES, 0, 3);
                        glDrawElements(GL_TRIANGLES, m_entityTemp->graphics->model->mesh[j].numIndex, GL_UNSIGNED_INT, nullptr);
                    }
                }
            }

            // Health bar
//            if ((m_entityTemp->physics->mouseOver) && (m_entityTemp->character != nullptr) && (m_entityTemp->character->healthBarModel != nullptr))
            if ((m_entityTemp->character != nullptr) && (m_entityTemp->character->healthBarModel != nullptr) && m_entityTemp->character->healthBarEnabled)
            {
                glUniform1i(m_p3_loc_billboard, 1);
                glUniform1i(m_p3_loc_collision, 0);
                glUniform1i(m_p3_loc_mouseOver, 0);
                glUniform1i(m_p3_loc_animationEnabled, 0);

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
                    glActiveTexture(GL_TEXTURE0 + MAX_POINT_LIGHTS + 1);

                    // Health bar background
                    billboardPosition.x = m_entityTemp->base.position.x - 0.001f;
                    billboardPosition.y = m_entityTemp->base.position.y + m_entityTemp->character->healthBarOffset;
                    billboardPosition.z = m_entityTemp->base.position.z - 0.001f;
                    billboardModelMatrix = glm::translate(glm::mat4(1), billboardPosition);
                    billboardScale       = glm::vec3(billboardScaleRatio * m_entityTemp->character->healthBarScale.x, 1.0f * m_entityTemp->character->healthBarScale.y, 1.0f);
                    billboardScaleMatrix = glm::scale(glm::mat4(1), billboardScale);
                    billboardModelMatrix = billboardModelMatrix * billboardScaleMatrix;
                    glUniformMatrix4fv(m_p3_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(billboardModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, m_entityTemp->character->healthBarmaterial[0]->specular->ID);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->character->healthBarModel->mesh[0].numIndex, GL_UNSIGNED_INT, nullptr);

                    // Health bar
                    float factor = m_entityTemp->character->attribute.health.current / m_entityTemp->character->attribute.health.max;
                    float offset = ((billboardScaleRatioDiv) * factor * m_entityTemp->character->healthBarScale.x) - (billboardScaleRatioDiv * m_entityTemp->character->healthBarScale.x);
                    billboardPosition.x = m_entityTemp->base.position.x + offset;
                    billboardPosition.y = m_entityTemp->base.position.y + m_entityTemp->character->healthBarOffset;
                    billboardPosition.z = m_entityTemp->base.position.z - offset;
                    billboardModelMatrix = glm::translate(glm::mat4(1), billboardPosition);
                    billboardScale       = glm::vec3(billboardScaleRatio * factor * m_entityTemp->character->healthBarScale.x, 1.0f * m_entityTemp->character->healthBarScale.y, 1.0f);
                    billboardScaleMatrix = glm::scale(glm::mat4(1), billboardScale);
                    billboardModelMatrix = billboardModelMatrix * billboardScaleMatrix;
                    glUniformMatrix4fv(m_p3_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(billboardModelMatrix));

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
                    glUniformMatrix4fv(m_p3_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(billboardModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, m_entityTemp->character->healthBarmaterial[0]->diffuse->ID);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->character->healthBarModel->mesh[0].numIndex, GL_UNSIGNED_INT, nullptr);
                }
            }

            // Tooltip
           if ((m_entityTemp->base.textActive != 0) && (m_pc_bbq_VAO != 0))
            {
                if ((m_entityTemp->physics->mouseOver != 0) || (getKeyState(GLFW_KEY_LEFT_ALT)))
                {
                    glEnable(GL_BLEND);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                    glUniform1i(m_p3_loc_billboard, 1);
                    glUniform1i(m_p3_loc_collision, 0);
                    glUniform1i(m_p3_loc_mouseOver, 0);
                    glUniform1i(m_p3_loc_animationEnabled, 0);
                    glUniform1i(m_p3_loc_isText, 1);

                    glUniform4f(m_p3_loc_textColor,
                                m_entityTemp->base.textColor.x,
                                m_entityTemp->base.textColor.y,
                                m_entityTemp->base.textColor.z,
                                1.0);

                    // Model matrix uniform
                    glm::mat4 tooltipModelMatrix = glm::mat4(1);
                    glm::mat4 tooltipScaleMatrix = glm::mat4(1);
                    glm::vec3 tooltipPosition    = glm::vec3(0.001f, 0.001f, 0.001f);

                    glBindVertexArray(m_pc_bbq_VAO);
                    glActiveTexture(GL_TEXTURE0 + MAX_POINT_LIGHTS + 1);

                    sTexture* texture = m_resourceManager->generateTexture(m_entityTemp->base.textData);

                    // Scale
                    float scale  = 2.0f;
                    float scaleX = static_cast<float>(m_window_w) / 1920.0f * static_cast<float>(texture->width) * scale / static_cast<float>(m_window_w);
                    float scaleY = static_cast<float>(m_window_h) / 1080.0f * static_cast<float>(texture->height) * scale / static_cast<float>(m_window_h);

                    // position
                    tooltipPosition.x = m_entityTemp->base.position.x;
                    tooltipPosition.y = m_entityTemp->base.position.y + (m_entityTemp->physics->halfDimentions.y * 4);
                    tooltipPosition.z = m_entityTemp->base.position.z;
                    tooltipModelMatrix = glm::translate(glm::mat4(1), tooltipPosition);
                    tooltipScaleMatrix = glm::scale(glm::mat4(1), glm::vec3(scaleX, scaleY, 1.0f));
                    tooltipModelMatrix = tooltipModelMatrix * tooltipScaleMatrix;
                    glUniformMatrix4fv(m_p3_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(tooltipModelMatrix));

                    glBindTexture(GL_TEXTURE_2D, texture->ID);
                    glDrawArrays(GL_TRIANGLES, 0, 6);

                    glUniform1i(m_p3_loc_isText, 0);
                }
            }
        }
    }
};
