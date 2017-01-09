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

//http://gafferongames.com/game-physics/fix-your-timestep/

#ifndef RE_TIME_STEP_HPP
#define RE_TIME_STEP_HPP

#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <thread>

namespace RoboEngine
{

    class re_cFrameTimer
    {
        /// timer uses milliseconds
        public:
            re_cFrameTimer(void) { m_desiredFrameTime = 16; }
            explicit re_cFrameTimer(uint64_t _desiredFrameTime) { m_desiredFrameTime = _desiredFrameTime; }
            virtual ~re_cFrameTimer(void) {}
            void initialize(void);
            void frameStart(void);
            uint64_t frameTime(void);
            bool ready(void) { return m_frameReady; }

            void setDesiredFrameTime(uint64_t _dft) { m_desiredFrameTime = _dft; }
            uint64_t getDesiredFrameTime(void) { return m_desiredFrameTime; }
            uint64_t getFrameTime(void) { return m_deltaFrameTime; }

        private:
            uint64_t m_desiredFrameTime = 16;
            uint64_t m_deltaFrameTime = 0;
            bool m_frameReady = false;
            uint64_t m_startFrameTime = 0;
            uint64_t m_endFrameTime = 0;
            uint64_t m_durationFrame = 0;
    };

}
#endif // RE_TIME_STEP_HPP
