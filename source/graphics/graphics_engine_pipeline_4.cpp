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

void cGraphicsEngine::m_p4_initialize(void)
{
    // Initialize shader
    m_p4_shader.initialize();
    m_p4_shader.load("4_particles");
    glUseProgram(m_p4_shader.getID());

    // Get shader uniform locations
    m_p4_loc_cameraRight     = m_p4_shader.getUniformLocation("cameraRight");
    m_p4_loc_cameraUp        = m_p4_shader.getUniformLocation("cameraUp");
    m_p4_loc_VP              = m_p4_shader.getUniformLocation("VP");
    m_p4_loc_textureParticle = m_p4_shader.getUniformLocation("textureParticle");

    // Vertex data for all particles.
    static const float32 vertex_buffer_data[] =
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
    };

    // Vertex array object
    glGenVertexArrays(1, &m_p4_VAO);
    glBindVertexArray(m_p4_VAO);

   // Vertex buffer
    glGenBuffers(1, &m_p4_vbo_vertex);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_vertex);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), &vertex_buffer_data, GL_STATIC_DRAW);

    // Position and size buffer
    glGenBuffers(1, &m_p4_vbo_position);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_position);
    glBufferData(GL_ARRAY_BUFFER, m_particleEngine.getNumParticles() * 4 * sizeof(float32), NULL, GL_STREAM_DRAW);

    // Color buffer
    glGenBuffers(1, &m_p4_vbo_color);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_color);
    glBufferData(GL_ARRAY_BUFFER, m_particleEngine.getNumParticles() * 4 * sizeof(float32), NULL, GL_STREAM_DRAW);

    // Bind VAO to 0, ie. none
    glBindVertexArray(0);
};

void cGraphicsEngine::m_p4_update(void)
{
    // Activate shader
    glUseProgram(m_p4_shader.getID());
    glBindVertexArray(m_p4_VAO);
    
    std::uint32_t numParticles = m_particleEngine.getNumParticles();
    sParticle*    particles    = m_particleEngine.getParticles();

    m_p4_particleCount = 0;
    for (std::uint32_t i = 0; i < numParticles; ++i)
    {
        if (particles[i].life > 0.0f)
        {
            m_p4_particleCount++;
        }
    }

    float32 positionsize[m_p4_particleCount * 4];
    float32 color[m_p4_particleCount * 4];
    for (std::uint32_t i = 0; i < numParticles; ++i)
    {
        if (particles[i].life > 0.0f)
        {
            positionsize[(i * 4) + 0] = particles[i].position.x;
            positionsize[(i * 4) + 1] = particles[i].position.y;
            positionsize[(i * 4) + 2] = particles[i].position.z;
            positionsize[(i * 4) + 3] = particles[i].size;

            color[(i * 4) + 0] = particles[i].color[0];
            color[(i * 4) + 1] = particles[i].color[1];
            color[(i * 4) + 2] = particles[i].color[2];
            color[(i * 4) + 3] = particles[i].color[3];
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_position);
    glBufferData(GL_ARRAY_BUFFER, m_p4_particleCount * 4 * sizeof(float32), NULL, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_p4_particleCount * sizeof(float32) * 4, &positionsize);

    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_color);
    glBufferData(GL_ARRAY_BUFFER, m_p4_particleCount * 4 * sizeof(float32), NULL, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_p4_particleCount * sizeof(float32) * 4, &color);
};

void cGraphicsEngine::m_p4_terminate(void)
{
    glDeleteBuffers(1, &m_p4_vbo_vertex);
    glDeleteBuffers(1, &m_p4_vbo_position);
    glDeleteBuffers(1, &m_p4_vbo_color);
    m_p4_shader.terminate();
    glDeleteTextures(1, &m_p4_particleTextureID);
    glDeleteVertexArrays(1, &m_p4_VAO);

};

void cGraphicsEngine::m_p4_render(void)
{
    // Dont clear the buffers, just draw the particles on top.

    // Update buffer content
    m_p4_update();

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Shader uniforms
    glm::mat4 viewMatrix = m_camera.getViewMatrix();
    glm::mat4 projectionMatrix = m_camera.getProjectionMatrix();
    glm::mat4 VPMatrix = projectionMatrix * viewMatrix;
    glUniformMatrix4fv(m_p4_loc_VP, 1, GL_FALSE, &VPMatrix[0][0]);

    glUniform3f(m_p4_loc_cameraRight, viewMatrix[0][0], viewMatrix[1][0], viewMatrix[2][0]);
    glUniform3f(m_p4_loc_cameraUp   , viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);

    // Texture locations
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_p4_particleTextureID);
    glUniform1i(m_p4_loc_textureParticle, GL_TEXTURE0);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_vertex);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    
    // 2nd attribute buffer : positions of particles' centers
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_position);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // 3rd attribute buffer : particles' colors
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_color);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glVertexAttribDivisor(0, 0);
    glVertexAttribDivisor(1, 1);
    glVertexAttribDivisor(2, 1);

    // Instance render, triangle strip
    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, m_p4_particleCount);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}
