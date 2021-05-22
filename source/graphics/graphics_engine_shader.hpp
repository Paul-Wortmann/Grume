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

#include "../includes.hpp"
#include "../utils/file_utils.hpp"

class cGraphicsEngineShader
{
    public:
        void initialize(void);
        void terminate(void);
        uint32 load(const std::string &_fileName);
        uint32 getID(void) {return m_shaderID;}
        uint32 getUniformLocation(const std::string &_name);
        uint32 getAttribLocation(const std::string &_name);
    
    protected:
        
    private:
        uint32 m_shaderID = 0;
};

#endif //GRAPHICS_ENGINE_SHADER_HPP