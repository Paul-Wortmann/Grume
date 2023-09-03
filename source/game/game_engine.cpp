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

std::uint32_t cGameEngine::initialize(const std::uint32_t &_argc, char** _argv)
{
    // return value
    std::uint32_t return_value = EXIT_SUCCESS;

    // Clear the log
    gLogClear();

    // Log time and application details.
    std::chrono::system_clock::time_point currentSystemTime = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentSystemTime);

    gLogWrite(LOG_INFO, std::string(std::ctime(&currentTime)) + " " + std::string(__TIME__) + " - Starting Grume.", __FILE__, __LINE__, __FUNCTION__);
    std::string GRUMEVersion = std::to_string(GRUME_VERSION_MAJOR) + "." + std::to_string(GRUME_VERSION_MINOR) + "." + std::to_string(GRUME_VERSION_MICRO);
    gLogWrite(LOG_INFO, "Grume version: " + GRUMEVersion, __FILE__, __LINE__, __FUNCTION__);
    std::string GRUMECompile = __DATE__; GRUMECompile += " - "; GRUMECompile += __TIME__;
    gLogWrite(LOG_INFO, "Compile details: " + GRUMECompile, __FILE__, __LINE__, __FUNCTION__);

    gLogWrite(LOG_INFO, "Home path: " + std::string(std::getenv("HOME")), __FILE__, __LINE__, __FUNCTION__);

    // Load the configuration file
    m_gameConfig.load();

    // Process command line arguments
    for (std::uint32_t i = 1; i < _argc; i++)
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

    // Apply pre-initialization configuration settings
    m_graphicsEngine.setWireframeRender(m_gameConfig.m_wireframeRender);
    m_graphicsEngine.setBasicRenderPath(m_gameConfig.m_basicRenderer);
    m_graphicsEngine.setDisplay(m_gameConfig.m_resolution_x, m_gameConfig.m_resolution_y, m_gameConfig.m_fullscreen);

    //Initialize IO
    m_IOManager.initialize();

    // Load database and initialize resource management
    return_value = (return_value == EXIT_SUCCESS) ? m_databaseManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_resourceManager.initialize() : return_value;

    // Initialize sub-systems
    return_value = (return_value == EXIT_SUCCESS) ? m_resourceManager.initializeFont() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_uiManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_graphicsEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_entityManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_lootManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_mapManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_playerManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_audioEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_particleEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_physicsEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_animationEngine.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_npcManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_objectManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_questManager.initialize() : return_value;
    return_value = (return_value == EXIT_SUCCESS) ? m_networkEngine.initialize() : return_value;

    // Apply post-initialization configuration settings
    m_audioEngine.setVolumeMaster(m_gameConfig.m_volume_master);
    m_audioEngine.setVolumeMusic(m_gameConfig.m_volume_music);
    m_audioEngine.setVolumeSound(m_gameConfig.m_volume_sfx);

    // Seed the random number generator
    std::uint32_t gameSeed = 0;
    gRandSeed(gameSeed);

    // Set inter-system connections
    m_entityManager.setAudioEngine(&m_audioEngine);
    m_entityManager.setDatabaseManager(&m_databaseManager);
    m_entityManager.setResourceManager(&m_resourceManager);
    m_entityManager.setMapPointer(m_mapManager.getMapPointer());
    m_animationEngine.setEntityHead(m_entityManager.getHead());
    m_graphicsEngine.setEntityHead(m_entityManager.getHead());
    m_graphicsEngine.setGameConfigPointer(&m_gameConfig);
    m_graphicsEngine.setIOPointer(m_IOManager.getIOPointer());
    m_graphicsEngine.setUIPointer(&m_uiManager);
    m_graphicsEngine.setPlayerActionBarPointer(m_playerManager.getPlayerActionBar());
    m_graphicsEngine.setPlayerEquipmentPointer(m_playerManager.getPlayerEquipment());
    m_graphicsEngine.setPlayerInventoryPointer(m_playerManager.getPlayerInventory());
    m_graphicsEngine.setPlayerVendorPointer(m_playerManager.getPlayerVendor());
    m_graphicsEngine.setPlayerWaypointsPointer(m_playerManager.getPlayerWaypoints());
    m_graphicsEngine.setResourceManagerPointer(&m_resourceManager);
    m_graphicsEngine.setMapPointer(m_mapManager.getMapPointer());
    m_physicsEngine.setIOPointer(m_IOManager.getIOPointer());
    m_physicsEngine.setEntityHead(m_entityManager.getHead());
    m_physicsEngine.setEntityManager(&m_entityManager);
    m_physicsEngine.setMapPointer(m_mapManager.getMapPointer());
    m_particleEngine.setEntityHead(m_entityManager.getHead());
    m_particleEngine.setEntityManager(&m_entityManager);
    m_particleEngine.setMapPointer(m_mapManager.getMapPointer());
    m_particleEngine.setDatabaseManager(&m_databaseManager);
    m_particleEngine.setGraphicsEngine(&m_graphicsEngine);
    m_mapManager.setAudioEngine(&m_audioEngine);
    m_mapManager.setEntityManager(&m_entityManager);
    m_mapManager.setDatabaseManager(&m_databaseManager);
    m_mapManager.setGraphicsEngine(&m_graphicsEngine);
    m_mapManager.setAnimationEngine(&m_animationEngine);
    m_mapManager.setPlayerManager(&m_playerManager);
    m_mapManager.setresourceManager(&m_resourceManager);
    m_mapManager.setQuestManager(&m_questManager);
    m_npcManager.setAudioEngine(&m_audioEngine);
    m_npcManager.setGraphicsEnginePointer(&m_graphicsEngine);
    m_npcManager.setEntityHead(m_entityManager.getHead());
    m_npcManager.setEntityManagerPointer(&m_entityManager);
    m_npcManager.setDatabaseManagerPointer(&m_databaseManager);
    m_npcManager.setLootManagerPointer(&m_lootManager);
    m_npcManager.setParticleEnginePointer(&m_particleEngine);
    m_npcManager.setResourceManagerPointer(&m_resourceManager);
    m_npcManager.setQuestManager(&m_questManager);
    m_npcManager.setIOPointer(m_IOManager.getIOPointer());
    m_objectManager.setAudioEngine(&m_audioEngine);
    m_objectManager.setEntityHead(m_entityManager.getHead());
    m_objectManager.setEntityManagerPointer(&m_entityManager);
    m_objectManager.setLootManagerPointer(&m_lootManager);
    m_objectManager.setParticleEnginePointer(&m_particleEngine);
    m_objectManager.setPlayerManager(&m_playerManager);
    m_objectManager.setResourceManagerPointer(&m_resourceManager);
    m_objectManager.setIOPointer(m_IOManager.getIOPointer());
    m_playerManager.setAudioEngine(&m_audioEngine);
    m_playerManager.setEntityManager(&m_entityManager);
    m_playerManager.setDatabaseManager(&m_databaseManager);
    m_playerManager.setMapPointer(m_mapManager.getMapPointer());
    m_playerManager.setUIManager(&m_uiManager);
    m_playerManager.setResourceManagerPointer(&m_resourceManager);
    m_uiManager.setIOPointer(m_IOManager.getIOPointer());
    m_uiManager.setAudioEngine(&m_audioEngine);
    m_uiManager.setDatabaseManager(&m_databaseManager);
    m_uiManager.setResourceManager(&m_resourceManager);
    m_uiManager.setWindowSize(m_graphicsEngine.getWindow_w(), m_graphicsEngine.getWindow_h());
    m_uiManager.setTextGold(0);
    m_uiManager.setTextStrength(0);
    m_uiManager.setTextDexterity(0);
    m_uiManager.setTextEnergy(0);
    m_uiManager.setTextVitality(0);
    m_uiManager.setTextPoints(0);

    // Display loading screen
    m_graphicsEngine.process(0);

    // Setup sub-systems
    if (return_value == EXIT_SUCCESS)
    {

        // Load data
        //return_value = m_game_load_ui();
        return_value = m_game_load();
    }

    // set menu component state
    m_uiManager.setMenuComponentActivated(eComponentFunction::componentFunctionFullscreenModified, m_gameConfig.m_fullscreen);
    m_uiManager.setMenuComponentActivated(eComponentFunction::componentFunctionLightingModified, !m_gameConfig.m_basicRenderer);

    // Start the game engine timer.
    m_timer.initialize();

    // Set engine state
    m_uiManager.setMenuEnabled(eMenuType::menuTypeActionBar, false);
    m_uiManager.setMenuEnabled(eMenuType::menuTypeMain, true);
    m_uiManager.setMenuComponentEnabled(eComponentFunction::componentFunctionGameSave ,false);
    m_engineState = (return_value == EXIT_SUCCESS) ? eEngineState::engineStateMenu : eEngineState::engineStateTerm;
    return return_value;
}

