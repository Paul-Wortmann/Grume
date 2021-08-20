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
    m_p4_shader.load("4");

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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

    // Position and size buffer
    glGenBuffers(1, &m_p4_vbo_position);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_position);
    glBufferData(GL_ARRAY_BUFFER, m_particleEngine.getNumParticles() * 4 * sizeof(float32), NULL, GL_STREAM_DRAW);

    // Color buffer
    glGenBuffers(1, &m_p4_vbo_color);
    glBindBuffer(GL_ARRAY_BUFFER, m_p4_vbo_color);
    glBufferData(GL_ARRAY_BUFFER, m_particleEngine.getNumParticles() * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);

    // Bind VAO to 0, ie. none
    glBindVertexArray(0);
};

void cGraphicsEngine::m_p4_terminate(void)
{
    m_p4_shader.terminate();
};

void cGraphicsEngine::m_p4_render(void)
{

    // Dont clear the buffers, just draw the particles on top.

    // Setup shader, uniforms
    //glUseProgram(m_p4_shader.getID());

    // Shader uniforms

    // Texture locations

}
