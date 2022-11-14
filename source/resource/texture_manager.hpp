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
#include "font_manager.hpp"
#include "texture_define.hpp"

class cTextureManager : public tcLinkedList<sTexture>
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        void          process(const float &_dt);
        sTexture*     load(const std::string &_fileName);

        // Font
        std::uint32_t initializeFont(void) { return m_fontManager.initializeFont(); };
        sTexture*     generateTexture(const std::string &_text);
        sTexture*     generateTexture(const std::string &_text, const glm::vec4 &_color);

    protected:

    private:
        cFontManager m_fontManager = {};
        void freeData(sTexture *&_pointer) override;

};

#endif // TEXTURE_MANAGER_HPP
