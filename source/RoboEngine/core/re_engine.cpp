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

#include "re_engine.hpp"
#include "../roboengine.hpp"

namespace RoboEngine
{

    void re_cRoboEngine::glfw_error_callback(int _error, const char* _description)
    {
        RoboEngine::re_logWrite("glfw-error-callback: " + std::to_string(_error) + " - " + _description, RE_ENGINE_LOG);
    }

    uint32_t re_cRoboEngine::log_initialize(const std::string &_message)
    {
        uint32_t return_value = m_log.initialize(RE_ENGINE_LOG);
        m_log.write(_message);
        return return_value;
    }

    uint32_t re_cRoboEngine::process_cl(const uint32_t &_argc, char** _argv)
    {
        uint32_t return_value = EXIT_SUCCESS;
        //m_log.write("Ignoring command line argument: " + std::to_string(0) + ": " + _argv[0], __FILE__, __LINE__, __FUNCTION__);
        for (uint32_t i = 1; i < _argc; i++)
        {
            std::string clString = _argv[i];
            if (clString.compare("--logc") == 0)
            {
                m_log.write("Processing command line argument: " + std::to_string(i) + ": " + _argv[i], __FILE__, __LINE__, __FUNCTION__);
                m_log.setLogConsole(true);
            }
            else
                m_log.write("Invalid command line argument: " + std::to_string(i) + ": " + _argv[i], __FILE__, __LINE__, __FUNCTION__);
        }
        return return_value;
    }

