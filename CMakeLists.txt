Project ("Frost and Flame")
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

Set (PACKAGE "FROST_AND_FLAME")
Set (VERSION "0.32.01")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

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

set(BINDIR  "games" CACHE STRING "Directory from CMAKE_INSTALL_PREFIX where game executable will be installed.")
set(DATADIR "share/games/frost_and_flame" CACHE STRING "Directory from CMAKE_INSTALL_PREFIX where game data files will be installed.")

If(NOT IS_ABSOLUTE "${DATADIR}")
	add_definitions(-DDATA_INSTALL_DIR="${CMAKE_INSTALL_PREFIX}/${DATADIR}")
Else(NOT IS_ABSOLUTE "${DATADIR}")
	add_definitions(-DDATA_INSTALL_DIR="${DATADIR}")
EndIf(NOT IS_ABSOLUTE "${DATADIR}")

Include(FindPkgConfig)

PKG_SEARCH_MODULE(GLFW3 REQUIRED glfw3)
If (NOT GLFW3_FOUND)
    Message (ERROR "Couldn't find GLFW3 development files. On Debian-based systems (such as Ubuntu) you should install the 'glfw3-dev' package.")
Else (NOT GLFW3_FOUND)
    INCLUDE_DIRECTORIES(${GLFW3_INCLUDE_DIRS})
EndIf (NOT GLFW3_FOUND)

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
	./source/main.cpp
	./source/mainloop.cpp

	./source/RoboEngine/entity/re_entity.cpp
	./source/RoboEngine/entity/re_entity_physics.cpp
	./source/RoboEngine/entity/re_entity_render.cpp

	./source/RoboEngine/graphics/re_camera.cpp
	./source/RoboEngine/graphics/re_glsl.cpp
	./source/RoboEngine/graphics/re_graphics_engine.cpp
	./source/RoboEngine/graphics/re_image_loader.cpp

	./source/RoboEngine/physics/re_physics_engine.cpp

	./source/RoboEngine/resource/lodepng.cpp
	./source/RoboEngine/resource/re_loader_dae.cpp
	./source/RoboEngine/resource/re_loader_obj.cpp
	./source/RoboEngine/resource/re_manager_mesh.cpp
	./source/RoboEngine/resource/re_manager_shader.cpp
	./source/RoboEngine/resource/re_manager_texture.cpp
	./source/RoboEngine/resource/re_parser_xml.cpp

	./source/RoboEngine/system/re_file.cpp
	./source/RoboEngine/system/re_log.cpp
	./source/RoboEngine/system/re_mainloop.cpp
	./source/RoboEngine/system/re_system_events.cpp
	./source/RoboEngine/system/re_time_step.cpp
	./source/RoboEngine/system/re_types.cpp

)

# Add icon and file info to executable for Windows systems
IF (WIN32)
  SET(FROST_AND_FLAME_SOURCES
    ${FROST_AND_FLAME_SOURCES}
    ./source/icon.rc
    )
ENDIF (WIN32)

Add_Executable (frost_and_flame ${FROST_AND_FLAME_SOURCES})

# target_compile_features(frost_and_flame PRIVATE cxx_range_for)

link_directories( /path/to/PHYSFSlibs/)

Target_Link_Libraries (frost_and_flame ${CMAKE_LD_FLAGS} ${PHYSFS_LIBRARY} ${GLFW3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})


