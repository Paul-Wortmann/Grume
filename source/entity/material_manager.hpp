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
#include "entity_material.hpp"
#include "../core/linked_list.hpp"
#include "texture_manager.hpp"

class cMaterialManager : public tcLinkedList<sEntityMaterial>
{
    public:
        void             initialize(void);
        void             terminate(void);
        bool             isLoaded(const std::string &_diffuse, const std::string &_emissive, const std::string &_normal, const std::string &_specular);
        sEntityMaterial* add(std::string _diffuse, std::string _emissive, std::string _normal, std::string _specular);
        sEntityTexture*  loadTexture(const std::string &_fileName);
        GLFWimage*       loadIcon(const std::string &_fileName);
        void             freeIcon(GLFWimage *&_image);
        void             saveScreenShot(const std::string &_fileName) { textureManager.savePNG(_fileName); };
        
    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sEntityMaterial*& _pointer);
        
        cTextureManager textureManager;
};



#endif // MATERIAL_MANAGER_HPP
