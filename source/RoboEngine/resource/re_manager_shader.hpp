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

#ifndef RE_MANAGER_SHADER_HPP
#define RE_MANAGER_SHADER_HPP

#include "../graphics/re_glsl.hpp"
#include <string>

namespace RoboEngine
{

    struct re_sShader
    {
            std::string fileName = "";
            uint32_t ID = 0;
            re_sShader *next = nullptr;
    };

    class re_cManagerShader
    {
        public:
            re_cManagerShader(void) {}
            ~re_cManagerShader(void) {}
            inline re_cManagerShader(const re_cManagerShader&) = default;
            inline re_cManagerShader& operator=(const re_cManagerShader& _rhs) {if (this == &_rhs) return *this; return *this;}
            inline const re_sShader *getHead(void) {return m_head;}
            inline const re_sShader *getTail(void) {return m_tail;}
            void freeAll(void);
            re_sShader *getNew(std::string _fileName);
        protected:
        private:
            re_sShader *m_head = nullptr;
            re_sShader *m_tail = nullptr;
    };
}

#endif // RE_MANAGER_SHADER_HPP
