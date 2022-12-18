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

// Move the camera to position
void cGraphicsEngine::moveCamera(glm::vec3 &_position)
{
    glm::vec3 cameraTarget = getCameraTarget();
    glm::vec3 cameraPosition = getCameraPosition();

    float deltaX = _position.x - cameraTarget.x;
    float deltaZ = _position.z - cameraTarget.z;

    // Camera follow player
    cameraPosition.x += deltaX;
    cameraPosition.z += deltaZ;
    cameraTarget.x += deltaX;
    cameraTarget.z += deltaZ;
    setCameraPosition(cameraPosition);
    setCameraTarget(cameraTarget);
}

// GLFW Error callback
void cGraphicsEngine::sm_glfwErrorCallback(std::int32_t _error, const char* _description)
{
    std::cout << std::to_string(_error) << ": " << std::string(_description) <<  __FILE__ << __LINE__ <<  __FUNCTION__ << std::endl;
}

// GLFW Window closed
void cGraphicsEngine::sm_glfwWindowCloseCallback(GLFWwindow* _window)
{
    cGraphicsEngine *graphicsEngine = reinterpret_cast<cGraphicsEngine*>(glfwGetWindowUserPointer(_window));
    graphicsEngine->m_windowClosed = true;
}

// GLFW Key io callback
void cGraphicsEngine::sm_glfwKeyCallback(GLFWwindow* _window, std::int32_t _key, std::int32_t _scancode, std::int32_t _action, std::int32_t _mods)
{
    cGraphicsEngine *graphicsEngine = static_cast<cGraphicsEngine*>(glfwGetWindowUserPointer(_window));

    if (_action == GLFW_PRESS)
    {
        graphicsEngine->m_keyMap[_key] = true;
    }
    else if (_action == GLFW_RELEASE)
    {
        graphicsEngine->m_keyMap[_key] = false;
        graphicsEngine->m_keyReadyMap[_key] = true;
    }
    else if (_action == GLFW_REPEAT)
    {
        graphicsEngine->m_keyMap[_key] = true;
    }
    else
    {
        graphicsEngine->m_keyMap[_key] = false;
    }
}

// GLFW Mouse cursor position callback
void cGraphicsEngine::sm_glfwCursorPosCallback(GLFWwindow* _window, double _xpos, double _ypos)
{
    cGraphicsEngine *graphicsEngine = static_cast<cGraphicsEngine*>(glfwGetWindowUserPointer(_window));

    graphicsEngine->m_mouseX = static_cast<float>(_xpos);
    graphicsEngine->m_mouseY = static_cast<float>(_ypos);
}

// GLFW Mouse button callback
void cGraphicsEngine::sm_glfwMouseButtonCallback(GLFWwindow* _window, std::int32_t _button, std::int32_t _action, std::int32_t _mods)
{
    cGraphicsEngine *graphicsEngine = static_cast<cGraphicsEngine*>(glfwGetWindowUserPointer(_window));

    if (_action == GLFW_PRESS)
    {
        graphicsEngine->m_keyMap[_button] = true;
    }
    else if (_action == GLFW_RELEASE)
    {
        graphicsEngine->m_keyMap[_button] = false;
        graphicsEngine->m_keyReadyMap[_button] = true;
    }
    else if (_action == GLFW_REPEAT)
    {
        graphicsEngine->m_keyMap[_button] = true;
    }
    else
    {
        graphicsEngine->m_keyMap[_button] = false;
    }
}

// GLFW Framebuffer size callback
void cGraphicsEngine::sm_glfwFramebufferSizeCallback(GLFWwindow* _window, std::int32_t _width, std::int32_t _height)
{
    cGraphicsEngine *graphicsEngine = static_cast<cGraphicsEngine*>(glfwGetWindowUserPointer(_window));

    glfwGetFramebufferSize(_window, &graphicsEngine->m_framebufferSize_w, &graphicsEngine->m_framebufferSize_h);
    glViewport(0, 0, graphicsEngine->m_framebufferSize_w, graphicsEngine->m_framebufferSize_h);
    graphicsEngine->m_aspectRatio = static_cast<float>(graphicsEngine->m_framebufferSize_w) / static_cast<float>(graphicsEngine->m_framebufferSize_h);
    graphicsEngine->m_camera.initialize(graphicsEngine->m_fieldOfView, graphicsEngine->m_framebufferSize_w, graphicsEngine->m_framebufferSize_h);
}

