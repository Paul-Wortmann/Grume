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

#ifndef MATERIAL_MANAGER_HPP
#define MATERIAL_MANAGER_HPP

#include "../core/includes.hpp"
#include "material_define.hpp"
#include "texture_manager.hpp"

class cMaterialManager : public tcLinkedList<sMaterial>
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        sMaterial*    load(const std::string &_fileName);

        // Texture
        sTexture*     loadTexture(const std::string &_fileName);

        // Font
        std::uint32_t initializeFont(void) { return m_textureManager.initializeFont(); };
        sTexture*     generateTexture(const std::string &_text) { return m_textureManager.generateTexture(_text); };
        sTexture*     generateTexture(const std::string &_text, const glm::uvec4 &_color) { return m_textureManager.generateTexture(_text, _color); };

    protected:

    private:
        void freeData(sMaterial *&_pointer) override;
        cTextureManager  m_textureManager  = {};

};

#endif // MATERIAL_MANAGER_HPP
