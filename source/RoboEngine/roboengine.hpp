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

#ifndef RE_ROBOENGINE_HPP
#define RE_ROBOENGINE_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

#include "core/re_defines.hpp"
#include "core/re_engine.hpp"
#include "core/re_platform_headers.hpp"
#include "core/re_time_step.hpp"
#include "core/re_types.hpp"
#include "core/re_version.hpp"

#include "entity/re_entity.hpp"
#include "entity/re_entity_physics.hpp"
#include "entity/re_entity_render.hpp"

#include "graphics/re_camera.hpp"
#include "graphics/re_glsl.hpp"
#include "graphics/re_graphics_engine.hpp"
#include "graphics/re_image_loader.hpp"

#include "physics/re_physics.hpp"
#include "physics/re_physics_engine.hpp"

#include "resource/lodepng.h"
#include "resource/re_generate_mesh.hpp"
#include "resource/re_loader_dae.hpp"
#include "resource/re_loader_obj.hpp"
#include "resource/re_loader_tmx.hpp"
#include "resource/re_manager_mesh.hpp"
#include "resource/re_manager_shader.hpp"
#include "resource/re_manager_texture.hpp"
#include "resource/re_parser_xml.hpp"
#include "resource/re_texture_atlas.hpp"

#include "system/re_file.hpp"
#include "system/re_log.hpp"
#include "system/re_math.hpp"
#include "system/re_random.hpp"
#include "system/re_system_events.hpp"

namespace RoboEngine
{

}

#endif // RE_ROBOENGINE_HPP
