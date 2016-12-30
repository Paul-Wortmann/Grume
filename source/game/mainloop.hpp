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

// Robo Engine
#include "../RoboEngine/roboengine.hpp"

// Game specific
#include "core_struct.hpp"

class c_mainloop : public RoboEngine::re_cRoboEngine
{
    public:
        // mainloop
        uint32_t initialize(void);
        uint32_t terminate(void);
        uint32_t process(int64_t _dt);

        // mainloop_map
        void loadMap(const std::string &_fileName);
        void GenMap(uint32_t _size);
    private:
        fnf_core m_core = {};

};

#endif // MAINLOOP_HPP