// GLFW Monitor callback
void cGraphicsEngine::sm_glfwMonitorCallback(GLFWmonitor* _monitor, std::int32_t _event)
{
    const char* monitorName = glfwGetMonitorName(_monitor);

    if (_event == GLFW_CONNECTED)
    {
        // The monitor was connected
        std::cout << "Monitor - " << std::string(monitorName) << " - Connected" << std::endl;
    }
    else if (_event == GLFW_DISCONNECTED)
    {
        // The monitor was disconnected
        std::cout << "Monitor - " << std::string(monitorName) << " - Disconnected" << std::endl;
    }
}

// Set window icon
void cGraphicsEngine::setWindowIcon(GLFWimage* _image)
{
    // If the image failed to load it will not exist
    if (_image != nullptr)
    {
        if (_image->pixels != nullptr)
        {
            // Use data
            glfwSetWindowIcon(m_window, 1, _image);

            // Free data
            delete[] _image->pixels;
            _image->pixels = nullptr;
        }

        // Free pointer
        delete _image;
        _image = nullptr;
    }
}

// Set custom mouse cursor
void cGraphicsEngine::setMouseCursor(GLFWimage* _image)
{
    // If the image failed to load it will not exist
    if (_image != nullptr)
    {
        if (_image->pixels != nullptr)
        {
            // Use data
            GLFWcursor* cursor = glfwCreateCursor(_image, 0, 0);
            glfwSetCursor(m_window, cursor);

            // Free data
            delete[] _image->pixels;
            _image->pixels = nullptr;
        }

        // Free pointer
        delete _image;
        _image = nullptr;
    }
}

