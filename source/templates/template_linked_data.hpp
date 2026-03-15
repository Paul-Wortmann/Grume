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

#ifndef LINKED_DATA_HPP
#define LINKED_DATA_HPP

#include <cstdint>
#include <mutex>

// !!! This implementation is custom designed for this project. !!!

// Note The list maintains the head node, which is only freed by the destructor.
// The reason being is to maintain the same pointer to the linked list head which
// is required by external classes that share the head node to reference the list.
// While external classes could keep updating their pointer to the list, it is
// more efficient to avoid unnecessary function calls for performance critical systems.
// Thus the complexity of maintaining the head pointer by the class is desired.

// The linked list creates a sentinel non on initialization, so that the head pointer
// reference remains constant throughout the life of the linked list.

// Instead of deleting nodes, they are disabled and reused later
// This avoids unnecessary memory allocation, deallocation and fragmentation.
// If the exact number of required nodes is known, one may allocate them in advance.

template<class T> class tcLinkedData
{
    public:
        // Constructor
        tcLinkedData(void)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            // create the sentinel node
            m_head = new std::unique_ptr<T>;
            m_head->enabled = false;
            m_tail = m_head;
        }

        // Destructor
        ~tcLinkedData(void)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            for (std::unique_ptr<T> m_temp = m_head; m_temp != nullptr;)
            {
                m_head = m_temp;
                m_temp = m_temp->next;
                if (m_head != nullptr)
                {
                    delete m_head;
                    m_head = nullptr;
                    m_tail = nullptr;
                }
            }
        }

        // Delete copy and move constructors and assignment operators
        inline tcLinkedData(tcLinkedData& _other) = delete;                 // Copy constructor
        inline tcLinkedData(const tcLinkedData& _other) = delete;           // Copy constructor
        inline tcLinkedData(tcLinkedData&& _other) = delete;                // Move constructor
        inline tcLinkedData& operator=(const tcLinkedData& other) = delete; // Copy assignment
        inline tcLinkedData& operator=(tcLinkedData&& other) = delete;      // Move assignment

        // Free all data held by the linked list
        inline void freeAll(void)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            for (std::unique_ptr<T> m_temp = m_head; m_temp != nullptr;)
            {
                m_head = m_temp;
                m_temp = m_temp->next;
                if (m_head != nullptr)
                {
                    freeData(m_head);
                    delete m_head;
                    m_head = nullptr;
                }
            }
        }

        // Free all data held by the pointer
        virtual void freeData(std::unique_ptr<T>& _pointer) = 0;

        // Get head
        inline std::unique_ptr<T> getHead(void)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            return m_head;
        }

        // Get new
        inline std::unique_ptr<T> getNew(void)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            for (std::unique_ptr<T> m_temp = m_head; m_temp != nullptr;)
            {
                if (m_temp->enabled == false)
                {
                    m_temp->enabled = true;
                    return m_temp;
                }
            }
            m_tail->next = new T;
            m_tail = m_tail->next;
            m_tail->enabled = true;

            return m_tail;
        }

        // Add a preexisting pointer to the end of the the linked list
        inline void addBack(std::unique_ptr<T>& _T)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            m_tail->next = _T;
            m_tail = m_tail->next;
            m_tail->enabled = true;
        }

        // Add preexisting pointer before a preexisting pointer
        // ! _existing shouldn't == m_head, for external classes
        inline void addBefore(std::unique_ptr<T>& _new, std::unique_ptr<T>& _existing)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            std::unique_ptr<T> Tp = nullptr;
            // Loop through the linked list to find previous pointer
            for (std::unique_ptr<T> m_temp = m_head; m_temp != nullptr; m_temp = m_temp->next)
            {
                Tp = (m_temp->next == _existing) ? m_temp : Tp;
            }
            Tp->next = _new;
            _new->next = _existing;
            _existing->enabled = true;
        }

        // Add preexisting pointer after specified pointer
        inline void addAfter(std::unique_ptr<T>& _new, std::unique_ptr<T>& _existing)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            std::unique_ptr<T> m_temp = _existing->next;
            _existing->next = _new;
            _new->next = m_temp;
            _existing->enabled = true;
        }

        // Swap the location of 2 nodes
        inline void swap(std::unique_ptr<T> _T1, std::unique_ptr<T> _T2)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            // If the pointers are the same or invalid, return
            if ((_T1 == nullptr) || (_T2 == nullptr) || (_T1 == _T2))
                return;

            // temp pointer
            std::unique_ptr<T> m_temp = nullptr;

            // get previous pointers
            std::unique_ptr<T> T1p = nullptr;
            std::unique_ptr<T> T2p = nullptr;

            // Loop through the linked list to find previous pointers
            for (m_temp = m_head; m_temp != nullptr; m_temp = m_temp->next)
            {
                T1p = (m_temp->next == _T1) ? m_temp : T1p;
                T2p = (m_temp->next == _T2) ? m_temp : T2p;
            }

            // swap
            if (_T1->next == _T2) // Adjacent
            {
                //std::cout << "CASE 1" << std::endl;
                //1 2 3
                //2 1 3
                _T1->next = _T2->next;
                _T2->next = _T1;
                T2p = T1p;
                T1p = _T2;
                if (T1p != nullptr) T1p->next = _T1;
                if (T2p != nullptr) T2p->next = _T2;
            }
            else if (_T2->next == _T1) // Adjacent
            {
                //std::cout << "CASE 2" << std::endl;
                //2 1 3
                //1 2 3
                _T2->next = _T1->next;
                _T1->next = _T2;
                T1p = T2p;
                T2p = _T1;
                if (T1p != nullptr) T1p->next = _T1;
                if (T2p != nullptr) T2p->next = _T2;
            }
            else // Disjoined
            {
                //std::cout << "CASE 3" << std::endl;
                //1 2 3 4
                //3 2 1 4
                m_temp = _T1->next;
                _T1->next = _T2->next;
                _T2->next = m_temp;
                m_temp = T1p;
                T1p = T2p;
                T2p = m_temp;
                if (T1p != nullptr) T1p->next = _T1;
                if (T2p != nullptr) T2p->next = _T2;
            }

            // Make sure m_head points to the correct node if need be
            if (_T1 == m_head) m_head = _T2;
            else if (_T2 == m_head) m_head = _T1;

            // Make sure m_tail points to the correct node if need be
            if (_T1 == m_tail) m_tail = _T2;
            else if (_T2 == m_tail) m_tail = _T1;
        }

        // Remove a pointer from the list
        // !!!! MAKE SURE YOU HAVE FREED ALL DATA FROM THE NODE BEFOREHAND !!!!
        inline void remove(std::unique_ptr<T>& _T)
        {
            // Lock for thread safety
            std::lock_guard<std::mutex> lock(m_mutex);

            // temp pointer
            std::unique_ptr<T> m_temp = nullptr;

            if (_T == nullptr) // Corner case
            {
                return;
            }
            else if (_T == m_head) // Head
            {
                if (m_head->next == nullptr)
                {
                    m_head->enabled = false;
                }
                else
                {
                    m_head = _T->next;
                    delete _T;
                    _T = nullptr;
                }
            }
            else if (_T == m_tail) // Tail
            {
                // Loop through the linked list to find previous pointer
                for (m_temp = m_head; m_temp != nullptr; m_temp = m_temp->next)
                {
                    m_tail = (m_temp->next == _T) ? m_temp : m_tail;
                }
                m_tail->next = nullptr;
                delete _T;
                _T = nullptr;
            }
            else // not head or tail
            {
                // Loop through the linked list to find the pointer
                for (m_temp = m_head; m_temp != nullptr; m_temp = m_temp->next)
                {
                    if (m_temp->next == _T)
                    {
                        m_temp->next = _T->next;
                        delete _T;
                        _T = nullptr;
                        return;
                    }
                }
            }
        }

    protected:

    private:
        std::mutex         m_mutex = {};
        std::unique_ptr<T> m_head  = nullptr;
        std::unique_ptr<T> m_tail  = nullptr;
};

#endif // LINKED_LIST_HPP
