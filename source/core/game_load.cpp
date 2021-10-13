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
    // Clean up
    xmlGameFile.free();    
}


void cGameEngine::load(const std::uint32_t &_slotNum)
{

//        mapManager.load(xmlGameFile.getString("<map>"));
}

/*
<?xml version = "1.0" encoding = "UTF-8" ?>
<save_file>

    <information>
        <current_map>test_1_town_1_001</current_map>
        <current_position>526</current_position>
    </information>

    <player>
        <level>0</level>
        <experience>0</experience>
    </player>

    <quest>
        <001>0</001>
    </quest>

    <map_data>
        <map>test_1_town_1_001 1634141856</map>
    </map_data>

</save_file>
*/
