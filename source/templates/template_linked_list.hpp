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

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "../core/defines_types.hpp"

// !!! This implementation is custom designed for this project. !!!

// Note The list maintains the head node, which is only freed by the destructor.
// The reason being is to maintain the same pointer to the linked list head which
// is required by external classes that share the head node to reference the list.
// While external classes could keep updating their pointer to the list, it is
// more efficient to avoid unnecessary function calls for performance critical systems.
// Thus the complexity of maintaining the head pointer by the class is desired.
// When the list is empty m_count will be set to 0.

template<class T> class tcLinkedList
{
    public:
        // Constructor
        inline tcLinkedList(void)
        {
            m_head = new T;
            m_tail = m_head;
            m_count = 0;
        }

        // Destructor
        inline ~tcLinkedList(void)
        {
            for (m_temp = m_head; m_temp != nullptr;)
            {
                m_head = m_temp;
                m_temp = m_temp->next;
                if (m_head != nullptr)
                {
                    delete m_head;
                    m_head = nullptr;
                }
            }
        }

        // Delete copy constructors
        inline tcLinkedList(tcLinkedList& _other) = delete;
        inline tcLinkedList(const tcLinkedList& _other) = delete;
        inline tcLinkedList&operator=(const tcLinkedList& other) = delete;

        // Free all data held by the linked list
        inline void freeAll(void)
        {
            for (m_temp = m_head; m_temp != nullptr;)
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
        virtual void freeData(T*& _pointer) = 0;

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

        // Get new (Back)
        inline T* getNew(void)
        {
            return getNewBack();
        }

        // Get new Back
        inline T* getNewBack(void)
        {
            if (m_count == 0)
            {
                m_count++;
                m_head->UID = m_count;
                return m_head;
            }
            m_tail->next = new T;
            m_tail = m_tail->next;
            m_count++;
            m_tail->UID = m_count;
            return m_tail;
        }


        // Get new from front
        // ! disabled for this project
        /*
        inline T* getNewFront(void)
        {
            if (m_count == 0)
            {
                m_count++;
                return m_head;
            }
            T* Tnew = new T;
            Tnew->next = m_head;
            m_head = Tnew;
            m_count++;
            return m_head;
        }
        */

        // Add pre existing pointerto the end of the the linked list
        inline void addBack(T*& _T)
        {
            m_tail->next = _T;
            m_tail = m_tail->next;
            m_count++;
            m_tail->UID = m_count;
        }

        // Add pre existing pointer to the end of the the linked list
        // ! disabled for this project
        /*
        inline void addFront(T*& _T)
        {
            _T->next = m_head;
            m_head = _T;
            m_count++;
        }
        */

        // Add pre existing pointer before a preexisting pointer
        // ! _existing shouldn't == m_head, for external classes
        inline void addBefore(T*& _new, T*& _existing)
        {
            T* Tp = nullptr;
            // Loop through the linked list to find previous pointer
            for (m_temp = m_head; m_temp != nullptr; m_temp = m_temp->next)
            {
                Tp = (m_temp->next == _existing) ? m_temp : Tp;
            }
            Tp->next = _new;
            _new->next = _existing;
            m_count++;
            _existing->UID = m_count;
        }

        // Add pre existing pointer after specified pointer
        inline void addAfter(T*& _new, T*& _existing)
        {
            m_temp = _existing->next;
            _existing->next = _new;
            _new->next = m_temp;
            m_count++;
            _existing->UID = m_count;
        }

        // Swap the location of 2 nodes
        inline void swap(T* _T1, T* _T2)
        {
            // If the pointers are the same or invalid, return
            if ((_T1 == nullptr) || (_T2 == nullptr) || (_T1 == _T2))
                return;

            // get previous pointers
            T* T1p = nullptr;
            T* T2p = nullptr;

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
        inline void remove(T*& _T)
        {
            if ((_T == nullptr) || (m_count == 0)) // Corner cases
            {
                return;
            }
            else if (_T == m_head) // Head
            {
                if (m_head->next == nullptr)
                {
                    m_count = 0;
                }
                else
                {
                    m_head = _T->next;
                    m_count--;
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
                m_count--;
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
                        m_count--;
                        return;
                    }
                }
            }
        }

    protected:

    private:
        std::uint32_t m_count = 0;
        T*            m_head  = nullptr;
        T*            m_tail  = nullptr;
        T*            m_temp  = nullptr;
};

#endif // LINKED_LIST_HPP
