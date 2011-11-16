/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "UI.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

    player_stats_class::player_stats_class(void)
{
    player_stats_class::highlighted      = false;
    player_stats_class::drag             = false;
    player_stats_class::portrait         = 0;
    player_stats_class::mouse_over_count = 0;
    player_stats_class::tooltip_time     = 128;
    player_stats_class::tooltip_active   = false;
    player_stats_class::pos_x            = 0.0f;
    player_stats_class::pos_y            = 0.0f;
    player_stats_class::pos_z            = 0.0f;
    player_stats_class::width            = 0.0f;
    player_stats_class::height           = 0.0f;
};
    player_stats_class::~player_stats_class(void)
{

};

void player_stats_class::process(void)
{
    //if mouse_over, drag, tool_tip etc...
};

void player_stats_class::draw(void)
{
    game.texture.icon_melee.draw(false,player_stats_class::pos_x,player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width,player_stats_class::height);

};

//----------------------------------------------------------------------------------------------------------------

    action_slot_class::action_slot_class(void)
{
    action_slot_class::highlighted      = false;
    action_slot_class::drag             = false;
    action_slot_class::button_type      = 0;
    action_slot_class::mouse_over_count = 0;
    action_slot_class::tooltip_time     = 128;
    action_slot_class::tooltip_active   = false;
    action_slot_class::pos_x            = 0.0f;
    action_slot_class::pos_y            = 0.0f;
    action_slot_class::pos_z            = 0.0f;
    action_slot_class::width            = 0.0f;
    action_slot_class::height           = 0.0f;
};
    action_slot_class::~action_slot_class(void)
{

};

void action_slot_class::process(void)
{
    //if mouse_over, drag, tool_tip etc...
};

void action_slot_class::draw(void)
{
    if (action_slot_class::button_type == 1) game.texture.icon_melee.draw(false,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);

    game.texture.glass_cover_01.draw(false,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
};

//----------------------------------------------------------------------------------------------------------------

    menu_slot_class::menu_slot_class(void)
{
    menu_slot_class::highlighted      = false;
    menu_slot_class::drag             = false;
    menu_slot_class::button_type      = 0;
    menu_slot_class::mouse_over_count = 0;
    menu_slot_class::tooltip_time     = 128;
    menu_slot_class::tooltip_active   = false;
    menu_slot_class::pos_x            = 0.0f;
    menu_slot_class::pos_y            = 0.0f;
    menu_slot_class::pos_z            = 0.0f;
    menu_slot_class::width            = 0.0f;
    menu_slot_class::height           = 0.0f;
};
    menu_slot_class::~menu_slot_class(void)
{

};

void menu_slot_class::process(void)
{
    //if mouse_over, drag, tool_tip etc...
};

void menu_slot_class::draw(void)
{
    if (menu_slot_class::button_type == 1) game.texture.icon_01.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 2) game.texture.icon_02.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 3) game.texture.icon_03.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 4) game.texture.icon_04.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 5) game.texture.icon_05.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 6) game.texture.icon_06.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);

    game.texture.glass_cover_02.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
};

//----------------------------------------------------------------------------------------------------------------

    action_bar_class::action_bar_class(void)
{
    action_bar_class::pos_x            = 0.0f;
    action_bar_class::pos_y            = 0.0f;
    action_bar_class::pos_z            = 0.0f;
    action_bar_class::width            = 0.0f;
    action_bar_class::height           = 0.0f;
};
    action_bar_class::~action_bar_class(void)
{

};

void action_bar_class::process(void)
{
    action_bar_class::menu_slot_01.process();
    action_bar_class::menu_slot_02.process();
    action_bar_class::menu_slot_03.process();
    action_bar_class::menu_slot_04.process();
    action_bar_class::menu_slot_05.process();
    action_bar_class::menu_slot_06.process();
    action_bar_class::action_slot_01.process();
    action_bar_class::action_slot_02.process();
    action_bar_class::action_slot_03.process();
    action_bar_class::action_slot_04.process();
    action_bar_class::action_slot_05.process();
    action_bar_class::action_slot_06.process();
    action_bar_class::action_slot_07.process();
    action_bar_class::action_slot_08.process();
    action_bar_class::action_slot_09.process();
    action_bar_class::action_slot_10.process();
};

void action_bar_class::draw(void)
{
    game.texture.action_bar.draw(false,action_bar_class::pos_x,action_bar_class::pos_y,action_bar_class::pos_z,action_bar_class::width,action_bar_class::height);
    action_bar_class::action_slot_01.draw();
    action_bar_class::action_slot_02.draw();
    action_bar_class::action_slot_03.draw();
    action_bar_class::action_slot_04.draw();
    action_bar_class::action_slot_05.draw();
    action_bar_class::action_slot_06.draw();
    action_bar_class::action_slot_07.draw();
    action_bar_class::action_slot_08.draw();
    action_bar_class::action_slot_09.draw();
    action_bar_class::action_slot_10.draw();
    game.texture.action_bar_front.draw(false,action_bar_class::pos_x,action_bar_class::pos_y,action_bar_class::pos_z,action_bar_class::width,action_bar_class::height);
    action_bar_class::menu_slot_01.draw();
    action_bar_class::menu_slot_02.draw();
    action_bar_class::menu_slot_03.draw();
    action_bar_class::menu_slot_04.draw();
    action_bar_class::menu_slot_05.draw();
    action_bar_class::menu_slot_06.draw();
};

//----------------------------------------------------------------------------------------------------------------
    UI_class::UI_class(void)
{

};
    UI_class::~UI_class(void)
{

};

void UI_class::process(void)
{
    UI_class::player_stats.process();
    UI_class::action_bar.process();
};

void UI_class::draw(void)
{
    UI_class::player_stats.draw();
    UI_class::action_bar.draw();
};

