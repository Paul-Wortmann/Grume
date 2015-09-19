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

#ifndef MAP_H
#define MAP_H

#include <../RoboEngine/graphics_engine/camera.hpp>
#include <../RoboEngine/graphics_engine/graphicsobject.hpp>
#include <../RoboEngine/graphics_engine/transform.hpp>
#include <../RoboEngine/resource_management/texturemanager.hpp>
#include <../RoboEngine/resource_management/shadermanager.hpp>
#include <../RoboEngine/resource_management/meshmanager.hpp>

#include <string>

class Map
{
    public:
        Map() {}
        virtual ~Map() {if (m_tile) delete m_tile;}
        Map(const Map& other) {}
        Map& operator=(const Map& other) {if (this == &other) return *this;}
        void Load(const std::string& FileName, const RoboEngine::MeshManager& meshManager, const RoboEngine::ShaderManager& shaderManager, const RoboEngine::TextureManager& textureManager);
        void Draw(const RoboEngine::Transform& transform, const RoboEngine::Camera& camera);
        unsigned int getSize() {return m_size;}
    protected:
    private:
        enum
        {
            XML_BLOCK_UNKNOWN,
            XML_BLOCK_MAP,
            XML_BLOCK_TILE,

            XML_KEY_UNKNOWN,
            XML_KEY_SIZE,
            XML_KEY_SIZE_TILE,
            XML_KEY_POSITION,
            XML_KEY_TILE_DEFAULT_TEXTURE,
            XML_KEY_TEXTURE
        };
        unsigned int m_size_x = 0;
        unsigned int m_size_y = 0;
        unsigned int m_size   = 0;
        float m_tile_size_x   = 0.1f;
        float m_tile_size_y   = 0.1f;
        RoboEngine::GraphicsObject* m_tile;
};

#endif // MAP_H
