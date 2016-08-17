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

#ifndef C_GLSL_HPP
#define C_GLSL_HPP

#include <string>
#include <fstream>
#include <vector>
#include "../wrappers/re_opengl.hpp"
#include "../system/re_log.hpp"
#include "../system/re_file.hpp"

namespace RoboEngine
{

    class re_cglsl
    {
        public:
            re_cglsl() {}
            virtual ~re_cglsl() {}
            void compileShaders(const std::string &_file_name);
            void linkShaders(void);
            void addAttribute(const std::string &_attributeName);
            int32_t getUniformLocation(const std::string &_uniformName);
            void use(void);
            void unuse(void);
        protected:
        private:
            uint16_t m_numAttributes = 0;
            uint32_t m_program_ID = 0;
            uint32_t m_shaderVS_ID = 0;
            uint32_t m_shaderFS_ID = 0;
            enum e_shader_type {VERTEX, FRAGMENT};
            void compileShader(const std::string &_file_name, e_shader_type _type);
    };

}

#endif // C_GLSL_HPP
