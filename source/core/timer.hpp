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

#ifndef TIMER_HPP
#define TIMER_HPP

#include "includes.hpp"

class cTimer
{
    public:
        // Constructors and operators
        cTimer(void) = default;
        ~cTimer(void) = default;
        cTimer(cTimer& _other) = delete;
        cTimer(const cTimer& _other) = delete;
        cTimer& operator=(const cTimer& other) = delete;
        
        // Initialize, start of application
        void initialize(void)
        {
            m_frameStart = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
            m_frameEnd = m_frameStart;
        };

        // Process, per game loop
        void process(void)
        {
            m_frameEnd = m_frameStart;
            m_frameStart = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
            m_frameTime = m_frameStart - m_frameEnd;
            if (m_frameTime > m_mt)
                m_frameTime = m_mt;
            m_accumulator += m_frameTime;
        };

        // Check if enough time has passed
        bool ready(void)
        {
            return (m_accumulator > m_dt);
        };

        // Called at the end of the same loop as ready()
        void advance_dt(void)
        {
            m_t += m_dt;
            m_accumulator -= m_dt;
        };

        // Set desired frametime
        void set_dt(double _dt) {m_dt = _dt;}

        // Get desired frametime
        double get_dt(void) {return m_dt;}

        // Get the frametime (time to process the game loop)
        double get_frameTime(void) {return m_frameTime;}

    protected:

    private:
        double m_t           = 0.0f;  // total time
        double m_dt          = 16.0f; // desired frametime
        double m_mt          = 64.0f; // max frametime - limit
        double m_accumulator = 0.0f;  // Used to accumulate frame time until it is m_dt
        double m_frameStart  = 0.0f;  // Time at frame start
        double m_frameEnd    = 0.0f;  // Time at frame end
        double m_frameTime   = 0.0f;  // delta time
};

#endif // TIMER_HPP