std::uint32_t cGraphicsEngine::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    // Initialize GLFW ------------------------------------------
    if (glfwInit() == GLFW_TRUE)
    {
        // Set the GLFW error callback function
        glfwSetErrorCallback(sm_glfwErrorCallback);

        // Get monitor data (primary monitor only, although this could be expanded on if need be)
        m_monitors         = glfwGetMonitors(&m_monitorCount);
        m_monitor          = glfwGetPrimaryMonitor();
        m_videoModes       = glfwGetVideoModes(m_monitor, &m_videoModeCount);
        m_currentVideoMode = glfwGetVideoMode(m_monitor);

        // Log monitor data
        gLogWrite(LOG_INFO, "Monitor count: " + std::to_string(m_monitorCount), __FILE__, __LINE__, __FUNCTION__);
        for (std::int32_t i = 0; i < m_monitorCount; ++i)
        {
            gLogWrite(LOG_INFO, "Monitor " + std::to_string(i + 1) + " : " + std::string(glfwGetMonitorName(m_monitors[i])), __FILE__, __LINE__, __FUNCTION__);
        }

        // Log monitor video mode data
        gLogWrite(LOG_INFO, "Monitor supported video mode count: " + std::to_string(m_videoModeCount), __FILE__, __LINE__, __FUNCTION__);
        for (std::int32_t i = 0; i < m_videoModeCount; ++i)
        {
            gLogWrite(LOG_INFO, "Monitor supported video mode " + std::to_string(i + 1) + " : " +
            std::to_string(m_videoModes[i].width) + " x " +
            std::to_string(m_videoModes[i].height) + " @ " +
            std::to_string(m_videoModes[i].refreshRate) + " Hz", __FILE__, __LINE__, __FUNCTION__);
        }

        // Log current video mode
        gLogWrite(LOG_INFO, "Monitor current video mode: " +
        std::to_string(m_currentVideoMode->width) + " x " +
        std::to_string(m_currentVideoMode->height) + " @ " +
        std::to_string(m_currentVideoMode->refreshRate) + " Hz", __FILE__, __LINE__, __FUNCTION__);

        // GLFW OpenGL Window settings
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        // Create the window
        if (!m_fullscreen)
        {
            // If window width / height are 0, use the maximum available work area
            int xpos, ypos, width, height;
            glfwGetMonitorWorkarea(m_monitor, &xpos, &ypos, &width, &height);
            if ((m_window_w == 0) || (m_window_h == 0))
            {
                m_window_w = width;
                m_window_h = height;
            }

            // GLFW window creation
            m_window = glfwCreateWindow(m_window_w, m_window_h, m_windowTitle.c_str(), nullptr, nullptr);
        }
        else
        {
            // GLFW fullscreen window creation
            m_window_w = m_currentVideoMode->width;
            m_window_h = m_currentVideoMode->height;
            glfwWindowHint(GLFW_RED_BITS, m_currentVideoMode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, m_currentVideoMode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, m_currentVideoMode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, m_currentVideoMode->refreshRate);
            m_window = glfwCreateWindow(m_window_w, m_window_h, m_windowTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
        }

        // Create an OpenGL context
        if (m_window != nullptr)
        {

            // Create an OpenGL context
            glfwMakeContextCurrent(m_window);
            glfwSetWindowUserPointer(m_window, reinterpret_cast<void *>(this));

            // Log version information
            gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_VERSION)), __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_VENDOR)), __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_RENDERER)), __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)), __FILE__, __LINE__, __FUNCTION__);

            gLogWrite(LOG_INFO, "GLFW version: " + std::string(glfwGetVersionString()), __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_INFO, "GLM version: " + std::to_string(GLM_VERSION_MAJOR) + "." + std::to_string(GLM_VERSION_MINOR) + "." + std::to_string(GLM_VERSION_PATCH) + "." + std::to_string(GLM_VERSION_REVISION), __FILE__, __LINE__, __FUNCTION__);

            // View port and framebuffer
            glfwGetFramebufferSize(m_window, &m_framebufferSize_w, &m_framebufferSize_h);
            glViewport(0, 0, m_framebufferSize_w, m_framebufferSize_h);
            m_aspectRatio = static_cast<float>(m_framebufferSize_w) / static_cast<float>(m_framebufferSize_h);

            // GLFW set callback functions
            glfwSetWindowCloseCallback(m_window, sm_glfwWindowCloseCallback);
            glfwSetKeyCallback(m_window, sm_glfwKeyCallback);
            glfwSetCursorPosCallback(m_window, sm_glfwCursorPosCallback);
            glfwSetMouseButtonCallback(m_window, sm_glfwMouseButtonCallback);
            glfwSetFramebufferSizeCallback(m_window, sm_glfwFramebufferSizeCallback);
            glfwSetMonitorCallback(sm_glfwMonitorCallback);

            // OpenGL ----------------------------------
            glfwSwapInterval(1);
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CCW);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            //glDepthFunc(GL_LEQUAL);
            glClearDepth(1.0);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            checkOpenGL();

            // Camera --------------------------------
            m_camera.initialize(m_fieldOfView, m_framebufferSize_w, m_framebufferSize_h);
            m_camera.setPosition(glm::vec3(6.0f,12.0f,6.0f));
            m_camera.setTarget     (glm::vec3(0.0f, -1.0f, 0.0f));
            m_camera.setOrientation(glm::vec3(0.0f, 1.0f, 0.0f));

            // Input --------------------------------
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            //glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetCursorPos(m_window, m_window_w/2, m_window_h/2);
            glfwSetCursorPos(m_window, m_framebufferSize_w / 2, m_framebufferSize_h / 2);

            // Lights ------------------------------------
            m_lightManager.initialize();

            // Default global directional light
            m_lightManager.directionalLight.enabled   = 0;
            m_lightManager.directionalLight.direction = glm::vec3(-4.0f, 20.0f, -4.0f);
            m_lightManager.directionalLight.ambient   = glm::vec3(0.2f, 0.2f, 0.2f);
            m_lightManager.directionalLight.diffuse   = glm::vec3(0.3f, 0.3f, 0.3f);
            m_lightManager.directionalLight.specular  = glm::vec3(0.25f, 0.25f, 0.25f);

            // Player point light
            m_playerLight = m_lightManager.getNew();
            m_playerLight->enabled   = 1;
            m_playerLight->position  = glm::vec3(0.0f, 1.0f, 0.0f);
            m_playerLight->ambient   = glm::vec3(1.5f, 1.5f, 1.5f);
            m_playerLight->diffuse   = glm::vec3(1.8f, 1.8f, 1.8f);
            m_playerLight->specular  = glm::vec3(1.0f, 1.0f, 1.0f);
            m_playerLight->constant  = 1.0f;
            m_playerLight->linear    = 0.09f;
            m_playerLight->quadratic = 0.032f;
