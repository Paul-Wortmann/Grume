/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#include <GL/glew.h>
#include <iostream>
#include "gamecore.h"

void GameCore::init()
{
    RoboEngine::TRoboEngineVersion RoboEngineVersion;
    setGameName("Frost and Flame");
    log("  "+getGameName());
    log("# ---------------------------------------------- #");
    log("");
    log("Compiled with RoboEngine version: "+std::to_string(RoboEngineVersion.m_nMajorVersion)
                                        +"."+std::to_string(RoboEngineVersion.m_nMinorVersion)
                                        +"."+std::to_string(RoboEngineVersion.m_nPatchVersion));
    if (!m_window.Create(getGameName(),1024,768,0))
    {
        log("Failed to initialize the window subsystem.");
        setGameState(RoboEngine::EXIT);
    }
    m_map.Load("./maps/level_0.xml", m_meshManager, m_shaderManager, m_textureManager);
    /*
    m_graphicsObject.SetMesh("./models/tile.obj");
    m_graphicsObject.SetShader("./shaders/default");
    m_graphicsObject.SetTexture("./textures/tiles/blue_d.png");
    m_graphicsObject.SetMeshManager(m_meshManager);
    m_graphicsObject.SetShaderManager(m_shaderManager);
    m_graphicsObject.SetTextureManager(m_textureManager);
    m_graphicsObject.SetPosition(0.0f,0.0f,0.0f);
    m_graphicsObject.SetScale(1.0f,1.0f,1.0f);
    m_graphicsObject.SetRotation(0.0f,0.0f,0.0f);
    m_graphicsObject.Load();
    */

    //m_shader.Init("./shaders/basicshader");
    m_camera.Init(glm::vec3(0,0,-4), 70.0f, (float)m_window.GetWidth()/(float)m_window.GetHeight(), 0.01f, 1000.0f);

    //m_texture.Create("./textures/bricks.png");
    //m_mesh.Create("./models/wyvern.obj");
}

void GameCore::update()
{
    float move_speed = 0.1f;
    m_ioManager.process();
    if (m_ioManager.state.quit)
        setGameState(RoboEngine::EXIT);
    if (m_ioManager.state.key_w)
        m_camera.SetPosition(glm::vec3(m_camera.GetPosition().x, m_camera.GetPosition().y, m_camera.GetPosition().z - move_speed));
    if (m_ioManager.state.key_s)
        m_camera.SetPosition(glm::vec3(m_camera.GetPosition().x, m_camera.GetPosition().y, m_camera.GetPosition().z + move_speed));
    if (m_ioManager.state.key_a)
        m_camera.SetPosition(glm::vec3(m_camera.GetPosition().x - move_speed, m_camera.GetPosition().y, m_camera.GetPosition().z));
    if (m_ioManager.state.key_d)
        m_camera.SetPosition(glm::vec3(m_camera.GetPosition().x + move_speed, m_camera.GetPosition().y, m_camera.GetPosition().z));
    if (m_ioManager.state.key_z)
        m_camera.SetPosition(glm::vec3(m_camera.GetPosition().x, m_camera.GetPosition().y - move_speed, m_camera.GetPosition().z));
    if (m_ioManager.state.key_c)
        m_camera.SetPosition(glm::vec3(m_camera.GetPosition().x, m_camera.GetPosition().y + move_speed, m_camera.GetPosition().z));
    if (m_ioManager.state.key_r)
        m_transform.GetRot().x += 1;
    if (m_ioManager.state.key_t)
        m_transform.GetRot().x -= 1;
    if (m_ioManager.state.key_f)
        m_transform.GetRot().y += 1;
    if (m_ioManager.state.key_g)
        m_transform.GetRot().y -= 1;
    if (m_ioManager.state.key_v)
        m_transform.GetRot().z += 1;
    if (m_ioManager.state.key_b)
        m_transform.GetRot().z -= 1;
    m_window.Update();
}

void GameCore::draw()
{
    if (m_window.IsOpen())
    {
        m_map.Draw(m_transform, m_camera);

        //m_transform.GetRot().y += 1;
        //m_transform.GetRot().z += 1;
        //m_graphicsObject.Update(m_transform, m_camera);
        //m_graphicsObject.Draw();

        //m_shader.Update(m_transform, m_camera);
        //m_shader.Bind();
        //m_texture.Bind(0);
        //m_mesh.Draw();
    }
}

