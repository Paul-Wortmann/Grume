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

#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_graphics.hpp"
#include "graphics_engine_camera.hpp"
#include "graphics_engine_debug.hpp"

class cGraphicsEngine
{
    private:
        // Linked list pointers
        sEntityGraphics *m_entityFirst = nullptr;
        sEntityGraphics *m_entityTemp  = nullptr;
        
        // Private instances
        cCamera     m_camera           = {};

        // Private member variables
        static bool m_windowClosed;
        std::string m_windowTitle      = "Frost and Flame";
        int32_t     m_window_w         = 800;
        int32_t     m_window_h         = 600;
        int32_t     m_frameBuffer_w    = m_window_w;
        int32_t     m_frameBuffer_h    = m_window_h;
        float       m_aspectRatio      = static_cast<float>(m_window_w) / static_cast<float>(m_window_h);
        float       m_window_fov       = 90.0f; // degrees
        bool        m_windowActive     = false;
        uint32_t    m_currentShader    = 0;
        bool        m_fullscreen       = false;
        glm::mat4   m_viewMatrix       = glm::mat4(1);
        glm::mat4   m_projectionMatrix = glm::mat4(1);
        
        // GLFW
        GLFWwindow* m_window           = nullptr;
        static void m_errorCallback(int error, const char* description);
        static void m_closeWindowCallback(GLFWwindow* _windowContext);
        
    protected:
        
    public:
        cGraphicsEngine(void);
        ~cGraphicsEngine(void);
        
        uint32_t initialize(void);
        void     terminate(void);
        void     process(void);
        void     render(void);
        
        void     setEntityHandle(sEntityGraphics *_entity);
        bool     windowActive(void) { return m_windowActive; }
        int32_t  getKeyState(int32_t _key) { return glfwGetKey(m_window, _key); }
};

#endif // GRAPHICS_ENGINE_HPP
