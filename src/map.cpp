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

#include "map.h"
#include <../RoboEngine/resource_management/xmlparser.h>

void Map::Load(const std::string& FileName, const RoboEngine::MeshManager& meshManager, const RoboEngine::ShaderManager& shaderManager, const RoboEngine::TextureManager& textureManager)
{
    RoboEngine::ParserXML xmlParser;
    xmlParser.load(FileName);
    /*
    unsigned int block_type = XML_BLOCK_UNKNOWN;
    unsigned int key_type   = XML_KEY_UNKNOWN;
    RoboEngine::xml_type      xmlData;
    RoboEngine::ParserXML     xmlParser;
    xmlParser.load(xmlData, FileName);
    std::string fileNameShader = "";
    std::string fileNameMesh = "";
    std::string fileNameTexture = "";
    for (int i = 0; i < xmlData.number_of_data; i++)
    {
        if (xmlData.data[i].key_present)
        {
            if (xmlData.data[i].key.compare("map")                   == 0) block_type = XML_BLOCK_MAP;
            if (xmlData.data[i].key.compare("/map")                  == 0) block_type = XML_BLOCK_UNKNOWN;
            if (xmlData.data[i].key.compare("tile")                  == 0) block_type = XML_BLOCK_TILE;
            if (xmlData.data[i].key.compare("/tile")                 == 0) block_type = XML_BLOCK_TILE;
            if (xmlData.data[i].key.compare("default_tile_texture")  == 0) key_type = XML_KEY_TILE_DEFAULT_TEXTURE;
            if (xmlData.data[i].key.compare("/default_tile_texture") == 0) key_type = XML_KEY_TILE_DEFAULT_TEXTURE;
            if (xmlData.data[i].key.compare("texture")               == 0) key_type = XML_KEY_TEXTURE;
            if (xmlData.data[i].key.compare("/texture")              == 0) key_type = XML_KEY_UNKNOWN;
            if (xmlData.data[i].key.compare("position")              == 0) key_type = XML_KEY_POSITION;
            if (xmlData.data[i].key.compare("/position")             == 0) key_type = XML_KEY_UNKNOWN;
            if (xmlData.data[i].key.compare("size")                  == 0) key_type = XML_KEY_SIZE;
            if (xmlData.data[i].key.compare("/size")                 == 0) key_type = XML_KEY_UNKNOWN;
            if (xmlData.data[i].key.compare("tile_size")             == 0) key_type = XML_KEY_SIZE_TILE;
            if (xmlData.data[i].key.compare("/tile_size")            == 0) key_type = XML_KEY_UNKNOWN;
        }
        if ((block_type == XML_BLOCK_MAP) && (xmlData.data[i].key_present) && (xmlData.data[i].value_present))
        {
            if (xmlData.data[i].key.compare("obj")    == 0) fileNameMesh   = xmlData.data[i].value;
            if (xmlData.data[i].key.compare("shader") == 0) fileNameShader = xmlData.data[i].value;
            if ((xmlData.data[i].key.compare("diffuse") == 0) && (key_type == XML_KEY_TILE_DEFAULT_TEXTURE)) fileNameTexture = xmlData.data[i].value;
            if ((xmlData.data[i].key.compare("x") == 0) && (key_type == XML_KEY_SIZE)) m_size_x = atoi(xmlData.data[i].value.c_str());
            if ((xmlData.data[i].key.compare("y") == 0) && (key_type == XML_KEY_SIZE)) m_size_y = atoi(xmlData.data[i].value.c_str());
            if ((xmlData.data[i].key.compare("x") == 0) && (key_type == XML_KEY_SIZE_TILE)) m_tile_size_x = atof(xmlData.data[i].value.c_str());
            if ((xmlData.data[i].key.compare("y") == 0) && (key_type == XML_KEY_SIZE_TILE)) m_tile_size_y = atof(xmlData.data[i].value.c_str());
        }
    }
    m_size = m_size_x * m_size_y;
    unsigned int temp_x = 0;
    unsigned int temp_y = 0;
    std::string fileNameTempTexture[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        fileNameTempTexture[i] = fileNameTexture;
    }
    for (int i = 0; i < xmlData.number_of_data; i++)
    {
        if (xmlData.data[i].key_present)
        {
            if (xmlData.data[i].key.compare("map")                   == 0) block_type = XML_BLOCK_MAP;
            if (xmlData.data[i].key.compare("/map")                  == 0) block_type = XML_BLOCK_UNKNOWN;
            if (xmlData.data[i].key.compare("tile")                  == 0) block_type = XML_BLOCK_TILE;
            if (xmlData.data[i].key.compare("/tile")                 == 0) block_type = XML_BLOCK_TILE;
            if (xmlData.data[i].key.compare("default_tile_texture")  == 0) key_type = XML_KEY_TILE_DEFAULT_TEXTURE;
            if (xmlData.data[i].key.compare("/default_tile_texture") == 0) key_type = XML_KEY_TILE_DEFAULT_TEXTURE;
            if (xmlData.data[i].key.compare("texture")               == 0) key_type = XML_KEY_TEXTURE;
            if (xmlData.data[i].key.compare("/texture")              == 0) key_type = XML_KEY_UNKNOWN;
            if (xmlData.data[i].key.compare("position")              == 0) key_type = XML_KEY_POSITION;
            if (xmlData.data[i].key.compare("/position")             == 0) key_type = XML_KEY_UNKNOWN;
            if (xmlData.data[i].key.compare("size")                  == 0) key_type = XML_KEY_SIZE;
            if (xmlData.data[i].key.compare("/size")                 == 0) key_type = XML_KEY_UNKNOWN;
            if (xmlData.data[i].key.compare("tile_size")             == 0) key_type = XML_KEY_SIZE_TILE;
            if (xmlData.data[i].key.compare("/tile_size")            == 0) key_type = XML_KEY_UNKNOWN;
        }
        if ((block_type == XML_BLOCK_TILE) && (xmlData.data[i].key_present) && (xmlData.data[i].value_present))
        {
            if ((xmlData.data[i].key.compare("x") == 0) && (key_type == XML_KEY_POSITION)) temp_x = atoi(xmlData.data[i].value.c_str());
            if ((xmlData.data[i].key.compare("y") == 0) && (key_type == XML_KEY_POSITION)) temp_y = atoi(xmlData.data[i].value.c_str());
            if ((xmlData.data[i].key.compare("diffuse") == 0) && (key_type == XML_KEY_TEXTURE)) fileNameTempTexture[(temp_y*m_size_x)+temp_x] = xmlData.data[i].value;
        }
    }
    m_tile = new RoboEngine::GraphicsObject[m_size];
    unsigned int k = 0;
    for (unsigned int i = 0; i < m_size_y; i++)
    {
        for (unsigned int j = 0; j < m_size_x; j++)
        {
            k = (i*m_size_x)+j;
            m_tile[k].SetMesh(fileNameMesh);
            m_tile[k].SetShader(fileNameShader);
            m_tile[k].SetTexture(fileNameTempTexture[k]);
            m_tile[k].SetMeshManager(meshManager);
            m_tile[k].SetShaderManager(shaderManager);
            m_tile[k].SetTextureManager(textureManager);
            m_tile[k].SetPosition(m_tile_size_x*j,m_tile_size_y*i,0.0f);
            m_tile[k].SetScale(1.0f,1.0f,1.0f);
            m_tile[k].SetRotation(0.0f,0.0f,0.0f);
            m_tile[k].Load();
        }
    }
    */
}

void Map::Draw(const RoboEngine::Transform& transform, const RoboEngine::Camera& camera)
{
    for (unsigned int i = 0; i < m_size; i++)
    {
        //m_tile[i].Update(transform,camera);
        //m_tile[i].Draw();
    }
}
