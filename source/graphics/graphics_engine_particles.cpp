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

#include "graphics_engine_particles.hpp"

void cGraphicsEngineParticles::initialize(void)
{
    // If the particle array is not empty, free its data
    if (m_particle != nullptr)
    {
        delete[] m_particle;
        m_particle = nullptr;
    }
    // Create the particle array
    m_particle = new sParticle[m_numParticles];
}

void cGraphicsEngineParticles::terminate(void)
{
    // If the particle array is not empty, free its data
    if (m_particle != nullptr)
    {
        delete[] m_particle;
        m_particle = nullptr;
    }
}

void cGraphicsEngineParticles::addParticle(const sParticle &_particle)
{
    bool found = false;

    // Search for an unused particle in the array from the last used particle
    for(std::uint32_t i = m_lastParticle; i < m_numParticles; ++i)
    {
        if (m_particle[i].life < 0.0f)
        {
            m_lastParticle = i;
            found = true;
            break;
        }
    }

    // If we haven't found a particle to use yet, search for an unused particle in the array from the beginning of the array
    if (found == false)
    {
        for(std::uint32_t i = 0; i < m_lastParticle; ++i)
        {
            if (m_particle[i].life < 0.0f)
            {
                m_lastParticle = i;
                found = true;
                break;
            }
        }
    }

    // If we haven't found a particle to use yet, overwrite the particle in the array before the last used particle.
    // If the last used particle in the array is the first particle in the array, use the last particle in the array.
    // This is not optimal, but avoids searching the array for the particle with the least amount of health, which
    // would be too costly in terms of CPU overhead.
    if (found == false)
    {
        if (m_lastParticle == 0)
        {
            m_lastParticle = m_numParticles - 1; // zero indexed array
        }
        else
        {
            --m_lastParticle; // Decrement by 1
        }
        found = true;
    }

    // Copy the data from the particle passed to the function to the particle in the array
    m_particle[m_lastParticle] = _particle;
}


void cGraphicsEngineParticles::process(const float32 &_dt)
{
    // Loop throught the particle array
    for (std::uint32_t i = 0; i < m_numParticles; ++i)
    {
        // If particle is alive, continue
        if (m_particle[i].life > 0.0f)
        {
            // Decrese particle life
            m_particle[i].life -= _dt;
            
            // If particle is alive, update
            if (m_particle[i].life > 0.0f)
            {
                m_particle[i].velocity += glm::vec3(0.0f,-9.81f, 0.0f) * _dt * 0.5f;
                m_particle[i].position += m_particle[i].velocity * _dt;
            }
        }
    }
}
