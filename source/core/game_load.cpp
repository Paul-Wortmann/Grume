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
    string fileName = string("game_001.txt");
    xmlGameFile.load(string(FILE_PATH_DATA) + fileName);
    
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


void cGameEngine::load(const uint32 &_slotNum)
{
    // Load the game startup file
    cXML xmlSaveGameFile;
    string fileName = string("save_00") + std::to_string(_slotNum) + string(".txt");
    xmlSaveGameFile.load(string(FILE_PATH_SAVE) + fileName);
    
    // Only contine if we can load the game startup file
    if (xmlSaveGameFile.lineCount() > 0)
    {
        // Information
        string   currentMap      = xmlSaveGameFile.getString("<current_map>");
        uint32 currentPosition = xmlSaveGameFile.getInteger("<current_position>");
        float         currentRotation = xmlSaveGameFile.getFloat("<current_rotation>");
        
        // Player
        sEntity* player = playerManager.getPlayerEntity();
        
        // Experience + level
        player->character->level.current = xmlSaveGameFile.getInteger("<level_current>");
        player->character->level.exp     = xmlSaveGameFile.getInteger64("<exp_current>");
        player->character->level.expNext = xmlSaveGameFile.getInteger64("<exp_next>");
        
        // Health
        player->character->attributes.health.current = xmlSaveGameFile.getInteger("<health_current>");
        player->character->attributes.health.max     = xmlSaveGameFile.getInteger("<health_max>");
        player->character->attributes.health.regen   = xmlSaveGameFile.getFloat("<health_regen>");

        // Mana
        player->character->attributes.mana.current = xmlSaveGameFile.getInteger("<mana_current>");
        player->character->attributes.mana.max     = xmlSaveGameFile.getInteger("<mana_max>");
        player->character->attributes.mana.regen   = xmlSaveGameFile.getFloat("<mana_regen>");

        // Damage
        player->character->attributes.damagePhysical.base           = xmlSaveGameFile.getFloat("<damage_physical_base>");
        player->character->attributes.damagePhysical.critChancev    = xmlSaveGameFile.getFloat("<damage_physical_crit_chance>");
        player->character->attributes.damagePhysical.critMultiplier = xmlSaveGameFile.getFloat("<damage_physical_crit_multiplier>");
        player->character->attributes.damageFire.base               = xmlSaveGameFile.getFloat("<damage_fire_base>");
        player->character->attributes.damageFire.critChancev        = xmlSaveGameFile.getFloat("<damage_fire_crit_chance>");
        player->character->attributes.damageFire.critMultiplier     = xmlSaveGameFile.getFloat("<damage_fire_crit_multiplier>");
        player->character->attributes.damageFrost.base              = xmlSaveGameFile.getFloat("<damage_frost_base>");
        player->character->attributes.damageFrost.critChancev       = xmlSaveGameFile.getFloat("<damage_frost_crit_chance>");
        player->character->attributes.damageFrost.critMultiplier    = xmlSaveGameFile.getFloat("<damage_frost_crit_multiplier>");
        
        // Armor
        player->character->attributes.armorPhysical.base            = xmlSaveGameFile.getFloat("<armor_physical_base>");
        
        // Resistance
        player->character->attributes.resistanceFire.base           = xmlSaveGameFile.getFloat("<resistance_fire_base>");
        player->character->attributes.resistanceFrost.base          = xmlSaveGameFile.getFloat("<resistance_frost_base>");

        // Quest
        
        // Map data
        mapManager.mapList.clear();
        uint32 mapSeedCount = xmlSaveGameFile.getInstanceCount("<map>");
        for (uint32 i = 0; i < mapSeedCount; ++i)
        {
            string tmapData = xmlSaveGameFile.getString("<map>", 1 + i);
            tmapData += "    ";
            uint64 tmapDataLength = tmapData.length();
            string tmapName       = "";
            uint32 tmapSeed       = 0;
            uint32 tStringNum = 0;
            string tString = "";
            if (tmapDataLength > 6)
            {
                for (uint64 j = 0; j < tmapDataLength; ++j)
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
        
        // Load map
        mapManager.load(currentMap + ".txt");
        
        // Database reference? to load map and biome is needed

        mapManager.setPlayerStartTile(currentPosition);
        mapManager.setPlayerStartDirection(currentRotation);
        mapManager.resetPlayerPosition();
        //playerManager.setCurrentTile(currentPosition);
        //playerManager.setRotation(currentRotation);

        // Play the music defined in the previously loaded biome
        mapManager.stopMusic();
        mapManager.playMusic();

        // Initialize systems
        graphicsEngine.initializeEntities();
        animationEngine.initializeEntities();

    }
    else
    {
        // Log error, failed to load file
        gLogWrite(LOG_ERROR, "Failed to load file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    // Clean up
    xmlSaveGameFile.free();
}
