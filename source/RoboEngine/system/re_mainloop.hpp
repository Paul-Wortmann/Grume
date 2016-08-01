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

#ifndef RE_MAINLOOP_HPP
#define RE_MAINLOOP_HPP

#include "re_log.hpp"
#include "re_system_events.hpp"
#include "re_time_step.hpp"
#include "../roboengine.hpp"
#include "../graphics/re_graphics_engine.hpp"

namespace RoboEngine
{

    enum RE_STATE_ENUM : uint8_t {RE_ACTIVE, RE_INACTIVE, RE_DEACTIVATING};

    class re_cMainLoop
    {
        public:
            re_cMainLoop(void) {}
            virtual ~re_cMainLoop(void) {}
            virtual uint16_t initialize(void) = 0;
            virtual uint16_t deinitialize(void) = 0;
            virtual uint16_t process(int64_t _dt) = 0;
            virtual uint16_t run(void) final;
        private:
            virtual uint16_t initialize_internal(void) final;
            virtual uint16_t deinitialize_internal(void) final;
            virtual uint16_t process_internal(int64_t _dt) final;
            RE_STATE_ENUM RE_STATE = RE_STATE_ENUM::RE_ACTIVE;
            re_cSystemEvents m_SystemEvents = {};
            re_cFrameTimer m_frameTimer = {};
            re_cGraphicsEngine m_graphicsEngine = {};
            re_cLog m_log = re_cLog("RoboEngine.txt");
    };

}
#endif // RE_MAINLOOP_HPP
