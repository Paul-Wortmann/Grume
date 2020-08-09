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

bool cGraphicsEngine::m_windowClosed = false;

void cGraphicsEngine::m_errorCallback(int error, const char* description)
{
    gLogWrite(LOG_ERROR, " " + std::string(description), __FILE__, __LINE__, __FUNCTION__);
}

void cGraphicsEngine::m_closeWindowCallback(GLFWwindow* _windowContext)
{
    cGraphicsEngine::m_windowClosed = (glfwWindowShouldClose(_windowContext) == GLFW_TRUE);
}

cGraphicsEngine::cGraphicsEngine(void)
{
    
};

cGraphicsEngine::~cGraphicsEngine(void)
{
    
};

void cGraphicsEngine::setEntityHandle(sEntityGraphics *_entity)
{
    m_entityFirst = _entity;
}

uint32_t cGraphicsEngine::initialize(void)
{
    glfwSetErrorCallback(m_errorCallback);
    if(!glfwInit())
    {
        gLogWrite(LOG_ERROR, "GLFW Initialization failed!", __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    else
    {
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        if (!m_fullscreen)
        {
            m_window = glfwCreateWindow(m_window_w, m_window_h, m_windowTitle.c_str(), nullptr, nullptr);
            m_aspectRatio = static_cast<float>(m_window_w) / static_cast<float>(m_window_h);
        }
        else
        {
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            m_window_w = mode->width;
            m_window_h = mode->height;
            m_aspectRatio = static_cast<float>(m_window_w) / static_cast<float>(m_window_h);
            m_window = glfwCreateWindow(m_window_w, m_window_h, m_windowTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
        }
        if (m_window == nullptr)
        {
            gLogWrite(LOG_ERROR, "GLFW window or OpenGL context creation failed!", __FILE__, __LINE__, __FUNCTION__);
            glfwTerminate();
            return EXIT_FAILURE;
        }
        else
        {
            glfwGetFramebufferSize(m_window, &m_frameBuffer_w, &m_frameBuffer_h);
            glfwMakeContextCurrent(m_window);
            
            glewExperimental = GL_TRUE;
            GLenum glewStatus = glewInit();
            if (glewStatus != GLEW_OK)
            {
                gLogWrite(LOG_ERROR, " GLEW initialization failed :  " + std::string(reinterpret_cast<const char*>(glewGetErrorString(glewStatus))), __FILE__, __LINE__, __FUNCTION__);
                glfwDestroyWindow(m_window);
                glfwTerminate();
                return EXIT_FAILURE;
            }
            else
            {
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_VERSION)), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_VENDOR)), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_RENDERER)), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)), __FILE__, __LINE__, __FUNCTION__);

                gLogWrite(LOG_INFO, "GLFW version: " + std::string(glfwGetVersionString()), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, "GLEW version: " + std::string(reinterpret_cast<const char*>(glewGetString(GLEW_VERSION))), __FILE__, __LINE__, __FUNCTION__);
                
                std::string assimpVersion = std::to_string(aiGetVersionMajor()) + "." + std::to_string(aiGetVersionMinor()) + "." + std::to_string(aiGetVersionRevision());
                gLogWrite(LOG_INFO, "ASIMP version: " + assimpVersion, __FILE__, __LINE__, __FUNCTION__);
                /*
                std::string libMathVersion = std::to_string(LIBMATH_VERSION_MAJOR) + "." + std::to_string(LIBMATH_VERSION_MINOR) + "." + std::to_string(LIBMATH_VERSION_PATCH);
                gLogWrite(LOG_INFO, "LibMath version: " + libMathVersion, __FILE__, __LINE__, __FUNCTION__);
                std::string libRMGVersion = std::to_string(LIBRMG_VERSION_MAJOR) + "." + std::to_string(LIBRMG_VERSION_MINOR) + "." + std::to_string(LIBRMG_VERSION_PATCH);
                gLogWrite(LOG_INFO, "LibRMG version: " + libRMGVersion, __FILE__, __LINE__, __FUNCTION__);
                */
                
                //glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                
                glViewport(0, 0, m_frameBuffer_w, m_frameBuffer_h);
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_CULL_FACE);
                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);
                glFrontFace(GL_CCW);
                glClearDepth(1.0);
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

                m_windowActive = true;

            }
        }
    }
    return EXIT_SUCCESS;    
};

void cGraphicsEngine::terminate(void)
{
    
};

void cGraphicsEngine::process(void)
{
    for (m_entityTemp = m_entityFirst; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        
    }
};

