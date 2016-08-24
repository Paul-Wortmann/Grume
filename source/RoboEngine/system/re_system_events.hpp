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

#ifndef RE_SYSTEM_EVENTS_HPP
#define RE_SYSTEM_EVENTS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include "re_log.hpp"

namespace RoboEngine
{

    class re_cSystemEvents
    {
        public:
            re_cSystemEvents(void) {}
            virtual ~re_cSystemEvents(void) {}
            re_cSystemEvents(const re_cSystemEvents&) = default;
            re_cSystemEvents& operator=(const re_cSystemEvents& rhs) {if (this == &rhs) return *this; return *this;}
            void initialize(GLFWwindow* _window);
            void deinitialize(void);
            void process(void);
            inline bool statusQuit(void) { return m_quit; }
            inline bool getKey(int32_t _key){ return (glfwGetKey(m_window, _key) != GLFW_RELEASE ); }
            inline int32_t GetMouseButton (int32_t _button) { return glfwGetMouseButton(m_window, _button); }
            inline void GetCursorPos (double *_xpos, double *_ypos) { glfwGetCursorPos (m_window, _xpos, _ypos); }
            inline void SetCursorPos (double _xpos, double _ypos) { glfwSetCursorPos (m_window, _xpos, _ypos); }

        private:
            GLFWwindow* m_window = nullptr;
            bool m_quit = false;
    };

}
#endif // RE_SYSTEM_EVENTS_HPP

