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

#include "re_mainloop.hpp"

namespace RoboEngine
{

    uint16_t re_cMainLoop::initialize_internal(void)
    {
        RE_SetMainReady();
        RE_Init(RE_INIT_EVERYTHING);
        uint16_t return_value = EXIT_SUCCESS;
        RE_STATE = RE_STATE_ENUM::RE_ACTIVE;
        m_SystemEvents.initialize();
        m_frameTimer.initialize();
        m_graphicsEngine.initialize();

        return_value = initialize();
        return return_value;
    }

    uint16_t re_cMainLoop::deinitialize_internal(void)
    {
        uint16_t return_value = EXIT_SUCCESS;
        RE_STATE = RE_STATE_ENUM::RE_INACTIVE;
        m_graphicsEngine.deinitialize();
        m_SystemEvents.deinitialize();

        return_value = deinitialize();
        atexit(RE_Quit);
        return return_value;
    }

    uint16_t re_cMainLoop::run(void)
    {
        uint16_t return_value = EXIT_SUCCESS;
        return_value = initialize_internal();
        while (RE_STATE == RE_STATE_ENUM::RE_ACTIVE)
        {
            m_frameTimer.frameStart();
            while(m_frameTimer.ready())
                return_value = process_internal(m_frameTimer.frameTime());
            //std::cout << (m_frameTimer.getFrameTime()) << std::endl;
            //RE_STATE = RE_STATE_ENUM::RE_DEACTIVATING;
            m_graphicsEngine.render();
        }
        return_value = deinitialize_internal();
        return return_value;
    }

    uint16_t re_cMainLoop::process_internal(int64_t _dt)
    {
        uint16_t return_value = EXIT_SUCCESS;
        m_SystemEvents.process();
        if (m_SystemEvents.statusQuit())
            RE_STATE = RE_STATE_ENUM::RE_DEACTIVATING;
        return_value = process(_dt);
        return return_value;
    }

}
//http://gafferongames.com/game-physics/fix-your-timestep/
