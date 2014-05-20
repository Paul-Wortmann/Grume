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

#include "graphics_engine.hpp"
#include "graphics_engine_GL.hpp"
#include "graphics_engine_GL_legacy.hpp"
#include "core.hpp"
#include "../game/game.hpp"

extern game_class game;


int gl_to_res (float gl_coord, int max_res)
{
   return ((gl_coord+1)*(max_res / 2));
}

float res_to_gl (int res_coord, int max_res)
{
   return ((((float) res_coord / (float) max_res) *2) -1);
}

std::string pixel_format_from_int(int pfi)
{
    switch (pfi)
    {
        case SDL_PIXELFORMAT_INDEX1LSB:
            return ("SDL_PIXELFORMAT_INDEX1LSB");
        break;
        case SDL_PIXELFORMAT_INDEX1MSB:
            return ("SDL_PIXELFORMAT_INDEX1MSB");
        break;
        case SDL_PIXELFORMAT_INDEX4LSB:
            return ("SDL_PIXELFORMAT_INDEX4LSB");
        break;
        case SDL_PIXELFORMAT_INDEX4MSB:
            return ("SDL_PIXELFORMAT_INDEX4MSB");
        break;
        case SDL_PIXELFORMAT_INDEX8:
            return ("SDL_PIXELFORMAT_INDEX8");
        break;
        case SDL_PIXELFORMAT_RGB332:
            return ("SDL_PIXELFORMAT_RGB332");
        break;
        case SDL_PIXELFORMAT_RGB444:
            return ("SDL_PIXELFORMAT_RGB444");
        break;
        case SDL_PIXELFORMAT_RGB555:
            return ("SDL_PIXELFORMAT_RGB555");
        break;
        case SDL_PIXELFORMAT_BGR555:
            return ("SDL_PIXELFORMAT_BGR555");
        break;
        case SDL_PIXELFORMAT_ARGB4444:
            return ("SDL_PIXELFORMAT_ARGB4444");
        break;
        case SDL_PIXELFORMAT_RGBA4444:
            return ("SDL_PIXELFORMAT_RGBA4444");
        break;
        case SDL_PIXELFORMAT_ABGR4444:
            return ("SDL_PIXELFORMAT_ABGR4444");
        break;
        case SDL_PIXELFORMAT_BGRA4444:
            return ("SDL_PIXELFORMAT_BGRA4444");
        break;
        case SDL_PIXELFORMAT_ARGB1555:
            return ("SDL_PIXELFORMAT_ARGB1555");
        break;
        case SDL_PIXELFORMAT_RGBA5551:
            return ("SDL_PIXELFORMAT_RGBA5551");
        break;
        case SDL_PIXELFORMAT_ABGR1555:
            return ("SDL_PIXELFORMAT_ABGR1555");
        break;
        case SDL_PIXELFORMAT_BGRA5551:
            return ("SDL_PIXELFORMAT_BGRA5551");
        break;
        case SDL_PIXELFORMAT_RGB565:
            return ("SDL_PIXELFORMAT_RGB565");
        break;
        case SDL_PIXELFORMAT_BGR565:
            return ("SDL_PIXELFORMAT_BGR565");
        break;
        case SDL_PIXELFORMAT_RGB24:
            return ("SDL_PIXELFORMAT_RGB24");
        break;
        case SDL_PIXELFORMAT_BGR24:
            return ("SDL_PIXELFORMAT_BGR24");
        break;
        case SDL_PIXELFORMAT_RGB888:
            return ("SDL_PIXELFORMAT_RGB888");
        break;
        case SDL_PIXELFORMAT_RGBX8888:
            return ("SDL_PIXELFORMAT_RGBX8888");
        break;
        case SDL_PIXELFORMAT_BGR888:
            return ("SDL_PIXELFORMAT_BGR888");
        break;
        case SDL_PIXELFORMAT_BGRX8888:
            return ("SDL_PIXELFORMAT_BGRX8888");
        break;
        case SDL_PIXELFORMAT_ARGB8888:
            return ("SDL_PIXELFORMAT_ARGB8888");
        break;
        case SDL_PIXELFORMAT_RGBA8888:
            return ("SDL_PIXELFORMAT_RGBA8888");
        break;
        case SDL_PIXELFORMAT_ABGR8888:
            return ("SDL_PIXELFORMAT_ABGR8888");
        break;
        case SDL_PIXELFORMAT_BGRA8888:
            return ("SDL_PIXELFORMAT_BGRA8888");
        break;
        case SDL_PIXELFORMAT_ARGB2101010:
            return ("SDL_PIXELFORMAT_ARGB2101010");
        break;
        case SDL_PIXELFORMAT_YV12:
            return ("SDL_PIXELFORMAT_YV12");
        break;
        case SDL_PIXELFORMAT_IYUV:
            return ("SDL_PIXELFORMAT_IYUV");
        break;
        case SDL_PIXELFORMAT_YUY2:
            return ("SDL_PIXELFORMAT_YUY2");
        break;
        case SDL_PIXELFORMAT_UYVY:
            return ("SDL_PIXELFORMAT_UYVY");
        break;
        case SDL_PIXELFORMAT_YVYU:
            return ("SDL_PIXELFORMAT_YVYU");
        break;
        case SDL_PIXELFORMAT_UNKNOWN:
        default:
            return ("SDL_PIXELFORMAT_UNKNOWN");
        break;
    }
    return ("Error in pixel_format_from_int(int pfi)");
}

