Project ("Frost and Flame")
cmake_minimum_required (VERSION 2.6)

Set (PACKAGE "FROST_AND_FLAME")
Set (VERSION "0.16")


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

Find_Package (SDL REQUIRED)
If (NOT SDL_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl1.2-dev' package.")
Else (NOT SDL_FOUND)
  Include_Directories (${SDL_INCLUDE_DIR})
EndIf (NOT SDL_FOUND)

Find_Package (SDL_mixer REQUIRED)
If (NOT SDLMIXER_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-mixer development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-mixer1.2-dev' package.")
Else (NOT SDLMIXER_FOUND)
  Include_Directories (${SDLMIXER_INCLUDE_DIR})
EndIf (NOT SDLMIXER_FOUND)

Find_Package (SDL_image REQUIRED)
If (NOT SDLIMAGE_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-image development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-image1.2-dev' package.")
Else (NOT SDLIMAGE_FOUND)
  Include_Directories (${SDLIMAGE_INCLUDE_DIR})
EndIf (NOT SDLIMAGE_FOUND)

Find_Package (SDL_ttf REQUIRED)
If (NOT SDLTTF_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-ttf development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-ttf2.0-dev' package.")
Else (NOT SDLTTF_FOUND)
  Include_Directories (${SDLTTF_INCLUDE_DIR})
EndIf (NOT SDLTTF_FOUND)

Find_Package (SDL_net REQUIRED)
If (NOT SDLNET_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-net development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-net2.1-dev' package.")
Else (NOT SDLNET_FOUND)
  Include_Directories (${SDLNET_INCLUDE_DIR})
EndIf (NOT SDLNET_FOUND)

# make sure PhysFS is installed
Find_Package (PhysFS REQUIRED)
If (NOT PHYSFS_FOUND)
  Message (FATAL_ERROR "Couldn't find libphysfs development files. On Debian-based systems (such as Ubuntu) you should install the 'libphysfs-dev' package.")
Else (NOT PHYSFS_FOUND)
  Include_Directories (${LIBPHYSFS_INCLUDE_DIR})
EndIf (NOT PHYSFS_FOUND)

# TODO: If OpenGL isn't found, we should complain loudly since an
#	appropriate alternative graph driver is unavailable.
#	The plan is to allow someone to contribute a DirectX driver
#	or produce an alternative as needs arise.
find_package(OpenGL)
if (OPENGL_FOUND)
  include_directories(${OPENGL_INCLUDE_DIR})
  link_directories(${OPENGL_LIBRARIES})
Else (OPENGL_FOUND)
  Message (FATAL_ERROR "Couldn't find OpenGl development files. On Debian-based systems (such as Ubuntu) you should install the OpenGL development package.")
endif (OPENGL_FOUND)

# Sources

Set (FROST_AND_FLAME_SOURCES
	./source/UI/loading_screen.cpp
	./source/UI/menu_game_save.cpp
	./source/UI/UI.cpp
	./source/UI/window_manager.cpp
	./source/UI/menu_game_load.cpp
	./source/UI/menu_main.cpp
	./source/UI/window.cpp
	./source/UI/menu_game_new.cpp
	./source/UI/menu_options.cpp
	./source/UI/window_element.cpp
	./source/core/background.cpp
	./source/core/graphics.cpp
	./source/core/log.cpp
	./source/core/network.cpp
	./source/core/savegame.cpp
	./source/core/config.cpp
	./source/core/io.cpp
	./source/core/map_2D.cpp
	./source/core/particles.cpp
	./source/core/sound.cpp
	./source/core/core.cpp
	./source/core/loader_md2.cpp
	./source/core/map_3D.cpp
	./source/core/pathfinding.cpp
	./source/core/textures.cpp
	./source/core/file.cpp
	./source/core/loader_obj.cpp
	./source/core/misc.cpp
	./source/core/physics.cpp
	./source/core/timer.cpp
	./source/core/font.cpp
	./source/core/loader_tmx.cpp
	./source/core/music.cpp
	./source/core/rs232.cpp
	./source/core/vector.cpp
	./source/npc.cpp
	./source/save_data.cpp
	./source/language.cpp
	./source/player.cpp
	./source/spells.cpp
	./source/game.cpp
	./source/item_manager.cpp
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

# libSDLMain comes with libSDL if needed on certain platforms
If (NOT SDLMAIN_LIBRARY)
  Set (SDLMAIN_LIBRARY "")
EndIf (NOT SDLMAIN_LIBRARY)

Target_Link_Libraries (frost_and_flame ${CMAKE_LD_FLAGS} ${SDL_LIBRARY} ${SDLMIXER_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY} ${SDLNET_LIBRARY} ${SDLMAIN_LIBRARY} ${LIBPHYSFS_INCLUDE_DIR})


# desktop file
#If(NOT IS_ABSOLUTE "${BINDIR}")
#	set(FROST_AND_FLAME_EXECUTABLE_PATH ${CMAKE_INSTALL_PREFIX}/${BINDIR}/frost_and_flame)
#Else(NOT IS_ABSOLUTE "${BINDIR}")
#	set(FROST_AND_FLAME_EXECUTABLE_PATH ${BINDIR}/frost_and_flame)
#EndIf(NOT IS_ABSOLUTE "${BINDIR}")
#configure_file("${CMAKE_CURRENT_SOURCE_DIR}/distribution/frost_and_flame.desktop.in" "${CMAKE_CURRENT_BINARY_DIR}/frost_and_flame.desktop")


# installing to the proper places
#install(PROGRAMS
#  ${CMAKE_CURRENT_BINARY_DIR}/frost_and_flame
#  DESTINATION ${BINDIR})
#install(DIRECTORY
#  "${CMAKE_CURRENT_SOURCE_DIR}/mods"
#  DESTINATION ${DATADIR})
#install(FILES
#  "${CMAKE_CURRENT_BINARY_DIR}/frost_and_flame.desktop"
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
#install(FILES
#  "${CMAKE_CURRENT_SOURCE_DIR}/distribution/frost_and_flame_logo.svg"
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/scalable/apps
#  RENAME frost_and_flame.svg)

