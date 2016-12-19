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

#ifndef RE_TIME_HPP
#define RE_TIME_HPP

#include <iostream>
#include <chrono>
#include <ctime>

namespace RoboEngine
{

    class re_cTime
    {
        public:
            re_cTime(void) = default;
            virtual ~re_cTime(void) = default;
            re_cTime(const re_cTime&) = default;
            re_cTime& operator=(const re_cTime& _rhs) {if (this == &_rhs) return *this; return *this;}

            inline uint64_t getTime(void) {return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();}
        protected:

        private:
            double m_delta = 0.0f;

            inline double getDelta(void) {return m_delta;}
            inline void setDelta(double _delta) {m_delta = _delta;}


    };

}

#endif // RE_TIME_HPP
