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

#ifndef RE_GRAPHICS_ENGINE_HPP
#define RE_GRAPHICS_ENGINE_HPP

// common headers
#include "../core/re_common_headers.hpp"

// RoboEngine headers
#include "../core/re_defines.hpp"
#include "../entity/re_entity.hpp"
#include "../core/re_log.hpp"
#include "re_camera.hpp"

namespace RoboEngine
{

    class re_cGraphicsEngine
    {
        public:
            re_cGraphicsEngine() = default;
            virtual ~re_cGraphicsEngine() = default;
            re_cGraphicsEngine(const re_cGraphicsEngine&) = default;
            re_cGraphicsEngine& operator=(const re_cGraphicsEngine& _rhs) {if (this == &_rhs) return *this; return *this;}

            uint32_t initialize(void);
            uint32_t terminate(void);
            void process(void);

            inline GLFWwindow* getWindow(void) {return m_window;}
            inline void setEntity(re_sEntity *_entityHead) {m_entityHead = _entityHead;  m_entity = _entityHead;}

            inline void setCameraPosition(glm::vec3 _position, glm::vec3 _lookat) {m_camera.setPosition(_position, _lookat);}
            inline glm::vec3 getCameraPosition(void) {return m_camera.getPosition();}
            inline glm::vec3 getCameraLookat(void) {return m_camera.getLookat();}

            inline uint32_t getWidth(void) {return m_width;}
            inline uint32_t getHeight(void) {return m_height;}
            inline std::string getTitle(void) {return m_title;}
            inline bool getWireFrameMode(void) {return m_wireFrameMode;}

            inline void setWidth(const uint32_t &_width) {m_width = _width;}
            inline void setHeight(const uint32_t &_height) {m_height = _height;}
            inline void setTitle(const std::string &_title) {m_title = _title;}
            void setWireFrameMode(const bool &_state);


        private:
            GLFWwindow* m_window = nullptr;
            re_sEntity *m_entityHead = nullptr;
            re_sEntity *m_entity = nullptr;
            re_cCamera m_camera = {};
            std::string m_title = "RoboEngine " + std::to_string(ROBOENGINE_VERSION_MAJOR) + "." + std::to_string(ROBOENGINE_VERSION_MINOR) + "." + std::to_string(ROBOENGINE_VERSION_MINOR);
            uint32_t m_width = 640;
            uint32_t m_height = 640;
            bool m_fullscreen = false;
            uint32_t m_displayFlags = 0;
            uint16_t m_currentDisplay = 0;
            uint16_t m_currentDisplayMode = 0;
            uint16_t m_numberDisplays = 0;
            uint16_t m_numberDisplayModes = 0;

            bool m_wireFrameMode = false;
    };

}
#endif // RE_GRAPHICS_ENGINE_HPP

