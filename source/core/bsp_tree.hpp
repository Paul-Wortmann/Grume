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

#ifndef BSP_TREE_HPP
#define BSP_TREE_HPP

#include <cstdint>
#include <iostream>

// !!! This implementation is custom designed for this project. !!!

template<class T> class tcBspTree
{
    public:
        // Constructor
        inline tcBspTree(void)
        {

        }

        // Destructor
        inline ~tcBspTree(void)
        {

        }

        // Delete copy constructors
        inline tcBspTree(tcBspTree& _other) = delete;
        inline tcBspTree(const tcBspTree& _other) = delete;
        inline tcBspTree&operator=(const tcBspTree& other) = delete;

    protected:

    private:
        uint32 m_count = 0;
        T* m_head = nullptr;
        T* m_temp = nullptr;
};

#endif // LINKED_LIST_HPP
