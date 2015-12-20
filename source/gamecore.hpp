/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#ifndef GAMECORE_H
#define GAMECORE_H

#include "../../RoboEngine2/resource/RE_resource_manager.hpp"
#include "../../RoboEngine2/resource/RE_xml_parser.hpp"
#include "../../RoboEngine2/resource/RE_obj_loader.hpp"
#include "../../RoboEngine2/resource/RE_reo_loader.hpp"
#include "../../RoboEngine2/RE_maingame.hpp"
#include "../../RoboEngine2/system/RE_log.hpp"

class GameCore : public RoboEngine::MainGame
{
    public:
            GameCore()  : m_log("game.log"), ResourceManager() { };
            ~GameCore() { };
            GameCore(const GameCore&) = default;
            GameCore& operator=(const GameCore& rhs) {if (this == &rhs) return *this; return *this;}
            uint16_t loadResources(void);
            uint16_t init(int argc, char** afileNamergv);
            uint16_t parse_args(int argc, char** argv);
            uint16_t setup(void);
            uint16_t deinit();
            uint16_t update();
            uint16_t draw();
            RoboEngine::c_log m_log;
            RoboEngine::resource_manager ResourceManager;
    protected:
    private:


};


#endif // GAMECORE_H
