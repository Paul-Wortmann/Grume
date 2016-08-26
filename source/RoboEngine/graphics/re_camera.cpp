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

#include "re_camera.hpp"

namespace RoboEngine
{

    void re_cCamera::setPosition(glm::vec3 _position, glm::vec3 _lookat)
    {
        m_position = _position;
        m_lookat = _lookat;
        m_projection = glm::perspective(glm::radians(m_fov), (float)m_displayX / (float)m_displayY, 0.1f, 100.0f);
        m_view = glm::lookAt(m_position, m_lookat, m_upvec);
    }

    void re_cCamera::initialize(uint16_t _displayX, uint16_t _displayY, float _fov)
    {
        m_displayX = _displayX;
        m_displayY = _displayY;
        m_fov = _fov;
        m_projection = glm::perspective(glm::radians(m_fov), (float)m_displayX / (float)m_displayY, 0.1f, 100.0f);
        m_view = glm::lookAt(m_position, m_lookat, m_upvec);
    }

}
