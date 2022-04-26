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

void cTextureManager::initialize(void)
{
    m_fontManager.initialize("aileron_001.otf");
    m_fontManager.initializeFont();
}

void cTextureManager::terminate(void)
{
    m_fontManager.terminate();
    freeAll();
}

void cTextureManager::freeData(sEntityTexture*& _pointer)
{
    if (_pointer->ID != 0)
    {
        glDeleteTextures(1, &_pointer->ID);
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
    
    // Add a short delay to prevent CPU saturation;
    gThreadSleep(1);
    
    int width      = 0;
    int height     = 0;
    int numChannel = 0;
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
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
        return texture;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to load texture: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}

GLFWimage* cTextureManager::loadIcon(const std::string &_fileName)
{
    // Add a short delay to prevent CPU saturation;
    gThreadSleep(1);
    
    int width      = 0;
    int height     = 0;
    int numChannel = 0;
    stbi_set_flip_vertically_on_load(false);
    unsigned char *data = stbi_load((std::string(FILE_PATH_TEXTURE)+_fileName).c_str(), &width, &height, &numChannel, 0);
    if (data)
    {
        // Create gflw image and populate it with the loaded image data
        GLFWimage* tImage = new GLFWimage;
        tImage->width = width;
        tImage->height = height;
        std::uint32_t pixelCount = tImage->width * tImage->height * numChannel;
        tImage->pixels = new unsigned char[pixelCount];
        for (std::uint32_t i = 0; i < pixelCount; ++i)
        {
            tImage->pixels[i] = data[i];
        }

        // Cleanup and return
        stbi_image_free(data);
        return tImage;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to laod icon: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}

void cTextureManager::freeIcon(GLFWimage *&_image)
{
    if (_image != nullptr)
    {
        // Delete the data
        if (_image->pixels != nullptr)
        {
            delete _image->pixels;
            _image->pixels = nullptr;
        }
        
        // Delete the pointer
        delete _image;
        _image = nullptr;
    }
}

sEntityTexture* cTextureManager::loadPNG(const std::string &_fileName)
{
    std::vector<unsigned char> image;
    std::uint32_t width  = 0;
    std::uint32_t height = 0;
    std::uint32_t error = lodepng::decode(image, width, height, (std::string(FILE_PATH_TEXTURE)+_fileName).c_str());
    if (error == 0) // No error
    {
        // Flip the image data
        GLenum bitsPerPixel = 4; // RGBA
        std::vector<unsigned char> imageOut = m_flipImage(width, height, bitsPerPixel, image);
        
        // Create a new texture pointer
        sEntityTexture* texture = getNew();
        texture->fileName = _fileName;
        glGenTextures(1, &texture->ID);
        glBindTexture(GL_TEXTURE_2D, texture->ID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageOut[0]);
        glGenerateMipmap(GL_TEXTURE_2D);
        return texture;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to laod texture: " + std::string(FILE_PATH_TEXTURE) + _fileName + " - " + lodepng_error_text(error), __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}

void cTextureManager::savePNG(const std::string &_fileName)
{
    // Image width and height
    std::int32_t width  = 0;
    std::int32_t height = 0;
    std::int32_t bitsPerPixel = 4; // GL_RGBA

    // Get the framebuffer size
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &width);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &height);
    
    // Read the imaged data from the framebuffer
    unsigned char* image = new unsigned char[width * height * bitsPerPixel];
    glReadPixels(0.0, 0.0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image);
    unsigned char* imageOut = m_flipImage(width, height, bitsPerPixel, image);
    
    // Write the image to disk
    std::uint32_t error = lodepng::encode(_fileName, imageOut, width, height);
    
    if (error != 0)
    {
        gLogWrite(LOG_ERROR, "Error - Failed to save image: " + std::string(FILE_PATH_TEXTURE) + _fileName + " - " + lodepng_error_text(error), __FILE__, __LINE__, __FUNCTION__);
    }
    
    // clean up
    if (image != nullptr)
    {
        delete[] image;
        image = nullptr;
    }
    if (imageOut != nullptr)
    {
        delete[] imageOut;
        imageOut = nullptr;
    }
}

unsigned char* cTextureManager::m_flipImage(const std::uint32_t &_width, const std::uint32_t &_height, const std::uint32_t &_bitsPerPixel, const unsigned char* _image)
{
    // Dynamically allocate memory for the new image
    unsigned char* image = new unsigned char[_width * _height * _bitsPerPixel];
    
    // loop through the input image and write the data to the new image
    for (std::uint32_t h = 0; h < _height; ++h)
    {
        for (std::uint32_t w = 0; w < (_width * _bitsPerPixel); ++w)
        {
            image[(h * _width * _bitsPerPixel) + w] = _image[((_height - h - 1) * _width * _bitsPerPixel) + w];
        }
    }
    
    // return flipped image
    return image;
}

std::vector<unsigned char> cTextureManager::m_flipImage(const std::uint32_t &_width, const std::uint32_t &_height, const std::uint32_t &_bitsPerPixel, std::vector<unsigned char> _image)
{
    // Create and resize the output vector
    std::vector<unsigned char>  image;
    image.resize(_width * _height * _bitsPerPixel);
    
    // loop through the input image and write the data to the new image
    for (std::uint32_t h = 0; h < _height; ++h)
    {
        for (std::uint32_t w = 0; w < (_width * _bitsPerPixel); ++w)
        {
            image[(h * _width * _bitsPerPixel) + w] = _image[((_height - h - 1) * _width * _bitsPerPixel) + w];
        }
    }
    
    // return flipped image
    return image;
}

sEntityTexture* cTextureManager::textureFont(const std::string &_text)
{
    // Generate image
    std::uint32_t  width  = 0;
    std::uint32_t  height = 0;
    unsigned char* imageBuffer = nullptr;
    //m_fontManager.generateImage(_text, width, height, imageBuffer);
    
    // Assume  RGBA
    std::uint32_t format = GL_RGBA;
    
    // Create the texture
    if (imageBuffer != nullptr)
    {
        sEntityTexture* texture = getNew();
        texture->fileName = _text;
        glGenTextures(1, &texture->ID);
        glBindTexture(GL_TEXTURE_2D, texture->ID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageBuffer);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        
        // clean up
        if (imageBuffer != nullptr)
        {
            delete[] imageBuffer;
            imageBuffer = nullptr;
        }

        // Return the texture
        return texture;
    }
    
    // Failed to load
    return nullptr;
}
