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

#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "../core/includes.hpp"
#include "material_manager.hpp"
#include "model_manager.hpp"

class cResourceManager :tcTemplateManager
{
    public:
        std::uint32_t  initialize(void) override;
        void           terminate(void) override;
        void           process(const std::int64_t &_dt) override;

        // Model
        sEntityModel*  loadModel(const std::string &_fileName);

        // Material
        sMaterial*     loadMaterial(const std::string &_fileName);

        // Texture
        sTexture*      loadTexture(const std::string &_fileName);

        // GLFW Image
        GLFWimage*     loadGLFWImage(const std::string &_fileName);

        // Save screenshot
        void           savePNG(const std::string &_fileName);

        // Image manipulation
        unsigned char* m_flipImage(const std::uint32_t &_width, const std::uint32_t &_height, const std::uint32_t &_bitsPerPixel, const unsigned char* _image);

        // Font
        std::uint32_t initializeFont(void) { return m_materialManager.initializeFont(); };
        sTexture*     generateTexture(const std::string &_text) { return m_materialManager.generateTexture(_text); };
        sTexture*     generateTexture(const std::string &_text, const glm::vec4 &_color) { return m_materialManager.generateTexture(_text, _color); };

    protected:

    private:
        cMaterialManager m_materialManager = {};
        cModelManager    m_modelManager    = {};
};

#endif // RESOURCE_MANAGER_HPP
