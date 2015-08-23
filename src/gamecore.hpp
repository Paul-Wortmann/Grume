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

#ifndef GAMECORE_H
#define GAMECORE_H

#include <../RoboEngine/maingame.hpp>
#include <../RoboEngine/graphics_engine/window.hpp>
#include <../RoboEngine/resource_management/texturemanager.hpp>
#include <../RoboEngine/resource_management/shadermanager.hpp>
#include <../RoboEngine/resource_management/meshmanager.hpp>
#include <../RoboEngine/system/config.hpp>
#include <../RoboEngine/system/iomanager.hpp>
#include <../RoboEngine/graphics_engine/camera.hpp>
#include <../RoboEngine/graphics_engine/shader.hpp>
#include <../RoboEngine/graphics_engine/transform.hpp>
#include <../RoboEngine/graphics_engine/texture.hpp>
#include <../RoboEngine/graphics_engine/mesh.hpp>
#include <../RoboEngine/graphics_engine/graphicsobject.hpp>

#include "map.hpp"

class GameCore : public RoboEngine::MainGame
{
    public:
            void init(int argc, char** argv);
            void update();
            void draw();
    protected:
    private:
        RoboEngine::Config         m_config;
        RoboEngine::Window         m_window;
        RoboEngine::MeshManager    m_meshManager;
        RoboEngine::ShaderManager  m_shaderManager;
        RoboEngine::TextureManager m_textureManager;
        RoboEngine::IOManager      m_ioManager;
        RoboEngine::Camera         m_camera;
        RoboEngine::Transform      m_transform;
        Map                        m_map;
        //RoboEngine::Shader         m_shader;
        //RoboEngine::Texture        m_texture;
        //RoboEngine::Mesh           m_mesh;
        RoboEngine::GraphicsObject m_graphicsObject;

};


#endif // GAMECORE_H
