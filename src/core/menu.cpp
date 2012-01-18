/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "menu.hpp"
#include "../game.hpp"

extern  game_type                game;
extern  int                      JUSTIFY_STATE;

button_class::button_class(void)
{
    button_class::active                = false;
    button_class::image_normal          = 0;
    button_class::image_highlighted     = 0;
    button_class::image_disabled        = 0;
    button_class::image_choice_disabled = 0;
    button_class::highlighted           = false;
    button_class::enabled               = true;
    button_class::glow                  = true;
    button_class::zoom                  = true;
    button_class::zoom_size             = 0.0f;
    button_class::zoom_size_counter     = 0.0f;
    button_class::zoom_speed            = 0.0f;
    button_class::pos_x                 = 0.0f;
    button_class::pos_y                 = 0.0f;
    button_class::pos_z                 = 0.0f;
    button_class::height                = 0.0f;
    button_class::width                 = 0.0f;
    button_class::label                 = "Label Not Set";
    button_class::normal_color_r        = 255;
    button_class::normal_color_g        = 255;
    button_class::normal_color_b        = 255;
    button_class::normal_color_a        = 255;
    button_class::highlighted_color_r   = 255;
    button_class::highlighted_color_g   = 255;
    button_class::highlighted_color_b   = 255;
    button_class::highlighted_color_a   = 255;
    button_class::disabled_color_r      = 255;
    button_class::disabled_color_g      = 255;
    button_class::disabled_color_b      = 255;
    button_class::disabled_color_a      = 255;
    button_class::type                  = 0;
};

button_class::button_class(float x, float y, float z, float w, float h, int in, int ih, int id, bool hl, bool en, bool gl, bool zm, float zs, int nr, int ng, int nb, int na, int hr, int hg, int hb, int ha, int dr, int dg, int db, int da, std::string  lb)
{
    button_class::type                = 0;
    button_class::active              = false;
    button_class::image_normal        = in;
    button_class::image_highlighted   = ih;
    button_class::image_disabled      = id;
    button_class::highlighted         = hl;
    button_class::enabled             = en;
    button_class::glow                = gl;
    button_class::zoom                = zm;
    button_class::zoom_size           = zs;
    button_class::pos_x               = x;
    button_class::pos_y               = y;
    button_class::pos_z               = z;
    button_class::width               = w;
    button_class::height              = h;
    button_class::label               = lb;
    button_class::normal_color_r      = nr;
    button_class::normal_color_g      = ng;
    button_class::normal_color_b      = nb;
    button_class::normal_color_a      = na;
    button_class::highlighted_color_r = hr;
    button_class::highlighted_color_g = hg;
    button_class::highlighted_color_b = hb;
    button_class::highlighted_color_a = ha;
    button_class::disabled_color_r    = dr;
    button_class::disabled_color_g    = dg;
    button_class::disabled_color_b    = db;
    button_class::disabled_color_a    = da;
};

button_class::~button_class(void)
{

};

void button_class::set_pos(float x, float y, float z)
{
    button_class::pos_x = x;
    button_class::pos_y = y;
    button_class::pos_z = z;
};

void button_class::set_pos_x(float x)
{
    button_class::pos_x = x;
};

void button_class::set_pos_y(float y)
{
    button_class::pos_y = y;
};

void button_class::set_pos_z(float z)
{
    button_class::pos_z = z;
};

void button_class::set_size(float w, float h)
{
    button_class::width  = w;
    button_class::height = h;
};

float button_class::get_width(void)
{
    return(button_class::width);
};

float button_class::get_height(void)
{
    return(button_class::height);
};

void button_class::set_label(std::string text)
{
    button_class::label = text;
};

void button_class::set_color_normal(int r, int g, int b, int a)
{
    button_class::normal_color_r = r;
    button_class::normal_color_g = g;
    button_class::normal_color_b = b;
    button_class::normal_color_a = a;
};

void button_class::set_color_highlighted(int r, int g, int b, int a)
{
    button_class::highlighted_color_r = r;
    button_class::highlighted_color_g = g;
    button_class::highlighted_color_b = b;
    button_class::highlighted_color_a = a;
};

void button_class::set_color_disabled(int r, int g, int b, int a)
{
    button_class::disabled_color_r = r;
    button_class::disabled_color_g = g;
    button_class::disabled_color_b = b;
    button_class::disabled_color_a = a;
};

void button_class::set_image_normal(int image)
{
    button_class::image_normal = image;
};

void button_class::set_image_disabled(int image)
{
    button_class::image_disabled = image;
};

void button_class::set_image_highlighted(int image)
{
    button_class::image_highlighted = image;
};

void  button_class::set_image_choice_disabled(int image)
{
    button_class::image_choice_disabled = image;
};

void button_class::set_image_arrow_normal(int image)
{
    button_class::image_arrow_normal = image;
};

void button_class::set_image_arrow_disabled(int image)
{
    button_class::image_arrow_disabled = image;
};

void button_class::set_image_arrow_highlighted(int image)
{
    button_class::image_arrow_highlighted = image;
};

void button_class::set_enabled(bool bool_value)
{
    button_class::enabled = bool_value;
};

void button_class::set_highlighted(bool bool_value)
{
    button_class::highlighted = bool_value;
};

