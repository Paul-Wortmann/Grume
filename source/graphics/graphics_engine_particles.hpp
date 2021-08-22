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

#ifndef GRAPHICS_ENGINE_PARTICLES_HPP
#define GRAPHICS_ENGINE_PARTICLES_HPP

#include "../core/includes.hpp"
#include "graphics_engine_particle_define.hpp"

class cGraphicsEngineParticles
{
    public:
        // Constructors
        cGraphicsEngineParticles(void) = default;
        ~cGraphicsEngineParticles(void) = default;

        // Member functions
        void     initialize(void);
        void     terminate(void);
        void     addParticle(const sParticle &_particle);
        void     process(const float32 &_dt);
        
        // Getters
        std::uint32_t getNumParticles(void) { return m_numParticles; };
        sParticle*    getParticles(void) { return m_particle; };

    protected:

    private:
        std::uint32_t m_numParticles = 100;
        std::uint32_t m_lastParticle = 0;
        sParticle*    m_particle     = nullptr;
};

#endif //GRAPHICS_ENGINE_PARTICLES_HPP