/*
            // Test point light
            sGraphicsEnginePointLight* tLight = m_lightManager.getNew();
            tLight->enabled   = 1;
            tLight->position  = glm::vec3(6.0f, 1.0f, 6.0f);
            tLight->ambient   = glm::vec3(1.5f, 1.5f, 1.5f);
            tLight->diffuse   = glm::vec3(1.8f, 1.8f, 1.8f);
            tLight->specular  = glm::vec3(1.0f, 1.0f, 1.0f);
            tLight->constant  = 1.0f;
            tLight->linear    = 0.09f;
            tLight->quadratic = 0.032f;

            // Test point light
            tLight = m_lightManager.getNew();
            tLight->enabled   = 1;
            tLight->position  = glm::vec3(6.0f, 1.0f, -6.0f);
            tLight->ambient   = glm::vec3(1.5f, 1.5f, 1.5f);
            tLight->diffuse   = glm::vec3(1.8f, 1.8f, 1.8f);
            tLight->specular  = glm::vec3(1.0f, 1.0f, 1.0f);
            tLight->constant  = 1.0f;
            tLight->linear    = 0.09f;
            tLight->quadratic = 0.032f;


            // Test point light
            tLight = m_lightManager.getNew();
            tLight->enabled   = 1;
            tLight->position  = glm::vec3(-6.0f, 1.0f, -6.0f);
            tLight->ambient   = glm::vec3(1.5f, 1.5f, 1.5f);
            tLight->diffuse   = glm::vec3(1.8f, 1.8f, 1.8f);
            tLight->specular  = glm::vec3(1.0f, 1.0f, 1.0f);
            tLight->constant  = 1.0f;
            tLight->linear    = 0.09f;
            tLight->quadratic = 0.032f;


            // Test point light
            tLight = m_lightManager.getNew();
            tLight->enabled   = 1;
            tLight->position  = glm::vec3(-6.0f, 1.0f, 6.0f);
            tLight->ambient   = glm::vec3(1.5f, 1.5f, 1.5f);
            tLight->diffuse   = glm::vec3(1.8f, 1.8f, 1.8f);
            tLight->specular  = glm::vec3(1.0f, 1.0f, 1.0f);
            tLight->constant  = 1.0f;
            tLight->linear    = 0.09f;
            tLight->quadratic = 0.032f;
*/

            // Initialize render pipelines ------------------
            if (m_basicRender)
            {
                m_pb_initialize();
            }
            else
            {
                m_p1_initialize();
                m_p2_initialize();
                m_p3_initialize();
            }
            m_pc_initialize();
            m_pui_initialize();
            m_pls_initialize();

        }
        else
        {
            gLogWrite(LOG_ERROR, "GLFW window or OpenGL context creation failed!", __FILE__, __LINE__, __FUNCTION__);
            glfwTerminate();
            return EXIT_FAILURE;
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "GLFW Initialization failed!", __FILE__, __LINE__, __FUNCTION__);
        glfwTerminate();
        return_value = EXIT_FAILURE;
    }

    return return_value;
}

