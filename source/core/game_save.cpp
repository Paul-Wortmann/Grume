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

void cGameEngine::game_save(const uint32 &_slotNum)
{
    // Create a new save file, or overwrite its content if it does not exist
    string   fileName = string("save_00") + std::to_string(_slotNum) + string(".txt");
    std::ofstream saveFile;
    saveFile.open (FILE_PATH_SAVE + fileName, std::ios::trunc); 

    // Only proceed if there is map data
    if (saveFile.is_open())
    {
        uint32 indent_width = 4;
        uint32 indent_level = 0;
        
        // XML information
        saveFile << "<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;

        // Save tag open
        saveFile << "<save_file>" << std::endl;
        saveFile << std::endl;
        
        // Information
        indent_level++;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<information>" << std::endl;
        indent_level++;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<current_map>" << mapManager.getCurrentMapName() << "</current_map>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<current_position>" << playerManager.getCurrentTile() << "</current_position>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<current_rotation>" << playerManager.getRotation().z << "</current_rotation>" << std::endl;
        indent_level--;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "</information>" << std::endl;
        saveFile << std::endl;
        
        // Player
        sEntity* player = playerManager.getPlayerEntity();
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<player>" << std::endl;
        indent_level++;
        
        // Level and experience
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<level_current>" << player->character->level.current << "</level_current>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<exp_current>" << player->character->level.exp << "</exp_current>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<exp_next>" << player->character->level.expNext << "</exp_next>" << std::endl;

        // Health
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<health_current>" << player->character->attributes.health.current << "</health_current>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<health_max>" << player->character->attributes.health.max << "</health_max>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<health_regen>" << player->character->attributes.health.regen << "</health_regen>" << std::endl;
        
        // Mana
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<mana_current>" << player->character->attributes.mana.current << "</mana_current>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<mana_max>" << player->character->attributes.mana.max << "</mana_max>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<mana_regen>" << player->character->attributes.mana.regen << "</mana_regen>" << std::endl;

        // Damage
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_physical_base>" << player->character->attributes.damagePhysical.base << "</damage_physical_base>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_physical_crit_chance>" << player->character->attributes.damagePhysical.critChancev << "</damage_physical_crit_chance>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_physical_crit_multiplier>" << player->character->attributes.damagePhysical.critMultiplier << "</damage_physical_crit_multiplier>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_fire_base>" << player->character->attributes.damageFire.base << "</damage_fire_base>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_fire_crit_chance>" << player->character->attributes.damageFire.critChancev << "</damage_fire_crit_chance>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_fire_crit_multiplier>" << player->character->attributes.damageFire.critMultiplier << "</damage_fire_crit_multiplier>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_frost_base>" << player->character->attributes.damageFrost.base << "</damage_frost_base>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_frost_crit_chance>" << player->character->attributes.damageFrost.critChancev << "</damage_frost_crit_chance>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<damage_frost_crit_multiplier>" << player->character->attributes.damageFrost.critMultiplier << "</damage_frost_crit_multiplier>" << std::endl;
        
        // Armor
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<armor_physical_base>" << player->character->attributes.armorPhysical.base << "</armor_physical_base>" << std::endl;
        
        // Resistance
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<resistance_fire_base>" << player->character->attributes.resistanceFire.base << "</resistance_fire_base>" << std::endl;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<resistance_frost_base>" << player->character->attributes.resistanceFrost.base << "</resistance_frost_base>" << std::endl;

        indent_level--;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "</player>" << std::endl;
        saveFile << std::endl;
        
        // Quest
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<quest>" << std::endl;
        indent_level++;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<001>" << "0" << "</001>" << std::endl;
        indent_level--;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "</quest>" << std::endl;
        saveFile << std::endl;
        
        // Map data
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "<map_data>" << std::endl;
        indent_level++;
        std::map<std::string, uint32>::iterator it;
        for (it = mapManager.mapList.begin(); it != mapManager.mapList.end(); it++)
        {
            saveFile << string(indent_width * indent_level, ' ');
            saveFile << "<map>" << it->first << " " << it->second << "</map>" << std::endl;
        }
        indent_level--;
        saveFile << string(indent_width * indent_level, ' ');
        saveFile << "</map_data>" << std::endl;
        saveFile << std::endl;

        // Save tag close
        indent_level--;
        saveFile << "</save_file>" << std::endl;
        saveFile << std::endl;

        // Clean up
        saveFile.close();
    }
    else
    {
        // Log error, failed to save file
        gLogWrite(LOG_ERROR, "Failed to save file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}
