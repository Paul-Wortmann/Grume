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

#include "texture_manager.hpp"

std::uint32_t cTextureManager::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    return_value = (return_value == EXIT_SUCCESS) ? m_fontManager.initialize("aileron_001.otf") : return_value;

    return return_value;
}

void cTextureManager::freeData(sTexture*& _pointer)
{
    if (_pointer->ID != 0)
    {
        glDeleteTextures(1, &_pointer->ID);
        _pointer->ID = 0;
    }
}

void cTextureManager::terminate(void)
{
    freeAll();
    m_fontManager.terminate();
}

sTexture* cTextureManager::getFreePointer(void)
{
    // If an unused pointer is available, reuse it
    for (sTexture* tempReuse = getHead(); tempReuse != nullptr; tempReuse = tempReuse->next)
    {
        if (tempReuse->enabled == false)
        {
            tempReuse->enabled = true;
            tempReuse->numInstance++;
            return tempReuse;
        }
    }

    // Allocate memory and return a new pointer
    sTexture* tempNew = getNew();
    tempNew->enabled = true;
    tempNew->numInstance++;
    return tempNew;
}

void cTextureManager::setPointerFree(sTexture *&_pointer)
{
    // decrement the instance count
    _pointer->numInstance--;

    // if there are still instances in use, early exit
    if (_pointer->numInstance > 0)
    {
        return;
    }

    // free data and disabled
    freeData(_pointer);
    _pointer->enabled = false;
}

