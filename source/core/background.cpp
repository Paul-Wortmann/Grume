/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "core.hpp"
#include "../game/game.hpp"
#include "background.hpp"

extern game_class game;

background_class::background_class (void)
{
    for (int layer_number = 1; layer_number < MAX_LAYERS+1; layer_number++)
    {
        background_class::layer[layer_number].active    = false;
    }
};

void background_class::set_data (int layer_number, int dx, int dy, float px, float py, float srx, float sry, std::string image_path)
{
    background_class::layer[layer_number].active        = true;
    background_class::layer[layer_number].dir_x         = dx;
    background_class::layer[layer_number].dir_y         = dy;
    background_class::layer[layer_number].pos_x         = px;
    background_class::layer[layer_number].pos_y         = py;
    background_class::layer[layer_number].scroll_rate_x = srx;
    background_class::layer[layer_number].scroll_rate_y = sry;
    background_class::layer[layer_number].image_path    = image_path;
    background_class::layer[layer_number].image         = game.texture_manager.add_texture(image_path);
};

void background_class::set_image (int layer_number, std::string image_path)
{
    background_class::layer[layer_number].image_path    = image_path;
    background_class::layer[layer_number].image         = game.texture_manager.add_texture(image_path);
};

bool  background_class::scroll_up (void)
{
    bool return_value = false;
    for (int layer_number = 1; layer_number < MAX_LAYERS+1; layer_number++)
    {
        background_class::layer[layer_number].pos_y -= background_class::layer[layer_number].scroll_rate_y;
        if (background_class::layer[layer_number].pos_y < -1.0f) background_class::layer[layer_number].pos_y = -1.0f;
        else return_value = true;
    }
    return(return_value);
};

bool  background_class::scroll_down (void)
{
    bool return_value = false;
    for (int layer_number = 1; layer_number < MAX_LAYERS+1; layer_number++)
    {
        background_class::layer[layer_number].pos_y += background_class::layer[layer_number].scroll_rate_y;
        if (background_class::layer[layer_number].pos_y > 1.0f) background_class::layer[layer_number].pos_y = 1.0f;
        else return_value = true;
    }
    return(return_value);
};

void background_class::process (void)
{
    switch (background_class::movemennt_type)
    {
        case BOUNCE:
            for (int layer_number = 1; layer_number < MAX_LAYERS+1; layer_number++)
            {
                if (background_class::layer[layer_number].dir_x == 0)
                {
                    background_class::layer[layer_number].pos_x -= background_class::layer[layer_number].scroll_rate_x;
                    if (background_class::layer[layer_number].pos_x < 0.0f) background_class::layer[layer_number].dir_x = 1;
                }
                if (background_class::layer[layer_number].dir_x == 1)
                {
                    background_class::layer[layer_number].pos_x += background_class::layer[layer_number].scroll_rate_x;
                    if (background_class::layer[layer_number].pos_x > 1.0f) background_class::layer[layer_number].dir_x = 0;
                }
                if (background_class::layer[layer_number].dir_y == 0)
                {
                    background_class::layer[layer_number].pos_y -= background_class::layer[layer_number].scroll_rate_y;
                    if (background_class::layer[layer_number].pos_y < 0.0f) background_class::layer[layer_number].dir_y = 1;
                }
                if (background_class::layer[layer_number].dir_y == 1)
                {
                    background_class::layer[layer_number].pos_y += background_class::layer[layer_number].scroll_rate_y;
                    if (background_class::layer[layer_number].pos_y > 1.0f) background_class::layer[layer_number].dir_y = 0;
                }
            }
        break;
        case SCROLL:
            for (int layer_number = 1; layer_number < MAX_LAYERS+1; layer_number++)
            {
                background_class::layer[layer_number].pos_x -= background_class::layer[layer_number].scroll_rate_x;
                if (background_class::layer[layer_number].pos_x <= -4.0f) background_class::layer[layer_number].pos_x = 4.0f;
            }
        break;
        case FRONT_SCROLL:
            for (int layer_number = 1; layer_number < MAX_LAYERS+1; layer_number++)
            {
                if (layer_number != 2)
                {
                    background_class::layer[layer_number].pos_x -= background_class::layer[layer_number].scroll_rate_x;
                    if (background_class::layer[layer_number].pos_x <= -4.0f) background_class::layer[layer_number].pos_x = 4.0f;
                }
            }
        break;
        default:
        break;
    }
};

void background_class::draw (void)
{
    float z_pos = 0.15f;
    for (int layer_number = 0; layer_number <= MAX_LAYERS; layer_number++)
    {
        if (background_class::layer[layer_number].active)
        {
            switch (background_class::movemennt_type)
            {
                case BOUNCE:
                    game.texture_manager.draw(background_class::layer[layer_number].image,true,background_class::layer[layer_number].pos_x,background_class::layer[layer_number].pos_y,z_pos,4.0f,4.0f);
                break;
                case SCROLL:
                    game.texture_manager.draw(background_class::layer[layer_number].image,true,background_class::layer[layer_number].pos_x,background_class::layer[layer_number].pos_y,z_pos,4.0f,4.0f);
                break;
                case FRONT_SCROLL:
                    if  (layer_number <= 2) game.texture_manager.draw(background_class::layer[layer_number].image,true,background_class::layer[layer_number].pos_x,background_class::layer[layer_number].pos_y,z_pos,2.0f,2.0f);
                    if ((layer_number == 3) || (layer_number == 4)) game.texture_manager.draw(background_class::layer[layer_number].image,true,background_class::layer[layer_number].pos_x,background_class::layer[layer_number].pos_y,z_pos,4.0f,4.0f);
                    if  (layer_number >= 5) game.texture_manager.draw(background_class::layer[layer_number].image,true,background_class::layer[layer_number].pos_x,background_class::layer[layer_number].pos_y,z_pos,4.0f,4.0f);
                break;
                default:
                break;
            }
        }
    }
}

void background_class::reload_textures (void)
{
    for (int layer_number = 0; layer_number <= MAX_LAYERS; layer_number++)
    {
        if (background_class::layer[layer_number].active) game.texture_manager.add_texture(background_class::layer[layer_number].image_path);
    }
}