void cGraphicsEngine::terminate(void)
{
    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityTemp->graphics != nullptr) && (m_entityTemp->graphics->model != nullptr))
        {
            for (std::uint32_t i = 0; i < m_entityTemp->graphics->model->numMesh; ++i)
            {
                // VBO_vertices
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glDeleteBuffers(1, &m_entityTemp->graphics->model->mesh[i].VBO_vertices);
                glDeleteBuffers(1, &m_entityTemp->graphics->model->mesh[i].VBO_bones);

                // IBO
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                glDeleteBuffers(1, &m_entityTemp->graphics->model->mesh[i].IBO);

                // VAO
                glBindVertexArray(0);
                glDeleteVertexArrays(1, &m_entityTemp->graphics->model->mesh[i].VAO);
            }
        }
    }

    // Pipelines
    if (m_basicRender)
    {
        m_pb_terminate();
    }
    else
    {
        m_p1_terminate();
        m_p2_terminate();
        m_p3_terminate();
    }
    m_pc_terminate();
    m_pui_terminate();
    m_pls_terminate();

    // Systems
    m_camera.terminate();
    m_lightManager.terminate();

    // GLFW
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void cGraphicsEngine::m_initializeEntity(sEntity *&_entity)
{
    if ((_entity->graphics != nullptr) && (_entity->graphics->model != nullptr) && (_entity->graphics->model->mesh != nullptr))
    {
        for (std::uint32_t i = 0; i < _entity->graphics->model->numMesh; ++i)
        {
                if (_entity->graphics->model->mesh[i].VAO == 0)
                {
                    // VAO
                    glGenVertexArrays(1, &_entity->graphics->model->mesh[i].VAO);
                    glBindVertexArray(_entity->graphics->model->mesh[i].VAO);

                    // VBO_vertices
                    glGenBuffers(1, &_entity->graphics->model->mesh[i].VBO_vertices);
                    glBindBuffer(GL_ARRAY_BUFFER, _entity->graphics->model->mesh[i].VBO_vertices);
                    glBufferData(GL_ARRAY_BUFFER, _entity->graphics->model->mesh[i].numVertex * sizeof(sEntityModelVertex), _entity->graphics->model->mesh[i].vertex, GL_STATIC_DRAW);

                    // positions
                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, position));
                    glEnableVertexAttribArray(0);

                    // normals
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, normal));
                    glEnableVertexAttribArray(1);

                    // texture coords
                    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, texcoord));
                    glEnableVertexAttribArray(2);

                    // tangents
                    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, tangent));
                    glEnableVertexAttribArray(3);

                    // bitangentss
                    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, bitangent));
                    glEnableVertexAttribArray(4);

                    // Index Buffer object
                    glGenBuffers(1, &_entity->graphics->model->mesh[i].IBO);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _entity->graphics->model->mesh[i].IBO);
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _entity->graphics->model->mesh[i].numIndex * sizeof(std::uint32_t), _entity->graphics->model->mesh[i].index, GL_STATIC_DRAW);

                    //VBO_bones
                    if (_entity->graphics->model->numBones > 0)
                    {
                        glGenBuffers(1, &_entity->graphics->model->mesh[i].VBO_bones);
                        glBindBuffer(GL_ARRAY_BUFFER, _entity->graphics->model->mesh[i].VBO_bones);
                        glBufferData(GL_ARRAY_BUFFER, _entity->graphics->model->mesh[i].numVertex * sizeof(sEntityModelVertexBone), _entity->graphics->model->mesh[i].vertexBone, GL_STATIC_DRAW);
                        // boneWeights
                        glEnableVertexAttribArray(5);
                        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertexBone), (void*)offsetof(sEntityModelVertexBone, boneWeight));
                        // boneIDs
                        glEnableVertexAttribArray(6); // USE "glVertexAttrib I Pointer" <- 'I' very important!
                        glVertexAttribIPointer(6, 4, GL_INT, sizeof(sEntityModelVertexBone), (void*)offsetof(sEntityModelVertexBone, boneID));
                    }

                    // Unbind IBO, VBO，VAO
                    glBindVertexArray(0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                    glBindBuffer(GL_ARRAY_BUFFER, 0);
                }
        }
    }

    // Character health bar
    if ((_entity->character != nullptr) && (_entity->character->healthBarModel != nullptr) && (_entity->character->healthBarModel->mesh != nullptr))
    {
        for (std::uint32_t i = 0; i < _entity->character->healthBarModel->numMesh; ++i)
        {
                if (_entity->character->healthBarModel->mesh[i].VAO == 0)
                {
                    // VAO
                    glGenVertexArrays(1, &_entity->character->healthBarModel->mesh[i].VAO);
                    glBindVertexArray(_entity->character->healthBarModel->mesh[i].VAO);

                    // VBO_vertices
                    glGenBuffers(1, &_entity->character->healthBarModel->mesh[i].VBO_vertices);
                    glBindBuffer(GL_ARRAY_BUFFER, _entity->character->healthBarModel->mesh[i].VBO_vertices);
                    glBufferData(GL_ARRAY_BUFFER, _entity->character->healthBarModel->mesh[i].numVertex * sizeof(sEntityModelVertex), _entity->character->healthBarModel->mesh[i].vertex, GL_STATIC_DRAW);

                    // positions
                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, position));
                    glEnableVertexAttribArray(0);

                    // normals
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, normal));
                    glEnableVertexAttribArray(1);

                    // texture coords
                    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, texcoord));
                    glEnableVertexAttribArray(2);

                    // tangents
                    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, tangent));
                    glEnableVertexAttribArray(3);

                    // bitangentss
                    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(sEntityModelVertex), (GLvoid*) offsetof(struct sEntityModelVertex, bitangent));
                    glEnableVertexAttribArray(4);

                    // Index Buffer object
                    glGenBuffers(1, &_entity->character->healthBarModel->mesh[i].IBO);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _entity->character->healthBarModel->mesh[i].IBO);
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _entity->character->healthBarModel->mesh[i].numIndex * sizeof(std::uint32_t), _entity->character->healthBarModel->mesh[i].index, GL_STATIC_DRAW);

                    // Unbind IBO, VBO，VAO
                    glBindVertexArray(0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
                    glBindBuffer(GL_ARRAY_BUFFER, 0);
                }
        }
    }
}

