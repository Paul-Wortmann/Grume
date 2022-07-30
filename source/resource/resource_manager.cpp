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

#include "resource_manager.hpp"

std::uint32_t cResourceManager::initialize(void)
{
    std::uint32_t returnValue = EXIT_SUCCESS;
    returnValue = (returnValue == EXIT_SUCCESS) ? m_materialManager.initialize() : returnValue;
    returnValue = (returnValue == EXIT_SUCCESS) ? m_modelManager.initialize() : returnValue;
    return returnValue;
}

void cResourceManager::terminate(void)
{
    m_modelManager.terminate();
    m_materialManager.terminate();
}

void cResourceManager::process(const float &_dt)
{

}

sEntityModel* cResourceManager::loadModel(const std::string &_fileName)
{
    return m_modelManager.load(_fileName);
}

sMaterial* cResourceManager::loadMaterial(const std::string &_fileName)
{
    return m_materialManager.load(_fileName);
}

sTexture* cResourceManager::loadTexture(const std::string &_fileName)
{
    return m_materialManager.loadTexture(_fileName);
}

GLFWimage* cResourceManager::loadGLFWImage(const std::string &_fileName)
{
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
        gLogWrite(LOG_ERROR, "Error - Failed to load icon: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}

void cResourceManager::savePNG(const std::string &_fileName)
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

    // Alpha fix
    std::uint32_t pixelCount = width * height * bitsPerPixel;
    for (std::uint32_t i = 3; i < pixelCount; i += 4)
    {
        imageOut[i] = 255;
    }

    // Write the image to disk
    //std::uint32_t error = lodepng::encode(_fileName, imageOut, width, height);
    std::uint32_t error = stbi_write_png(_fileName.c_str(), width, height, bitsPerPixel, imageOut, width * bitsPerPixel);

    if (error != 1)
    {
        //gLogWrite(LOG_ERROR, "Error - Failed to save image: " + std::string(FILE_PATH_TEXTURE) + _fileName + " - " + lodepng_error_text(error), __FILE__, __LINE__, __FUNCTION__);
        gLogWrite(LOG_ERROR, "Error - Failed to save image: " + std::string(FILE_PATH_TEXTURE) + _fileName + " - " + std::to_string(error), __FILE__, __LINE__, __FUNCTION__);
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

unsigned char* cResourceManager::m_flipImage(const std::uint32_t &_width, const std::uint32_t &_height, const std::uint32_t &_bitsPerPixel, const unsigned char* _image)
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
