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

#include <SDL2/SDL.h>

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <unordered_map>

namespace RoboEngine
{

    class re_cSystemEvents
    {
        public:
            re_cSystemEvents(void) {}
            virtual ~re_cSystemEvents(void) {}
            void initialize(void);
            void deinitialize(void);
            void process(void);
            inline bool statusQuit(void) { return m_quit; }
            inline void set_mouseCoords(float x, float y) {m_mouseX = x; m_mouseY = y;}
            inline float get_mouseX() const {return m_mouseX;}
            inline float get_mouseY() const {return m_mouseY;}
            bool keyDown(uint16_t keyID);
        private:
            SDL_Event m_event = {};
            std::unordered_map<unsigned int, bool> m_keyMap = {};
            float m_mouseX = 0.0f;
            float m_mouseY = 0.0f;
            bool m_quit = false;
    };

}
#endif // RE_SYSTEM_EVENTS_HPP

