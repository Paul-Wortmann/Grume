Project ("Frost and Flame")
cmake_minimum_required (VERSION 2.8)

Set (PACKAGE "FROST_AND_FLAME")
Set (VERSION "0.30")


# Default definitions
if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-math-errno -fno-exceptions -ffast-math")
  set(CMAKE_LD_FLAGS "-fwhole-program")
endif (NOT MSVC)

if (CMAKE_CXX_COMPILER MATCHES "clang")
  # clang needs lstdc++ linked explicitly:
  set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -lstdc++")
elseif (NOT MSVC)
  # assume gcc:
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-enforce-eh-specs")
endif ()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
  set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -g0")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -pg")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-pg")
  set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "-pg")
  set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "-pg")
endif()

set(BINDIR  "games"             CACHE STRING "Directory from CMAKE_INSTALL_PREFIX where game executable will be installed.")
set(DATADIR "share/games/frost_and_flame" CACHE STRING "Directory from CMAKE_INSTALL_PREFIX where game data files will be installed.")

If(NOT IS_ABSOLUTE "${DATADIR}")
	add_definitions(-DDATA_INSTALL_DIR="${CMAKE_INSTALL_PREFIX}/${DATADIR}")
Else(NOT IS_ABSOLUTE "${DATADIR}")
	add_definitions(-DDATA_INSTALL_DIR="${DATADIR}")
EndIf(NOT IS_ABSOLUTE "${DATADIR}")

# Detect missing dependencies

Include(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
If (NOT SDL2_FOUND)
    Message (ERROR "Couldn't find SDL2 development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl2-dev' package.")
Else (NOT SDL2_FOUND)
    INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
EndIf (NOT SDL2_FOUND)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)
If (NOT SDL2IMAGE_FOUND)
    Message (ERROR "Couldn't find SDL2-image development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl2-image-dev' package.")
Else (NOT SDL2IMAGE_FOUND)
    INCLUDE_DIRECTORIES(${SDL2IMAGE_INCLUDE_DIRS})
EndIf (NOT SDL2IMAGE_FOUND)

PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer)
If (NOT SDL2MIXER_FOUND)
    Message (ERROR "Couldn't find SDL2-mixer development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl2-mixer-dev' package.")
Else (NOT SDL2MIXER_FOUND)
    INCLUDE_DIRECTORIES(${SDL2MIXER_INCLUDE_DIRS})
EndIf (NOT SDL2MIXER_FOUND)

 PKG_SEARCH_MODULE(SDL2NET REQUIRED SDL2_net)
 If (NOT SDL2NET_FOUND)
     Message (ERROR "Couldn't find SDL2_net development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl2-net-dev' package.")
 Else (NOT SDL2NET_FOUND)
     INCLUDE_DIRECTORIES(${SDL2NET_INCLUDE_DIRS})
 EndIf (NOT SDL2NET_FOUND)

PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
If (NOT SDL2TTF_FOUND)
    Message (ERROR "Couldn't find SDL2-ttf development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl2-ttf-dev' package.")
Else (NOT SDL2TTF_FOUND)
    INCLUDE_DIRECTORIES(${SDL2TTF_INCLUDE_DIRS})
EndIf (NOT SDL2TTF_FOUND)

#PKG_SEARCH_MODULE(PHYSFS REQUIRED PhysFS)
#If (NOT PHYSFS_FOUND)
#    Message (ERROR "Couldn't find PhysicsFS development files. On Debian-based systems (such as Ubuntu) you should install the 'libphysfs-dev' package.")
#Else (NOT PHYSFS_FOUND)
#    INCLUDE_DIRECTORIES(${PHYSFS_INCLUDE_DIRS})
#EndIf (NOT PHYSFS_FOUND)

find_package(PhysFS REQUIRED)
if (PHYSFS_FOUND)
  INCLUDE_DIRECTORIES(${PHYSFS_INCLUDE_DIR})
  link_directories(${PHYSFS_LIBRARY})
Else (PHYSFS_FOUND)
   Message (FATAL_ERROR "Couldn't find libphysfs development files. On Debian-based systems (such as Ubuntu) you should install the 'libphysfs-dev' package.")
