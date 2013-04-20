/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include <SDL/SDL_events.h>
#include "../game.hpp"
#include "io.hpp"

extern game_class          game;


bool events_init(void)
{
   SDL_Init(SDL_INIT_JOYSTICK);
   SDL_Joystick *joystick;
   SDL_JoystickEventState(SDL_ENABLE);
   joystick = SDL_JoystickOpen(0);
   if (SDL_JoystickOpened(0) == 1)
   {
      game.core.config.joystick_enabled        = true;
      game.core.io.joystick_sensitivity        = 6400;
      game.core.config.joystick_no_buttons     = SDL_JoystickNumButtons(joystick);
   }
   else
   {
      game.core.config.joystick_enabled    = false;
      game.core.io.joystick_sensitivity    = 0;
      game.core.config.joystick_no_buttons = 0;
   }
   game.core.io.mouse_button_ready         = false;
   game.core.io.keyboard_ready             = false;
   game.core.io.joystick_ready             = false;
   game.core.io.mouse_button_delay         = 32;
   game.core.io.mouse_button_delay_count   = 0;
   game.core.io.keyboard_delay             = 24;
   game.core.io.keyboard_delay_count       = 0;
   game.core.io.joystick_delay             = 24;
   game.core.io.joystick_delay_count       = 0;
   game.core.io.joystick_up                = false;
   game.core.io.joystick_down              = false;
   game.core.io.joystick_left              = false;
   game.core.io.joystick_right             = false;
   game.core.io.joystick_button_0          = false;
   game.core.io.joystick_button_1          = false;
   game.core.io.joystick_button_2          = false;
   game.core.io.joystick_button_3          = false;
   game.core.io.joystick_button_4          = false;
   game.core.io.joystick_button_5          = false;
   game.core.io.joystick_button_6          = false;
   game.core.io.joystick_button_7          = false;
   game.core.io.joystick_button_8          = false;
   game.core.io.joystick_button_9          = false;
   game.core.io.joystick_button_10         = false;
   game.core.io.joystick_button_11         = false;
   game.core.io.mouse_wheel_up             = false;
   game.core.io.mouse_wheel_down           = false;
   game.core.io.mouse_button_left          = false;
   game.core.io.mouse_button_middle        = false;
   game.core.io.mouse_button_right         = false;
   game.core.io.mouse_x                    = 0.0f;
   game.core.io.mouse_y                    = 0.0f;
   game.core.io.mouse_xrel                 = 0.0f;
   game.core.io.mouse_yrel                 = 0.0f;
   game.core.io.key_0                      = false;
   game.core.io.key_1                      = false;
   game.core.io.key_2                      = false;
   game.core.io.key_3                      = false;
   game.core.io.key_4                      = false;
   game.core.io.key_5                      = false;
   game.core.io.key_6                      = false;
   game.core.io.key_7                      = false;
   game.core.io.key_8                      = false;
   game.core.io.key_9                      = false;
   game.core.io.key_a                      = false;
   game.core.io.key_b                      = false;
   game.core.io.key_c                      = false;
   game.core.io.key_d                      = false;
   game.core.io.key_e                      = false;
   game.core.io.key_f                      = false;
   game.core.io.key_g                      = false;
   game.core.io.key_h                      = false;
   game.core.io.key_i                      = false;
   game.core.io.key_j                      = false;
   game.core.io.key_k                      = false;
   game.core.io.key_l                      = false;
   game.core.io.key_m                      = false;
   game.core.io.key_n                      = false;
   game.core.io.key_o                      = false;
   game.core.io.key_p                      = false;
   game.core.io.key_q                      = false;
   game.core.io.key_r                      = false;
   game.core.io.key_s                      = false;
   game.core.io.key_t                      = false;
   game.core.io.key_u                      = false;
   game.core.io.key_v                      = false;
   game.core.io.key_w                      = false;
   game.core.io.key_x                      = false;
   game.core.io.key_y                      = false;
   game.core.io.key_z                      = false;
   game.core.io.key_up                     = false;
   game.core.io.key_down                   = false;
   game.core.io.key_left                   = false;
   game.core.io.key_right                  = false;
   game.core.io.key_escape                 = false;
   game.core.io.key_plus                   = false;
   game.core.io.key_minus                  = false;
   game.core.io.key_space                  = false;
   game.core.io.key_enter                  = false;
   game.core.io.key_alt                    = false;
   game.core.io.select                     = false;
   game.core.io.pause                      = false;
   game.core.io.shoot                      = false;
   game.core.io.up                         = false;
   game.core.io.down                       = false;
   game.core.io.left                       = false;
   game.core.io.right                      = false;
   return(true);
};