sTexture* cTextureManager::load(const std::string &_fileName)
{
    for (sTexture* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if ((temp->enabled == true) && (temp->fileName.compare(_fileName) == 0))
        {
            temp->numInstance++;
            return temp;
        }
    }

    std::int32_t width      = 0;
    std::int32_t height     = 0;
    std::int32_t numChannel = 0;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load((std::string(FILE_PATH_TEXTURE)+_fileName).c_str(), &width, &height, &numChannel, 0);

    // Create a texture
    if (data != nullptr)
    {
        // Texture is less that the smallest required by OpenGL
        if ((width < 64) || (height < 64))
        {
            gLogWrite(LOG_WARNING, "Texture size is too small: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        }

        // Setup format enum based on the number of channels in the image
        GLenum format = 0;
        if (numChannel == 1)
            format = GL_RED;
        else if (numChannel == 2)
            format = GL_RG;
        else if (numChannel == 3)
            format = GL_RGB;
        else if (numChannel == 4)
            format = GL_RGBA;

        // Create a new texture pointer
        sTexture* texture   = getFreePointer();
        texture->fileName   = _fileName;
        texture->width      = static_cast<std::uint32_t>(width);
        texture->height     = static_cast<std::uint32_t>(height);
        texture->numChannel = static_cast<std::uint32_t>(numChannel);
        glGenTextures(1, &texture->ID);
        glBindTexture(GL_TEXTURE_2D, texture->ID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
        return texture;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to load texture: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    // could not load texture
    return nullptr;
}

sTexture* cTextureManager::generateTexture(const std::string &_text)
{
    // If it already exists in memory, return a pointer to it
    for (sTexture* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if ((temp->enabled == true) && (temp->fileName.compare(_text) == 0))
        {
            temp->numInstance++;
            return temp;
        }
    }

    // Create a new texture pointer
    sTexture* texture   = getFreePointer();
    texture->fileName   = _text;
    texture->width      = 0;
    texture->height     = 0;
    texture->numChannel = 1; // GL_RED

    // Determine texture size
    std::uint64_t dataLength = _text.length();
    for (std::uint64_t i = 0; i < dataLength; i++)
    {
        sFontCharacter charData = m_fontManager.getFontCharacter(_text[i]);
        texture->width += charData.size.x;
        texture->height = (static_cast<std::uint32_t>(charData.size.y) > texture->height) ? static_cast<std::uint32_t>(charData.size.y) : texture->height;
    }

    // Create and fill the pixel buffer
    std::uint32_t xPos     = 0;
    std::uint32_t dataSize = texture->width * texture->height;
    unsigned char *data = new unsigned char[dataSize];
    for (std::uint32_t i = 0; i < dataSize; i++)
    {
        data[i] = 0;
    }

    for (std::uint64_t i = 0; i < dataLength; i++)
    {
        sFontCharacter charData = m_fontManager.getFontCharacter(_text[i]);
        for (std::uint32_t y = 0; y < static_cast<std::uint32_t>(charData.size.y); y++)
        {
            for (std::uint32_t x = 0; x < static_cast<std::uint32_t>(charData.size.x); x++)
            {
                data[(y * texture->width) + xPos + x] = charData.bitmap[(y * charData.size.x) + x];
            }
        }
        xPos += charData.size.x;
    }

    // Disable 4 byte packing alignment
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Generate OpenGL texture
    glGenTextures(1, &texture->ID);
    glBindTexture(GL_TEXTURE_2D, texture->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, texture->width, texture->height, 0, GL_RED, GL_UNSIGNED_BYTE, data);

    // Set texture options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //stbi_write_png("texture_out.png", texture->width, texture->height, 1, data, texture->width);

    // Cleanup
    delete[] data;

    // Return texture pointer
    return texture;
}

sTexture* cTextureManager::generateTexture(const std::string &_text, const glm::uvec4 &_color)
{
    // If it already exists in memory, return a pointer to it
    for (sTexture* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if ((temp->enabled == true) && (temp->fileName.compare(_text) == 0))
        {
            temp->numInstance++;
            return temp;
        }
    }

    // Create a new texture pointer
    sTexture* texture   = getFreePointer();
    texture->fileName   = _text;
    texture->width      = 0;
    texture->height     = 0;
    texture->numChannel = 1; // GL_RED

    // Determine texture size
    std::uint64_t dataLength = _text.length();
    for (std::uint64_t i = 0; i < dataLength; i++)
    {
        sFontCharacter charData = m_fontManager.getFontCharacter(_text[i]);
        texture->width += charData.size.x;
        texture->height = (static_cast<std::uint32_t>(charData.size.y) > texture->height) ? static_cast<std::uint32_t>(charData.size.y) : texture->height;
    }

    // Create and fill the pixel buffer
    std::uint32_t xPos     = 0;
    std::uint32_t dataSize = texture->width * texture->height;
    unsigned char *data = new unsigned char[dataSize];
    for (std::uint32_t i = 0; i < dataSize; i++)
    {
        data[i] = 0;
    }

    for (std::uint64_t i = 0; i < dataLength; i++)
    {
        sFontCharacter charData = m_fontManager.getFontCharacter(_text[i]);
        for (std::uint32_t y = 0; y < static_cast<std::uint32_t>(charData.size.y); y++)
        {
            for (std::uint32_t x = 0; x < static_cast<std::uint32_t>(charData.size.x); x++)
            {
                data[(y * texture->width) + xPos + x] = charData.bitmap[(y * charData.size.x) + x];
            }
        }
        xPos += charData.size.x;
    }

    // Convert GL_RED to GL_RGBA
    std::uint32_t dataSizeRGBA = texture->width * texture->height * 4;
    unsigned char *dataRGBA = new unsigned char[dataSizeRGBA];
    for (std::uint32_t i = 0; i < dataSize; i++)
    {
        dataRGBA[(i * 4) + 0] = static_cast<unsigned char>((data[i] > 0) ? _color.x : 0); // Red
        dataRGBA[(i * 4) + 1] = static_cast<unsigned char>((data[i] > 0) ? _color.y : 0); // Green
        dataRGBA[(i * 4) + 2] = static_cast<unsigned char>((data[i] > 0) ? _color.z : 0); // Blue
        dataRGBA[(i * 4) + 3] = static_cast<unsigned char>((data[i] > 0) ? _color.w : 0); // Alpha
    }

    // Disable 4 byte packing alignment
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Generate OpenGL texture
    glGenTextures(1, &texture->ID);
    glBindTexture(GL_TEXTURE_2D, texture->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataRGBA);

    // Set texture options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //stbi_write_png("texture_out.png", texture->width, texture->height, 1, data, texture->width);

    // Cleanup
    delete[] data;
    delete[] dataRGBA;

    // Return texture pointer
    return texture;
}
