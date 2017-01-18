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
#include "../core/re_log.hpp"
#include "../resource/lodepng.h"
#include "../roboengine.hpp"

namespace RoboEngine
{

    uint32_t loadTexture(const std::string& _fileName)
    {
        uint32_t textureID = 0;
        std::vector<unsigned char> image;
        unsigned width, height;
        unsigned error = lodepng::decode(image, width, height, _fileName);
        if (error)
        {
            re_logWrite(" Failed to decode png : " + _fileName + "(" + std::to_string(error) + ") : " + lodepng_error_text(error), RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            return textureID;
        }
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
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
