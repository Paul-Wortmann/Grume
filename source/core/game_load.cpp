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

void cGameEngine::load(void)
{
    // Load the game startup file
    cXML xmlGameFile;
    std::string fileName = std::string("game_001.txt");
    xmlGameFile.load(std::string(FILE_PATH_DATA) + fileName);
    
    // Only contine if we can load the game startup file
    if (xmlGameFile.lineCount() > 0)
    {
        // Load the UI
        uiManager.load(xmlGameFile.getString("<ui>"));

        // Load the player
        playerManager.load(xmlGameFile.getString("<player>"));

        // Load the map
        mapManager.load(xmlGameFile.getString("<map>"));

        // Pass the map pointer to the player manager
        playerManager.setMapPointer(mapManager.getMapPointer());

        // Play the music defined in the previously loaded biome
        mapManager.playMusic();

        // Set player position acording to the map
        mapManager.resetPlayerPosition();

        // Set the player pointer, so NPCs can be aware of the player
        npcManager.setEntityPlayer(playerManager.getPlayerEntity());

        // Set the map pointer
        npcManager.setMapPointer(mapManager.getMapPointer());
        
        // Initialize entities
        graphicsEngine.initializeEntities();
        animationEngine.initializeEntities();
        
    }
    else
    {
        // Log error, failed to load file
        gLogWrite(LOG_ERROR, "Failed to load file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    // Clean up
    xmlGameFile.free();    
}


void cGameEngine::load(const std::uint32_t &_slotNum)
{
    // Load the game startup file
    cXML xmlSaveGameFile;
    std::string fileName = std::string("save_00") + std::to_string(_slotNum) + std::string(".txt");
    xmlSaveGameFile.load(std::string(FILE_PATH_SAVE) + fileName);
    
    // Only contine if we can load the game startup file
    if (xmlSaveGameFile.lineCount() > 0)
    {
        // Information
        std::string   currentMap      = xmlSaveGameFile.getString("<current_map>");
        std::uint32_t currentPosition = xmlSaveGameFile.getInteger("<current_position>");

        // Player
        
        // Quest
        
        // Map data
        std::uint32_t mapSeedCount = xmlSaveGameFile.getInstanceCount("<map>");
        for (std::uint32_t i = 0; i < mapSeedCount; ++i)
        {
            std::string tmapData = xmlSaveGameFile.getString("<map>", 1 + i);
            tmapData += "    ";
            std::uint64_t tmapDataLength = tmapData.length();
            std::string   tmapName       = "";
            std::uint32_t tmapSeed       = 0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tmapDataLength > 6)
            {
                for (std::uint64_t j = 0; j < tmapDataLength; ++j)
                {
                    if (tmapData[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tmapName = tString;
                        }
                        else if (tStringNum == 1)
                        {
                            tmapSeed = std::stoi(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tmapData[j];
                    }
                }
                mapManager.mapList[tmapName] = tmapSeed;
            }
        }
        
        // Loading screen
        //mapManager.m_loadRequest = true;

        // Load map
        mapManager.load(currentMap + ".txt");
        
        // Database reference? to load map and biome is needed

        playerManager.setCurrentTile(currentPosition);
        mapManager.setPlayerStartTile(currentPosition);
        mapManager.resetPlayerPosition();

        // Play the music defined in the previously loaded biome
        mapManager.stopMusic();
        mapManager.playMusic();

        // Initialize systems
        graphicsEngine.initializeEntities();
        animationEngine.initializeEntities();
        //m_loadRequest = false;

        
    }
    else
    {
        // Log error, failed to load file
        gLogWrite(LOG_ERROR, "Failed to load file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    // Clean up
    xmlSaveGameFile.free();    
}
