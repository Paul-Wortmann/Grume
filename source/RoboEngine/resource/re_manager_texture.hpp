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

#ifndef RE_MANAGER_TEXTURE_HPP
#define RE_MANAGER_TEXTURE_HPP

#include "../graphics/re_image_loader.hpp"
#include <string>

namespace RoboEngine
{

    struct re_sTexture
    {
            std::string fileName = "";
            uint32_t ID = 0;
            re_sTexture *next = nullptr;
    };

    class re_cTextureManager
    {
        public:
            re_cTextureManager(void) {}
            ~re_cTextureManager(void) {}
            inline re_cTextureManager(const re_cTextureManager&) = default;
            inline re_cTextureManager& operator=(const re_cTextureManager& _rhs) {if (this == &_rhs) return *this; return *this;}
            inline const re_sTexture *getHead(void) {return m_head;}
            inline const re_sTexture *getTail(void) {return m_tail;}
            void freeAll(void);
            re_sTexture *getNew(std::string _fileName);
        protected:
        private:
            re_sTexture *m_head = nullptr;
            re_sTexture *m_tail = nullptr;
    };
}

#endif // RE_MANAGER_TEXTURE_HPP