graphics_engine_class::graphics_engine_class(void)
{
    graphics_engine_class::gl_extention_count       = 0;
    graphics_engine_class::gl_extention_names       = NULL;
    graphics_engine_class::current_display          = 0;
    graphics_engine_class::current_display_mode     = 0;
    graphics_engine_class::GL_major_version_number  = 0;
    graphics_engine_class::GL_minor_version_number  = 0;
    graphics_engine_class::number_displays          = 0;
    graphics_engine_class::number_display_modes     = 0;
    graphics_engine_class::renderer                 = RENDERER_GL1;
    graphics_engine_class::window                   = NULL;
    graphics_engine_class::display_mode             = NULL;
    graphics_engine_class::menu_mode_list           = NULL;
    graphics_engine_class::menu_mode_length         = 0;
    graphics_engine_class::render_GL.fragmentshader = 0;
    graphics_engine_class::render_GL.vertexshader   = 0;
    graphics_engine_class::render_GL.shaderprogram  = 0;
}

graphics_engine_class::~graphics_engine_class(void)
{

}

bool graphics_engine_class::init(void)
{
    bool return_value = false;
    switch (graphics_engine_class::renderer)
    {
        case RENDERER_GL3:
            return_value = GL_init();
        break;
        case RENDERER_GL1:
        default:
            graphics_engine_class::renderer = RENDERER_GL1;
            return_value = GL_legacy_init();
        break;
    }
    return(return_value);
};

bool graphics_engine_class::deinit(void)
{
    bool return_value = false;
    switch (graphics_engine_class::renderer)
    {
        case RENDERER_GL3:
            return_value = GL_deinit();
        break;
        case RENDERER_GL1:
        default:
            return_value = GL_legacy_deinit();
        break;
    }
    return(return_value);
};

bool graphics_engine_class::render(void)
{
    bool return_value = false;
    switch (graphics_engine_class::renderer)
    {
        case RENDERER_GL3:
            return_value = GL_render();
        break;
        case RENDERER_GL1:
        default:
            return_value = GL_legacy_render();
        break;
    }
    return(return_value);
};

bool graphics_engine_class::build_mode_list(void)
{
    bool return_value = false;
    switch (graphics_engine_class::renderer)
    {
        case RENDERER_GL3:
            return_value = GL_build_mode_list();
        break;
        case RENDERER_GL1:
        default:
            return_value = GL_legacy_build_mode_list();
        break;
    }
    return(return_value);
};

std::string graphics_engine_class::get_display_mode(int mode_number)
{
    std::string return_value = "error";
    switch (graphics_engine_class::renderer)
    {
        case RENDERER_GL3:
            return_value = GL_get_display_mode(mode_number);
        break;
        case RENDERER_GL1:
        default:
            return_value = GL_legacy_get_display_mode(mode_number);
        break;
    }
    return(return_value);
};

