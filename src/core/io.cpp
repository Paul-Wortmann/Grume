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

#include <SDL/SDL.h>
#include "core.hpp"
#include "../game.hpp"
#include "io.hpp"

extern game_type          game_o;
extern game_class         game;


bool events_init(void)
{
   SDL_Init(SDL_INIT_JOYSTICK);
   SDL_Joystick *joystick;
   SDL_JoystickEventState(SDL_ENABLE);
   joystick = SDL_JoystickOpen(0);
   if (SDL_JoystickOpened(0) == 1)
   {
      game.config.joystick_enabled        = true;
      game.io.joystick_sensitivity        = 6400;
      game.config.joystick_no_buttons     = SDL_JoystickNumButtons(joystick);
   }
   else
   {
      game.config.joystick_enabled    = false;
      game.io.joystick_sensitivity    = 0;
      game.config.joystick_no_buttons = 0;
   }
   game.io.mouse_button_delay         = 32;
   game.io.mouse_button_delay_count   = 0;
   game.io.keyboard_delay             = 24;
   game.io.keyboard_delay_count       = 0;
   game.io.joystick_delay             = 24;
   game.io.joystick_delay_count       = 0;
   game.io.joystick_up                = false;
   game.io.joystick_down              = false;
   game.io.joystick_left              = false;
   game.io.joystick_right             = false;
   game.io.joystick_button_0          = false;
   game.io.joystick_button_1          = false;
   game.io.joystick_button_2          = false;
   game.io.joystick_button_3          = false;
   game.io.joystick_button_4          = false;
   game.io.joystick_button_5          = false;
   game.io.joystick_button_6          = false;
   game.io.joystick_button_7          = false;
   game.io.joystick_button_8          = false;
   game.io.joystick_button_9          = false;
   game.io.joystick_button_10         = false;
   game.io.joystick_button_11         = false;
   game.io.mouse_button_left          = false;
   game.io.mouse_button_middle        = false;
   game.io.mouse_button_right         = false;
   game.io.mouse_x                    = 0.0f;
   game.io.mouse_y                    = 0.0f;
   game.io.mouse_xrel                 = 0.0f;
   game.io.mouse_yrel                 = 0.0f;
   game.io.key_0                      = false;
   game.io.key_1                      = false;
   game.io.key_2                      = false;
   game.io.key_3                      = false;
   game.io.key_4                      = false;
   game.io.key_5                      = false;
   game.io.key_6                      = false;
   game.io.key_7                      = false;
   game.io.key_8                      = false;
   game.io.key_9                      = false;
   game.io.key_a                      = false;
   game.io.key_b                      = false;
   game.io.key_c                      = false;
   game.io.key_d                      = false;
   game.io.key_e                      = false;
   game.io.key_f                      = false;
   game.io.key_g                      = false;
   game.io.key_h                      = false;
   game.io.key_i                      = false;
   game.io.key_j                      = false;
   game.io.key_k                      = false;
   game.io.key_l                      = false;
   game.io.key_m                      = false;
   game.io.key_n                      = false;
   game.io.key_o                      = false;
   game.io.key_p                      = false;
   game.io.key_q                      = false;
   game.io.key_r                      = false;
   game.io.key_s                      = false;
   game.io.key_t                      = false;
   game.io.key_u                      = false;
   game.io.key_v                      = false;
   game.io.key_w                      = false;
   game.io.key_x                      = false;
   game.io.key_y                      = false;
   game.io.key_z                      = false;
   game.io.key_up                     = false;
   game.io.key_down                   = false;
   game.io.key_left                   = false;
   game.io.key_right                  = false;
   game.io.select                     = false;
   game.io.escape                     = false;
   game.io.pause                      = false;
   game.io.plus                       = false;
   game.io.minus                      = false;
   game.io.space                      = false;
   game.io.enter                      = false;
   game.io.shoot                      = false;
   game.io.up                         = false;
   game.io.down                       = false;
   game.io.left                       = false;
   game.io.right                      = false;
   return(true);
};

