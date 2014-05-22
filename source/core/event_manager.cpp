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

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "../game/game.hpp"
#include "graphics_engine.hpp"
#include "event_manager.hpp"

extern game_class          game;


bool events_init(void)
{
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_Joystick *joystick;
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    if ((SDL_NumJoysticks() > 0) && (joystick))
    {
        game.core.config.joystick_enabled        = true;
        game.core.event_manager.joystick_sensitivity        = 6400;
        game.core.config.joystick_no_buttons     = SDL_JoystickNumButtons(joystick);
    }
    else
    {
        game.core.config.joystick_enabled    = false;
        game.core.event_manager.joystick_sensitivity    = 0;
        game.core.config.joystick_no_buttons = 0;
    }
    game.core.event_manager.mouse_in_window            = true;
    game.core.event_manager.mouse_button_ready         = false;
    game.core.event_manager.keyboard_ready             = false;
    game.core.event_manager.joystick_ready             = false;
    game.core.event_manager.mouse_button_delay         = 32;
    game.core.event_manager.mouse_button_delay_count   = 0;
    game.core.event_manager.keyboard_delay             = 24;
    game.core.event_manager.keyboard_delay_count       = 0;
    game.core.event_manager.joystick_delay             = 24;
    game.core.event_manager.joystick_delay_count       = 0;
    game.core.event_manager.joystick_up                = false;
    game.core.event_manager.joystick_down              = false;
    game.core.event_manager.joystick_left              = false;
    game.core.event_manager.joystick_right             = false;
    game.core.event_manager.joystick_button_0          = false;
    game.core.event_manager.joystick_button_1          = false;
    game.core.event_manager.joystick_button_2          = false;
    game.core.event_manager.joystick_button_3          = false;
    game.core.event_manager.joystick_button_4          = false;
    game.core.event_manager.joystick_button_5          = false;
    game.core.event_manager.joystick_button_6          = false;
    game.core.event_manager.joystick_button_7          = false;
    game.core.event_manager.joystick_button_8          = false;
    game.core.event_manager.joystick_button_9          = false;
    game.core.event_manager.joystick_button_10         = false;
    game.core.event_manager.joystick_button_11         = false;
    game.core.event_manager.mouse_wheel_x              = 0;
    game.core.event_manager.mouse_wheel_y              = 0;
    game.core.event_manager.mouse_wheel_up             = false;
    game.core.event_manager.mouse_wheel_down           = false;
    game.core.event_manager.mouse_button_left          = false;
    game.core.event_manager.mouse_button_middle        = false;
    game.core.event_manager.mouse_button_right         = false;
    game.core.event_manager.mouse_x                    = 0.0f;
    game.core.event_manager.mouse_y                    = 0.0f;
    game.core.event_manager.mouse_xrel                 = 0.0f;
    game.core.event_manager.mouse_yrel                 = 0.0f;
    game.core.event_manager.key_0                      = false;
    game.core.event_manager.key_1                      = false;
    game.core.event_manager.key_2                      = false;
    game.core.event_manager.key_3                      = false;
    game.core.event_manager.key_4                      = false;
    game.core.event_manager.key_5                      = false;
    game.core.event_manager.key_6                      = false;
    game.core.event_manager.key_7                      = false;
    game.core.event_manager.key_8                      = false;
    game.core.event_manager.key_9                      = false;
    game.core.event_manager.key_a                      = false;
    game.core.event_manager.key_b                      = false;
    game.core.event_manager.key_c                      = false;
    game.core.event_manager.key_d                      = false;
    game.core.event_manager.key_e                      = false;
    game.core.event_manager.key_f                      = false;
    game.core.event_manager.key_g                      = false;
    game.core.event_manager.key_h                      = false;
    game.core.event_manager.key_i                      = false;
    game.core.event_manager.key_j                      = false;
    game.core.event_manager.key_k                      = false;
    game.core.event_manager.key_l                      = false;
    game.core.event_manager.key_m                      = false;
    game.core.event_manager.key_n                      = false;
    game.core.event_manager.key_o                      = false;
    game.core.event_manager.key_p                      = false;
    game.core.event_manager.key_q                      = false;
    game.core.event_manager.key_r                      = false;
    game.core.event_manager.key_s                      = false;
    game.core.event_manager.key_t                      = false;
    game.core.event_manager.key_u                      = false;
    game.core.event_manager.key_v                      = false;
    game.core.event_manager.key_w                      = false;
    game.core.event_manager.key_x                      = false;
    game.core.event_manager.key_y                      = false;
    game.core.event_manager.key_z                      = false;
    game.core.event_manager.key_up                     = false;
    game.core.event_manager.key_down                   = false;
    game.core.event_manager.key_left                   = false;
    game.core.event_manager.key_right                  = false;
    game.core.event_manager.key_escape                 = false;
    game.core.event_manager.key_plus                   = false;
    game.core.event_manager.key_minus                  = false;
    game.core.event_manager.key_space                  = false;
    game.core.event_manager.key_enter                  = false;
    game.core.event_manager.key_alt                    = false;
    game.core.event_manager.select                     = false;
    game.core.event_manager.pause                      = false;
    game.core.event_manager.shoot                      = false;
    game.core.event_manager.up                         = false;
    game.core.event_manager.down                       = false;
    game.core.event_manager.left                       = false;
    game.core.event_manager.right                      = false;
    game.core.event_manager.key_f1                     = false;
    game.core.event_manager.key_f2                     = false;
    game.core.event_manager.key_f3                     = false;
    game.core.event_manager.key_f4                     = false;
    game.core.event_manager.key_f5                     = false;
    game.core.event_manager.key_f6                     = false;
    game.core.event_manager.key_f7                     = false;
    game.core.event_manager.key_f8                     = false;
    game.core.event_manager.key_f9                     = false;
    game.core.event_manager.key_f10                    = false;
    game.core.event_manager.key_f11                    = false;
    game.core.event_manager.key_f12                    = false;
    return(true);
};

