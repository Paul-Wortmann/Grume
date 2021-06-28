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

    // Initialize game subsystems
    initialize();
    
    // Enter the main loop
    while (m_state == eGameState::active)
    {
        process();
    }
    terminate();
}

void cGameEngine::initialize(void)
{
    // Load the config file first
    gameConfig.load();
    gameDatabase.load();
    
    graphicsEngine.setDisplay(gameConfig.m_resolution_x, gameConfig.m_resolution_y, gameConfig.m_fullscreen);

    uint32 status = graphicsEngine.initialize(); // This should be initialized first
    if (status == EXIT_SUCCESS)
    {
        // Before loading entities
        audioManager.initialize();
        audioManager.setVolumeMaster(gameConfig.m_volume_master / 100.0f);
        entityManager.initialize();
        entityManager.setAudioPointer(&audioManager);
        entityManager.setDatabasePointer(&gameDatabase);
        mapManager.initialize(&entityManager);
        mapManager.setDatabasePointer(&gameDatabase);
        npcManager.initialize(&entityManager);
        npcManager.setDatabasePointer(&gameDatabase);
        playerManager.initialize(&entityManager);
        playerManager.setDatabasePointer(&gameDatabase);
        mapManager.setPlayerPointer(&playerManager);
        graphicsEngine.setEntityHead(entityManager.getHead());
        graphicsEngine.setUIHead(uiManager.getHead());
        graphicsEngine.initializeUIComponents();
        physicsEngine.initialize();
        animationEngine.initialize();
        animationEngine.setEntityHead(entityManager.getHead());
        npcManager.setEntityHead(entityManager.getHead());
        mapManager.setAnimationPointer(&animationEngine);
        mapManager.setAudioPointer(&audioManager);
        mapManager.setGraphicsPointer(&graphicsEngine);
        uiManager.initialize(&entityManager);
        graphicsEngine.setLoadTextureID(entityManager.loadTexture("ui/loading_screen_001.png")->ID);
        graphicsEngine.process(0);

        // load the game startup file
        load();

        // Ater loading entities
        m_entityHead = entityManager.getHead();
        m_state = eGameState::active;
        playerManager.setTerrainHeight(-1.0f);
        graphicsEngine.setLoading(false);
    }
    else
    {
        m_state = eGameState::shutdown;
    }
}

void cGameEngine::terminate(void)
{
    // Save the config file first
    gameConfig.save();

    // Terminate subsystems
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
        graphicsEngine.setLoading(mapManager.getLoading());
        
        graphicsEngine.process(dt);
        animationEngine.process(dt);
        npcManager.process(dt);
        playerManager.process(dt);
        mapManager.process(dt);
        physicsEngine.process(dt);
        audioManager.process(dt);
        entityManager.process(dt);

        // Screenshot - GLFW_KEY_F12
        if (graphicsEngine.getKeyState(GLFW_KEY_F12))
        {
            entityManager.saveScreenShot("screenshot.png");
        }
        
        // Use input
        if (graphicsEngine.getKeyState(GLFW_MOUSE_BUTTON_LEFT))
        {
            // If mouse over UI
            
            // Else:
            playerManager.setMouseClick(graphicsEngine.getMouseTerrainPosition());
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