bool events_process(void)
{
    //----------------------------------- Process events ------------------------------------------------
    game.io.mouse_button_delay_count++;
    if (game.io.mouse_button_delay_count > game.io.mouse_button_delay) game.io.mouse_button_delay_count = game.io.mouse_button_delay;
    game.io.keyboard_delay_count++;
    if (game.io.keyboard_delay_count > game.io.keyboard_delay) game.io.keyboard_delay_count = game.io.keyboard_delay;
    while (SDL_PollEvent(&game.event))
    {
    //-------------------- Mouse events-------------------------------
       if (game.event.type == SDL_MOUSEMOTION)
       {
           game.config.process(true);
           game.io.mouse_x      = game.graphics.res_to_gl(game.event.motion.x,game.config.mouse_resolution_x);
           game.io.mouse_y      = game.graphics.res_to_gl(game.event.motion.y,game.config.mouse_resolution_y);
           game.io.mouse_xrel   = game.graphics.res_to_gl(game.event.motion.xrel,game.config.mouse_resolution_x);
           game.io.mouse_yrel   = game.graphics.res_to_gl(game.event.motion.yrel,game.config.mouse_resolution_y);
           game.io.mouse_y *= -1;
       }
       if (game.event.type == SDL_MOUSEBUTTONUP)
       {
           switch(game.event.button.button)
           {
              case 1:
                game.io.mouse_button_left = false;
              break;
              case 2:
                game.io.mouse_button_middle = false;
              break;
              case 3:
                game.io.mouse_button_right = false;
              break;
              default:
              break;
           }
       }
       if (game.event.type == SDL_MOUSEBUTTONDOWN)
       {
           switch(game.event.button.button)
           {
              case 1:
                if (game.io.mouse_button_delay_count >= game.io.mouse_button_delay)
                {
                   game.io.mouse_button_delay_count = 0;
                   game.io.mouse_button_left = true;
                }
                else game.io.mouse_button_left = false;
              break;
              case 2:
                if (game.io.mouse_button_delay_count >= game.io.mouse_button_delay)
                {
                   game.io.mouse_button_delay_count = 0;
                   game.io.mouse_button_middle = true;
                }
                else game.io.mouse_button_middle = false;
              break;
              case 3:
                if (game.io.mouse_button_delay_count >= game.io.mouse_button_delay)
                {
                   game.io.mouse_button_delay_count = 0;
                   game.io.mouse_button_right = true;
                }
                else game.io.mouse_button_right = false;
              break;
              default:
              break;
           }
       }
    //-------------------------- joystick / gamepad events --------------------------------------------
       if (game.event.type == SDL_JOYHATMOTION)
       {
          if (game.event.jhat.value & SDL_HAT_UP)
          {
              game.io.joystick_up    = true;
              game.io.joystick_down  = false;
              game.io.joystick_left  = false;
              game.io.joystick_right = false;
          }
          if (game.event.jhat.value & SDL_HAT_DOWN)
          {
              game.io.joystick_up    = false;
              game.io.joystick_down  = true;
              game.io.joystick_left  = false;
              game.io.joystick_right = false;
          }
          if (game.event.jhat.value & SDL_HAT_RIGHT)
          {
              game.io.joystick_up    = false;
              game.io.joystick_down  = false;
              game.io.joystick_left  = false;
              game.io.joystick_right = true;
          }
          if (game.event.jhat.value & SDL_HAT_RIGHTUP)
          {
              game.io.joystick_up    = true;
              game.io.joystick_down  = false;
              game.io.joystick_left  = false;
              game.io.joystick_right = true;
          }
          if (game.event.jhat.value & SDL_HAT_RIGHTDOWN)
          {
              game.io.joystick_up    = false;
              game.io.joystick_down  = true;
              game.io.joystick_left  = false;
              game.io.joystick_right = true;
          }
          if (game.event.jhat.value & SDL_HAT_LEFT)
          {
              game.io.joystick_up    = false;
              game.io.joystick_down  = false;
              game.io.joystick_left  = true;
              game.io.joystick_right = false;
          }
          if (game.event.jhat.value & SDL_HAT_LEFTUP)
          {
              game.io.joystick_up    = true;
              game.io.joystick_down  = false;
              game.io.joystick_left  = true;
              game.io.joystick_right = false;
          }
          if (game.event.jhat.value & SDL_HAT_LEFTDOWN)
          {
              game.io.joystick_up    = false;
              game.io.joystick_down  = true;
              game.io.joystick_left  = true;
              game.io.joystick_right = false;
          }
          if (game.event.jhat.value & SDL_HAT_CENTERED)
          {
              game.io.joystick_up    = false;
              game.io.joystick_down  = false;
              game.io.joystick_left  = false;
              game.io.joystick_right = false;
         }
       }
       //--------------------------------------------------------------------------
       if (game.event.type == SDL_JOYAXISMOTION)
       {
          if ((game.event.jaxis.value < (-1*(game.config.joystick_sensitivity))) || (game.event.jaxis.value > game.config.joystick_sensitivity))
          {
             if (game.event.jaxis.axis == 0)
             {
                if(game.event.jaxis.value < -(-1*(game.config.joystick_sensitivity)))
                {
                   game.io.joystick_left  = true;
                   game.io.joystick_right = false;
                }
                if(game.event.jaxis.value > game.config.joystick_sensitivity)
                {
                   game.io.joystick_left  = false;
                   game.io.joystick_right = true;
                }
             }
             if (game.event.jaxis.axis == 1)
             {
                if(game.event.jaxis.value < -(-1*(game.config.joystick_sensitivity)))
                {
                   game.io.joystick_up    = true;
                   game.io.joystick_down  = false;
                }
                if(game.event.jaxis.value > game.config.joystick_sensitivity)
                {
                   game.io.joystick_up    = false;
                   game.io.joystick_down  = true;
                }
             }
          }
          else
          {
               game.io.joystick_up    = false;
               game.io.joystick_down  = false;
               game.io.joystick_left  = false;
               game.io.joystick_right = false;
          }
       }
       //--------------------------------------------------------------------
       if (game.event.type == SDL_JOYBUTTONDOWN)
       {
           if (game.event.jbutton.button ==  0) game.io.joystick_button_0  = true;
           if (game.event.jbutton.button ==  1) game.io.joystick_button_1  = true;
           if (game.event.jbutton.button ==  2) game.io.joystick_button_2  = true;
           if (game.event.jbutton.button ==  3) game.io.joystick_button_3  = true;
           if (game.event.jbutton.button ==  4) game.io.joystick_button_4  = true;
           if (game.event.jbutton.button ==  5) game.io.joystick_button_5  = true;
           if (game.event.jbutton.button ==  6) game.io.joystick_button_6  = true;
           if (game.event.jbutton.button ==  7) game.io.joystick_button_7  = true;
           if (game.event.jbutton.button ==  8) game.io.joystick_button_8  = true;
           if (game.event.jbutton.button ==  9) game.io.joystick_button_9  = true;
           if (game.event.jbutton.button == 10) game.io.joystick_button_10 = true;
           if (game.event.jbutton.button == 11) game.io.joystick_button_11 = true;
       }
       if (game.event.type == SDL_JOYBUTTONUP)
       {
           if (game.event.jbutton.button ==  0) game.io.joystick_button_0  = false;
           if (game.event.jbutton.button ==  1) game.io.joystick_button_1  = false;
           if (game.event.jbutton.button ==  2) game.io.joystick_button_2  = false;
           if (game.event.jbutton.button ==  3) game.io.joystick_button_3  = false;
           if (game.event.jbutton.button ==  4) game.io.joystick_button_4  = false;
           if (game.event.jbutton.button ==  5) game.io.joystick_button_5  = false;
           if (game.event.jbutton.button ==  6) game.io.joystick_button_6  = false;
           if (game.event.jbutton.button ==  7) game.io.joystick_button_7  = false;
           if (game.event.jbutton.button ==  8) game.io.joystick_button_8  = false;
           if (game.event.jbutton.button ==  9) game.io.joystick_button_9  = false;
           if (game.event.jbutton.button == 10) game.io.joystick_button_10 = false;
           if (game.event.jbutton.button == 11) game.io.joystick_button_11 = false;
       }
       //------------------ keybord events ------------------------------------------------------
       if (game.event.type == SDL_QUIT) game.status_quit_active = true;
       if (game.event.type == SDL_KEYDOWN)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE) game.io.escape     = true;
          if (game.event.key.keysym.sym == SDLK_UP)     game.io.key_up     = true;
          if (game.event.key.keysym.sym == SDLK_DOWN)   game.io.key_down   = true;
          if (game.event.key.keysym.sym == SDLK_LEFT)   game.io.key_left   = true;
          if (game.event.key.keysym.sym == SDLK_RIGHT)  game.io.key_right  = true;
          if (game.event.key.keysym.sym == SDLK_PLUS)   game.io.plus       = true;
          if (game.event.key.keysym.sym == SDLK_MINUS)  game.io.minus      = true;
          if (game.event.key.keysym.sym == SDLK_SPACE)  game.io.space      = true;
          if (game.event.key.keysym.sym == SDLK_RETURN) game.io.enter      = true;
          if (game.event.key.keysym.sym == SDLK_0)      game.io.key_0      = true;
          if (game.event.key.keysym.sym == SDLK_1)      game.io.key_1      = true;
          if (game.event.key.keysym.sym == SDLK_2)      game.io.key_2      = true;
          if (game.event.key.keysym.sym == SDLK_3)      game.io.key_3      = true;
          if (game.event.key.keysym.sym == SDLK_4)      game.io.key_4      = true;
          if (game.event.key.keysym.sym == SDLK_5)      game.io.key_5      = true;
          if (game.event.key.keysym.sym == SDLK_6)      game.io.key_6      = true;
          if (game.event.key.keysym.sym == SDLK_7)      game.io.key_7      = true;
          if (game.event.key.keysym.sym == SDLK_8)      game.io.key_8      = true;
          if (game.event.key.keysym.sym == SDLK_9)      game.io.key_9      = true;
          if (game.event.key.keysym.sym == SDLK_a)      game.io.key_a      = true;
          if (game.event.key.keysym.sym == SDLK_b)      game.io.key_b      = true;
          if (game.event.key.keysym.sym == SDLK_c)      game.io.key_c      = true;
          if (game.event.key.keysym.sym == SDLK_d)      game.io.key_d      = true;
          if (game.event.key.keysym.sym == SDLK_e)      game.io.key_e      = true;
          if (game.event.key.keysym.sym == SDLK_f)      game.io.key_f      = true;
          if (game.event.key.keysym.sym == SDLK_g)      game.io.key_g      = true;
          if (game.event.key.keysym.sym == SDLK_h)      game.io.key_h      = true;
          if (game.event.key.keysym.sym == SDLK_i)      game.io.key_i      = true;
          if (game.event.key.keysym.sym == SDLK_j)      game.io.key_j      = true;
          if (game.event.key.keysym.sym == SDLK_k)      game.io.key_k      = true;
          if (game.event.key.keysym.sym == SDLK_l)      game.io.key_l      = true;
          if (game.event.key.keysym.sym == SDLK_m)      game.io.key_m      = true;
          if (game.event.key.keysym.sym == SDLK_n)      game.io.key_n      = true;
          if (game.event.key.keysym.sym == SDLK_o)      game.io.key_o      = true;
          if (game.event.key.keysym.sym == SDLK_p)      game.io.key_p      = true;
          if (game.event.key.keysym.sym == SDLK_q)      game.io.key_q      = true;
          if (game.event.key.keysym.sym == SDLK_r)      game.io.key_r      = true;
          if (game.event.key.keysym.sym == SDLK_s)      game.io.key_s      = true;
          if (game.event.key.keysym.sym == SDLK_t)      game.io.key_t      = true;
          if (game.event.key.keysym.sym == SDLK_u)      game.io.key_u      = true;
          if (game.event.key.keysym.sym == SDLK_v)      game.io.key_v      = true;
          if (game.event.key.keysym.sym == SDLK_w)      game.io.key_w      = true;
          if (game.event.key.keysym.sym == SDLK_x)      game.io.key_x      = true;
          if (game.event.key.keysym.sym == SDLK_y)      game.io.key_y      = true;
          if (game.event.key.keysym.sym == SDLK_z)      game.io.key_z      = true;
       }
       if (game.event.type == SDL_KEYUP)
       {
          if (game.event.key.keysym.sym == SDLK_ESCAPE) game.io.escape     = false;
          if (game.event.key.keysym.sym == SDLK_UP)     game.io.key_up     = false;
          if (game.event.key.keysym.sym == SDLK_DOWN)   game.io.key_down   = false;
          if (game.event.key.keysym.sym == SDLK_LEFT)   game.io.key_left   = false;
          if (game.event.key.keysym.sym == SDLK_RIGHT)  game.io.key_right  = false;
          if (game.event.key.keysym.sym == SDLK_PLUS)   game.io.plus       = false;
          if (game.event.key.keysym.sym == SDLK_MINUS)  game.io.minus      = false;
          if (game.event.key.keysym.sym == SDLK_SPACE)  game.io.space      = false;
          if (game.event.key.keysym.sym == SDLK_RETURN) game.io.enter      = false;
          if (game.event.key.keysym.sym == SDLK_0)      game.io.key_0      = false;
          if (game.event.key.keysym.sym == SDLK_1)      game.io.key_1      = false;
          if (game.event.key.keysym.sym == SDLK_2)      game.io.key_2      = false;
          if (game.event.key.keysym.sym == SDLK_3)      game.io.key_3      = false;
          if (game.event.key.keysym.sym == SDLK_4)      game.io.key_4      = false;
          if (game.event.key.keysym.sym == SDLK_5)      game.io.key_5      = false;
          if (game.event.key.keysym.sym == SDLK_6)      game.io.key_6      = false;
          if (game.event.key.keysym.sym == SDLK_7)      game.io.key_7      = false;
          if (game.event.key.keysym.sym == SDLK_8)      game.io.key_8      = false;
          if (game.event.key.keysym.sym == SDLK_9)      game.io.key_9      = false;
          if (game.event.key.keysym.sym == SDLK_a)      game.io.key_a      = false;
          if (game.event.key.keysym.sym == SDLK_b)      game.io.key_b      = false;
          if (game.event.key.keysym.sym == SDLK_c)      game.io.key_c      = false;
          if (game.event.key.keysym.sym == SDLK_d)      game.io.key_d      = false;
          if (game.event.key.keysym.sym == SDLK_e)      game.io.key_e      = false;
          if (game.event.key.keysym.sym == SDLK_f)      game.io.key_f      = false;
          if (game.event.key.keysym.sym == SDLK_g)      game.io.key_g      = false;
          if (game.event.key.keysym.sym == SDLK_h)      game.io.key_h      = false;
          if (game.event.key.keysym.sym == SDLK_i)      game.io.key_i      = false;
          if (game.event.key.keysym.sym == SDLK_j)      game.io.key_j      = false;
          if (game.event.key.keysym.sym == SDLK_k)      game.io.key_k      = false;
          if (game.event.key.keysym.sym == SDLK_l)      game.io.key_l      = false;
          if (game.event.key.keysym.sym == SDLK_m)      game.io.key_m      = false;
          if (game.event.key.keysym.sym == SDLK_n)      game.io.key_n      = false;
          if (game.event.key.keysym.sym == SDLK_o)      game.io.key_o      = false;
          if (game.event.key.keysym.sym == SDLK_p)      game.io.key_p      = false;
          if (game.event.key.keysym.sym == SDLK_q)      game.io.key_q      = false;
          if (game.event.key.keysym.sym == SDLK_r)      game.io.key_r      = false;
          if (game.event.key.keysym.sym == SDLK_s)      game.io.key_s      = false;
          if (game.event.key.keysym.sym == SDLK_t)      game.io.key_t      = false;
          if (game.event.key.keysym.sym == SDLK_u)      game.io.key_u      = false;
          if (game.event.key.keysym.sym == SDLK_v)      game.io.key_v      = false;
          if (game.event.key.keysym.sym == SDLK_w)      game.io.key_w      = false;
          if (game.event.key.keysym.sym == SDLK_x)      game.io.key_x      = false;
          if (game.event.key.keysym.sym == SDLK_y)      game.io.key_y      = false;
          if (game.event.key.keysym.sym == SDLK_z)      game.io.key_z      = false;
       }
    }
    //---------------------------------------------------------------------------------------------
    if ((game.io.joystick_button_0) || (game.io.enter)) game.io.select = true; else game.io.select = false;
    if ((game.io.joystick_button_1) || (game.io.space) || (game.io.mouse_button_left)) game.io.shoot   = true; else game.io.shoot  = false;
    if ((game.io.joystick_button_2) || (game.io.key_p)) game.io.pause   = true; else game.io.pause  = false;
    if ((game.io.joystick_button_3) || (game.io.escape)) game.io.escape = true; else game.io.escape = false;
    if ((game.io.joystick_up)    || (game.io.key_up   )) game.io.up     = true; else game.io.up     = false;
    if ((game.io.joystick_down)  || (game.io.key_down )) game.io.down   = true; else game.io.down   = false;
    if ((game.io.joystick_left)  || (game.io.key_left )) game.io.left   = true; else game.io.left   = false;
    if ((game.io.joystick_right) || (game.io.key_right)) game.io.right  = true; else game.io.right  = false;
    return(true);
}





