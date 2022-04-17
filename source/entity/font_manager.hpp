
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

#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP

#include "../core/includes.hpp"

struct sFontCharacter
{
    glm::ivec2     size    = glm::ivec2(0, 0);
    glm::ivec2     bearing = glm::ivec2(0, 0);
    std::uint32_t  advance = 0;
    unsigned char* bitmap  = nullptr;
};

class cFontManager
{
    public:
        std::uint32_t  initialize(const std::string &_fileName);
        void           terminate(void);
        sFontCharacter getFontCharacter(const char &_char) { return m_characters[_char]; };
        std::uint32_t  initializeFont(void);

        // cruft
        void           generateImage(const std::string &_string, std::uint32_t &_width, std::uint32_t &_height, unsigned char* &_imageBuffer) { m_fontToImage(_string, _width, _height, _imageBuffer); }

    protected:
    private:
        std::map<char, sFontCharacter> m_characters;
        void          m_generateGlyphs(void);
        std::uint32_t m_fontPixelSize = 96;


        // cruft
        std::string    m_fileName   = "aileron_001.otf";
        char*          m_fontBuffer = nullptr;
        stbtt_fontinfo m_fontInfo   = {};
        std::uint32_t  m_pixelSize  = 96;
        
        void m_convertAlphaToRGBA(const std::uint32_t &_width, const std::uint32_t &_height, unsigned char* &_imageBuffer);
        void m_fontToImage(const std::string &_string, std::uint32_t &_width, std::uint32_t &_height, unsigned char* &_imageBuffer);
};

#endif //FONT_MANAGER_HPP
