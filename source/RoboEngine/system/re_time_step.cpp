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

#include "re_time_step.hpp"

#include <iostream>
#include <string>

namespace RoboEngine
{
            void re_cFrameTimer::initialize(void)
            {
                m_startFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
                m_endFrameTime = m_startFrameTime;
            }

            void re_cFrameTimer::frameStart(void)
            {
                m_endFrameTime = m_startFrameTime;
                m_startFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
                m_durationFrame = m_startFrameTime - m_endFrameTime;
                m_deltaFrameTime += m_durationFrame;

                //std::cout << "Start: " << std::to_string(m_startFrameTime) << " ";
                //std::cout << "End: " << std::to_string(m_endFrameTime) << " ";
                //std::cout << "Delta: " << std::to_string(m_durationFrame) <<  " ";
                //std::cout << "FPS: " << std::to_string(1080/(m_durationFrame+1)) << std::endl;
                if (m_deltaFrameTime >= m_desiredFrameTime)
                    m_frameReady = true;
            }

            uint64_t re_cFrameTimer::frameTime(void)
            {
                uint64_t returnFrameRate = 0.0f;
                if (m_deltaFrameTime >= m_desiredFrameTime)
                {
                    m_deltaFrameTime -= m_desiredFrameTime;
                    if (m_deltaFrameTime < m_desiredFrameTime)
                        m_frameReady = false;
                    returnFrameRate = m_desiredFrameTime;
                }
                else
                {
                    returnFrameRate = m_deltaFrameTime;
                    m_deltaFrameTime = 0;
                    m_frameReady = false;
                }
                return returnFrameRate;
            }

}
