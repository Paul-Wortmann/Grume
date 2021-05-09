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

void cGameEngine::load(void)
{
    // Load the game startup file
    cXML xmlGameFile;
    xmlGameFile.load(std::string(FILE_PATH_DATA) + "game_001.txt");
    
    // Only contine if we can load the game startup file
    if (xmlGameFile.lineCount() > 0)
    {
        // Load the UI
        uiManager.load(xmlGameFile.getString("<ui>"));

        // Load the player
        playerManager.load(xmlGameFile.getString("<player>"));

        // Load the map
        mapManager.load(xmlGameFile.getString("<map>"));

        // Play the music defined in the previously loaded biome
        mapManager.playMusic();

        // Set player position acording to the map
        mapManager.resetPlayerPosition();

        // Set the player pointer, so NPCs can be aware of the player
        npcManager.setEntityPlayer(playerManager.getPlayerEntity());
        
        // Initialize entities
        graphicsEngine.initializeEntities();

    }
    // Clean up
    xmlGameFile.free();    
}
