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

#include "graphics_engine_camera.hpp"

void cGraphicsEngineCamera::initialize(uint32 _fov, uint32 _width, uint32 _height)
{
    m_fov    = _fov;
    m_width  = _width;
    m_height = _height;
    m_calculateMartacies();
}

void cGraphicsEngineCamera::terminate(void)
{

}

void cGraphicsEngineCamera::process(const float32 &_dt)
{
    if (m_shakeActive)
    {
        m_shakeTime -= _dt;
        if (m_shakeTime < 0.0f)
        {
            m_shakeTarget = glm::vec3(0.0f, 0.0f, 0.0f);
            m_view        = glm::lookAt(m_position, m_target, m_orientation);
            m_shakeActive = false;
        }
        else
        {
            float32 fx = static_cast<float32>(20000 - (rand() % 20000)) / 10000.0f;
            float32 fy = static_cast<float32>(20000 - (rand() % 20000)) / 10000.0f;
            float32 fz = static_cast<float32>(20000 - (rand() % 20000)) / 10000.0f;
            
            m_shakeTarget = glm::vec3(fx * m_shakeForce, fy * m_shakeForce, fz * m_shakeForce);
            m_view        = glm::lookAt(m_position, m_target + m_shakeTarget, m_orientation);
        }
    }
}

void cGraphicsEngineCamera::m_calculateMartacies(void)
{
    m_projection = glm::perspective(static_cast<float32>(m_fov), static_cast<float32>(m_width) / static_cast<float32>(m_height), 0.1f, 100.0f);
    m_view       = glm::lookAt(m_position, m_target + m_shakeTarget, m_orientation);
}

glm::vec3 cGraphicsEngineCamera::getMouseRay(const float32 &_mouseX, const float32 &_mouseY)
{
    // Normalized device coordinates:
    float32 posX = ((_mouseX * 2.0f) / static_cast<float32>(m_width)) - 1.0f;
    float32 posY = 1.0f - ((_mouseY * 2.0f) / static_cast<float32>(m_height));
    //glm::vec3  normalizedDC = glm::vec3(posX, posY, 1.0f);

    // 3D Normalised Device Coordinates
    float z = 1.0f; // the camera looks on the negative z axis
    glm::vec3 rayNds = glm::vec3(posX, posY, z);

    // 4D Homogeneous Clip Coordinates
    glm::vec4 rayClip = glm::vec4(rayNds.x, rayNds.y, -rayNds.z, 1.0);

    // 4D Eye (Camera) Coordinates
    glm::vec4 rayEye = glm::inverse(m_projection) * rayClip;

    // Now, we only needed to un-project the x,y part, so let's manually set the z,w part to mean "forwards, and not a point". From http://antongerdelan.net/opengl/raycasting.html
    rayEye = glm::vec4(rayEye.x, rayEye.y, -1.0, 0.0);

    // 4D World Coordinates
    glm::vec4 rayWorldv4 = glm::inverse(m_view) * rayEye;
    glm::vec3 rayWorld = glm::vec3(rayWorldv4.x, rayWorldv4.y, rayWorldv4.z);

    rayWorld = glm::normalize(rayWorld);
    return rayWorld;
};

glm::vec3 cGraphicsEngineCamera::getRayPlaneIntersection(const glm::vec3 &_ray)
{
    glm::vec3 n = glm::vec3(0.0, -1.0, 0.0);
    float32   t = -glm::dot(m_position, n) / glm::dot(_ray, n);

    return m_position + _ray * t;
}

glm::vec3 cGraphicsEngineCamera::getMousePositionTerrain(const float32 &_mouseX, const float32 &_mouseY)
{
    glm::vec3 rayDirection = getMouseRay(_mouseX, _mouseY);
    glm::vec3 planePoint = getRayPlaneIntersection(rayDirection);

    //std::cout << "Ray x: " << rayDirection.x << " y: " << rayDirection.y << " z: " << rayDirection.z << std::endl;
    //std::cout << "PlanePoint x: " << planePoint.x << " y: " << planePoint.y << " z: " << planePoint.z << std::endl;

    return planePoint;
}








