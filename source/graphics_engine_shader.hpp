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

#ifndef GRAPHICS_ENGINE_SHADER_HPP
#define GRAPHICS_ENGINE_SHADER_HPP

#include "defines.hpp"
#include "includes.hpp"

class cShader
{
    private:

    public:
        cShader(void) {};
        ~cShader(void) { if (m_programID != 0) glDeleteShader(m_programID); }
        uint32_t load(const std::string &_fileName);
        uint32_t getID(void) { return m_programID; }
        void     use(void);
        uint32_t getAnimationEnabledID(void)    { return m_animationEnabledID; }
        uint32_t getModelMatrixID(void)         { return m_modelMatrixID; }
        uint32_t getViewMatrixID(void)          { return m_viewMatrixID; }
        uint32_t getBoneMatrixID(uint32_t _num) { return m_boneID[_num]; }
        uint32_t getProjectionMatrixID(void)    { return m_projectionMatrixID; }
        uint32_t getTextureDiffuseID(void)      { return m_textureDiffuseID; }
        uint32_t getTextureNormalID(void)       { return m_textureNormalID; }
        uint32_t getTextureSpecularID(void)     { return m_textureSpecularID; }

    protected:

    private:
        void m_setupIDs(void);
        
        uint32_t m_programID          = 0;
        uint32_t m_animationEnabledID = 0;
        uint32_t m_modelMatrixID      = 0;
        uint32_t m_viewMatrixID       = 0;
        uint32_t m_projectionMatrixID = 0;
        uint32_t m_textureDiffuseID   = 0;
        uint32_t m_textureNormalID    = 0;
        uint32_t m_textureSpecularID  = 0;
        uint32_t m_boneID[MAX_BONES]  = {0};
};

#endif //GRAPHICS_ENGINE_SHADER_HPP

