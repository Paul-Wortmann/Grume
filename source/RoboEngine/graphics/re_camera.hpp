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

#ifndef RE_CAMERA_HPP
#define RE_CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtx/projection.hpp>
#include <glm/gtx/transform2.hpp>

#include <cstdint>

namespace RoboEngine
{

    class re_cCamera
    {
        public:
            re_cCamera(void) {}
            virtual ~re_cCamera(void) {}
            re_cCamera(const re_cCamera&) = default;
            re_cCamera& operator=(const re_cCamera& rhs) {if (this == &rhs) return *this; return *this;}
            void initialize(uint16_t _displayX, uint16_t _displayY, float _fov);
            void setPosition(glm::vec3 _position, glm::vec3 _lookat);
            inline glm::vec3 getPosition(void) {return m_position;}
            inline glm::mat4 getProjection(void) {return m_projection;}
            inline glm::mat4 getView(void) {return m_view;}
            inline glm::vec3 getLookat(void) {return m_lookat;}
        private:
            uint16_t m_displayX = 640;
            uint16_t m_displayY = 480;
            float m_fov = 45.0f;
            glm::vec3 m_position = glm::vec3(0.0f);
            glm::vec3 m_lookat = glm::vec3(0.0f);
            glm::vec3 m_upvec = glm::vec3(0.0f, 1.0f, 0.0f);
            glm::mat4 m_projection = glm::mat4(1.0f);
            glm::mat4 m_view = glm::mat4(1.0f);
    };

}

#endif // RE_CAMERA_HPP
