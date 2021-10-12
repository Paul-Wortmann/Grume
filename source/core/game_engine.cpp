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

#include "game_engine.hpp"

std::uint32_t cGameEngine::run(const std::uint32_t &_argc, char** _argv)
{
    // Clear the log and log version information.
    gLogClear();
    gLogWrite(LOG_INFO, std::string(__DATE__) + " " + std::string(__TIME__) + " - Starting Grume.", __FILE__, __LINE__, __FUNCTION__);
    std::string GRUMEVersion = std::to_string(GRUME_VERSION_MAJOR) + "." + std::to_string(GRUME_VERSION_MINOR) + "." + std::to_string(GRUME_VERSION_MICRO);
    gLogWrite(LOG_INFO, "Grume version: " + GRUMEVersion, __FILE__, __LINE__, __FUNCTION__);
    std::string GRUMECompile = __DATE__; GRUMECompile += " - "; GRUMECompile += __TIME__;
    gLogWrite(LOG_INFO, "Compile details: " + GRUMECompile, __FILE__, __LINE__, __FUNCTION__);

    // Initialize game subsystems
    uint32 status = initialize(_argc, _argv);
    
    // Enter the main loop
    while (m_state != eGameState::shutdown)
    {
        process();
    }
    terminate();
    return status;
}

std::uint32_t cGameEngine::initialize(const std::uint32_t &_argc, char** _argv)
{
    // Load the config file first
    gameConfig.load();

    // Process command line arguments
    for (uint32_t i = 1; i < _argc; i++)
    {
        std::string clString = _argv[i];
        if (clString.compare("--test") == 0)
        {
            std::cout << "Command line test arg passed" << std::endl;
        }
        else if (clString.compare("--help") == 0)
        {
            std::cout << "Command line help arg passed" << std::endl;
        }
    }

    // Load the game database list
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
        playerManager.setGraphicsEnginePointer(&graphicsEngine);
        mapManager.setPlayerPointer(&playerManager);
        graphicsEngine.setEntityHead(entityManager.getHead());
        graphicsEngine.setUIPointer(&uiManager);
        graphicsEngine.initializeUIComponents();
        physicsEngine.initialize();
        animationEngine.initialize();
        animationEngine.setEntityHead(entityManager.getHead());
        npcManager.setEntityHead(entityManager.getHead());
        mapManager.setAnimationPointer(&animationEngine);
        mapManager.setAudioPointer(&audioManager);
        mapManager.setGraphicsPointer(&graphicsEngine);
        entityManager.setMapPointer(mapManager.getHead());
        uiManager.initialize(&entityManager);
        uiManager.setWindowSize(graphicsEngine.getWindow_w(), graphicsEngine.getWindow_h());
        graphicsEngine.setLoadTextureID(entityManager.loadTexture("ui/loading_screen_001.png")->ID);
        graphicsEngine.setParticleTextureID(entityManager.loadTexture("default_d.png")->ID);
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

    // Start the game engine timer.
    timer.initialize();
    return status;
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
        
        if (m_state != eGameState::pause)
        {
            npcManager.process(dt);
            playerManager.process(dt);
            physicsEngine.process(dt);
        }
        
        uiManager.process(dt);
        graphicsEngine.process(dt);
        animationEngine.process(dt);
        mapManager.process(dt);
        audioManager.process(dt);
        entityManager.process(dt);
        
        // Ui management
        if (uiManager.getActiveWindowCount() < 2)
        {
            m_state = eGameState::active;
        }
        //std::cout << "Menu count: " << uiManager.getActiveWindowCount() << std::endl;

        // User input handeling
        // -----------------------------------------

        // Instant Quit - GLFW_KEY_ESCAPE
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_ESCAPE))
        {
            graphicsEngine.setWindowClosed();
        }

        // Pause game - GLFW_KEY_P
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_P))
        {
            graphicsEngine.setKeyReadyState(GLFW_KEY_P, false);
            m_state = (m_state == eGameState::pause) ? eGameState::active : eGameState::pause;
        }

        // Main menu - GLFW_KEY_F1
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_F1))
        {
            bool menuState = !uiManager.getMenuEnabled("main_menu");
            uiManager.setMenuEnabled("main_menu", menuState);
            graphicsEngine.setKeyReadyState(GLFW_KEY_F1, false);
            m_state = (menuState) ? eGameState::pause : eGameState::active;
            if (menuState == true)
            {
                uiManager.setMenuEnabled("inventory", false);
                uiManager.setMenuEnabled("character", false);
                uiManager.setMenuEnabled("skills", false);
            }
        }

        // Inventory - GLFW_KEY_I
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_I))
        {
            bool menuState = !uiManager.getMenuEnabled("inventory");
            uiManager.setMenuEnabled("inventory", menuState);
            graphicsEngine.setKeyReadyState(GLFW_KEY_I, false);
            m_state = (menuState) ? eGameState::pause : eGameState::active;
            if (menuState == true)
            {
                uiManager.setMenuEnabled("main_menu", false);
            }
        }

        // Inventory - GLFW_KEY_C
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_C))
        {
            bool menuState = !uiManager.getMenuEnabled("character");
            uiManager.setMenuEnabled("character", menuState);
            graphicsEngine.setKeyReadyState(GLFW_KEY_C, false);
            m_state = (menuState) ? eGameState::pause : eGameState::active;
            if (menuState == true)
            {
                uiManager.setMenuEnabled("main_menu", false);
            }
        }

        // Inventory - GLFW_KEY_S
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_S))
        {
            bool menuState = !uiManager.getMenuEnabled("skills");
            uiManager.setMenuEnabled("skills", menuState);
            graphicsEngine.setKeyReadyState(GLFW_KEY_S, false);
            m_state = (menuState) ? eGameState::pause : eGameState::active;
            if (menuState == true)
            {
                uiManager.setMenuEnabled("main_menu", false);
            }
        }

        // Screenshot - GLFW_KEY_F12
        if (graphicsEngine.getKeyReadyState(GLFW_KEY_F12))
        {
            entityManager.saveScreenShot("screenshot.png");
            graphicsEngine.setKeyReadyState(GLFW_KEY_F12, false);
        }

        // If mouse over UI
        if (uiManager.getMouseOverMenu())
        {
            // Use input
            if (graphicsEngine.getKeyReadyState(GLFW_MOUSE_BUTTON_LEFT))
            {
                graphicsEngine.setKeyReadyState(GLFW_MOUSE_BUTTON_LEFT, false);
                uiManager.setMouseClicked(true);
            }
        }
        else
        {
            // Use input
            if (graphicsEngine.getKeyState(GLFW_MOUSE_BUTTON_LEFT))
            {
                playerManager.setMouseClick(graphicsEngine.getMouseTerrainPosition());
            }
        }

        // If player has moved update camera and player light
        if ((m_state != eGameState::pause) && (playerManager.getMoved()))
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
