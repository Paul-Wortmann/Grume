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

void cGameEngine::run(void)
{
    // Clear the log and log version information.
    gLogClear();
    gLogWrite(LOG_INFO, std::string(__DATE__) + " " + std::string(__TIME__) + " - Starting Frost and Flame.", __FILE__, __LINE__, __FUNCTION__);
    std::string FNFVersion = std::to_string(FNF_VERSION_MAJOR) + "." + std::to_string(FNF_VERSION_MINOR) + "." + std::to_string(FNF_VERSION_MICRO);
    gLogWrite(LOG_INFO, "Frost and Flame version: " + FNFVersion, __FILE__, __LINE__, __FUNCTION__);

    // Start the game engine timer.
    timer.initialize();

    initialize();
    while (m_state == eGameState::active)
    {
        process();
    }
    terminate();
}

void cGameEngine::initialize(void)
{
    uint32 status = graphicsEngine.initialize(); // This should be initialized first
    if (status == EXIT_SUCCESS)
    {
        // Before loading entities
        entityManager.initialize();
        audioManager.initialize();
        audioManager.setVolumeMaster(0.1f);
        mapManager.initialize(&entityManager);
        npcManager.initialize(&entityManager);
        playerManager.initialize(&entityManager);
        mapManager.setPlayerPointer(&playerManager);
        graphicsEngine.setEntityHead(entityManager.getHead());
        graphicsEngine.setUIHead(uiManager.getHead());
        graphicsEngine.initializeUIComponents();
        physicsEngine.initialize();
        animationEngine.initialize();
        animationEngine.setEntityHead(entityManager.getHead());
        npcManager.setEntityHead(entityManager.getHead());
        mapManager.setGraphicsPointer(&graphicsEngine);
        mapManager.setAudioPointer(&audioManager);
        playerManager.setTerrainHeight(-1.0f);
        uiManager.initialize(&entityManager);
        

        // TEST bat -- DELETE ME --
        m_entityBat = entityManager.load("npc/bat_1_001.txt");
        if (m_entityBat != nullptr)
        {
            m_entityBat->position += glm::vec3(-4.0, 0.0, 4.0);
            entityManager.updateModelMatrix(m_entityBat);
        }
        // TEST bat -- DELETE ME --


        // load the game startup file
        load();

        // Ater loading entities
        m_entityHead = entityManager.getHead();
        m_state = eGameState::active;
    }
    else
    {
        m_state = eGameState::shutdown;
    }
}

void cGameEngine::terminate(void)
{
    audioManager.terminate();
    animationEngine.terminate();
    uiManager.terminate();
    npcManager.terminate();
    playerManager.terminate();
    physicsEngine.terminate();
    graphicsEngine.terminate();
    mapManager.terminate();
    entityManager.terminate(); // Terminate the entity manager last
}

void cGameEngine::process(void)
{
    timer.process(); // Called first in the main loop

    // Process if timer ready
    if (timer.ready())
    {
        // Get the delta time
        double dt = timer.get_frameTime();

        // System processes
        // -----------------------------------------
        graphicsEngine.process(dt);
        animationEngine.process(dt);
        npcManager.process(dt);
        playerManager.process(dt);
        mapManager.process(dt);
        physicsEngine.process(dt);
        audioManager.process(dt);

        // Player movement
        if (graphicsEngine.getKeyState(GLFW_MOUSE_BUTTON_LEFT))
        {
            playerManager.moveTo(graphicsEngine.getMouseTerrainPosition());
        }
        
        // If player has moved update camera and player light
        if (playerManager.getMoved())
        {
            // Update player light
            glm::vec3 tPlayerPosition = playerManager.getPosition();
            glm::vec3 tPlayerLightPosition = graphicsEngine.getPlayerLightPosition();
            tPlayerLightPosition +=  playerManager.getMoveDelta();
            graphicsEngine.setPlayerLightPosition(tPlayerLightPosition);
            
            // Update camera
            glm::vec3 cameraTarget = graphicsEngine.getCameraTarget();
            glm::vec3 cameraPosition = graphicsEngine.getCameraPosition();
            
            float32 deltaX = tPlayerPosition.x - cameraTarget.x;
            float32 deltaZ = tPlayerPosition.z - cameraTarget.z;

            // Camera follow player
            cameraPosition.x += deltaX;
            cameraPosition.z += deltaZ;
            cameraTarget.x += deltaX;
            cameraTarget.z += deltaZ;
            graphicsEngine.setCameraPosition(glm::vec3(cameraPosition));
            graphicsEngine.setCameraTarget(glm::vec3(cameraTarget));
        }

        // !! This bat is only here for TESTING !!
        m_entityBat->position = graphicsEngine.getMouseTerrainPosition();
        m_entityBat->position = glm::vec3(m_entityBat->position.x, m_entityBat->position.y - 1.0f, m_entityBat->position.z);
        entityManager.updateModelMatrix(m_entityBat);


        // -----------------------------------------
        // Advance the timer
        timer.advance_dt();
        //std::cout << "Frame time: " << timer.get_frameTime() << std::endl;
    }

    // Check for shutdown events
    if (graphicsEngine.windowClosed())
    {
        m_state = eGameState::shutdown;
    }
}
