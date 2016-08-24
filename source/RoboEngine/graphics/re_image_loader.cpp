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

#include <GL/glew.h>

#include <stdio.h>
#include <cstring>

#include "re_image_loader.hpp"
#include "../system/re_file.hpp"
#include "../system/re_log.hpp"
#include "../resource/picopng.hpp"

namespace RoboEngine
{

    uint32_t loadTexture(const std::string& _fileName)
    {
        uint32_t textureID = 0;
        unsigned long width = 0;
        unsigned long height = 0;
        std::vector<unsigned char> in_image;
        if (!fileToBufferV(_fileName, in_image))
        {
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, " Failed to load texture : " + _fileName);
        }
        std::vector<unsigned char> out_image;
        int32_t statusPNG = decodePNG(out_image, width, height, &in_image[0] , in_image.size());
        if (statusPNG != 0)
        {
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, " Failed to decode png (" + std::to_string(statusPNG) + ") : " + _fileName);
            return textureID;
        }
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &out_image[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        return textureID;
    }

    void freeTexture(uint32_t _textureID)
    {
        uint32_t *_textureArray = new uint32_t[1];
        _textureArray[0] = _textureID;
        glDeleteTextures(1, _textureArray);
        delete [] _textureArray;
    }

}