void cGraphicsEngine::m_initializeEntities(void)
{
    for (sEntity* tEntity = m_entityHead; tEntity != nullptr; tEntity = tEntity->next)
    {
        m_initializeEntity(tEntity);
    }
}

void cGraphicsEngine::process(const std::int64_t &_dt)
{
    // get current time
    m_time = static_cast<float>(glfwGetTime());

    // Windows close event
    if (m_windowClosed)
    {
        sGraphicsEvent* event = new sGraphicsEvent;
        event->type = eGraphicsEventType::graphicsEventType_windowClose; // Window close
        event->data = 1; // True
        m_event.push(event);
    }

    // UI
    m_UIManager->setMousePosition(glm::vec2(m_mouseX, m_mouseY));

    // Camera
    m_camera.process(_dt);

    if (m_loadRender)
    {
        // Render loading screen
        m_pls_render();
    }
    else
    {
        if (m_basicRender)
        {
            // Basic render pass: testing no graphics
            m_pb_render();
        }
        else
        {
            // 1st render pass: shadow map
            m_p1_render();

            // 2nd render pass: Point light shadow cube map generation
            m_p2_render();

            // 3rd render pass: Lighting
            m_p3_render();
        }

        // UI render pass: last stage
        m_pui_render();

    }
    // End frame
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}