endif (PHYSFS_FOUND)

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
  INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
  link_directories(${OPENGL_LIBRARIES})
Else (OPENGL_FOUND)
  Message (FATAL_ERROR "Couldn't find OpenGl development files. On Debian-based systems (such as Ubuntu) you should install the OpenGL development package.")
endif (OPENGL_FOUND)

PKG_SEARCH_MODULE(GLEW REQUIRED glew)
If (NOT GLEW_FOUND)
    Message (ERROR "Couldn't find glew development files. On Debian-based systems (such as Ubuntu) you should install the 'libglew-dev' package.")
Else (NOT GLEW_FOUND)
    INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
    #link_directories(${GLEW_LIBRARIES})
EndIf (NOT GLEW_FOUND)

include_directories(/usr/include)

# Sources

Set (FROST_AND_FLAME_SOURCES
	./source/core/background.cpp
	./source/core/command_line_parser.cpp
	./source/core/config.cpp
	./source/core/core.cpp
	./source/core/effect_manager.cpp
	./source/core/event_manager.cpp
	./source/core/file.cpp
	./source/core/font_manager.cpp
	./source/core/graphics_engine.cpp
	./source/core/graphics_engine_GL.cpp
	./source/core/graphics_engine_GL_legacy.cpp
	./source/core/graphics_engine_vao_manager.cpp
	./source/core/item_manager.cpp
	./source/core/item_manager.cpp
	./source/core/loader_fmx.cpp
	./source/core/loader_md2.cpp
	./source/core/loader_obj.cpp
	./source/core/loader_tmx.cpp
	./source/core/log.cpp
	./source/core/map_2D.cpp
	./source/core/map_3D.cpp
	./source/core/map_main.cpp
	./source/core/map_environment_manager.cpp
	./source/core/map_gen.cpp
	./source/core/map_gen_BSP.cpp
	./source/core/map_gen_CA.cpp
	./source/core/map_gen_M1.cpp
	./source/core/map_gen_RC.cpp
	./source/core/math.cpp
	./source/core/misc.cpp
	./source/core/music_manager.cpp
	./source/core/network.cpp
	./source/core/object_manager.cpp
	./source/core/particles.cpp
	./source/core/pathfinding.cpp
	./source/core/physics.cpp
	./source/core/savegame.cpp
	./source/core/sound_manager.cpp
	./source/core/spell_manager.cpp
	./source/core/texture_manager.cpp
	./source/core/timer.cpp
	#./source/core/types.cpp
	./source/core/vector.cpp
	./source/UI/action_bar.cpp
	./source/UI/character_window.cpp
	./source/UI/equipment_window.cpp
	./source/UI/inventory_window.cpp
	./source/UI/menu_game_load.cpp
	./source/UI/menu_game_new.cpp
	./source/UI/menu_game_save.cpp
	./source/UI/menu_help.cpp
	./source/UI/menu_main.cpp
	./source/UI/menu_options.cpp
	./source/UI/player_profile.cpp
	./source/UI/quest_log_window.cpp
	./source/UI/skillbook_window.cpp
	./source/UI/UI_cursor.cpp
	./source/UI/UI_loading_screen.cpp
	./source/UI/UI_manager.cpp
	./source/UI/UI_types.cpp
	./source/game/effects.cpp
	./source/game/game.cpp
	./source/game/items.cpp
	./source/game/language.cpp
	./source/game/npc.cpp
	./source/game/player.cpp
	./source/game/save_data.cpp
	./source/game/spells.cpp
	./source/main.cpp
)

# Add icon and file info to executable for Windows systems
IF (WIN32)
  SET(FROST_AND_FLAME_SOURCES
    ${FROST_AND_FLAME_SOURCES}
    ./source/icon.rc
    )
ENDIF (WIN32)

Add_Executable (frost_and_flame ${FROST_AND_FLAME_SOURCES})

link_directories( /path/to/PHYSFSlibs/)

Target_Link_Libraries (frost_and_flame ${CMAKE_LD_FLAGS}  ${PHYSFS_LIBRARY} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2NET_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})


