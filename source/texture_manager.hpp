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


#ifndef MANAGER_TEXTURE_HPP
#define MANAGER_TEXTURE_HPP

#include "includes.hpp"
#include "defines.hpp"
#include "texture_loader.hpp"

struct sTextureNode
{
    sTextureNode *next     = nullptr;
    uint32_t      ID       = 0;
    std::string   fileName = "";
};

class cTextureManager
{
    public:
        void initialize(void);
        void freeTextures(void);
        uint32_t add(const std::string &_fileName);

    protected:
    private:
        void freeTexture(uint32_t _ID);
        uint32_t load(const std::string &_fileName);
        
        uint32_t      m_count       = 0;
        sTextureNode *m_textureHead = nullptr;
        sTextureNode *m_textureTail = nullptr;
        sTextureNode *m_textureTemp = nullptr;
}; 

#endif //MANAGER_TEXTURE_HPP
