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

#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "../core/includes.hpp"
#include "entity_texture.hpp"
#include "font_manager.hpp"

class cTextureManager : public tcLinkedList<sEntityTexture>
{
    public:
        void initialize(void);
        void terminate(void);
        sEntityTexture* load(const std::string &_fileName);     // stb_image
        GLFWimage*      loadIcon(const std::string &_fileName); // stb_image
        void            freeIcon(GLFWimage *&_image);
        sEntityTexture* loadPNG(const std::string &_fileName); // lodepng - load
        void            savePNG(const std::string &_fileName); // lodepng - save
        sEntityTexture* textureFont(const std::string &_text); // Font manager generate font

    protected:

    private:
        cFontManager m_fontManager = {};
        
        void freeData(sEntityTexture*& _pointer) override;
        unsigned char* m_flipImage(const std::uint32_t &_width, const std::uint32_t &_height, const std::uint32_t &_bitsPerPixel, const unsigned char* _image);
        std::vector<unsigned char> m_flipImage(const std::uint32_t &_width, const std::uint32_t &_height, const std::uint32_t &_bitsPerPixel, std::vector<unsigned char> _image);

};

#endif // TEXTURE_MANAGER_HPP
