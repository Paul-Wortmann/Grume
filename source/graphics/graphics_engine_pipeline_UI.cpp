
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

    // Texture locations
    glUniform1i(m_pui_loc_diffuseMap,   0);

    // Render previous stage texture as background
    m_pui_modelMatrix = glm::mat4(1);
    glUniformMatrix4fv(m_pui_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pui_modelMatrix));
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_p3_renderTextureID);
    glBindVertexArray(m_pui_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
/*
    // Render UI components
    glm::vec3 tPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    for(m_UITemp = m_UIHead; m_UITemp != nullptr; m_UITemp = m_UITemp->next)
    {
        // Shader uniforms
        tPosition += glm::vec3(0.0f, 0.0f, -0.1f);
        m_pui_modelMatrix = glm::translate(m_pui_modelMatrix, tPosition);
        glUniformMatrix4fv(m_pui_loc_modelMatrix, 1, GL_FALSE, glm::value_ptr(m_pui_modelMatrix));

        if (m_pui_VAO != 0)
        {
            // Texture
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, m_UITemp->normalTexture->ID);

            // VAO
            glBindVertexArray(m_pui_VAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
    }
*/
}
