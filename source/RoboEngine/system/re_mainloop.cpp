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

#include "re_mainloop.hpp"

namespace RoboEngine
{
    static void glfw_error_callback(int error, const char* description)
    {
        RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "GLFW error - " + std::to_string(error) + " : " + description);
    }

    uint16_t re_cMainLoop::initialize_internal(void)
    {
        uint16_t return_value = EXIT_SUCCESS;
        glfwSetErrorCallback(glfw_error_callback);
        m_log.clear();
        m_log.write("RoboEngine started.");
        if(!glfwInit())
        {
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Failed to initialize glfw");
            return EXIT_FAILURE;
        }
        else
        {
            RE_STATE = RE_STATE_ENUM::RE_ACTIVE;
            m_entityManager.initialize();
            m_frameTimer.initialize();
            //graphics engine
            //m_graphicsEngine.setTitle("Project 0");
            return_value = m_graphicsEngine.initialize();
            if (return_value == EXIT_FAILURE)
            {
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Failed to initialize the graphics engine");
            }
            else
            {
                m_window = m_graphicsEngine.getWindow();
                m_SystemEvents.initialize(m_window);

                re_sEntity *entity_2 = m_entityManager.getNew();
                m_entityManager.addPhysics(entity_2);
                m_entityManager.addRender(entity_2);
                m_entityManager.addTexture(entity_2,"data/texture/cube");
                m_entityManager.addMesh(entity_2,"data/mesh/cube.obj");
                m_entityManager.addShader(entity_2,"data/shader/shader_000");
                m_entityManager.setPosition(entity_2,glm::vec3(0.0f, 0.0f, 0.0f));
                m_entityManager.setScale(entity_2,glm::vec3(2.0f, 2.0f, 2.0f));
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Added Entity ID: " + std::to_string(entity_2->ID));

                m_graphicsEngine.setEntity((re_sEntity*)m_entityManager.getHead());
                m_graphicsEngine.setEntity((re_sEntity*)m_entityManager.getHead());
                //physics engine
                return_value = m_physicsEngine.initialize();
                if (return_value == EXIT_FAILURE)
                {
                    RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Failed to initialize the physics engine");
                }
                else
                {
                    m_physicsEngine.setEntity((re_sEntity*)m_entityManager.getHead());
                    return_value = initialize();
                }
                return_value = initialize();
            }
        }
        return return_value;
    }

    uint16_t re_cMainLoop::deinitialize_internal(void)
    {
        uint16_t return_value = EXIT_SUCCESS;
        RE_STATE = RE_STATE_ENUM::RE_INACTIVE;
        m_graphicsEngine.deinitialize();
        m_physicsEngine.deinitialize();
        m_SystemEvents.deinitialize();

        m_entityManager.freeAll();

        return_value = deinitialize();
        glfwTerminate();
        return return_value;
    }

    uint16_t re_cMainLoop::run(void)
    {
        uint16_t return_value = EXIT_SUCCESS;
        return_value = initialize_internal();
        if (return_value == EXIT_SUCCESS)
        {
            while (RE_STATE == RE_STATE_ENUM::RE_ACTIVE)
            {
                m_frameTimer.frameStart();
                while(m_frameTimer.ready())
                {
                    uint64_t deltaTime = m_frameTimer.frameTime();
                    m_physicsEngine.process(deltaTime);
                    return_value = process_internal(deltaTime);
                    //std::cout << "Main engine running at -> " << std::to_string(deltaTime) << "ms frame time." << std::endl;
                }
                //RE_STATE = RE_STATE_ENUM::RE_DEACTIVATING;
                m_graphicsEngine.render();
            }
        }
        return_value = deinitialize_internal();
        return return_value;
    }

    uint16_t re_cMainLoop::process_internal(int64_t _dt)
    {
        uint16_t return_value = EXIT_SUCCESS;
        glfwPollEvents();
        m_SystemEvents.process();
        if (m_SystemEvents.statusQuit())
        {
            RE_STATE = RE_STATE_ENUM::RE_DEACTIVATING;
        }
        else
        {
            m_entityManager.setRotation(1, glm::vec3(0.001f, -0.002f, 0.003f));

            if (m_SystemEvents.getKey(GLFW_KEY_UP))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = m_graphicsEngine.getCameraPosition();
                glm::vec3 lookat = m_graphicsEngine.getCameraLookat();
                position.z += cameraSpeed * _dt;
                lookat.z += cameraSpeed * _dt;
                m_graphicsEngine.setCameraPosition(position, lookat);
            }
            if (m_SystemEvents.getKey(GLFW_KEY_DOWN))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = m_graphicsEngine.getCameraPosition();
                glm::vec3 lookat = m_graphicsEngine.getCameraLookat();
                position.z -= cameraSpeed * _dt;
                lookat.z -= cameraSpeed * _dt;
                m_graphicsEngine.setCameraPosition(position, lookat);
            }
            if (m_SystemEvents.getKey(GLFW_KEY_LEFT))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = m_graphicsEngine.getCameraPosition();
                glm::vec3 lookat = m_graphicsEngine.getCameraLookat();
                position.x += cameraSpeed * _dt;
                lookat.x += cameraSpeed * _dt;
                m_graphicsEngine.setCameraPosition(position, lookat);
            }
            if (m_SystemEvents.getKey(GLFW_KEY_RIGHT))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = m_graphicsEngine.getCameraPosition();
                glm::vec3 lookat = m_graphicsEngine.getCameraLookat();
                position.x -= cameraSpeed * _dt;
                lookat.x -= cameraSpeed * _dt;
                m_graphicsEngine.setCameraPosition(position, lookat);
            }
        }
        return_value = process(_dt);
        return return_value;
    }

}
