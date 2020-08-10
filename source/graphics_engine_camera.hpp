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

#include "defines.hpp"
#include "includes.hpp"

class cCamera
{
    public:
        explicit cCamera(uint32_t _windowWidth, uint32_t _windowHeight) { initialize(_windowWidth, _windowHeight, m_fieldOfView); }
        cCamera(void) = default;
        ~cCamera(void) = default;
        cCamera(cCamera& _other) = delete;
        cCamera(const cCamera& _other) = delete;
        cCamera& operator=(const cCamera& other) = delete;
        void initialize(uint32_t _windowWidth, uint32_t _windowHeight, float _fieldOfView) { m_windowWidth = _windowWidth; m_windowHeight = _windowHeight; m_aspectRatio = (float)m_windowWidth / (float)m_windowHeight; m_fieldOfView = _fieldOfView; buildProjectionMatrixOrthographic(); buildProjectionMatrixPerspective(); buildViewMatrix(); }
        void buildProjectionMatrixOrthographic(void) { m_projectionMatrixOrthographic = glm::ortho((-1.0f*m_aspectRatio) - m_cameraZoom, (1.f*m_aspectRatio) + m_cameraZoom, -1.0f - m_cameraZoom, 1.0f + m_cameraZoom, 10.0f + m_cameraZoom, -10.0f - m_cameraZoom); }
        void buildProjectionMatrixPerspective(void)  { m_projectionMatrixPerspective  = glm::perspective(glm::radians(m_fieldOfView), m_aspectRatio, m_near + m_cameraZoom, m_far + m_cameraZoom); }
        void buildViewMatrix(void) { m_viewMatrix = lookAt(m_cameraPosition, m_cameraTarget, m_upVector); }
        void setCameraPosition(glm::vec3 _position) { m_cameraPosition = _position; buildViewMatrix(); }
        void setCameraTarget(glm::vec3 _target) { m_cameraTarget = _target; buildViewMatrix(); }
        void setPosition(glm::vec3 _position, glm::vec3 _target) { m_cameraPosition = _position; m_cameraTarget = _target; buildViewMatrix(); }
        void setCameraZoom(float _zoom) { m_cameraZoom = _zoom; buildProjectionMatrixOrthographic(); buildProjectionMatrixPerspective(); }
        glm::mat4 getViewMatrix(void) { return m_viewMatrix; }
        glm::mat4 getProjectionMatrixOrthographic(void) { return m_projectionMatrixOrthographic; }
        glm::mat4 getProjectionMatrixPerspective(void) { return m_projectionMatrixPerspective; }
        glm::vec3 getCameraPosition(void) { return m_cameraPosition; }
        glm::vec3 getCameraTarget(void) { return m_cameraTarget; }
        float getCameraZoom(void) { return m_cameraZoom; }
        
    protected:
        
    private:
        uint32_t  m_windowWidth                  = 800;
        uint32_t  m_windowHeight                 = 600;
        float     m_aspectRatio                  = (float)m_windowWidth / (float)m_windowHeight;
        float     m_fieldOfView                  = 90.0f; // degrees
        float     m_cameraZoom                   = 0.0f;
        float     m_near                         = 0.1f;
        float     m_far                          = 100.0f;
        glm::vec3 m_cameraPosition               = glm::vec3(0.0f, 10.0f, 10.0f);
        glm::vec3 m_cameraTarget                 = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 m_upVector                     = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 m_projectionMatrixOrthographic = glm::ortho((-1.0f*m_aspectRatio) - m_cameraZoom, (1.f*m_aspectRatio) + m_cameraZoom, -1.0f - m_cameraZoom, 1.0f + m_cameraZoom, 10.0f + m_cameraZoom, -10.0f - m_cameraZoom);
        glm::mat4 m_projectionMatrixPerspective  = glm::perspective(glm::radians(m_fieldOfView), m_aspectRatio, m_near + m_cameraZoom, m_far + m_cameraZoom);
        glm::mat4 m_viewMatrix                   = lookAt(m_cameraPosition, m_cameraTarget, m_upVector);
        
};

#endif //GRAPHICS_ENGINE_CAMERA_HPP
