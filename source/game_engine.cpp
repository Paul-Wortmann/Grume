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

// Stop the music that is currently playing
void cGameEngine::stopMusic(void)
{
    audioManager.stopSource(mapManager.getMusicSID());
}

// Load and play the music defined in the previously loaded biome
void cGameEngine::playMusic(void)
{
    if (mapManager.getMapMusic().length() > 3)
    {
        std::uint32_t sID = audioManager.newAudioSource();
        audioManager.setAudioSourcePosition(sID, 0.0f, 0.0f, 0.0f);
        std::uint32_t bID = audioManager.newAudioBuffer();
        audioManager.loadBufferOgg(bID, FILE_PATH_MUSIC + mapManager.getMapMusic());
        audioManager.setAudioBufferName(bID, mapManager.getMapMusic());
        audioManager.attachSourceBuffer(sID, bID);
        audioManager.playSource(sID);
        mapManager.setMusicSID(sID);
        mapManager.setMusicBID(bID);
    }
}

void cGameEngine::resetPlayerPosition(void)
{
    playerManager.setMapPointer(mapManager.getMapPointer());
    playerManager.resetStartTile();

    glm::vec3 playerPosition      = playerManager.getPosition();
    glm::vec3 cameraTarget        = graphicsEngine.getCameraTarget();
    glm::vec3 cameraPosition      = graphicsEngine.getCameraPosition();
    glm::vec3 playerLightPosition = graphicsEngine.getPlayerLightPosition();
    
    glm::vec3 delta = cameraPosition - cameraTarget;
    cameraTarget    = playerPosition;
    cameraPosition  = cameraTarget + delta;

    graphicsEngine.setPlayerLightPosition(glm::vec3(playerPosition.x, playerLightPosition.y, playerPosition.z));
    graphicsEngine.setCameraPosition(cameraPosition);
    graphicsEngine.setCameraTarget(cameraTarget);
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
        playerManager.initialize(&entityManager);
        playerManager.setTerrainHeight(-1.0f);
        uiManager.initialize(&entityManager);
        
        // load the starting map, player, and ui
        load();

        // TEST bat -- DELETE ME --
        m_entityBat = entityManager.load("npc/bat_1_001.txt");
        if (m_entityBat != nullptr)
        {
            m_entityBat->position += glm::vec3(-4.0, 0.0, 4.0);
            entityManager.updateModelMatrix(m_entityBat);
        }
        // TEST bat -- DELETE ME --
        
        // Play the music defined in the previously loaded biome
        playMusic();

        // Ater loading entities
        m_entityHead = entityManager.getHead();
        graphicsEngine.setEntityHead(entityManager.getHead());
        graphicsEngine.initializeEntities();
        graphicsEngine.setUIHead(uiManager.getHead());
        graphicsEngine.initializeUIComponents();
        physicsEngine.initialize();
        animationEngine.initialize();
        animationEngine.setEntityHead(entityManager.getHead());
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
        playerManager.process(dt);
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
            
            float32 deltaTmax = 4.0f; // We shoud base this off the current zoom level
            float32 deltaTmin = deltaTmax * graphicsEngine.getAspectRatio();
            
            float32 deltaX = tPlayerPosition.x - cameraTarget.x;
            float32 deltaZ = tPlayerPosition.z - cameraTarget.z;

            if (deltaX > deltaTmax)
            {
                deltaX -= deltaTmax;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x + deltaX, cameraPosition.y, cameraPosition.z));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x + deltaX, cameraTarget.y, cameraTarget.z));
            }
            else if (deltaX < -deltaTmin)
            {
                deltaX += deltaTmin;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x + deltaX, cameraPosition.y, cameraPosition.z));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x + deltaX, cameraTarget.y, cameraTarget.z));
            }
            if (deltaZ > deltaTmax)
            {
                deltaZ -= deltaTmax;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z + deltaZ));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x, cameraTarget.y, cameraTarget.z + deltaZ));
            }
            else if (deltaZ < -deltaTmin)
            {
                deltaZ += deltaTmin;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z + deltaZ));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x, cameraTarget.y, cameraTarget.z + deltaZ));
            }
        }