bool events_process(void)
{
    //----------------------------------- Process events ------------------------------------------------
    game.core.io.mouse_button_delay_count++;
    if (game.core.io.mouse_button_delay_count > game.core.io.mouse_button_delay)
    {
        game.core.io.mouse_button_delay_count = game.core.io.mouse_button_delay;
        game.core.io.mouse_button_ready  = true;
    }
    else game.core.io.mouse_button_ready = false;
    game.core.io.keyboard_delay_count++;
    if (game.core.io.keyboard_delay_count > game.core.io.keyboard_delay)
    {
        game.core.io.keyboard_delay_count = game.core.io.keyboard_delay;
        game.core.io.keyboard_ready  = true;
    }
    else game.core.io.keyboard_ready = false;
    game.core.io.joystick_delay_count++;
    if (game.core.io.joystick_delay_count > game.core.io.joystick_delay)
    {
        game.core.io.joystick_delay_count = game.core.io.joystick_delay;
        game.core.io.joystick_ready  = true;
    }
    else game.core.io.joystick_ready = false;
    while (SDL_PollEvent(&game.core.event))
    {
        if (game.core.event.type == SDL_QUIT) game.state = STATE_QUIT;
    //-------------------- Mouse events-------------------------------
        //if (game.core.event.type == SDL_MOUSEWHEEL)
        //{
        //};
        if (game.core.event.type == SDL_MOUSEMOTION)
        {
            game.core.config.mouse_autohide_process(true);
            game.core.io.mouse_x      = game.core.graphics.res_to_gl(game.core.event.motion.x,game.core.config.mouse_resolution_x);
            game.core.io.mouse_y      = game.core.graphics.res_to_gl(game.core.event.motion.y,game.core.config.mouse_resolution_y);
            game.core.io.mouse_xrel   = game.core.graphics.res_to_gl(game.core.event.motion.xrel,game.core.config.mouse_resolution_x);
            game.core.io.mouse_yrel   = game.core.graphics.res_to_gl(game.core.event.motion.yrel,game.core.config.mouse_resolution_y);
            game.core.io.mouse_y *= -1;
        }
        if (game.core.event.type == SDL_MOUSEBUTTONUP)
        {
            switch(game.core.event.button.button)
            {
                case SDL_BUTTON_WHEELUP:
                    game.core.io.mouse_wheel_up = false;
                break;
                case SDL_BUTTON_WHEELDOWN:
                    game.core.io.mouse_wheel_down = false;
                break;
                case SDL_BUTTON_LEFT:
                    game.core.io.mouse_button_left = false;
                break;
                case SDL_BUTTON_MIDDLE:
                    game.core.io.mouse_button_middle = false;
                break;
                case SDL_BUTTON_RIGHT:
                    game.core.io.mouse_button_right = false;
                break;
                default:
                break;
            }
        }
        if (game.core.event.type == SDL_MOUSEBUTTONDOWN)
        {
            switch(game.core.event.button.button)
            {
                case SDL_BUTTON_WHEELUP:
                    game.core.io.mouse_wheel++;
                    if (game.core.io.mouse_wheel > 65535) game.core.io.mouse_wheel = 65535;
                    game.core.io.mouse_wheel_up = true;
                break;
                case SDL_BUTTON_WHEELDOWN:
                    game.core.io.mouse_wheel--;
                    if (game.core.io.mouse_wheel < -65535) game.core.io.mouse_wheel = -65535;
                    game.core.io.mouse_wheel_down = true;
                break;
                case SDL_BUTTON_LEFT:
                    if (game.core.io.mouse_button_delay_count >= game.core.io.mouse_button_delay)
                    {
                        game.core.io.mouse_button_delay_count = 0;
                        game.core.io.mouse_button_left = true;
                    }
                    else game.core.io.mouse_button_left = false;
                break;
                case SDL_BUTTON_MIDDLE:
                    if (game.core.io.mouse_button_delay_count >= game.core.io.mouse_button_delay)
                    {
                        game.core.io.mouse_button_delay_count = 0;
                        game.core.io.mouse_button_middle = true;
                    }
                    else game.core.io.mouse_button_middle = false;
                break;
                case SDL_BUTTON_RIGHT:
                    if (game.core.io.mouse_button_delay_count >= game.core.io.mouse_button_delay)
                    {
                        game.core.io.mouse_button_delay_count = 0;
                        game.core.io.mouse_button_right = true;
                    }
                    else game.core.io.mouse_button_right = false;
                break;
                default:
                break;
            }
        }
    //-------------------------- joystick / gamepad events --------------------------------------------
       if (game.core.event.type == SDL_JOYHATMOTION)
       {
          if (game.core.event.jhat.value & SDL_HAT_UP)
          {
              game.core.io.joystick_up    = true;
              game.core.io.joystick_down  = false;
              game.core.io.joystick_left  = false;
              game.core.io.joystick_right = false;
          }
          if (game.core.event.jhat.value & SDL_HAT_DOWN)
          {
              game.core.io.joystick_up    = false;
              game.core.io.joystick_down  = true;
              game.core.io.joystick_left  = false;
              game.core.io.joystick_right = false;
          }
          if (game.core.event.jhat.value & SDL_HAT_RIGHT)
          {
              game.core.io.joystick_up    = false;
              game.core.io.joystick_down  = false;
              game.core.io.joystick_left  = false;
              game.core.io.joystick_right = true;
          }
          if (game.core.event.jhat.value & SDL_HAT_RIGHTUP)
          {
              game.core.io.joystick_up    = true;
              game.core.io.joystick_down  = false;
              game.core.io.joystick_left  = false;
              game.core.io.joystick_right = true;
          }
          if (game.core.event.jhat.value & SDL_HAT_RIGHTDOWN)
          {
              game.core.io.joystick_up    = false;
              game.core.io.joystick_down  = true;
              game.core.io.joystick_left  = false;
              game.core.io.joystick_right = true;
          }
          if (game.core.event.jhat.value & SDL_HAT_LEFT)
          {
              game.core.io.joystick_up    = false;
              game.core.io.joystick_down  = false;
              game.core.io.joystick_left  = true;
              game.core.io.joystick_right = false;
          }
          if (game.core.event.jhat.value & SDL_HAT_LEFTUP)
          {
              game.core.io.joystick_up    = true;
              game.core.io.joystick_down  = false;
              game.core.io.joystick_left  = true;
              game.core.io.joystick_right = false;
          }
          if (game.core.event.jhat.value & SDL_HAT_LEFTDOWN)
          {
              game.core.io.joystick_up    = false;
              game.core.io.joystick_down  = true;
              game.core.io.joystick_left  = true;
              game.core.io.joystick_right = false;
          }
          if (game.core.event.jhat.value & SDL_HAT_CENTERED)
          {
              game.core.io.joystick_up    = false;
              game.core.io.joystick_down  = false;
              game.core.io.joystick_left  = false;
              game.core.io.joystick_right = false;
         }
       }
       //--------------------------------------------------------------------------
       if (game.core.event.type == SDL_JOYAXISMOTION)
       {
          if ((game.core.event.jaxis.value < (-1*(game.core.config.joystick_sensitivity))) || (game.core.event.jaxis.value > game.core.config.joystick_sensitivity))
          {
             if (game.core.event.jaxis.axis == 0)
             {
                if(game.core.event.jaxis.value < -(-1*(game.core.config.joystick_sensitivity)))
                {
                   game.core.io.joystick_left  = true;
                   game.core.io.joystick_right = false;
                }
                if(game.core.event.jaxis.value > game.core.config.joystick_sensitivity)
                {
                   game.core.io.joystick_left  = false;
                   game.core.io.joystick_right = true;
                }
             }
             if (game.core.event.jaxis.axis == 1)
             {
                if(game.core.event.jaxis.value < -(-1*(game.core.config.joystick_sensitivity)))
                {
                   game.core.io.joystick_up    = true;
                   game.core.io.joystick_down  = false;
                }
                if(game.core.event.jaxis.value > game.core.config.joystick_sensitivity)
                {
                   game.core.io.joystick_up    = false;
                   game.core.io.joystick_down  = true;
                }
             }
          }
          else
          {
               game.core.io.joystick_up    = false;
               game.core.io.joystick_down  = false;
               game.core.io.joystick_left  = false;
               game.core.io.joystick_right = false;
          }
       }
       //--------------------------------------------------------------------
       if (game.core.event.type == SDL_JOYBUTTONDOWN)
       {
           if (game.core.event.jbutton.button ==  0) game.core.io.joystick_button_0  = true;
           if (game.core.event.jbutton.button ==  1) game.core.io.joystick_button_1  = true;
           if (game.core.event.jbutton.button ==  2) game.core.io.joystick_button_2  = true;
           if (game.core.event.jbutton.button ==  3) game.core.io.joystick_button_3  = true;
           if (game.core.event.jbutton.button ==  4) game.core.io.joystick_button_4  = true;
           if (game.core.event.jbutton.button ==  5) game.core.io.joystick_button_5  = true;
           if (game.core.event.jbutton.button ==  6) game.core.io.joystick_button_6  = true;
           if (game.core.event.jbutton.button ==  7) game.core.io.joystick_button_7  = true;
           if (game.core.event.jbutton.button ==  8) game.core.io.joystick_button_8  = true;
           if (game.core.event.jbutton.button ==  9) game.core.io.joystick_button_9  = true;
           if (game.core.event.jbutton.button == 10) game.core.io.joystick_button_10 = true;
           if (game.core.event.jbutton.button == 11) game.core.io.joystick_button_11 = true;
       }
       if (game.core.event.type == SDL_JOYBUTTONUP)
       {
           if (game.core.event.jbutton.button ==  0) game.core.io.joystick_button_0  = false;
           if (game.core.event.jbutton.button ==  1) game.core.io.joystick_button_1  = false;
           if (game.core.event.jbutton.button ==  2) game.core.io.joystick_button_2  = false;
           if (game.core.event.jbutton.button ==  3) game.core.io.joystick_button_3  = false;
           if (game.core.event.jbutton.button ==  4) game.core.io.joystick_button_4  = false;
           if (game.core.event.jbutton.button ==  5) game.core.io.joystick_button_5  = false;
           if (game.core.event.jbutton.button ==  6) game.core.io.joystick_button_6  = false;
           if (game.core.event.jbutton.button ==  7) game.core.io.joystick_button_7  = false;
           if (game.core.event.jbutton.button ==  8) game.core.io.joystick_button_8  = false;
           if (game.core.event.jbutton.button ==  9) game.core.io.joystick_button_9  = false;
           if (game.core.event.jbutton.button == 10) game.core.io.joystick_button_10 = false;
           if (game.core.event.jbutton.button == 11) game.core.io.joystick_button_11 = false;
       }
       //------------------ keyboard events ------------------------------------------------------
       if (game.core.event.type == SDL_KEYDOWN)
       {
          if (game.core.event.key.keysym.sym == SDLK_ESCAPE) game.core.io.key_escape = true;
          if (game.core.event.key.keysym.sym == SDLK_UP)     game.core.io.key_up     = true;
          if (game.core.event.key.keysym.sym == SDLK_DOWN)   game.core.io.key_down   = true;
          if (game.core.event.key.keysym.sym == SDLK_LEFT)   game.core.io.key_left   = true;
          if (game.core.event.key.keysym.sym == SDLK_RIGHT)  game.core.io.key_right  = true;
          if (game.core.event.key.keysym.sym == SDLK_PLUS)   game.core.io.key_plus   = true;
          if (game.core.event.key.keysym.sym == SDLK_MINUS)  game.core.io.key_minus  = true;
          if (game.core.event.key.keysym.sym == SDLK_SPACE)  game.core.io.key_space  = true;
          if (game.core.event.key.keysym.sym == SDLK_RETURN) game.core.io.key_enter  = true;
          if (game.core.event.key.keysym.sym == SDLK_LALT)   game.core.io.key_lalt   = true;
          if (game.core.event.key.keysym.sym == SDLK_LCTRL)  game.core.io.key_lctrl  = true;
          if (game.core.event.key.keysym.sym == SDLK_LSHIFT) game.core.io.key_lshift = true;
          if (game.core.event.key.keysym.sym == SDLK_RALT)   game.core.io.key_ralt   = true;
          if (game.core.event.key.keysym.sym == SDLK_RCTRL)  game.core.io.key_rctrl  = true;
          if (game.core.event.key.keysym.sym == SDLK_RSHIFT) game.core.io.key_rshift = true;
          if (game.core.event.key.keysym.sym == SDLK_0)      game.core.io.key_0      = true;
          if (game.core.event.key.keysym.sym == SDLK_1)      game.core.io.key_1      = true;
          if (game.core.event.key.keysym.sym == SDLK_2)      game.core.io.key_2      = true;
          if (game.core.event.key.keysym.sym == SDLK_3)      game.core.io.key_3      = true;
          if (game.core.event.key.keysym.sym == SDLK_4)      game.core.io.key_4      = true;
          if (game.core.event.key.keysym.sym == SDLK_5)      game.core.io.key_5      = true;
          if (game.core.event.key.keysym.sym == SDLK_6)      game.core.io.key_6      = true;
          if (game.core.event.key.keysym.sym == SDLK_7)      game.core.io.key_7      = true;
          if (game.core.event.key.keysym.sym == SDLK_8)      game.core.io.key_8      = true;
          if (game.core.event.key.keysym.sym == SDLK_9)      game.core.io.key_9      = true;
          if (game.core.event.key.keysym.sym == SDLK_a)      game.core.io.key_a      = true;
          if (game.core.event.key.keysym.sym == SDLK_b)      game.core.io.key_b      = true;
          if (game.core.event.key.keysym.sym == SDLK_c)      game.core.io.key_c      = true;
          if (game.core.event.key.keysym.sym == SDLK_d)      game.core.io.key_d      = true;
          if (game.core.event.key.keysym.sym == SDLK_e)      game.core.io.key_e      = true;
          if (game.core.event.key.keysym.sym == SDLK_f)      game.core.io.key_f      = true;
          if (game.core.event.key.keysym.sym == SDLK_g)      game.core.io.key_g      = true;
          if (game.core.event.key.keysym.sym == SDLK_h)      game.core.io.key_h      = true;
          if (game.core.event.key.keysym.sym == SDLK_i)      game.core.io.key_i      = true;
          if (game.core.event.key.keysym.sym == SDLK_j)      game.core.io.key_j      = true;
          if (game.core.event.key.keysym.sym == SDLK_k)      game.core.io.key_k      = true;
          if (game.core.event.key.keysym.sym == SDLK_l)      game.core.io.key_l      = true;
          if (game.core.event.key.keysym.sym == SDLK_m)      game.core.io.key_m      = true;
          if (game.core.event.key.keysym.sym == SDLK_n)      game.core.io.key_n      = true;
          if (game.core.event.key.keysym.sym == SDLK_o)      game.core.io.key_o      = true;
          if (game.core.event.key.keysym.sym == SDLK_p)      game.core.io.key_p      = true;
          if (game.core.event.key.keysym.sym == SDLK_q)      game.core.io.key_q      = true;
          if (game.core.event.key.keysym.sym == SDLK_r)      game.core.io.key_r      = true;
          if (game.core.event.key.keysym.sym == SDLK_s)      game.core.io.key_s      = true;
          if (game.core.event.key.keysym.sym == SDLK_t)      game.core.io.key_t      = true;
          if (game.core.event.key.keysym.sym == SDLK_u)      game.core.io.key_u      = true;
          if (game.core.event.key.keysym.sym == SDLK_v)      game.core.io.key_v      = true;
          if (game.core.event.key.keysym.sym == SDLK_w)      game.core.io.key_w      = true;
          if (game.core.event.key.keysym.sym == SDLK_x)      game.core.io.key_x      = true;
          if (game.core.event.key.keysym.sym == SDLK_y)      game.core.io.key_y      = true;
          if (game.core.event.key.keysym.sym == SDLK_z)      game.core.io.key_z      = true;
       }
       if (game.core.event.type == SDL_KEYUP)
       {
          if (game.core.event.key.keysym.sym == SDLK_ESCAPE) game.core.io.key_escape = false;
          if (game.core.event.key.keysym.sym == SDLK_UP)     game.core.io.key_up     = false;
          if (game.core.event.key.keysym.sym == SDLK_DOWN)   game.core.io.key_down   = false;
          if (game.core.event.key.keysym.sym == SDLK_LEFT)   game.core.io.key_left   = false;
          if (game.core.event.key.keysym.sym == SDLK_RIGHT)  game.core.io.key_right  = false;
          if (game.core.event.key.keysym.sym == SDLK_PLUS)   game.core.io.key_plus   = false;
          if (game.core.event.key.keysym.sym == SDLK_MINUS)  game.core.io.key_minus  = false;
          if (game.core.event.key.keysym.sym == SDLK_SPACE)  game.core.io.key_space  = false;
          if (game.core.event.key.keysym.sym == SDLK_RETURN) game.core.io.key_enter  = false;
          if (game.core.event.key.keysym.sym == SDLK_LALT)   game.core.io.key_lalt   = false;
          if (game.core.event.key.keysym.sym == SDLK_LCTRL)  game.core.io.key_lctrl  = false;
          if (game.core.event.key.keysym.sym == SDLK_LSHIFT) game.core.io.key_lshift = false;
          if (game.core.event.key.keysym.sym == SDLK_RALT)   game.core.io.key_ralt   = false;
          if (game.core.event.key.keysym.sym == SDLK_RCTRL)  game.core.io.key_rctrl  = false;
          if (game.core.event.key.keysym.sym == SDLK_RSHIFT) game.core.io.key_rshift = false;
          if (game.core.event.key.keysym.sym == SDLK_0)      game.core.io.key_0      = false;
          if (game.core.event.key.keysym.sym == SDLK_1)      game.core.io.key_1      = false;
          if (game.core.event.key.keysym.sym == SDLK_2)      game.core.io.key_2      = false;
          if (game.core.event.key.keysym.sym == SDLK_3)      game.core.io.key_3      = false;
          if (game.core.event.key.keysym.sym == SDLK_4)      game.core.io.key_4      = false;
          if (game.core.event.key.keysym.sym == SDLK_5)      game.core.io.key_5      = false;
          if (game.core.event.key.keysym.sym == SDLK_6)      game.core.io.key_6      = false;
          if (game.core.event.key.keysym.sym == SDLK_7)      game.core.io.key_7      = false;
          if (game.core.event.key.keysym.sym == SDLK_8)      game.core.io.key_8      = false;
          if (game.core.event.key.keysym.sym == SDLK_9)      game.core.io.key_9      = false;
          if (game.core.event.key.keysym.sym == SDLK_a)      game.core.io.key_a      = false;
          if (game.core.event.key.keysym.sym == SDLK_b)      game.core.io.key_b      = false;
          if (game.core.event.key.keysym.sym == SDLK_c)      game.core.io.key_c      = false;
          if (game.core.event.key.keysym.sym == SDLK_d)      game.core.io.key_d      = false;
          if (game.core.event.key.keysym.sym == SDLK_e)      game.core.io.key_e      = false;
          if (game.core.event.key.keysym.sym == SDLK_f)      game.core.io.key_f      = false;
          if (game.core.event.key.keysym.sym == SDLK_g)      game.core.io.key_g      = false;
          if (game.core.event.key.keysym.sym == SDLK_h)      game.core.io.key_h      = false;
          if (game.core.event.key.keysym.sym == SDLK_i)      game.core.io.key_i      = false;
          if (game.core.event.key.keysym.sym == SDLK_j)      game.core.io.key_j      = false;
          if (game.core.event.key.keysym.sym == SDLK_k)      game.core.io.key_k      = false;
          if (game.core.event.key.keysym.sym == SDLK_l)      game.core.io.key_l      = false;
          if (game.core.event.key.keysym.sym == SDLK_m)      game.core.io.key_m      = false;
          if (game.core.event.key.keysym.sym == SDLK_n)      game.core.io.key_n      = false;
          if (game.core.event.key.keysym.sym == SDLK_o)      game.core.io.key_o      = false;
          if (game.core.event.key.keysym.sym == SDLK_p)      game.core.io.key_p      = false;
          if (game.core.event.key.keysym.sym == SDLK_q)      game.core.io.key_q      = false;
          if (game.core.event.key.keysym.sym == SDLK_r)      game.core.io.key_r      = false;
          if (game.core.event.key.keysym.sym == SDLK_s)      game.core.io.key_s      = false;
          if (game.core.event.key.keysym.sym == SDLK_t)      game.core.io.key_t      = false;
          if (game.core.event.key.keysym.sym == SDLK_u)      game.core.io.key_u      = false;
          if (game.core.event.key.keysym.sym == SDLK_v)      game.core.io.key_v      = false;
          if (game.core.event.key.keysym.sym == SDLK_w)      game.core.io.key_w      = false;
          if (game.core.event.key.keysym.sym == SDLK_x)      game.core.io.key_x      = false;
          if (game.core.event.key.keysym.sym == SDLK_y)      game.core.io.key_y      = false;
          if (game.core.event.key.keysym.sym == SDLK_z)      game.core.io.key_z      = false;
       }
    }
    //---------------------------------------------------------------------------------------------
    if ((game.core.io.joystick_button_0) || (game.core.io.key_enter))    game.core.io.select = true; else game.core.io.select = false;
    if ((game.core.io.joystick_button_1) || (game.core.io.key_space) || (game.core.io.mouse_button_left)) game.core.io.shoot   = true; else game.core.io.shoot  = false;
    if ((game.core.io.joystick_button_2) || (game.core.io.key_p))        game.core.io.pause   = true; else game.core.io.pause  = false;
    if ((game.core.io.joystick_button_3) || (game.core.io.key_escape))   game.core.io.key_escape = true; else game.core.io.key_escape = false;
    if ((game.core.io.joystick_up)    || (game.core.io.key_up   )) game.core.io.up     = true; else game.core.io.up     = false;
    if ((game.core.io.joystick_down)  || (game.core.io.key_down )) game.core.io.down   = true; else game.core.io.down   = false;
    if ((game.core.io.joystick_left)  || (game.core.io.key_left )) game.core.io.left   = true; else game.core.io.left   = false;
    if ((game.core.io.joystick_right) || (game.core.io.key_right)) game.core.io.right  = true; else game.core.io.right  = false;
    if ((game.core.io.key_lalt)   || (game.core.io.key_ralt))    game.core.io.key_alt   = true; else game.core.io.key_alt   = false;
    if ((game.core.io.key_lctrl)  || (game.core.io.key_rctrl))   game.core.io.key_ctrl  = true; else game.core.io.key_ctrl  = false;
    if ((game.core.io.key_lshift) || (game.core.io.key_rshift))  game.core.io.key_shift = true; else game.core.io.key_shift = false;
    return(true);
}

