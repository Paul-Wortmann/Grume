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

#include "re_system_events.hpp"

namespace RoboEngine
{

    void re_cSystemEvents::initialize(GLFWwindow* _window)
    {
        m_window = _window;
        if (_window == nullptr)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Failed to initialize system event manager");
    }

    void re_cSystemEvents::deinitialize(void)
    {
    }

    void re_cSystemEvents::process(void)
    {
        /*
        while (SDL_PollEvent(&m_event))
        {
            //std::cout << "Event ->n" << event.type << "\n";
            switch(m_event.type)
            {
                case SDL_QUIT:
                    m_quit = true;
                break;
                case SDL_WINDOWEVENT:
                    switch(m_event.window.event)
                    {
                        case SDL_WINDOWEVENT_ENTER:
                        break;
                        case SDL_WINDOWEVENT_LEAVE:
                        break;
                        default:
                            //RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Non fatal warning - Window event not processed: "+std::to_string(m_event.window.event));
                        break;
                    }
                break;
                case SDL_MOUSEMOTION:
                    m_mouseX = m_event.motion.x;
                    m_mouseY = m_event.motion.y;
                break;
                case SDL_MOUSEBUTTONDOWN:
                    m_keyMap[m_event.button.button] = true;
                break;
                case SDL_MOUSEBUTTONUP:
                    m_keyMap[m_event.button.button] = false;
                break;
                case SDL_KEYDOWN:
                    m_keyMap[m_event.key.keysym.sym] = true;
                break;
                case SDL_KEYUP:
                    m_keyMap[m_event.key.keysym.sym] = false;
                break;
                default:
                        //RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Non fatal warning - Event not processed: "+std::to_string(m_event.type));
                break;
            }
        }
        */
    }

}