bool events_process(void)
{
    //----------------------------------- Process events ------------------------------------------------
    game.core.event_manager.mouse_button_delay_count++;
    if (game.core.event_manager.mouse_button_delay_count > game.core.event_manager.mouse_button_delay)
    {
        game.core.event_manager.mouse_button_delay_count = game.core.event_manager.mouse_button_delay;
        game.core.event_manager.mouse_button_ready  = true;
    }
    else game.core.event_manager.mouse_button_ready = false;
    game.core.event_manager.keyboard_delay_count++;
    if (game.core.event_manager.keyboard_delay_count > game.core.event_manager.keyboard_delay)
    {
        game.core.event_manager.keyboard_delay_count = game.core.event_manager.keyboard_delay;
        game.core.event_manager.keyboard_ready  = true;
    }
    else game.core.event_manager.keyboard_ready = false;
    game.core.event_manager.joystick_delay_count++;
    if (game.core.event_manager.joystick_delay_count > game.core.event_manager.joystick_delay)
    {
        game.core.event_manager.joystick_delay_count = game.core.event_manager.joystick_delay;
        game.core.event_manager.joystick_ready  = true;
    }
    else game.core.event_manager.joystick_ready = false;
    while (SDL_PollEvent(&game.core.event))
    {
        switch (game.core.event.type)
        {
            case SDL_QUIT:
                game.core.log.write("Event -> User terminating application.");
                game.state = STATE_QUIT;
            break;
            case SDL_WINDOWEVENT:
                switch (game.core.event.window.event)
                {
                    case SDL_WINDOWEVENT_ENTER:
                        game.core.event_manager.mouse_in_window = true;
                    break;
                    case SDL_WINDOWEVENT_LEAVE:
                        game.core.event_manager.mouse_in_window = false;
                    break;
                }
            break;
            //-------------------- Mouse events-------------------------------
            case SDL_MOUSEMOTION:
                game.core.config.mouse_autohide_process(true);
                game.core.event_manager.mouse_x      = res_to_gl(game.core.event.motion.x,game.core.config.mouse_resolution_x);
                game.core.event_manager.mouse_y      = res_to_gl(game.core.event.motion.y,game.core.config.mouse_resolution_y);
                game.core.event_manager.mouse_xrel   = res_to_gl(game.core.event.motion.xrel,game.core.config.mouse_resolution_x);
                game.core.event_manager.mouse_yrel   = res_to_gl(game.core.event.motion.yrel,game.core.config.mouse_resolution_y);
                game.core.event_manager.mouse_y *= -1;
            break;
            case SDL_MOUSEWHEEL:
                game.core.event_manager.mouse_wheel_x = game.core.event.wheel.x;
                game.core.event_manager.mouse_wheel_y = game.core.event.wheel.y;
                game.core.event_manager.mouse_wheel += game.core.event_manager.mouse_wheel_y;
                if (game.core.event_manager.mouse_wheel_y > 0)
                {
                    if (game.core.event_manager.mouse_wheel > 65535) game.core.event_manager.mouse_wheel = 65535;
                    game.core.event_manager.mouse_wheel_up = true;
                }
                else game.core.event_manager.mouse_wheel_up = false;
                if (game.core.event_manager.mouse_wheel_y < 0)
                {
                    if (game.core.event_manager.mouse_wheel < -65535) game.core.event_manager.mouse_wheel = -65535;
                    game.core.event_manager.mouse_wheel_down = true;
                }
                else game.core.event_manager.mouse_wheel_down = false;
            break;
            case SDL_MOUSEBUTTONUP:
                switch(game.core.event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        game.core.event_manager.mouse_button_left = false;
                    break;
                    case SDL_BUTTON_MIDDLE:
                        game.core.event_manager.mouse_button_middle = false;
                    break;
                    case SDL_BUTTON_RIGHT:
                        game.core.event_manager.mouse_button_right = false;
                    break;
                    default:
                    break;
                }
            break;
            case SDL_MOUSEBUTTONDOWN:
                switch(game.core.event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if (game.core.event_manager.mouse_button_delay_count >= game.core.event_manager.mouse_button_delay)
                        {
                            game.core.event_manager.mouse_button_delay_count = 0;
                            game.core.event_manager.mouse_button_left = true;
                        }
                        else game.core.event_manager.mouse_button_left = false;
                    break;
                    case SDL_BUTTON_MIDDLE:
                        if (game.core.event_manager.mouse_button_delay_count >= game.core.event_manager.mouse_button_delay)
                        {
                            game.core.event_manager.mouse_button_delay_count = 0;
                            game.core.event_manager.mouse_button_middle = true;
                        }
                        else game.core.event_manager.mouse_button_middle = false;
                    break;
                    case SDL_BUTTON_RIGHT:
                        if (game.core.event_manager.mouse_button_delay_count >= game.core.event_manager.mouse_button_delay)
                        {
                            game.core.event_manager.mouse_button_delay_count = 0;
                            game.core.event_manager.mouse_button_right = true;
                        }
                        else game.core.event_manager.mouse_button_right = false;
                    break;
                    default:
                    break;
                }
            break;
            //-------------------------- joystick / game pad events --------------------------------------------
            case SDL_JOYHATMOTION:
                if (game.core.event.jhat.value & SDL_HAT_UP)
                {
                  game.core.event_manager.joystick_up    = true;
                  game.core.event_manager.joystick_down  = false;
                  game.core.event_manager.joystick_left  = false;
                  game.core.event_manager.joystick_right = false;
                }
                if (game.core.event.jhat.value & SDL_HAT_DOWN)
                {
                  game.core.event_manager.joystick_up    = false;
                  game.core.event_manager.joystick_down  = true;
                  game.core.event_manager.joystick_left  = false;
                  game.core.event_manager.joystick_right = false;
                }
                if (game.core.event.jhat.value & SDL_HAT_RIGHT)
                {
                  game.core.event_manager.joystick_up    = false;
                  game.core.event_manager.joystick_down  = false;
                  game.core.event_manager.joystick_left  = false;
                  game.core.event_manager.joystick_right = true;
                }
                if (game.core.event.jhat.value & SDL_HAT_RIGHTUP)
                {
                  game.core.event_manager.joystick_up    = true;
                  game.core.event_manager.joystick_down  = false;
                  game.core.event_manager.joystick_left  = false;
                  game.core.event_manager.joystick_right = true;
                }
                if (game.core.event.jhat.value & SDL_HAT_RIGHTDOWN)
                {
                  game.core.event_manager.joystick_up    = false;
                  game.core.event_manager.joystick_down  = true;
                  game.core.event_manager.joystick_left  = false;
                  game.core.event_manager.joystick_right = true;
                }
                if (game.core.event.jhat.value & SDL_HAT_LEFT)
                {
                  game.core.event_manager.joystick_up    = false;
                  game.core.event_manager.joystick_down  = false;
                  game.core.event_manager.joystick_left  = true;
                  game.core.event_manager.joystick_right = false;
                }
                if (game.core.event.jhat.value & SDL_HAT_LEFTUP)
                {
                  game.core.event_manager.joystick_up    = true;
                  game.core.event_manager.joystick_down  = false;
                  game.core.event_manager.joystick_left  = true;
                  game.core.event_manager.joystick_right = false;
                }
                if (game.core.event.jhat.value & SDL_HAT_LEFTDOWN)
                {
                  game.core.event_manager.joystick_up    = false;
                  game.core.event_manager.joystick_down  = true;
                  game.core.event_manager.joystick_left  = true;
                  game.core.event_manager.joystick_right = false;
                }
                if (game.core.event.jhat.value & SDL_HAT_CENTERED)
                {
                  game.core.event_manager.joystick_up    = false;
                  game.core.event_manager.joystick_down  = false;
                  game.core.event_manager.joystick_left  = false;
                  game.core.event_manager.joystick_right = false;
                }
            break;
            case SDL_JOYAXISMOTION:
                if ((game.core.event.jaxis.value < (-1*(game.core.config.joystick_sensitivity))) || (game.core.event.jaxis.value > game.core.config.joystick_sensitivity))
                {
                 if (game.core.event.jaxis.axis == 0)
                 {
                    if(game.core.event.jaxis.value < -(-1*(game.core.config.joystick_sensitivity)))
                    {
                       game.core.event_manager.joystick_left  = true;
                       game.core.event_manager.joystick_right = false;
                    }
                    if(game.core.event.jaxis.value > game.core.config.joystick_sensitivity)
                    {
                       game.core.event_manager.joystick_left  = false;
                       game.core.event_manager.joystick_right = true;
                    }
                 }
                 if (game.core.event.jaxis.axis == 1)
                 {
                    if(game.core.event.jaxis.value < -(-1*(game.core.config.joystick_sensitivity)))
                    {
                       game.core.event_manager.joystick_up    = true;
                       game.core.event_manager.joystick_down  = false;
                    }
                    if(game.core.event.jaxis.value > game.core.config.joystick_sensitivity)
                    {
                       game.core.event_manager.joystick_up    = false;
                       game.core.event_manager.joystick_down  = true;
                    }
                 }
                }
                else
                {
                   game.core.event_manager.joystick_up    = false;
                   game.core.event_manager.joystick_down  = false;
                   game.core.event_manager.joystick_left  = false;
                   game.core.event_manager.joystick_right = false;
                }
            break;
            case SDL_JOYBUTTONDOWN:
                if (game.core.event.jbutton.button ==  0) game.core.event_manager.joystick_button_0  = true;
                if (game.core.event.jbutton.button ==  1) game.core.event_manager.joystick_button_1  = true;
                if (game.core.event.jbutton.button ==  2) game.core.event_manager.joystick_button_2  = true;
                if (game.core.event.jbutton.button ==  3) game.core.event_manager.joystick_button_3  = true;
                if (game.core.event.jbutton.button ==  4) game.core.event_manager.joystick_button_4  = true;
                if (game.core.event.jbutton.button ==  5) game.core.event_manager.joystick_button_5  = true;
                if (game.core.event.jbutton.button ==  6) game.core.event_manager.joystick_button_6  = true;
                if (game.core.event.jbutton.button ==  7) game.core.event_manager.joystick_button_7  = true;
                if (game.core.event.jbutton.button ==  8) game.core.event_manager.joystick_button_8  = true;
                if (game.core.event.jbutton.button ==  9) game.core.event_manager.joystick_button_9  = true;
                if (game.core.event.jbutton.button == 10) game.core.event_manager.joystick_button_10 = true;
                if (game.core.event.jbutton.button == 11) game.core.event_manager.joystick_button_11 = true;
            break;
            case SDL_JOYBUTTONUP:
                if (game.core.event.jbutton.button ==  0) game.core.event_manager.joystick_button_0  = false;
                if (game.core.event.jbutton.button ==  1) game.core.event_manager.joystick_button_1  = false;
                if (game.core.event.jbutton.button ==  2) game.core.event_manager.joystick_button_2  = false;
                if (game.core.event.jbutton.button ==  3) game.core.event_manager.joystick_button_3  = false;
                if (game.core.event.jbutton.button ==  4) game.core.event_manager.joystick_button_4  = false;
                if (game.core.event.jbutton.button ==  5) game.core.event_manager.joystick_button_5  = false;
                if (game.core.event.jbutton.button ==  6) game.core.event_manager.joystick_button_6  = false;
                if (game.core.event.jbutton.button ==  7) game.core.event_manager.joystick_button_7  = false;
                if (game.core.event.jbutton.button ==  8) game.core.event_manager.joystick_button_8  = false;
                if (game.core.event.jbutton.button ==  9) game.core.event_manager.joystick_button_9  = false;
                if (game.core.event.jbutton.button == 10) game.core.event_manager.joystick_button_10 = false;
                if (game.core.event.jbutton.button == 11) game.core.event_manager.joystick_button_11 = false;
            break;
            //------------------ keyboard events ------------------------------------------------------
            case SDL_KEYDOWN:
                if (game.core.event.key.keysym.sym == SDLK_ESCAPE) game.core.event_manager.key_escape = true;
                if (game.core.event.key.keysym.sym == SDLK_UP)     game.core.event_manager.key_up     = true;
                if (game.core.event.key.keysym.sym == SDLK_DOWN)   game.core.event_manager.key_down   = true;
                if (game.core.event.key.keysym.sym == SDLK_LEFT)   game.core.event_manager.key_left   = true;
                if (game.core.event.key.keysym.sym == SDLK_RIGHT)  game.core.event_manager.key_right  = true;
                if (game.core.event.key.keysym.sym == SDLK_PLUS)   game.core.event_manager.key_plus   = true;
                if (game.core.event.key.keysym.sym == SDLK_MINUS)  game.core.event_manager.key_minus  = true;
                if (game.core.event.key.keysym.sym == SDLK_SPACE)  game.core.event_manager.key_space  = true;
                if (game.core.event.key.keysym.sym == SDLK_RETURN) game.core.event_manager.key_enter  = true;
                if (game.core.event.key.keysym.sym == SDLK_LALT)   game.core.event_manager.key_lalt   = true;
                if (game.core.event.key.keysym.sym == SDLK_LCTRL)  game.core.event_manager.key_lctrl  = true;
                if (game.core.event.key.keysym.sym == SDLK_LSHIFT) game.core.event_manager.key_lshift = true;
                if (game.core.event.key.keysym.sym == SDLK_RALT)   game.core.event_manager.key_ralt   = true;
                if (game.core.event.key.keysym.sym == SDLK_RCTRL)  game.core.event_manager.key_rctrl  = true;
                if (game.core.event.key.keysym.sym == SDLK_RSHIFT) game.core.event_manager.key_rshift = true;
                if (game.core.event.key.keysym.sym == SDLK_0)      game.core.event_manager.key_0      = true;
                if (game.core.event.key.keysym.sym == SDLK_1)      game.core.event_manager.key_1      = true;
                if (game.core.event.key.keysym.sym == SDLK_2)      game.core.event_manager.key_2      = true;
                if (game.core.event.key.keysym.sym == SDLK_3)      game.core.event_manager.key_3      = true;
                if (game.core.event.key.keysym.sym == SDLK_4)      game.core.event_manager.key_4      = true;
                if (game.core.event.key.keysym.sym == SDLK_5)      game.core.event_manager.key_5      = true;
                if (game.core.event.key.keysym.sym == SDLK_6)      game.core.event_manager.key_6      = true;
                if (game.core.event.key.keysym.sym == SDLK_7)      game.core.event_manager.key_7      = true;
                if (game.core.event.key.keysym.sym == SDLK_8)      game.core.event_manager.key_8      = true;
                if (game.core.event.key.keysym.sym == SDLK_9)      game.core.event_manager.key_9      = true;
                if (game.core.event.key.keysym.sym == SDLK_a)      game.core.event_manager.key_a      = true;
                if (game.core.event.key.keysym.sym == SDLK_b)      game.core.event_manager.key_b      = true;
                if (game.core.event.key.keysym.sym == SDLK_c)      game.core.event_manager.key_c      = true;
                if (game.core.event.key.keysym.sym == SDLK_d)      game.core.event_manager.key_d      = true;
                if (game.core.event.key.keysym.sym == SDLK_e)      game.core.event_manager.key_e      = true;
                if (game.core.event.key.keysym.sym == SDLK_f)      game.core.event_manager.key_f      = true;
                if (game.core.event.key.keysym.sym == SDLK_g)      game.core.event_manager.key_g      = true;
                if (game.core.event.key.keysym.sym == SDLK_h)      game.core.event_manager.key_h      = true;
                if (game.core.event.key.keysym.sym == SDLK_i)      game.core.event_manager.key_i      = true;
                if (game.core.event.key.keysym.sym == SDLK_j)      game.core.event_manager.key_j      = true;
                if (game.core.event.key.keysym.sym == SDLK_k)      game.core.event_manager.key_k      = true;
                if (game.core.event.key.keysym.sym == SDLK_l)      game.core.event_manager.key_l      = true;
                if (game.core.event.key.keysym.sym == SDLK_m)      game.core.event_manager.key_m      = true;
                if (game.core.event.key.keysym.sym == SDLK_n)      game.core.event_manager.key_n      = true;
                if (game.core.event.key.keysym.sym == SDLK_o)      game.core.event_manager.key_o      = true;
                if (game.core.event.key.keysym.sym == SDLK_p)      game.core.event_manager.key_p      = true;
                if (game.core.event.key.keysym.sym == SDLK_q)      game.core.event_manager.key_q      = true;
                if (game.core.event.key.keysym.sym == SDLK_r)      game.core.event_manager.key_r      = true;
                if (game.core.event.key.keysym.sym == SDLK_s)      game.core.event_manager.key_s      = true;
                if (game.core.event.key.keysym.sym == SDLK_t)      game.core.event_manager.key_t      = true;
                if (game.core.event.key.keysym.sym == SDLK_u)      game.core.event_manager.key_u      = true;
                if (game.core.event.key.keysym.sym == SDLK_v)      game.core.event_manager.key_v      = true;
                if (game.core.event.key.keysym.sym == SDLK_w)      game.core.event_manager.key_w      = true;
                if (game.core.event.key.keysym.sym == SDLK_x)      game.core.event_manager.key_x      = true;
                if (game.core.event.key.keysym.sym == SDLK_y)      game.core.event_manager.key_y      = true;
                if (game.core.event.key.keysym.sym == SDLK_z)      game.core.event_manager.key_z      = true;
                if (game.core.event.key.keysym.sym == SDLK_F1)     game.core.event_manager.key_f1     = true;
                if (game.core.event.key.keysym.sym == SDLK_F2)     game.core.event_manager.key_f2     = true;
                if (game.core.event.key.keysym.sym == SDLK_F3)     game.core.event_manager.key_f3     = true;
                if (game.core.event.key.keysym.sym == SDLK_F4)     game.core.event_manager.key_f4     = true;
                if (game.core.event.key.keysym.sym == SDLK_F5)     game.core.event_manager.key_f5     = true;
                if (game.core.event.key.keysym.sym == SDLK_F6)     game.core.event_manager.key_f6     = true;
                if (game.core.event.key.keysym.sym == SDLK_F7)     game.core.event_manager.key_f7     = true;
                if (game.core.event.key.keysym.sym == SDLK_F8)     game.core.event_manager.key_f8     = true;
                if (game.core.event.key.keysym.sym == SDLK_F9)     game.core.event_manager.key_f9     = true;
                if (game.core.event.key.keysym.sym == SDLK_F10)    game.core.event_manager.key_f10    = true;
                if (game.core.event.key.keysym.sym == SDLK_F11)    game.core.event_manager.key_f11    = true;
                if (game.core.event.key.keysym.sym == SDLK_F12)    game.core.event_manager.key_f12    = true;
            break;
            case SDL_KEYUP:
                if (game.core.event.key.keysym.sym == SDLK_ESCAPE) game.core.event_manager.key_escape = false;
                if (game.core.event.key.keysym.sym == SDLK_UP)     game.core.event_manager.key_up     = false;
                if (game.core.event.key.keysym.sym == SDLK_DOWN)   game.core.event_manager.key_down   = false;
                if (game.core.event.key.keysym.sym == SDLK_LEFT)   game.core.event_manager.key_left   = false;
                if (game.core.event.key.keysym.sym == SDLK_RIGHT)  game.core.event_manager.key_right  = false;
                if (game.core.event.key.keysym.sym == SDLK_PLUS)   game.core.event_manager.key_plus   = false;
                if (game.core.event.key.keysym.sym == SDLK_MINUS)  game.core.event_manager.key_minus  = false;
                if (game.core.event.key.keysym.sym == SDLK_SPACE)  game.core.event_manager.key_space  = false;
                if (game.core.event.key.keysym.sym == SDLK_RETURN) game.core.event_manager.key_enter  = false;
                if (game.core.event.key.keysym.sym == SDLK_LALT)   game.core.event_manager.key_lalt   = false;
                if (game.core.event.key.keysym.sym == SDLK_LCTRL)  game.core.event_manager.key_lctrl  = false;
                if (game.core.event.key.keysym.sym == SDLK_LSHIFT) game.core.event_manager.key_lshift = false;
                if (game.core.event.key.keysym.sym == SDLK_RALT)   game.core.event_manager.key_ralt   = false;
                if (game.core.event.key.keysym.sym == SDLK_RCTRL)  game.core.event_manager.key_rctrl  = false;
                if (game.core.event.key.keysym.sym == SDLK_RSHIFT) game.core.event_manager.key_rshift = false;
                if (game.core.event.key.keysym.sym == SDLK_0)      game.core.event_manager.key_0      = false;
                if (game.core.event.key.keysym.sym == SDLK_1)      game.core.event_manager.key_1      = false;
                if (game.core.event.key.keysym.sym == SDLK_2)      game.core.event_manager.key_2      = false;
                if (game.core.event.key.keysym.sym == SDLK_3)      game.core.event_manager.key_3      = false;
                if (game.core.event.key.keysym.sym == SDLK_4)      game.core.event_manager.key_4      = false;
                if (game.core.event.key.keysym.sym == SDLK_5)      game.core.event_manager.key_5      = false;
                if (game.core.event.key.keysym.sym == SDLK_6)      game.core.event_manager.key_6      = false;
                if (game.core.event.key.keysym.sym == SDLK_7)      game.core.event_manager.key_7      = false;
                if (game.core.event.key.keysym.sym == SDLK_8)      game.core.event_manager.key_8      = false;
                if (game.core.event.key.keysym.sym == SDLK_9)      game.core.event_manager.key_9      = false;
                if (game.core.event.key.keysym.sym == SDLK_a)      game.core.event_manager.key_a      = false;
                if (game.core.event.key.keysym.sym == SDLK_b)      game.core.event_manager.key_b      = false;
                if (game.core.event.key.keysym.sym == SDLK_c)      game.core.event_manager.key_c      = false;
                if (game.core.event.key.keysym.sym == SDLK_d)      game.core.event_manager.key_d      = false;
                if (game.core.event.key.keysym.sym == SDLK_e)      game.core.event_manager.key_e      = false;
                if (game.core.event.key.keysym.sym == SDLK_f)      game.core.event_manager.key_f      = false;
                if (game.core.event.key.keysym.sym == SDLK_g)      game.core.event_manager.key_g      = false;
                if (game.core.event.key.keysym.sym == SDLK_h)      game.core.event_manager.key_h      = false;
                if (game.core.event.key.keysym.sym == SDLK_i)      game.core.event_manager.key_i      = false;
                if (game.core.event.key.keysym.sym == SDLK_j)      game.core.event_manager.key_j      = false;
                if (game.core.event.key.keysym.sym == SDLK_k)      game.core.event_manager.key_k      = false;
                if (game.core.event.key.keysym.sym == SDLK_l)      game.core.event_manager.key_l      = false;
                if (game.core.event.key.keysym.sym == SDLK_m)      game.core.event_manager.key_m      = false;
                if (game.core.event.key.keysym.sym == SDLK_n)      game.core.event_manager.key_n      = false;
                if (game.core.event.key.keysym.sym == SDLK_o)      game.core.event_manager.key_o      = false;
                if (game.core.event.key.keysym.sym == SDLK_p)      game.core.event_manager.key_p      = false;
                if (game.core.event.key.keysym.sym == SDLK_q)      game.core.event_manager.key_q      = false;
                if (game.core.event.key.keysym.sym == SDLK_r)      game.core.event_manager.key_r      = false;
                if (game.core.event.key.keysym.sym == SDLK_s)      game.core.event_manager.key_s      = false;
                if (game.core.event.key.keysym.sym == SDLK_t)      game.core.event_manager.key_t      = false;
                if (game.core.event.key.keysym.sym == SDLK_u)      game.core.event_manager.key_u      = false;
                if (game.core.event.key.keysym.sym == SDLK_v)      game.core.event_manager.key_v      = false;
                if (game.core.event.key.keysym.sym == SDLK_w)      game.core.event_manager.key_w      = false;
                if (game.core.event.key.keysym.sym == SDLK_x)      game.core.event_manager.key_x      = false;
                if (game.core.event.key.keysym.sym == SDLK_y)      game.core.event_manager.key_y      = false;
                if (game.core.event.key.keysym.sym == SDLK_z)      game.core.event_manager.key_z      = false;
                if (game.core.event.key.keysym.sym == SDLK_F1)     game.core.event_manager.key_f1     = false;
                if (game.core.event.key.keysym.sym == SDLK_F2)     game.core.event_manager.key_f2     = false;
                if (game.core.event.key.keysym.sym == SDLK_F3)     game.core.event_manager.key_f3     = false;
                if (game.core.event.key.keysym.sym == SDLK_F4)     game.core.event_manager.key_f4     = false;
                if (game.core.event.key.keysym.sym == SDLK_F5)     game.core.event_manager.key_f5     = false;
                if (game.core.event.key.keysym.sym == SDLK_F6)     game.core.event_manager.key_f6     = false;
                if (game.core.event.key.keysym.sym == SDLK_F7)     game.core.event_manager.key_f7     = false;
                if (game.core.event.key.keysym.sym == SDLK_F8)     game.core.event_manager.key_f8     = false;
                if (game.core.event.key.keysym.sym == SDLK_F9)     game.core.event_manager.key_f9     = false;
                if (game.core.event.key.keysym.sym == SDLK_F10)    game.core.event_manager.key_f10    = false;
                if (game.core.event.key.keysym.sym == SDLK_F11)    game.core.event_manager.key_f11    = false;
                if (game.core.event.key.keysym.sym == SDLK_F12)    game.core.event_manager.key_f12    = false;
            break;
            default:
                if (game.core.debug) game.core.log.write("Unable to process event -> ", (int)game.core.event.type);
            break;
        }
    }
    //---------------------------------------------------------------------------------------------
    if ((game.core.event_manager.joystick_button_0) || (game.core.event_manager.key_enter))    game.core.event_manager.select = true; else game.core.event_manager.select = false;
    if ((game.core.event_manager.joystick_button_1) || (game.core.event_manager.key_space) || (game.core.event_manager.mouse_button_left)) game.core.event_manager.shoot   = true; else game.core.event_manager.shoot  = false;
    if ((game.core.event_manager.joystick_button_2) || (game.core.event_manager.key_p))        game.core.event_manager.pause   = true; else game.core.event_manager.pause  = false;
    if ((game.core.event_manager.joystick_button_3) || (game.core.event_manager.key_escape))   game.core.event_manager.key_escape = true; else game.core.event_manager.key_escape = false;
    if ((game.core.event_manager.joystick_up)    || (game.core.event_manager.key_up   )) game.core.event_manager.up     = true; else game.core.event_manager.up     = false;
    if ((game.core.event_manager.joystick_down)  || (game.core.event_manager.key_down )) game.core.event_manager.down   = true; else game.core.event_manager.down   = false;
    if ((game.core.event_manager.joystick_left)  || (game.core.event_manager.key_left )) game.core.event_manager.left   = true; else game.core.event_manager.left   = false;
    if ((game.core.event_manager.joystick_right) || (game.core.event_manager.key_right)) game.core.event_manager.right  = true; else game.core.event_manager.right  = false;
    if ((game.core.event_manager.key_lalt)   || (game.core.event_manager.key_ralt))    game.core.event_manager.key_alt   = true; else game.core.event_manager.key_alt   = false;
    if ((game.core.event_manager.key_lctrl)  || (game.core.event_manager.key_rctrl))   game.core.event_manager.key_ctrl  = true; else game.core.event_manager.key_ctrl  = false;
    if ((game.core.event_manager.key_lshift) || (game.core.event_manager.key_rshift))  game.core.event_manager.key_shift = true; else game.core.event_manager.key_shift = false;
    return(true);
}

