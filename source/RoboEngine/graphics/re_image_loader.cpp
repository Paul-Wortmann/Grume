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

#include "re_image_loader.hpp"
#include "../system/re_log.hpp"
#include "../wrappers/re_sdl_image.hpp"
#include "../wrappers/re_opengl.hpp"

namespace RoboEngine
{

    uint32_t loadTexture(const std::string& _fileName)
    {
        uint32_t textureID = 0;
        RE_Surface *image = nullptr;
        image = RE_IMG_Load(_fileName.c_str());
        if(image == nullptr)
        {
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, " Failed to load texture: " + _fileName);
            return textureID;
        }
        RE_glGenTextures(1, &textureID);
        RE_glBindTexture(RE_GL_TEXTURE_2D, textureID);
        RE_glTexImage2D(RE_GL_TEXTURE_2D, 0, RE_GL_RGBA, image->w, image->h, 0, RE_GL_RGBA, RE_GL_UNSIGNED_BYTE, image->pixels);
        RE_glTexParameteri(RE_GL_TEXTURE_2D, RE_GL_TEXTURE_WRAP_S, RE_GL_REPEAT);
        RE_glTexParameteri(RE_GL_TEXTURE_2D, RE_GL_TEXTURE_WRAP_T, RE_GL_REPEAT);
        RE_glTexParameterf(RE_GL_TEXTURE_2D, RE_GL_TEXTURE_MIN_FILTER, RE_GL_LINEAR_MIPMAP_LINEAR);
        RE_glTexParameterf(RE_GL_TEXTURE_2D, RE_GL_TEXTURE_MAG_FILTER, RE_GL_LINEAR);
        RE_glGenerateMipmap(RE_GL_TEXTURE_2D);
        RE_glBindTexture(RE_GL_TEXTURE_2D, 0);
        RE_FreeSurface(image);
        return textureID;
    }

}
