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


#include "texture_manager.hpp"

void cTextureManager::initialize(void)
{
    add(TEXTURE_DEFAULT_DIFFUSE);
    add(TEXTURE_DEFAULT_NORMAL);
    add(TEXTURE_DEFAULT_SPECULAR);
}

void cTextureManager::terminate(void)
{
    freeTextures();
}

void cTextureManager::freeTexture(uint32_t _ID)
{
    glDeleteTextures(1, &_ID);
}

void cTextureManager::freeTextures(void)
{
    if (m_textureHead != nullptr)
    {
        sTextureNode *textureDel = m_textureHead;
        for(m_textureTemp = m_textureHead->next; m_textureTemp != nullptr; m_textureTemp = m_textureTemp->next)
        {
            if (textureDel != nullptr)
            {
                freeTexture(textureDel->ID);
                delete textureDel;
                textureDel = nullptr;
            }
            textureDel = m_textureTemp;
        }
        if (textureDel != nullptr)
        {
            freeTexture(textureDel->ID);
            delete textureDel;
            textureDel = nullptr;
        }
    }
    m_textureHead = nullptr;
    m_textureTail = nullptr;
    m_textureTemp = nullptr;
    m_count = 0;
}

uint32_t cTextureManager::add(const std::string &_fileName)
{
    if (m_textureHead == nullptr)
    {
        m_textureHead = new sTextureNode;
        m_textureTail = m_textureHead;
    }
    else
    {
        for(m_textureTemp = m_textureHead; m_textureTemp != nullptr; m_textureTemp = m_textureTemp->next)
            if (std::strcmp(_fileName.c_str(), m_textureTemp->fileName.c_str()) == 0)
                return m_textureTemp->ID;
        m_textureTail->next = new sTextureNode;
        m_textureTail = m_textureTail->next;
    }
    m_count++;
    m_textureTail->fileName = _fileName;
    m_textureTail->ID = load(_fileName);
    return m_textureTail->ID;
}

uint32_t cTextureManager::load(const std::string &_fileName)
{
    uint32_t textureID;
    glGenTextures(1, &textureID);

    int32_t width, height, nrComponents;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *data = stbi_load(std::string(PATH_TEXTURES + _fileName).c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        gLogWrite(LOG_INFO, "cTextureManager - Loading file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        GLenum format = 0;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        gLogWrite(LOG_ERROR, "cTextureManager - Error loading file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        stbi_image_free(data);
    }

    return textureID;
}
