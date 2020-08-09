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

#include "game_engine.hpp"

void cGame::initialize(void)
{
    gLogClear();
    gLogWrite(LOG_INFO, std::string(__DATE__) + " " + std::string(__TIME__) + " - Starting Frost and Flame.", __FILE__, __LINE__, __FUNCTION__);

    m_timer.initialize();

    // the entity manager needs to be initialized prior to any system initializations
    m_entityManager.initialize();
        
    // Try to initialize the graphics engine first
    if (m_graphicsEngine.initialize() == EXIT_FAILURE)
    {
        state = eGameState::inactive;
        return;
    }
    else
    {
        // system initializations
        m_animationEngine.setEntityHandle(m_entityManager.getFirstAnimationComponent());
        m_animationEngine.initialize();

        m_audioEngine.setEntityHandle(m_entityManager.getFirstAudioComponent());
        m_audioEngine.initialize();

        m_graphicsEngine.setEntityHandle(m_entityManager.getFirstGraphicsComponent());

        m_physicsEngine.setEntityHandle(m_entityManager.getFirstPhysicsComponent());
        m_physicsEngine.initialize();
    }
}

void cGame::terminate(void)
{
    // terminate systems
    m_animationEngine.terminate();
    m_audioEngine.terminate();
    m_graphicsEngine.terminate();
    m_physicsEngine.terminate();

    // terminate the entity manager after terminating systems
    m_entityManager.terminate();
}

void cGame::process(void)
{
    m_timer.process();

    if (m_timer.ready())
    {
        double dt = m_timer.get_frameTime();
        m_physicsEngine.process();
        m_audioEngine.process();
        m_animationEngine.process(dt);
        m_graphicsEngine.process();
        m_graphicsEngine.render();
        m_timer.advance_dt();
        //std::cout << "Frame time: " << m_timer.get_frameTime() << std::endl;
    }
        
    state = (m_graphicsEngine.windowActive()) ? eGameState::active : eGameState::inactive;
    if (state == eGameState::inactive)
    {
        return;
    }
    state = (m_graphicsEngine.getKeyState(GLFW_KEY_ESCAPE) == GLFW_RELEASE) ? eGameState::active : eGameState::inactive;
    if (state == eGameState::inactive)
    {
        return;
    }
}
