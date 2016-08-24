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

#ifndef RE_GRAPHICS_HPP
#define RE_GRAPHICS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cstdint>
#include <string>
#include <thread>
#include <chrono>
#include "../entity/re_entity.hpp"
#include "../system/re_log.hpp"

namespace RoboEngine
{
    #define RE_GL_CONTEXT_MAJOR 3
    #define RE_GL_CONTEXT_MINOR 3

    class re_cGraphicsEngine
    {
        public:
            re_cGraphicsEngine(void) {}
            virtual ~re_cGraphicsEngine(void) {}
            re_cGraphicsEngine(const re_cGraphicsEngine&) = default;
            re_cGraphicsEngine& operator=(const re_cGraphicsEngine& rhs) {if (this == &rhs) return *this; return *this;}
            uint32_t initialize(void);
            void deinitialize(void);
            void render(void);
            inline void setEntity(re_sEntity *_entityHead) {m_entityHead = _entityHead;  m_entity = _entityHead;}
            inline GLFWwindow* getWindow(void) { return m_window; }
        private:
            GLFWwindow* m_window = nullptr;
            std::string m_title = "Frost and Flame";
            uint16_t m_displayX = 640;
            uint16_t m_displayY = 480;
            bool m_displayFullscreen = false;
            uint32_t m_displayFlags = 0;
            uint16_t m_currentDisplay = 0;
            uint16_t m_currentDisplayMode = 0;
            uint16_t m_numberDisplays = 0;
            uint16_t m_numberDisplayModes = 0;
            uint16_t m_currentShader = 0;
            re_sEntity *m_entityHead = nullptr;
            re_sEntity *m_entity = nullptr;
    };

}
#endif // RE_GRAPHICS_HPP