    uint32_t re_cRoboEngine::internal_initialize(void)
    {
        uint32_t return_value = EXIT_SUCCESS;
        if (m_state == eState::RE_INIT)
        {
            // initialize glfw3
            glfwSetErrorCallback(glfw_error_callback);
            uint32_t f_return_value = glfwInit();
            return_value = (f_return_value == GLFW_TRUE) ? EXIT_SUCCESS : EXIT_FAILURE;
            if (return_value != EXIT_SUCCESS)
                m_log.write("Failed to initialize glfw." , __FILE__, __LINE__, __FUNCTION__);

            // initialize graphics engine
            if (return_value == EXIT_SUCCESS)
            {
                f_return_value = m_graphicsEngine.initialize();
                return_value = (f_return_value == EXIT_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
                if (return_value != EXIT_SUCCESS)
                    m_log.write("Failed to initialize graphics engine." , __FILE__, __LINE__, __FUNCTION__);
            }

            // initialize system events
            if (return_value == EXIT_SUCCESS)
                m_SystemEvents.initialize(m_graphicsEngine.getWindow());

            // initialize frame timer
            if (return_value == EXIT_SUCCESS)
                m_frameTimer.initialize();

            // initialize physics engine
            if (return_value == EXIT_SUCCESS)
            {
                f_return_value = m_physicsEngine.initialize();
                return_value = (f_return_value == EXIT_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
                if (return_value != EXIT_SUCCESS)
                    m_log.write("Failed to initialize physics engine." , __FILE__, __LINE__, __FUNCTION__);
            }

            // initialize entity manager
            if (return_value == EXIT_SUCCESS)
            {
                f_return_value = m_entityManager.initialize();
                return_value = (f_return_value == EXIT_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
                if (return_value != EXIT_SUCCESS)
                    m_log.write("Failed to initialize entity manager." , __FILE__, __LINE__, __FUNCTION__);

                re_sEntity *entity_1 = m_entityManager.getNew();
                m_entityManager.addPhysics(entity_1);
                m_entityManager.addRender(entity_1);
                m_entityManager.addTexture(entity_1,"data/texture/default");
                m_entityManager.addMesh(entity_1,"data/mesh/default.obj");
                m_entityManager.addShader(entity_1,"data/shader/default");
                entity_1->enabled = false;



                m_graphicsEngine.setEntity(const_cast<re_sEntity*>(m_entityManager.getHead()));
                m_physicsEngine.setEntity(const_cast<re_sEntity*>(m_entityManager.getHead()));
            }

        }
        if (return_value == EXIT_SUCCESS)
            m_state = eState::RE_ACTV;
        return return_value;
    }

    uint32_t re_cRoboEngine::internal_terminate(void)
    {
        uint32_t return_value = EXIT_SUCCESS;
        if (m_state == eState::RE_TERM)
        {
            return_value = m_graphicsEngine.terminate();
            m_physicsEngine.terminate();
            m_SystemEvents.terminate();

            m_entityManager.freeAll();

            glfwTerminate();
        }
        if (return_value == EXIT_SUCCESS)
            m_state = eState::RE_STOP;
        return return_value;
    }


    uint32_t re_cRoboEngine::internal_run(const uint32_t &_argc, char** _argv)
    {
        if (m_state != eState::RE_STOP)
            return EXIT_FAILURE;
        if (RE_DEBUG == 1)
            m_log.setLogConsole(true);
        uint32_t f_return_value = EXIT_SUCCESS;
        std::chrono::system_clock::time_point c_time_init = std::chrono::system_clock::now();
        time_t t_time_init = std::chrono::system_clock::to_time_t(c_time_init);
        std::string s_time_init = ctime(&t_time_init);

        //basic core initialize
        uint32_t return_value = log_initialize("Starting RoboEngine - Version: "
                                      + std::to_string(ROBOENGINE_VERSION_MAJOR) + "."
                                      + std::to_string(ROBOENGINE_VERSION_MINOR) + "."
                                      + std::to_string(ROBOENGINE_VERSION_MICRO) + " - "
                                      + "Time: "
                                      + s_time_init);
        if (return_value == EXIT_SUCCESS)
            return_value = process_cl(_argc, _argv);

        //initialize
        if (return_value == EXIT_SUCCESS)
        {
            m_state = eState::RE_INIT;
            f_return_value = internal_initialize();
            return_value = (return_value == EXIT_SUCCESS) ? f_return_value : return_value;
            f_return_value = initialize();
            return_value = (return_value == EXIT_SUCCESS) ? f_return_value : return_value;
        }

        //run
        if (return_value == EXIT_SUCCESS)
        {
            ///delete_me!
            uint64_t fps_print_count = 0;
            uint64_t fps_print_max = 100;
            uint64_t fps_print_data_ups = 0;
            uint64_t fps_print_data_fps = 0;
            ///delete_me!
            while (m_state == eState::RE_ACTV)
            {
                if (m_SystemEvents.windowCloseRequested())
                    m_state = eState::RE_TERM;
                else
                {
                    m_frameTimer.frameStart();
                    while(m_frameTimer.ready())
                    {
                        uint64_t deltaTime = m_frameTimer.frameTime();

                        glfwPollEvents();
                        m_SystemEvents.process();
                        if (return_value == EXIT_SUCCESS)
                            return_value = m_physicsEngine.process(deltaTime);
                        if (return_value == EXIT_SUCCESS)
                            return_value = process(deltaTime);

                        ///delete_me!
                        fps_print_count++;
                        fps_print_data_ups += deltaTime;
                        fps_print_data_fps += m_frameTimer.getFrameTime();
                        if (fps_print_count >= fps_print_max)
                        {
                            std::cout << "Roboengine engine ups -> " << std::to_string(fps_print_data_ups / fps_print_max) << "ms" << std::endl;
                            std::cout << "Roboengine engine fps -> " << std::to_string(fps_print_data_fps / fps_print_max) << "ms" << std::endl;
                            fps_print_count = 0;
                            fps_print_data_ups = 0;
                            fps_print_data_fps = 0;
                        }
                        ///delete_me!

                    }
                    m_graphicsEngine.process();
                }
            }
        }

        //terminate
        m_state = eState::RE_TERM;
        f_return_value = internal_terminate();
        return_value = (return_value == EXIT_SUCCESS) ? f_return_value : return_value;
        f_return_value = terminate();
        return_value = (return_value == EXIT_SUCCESS) ? f_return_value : return_value;
        return return_value;
    }

}
