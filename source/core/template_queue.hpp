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

// !!! This implementation is custom designed for this project. !!!

// !!!! Warning, take care when using this template, it does not manage the memory of the pointers used !!!!
//
// Example usage:
//
//    1. Define a struct with data and a next pointer
//
//    struct sEvent
//    {
//        sEvent* next = nullptr;
//        uint32  data = 0;
//    };
//
//    2. Create a cQueue with the struct defined above
//
//    cQueue<sEvent> m_event;
//
//    3. When pushing to the queue, allocate memory before pushing the pointer, do not free the memory
//
//    sEvent* event1 = new sEvent;
//    event1->data = 100;
//    m_event.push(event1);
//
//    4. When popping an event, use the data and free the pointer.
//
//    for (sEvent* tEvent = system.getEvent(); tEvent != nullptr; tEvent = system.getEvent())
//    {
//        std::cout << "Event data: " << tEvent->data << std::endl;
//        delete tEvent;
//    }
//

#ifndef TEMPLATE_QUEUE_HPP
#define TEMPLATE_QUEUE_HPP

#include "defines_types.hpp"

template <typename T>
class tcQueue
{
    public:
        // Constructors and destructors
        tcQueue(void) { m_initialize(); }  // constructor
        ~tcQueue(void) { m_terminate(); }  // destructor
        tcQueue(const  tcQueue&) = delete; // copy constructor

        // Interface
        uint32 size(void) { return m_size; }
        void   push(T* _data) { m_push(_data); }
        T*     pop(void) { return m_pop(); }

    private:
        // Data
        T*     m_head = nullptr;
        T*     m_tail = nullptr;
        uint32 m_size = 0;

        // Initialize
        void   m_initialize(void) { m_size = 0;}

        // Terminate
        void   m_terminate(void)
        {
            for(T* temp = m_head; m_head != nullptr; )
            {
                if (temp != nullptr)
                {
                    m_head = m_head->next;
                    delete temp;
                    temp = nullptr;
                }
            }
            m_size = 0;
        }

        // Push
        // The caller allocates memory for the passed pointer
        void   m_push(T* _data)
        {
            if (m_tail == nullptr)
            {
                m_tail = _data;
            }
            else
            {
                m_tail->next = _data;
                m_tail = m_tail->next;
            }
            if (m_head == nullptr)
            {
                m_head = m_tail;
            }
            m_size++;
        }

        // Pop
        // The caller frees the memory of the returned pointer
        T*     m_pop(void)
        {
            T* temp = m_head;
            if (m_head != nullptr)
            {
                m_head = m_head->next;
                if (m_head == nullptr)
                {
                    m_tail = nullptr;
                }
                m_size--;
            }
            return temp;
        }
};

#endif // TEMPLATE_QUEUE_HPP

