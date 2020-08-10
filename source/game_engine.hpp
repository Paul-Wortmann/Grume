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

#ifndef GAME_HPP
#define GAME_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "animation_engine.hpp"
#include "audio_engine.hpp"
#include "entity_manager.hpp"
#include "graphics_engine.hpp"
#include "physics_engine.hpp"

#include "timer.hpp"
#include "version.hpp"

class cGame
{
    public:
        eGameState state = eGameState::active;
        
        cGame(void) = default;
        ~cGame(void) = default;
        void initialize(void);
        void terminate(void);
        void process(void);
        
    protected:

    private:
        cEntityManager    m_entityManager   = {};
        cTimer            m_timer           = {};
        
        cAnimationEngine  m_animationEngine = {};
        cAudioEngine      m_audioEngine     = {};
        cGraphicsEngine   m_graphicsEngine  = {};
        cPhysicsEngine    m_physicsEngine   = {};
};



#endif //GAME_HPP
