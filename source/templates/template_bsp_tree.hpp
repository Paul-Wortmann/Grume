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

// Define datatypes
#include "../core/defines_types.hpp"

// !!! This implementation is custom designed for this project. !!!

// Note The tree maintains the head node, which is only freed by the destructor.
// The reason being is to maintain the same pointer to the bsp tree head which
// is required by external classes that share the head node to reference the tree.
// While external classes could keep updating their pointer to the tree, it is
// more efficient to avoid unnecessary function calls for performance critical systems.
// Thus the complexity of maintaining the head pointer by the class is desired.
// When the tree is empty m_count will be set to 0.

template<class T> class tcBspTree
{
    public:
        // Constructor
        inline tcBspTree(void)
        {
            m_head = new T;
            m_count = 0;
        }

        // Destructor
        inline ~tcBspTree(void)
        {
            for (m_temp = m_head; m_temp != nullptr;)
            {
                if ((m_temp->left == nullptr) && (m_temp->right == nullptr))
                {
                    delete m_temp;
                    m_temp = m_head;
                }
                else if (m_temp->left != nullptr)
                {
                    m_temp = m_temp->left;
                }
                else if (m_temp->right != nullptr)
                {
                    m_temp = m_temp->right;
                }
            }
        }

        // Delete copy constructors
        inline tcBspTree(tcBspTree& _other) = delete;
        inline tcBspTree(const tcBspTree& _other) = delete;
        inline tcBspTree&operator=(const tcBspTree& other) = delete;

        // Get head
        inline T* getHead(void)
        {
            return m_head;
        }

        // Get count
        inline std::uint32_t getCount(void)
        {
            return m_count;
        }

    protected:

    private:
        std::uint32_t m_count = 0;
        T*            m_head  = nullptr;
        T*            m_temp  = nullptr;
};

#endif // BSP_TREE_HPP