bool button_class::mouse_over(void)
{
    if ((highlighted) && (zoom)) return(game.core.physics.point_in_quadrangle(button_class::pos_x,button_class::width+button_class::zoom_size,button_class::pos_y,button_class::height+button_class::zoom_size,game.core.io.mouse_x,game.core.io.mouse_y));
    else return(game.core.physics.point_in_quadrangle(button_class::pos_x,button_class::width,button_class::pos_y,button_class::height,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool button_class::mouse_clicked(void)
{
    if (game.core.io.mouse_button_left)
    {
        if ((highlighted) && (zoom)) return(game.core.physics.point_in_quadrangle(button_class::pos_x,button_class::width+button_class::zoom_size,button_class::pos_y,button_class::height+button_class::zoom_size,game.core.io.mouse_x,game.core.io.mouse_y));
       else return(game.core.physics.point_in_quadrangle(button_class::pos_x,button_class::width,button_class::pos_y,button_class::height,game.core.io.mouse_x,game.core.io.mouse_y));
    }
    else return(false);
};

void  button_class::set_zoom_size_counter(float zsc)
{
    button_class::zoom_size_counter = zsc;
};

float button_class::get_zoom_size_counter(void)
{
    return(button_class::zoom_size_counter);
};

void  button_class::set_zoom_speed(float zsp)
{
    button_class::zoom_speed = zsp;
};

float button_class::get_zoom_speed(void)
{
    return(button_class::zoom_speed);
};

void button_class::draw(void)
{
    float delta_x = 0.0f;
    float temp_x  = 0.0f;
    float temp_y  = 0.0f;
    float temp_z  = 0.0f;
    float temp_w  = 0.0f;
    float temp_h  = 0.0f;
    if ((button_class::type == NORMAL) || (button_class::type == TOGGLE)) //----- normal / toggle button -----
    {
        temp_x  = button_class::pos_x;
        temp_y  = button_class::pos_y;
        temp_z  = button_class::pos_z;
        temp_w  = button_class::width  + button_class::get_zoom_size_counter();
        temp_h  = button_class::height + button_class::get_zoom_size_counter();
        if (!button_class::active) return;
        if (!button_class::enabled) draw_texture(false,button_class::image_disabled,temp_x,temp_y,temp_z,temp_w,temp_h);
        else
        {
            if (button_class::highlighted) draw_texture(false,button_class::image_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
            else draw_texture(false,button_class::image_normal,temp_x,temp_y,temp_z,temp_w,temp_h);
        };
        if (button_class::type == TOGGLE) //----- toggle button -----
        {
            temp_x  = button_class::pos_x+(button_class::width/2)-(button_class::height/2);
            temp_y  = button_class::pos_y;
            temp_z  = button_class::pos_z;
            temp_w  = button_class::height + button_class::get_zoom_size_counter();
            temp_h  = button_class::height + button_class::get_zoom_size_counter();
            if (button_class::toggle_data)
            {
                if (button_class::highlighted) draw_texture(false,button_class::image_toggle_true_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
                else draw_texture(false,button_class::image_toggle_true_normal,temp_x,temp_y,temp_z,temp_w,temp_h);
            }
            else
            {
                if (button_class::highlighted) draw_texture(false,button_class::image_toggle_false_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
                else draw_texture(false,button_class::image_toggle_false_normal,temp_x,temp_y,temp_z,temp_w,temp_h);
            }
        };
        switch(button_class::get_font())
        {
            case 1:
                if ((!button_class::enabled) && ( button_class::highlighted)) game.font.font_1.Write(button_class::disabled_color_r   ,button_class::disabled_color_g   ,button_class::disabled_color_b   ,button_class::disabled_color_a   ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) game.font.font_1.Write(button_class::disabled_color_r   ,button_class::disabled_color_g   ,button_class::disabled_color_b   ,button_class::disabled_color_a   ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) game.font.font_1.Write(button_class::normal_color_r     ,button_class::normal_color_g     ,button_class::normal_color_b     ,button_class::normal_color_a     ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
/*
            case 2:
                if ((!button_class::enabled) && ( button_class::highlighted)) game.font.font_2.Write(button_class::disabled_color_r   ,button_class::disabled_color_g   ,button_class::disabled_color_b   ,button_class::disabled_color_a   ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) game.font.font_2.Write(button_class::disabled_color_r   ,button_class::disabled_color_g   ,button_class::disabled_color_b   ,button_class::disabled_color_a   ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) game.font.font_2.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) game.font.font_2.Write(button_class::normal_color_r     ,button_class::normal_color_g     ,button_class::normal_color_b     ,button_class::normal_color_a     ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
*/
            default:
                if ((!button_class::enabled) && ( button_class::highlighted)) game.font.font_1.Write(button_class::disabled_color_r   ,button_class::disabled_color_g   ,button_class::disabled_color_b   ,button_class::disabled_color_a   ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) game.font.font_1.Write(button_class::disabled_color_r   ,button_class::disabled_color_g   ,button_class::disabled_color_b   ,button_class::disabled_color_a   ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) game.font.font_1.Write(button_class::normal_color_r     ,button_class::normal_color_g     ,button_class::normal_color_b     ,button_class::normal_color_a     ,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
        }
    };
    if (button_class::type == CLOSE) //----- close button -----
    {
        temp_x  = button_class::pos_x;
        temp_y  = button_class::pos_y;
        temp_z  = button_class::pos_z;
        temp_w  = button_class::width;
        temp_h  = button_class::height;

        if (button_class::highlighted) draw_texture(false,button_class::image_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
        else draw_texture(false,button_class::image_normal,temp_x,temp_y,temp_z,temp_w,temp_h);
    }

    if (button_class::type == CHOICE) //----- choice button -----
    {
        if(button_class::number_of_visible_choices < button_class::number_of_choices)
        {
            // --- left  arrow ---
            temp_x  = button_class::arrow_left_pos_x;
            temp_y  = button_class::arrow_left_pos_y;
            temp_z  = button_class::pos_z;
            temp_w  = button_class::arrow_width  + button_class::get_arrow_left_zoom_size_counter();
            temp_h  = button_class::arrow_height + button_class::get_arrow_left_zoom_size_counter();
            if (button_class::get_arrow_left_highlighted()) draw_texture(false,button_class::image_arrow_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
            else draw_texture(false,button_class::image_arrow_normal,temp_x,temp_y,temp_z,temp_w,temp_h);
            // --- right arrow ---
            temp_x  = button_class::arrow_right_pos_x;
            temp_y  = button_class::arrow_right_pos_y;
            temp_z  = button_class::pos_z;
            temp_w  = button_class::arrow_width  + button_class::get_arrow_right_zoom_size_counter();
            temp_h  = button_class::arrow_height + button_class::get_arrow_right_zoom_size_counter();
            if (button_class::get_arrow_right_highlighted()) draw_texture(false,button_class::image_arrow_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h,180.0f);
            else draw_texture(false,button_class::image_arrow_normal,temp_x,temp_y,temp_z,temp_w,temp_h,180.0f);
        }
        // --- Show current selection ---
        delta_x = (button_class::arrow_width/3) *4;
        for(int choice_count = 0; choice_count < button_class::get_number_of_visible_choices(); choice_count++)
        {
            if (button_class::choice_data[button_class::choice_position+choice_count].active)
            {
                if (button_class::choice_position+choice_count == (button_class::current_choice+2))
                {
                    float selector_size = button_class::arrow_width/10;
                    temp_x  = delta_x+button_class::arrow_left_pos_x;
                    temp_y  = button_class::arrow_left_pos_y;
                    temp_z  = button_class::pos_z;
                    temp_w  = button_class::arrow_width  + selector_size + button_class::get_choice_zoom_size_counter(button_class::choice_position+choice_count);
                    temp_h  = button_class::arrow_height + selector_size + button_class::get_choice_zoom_size_counter(button_class::choice_position+choice_count);
                    draw_texture(false,button_class::image_selector,temp_x,temp_y,temp_z,temp_w,temp_h);
                }
                delta_x += (button_class::arrow_width/2) *3;
            }
        }
        // --- choice buttons    ---
        delta_x = (button_class::arrow_width/3) *4;
        for(int choice_count = 0; choice_count < button_class::get_number_of_visible_choices(); choice_count++)
        {
            if (button_class::choice_data[button_class::choice_position+choice_count].active)
            {
                temp_x  = delta_x+button_class::arrow_left_pos_x;
                temp_y  = button_class::arrow_left_pos_y;
                temp_z  = button_class::pos_z;
                temp_w  = button_class::arrow_width  + button_class::get_choice_zoom_size_counter(button_class::choice_position+choice_count);
                temp_h  = button_class::arrow_height + button_class::get_choice_zoom_size_counter(button_class::choice_position+choice_count);
                if (button_class::choice_data[button_class::choice_position+choice_count].enabled) draw_texture(false,button_class::choice_data[button_class::choice_position+choice_count].image_ref,temp_x,temp_y,temp_z,temp_w,temp_h);
                else draw_texture(false,button_class::image_choice_disabled,temp_x,temp_y,temp_z,temp_w,temp_h);
                delta_x += (button_class::arrow_width/2) *3;
            }
        }
        std::string temp_label = " ";
        for(int choice_count = 0; choice_count < button_class::get_number_of_visible_choices(); choice_count++)
        {
            if ((button_class::choice_data[button_class::choice_position+choice_count].highlighted) && ( button_class::choice_data[button_class::choice_position+choice_count].enabled)) temp_label = button_class::choice_data[button_class::choice_position+choice_count].text_label;//choices
            if ((button_class::choice_data[button_class::choice_position+choice_count].highlighted) && (!button_class::choice_data[button_class::choice_position+choice_count].enabled)) temp_label = button_class::disabled_text_label;//choices
        }
        switch(button_class::get_font()) //write selected level name
        {
            case 1:
                game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,((button_class::arrow_width/3) *4)+button_class::arrow_left_pos_x-(button_class::arrow_width/2)-(button_class::get_zoom_size_counter()/2),button_class::arrow_left_pos_y-((button_class::arrow_height/5)*4)-(button_class::get_zoom_size_counter()/2),button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),temp_label);
            break;
/*
            case 2:
                game.font.font_2.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,((button_class::arrow_width/3) *4)+button_class::arrow_left_pos_x-(button_class::arrow_width/2)-(button_class::get_zoom_size_counter()/2),button_class::arrow_left_pos_y-((button_class::arrow_height/5)*4)-(button_class::get_zoom_size_counter()/2),button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),temp_label);
            break;
*/
            default:
                game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,((button_class::arrow_width/3) *4)+button_class::arrow_left_pos_x-(button_class::arrow_width/2)-(button_class::get_zoom_size_counter()/2),button_class::arrow_left_pos_y-((button_class::arrow_height/5)*4)-(button_class::get_zoom_size_counter()/2),button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),temp_label);
            break;
        };
    }
    if (button_class::type == SLIDER) //----- slider button -----
    {
        // --- left  arrow ---
        temp_x  = button_class::arrow_left_pos_x;
        temp_y  = button_class::arrow_left_pos_y;
        temp_z  = button_class::pos_z;
        temp_w  = button_class::arrow_width  + button_class::get_arrow_left_zoom_size_counter();
        temp_h  = button_class::arrow_height + button_class::get_arrow_left_zoom_size_counter();
        if (button_class::get_arrow_left_highlighted()) draw_texture(false,button_class::image_arrow_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
        else draw_texture(false,button_class::image_arrow_normal,temp_x,temp_y,temp_z,temp_w,temp_h);
        // --- right arrow ---
        temp_x  = button_class::arrow_right_pos_x;
        temp_y  = button_class::arrow_right_pos_y;
        temp_z  = button_class::pos_z;
        temp_w  = button_class::arrow_width  + button_class::get_arrow_right_zoom_size_counter();
        temp_h  = button_class::arrow_height + button_class::get_arrow_right_zoom_size_counter();
        if (button_class::get_arrow_right_highlighted()) draw_texture(false,button_class::image_arrow_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h,180.0f);
        else draw_texture(false,button_class::image_arrow_normal,temp_x,temp_y,temp_z,temp_w,temp_h,180.0f);
        // --- slider bar ---
        delta_x  = (((button_class::width/200)*140)*((float)button_class::slider_position/(float)button_class::slider_position_max));
        temp_x   = button_class::pos_x - ((button_class::width/200)*70) + (delta_x/2);
        temp_y   = button_class::pos_y;
        temp_z   = button_class::pos_z;
        temp_w   = delta_x + button_class::get_zoom_size_counter();
        temp_h   = button_class::height + button_class::get_zoom_size_counter();
        if (button_class::highlighted) draw_texture(false,button_class::image_slider_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h,0.0f);
        else draw_texture(false,button_class::image_slider_normal,temp_x,temp_y,temp_z,temp_w,temp_h,0.0f);
        std::string temp_label = button_class::label;
        switch(button_class::get_font()) //write selected level name
        {
            case 1:
                game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
/*
            case 2:
                game.font.font_2.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
*/
            default:
                game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
        };
    }
    if(button_class::type == ACHIEVE) // Achieve button
    {
        float delta_x = 0.0f;
        temp_x  = button_class::pos_x;
        temp_y  = button_class::pos_y;
        temp_z  = button_class::pos_z;
        temp_w  = button_class::height + button_class::get_zoom_size_counter();
        temp_h  = button_class::height + button_class::get_zoom_size_counter();
        for (int achieve_count = 0; achieve_count < button_class::achieve_data; achieve_count++)
        {
            delta_x =(button_class::pos_x - (button_class::width/2)) + ((button_class::width/(float)button_class::achieve_data) * (float)achieve_count)+ (button_class::width/2/(float)button_class::achieve_data);

            if(button_class::achieve_position > achieve_count) draw_texture(false,button_class::image_achieve_highlighted,temp_x,temp_y,temp_z,temp_w,temp_h);
            else draw_texture(false,button_class::image_achieve_normal,temp_x+delta_x,temp_y,temp_z,temp_w,temp_h);
        }
        std::string temp_label = button_class::label;
        switch(button_class::get_font()) //write selected level name
        {
            case 1:
                game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y+button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
/*
            case 2:
                game.font.font_2.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y+button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
*/
            default:
                game.font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y+button_class::height/3,button_class::text_width+(button_class::zoom_size/2),button_class::text_height+(button_class::zoom_size/2),button_class::label);
            break;
        };
    }
};

bool button_class::button_pressed(void)
{
    if ((game.core.io.select) && (button_class::highlighted)) return (true);
    else return (false);
};

void button_class::set_active(bool bool_data)
{
    button_class::active = bool_data;
};

bool  button_class::get_active(void)
{
    return(button_class::active);
};

void button_class::set_zoom(bool bool_data)
{
    button_class::zoom      = bool_data;
};

void button_class::set_zoom(bool bool_data, float zs)
{
    button_class::zoom      = bool_data;
    button_class::zoom_size = zs;
};

void  button_class::set_disabled_text_label(std::string disabled_text_label)
{
    button_class::disabled_text_label = disabled_text_label;
};

void  button_class::set_zoom(bool bool_data, float zs, float zsp)
{
    button_class::zoom       = bool_data;
    button_class::zoom_size  = zs;
    button_class::zoom_speed = zsp;
};

void button_class::set_font(int font_number)
{
    button_class::button_font = font_number;
};

int  button_class::get_font(void)
{
    return(button_class::button_font);
};

bool  button_class::get_highlighted(void)
{
    return(button_class::highlighted);
};

void  button_class::set_zoom_size(float zs)
{
    button_class::zoom_size = zs;
};

float button_class::get_zoom_size(void)
{
    return(button_class::zoom_size);
};

void  button_class::set_data(float x, float y, float z, float w, float h, int in, int ih)
{
    button_class::active              = true;
    button_class::image_normal        = in;
    button_class::image_highlighted   = ih;
    button_class::highlighted         = false;
    button_class::pos_x               = x;
    button_class::pos_y               = y;
    button_class::pos_z               = z;
    button_class::width               = w;
    button_class::height              = h;
    button_class::label               = "x";
};

void  button_class::set_data(float x, float y, float z, float w, float h)
{
    button_class::active              = true;
    button_class::highlighted         = false;
    button_class::pos_x               = x;
    button_class::pos_y               = y;
    button_class::pos_z               = z;
    button_class::width               = w;
    button_class::height              = h;
    button_class::label               = "x";
};

void  button_class::set_data(int in, int ih)
{
    button_class::active              = true;
    button_class::image_normal        = in;
    button_class::image_highlighted   = ih;
    button_class::highlighted         = false;
    button_class::label               = "x";
};

void  button_class::set_button_type(int bt)
{
    button_class::type = bt;
};

int   button_class::get_button_type(void)
{
    return(button_class::type);
};

float button_class::get_pos_x(void)
{
    return(button_class::pos_x);
};

float button_class::get_pos_y(void)
{
    return(button_class::pos_y);
};

float button_class::get_pos_z(void)
{
    return(button_class::pos_z);
};

void  button_class::set_arrow_left_pos_x(float set_data)
{
    button_class::arrow_left_pos_x = set_data;
};

float button_class::get_arrow_left_pos_x(void)
{
    return(button_class::arrow_left_pos_x);
};

void  button_class::set_arrow_left_pos_y(float set_data)
{
    button_class::arrow_left_pos_y = set_data;
};

float button_class::get_arrow_left_pos_y(void)
{
    return(button_class::arrow_left_pos_y);
};

void  button_class::set_arrow_right_pos_x(float set_data)
{
    button_class::arrow_right_pos_x = set_data;
};

float button_class::get_arrow_right_pos_x(void)
{
    return(button_class::arrow_right_pos_x);
};

void  button_class::set_arrow_right_pos_y(float set_data)
{
    button_class::arrow_right_pos_y = set_data;
};

float button_class::get_arrow_right_pos_y(void)
{
    return(button_class::arrow_right_pos_y);
};

void  button_class::set_arrow_width(float set_data)
{
    button_class::arrow_width = set_data;
};

void  button_class::set_arrow_height(float set_data)
{
    button_class::arrow_height = set_data;
};

float button_class::get_arrow_width(void)
{
    return(button_class::arrow_width);
};

float button_class::get_arrow_height(void)
{
    return(button_class::arrow_height);
};

void  button_class::set_arrow_data(float lx, float ly, float rx, float ry, float w, float h)
{
    button_class::arrow_left_pos_x  = lx;
    button_class::arrow_left_pos_y  = ly;
    button_class::arrow_right_pos_x = rx;
    button_class::arrow_right_pos_y = ry;
    button_class::arrow_width       = w;
    button_class::arrow_height      = h;
};

void  button_class::set_slider_position(int set_data)
{
    button_class::slider_position = set_data;
};

int button_class::get_slider_position(void)
{
    return(button_class::slider_position);
};

void  button_class::set_choice_position(int set_data)
{
    button_class::choice_position = set_data;
};

int   button_class::get_choice_position(void)
{
    return(button_class::choice_position);
};

void  button_class::set_choice_data(int choice_number, int image_ref_data, std::string text_label_data, bool active_data)
{
    button_class::choice_data[choice_number].active     = active_data;
    button_class::choice_data[choice_number].image_ref  = image_ref_data;
    button_class::choice_data[choice_number].text_label = text_label_data;
};

void  button_class::set_choice_data(int choice_number, int image_ref_data, bool active_data)
{
    button_class::choice_data[choice_number].active     = active_data;
    button_class::choice_data[choice_number].image_ref  = image_ref_data;
};

void  button_class::set_number_of_choices(int choice_data)
{
    button_class::number_of_choices = choice_data;
};

int   button_class::get_number_of_choices(void)
{
    return(button_class::number_of_choices);
};

void  button_class::set_choice_enabled(int choice_number, bool enabled_data)
{
    button_class::choice_data[choice_number].enabled = enabled_data;
};

bool  button_class::get_choice_enabled(int choice_number)
{
    return(button_class::choice_data[choice_number].enabled);
};

void  button_class::set_choice_zoom_size_counter(int choice_number, float zoom_data)
{
    button_class::choice_data[choice_number].zoom_size_counter = zoom_data;
};

float   button_class::get_choice_zoom_size_counter(int choice_number)
{
    return(button_class::choice_data[choice_number].zoom_size_counter);
};

void  button_class::set_arrow_left_zoom_size_counter(float zoom_data)
{
    button_class::arrow_left_zoom_size_counter = zoom_data;
};

float   button_class::get_arrow_left_zoom_size_counter(void)
{
    return(button_class::arrow_left_zoom_size_counter);
};

void  button_class::set_arrow_right_zoom_size_counter(float zoom_data)
{
    button_class::arrow_right_zoom_size_counter = zoom_data;
};

float   button_class::get_arrow_right_zoom_size_counter(void)
{
    return(button_class::arrow_right_zoom_size_counter);
};

void  button_class::set_choice_highlighted(int choice_number, bool bool_data)
{
    button_class::choice_data[choice_number].highlighted = bool_data;
};

bool  button_class::get_choice_highlighted(int choice_number)
{
    return(button_class::choice_data[choice_number].highlighted);
};

void  button_class::set_arrow_left_highlighted (bool bool_data)
{
    button_class::arrow_left_highlighted = bool_data;
};

bool  button_class::get_arrow_left_highlighted (void)
{
    return(button_class::arrow_left_highlighted);
};

void  button_class::set_arrow_right_highlighted(bool bool_data)
{
    button_class::arrow_right_highlighted = bool_data;
};

bool  button_class::get_arrow_right_highlighted(void)
{
    return(button_class::arrow_right_highlighted);
};

void  button_class::set_slider_pos_x(float float_data)
{
    button_class::slider_pos_x = float_data;
};

float button_class::get_slider_pos_x(void)
{
    return(button_class::slider_pos_x);
};

void  button_class::set_slider_pos_y(float float_data)
{
    button_class::slider_pos_y = float_data;
};

float button_class::get_slider_pos_y(void)
{
    return(button_class::slider_pos_y);
};

void  button_class::set_slider_width(float float_data)
{
    button_class::slider_width = float_data;
};

float button_class::get_slider_width(void)
{
    return(button_class::slider_width);
};

void  button_class::set_slider_height(float float_data)
{
    button_class::slider_height = float_data;
};

float button_class::get_slider_height(void)
{
    return(button_class::slider_height);
};

void  button_class::set_image_slider_normal(int image)
{
    button_class::image_slider_normal = image;
};

void  button_class::set_image_slider_highlighted(int image)
{
    button_class::image_slider_highlighted = image;
};

void  button_class::set_number_of_visible_choices(int visible_choice_data)
{
    button_class::number_of_visible_choices = visible_choice_data;
};

int   button_class::get_number_of_visible_choices(void)
{
    return(button_class::number_of_visible_choices);
};

void  button_class::set_slider_position_max(int set_data)
{
    button_class::slider_position_max = set_data;
};

int   button_class::get_slider_position_max(void)
{
    return(button_class::slider_position_max);
};

void  button_class::set_current_choice(int choice_data)
{
    button_class::current_choice = choice_data;
};

int   button_class::get_current_choice(void)
{
    return(button_class::current_choice);
};

void  button_class::set_image_selector(int image)
{
    button_class::image_selector = image;
};

void  button_class::set_toggle_data(bool bool_data)
{
    button_class::toggle_data = bool_data;
};

bool   button_class::get_toggle_data(void)
{
    return(button_class::toggle_data);
};

void  button_class::set_toggle_images(int tth, int ttn, int tfh, int tfn)
{
    button_class::image_toggle_true_highlighted   = tth;
    button_class::image_toggle_true_normal        = ttn;
    button_class::image_toggle_false_highlighted  = tfh;
    button_class::image_toggle_false_normal       = tfn;
};

void  button_class::set_image_toggle_true_highlighted(int image)
{
    button_class::image_toggle_true_highlighted   = image;
};

void  button_class::set_image_toggle_true_normal(int image)
{
    button_class::image_toggle_true_normal        = image;
};

void  button_class::set_image_toggle_false_highlighted(int image)
{
    button_class::image_toggle_false_highlighted  = image;
};

void  button_class::set_image_toggle_false_normal(int image)
{
    button_class::image_toggle_false_normal       = image;
};

void  button_class::set_image_achieve_highlighted(int image)
{
    button_class::image_achieve_highlighted = image;
};

void  button_class::set_image_achieve_normal(int image)
{
    button_class::image_achieve_normal = image;
};

void  button_class::set_achieve_data(int int_data)
{
    button_class::achieve_data = int_data;
};

int   button_class::get_achieve_data(void)
{
    return(button_class::achieve_data);
};

void  button_class::set_achieve_position(int int_data)
{
    button_class::achieve_position = int_data;
};

bool  button_class::get_enabled(void)
{
    return(button_class::enabled);
};

void  button_class::set_text_size(float width, float height)
{
    button_class::text_width  = width;
    button_class::text_height = height;
};

//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------
//------------------------------------------ menu ---------------------------------------------------------------------------------------

menu_class::menu_class(void)
{
    menu_class::current_vertical_selection = 1;
    menu_class::button[1].set_highlighted(true);
};

menu_class::menu_class(int num_buttons)
{
    menu_class::current_vertical_selection = 1;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        if (button_count <= num_buttons) menu_class::button[button_count].set_active(true);
        else menu_class::button[button_count].set_active(false);
    }
    menu_class::button[1].set_highlighted(true);
};

void menu_class::set_pos(float x, float y, float z)
{
    menu_class::pos_x = x;
    menu_class::pos_y = y;
    menu_class::pos_z = z;
};

void menu_class::set_size(float w, float h)
{
    menu_class::width  = w;
    menu_class::height = h;
};

void menu_class::set_image_background(int bi)
{
    menu_class::image_background = bi;
};

void menu_class::draw(void)
{
    draw_texture(false,menu_class::image_background,menu_class::pos_x,menu_class::pos_y,menu_class::pos_z,menu_class::width,menu_class::height);
    switch(menu_class::menu_font) // title text
    {
        case 1:
            game.font.font_1.Write(menu_class::title_color_r,menu_class::title_color_g,menu_class::title_color_b,menu_class::title_color_a,menu_class::title_pos_x-menu_class::title_width/3.4,menu_class::title_pos_y-menu_class::title_height/1.8f,menu_class::text_width,menu_class::text_height,menu_class::title_label);
        break;
/*
        case 2:
            game.font.font_2.Write(menu_class::title_color_r,menu_class::title_color_g,menu_class::title_color_b,menu_class::title_color_a,menu_class::title_pos_x-menu_class::title_width/3.4,menu_class::title_pos_y-menu_class::title_height/1.8f,menu_class::text_width,menu_class::text_height,menu_class::title_label);
        break;
*/
        default:
            game.font.font_1.Write(menu_class::title_color_r,menu_class::title_color_g,menu_class::title_color_b,menu_class::title_color_a,menu_class::title_pos_x-menu_class::title_width/3.4,menu_class::title_pos_y-menu_class::title_height/1.8f,menu_class::text_width,menu_class::text_height,menu_class::title_label);
        break;
    }
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].draw();
    }
    menu_class::close_button.draw();
};

void menu_class::set_color_title(int r, int g, int b, int a)
{
    menu_class::title_color_r = r;
    menu_class::title_color_g = g;
    menu_class::title_color_b = b;
    menu_class::title_color_a = a;
};

void menu_class::set_color_normal(int r, int g, int b, int a)
{
    menu_class::normal_color_r = r;
    menu_class::normal_color_g = g;
    menu_class::normal_color_b = b;
    menu_class::normal_color_a = a;
};

void menu_class::set_color_highlighted(int r, int g, int b, int a)
{
    menu_class::highlighted_color_r = r;
    menu_class::highlighted_color_g = g;
    menu_class::highlighted_color_b = b;
    menu_class::highlighted_color_a = a;
};

void menu_class::set_color_disabled(int r, int g, int b, int a)
{
    menu_class::disabled_color_r = r;
    menu_class::disabled_color_g = g;
    menu_class::disabled_color_b = b;
    menu_class::disabled_color_a = a;
};

void menu_class::set_button_image_normal(int image)
{
    menu_class::button_image_normal = image;
};

void menu_class::set_button_image_disabled(int image)
{
    menu_class::button_image_disabled = image;
};

void menu_class::set_button_image_highlighted(int image)
{
    menu_class::button_image_highlighted = image;
};

void menu_class::set_button_data(int button_number)
{
    menu_class::button[button_number].set_highlighted                    (false);
    menu_class::button[button_number].set_button_type                    (NORMAL);
    menu_class::button[button_number].set_active                         (true);
    menu_class::button[button_number].set_font                           (menu_class::button_font);
    menu_class::button[button_number].set_pos_z                          (menu_class::button_z_pos);
    menu_class::button[button_number].set_size                           (menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_label                          ("Not Set");
    menu_class::button[button_number].set_color_normal                   (menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted              (menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled                 (menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal                   (menu_class::button_image_normal);
    menu_class::button[button_number].set_image_highlighted              (menu_class::button_image_highlighted);
    menu_class::button[button_number].set_image_disabled                 (menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_choice_disabled          (menu_class::button_image_choice_disabled);
    menu_class::button[button_number].set_image_selector                 (menu_class::button_image_selector);
    menu_class::button[button_number].set_image_slider_normal            (menu_class::button_image_slider_normal);
    menu_class::button[button_number].set_image_slider_highlighted       (menu_class::button_image_slider_highlighted);
    menu_class::button[button_number].set_image_arrow_normal             (menu_class::button_image_arrow_normal);
    menu_class::button[button_number].set_image_arrow_highlighted        (menu_class::button_image_arrow_highlighted);
    menu_class::button[button_number].set_image_arrow_disabled           (menu_class::button_image_arrow_disabled);
    menu_class::button[button_number].set_image_toggle_true_highlighted  (menu_class::button_image_toggle_true_highlighted);
    menu_class::button[button_number].set_image_toggle_true_normal       (menu_class::button_image_toggle_true_normal);
    menu_class::button[button_number].set_image_toggle_false_highlighted (menu_class::button_image_toggle_false_highlighted);
    menu_class::button[button_number].set_image_toggle_false_normal      (menu_class::button_image_toggle_false_normal);
    menu_class::button[button_number].set_image_achieve_highlighted      (menu_class::button_image_achieve_highlighted);
    menu_class::button[button_number].set_image_achieve_normal           (menu_class::button_image_achieve_normal);
    menu_class::button[button_number].set_zoom                           (menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
};

void menu_class::set_button_data(int button_number, std::string label)
{
    menu_class::button[button_number].set_highlighted                    (false);
    menu_class::button[button_number].set_button_type                    (NORMAL);
    menu_class::button[button_number].set_active                         (true);
    menu_class::button[button_number].set_font                           (menu_class::button_font);
    menu_class::button[button_number].set_pos_z                          (menu_class::button_z_pos);
    menu_class::button[button_number].set_label                          (label);
    menu_class::button[button_number].set_size                           (menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_color_normal                   (menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted              (menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled                 (menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal                   (menu_class::button_image_normal);
    menu_class::button[button_number].set_image_highlighted              (menu_class::button_image_highlighted);
    menu_class::button[button_number].set_image_disabled                 (menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_choice_disabled          (menu_class::button_image_choice_disabled);
    menu_class::button[button_number].set_image_selector                 (menu_class::button_image_selector);
    menu_class::button[button_number].set_image_slider_normal            (menu_class::button_image_slider_normal);
    menu_class::button[button_number].set_image_slider_highlighted       (menu_class::button_image_slider_highlighted);
    menu_class::button[button_number].set_image_arrow_normal             (menu_class::button_image_arrow_normal);
    menu_class::button[button_number].set_image_arrow_highlighted        (menu_class::button_image_arrow_highlighted);
    menu_class::button[button_number].set_image_arrow_disabled           (menu_class::button_image_arrow_disabled);
    menu_class::button[button_number].set_image_toggle_true_highlighted  (menu_class::button_image_toggle_true_highlighted);
    menu_class::button[button_number].set_image_toggle_true_normal       (menu_class::button_image_toggle_true_normal);
    menu_class::button[button_number].set_image_toggle_false_highlighted (menu_class::button_image_toggle_false_highlighted);
    menu_class::button[button_number].set_image_toggle_false_normal      (menu_class::button_image_toggle_false_normal);
    menu_class::button[button_number].set_image_achieve_highlighted      (menu_class::button_image_achieve_highlighted);
    menu_class::button[button_number].set_image_achieve_normal           (menu_class::button_image_achieve_normal);
    menu_class::button[button_number].set_zoom                           (menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
};

void menu_class::set_button_data(int button_number, std::string label,float x, float y, float z)
{
    menu_class::button[button_number].set_highlighted                    (false);
    menu_class::button[button_number].set_button_type                    (NORMAL);
    menu_class::button[button_number].set_active                         (true);
    menu_class::button[button_number].set_font                           (menu_class::button_font);
    menu_class::button[button_number].set_pos                            (x,y,z);
    menu_class::button[button_number].set_label                          (label);
    menu_class::button[button_number].set_size                           (menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_color_normal                   (menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted              (menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled                 (menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal                   (menu_class::button_image_normal);
    menu_class::button[button_number].set_image_highlighted              (menu_class::button_image_highlighted);
    menu_class::button[button_number].set_image_disabled                 (menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_choice_disabled          (menu_class::button_image_choice_disabled);
    menu_class::button[button_number].set_image_selector                 (menu_class::button_image_selector);
    menu_class::button[button_number].set_image_slider_normal            (menu_class::button_image_slider_normal);
    menu_class::button[button_number].set_image_slider_highlighted       (menu_class::button_image_slider_highlighted);
    menu_class::button[button_number].set_image_arrow_normal             (menu_class::button_image_arrow_normal);
    menu_class::button[button_number].set_image_arrow_highlighted        (menu_class::button_image_arrow_highlighted);
    menu_class::button[button_number].set_image_arrow_disabled           (menu_class::button_image_arrow_disabled);
    menu_class::button[button_number].set_image_toggle_true_highlighted  (menu_class::button_image_toggle_true_highlighted);
    menu_class::button[button_number].set_image_toggle_true_normal       (menu_class::button_image_toggle_true_normal);
    menu_class::button[button_number].set_image_toggle_false_highlighted (menu_class::button_image_toggle_false_highlighted);
    menu_class::button[button_number].set_image_toggle_false_normal      (menu_class::button_image_toggle_false_normal);
    menu_class::button[button_number].set_image_achieve_highlighted      (menu_class::button_image_achieve_highlighted);
    menu_class::button[button_number].set_image_achieve_normal           (menu_class::button_image_achieve_normal);
    menu_class::button[button_number].set_zoom                           (menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
};

void menu_class::set_button_data(void)
{
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_highlighted                    (false);
        menu_class::button[button_count].set_button_type                    (NORMAL);
        menu_class::button[button_count].set_active                         (true);
        menu_class::button[button_count].set_font                           (menu_class::button_font);
        menu_class::button[button_count].set_pos_z                          (menu_class::button_z_pos);
        menu_class::button[button_count].set_size                           (menu_class::button_width,menu_class::button_height);
        menu_class::button[button_count].set_label                          ("Label Not Set");
        menu_class::button[button_count].set_color_normal                   (menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
        menu_class::button[button_count].set_color_highlighted              (menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
        menu_class::button[button_count].set_color_disabled                 (menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
        menu_class::button[button_count].set_image_normal                   (menu_class::button_image_normal);
        menu_class::button[button_count].set_image_highlighted              (menu_class::button_image_highlighted);
        menu_class::button[button_count].set_image_disabled                 (menu_class::button_image_disabled);
        menu_class::button[button_count].set_image_choice_disabled          (menu_class::button_image_choice_disabled);
        menu_class::button[button_count].set_image_selector                 (menu_class::button_image_selector);
        menu_class::button[button_count].set_image_slider_normal            (menu_class::button_image_slider_normal);
        menu_class::button[button_count].set_image_slider_highlighted       (menu_class::button_image_slider_highlighted);
        menu_class::button[button_count].set_image_arrow_normal             (menu_class::button_image_arrow_normal);
        menu_class::button[button_count].set_image_arrow_highlighted        (menu_class::button_image_arrow_highlighted);
        menu_class::button[button_count].set_image_arrow_disabled           (menu_class::button_image_arrow_disabled);
        menu_class::button[button_count].set_image_toggle_true_highlighted  (menu_class::button_image_toggle_true_highlighted);
        menu_class::button[button_count].set_image_toggle_true_normal       (menu_class::button_image_toggle_true_normal);
        menu_class::button[button_count].set_image_toggle_false_highlighted (menu_class::button_image_toggle_false_highlighted);
        menu_class::button[button_count].set_image_toggle_false_normal      (menu_class::button_image_toggle_false_normal);
        menu_class::button[button_count].set_image_achieve_highlighted      (menu_class::button_image_achieve_highlighted);
        menu_class::button[button_count].set_image_achieve_normal           (menu_class::button_image_achieve_normal);
        menu_class::button[button_count].set_zoom                           (menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
        menu_class::button[button_count].set_arrow_width                    ((menu_class::button_width /100)*10);
        menu_class::button[button_count].set_arrow_height                   (menu_class::button_height);
        menu_class::button[button_count].set_arrow_left_pos_x               (menu_class::pos_x-((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_left_pos_y               (menu_class::button[button_count].get_pos_y());
        menu_class::button[button_count].set_arrow_right_pos_x              (menu_class::pos_x+((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_right_pos_y              (menu_class::button[button_count].get_pos_y());
    }
};

void menu_class::set_button_zoom(bool z, float zs)
{
    menu_class::zoom      = z;
    menu_class::zoom_size = zs;
};

void  menu_class::set_button_zoom(bool bool_data, float zs, float zsp)
{
    menu_class::zoom       = bool_data;
    menu_class::zoom_size  = zs;
    menu_class::zoom_speed = zsp;
};

void menu_class::set_button_size(float w, float h)
{
    menu_class::button_width  = w;
    menu_class::button_height = h;
};

void menu_class::set_number_of_buttons(int nob)
{
    if (nob <  0) nob = 0;
    menu_class::number_of_buttons = nob;
    menu_class::current_vertical_selection = nob;
};

void menu_class::set_button_active(int button_number, bool bool_data)
{
    menu_class::button[button_number].set_active(bool_data);
};

void menu_class::set_button_spacing(void)
{
    menu_class::button_spacing = ((menu_class::width - menu_class::button_width) /2);
};

void menu_class::set_button_spacing(float button_offset)
{
    menu_class::button_spacing = button_offset;
};

void menu_class::set_button_spacing_auto(void)
{
    float button_offset = 0.0f;
    float temp_float    = 0.0f;
    switch (menu_class::number_of_buttons)
    {
        case 1:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 2:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 3:
            button_offset = (menu_class::button_height/2.0f)*2.6f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 4:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 5:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 6:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 7:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 8:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
        case 9:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.2)) - (menu_class::button_height/2.0f);
        break;
        default:
            button_offset = (menu_class::button_height/2.0f)*2.8f;
            temp_float = (menu_class::pos_y + (menu_class::height/2.1)) - (menu_class::button_height/2.0f);
        break;
    }
    menu_class::button_spacing = button_offset;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        temp_float -= button_offset;
        menu_class::button[button_count].set_pos_x(menu_class::pos_x);
        menu_class::button[button_count].set_pos_y(temp_float);
        menu_class::button[button_count].set_arrow_width    ((menu_class::button_width /100)*10);
        menu_class::button[button_count].set_arrow_height    (menu_class::button_height);
        menu_class::button[button_count].set_arrow_left_pos_x(menu_class::pos_x-((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_left_pos_y(menu_class::button[button_count].get_pos_y());
        menu_class::button[button_count].set_arrow_right_pos_x(menu_class::pos_x+((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_right_pos_y(menu_class::button[button_count].get_pos_y());
    }
};

void menu_class::set_button_spacing_auto(float button_offset)
{
    float temp_float = 0;
    menu_class::button_spacing = button_offset;
    temp_float = (menu_class::height/2) - button_offset - (button_offset /2);
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        temp_float -= button_offset;
        menu_class::button[button_count].set_pos_x(menu_class::pos_x);
        menu_class::button[button_count].set_pos_y(temp_float);
        menu_class::button[button_count].set_arrow_width ((menu_class::button_width /100)*10);
        menu_class::button[button_count].set_arrow_height (menu_class::button_height);
        menu_class::button[button_count].set_arrow_left_pos_x(menu_class::pos_x-((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_left_pos_y(menu_class::button[button_count].get_pos_y());
        menu_class::button[button_count].set_arrow_right_pos_x(menu_class::pos_x+((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_right_pos_y(menu_class::button[button_count].get_pos_y());
    }
};

void menu_class::set_button_x_pos(float xp)
{
    menu_class::button_x_pos = xp;
};

float menu_class::get_menu_x_pos(void)
{
    return(menu_class::pos_x);
};

void menu_class::set_button_y_pos(float yp)
{
    menu_class::button_y_pos = yp;
};

float menu_class::get_menu_y_pos(void)
{
    return(menu_class::pos_y);
};

void menu_class::set_button_z_pos(float zp)
{
    menu_class::button_z_pos = zp;
};

float menu_class::get_menu_z_pos(void)
{
    return(menu_class::pos_z);
};

void menu_class::set_menu_title(std::string menu_title)
{
    menu_class::title_label = menu_title;
};

void menu_class::set_menu_font(int font_number)
{
    menu_class::menu_font   = font_number;
    menu_class::button_font = font_number;
};

void menu_class::set_menu_button_font(int font_number)
{
    menu_class::button_font = font_number;
};

int  menu_class::get_menu_font(void)
{
    return(menu_class::menu_font);
};

void menu_class::set_button_font(int button_number)
{
    menu_class::button[button_number].set_font(menu_class::button_font);
};

void menu_class::set_button_size_auto(void)
{
    menu_class::button_width  = (menu_class::width / 100.0f) * 90.0f;
    menu_class::button_height = (menu_class::height / (menu_class::number_of_buttons+(((menu_class::number_of_buttons + 4)) / 2)));
    set_button_size(menu_class::button_width,menu_class::button_height);
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_size(menu_class::button_width,menu_class::button_height);
        menu_class::button[button_count].set_arrow_width ((menu_class::button_width /100)*10);
        menu_class::button[button_count].set_arrow_height (menu_class::button_height);
        menu_class::button[button_count].set_arrow_left_pos_x(menu_class::pos_x-((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_left_pos_y(menu_class::button[button_count].get_pos_y());
        menu_class::button[button_count].set_arrow_right_pos_x(menu_class::pos_x+((menu_class::width /200)*80));
        menu_class::button[button_count].set_arrow_right_pos_y(menu_class::button[button_count].get_pos_y());
    }
};

void menu_class::set_current_vertical_selection(int cvs)
{
    menu_class::current_vertical_selection = cvs;
};

int  menu_class::get_current_vertical_selection(void)
{
    return(menu_class::current_vertical_selection);
};

void  menu_class::set_zoom_size_counter(int button_number,float zsc)
{
    menu_class::button[button_number].set_zoom_size_counter(zsc);
};

float menu_class::get_zoom_size_counter(int button_number)
{
    return(menu_class::button[button_number].get_zoom_size_counter());
};

void  menu_class::set_zoom_speed(int button_number,float zsp)
{
    menu_class::button[button_number].set_zoom_speed(zsp);
};

float menu_class::get_zoom_speed(int button_number)
{
    return(menu_class::button[button_number].get_zoom_speed());
};

bool  menu_class::mouse_over_any_button(void)
{
    bool return_value = false;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        if (menu_class::button[button_count].mouse_over()) return_value = true;
    }
    return(return_value);
};

void  menu_class::set_keyboard_delay(int kd)
{
    menu_class::keyboard_delay = kd;
};

int   menu_class::get_keyboard_delay(void)
{
    return(menu_class::keyboard_delay);
};

void  menu_class::set_keyboard_delay_count(int kdc)
{
    menu_class::keyboard_delay_count = kdc;
};

int   menu_class::get_keyboard_delay_count(void)
{
    return(menu_class::keyboard_delay_count);
};

void  menu_class::set_mouse_delay(int md)
{
    menu_class::mouse_delay = md;
};

int   menu_class::get_mouse_delay(void)
{
    return(menu_class::mouse_delay);
};

void  menu_class::set_mouse_delay_count(int mdc)
{
    menu_class::mouse_delay_count = mdc;
};

int   menu_class::get_mouse_delay_count(void)
{
    return(menu_class::mouse_delay_count);
};

void  menu_class::set_close_button_type(int bt)
{
    menu_class::close_button.set_button_type(bt);
};

void  menu_class::set_close_button_data(float x, float y, float z, float w, float h, int in, int ih)
{
    menu_class::close_button.set_data(x,y,z,w,h,in,ih);
};

void  menu_class::set_close_button_data(float x, float y, float z, float w, float h)
{
    menu_class::close_button.set_data(x,y,z,w,h);
};

void  menu_class::set_close_button_data(int in, int ih)
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;
    float h = 0.0f;
    switch (menu_class::number_of_buttons)
    {
        case 1:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 2:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 3:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 4:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 5:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 6:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 7:
            w = (menu_class::button_spacing / 100.0f) * 70.0f;
            h = (menu_class::button_spacing / 100.0f) * 70.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*56);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 8:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        case 9:
            w = (menu_class::button_spacing / 100.0f) * 85.0f;
            h = (menu_class::button_spacing / 100.0f) * 85.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*60);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
        default:
            w = (menu_class::button_spacing / 100.0f) * 60.0f;
            h = (menu_class::button_spacing / 100.0f) * 60.0f;
            x = (menu_class::pos_x+(menu_class::width /2))-((w/100)*58);
            y = (menu_class::pos_y+(menu_class::height/2))-((h/100)*65);
            z = menu_class::pos_z;
        break;
    }
    menu_class::close_button.set_button_type(CLOSE);
    menu_class::close_button.set_data(x,y,z,w,h,in,ih);
};

void  menu_class::set_drag_active(bool bool_data)
{
    menu_class::drag_active = bool_data;
};

bool  menu_class::get_drag_active(void)
{
    return(menu_class::drag_active);
};

void  menu_class::set_button_disabled_text_label(std::string disabled_text_label)
{
    menu_class::button_disabled_text_label = disabled_text_label;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_disabled_text_label(disabled_text_label);
    }
};


void  menu_class::set_title_data(std::string menu_title)
{
    menu_class::title_label  = menu_title;
    menu_class::title_height = ((menu_class::button_spacing/30)*2);
    menu_class::title_width  = (menu_class::width / 100.0f) * 40.0f;
    menu_class::title_pos_x  = menu_class::pos_x;
    menu_class::title_pos_z  = menu_class::pos_z;
    switch (menu_class::number_of_buttons)
    {
        case 1:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/3.8f);
        break;
        case 2:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.26f);
        break;
        case 3:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.27f);
        break;
        case 4:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.276f);
        break;
        case 5:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.2768f);
        break;
        case 6:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.27686f);
        break;
        case 7:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.27687f);
        break;
        case 8:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.2769f);
        break;
        case 9:
            menu_class::title_pos_y  = menu_class::pos_y+(menu_class::height/2.277f);
        break;
        default:
            menu_class::title_pos_y  = 0.0f;
        break;
    }
};

void  menu_class::set_title_data(float x, float y, float z, float w, float h, std::string menu_title)
{
    menu_class::title_label  = menu_title;
    menu_class::title_height = h;
    menu_class::title_width  = w;
    menu_class::title_pos_x  = x;
    menu_class::title_pos_y  = y;
    menu_class::title_pos_z  = z;
};

bool  menu_class::mouse_over_title(void)
{
    return(game.core.physics.point_in_quadrangle(menu_class::pos_x,menu_class::button_width,menu_class::title_pos_y,menu_class::button_height,game.core.io.mouse_x,game.core.io.mouse_y));
};
bool  menu_class::mouse_click_title(void)
{
    if (game.core.io.mouse_button_left) return(menu_class::mouse_over_title());
    else return(false);
};

void  menu_class::set_close_button_data(float x, float y, float z)
{
    menu_class::close_button.set_pos_x(x);
    menu_class::close_button.set_pos_y(y);
    menu_class::close_button.set_pos_z(z);
};

float menu_class::get_close_button_pos_x(void)
{
    return(menu_class::close_button.get_pos_x());
};

float menu_class::get_close_button_pos_y(void)
{
    return(menu_class::close_button.get_pos_y());
};

float menu_class::get_close_button_pos_z(void)
{
    return(menu_class::close_button.get_pos_z());
};

float menu_class::set_buttons_auto(void)
{
    menu_class::set_menu_button_font(menu_class::get_menu_font());
    menu_class::set_button_x_pos(menu_class::get_menu_x_pos());
    menu_class::set_button_z_pos(menu_class::get_menu_z_pos());
    menu_class::set_button_size_auto();
    menu_class::set_button_spacing_auto();
};

void  menu_class::set_image_arrow_normal(int image_ref_no)
{
    menu_class::button_image_arrow_normal = image_ref_no;
};

void  menu_class::set_image_arrow_highlighted(int image_ref_no)
{
    menu_class::button_image_arrow_highlighted = image_ref_no;
};

void  menu_class::set_image_arrow_disabled(int image_ref_no)
{
    menu_class::button_image_arrow_disabled = image_ref_no;
};

void  menu_class::set_button_images(int in, int ih, int id, int icd, int is, int isn, int ish, int ian, int iah, int iad)
{
    menu_class::button_image_normal             = in;
    menu_class::button_image_highlighted        = ih;
    menu_class::button_image_disabled           = id;
    menu_class::button_image_choice_disabled    = icd;
    menu_class::button_image_selector           = is;
    menu_class::button_image_slider_normal      = isn;
    menu_class::button_image_slider_highlighted = ish;
    menu_class::button_image_arrow_normal       = ian;
    menu_class::button_image_arrow_highlighted  = iah;
    menu_class::button_image_arrow_disabled     = iad;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_image_normal             (in);
        menu_class::button[button_count].set_image_highlighted        (ih);
        menu_class::button[button_count].set_image_disabled           (id);
        menu_class::button[button_count].set_image_choice_disabled    (icd);
        menu_class::button[button_count].set_image_selector           (is);
        menu_class::button[button_count].set_image_slider_normal      (isn);
        menu_class::button[button_count].set_image_slider_highlighted (ish);
        menu_class::button[button_count].set_image_arrow_normal       (ian);
        menu_class::button[button_count].set_image_arrow_highlighted  (iah);
        menu_class::button[button_count].set_image_arrow_disabled     (iad);
    }
};

void  menu_class::set_toggle_button_images(int tth, int ttn, int tfh, int tfn)
{
    button_image_toggle_true_highlighted  = tth;
    button_image_toggle_true_normal       = ttn;
    button_image_toggle_false_highlighted = tfh;
    button_image_toggle_false_normal      = tfn;
};

void  menu_class::set_button_arrow_left_pos_x(float set_data)
{
    menu_class::button_arrow_left_pos_x = set_data;
};

void  menu_class::set_button_arrow_left_pos_y(float set_data)
{
    menu_class::button_arrow_left_pos_y = set_data;
};

void  menu_class::set_button_arrow_right_pos_x(float set_data)
{
    menu_class::button_arrow_right_pos_x = set_data;
};

void  menu_class::set_button_arrow_right_pos_y(float set_data)
{
    menu_class::button_arrow_right_pos_y = set_data;
};

void  menu_class::set_button_arrow_width(float set_data)
{
    menu_class::button_arrow_width = set_data;
};

void  menu_class::set_button_arrow_height(float set_data)
{
    menu_class::button_arrow_height = set_data;
};

void  menu_class::set_button_arrow_data(int button_number, float lx, float ly, float rx, float ry, float w, float h)
{
    menu_class::button[button_number].set_arrow_left_pos_x  (lx);
    menu_class::button[button_number].set_arrow_left_pos_y  (ly);
    menu_class::button[button_number].set_arrow_right_pos_x (rx);
    menu_class::button[button_number].set_arrow_right_pos_y (ry);
    menu_class::button[button_number].set_arrow_width       (w);
    menu_class::button[button_number].set_arrow_height      (h);
};

void  menu_class::set_button_arrow_data_auto(int button_number)
{
    menu_class::button[button_number].set_arrow_width ((menu_class::button_width /100)*10);
    menu_class::button[button_number].set_arrow_height (menu_class::button_height);
    menu_class::button[button_number].set_arrow_left_pos_x(menu_class::pos_x-((menu_class::width /200)*80));
    menu_class::button[button_number].set_arrow_left_pos_y(menu_class::button[button_number].get_pos_y());
    menu_class::button[button_number].set_arrow_right_pos_x(menu_class::pos_x+((menu_class::width /200)*80));
    menu_class::button[button_number].set_arrow_right_pos_y(menu_class::button[button_number].get_pos_y());
    menu_class::button[button_number].set_arrow_left_zoom_size_counter (0);
    menu_class::button[button_number].set_arrow_right_zoom_size_counter(0);
    menu_class::button[button_number].set_arrow_left_highlighted       (false);
    menu_class::button[button_number].set_arrow_right_highlighted      (false);
    for(int choice_count = 1; choice_count < menu_class::button[button_number].get_number_of_choices(); choice_count++)
    {
        menu_class::button[button_number].set_highlighted              (false);
        menu_class::button[button_number].set_choice_zoom_size_counter (choice_count,0);
    }
};

void  menu_class::set_button_slider_position(int button_number, float set_data)
{
    menu_class::button[button_number].set_slider_position(set_data);
};

float menu_class::get_button_slider_position(int button_number)
{
    return(menu_class::button[button_number].get_slider_position());
};

void  menu_class::set_button_choice_position(int button_number, int set_data)
{
    menu_class::button[button_number].set_choice_position(set_data);
};

int menu_class::get_button_choice_position(int button_number)
{
    return(menu_class::button[button_number].get_choice_position());
};

void  menu_class::set_button_choice_data(int button_number, int choice_number, int image_ref_data, std::string text_label_data, bool active_data, bool enabled_data)
{
    menu_class::set_button_choice_enabled(button_number,choice_number,enabled_data);
    menu_class::button[button_number].set_active(true);
    menu_class::button[button_number].set_button_type(CHOICE);
    menu_class::button[button_number].set_choice_data(choice_number, image_ref_data, text_label_data, active_data);
};

void  menu_class::set_button_choice_data(int button_number, int choice_number, int image_ref_data, bool active_data, bool enabled_data)
{
    menu_class::set_button_choice_enabled(button_number,choice_number,enabled_data);
    menu_class::button[button_number].set_active(true);
    menu_class::button[button_number].set_button_type(CHOICE);
    menu_class::button[button_number].set_choice_data(choice_number, image_ref_data, active_data);
};

void  menu_class::set_number_of_choices(int button_number, int choice_data)
{
    menu_class::button[button_number].set_number_of_choices(choice_data);
};

int   menu_class::get_number_of_choices(int button_number)
{
    return(menu_class::button[button_number].get_number_of_choices());
};

void  menu_class::set_button_type(int button_number, int bt)
{
    menu_class::button[button_number].set_button_type(bt);
};

int   menu_class::get_button_type(int button_number)
{
    return(menu_class::button[button_number].get_button_type());
};

void  menu_class::set_button_choice_enabled(int button_number, int choice_number, bool enabled_data)
{
    menu_class::button[button_number].set_choice_enabled(choice_number,enabled_data);
};

bool  menu_class::get_button_choice_enabled(int button_number, int choice_number)
{
    return(menu_class::button[button_number].get_choice_enabled(choice_number));
};

int  menu_class::mouse_over_button_choice(int button_number)
{
    int   return_data = -1;
    float delta_x     =  0.0f;
        if(menu_class::button[button_number].get_number_of_visible_choices() < menu_class::button[button_number].get_number_of_choices())
        {
            if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_left_pos_x() ,menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_left_pos_y() ,menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 4000+button_number; //left_arrow
            if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_right_pos_x(),menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_right_pos_y(),menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 5000+button_number; //right_arrow
        }
    delta_x = ((menu_class::button[button_number].get_arrow_width()/4) *3)+menu_class::button[button_number].get_arrow_left_pos_x()+(menu_class::button[button_number].get_choice_zoom_size_counter(menu_class::button[button_number].get_choice_position())/2)+(menu_class::button[button_number].get_arrow_width()/2);
    for(int choice_count = 1; choice_count < menu_class::get_number_of_visible_choices(button_number)+1; choice_count++)
    {
        if (game.core.physics.point_in_quadrangle(delta_x,menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_left_pos_y(),menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = (button_number*100)+choice_count;
        delta_x += (menu_class::button[button_number].get_arrow_width()/2) *3;
    }
    return(return_data);
};

int  menu_class::mouse_click_button_choice(int button_number)
{
    int   return_data = -1;
    float delta_x     =  0.0f;
    if (game.core.io.mouse_button_left)
    {
        if(menu_class::button[button_number].get_number_of_visible_choices() < menu_class::button[button_number].get_number_of_choices())
        {
            if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_left_pos_x() ,menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_left_pos_y() ,menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 4000+button_number; //left_arrow
            if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_right_pos_x(),menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_right_pos_y(),menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 5000+button_number; //right_arrow
        }
        delta_x = ((menu_class::button[button_number].get_arrow_width()/4) *3)+menu_class::button[button_number].get_arrow_left_pos_x()+(menu_class::button[button_number].get_choice_zoom_size_counter(menu_class::button[button_number].get_choice_position())/2)+(menu_class::button[button_number].get_arrow_width()/2);
        for(int choice_count = 1; choice_count < menu_class::get_number_of_visible_choices(button_number)+1; choice_count++)
        {
            if (game.core.physics.point_in_quadrangle(delta_x,menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_left_pos_y(),menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = (button_number*100)+choice_count;
            delta_x += (menu_class::button[button_number].get_arrow_width()/2) *3;
        }
    }
    return(return_data);
};

void  menu_class::set_button_slider_data(int button_number, int position_data, std::string text_label_data, bool active_data, bool enabled_data)
{
    menu_class::button[button_number].set_slider_position(position_data);
    menu_class::button[button_number].set_active(true);
    menu_class::button[button_number].set_button_type(SLIDER);
};

void  menu_class::set_number_of_visible_choices(int button_number, int visible_choice_data)
{
    menu_class::button[button_number].set_number_of_visible_choices(visible_choice_data);
};

int   menu_class::get_number_of_visible_choices(int button_number)
{
    return(menu_class::button[button_number].get_number_of_visible_choices());
};

void  menu_class::set_button_slider_position_max(int button_number, float set_data)
{
    menu_class::button[button_number].set_slider_position_max(set_data);
};

float menu_class::get_button_slider_position_max(int button_number)
{
    return(menu_class::button[button_number].get_slider_position_max());
};

int  menu_class::mouse_over_button_slider(int button_number)
{
    int   return_data = -1;
    if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_left_pos_x() ,menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_left_pos_y() ,menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 4000+button_number; //left_arrow
    if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_right_pos_x(),menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_right_pos_y(),menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 5000+button_number; //right_arrow
    return(return_data);
};

int  menu_class::mouse_click_button_slider(int button_number)
{
    int   return_data = -1;
    if (game.core.io.mouse_button_left)
    {
        if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_left_pos_x() ,menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_left_pos_y() ,menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 4000+button_number; //left_arrow
        if (game.core.physics.point_in_quadrangle(menu_class::button[button_number].get_arrow_right_pos_x(),menu_class::button[button_number].get_arrow_width(),menu_class::button[button_number].get_arrow_right_pos_y(),menu_class::button[button_number].get_arrow_height(),game.core.io.mouse_x,game.core.io.mouse_y)) return_data = 5000+button_number; //right_arrow
    }
    return(return_data);
};

void  menu_class::set_button_current_choice(int button_number, int choice_data)
{
    menu_class::button[button_number].set_current_choice(choice_data);
};

int   menu_class::get_button_current_choice(int button_number)
{
    return(menu_class::button[button_number].get_current_choice());
};

void  menu_class::set_toggle_data(int button_number, bool bool_data)
{
    menu_class::button[button_number].set_toggle_data(bool_data);
};

bool  menu_class::get_toggle_data(int button_number)
{
    return(menu_class::button[button_number].get_toggle_data());
};

void  menu_class::set_achieve_data(int button_number, int int_data)
{
    menu_class::button[button_number].set_button_type(ACHIEVE);
    menu_class::button[button_number].set_achieve_data(int_data);
};

int   menu_class::get_achieve_data(int button_number)
{
    return(menu_class::button[button_number].get_achieve_data());
};

void  menu_class::set_achieve_button_images(int ah, int an)
{
    menu_class::button_image_achieve_highlighted = ah;
    menu_class::button_image_achieve_normal      = an;
};

void  menu_class::set_achieve_position(int button_number, int int_data)
{
    menu_class::button[button_number].set_button_type(ACHIEVE);
    menu_class::button[button_number].set_achieve_position(int_data);
};

bool  menu_class::get_button_enabled(int button_number)
{
    return(menu_class::button[button_number].get_enabled());
};

void menu_class::set_button_enabled(int button_number, bool bool_data)
{
    menu_class::button[button_number].set_enabled(bool_data);
};

float menu_class::get_button_x_pos(int button_number)
{
    return(menu_class::button[button_number].get_pos_x());
};

float menu_class::get_button_y_pos(int button_number)
{
    return(menu_class::button[button_number].get_pos_y());
};

int menu_class::process(void)
{
    float  drag_x_delta = 0.0f;
    float  drag_y_delta = 0.0f;
    int    return_value = -1;
    bool   done = false;
    // ---- io delay ----
    if (!game.UI.drag_in_progress)
    {
    menu_class::keyboard_delay_count++;
    if (menu_class::keyboard_delay_count > menu_class::keyboard_delay) menu_class::keyboard_delay_count = menu_class::keyboard_delay;
    menu_class::mouse_delay_count++;
    if (menu_class::mouse_delay_count > menu_class::mouse_delay) menu_class::mouse_delay_count = menu_class::mouse_delay;
    if ((!game.core.io.mouse_button_left) && (!game.core.io.mouse_button_middle) && (!game.core.io.mouse_button_right)) menu_class::mouse_delay_count = menu_class::mouse_delay;
    // ---- movement from io ----
    if  (menu_class::keyboard_delay_count >= menu_class::keyboard_delay)
    {
        if (game.core.io.up)
        {
            menu_class::keyboard_delay_count = 0;
            done = false;
            while ((!done) && (menu_class::current_vertical_selection != 1))
            {
                return_value = 65533;
                menu_class::current_vertical_selection--;
                if (menu_class::button[current_vertical_selection].get_active()) done = true;
                if (menu_class::current_vertical_selection == 1) done = true;
            }
        }
        if (game.core.io.down)
        {
            menu_class::keyboard_delay_count = 0;
            done = false;
            while ((!done) && (menu_class::current_vertical_selection != menu_class::number_of_buttons))
            {
                return_value = 65533;
                menu_class::current_vertical_selection++;
                if (menu_class::button[current_vertical_selection].get_active()) done = true;
                if (menu_class::current_vertical_selection == menu_class::number_of_buttons) done = true;
            }
        }
        if (game.core.io.key_escape)
        {
            menu_class::keyboard_delay_count = 0;
            return_value = 65534;
        }
        if (menu_class::current_vertical_selection < 1) menu_class::current_vertical_selection = 1;
        if (menu_class::current_vertical_selection > menu_class::number_of_buttons) menu_class::current_vertical_selection = menu_class::number_of_buttons;
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
        {
            if (menu_class::current_vertical_selection == button_count) menu_class::button[button_count].set_highlighted(true);
            else  menu_class::button[button_count].set_highlighted(false);
        }
    }
    //---- mouse ----
    if ((menu_class::mouse_over_any_button()) && (!menu_class::get_drag_active()))//normal / toggle button
    {
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
        {
            if ((menu_class::button[button_count].get_button_type() == NORMAL) || (menu_class::button[button_count].get_button_type() == TOGGLE))
            {
                if (menu_class::button[button_count].mouse_over())
                {
                    if ((menu_class::current_vertical_selection != button_count) && (menu_class::button[button_count].get_active())) return_value = 65533;
                    menu_class::current_vertical_selection = button_count;
                    if (!menu_class::button[button_count].get_highlighted())
                    {
                        menu_class::button[button_count].set_highlighted(true); //??????
                        return_value = 65533;
                    }
                }
                else  menu_class::button[button_count].set_highlighted(false);
            }
        }
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)//normal
        {
            if ((menu_class::button[button_count].get_button_type() == NORMAL) || (menu_class::button[button_count].get_button_type() == TOGGLE))
            {
                if (menu_class::button[button_count].mouse_clicked())
                {
                    if  (menu_class::mouse_delay_count >= menu_class::mouse_delay)
                    {
                        menu_class::mouse_delay_count = 0;
                        return_value = button_count;
                    }
                }
            }
        }
        if (game.core.io.select) return_value = current_vertical_selection;
    }
    if ((!menu_class::mouse_over_any_button()) && (menu_class::number_of_buttons == 1)) menu_class::button[1].set_highlighted(false);
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)//choice
    {
        if (menu_class::button[button_count].get_button_type() == CHOICE)//choice button
        {
            int menu_button_choice = menu_class::mouse_over_button_choice(button_count);
            if(menu_class::button[button_count].get_number_of_visible_choices() < menu_class::button[button_count].get_number_of_choices())
            {
                if ((menu_button_choice == 4000+button_count) && (!menu_class::button[button_count].get_arrow_left_highlighted())) return_value = 65533;
                if  (menu_button_choice == 4000+button_count)      menu_class::button[button_count].set_arrow_left_highlighted(true);//left arrow
                else menu_class::button[button_count].set_arrow_left_highlighted(false);
                if ((menu_button_choice == 5000+button_count) && (!menu_class::button[button_count].get_arrow_right_highlighted())) return_value = 65533;
                if  (menu_button_choice == 5000+button_count)      menu_class::button[button_count].set_arrow_right_highlighted(true);//right arrow
                else menu_class::button[button_count].set_arrow_right_highlighted(false);
            }
            for(int choice_count = 1; choice_count < menu_class::get_number_of_visible_choices(button_count)+1; choice_count++)
            {
                if ((menu_button_choice == (button_count*100)+choice_count) && (!menu_class::button[button_count].get_choice_highlighted(menu_class::get_button_choice_position(button_count)+choice_count-1))) return_value = 65533;
                if  (menu_button_choice == (button_count*100)+choice_count)      menu_class::button[button_count].set_choice_highlighted(menu_class::get_button_choice_position(button_count)+choice_count-1,true);//Choices
                else menu_class::button[button_count].set_choice_highlighted(menu_class::get_button_choice_position(button_count)+choice_count-1,false);
            }
            if  ((menu_class::mouse_delay_count >= menu_class::mouse_delay) && (game.core.io.mouse_button_left))
            {
                if (return_value == -1) return_value = menu_class::mouse_click_button_choice(button_count);
                if (return_value != -1) menu_class::mouse_delay_count = 0;
            }
        }
    }
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)//slider
    {
        if (menu_class::button[button_count].get_button_type() == SLIDER)//slider button
        {
            int menu_button_choice = menu_class::mouse_over_button_slider(button_count);
            if ((menu_button_choice == 4000+button_count) && (!menu_class::button[button_count].get_arrow_left_highlighted())) return_value = 65533;
            if  (menu_button_choice == 4000+button_count)      menu_class::button[button_count].set_arrow_left_highlighted(true);//left arrow
            else menu_class::button[button_count].set_arrow_left_highlighted(false);
            if ((menu_button_choice == 5000+button_count) && (!menu_class::button[button_count].get_arrow_right_highlighted())) return_value = 65533;
            if  (menu_button_choice == 5000+button_count)      menu_class::button[button_count].set_arrow_right_highlighted(true);//right arrow
            else menu_class::button[button_count].set_arrow_right_highlighted(false);
            if ((menu_class::button[button_count].get_arrow_right_highlighted()) || (menu_class::button[button_count].get_arrow_left_highlighted())) menu_class::button[button_count].set_highlighted(true);
            else menu_class::button[button_count].set_highlighted(false);
            if (return_value == -1) return_value = menu_class::mouse_click_button_slider(button_count);
        }
    }
    // ---- zoom ----
    if (menu_class::zoom)
    {
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
        {
            if (menu_class::button[button_count].get_highlighted())//normal button
            {
                menu_class::button[button_count].set_zoom_size_counter(menu_class::button[button_count].get_zoom_size_counter()+menu_class::button[button_count].get_zoom_speed());
                if (menu_class::button[button_count].get_zoom_size_counter() > menu_class::button[button_count].get_zoom_size()) menu_class::button[button_count].set_zoom_size_counter(menu_class::button[button_count].get_zoom_size());
            }
            else
            {
                menu_class::button[button_count].set_zoom_size_counter(menu_class::button[button_count].get_zoom_size_counter()-menu_class::button[button_count].get_zoom_speed());
                if (menu_class::button[button_count].get_zoom_size_counter() < 0.0f) menu_class::button[button_count].set_zoom_size_counter(0.0f);
            }
            if (menu_class::button[button_count].get_arrow_left_highlighted())//left arrow
            {
                menu_class::button[button_count].set_arrow_left_zoom_size_counter(menu_class::button[button_count].get_arrow_left_zoom_size_counter()+menu_class::button[button_count].get_zoom_speed());
                if (menu_class::button[button_count].get_arrow_left_zoom_size_counter() > menu_class::button[button_count].get_zoom_size()) menu_class::button[button_count].set_arrow_left_zoom_size_counter(menu_class::button[button_count].get_zoom_size());
            }
            else
            {
                menu_class::button[button_count].set_arrow_left_zoom_size_counter(menu_class::button[button_count].get_arrow_left_zoom_size_counter()-menu_class::button[button_count].get_zoom_speed());
                if (menu_class::button[button_count].get_arrow_left_zoom_size_counter() < 0.0f) menu_class::button[button_count].set_arrow_left_zoom_size_counter(0.0f);
            }
            if (menu_class::button[button_count].get_arrow_right_highlighted())//right arrow
            {
                menu_class::button[button_count].set_arrow_right_zoom_size_counter(menu_class::button[button_count].get_arrow_right_zoom_size_counter()+menu_class::button[button_count].get_zoom_speed());
                if (menu_class::button[button_count].get_arrow_right_zoom_size_counter() > menu_class::button[button_count].get_zoom_size()) menu_class::button[button_count].set_arrow_right_zoom_size_counter(menu_class::button[button_count].get_zoom_size());
            }
            else
            {
                menu_class::button[button_count].set_arrow_right_zoom_size_counter(menu_class::button[button_count].get_arrow_right_zoom_size_counter()-menu_class::button[button_count].get_zoom_speed());
                if (menu_class::button[button_count].get_arrow_right_zoom_size_counter() < 0.0f) menu_class::button[button_count].set_arrow_right_zoom_size_counter(0.0f);
            }
            for(int choice_count = 1; choice_count < menu_class::button[button_count].get_number_of_choices()+1; choice_count++)
            {
                if (menu_class::button[button_count].get_choice_highlighted(choice_count))//choices
                {
                    menu_class::button[button_count].set_choice_zoom_size_counter(choice_count,menu_class::button[button_count].get_choice_zoom_size_counter(choice_count)+menu_class::button[button_count].get_zoom_speed());
                    if (menu_class::button[button_count].get_choice_zoom_size_counter(choice_count) > menu_class::button[button_count].get_zoom_size()) menu_class::button[button_count].set_choice_zoom_size_counter(choice_count,menu_class::button[button_count].get_zoom_size());
                }
                else
                {
                    menu_class::button[button_count].set_choice_zoom_size_counter(choice_count,menu_class::button[button_count].get_choice_zoom_size_counter(choice_count)-menu_class::button[button_count].get_zoom_speed());
                    if (menu_class::button[button_count].get_choice_zoom_size_counter(choice_count) < 0.0f) menu_class::button[button_count].set_choice_zoom_size_counter(choice_count,0.0f);
                }
            }
        }
    }
    //---- close button ----
    if(!menu_class::get_drag_active())
    {
        if (menu_class::close_button.mouse_over() && !menu_class::close_button.get_highlighted()) return_value = 65533;
        if (menu_class::close_button.mouse_over()) menu_class::close_button.set_highlighted(true);
        else  menu_class::close_button.set_highlighted(false);
        if (menu_class::close_button.mouse_clicked()) return_value = 65535;
    }
    }
    //---- menu drag ----
    if ((menu_class::mouse_over_title()) && (return_value != 65535))
    {
        if (menu_class::mouse_click_title())
        {
            if ((!menu_class::get_drag_active()) && (!game.UI.drag_in_progress))
            {
                game.UI.active_window_list.add_to_list(MAIN_MENU_WINDOW);
                menu_class::drag_offset_x = game.core.io.mouse_x - menu_class::title_pos_x;
                menu_class::drag_offset_y = game.core.io.mouse_y - menu_class::title_pos_y;
                menu_class::set_drag_active(true);
                game.UI.drag_in_progress = true;
            }
        }
    }
    if ((menu_class::get_drag_active()) && (!game.core.io.mouse_button_left))
    {
        menu_class::set_drag_active(false);
        game.UI.drag_in_progress = false;
    }
    if (menu_class::get_drag_active())
    {
        drag_x_delta = menu_class::title_pos_x;
        drag_y_delta = menu_class::title_pos_y;
        menu_class::title_pos_x = game.core.io.mouse_x - menu_class::drag_offset_x;
        menu_class::title_pos_y = game.core.io.mouse_y - menu_class::drag_offset_y;
        drag_x_delta -= menu_class::title_pos_x;
        drag_y_delta -= menu_class::title_pos_y;
        menu_class::set_pos(menu_class::pos_x-drag_x_delta,menu_class::pos_y-drag_y_delta,menu_class::pos_z);
        menu_class::set_close_button_data(menu_class::get_close_button_pos_x()-drag_x_delta,menu_class::get_close_button_pos_y()-drag_y_delta,menu_class::get_close_button_pos_z());
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
        {
            menu_class::button[button_count].set_arrow_left_pos_x (menu_class::button[button_count].get_arrow_left_pos_x ()-drag_x_delta);
            menu_class::button[button_count].set_arrow_left_pos_y (menu_class::button[button_count].get_arrow_left_pos_y ()-drag_y_delta);
            menu_class::button[button_count].set_arrow_right_pos_x(menu_class::button[button_count].get_arrow_right_pos_x()-drag_x_delta);
            menu_class::button[button_count].set_arrow_right_pos_y(menu_class::button[button_count].get_arrow_right_pos_y()-drag_y_delta);
        }
        menu_class::set_button_spacing_auto();
    }

    //---- return ----
    return(return_value);
};

void  menu_class::set_text_size(float width, float height)
{
    menu_class::text_width  = width;
    menu_class::text_height = height;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_text_size(width,height);
    }
};
















