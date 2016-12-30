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

#include "mainloop.hpp"
#include "../RoboEngine/roboengine.hpp"


uint32_t c_mainloop::initialize(void)
{
    setWindowTitle("Frost and Flame");
    loadMap("data/map/level_0");
    GenMap(5);
    return EXIT_SUCCESS;
}

uint32_t c_mainloop::terminate(void)
{
    return EXIT_SUCCESS;
}

uint32_t c_mainloop::process(int64_t _dt)
{
    if (c_mainloop::getState() == RoboEngine::eState::RE_ACTV)
    {
        if (m_core.m_playerID == 0)
        {
            glm::vec3 rotationVec = getEntityRotation(2);
            rotationVec += glm::vec3(0.001f, -0.002f, 0.003f);
            setEntityRotation(2, rotationVec);
            if (getKey(GLFW_KEY_UP))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = getCameraPosition();
                glm::vec3 lookat = getCameraLookat();
                position.y -= cameraSpeed * _dt;
                lookat.y -= cameraSpeed * _dt;
                setCameraPosition(position, lookat);
            }
            if (getKey(GLFW_KEY_DOWN))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = getCameraPosition();
                glm::vec3 lookat = getCameraLookat();
                position.y += cameraSpeed * _dt;
                lookat.y += cameraSpeed * _dt;
                setCameraPosition(position, lookat);
            }
            if (getKey(GLFW_KEY_LEFT))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = getCameraPosition();
                glm::vec3 lookat = getCameraLookat();
                position.x -= cameraSpeed * _dt;
                lookat.x -= cameraSpeed * _dt;
                setCameraPosition(position, lookat);
            }
            if (getKey(GLFW_KEY_RIGHT))
            {
                float cameraSpeed = 0.01f;
                glm::vec3 position = getCameraPosition();
                glm::vec3 lookat = getCameraLookat();
                position.x += cameraSpeed * _dt;
                lookat.x += cameraSpeed * _dt;
                setCameraPosition(position, lookat);
            }
        }
        else
        {
           if (getKey(GLFW_KEY_LEFT))
            {
                glm::vec3 playerPosition = getEntityPosition(m_core.m_playerID);
                playerPosition.x += m_core.m_playerSpeed * _dt;
                setEntityPosition(m_core.m_playerID, playerPosition);
                glm::vec3 cameraPosition = getCameraPosition();
                setCameraPosition(glm::vec3(playerPosition.x, playerPosition.y, cameraPosition.z), playerPosition);
            }
            if (getKey(GLFW_KEY_RIGHT))
            {
                glm::vec3 playerPosition = getEntityPosition(m_core.m_playerID);
                playerPosition.x -= m_core.m_playerSpeed * _dt;
                setEntityPosition(m_core.m_playerID, playerPosition);
                glm::vec3 cameraPosition = getCameraPosition();
                setCameraPosition(glm::vec3(playerPosition.x, playerPosition.y, cameraPosition.z), playerPosition);
            }
            if (getKey(GLFW_KEY_UP))
            {
                glm::vec3 playerPosition = getEntityPosition(m_core.m_playerID);
                playerPosition.y += m_core.m_playerSpeed * _dt;
                setEntityPosition(m_core.m_playerID, playerPosition);
                glm::vec3 cameraPosition = getCameraPosition();
                setCameraPosition(glm::vec3(playerPosition.x, playerPosition.y, cameraPosition.z), playerPosition);
            }
            if (getKey(GLFW_KEY_DOWN))
            {
                glm::vec3 playerPosition = getEntityPosition(m_core.m_playerID);
                playerPosition.y -= m_core.m_playerSpeed * _dt;
                setEntityPosition(m_core.m_playerID, playerPosition);
                glm::vec3 cameraPosition = getCameraPosition();
                setCameraPosition(glm::vec3(playerPosition.x, playerPosition.y, cameraPosition.z), playerPosition);
            }
        }
    }
    return EXIT_SUCCESS;
}
