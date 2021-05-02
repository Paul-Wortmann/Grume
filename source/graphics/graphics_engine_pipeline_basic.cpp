
#include "graphics_engine.hpp"

void cGraphicsEngine::m_pb_initialize(void)
{
    // Initialize shader
    m_pb_shader.initialize();
    m_pb_shader.load("0_basic");
    glUseProgram(m_pb_shader.getID());
    m_pb_loc_modelMatrix      = m_pb_shader.getUniformLocation("modelMatrix");
    m_pb_loc_viewMatrix       = m_pb_shader.getUniformLocation("viewMatrix");
    m_pb_loc_projectionMatrix = m_pb_shader.getUniformLocation("projectionMatrix");
    m_pb_loc_materialDiffuse  = m_pb_shader.getUniformLocation("diffuse");
    m_pb_loc_animationEnabled = m_pb_shader.getUniformLocation("animationEnabled");

    // Bone transformation matrices
    for (uint32 i = 0; i < MAX_BONES; ++i)
    {
        m_pb_loc_boneMatrix[i] = m_pb_shader.getUniformLocation("boneMatrix[" + std::to_string(i) + "]");
    }
};

void cGraphicsEngine::m_pb_terminate(void)
{
    m_pb_shader.terminate();
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

    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityTemp->model != nullptr))
        {
            // Shader uniforms
            glUniformMatrix4fv(m_pb_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_entityTemp->modelMatrix));

            // skeletal animation uniforms for dynamic models
            if ((m_entityTemp->model->numBones > 0) && (m_animation))
            {
                // enable skinning
                glUniform1i(m_pb_loc_animationEnabled, 1);

                // bone transforms
                for (std::size_t i = 0; i < m_entityTemp->model->numBones; ++i)
                {
                    glUniformMatrix4fv(m_pb_loc_boneMatrix[i], 1, GL_FALSE, glm::value_ptr(m_entityTemp->model->bone[i].transformFinal));
                }
            }
            else // no bones
            {
                // disable skinning
                glUniform1i(m_pb_loc_animationEnabled, 0);
            }

            // Model
            for (uint32 j = 0; j < m_entityTemp->model->numMesh; ++j)
            {
                if (m_entityTemp->model->mesh[j].VAO != 0)
                {
                    // Use custom textures
                    if (m_entityTemp->material != nullptr)
                    {
                        glActiveTexture(GL_TEXTURE0);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->material->diffuse->ID);
                    }
                    else // Use default model textures
                    {
                        glActiveTexture(GL_TEXTURE0);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->model->mesh[j].material->diffuse->ID);
                    }
                    // VAO
                    glBindVertexArray(m_entityTemp->model->mesh[j].VAO);
                    if (m_wireframe)
                    {
                        glDrawElements(GL_LINE_LOOP, m_entityTemp->model->mesh[j].numIndex, GL_UNSIGNED_INT, nullptr);
                    }
                    else
                    {
                        //glDrawArrays(GL_TRIANGLES, 0, 3);
                        glDrawElements(GL_TRIANGLES, m_entityTemp->model->mesh[j].numIndex, GL_UNSIGNED_INT, nullptr);
                    }
                }
            }
        }
    }
};