void cGameEngine::terminate(void)
{
    // save the map
    //m_mapManager.save("map_data.txt");

    // Save the configuration file
    m_gameConfig.m_volume_master = m_audioEngine.getVolumeMaster();
    m_gameConfig.m_volume_music  = m_audioEngine.getVolumeMusic();
    m_gameConfig.m_volume_sfx    = m_audioEngine.getVolumeSound();
    m_gameConfig.save();

    // Terminate systems
    m_graphicsEngine.terminate();
    m_networkEngine.terminate();
    m_audioEngine.terminate();
    m_animationEngine.terminate();
    m_particleEngine.terminate();
    m_physicsEngine.terminate();

    // Terminate managers
    m_questManager.terminate();
    m_npcManager.terminate();
    m_objectManager.terminate();
    m_lootManager.terminate();
    m_resourceManager.terminate();
    m_databaseManager.terminate();
    m_playerManager.terminate();
    m_mapManager.terminate();
    m_uiManager.terminate();
    m_entityManager.terminate();
    m_IOManager.terminate();

    // Set engine state
    m_engineState = eEngineState::engineStateNone;
}

void cGameEngine::process(void)
{
    m_timer.process(); // Called first in the main loop

    // Process if timer ready
    if (m_timer.ready())
    {
        // Get the delta time
        std::int64_t dt = m_timer.get_frameTime();

        // Process
        if ((m_engineState == eEngineState::engineStateProc) || (m_engineState == eEngineState::engineStatePause))
            m_process_play(dt);
        else if (m_engineState == eEngineState::engineStateMenu)
            m_process_menu(dt);
        else if (m_engineState == eEngineState::engineStateProc)
            m_process_editor(dt);

        // -----------------------------------------
        // Advance the timer
        m_timer.advance_dt();
        //std::cout << "Frame time: " << m_timer.get_frameTime() << std::endl;
    }
}

std::uint32_t cGameEngine::run(const std::uint32_t &_argc, char** _argv)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    // Initialize
    m_engineState = eEngineState::engineStateInit;
    return_value = initialize(_argc, _argv);

    // Process
    while (m_engineState != eEngineState::engineStateTerm)
    {
        process();
    }

    // Terminate
    terminate();
    return return_value;
}