// Level loading
        if (graphicsEngine.getKeyState(GLFW_KEY_1))
        {
            stopMusic();
            mapManager.load("dungeon_001.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
        if (graphicsEngine.getKeyState(GLFW_KEY_2))
        {
            stopMusic();
            mapManager.load("dungeon_002.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
        if (graphicsEngine.getKeyState(GLFW_KEY_3))
        {
            stopMusic();
            mapManager.load("dungeon_003.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
        if (graphicsEngine.getKeyState(GLFW_KEY_4))
        {
            stopMusic();
            mapManager.load("dungeon_004.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
        if (graphicsEngine.getKeyState(GLFW_KEY_5))
        {
            stopMusic();
            mapManager.load("dungeon_005.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
        if (graphicsEngine.getKeyState(GLFW_KEY_6))
        {
            stopMusic();
            mapManager.load("dungeon_003g.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
        if (graphicsEngine.getKeyState(GLFW_KEY_7))
        {
            stopMusic();
            mapManager.load("town_000.txt");
            resetPlayerPosition();
            graphicsEngine.initializeEntities();
            playMusic();
        }
/*
        if (graphicsEngine.getKeyState(GLFW_MOUSE_BUTTON_LEFT))
        {
            glm::vec3 destinationPosition = graphicsEngine.getMouseTerrainPosition();
            destinationPosition.y -= 1.0f;
            uint32 destinationTile = playerManager.positionToTile(destinationPosition);

            std::cout << "Current tile: " << playerManager.getCurrentTile() << std::endl;
            //std::cout << "Pathing to tile 17..." << std::endl;
            playerManager.setDestinationTile(destinationTile);
            //std::cout << "Pathing done." << std::endl;
            std::cout << "Pathing length: " << playerManager.getPathLength() << std::endl;
            std::cout << "Path: ";
            sMap* tMap = mapManager.getMapPointer();
            for (uint32 i = 0; i < playerManager.getPathLength(); ++i)
            {
                std::cout << playerManager.getPath(i) << " ";
                tMap->tile[playerManager.getPath(i)].object = 6;
            }
            std::cout << std::endl;
                mapManager.applyObjects(tMap);
                graphicsEngine.initializeEntities();
            
            // place objects on path as a visual test
        }


        // player movement
        bool player_moved = false;
        glm::vec3 tPlayerPosition = playerManager.getPosition();
        glm::vec3 tPlayerRotation = playerManager.getRotation();
        glm::vec3 tPlayerLightPosition = graphicsEngine.getPlayerLightPosition();
        
        if (graphicsEngine.getKeyState(GLFW_KEY_W))
        {
            player_moved = true;
            tPlayerPosition += glm::vec3(0.0f, 0.0f, -(playerManager.getMovementSpeed()));
            tPlayerRotation = glm::vec3(tPlayerRotation.x, tPlayerRotation.y, DTOR_180);
            tPlayerLightPosition += glm::vec3(0.0f, 0.0f, -(playerManager.getMovementSpeed()));
        }

        if (graphicsEngine.getKeyState(GLFW_KEY_S))
        {
            player_moved = true;
            tPlayerPosition += glm::vec3(0.0f, 0.0f, (playerManager.getMovementSpeed()));
            tPlayerRotation = glm::vec3(tPlayerRotation.x, tPlayerRotation.y, DTOR_0);
            tPlayerLightPosition += glm::vec3(0.0f, 0.0f, (playerManager.getMovementSpeed()));
        }

        if (graphicsEngine.getKeyState(GLFW_KEY_A))
        {
            player_moved = true;
            tPlayerPosition += glm::vec3(-(playerManager.getMovementSpeed()), 0.0f, 0.0f);
            tPlayerRotation = glm::vec3(tPlayerRotation.x, tPlayerRotation.y, DTOR_270);
            tPlayerLightPosition += glm::vec3(-(playerManager.getMovementSpeed()), 0.0f, 0.0f);
        }

        if (graphicsEngine.getKeyState(GLFW_KEY_D))
        {
            player_moved = true;
            tPlayerPosition += glm::vec3((playerManager.getMovementSpeed()), 0.0f, 0.0f);
            tPlayerRotation = glm::vec3(tPlayerRotation.x, tPlayerRotation.y, DTOR_90);
            tPlayerLightPosition += glm::vec3((playerManager.getMovementSpeed()), 0.0f, 0.0f);
        }

        if (player_moved)
        {
            playerManager.setPosition(tPlayerPosition);
            playerManager.setRotation(tPlayerRotation);
            graphicsEngine.setPlayerLightPosition(tPlayerLightPosition);

            glm::vec3 cameraTarget = graphicsEngine.getCameraTarget();
            glm::vec3 cameraPosition = graphicsEngine.getCameraPosition();
            
            float32 deltaTmax = 4.0f; // We shoud base this off the current zoom level
            float32 deltaTmin = deltaTmax * graphicsEngine.getAspectRatio();
            
            float32 deltaX = tPlayerPosition.x - cameraTarget.x;
            float32 deltaZ = tPlayerPosition.z - cameraTarget.z;

            if (deltaX > deltaTmax)
            {
                deltaX -= deltaTmax;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x + deltaX, cameraPosition.y, cameraPosition.z));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x + deltaX, cameraTarget.y, cameraTarget.z));
            }
            else if (deltaX < -deltaTmin)
            {
                deltaX += deltaTmin;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x + deltaX, cameraPosition.y, cameraPosition.z));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x + deltaX, cameraTarget.y, cameraTarget.z));
            }
            if (deltaZ > deltaTmax)
            {
                deltaZ -= deltaTmax;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z + deltaZ));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x, cameraTarget.y, cameraTarget.z + deltaZ));
            }
            else if (deltaZ < -deltaTmin)
            {
                deltaZ += deltaTmin;
                graphicsEngine.setCameraPosition(glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z + deltaZ));
                graphicsEngine.setCameraTarget(glm::vec3(cameraTarget.x, cameraTarget.y, cameraTarget.z + deltaZ));
            }


        glm::vec3 pos = playerManager.getPosition();
        std::cout << "Position: " << pos.x << " " << pos.y << " " << pos.z << std::endl;
        std::cout << "Tile: " << playerManager.getCurrentTile() << std::endl;
        }
*/

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
