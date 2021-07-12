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

#ifndef GRAPHICS_ENGINE_CAMERA_HPP
#define GRAPHICS_ENGINE_CAMERA_HPP

#include "../core/includes.hpp"

class cGraphicsEngineCamera
{
    public:
        void      initialize(uint32 _fov, uint32 _width, uint32 _height);
        void      terminate(void);
        void      process(const float32 &_dt);
        glm::mat4 getViewMatrix(void) { return m_view; }
        glm::mat4 getProjectionMatrix(void) { return m_projection; }
        glm::vec3 getPosition(void) { return m_position; }
        void      setPosition(glm::vec3 _position) { m_position = _position; m_calculateMartacies(); }
        glm::vec3 getTarget(void) { return m_target; }
        void      setTarget(glm::vec3 _target) { m_target = _target; m_calculateMartacies(); }
        glm::vec3 getOrientation(void) { return m_orientation; }
        void      setOrientation(glm::vec3 _orientation) { m_orientation = _orientation; m_calculateMartacies(); }
        glm::vec3 getMouseRay(const float32 &_mouseX, const float32 &_mouseY);
        glm::vec3 getRayPlaneIntersection(const glm::vec3 &_ray);
        glm::vec3 getMousePositionTerrain(const float32 &_mouseX, const float32 &_mouseY);
        void      addScreenShake(const float32 &_st, const float32 &_sf) { m_shakeTime += _st; m_shakeForce = _sf; m_shakeActive = true; }

    protected:

    private:
        void           m_calculateMartacies(void);
        uint32         m_fov          = 45;
        uint32         m_width        = 1920;
        uint32         m_height       = 1080;
        glm::mat4      m_view         = glm::mat4(1);
        glm::mat4      m_projection   = glm::mat4(1);
        glm::vec3      m_position     = glm::vec3(0.0f,  0.0f, 0.0f);
        glm::vec3      m_target       = glm::vec3(0.0f, -1.0f, 0.0f);
        glm::vec3      m_orientation  = glm::vec3(0.0f,  1.0f, 0.0f);
        glm::vec3      m_shakeTarget  = glm::vec3(0.0f,  0.0f, 0.0f);
        float32        m_shakeTime    = 0.0f;
        float32        m_shakeForce   = 0.25f;
        bool           m_shakeActive  = false;
};

#endif //GRAPHICS_ENGINE_CAMERA_HPP
