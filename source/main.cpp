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

#include "defines.hpp"
#include "includes.hpp"

#include "entity_manager.hpp"
#include "animation_engine.hpp"
#include "audio_engine.hpp"
#include "graphics_engine.hpp"
#include "physics_engine.hpp"

int main(int argc, char **argv)
{
    // the entity manager needs to be initialized prior to any system initializations
    cEntityManager entityManager;
    entityManager.initialize();
    
    // system initializations
    cAnimationEngine animationEngine;
    animationEngine.setEntityHandle(entityManager.getFirst());
    animationEngine.initialize();

    cAudioEngine audioEngine;
    audioEngine.setEntityHandle(entityManager.getFirst());
    audioEngine.initialize();

    cGraphicsEngine graphicsEngine;
    graphicsEngine.setEntityHandle(entityManager.getFirst());
    graphicsEngine.initialize();

    cPhysicsEngine physicsEngine;
    physicsEngine.setEntityHandle(entityManager.getFirst());
    physicsEngine.initialize();

    // main application loop
    // pysics, audio, animation, graphics
    //while (true)
    {
        physicsEngine.process();
        audioEngine.process();
        animationEngine.process();
        graphicsEngine.process();
    }
    
    // terminate systems
    animationEngine.terminate();
    audioEngine.terminate();
    graphicsEngine.terminate();
    physicsEngine.terminate();
    
    // terminate the entity manager after terminating systems
    entityManager.terminate();
    return EXIT_SUCCESS;
}

