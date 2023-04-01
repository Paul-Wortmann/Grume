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

void cGraphicsEngine::m_pls_initialize(void)
{
    // Initialize shader
    m_pls_shader.initialize();
    m_pls_shader.load("ls_001");
    glUseProgram(m_pls_shader.getID());
    m_pls_loc_diffuseMap  = m_pls_shader.getUniformLocation("diffuse");
};

void cGraphicsEngine::m_pls_terminate(void)
{
    m_pls_shader.terminate();
};

void cGraphicsEngine::m_pls_render(void)
{
    // Set the framebuffer to 0, ie. default framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, m_framebufferSize_w, m_framebufferSize_h);
    // Dont clear the buffers, just draw the UI on top.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup shader, uniforms
    glUseProgram(m_pls_shader.getID());

    // Shader uniforms

    // Texture locations
    glUniform1i(m_pls_loc_diffuseMap, GL_TEXTURE0);

    // Render previous stage texture as background
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_pls_renderTextureID);
    glBindVertexArray(m_pc_fsq_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
};
