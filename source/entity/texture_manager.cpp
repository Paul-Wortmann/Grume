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

}

void cTextureManager::terminate(void)
{
    m_freeAll();
}

void cTextureManager::m_freeData(sEntityTexture*& _pointer)
{
    if (_pointer->ID != 0)
    {
        glDeleteTextures(1, &_pointer->ID);
    }
}

void cTextureManager::m_freeAll(void)
{
    for (sEntityTexture* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

sEntityTexture* cTextureManager::load(const std::string &_fileName)
{
    for (sEntityTexture* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if (temp->fileName.compare(_fileName) == 0)
        {
            return temp;
        }
    }
    
    // Add a short delay to prevent CPU sturation;
    gThreadSleep(1);
    
    int width      = 0;
    int height     = 0;
    int numChannel = 0;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load((std::string(FILE_PATH_TEXTURE)+_fileName).c_str(), &width, &height, &numChannel, 0);
    if (data)
    {
        // Setup format enum based on the number of channels in the image
        GLenum format = 0;
        if (numChannel == 1)
            format = GL_RED;
        else if (numChannel == 3)
            format = GL_RGB;
        else if (numChannel == 4)
            format = GL_RGBA;
        
        // Create a new texture pointer
        sEntityTexture* texture = getNew();
        texture->fileName = _fileName;
        glGenTextures(1, &texture->ID);
        glBindTexture(GL_TEXTURE_2D, texture->ID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        return texture;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to laod texture: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}

sEntityTexture* cTextureManager::loadPNG(const std::string &_fileName)
{
    std::vector<unsigned char> image;
    std::uint32_t width  = 0;
    std::uint32_t height = 0;
    std::uint32_t error = lodepng::decode(image, width, height, _fileName);
    if (error == 0) // No error
    {
        
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to laod texture: " + std::string(FILE_PATH_TEXTURE) + _fileName + " - " + lodepng_error_text(error), __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}
