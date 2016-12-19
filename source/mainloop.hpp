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

#ifndef MAINLOOP_HPP
#define MAINLOOP_HPP

#include "RoboEngine/roboengine.hpp"

class c_mainloop : public RoboEngine::re_cMainLoop
{
    public:
        uint32_t initialize(void);
        uint32_t terminate(void);
        uint32_t process(int64_t _dt);
        void loadMap(const std::string &_fileName);
    private:
        uint32_t m_playerID = 0;
        float m_playerSpeed = 0.01f;
};

#endif // MAINLOOP_HPP
