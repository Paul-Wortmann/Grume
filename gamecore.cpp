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
 **/

#include <GL/glew.h>
#include <iostream>
#include "gamecore.hpp"

uint16_t GameCore::loadResources(void)
{
    RoboEngine::reo_data_s* xml_resource_1 = (RoboEngine::reo_data_s*)ResourceManager.load("data/re_object/cube.reo",RoboEngine::e_resource_type::REO);
    xml_resource_1->rem_data = (RoboEngine::rem_data_s*)ResourceManager.load("data/re_mesh/"+xml_resource_1->name_mesh,RoboEngine::e_resource_type::REM);
    xml_resource_1->ret_data = (RoboEngine::ret_data_s*)ResourceManager.load("data/re_texture/"+xml_resource_1->name_textures,RoboEngine::e_resource_type::RET);
    uint16_t returnValue = EXIT_SUCCESS;
    return returnValue;
}

uint16_t GameCore::parse_args(int argc, char** argv)
{
    uint16_t returnValue = EXIT_SUCCESS;
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
    return returnValue;
}

uint16_t GameCore::setup(void)
{
    uint16_t returnValue = EXIT_SUCCESS;
    return returnValue;
}

uint16_t GameCore::init(int argc, char** argv)
{
    uint16_t returnValue = EXIT_SUCCESS;
    parse_args(argc,argv);
    setGameName("Project 0");
    GameCore::m_log.set_file_name("RE2_Test.log");
    GameCore::m_log.clear();
    return returnValue;
}

uint16_t GameCore::deinit()
{
    ResourceManager.delete_all();
    uint16_t returnValue = EXIT_SUCCESS;
    return returnValue;
}

uint16_t GameCore::update()
{
    uint16_t returnValue = EXIT_SUCCESS;

    std::cout << getFPS() << std::endl;

    //update_object(speed * frametime);
    SDL_Delay(500);
    if (keyDown(SDLK_ESCAPE))
        setGameState(RoboEngine::gameState::EXIT);
    if(eventQuit())
        setGameState(RoboEngine::gameState::EXIT);
    return returnValue;
}

uint16_t GameCore::draw()
{
    uint16_t returnValue = EXIT_SUCCESS;

    //render_object(frametime);

    return returnValue;
}
