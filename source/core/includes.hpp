/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef INCLUDES_HPP
#define INCLUDES_HPP

// 3rd Party
#include "../3rd_party/dr_flac.hpp"
#include "../3rd_party/dr_mp3.hpp"
#include "../3rd_party/dr_wav.hpp"
#include "../3rd_party/galogen.hpp"
#include "../3rd_party/miniaudio.hpp"
#include "../3rd_party/stb_image.hpp"
#include "../3rd_party/stb_image_write.hpp"
#include "../3rd_party/stb_truetype.hpp"
#include "../3rd_party/stb_vorbis.hpp"

// Assimp
#include <assimp/cimport.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/version.h>

// GLM
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

// OpenGL, GLFW
//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Standard C++ headers
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <streambuf>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

// Project includes
#include "defines.hpp"
#include "defines_linux.hpp"
#include "defines_windows.hpp"
#include "defines_types.hpp"
#include "file_paths.hpp"

#include "../debug/debug_log.hpp"

#include "../math/libMath.hpp"

#include "../templates/template_bsp_tree.hpp"
#include "../templates/template_engine.hpp"
#include "../templates/template_linked_list.hpp"
#include "../templates/template_manager.hpp"
#include "../templates/template_queue.hpp"

#include "../utils/file_utils.hpp"
#include "../utils/random.hpp"
#include "../utils/thread_utils.hpp"
#include "../utils/xml_parser.hpp"

#endif // INCLUDES_HPP
