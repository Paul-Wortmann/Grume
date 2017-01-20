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

#ifndef RE_MANAGER_MESH_HPP
#define RE_MANAGER_MESH_HPP

#include <string>
#include "../system/re_file.hpp"
#include "../core/re_types.hpp"
#include "re_loader_obj.hpp"
#include "re_loader_dae.hpp"

namespace RoboEngine
{

    struct re_sMesh
    {
        std::string fileName = "";
        uint64_t indexCount = 0;
        v8_f* index = nullptr;
        re_sMesh *next = nullptr;
    };

    class re_cManagerMesh
    {
        public:
            re_cManagerMesh(void) {}
            ~re_cManagerMesh(void) {}
            inline re_cManagerMesh(const re_cManagerMesh&) = default;
            inline re_cManagerMesh& operator=(const re_cManagerMesh& _rhs) {if (this == &_rhs) return *this; return *this;}
            inline const re_sMesh *getHead(void) {return m_head;}
            inline const re_sMesh *getTail(void) {return m_tail;}
            void freeAll(void);
            re_sMesh *getNew(const std::string &_fileName);
            re_sMesh *genNew(uint32_t _size);
        protected:
        private:
            void loadMesh(const std::string &_fileName, re_sMesh *&_mesh);
            void genMesh(uint32_t _size, re_sMesh *&_mesh);
            re_sMesh *m_head = nullptr;
            re_sMesh *m_tail = nullptr;
    };
}

#endif // RE_MANAGER_MESH_HPP
