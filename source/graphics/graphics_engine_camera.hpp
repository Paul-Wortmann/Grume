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

#ifndef GRAPHICS_ENGINE_CAMERA_HPP
#define GRAPHICS_ENGINE_CAMERA_HPP

#include "../core/includes.hpp"

class cGraphicsEngineCamera
{
    public:
        void      initialize(std::uint32_t _fov, std::uint32_t _width, std::uint32_t _height);
        void      terminate(void);
        void      process(const std::int64_t &_dt);
        void      setOrthographic(void) { m_orthographic = true; m_perspective = false;  m_calculateMartacies(); }
        void      setPerspective(void)  { m_perspective = true;  m_orthographic = false; m_calculateMartacies(); }
        glm::mat4 getViewMatrix(void) { return m_view; }
        glm::mat4 getProjectionMatrix(void) { return m_projection; }
        glm::vec3 getPosition(void) { return m_position; }
        void      setPosition(glm::vec3 _position) { m_position = _position; m_calculateMartacies(); }
        glm::vec3 getTarget(void) { return m_target; }
        void      setTarget(glm::vec3 _target) { m_target = _target; m_calculateMartacies(); }
        glm::vec3 getOrientation(void) { return m_orientation; }
        void      setOrientation(glm::vec3 _orientation) { m_orientation = _orientation; m_calculateMartacies(); }
        glm::vec3 getMouseRay(const float &_mouseX, const float &_mouseY);
        void      addScreenShake(const std::uint32_t &_st, const float &_sf) { m_shakeTime += _st; m_shakeForce = _sf; m_shakeActive = true; }

    protected:

    private:
        void           m_calculateMartacies(void);
        std::uint32_t  m_fov           = 45;
        std::uint32_t  m_width         = 1920;
        std::uint32_t  m_height        = 1080;
        float          m_ratio         = static_cast<float>(m_width) / static_cast<float>(m_height);
        bool           m_perspective   = true;
        bool           m_orthographic  = false;
        glm::mat4      m_view          = glm::mat4(1);
        glm::mat4      m_projection    = glm::mat4(1);
        glm::vec3      m_position      = glm::vec3(0.0f,  0.0f, 0.0f);
        glm::vec3      m_target        = glm::vec3(0.0f, -1.0f, 0.0f);
        glm::vec3      m_orientation   = glm::vec3(0.0f,  1.0f, 0.0f);
        glm::vec3      m_shakeTarget   = glm::vec3(0.0f,  0.0f, 0.0f);
        std::uint32_t  m_shakeTime     = 0;
        float          m_shakeForce    = 0.25f;
        bool           m_shakeActive   = false;
};

#endif //GRAPHICS_ENGINE_CAMERA_HPP
