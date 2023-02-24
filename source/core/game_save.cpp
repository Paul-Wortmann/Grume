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

std::uint32_t cGameEngine::m_game_save(const std::uint32_t &_slotNum)
{
    auto indent = [] (const std::uint32_t &_value)
    {
        if (_value == 0)
            return std::string("");
        const std::uint32_t tabWidth = 3;
        return std::string(_value * tabWidth, ' ');
    };

    // Create a new save file, or overwrite its content if it does not exist
    std::string   fileName = std::string("save_00") + std::to_string(_slotNum) + std::string(".txt");
    std::ofstream saveFile;
    saveFile.open (FILE_PATH_SAVE + fileName, std::ofstream::out | std::ios::trunc);

    // Only proceed if there is map data
    if (saveFile.is_open())
    {
        std::uint32_t iLevel = 0;
        sMap*    tMap    = m_mapManager.getMapPointer();
        sEntity* tPlayer = m_playerManager.getEntityPlayer();

        // XML information
        saveFile << indent(iLevel) << "<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;

        // Save tag open
        saveFile << indent(iLevel) << "<save_file>" << std::endl;
        saveFile << std::endl;

        // Information
        iLevel++;
        saveFile << indent(iLevel) << "<information>" << std::endl;
        iLevel++;
        saveFile << indent(iLevel) << "<current_map>" << tMap->info.name << "</current_map>" << std::endl;
        saveFile << indent(iLevel) << "<current_position>" << gMapPositionToTile(tMap, tPlayer->base.position) << "</current_position>" << std::endl;
        saveFile << indent(iLevel) << "<current_rotation>" << tPlayer->base.rotation.z << "</current_rotation>" << std::endl;
        saveFile << indent(iLevel) << "<current_town>"     << m_mapManager.mapTown << "</current_town>" << std::endl;
        iLevel--;
        saveFile << indent(iLevel) << "</information>" << std::endl;
        saveFile << std::endl;

        // Player
        saveFile << indent(iLevel) << "<player>" << std::endl;
        iLevel++;

        // Level and experience
        saveFile << indent(iLevel) << "<level_current>" << tPlayer->character->level.current << "</level_current>" << std::endl;
        saveFile << indent(iLevel) << "<exp_current>" << tPlayer->character->level.exp << "</exp_current>" << std::endl;
        saveFile << indent(iLevel) << "<exp_next>" << tPlayer->character->level.expNext << "</exp_next>" << std::endl;

        // Core stats / abilities
        saveFile << indent(iLevel) << "<points>" << tPlayer->character->attribute.points << "</points>" << std::endl;
        saveFile << indent(iLevel) << "<strength>" << tPlayer->character->attribute.strength << "</strength>" << std::endl;
        saveFile << indent(iLevel) << "<dexterity>" << tPlayer->character->attribute.dexterity << "</dexterity>" << std::endl;
        saveFile << indent(iLevel) << "<vitality>" << tPlayer->character->attribute.vitality << "</vitality>" << std::endl;
        saveFile << indent(iLevel) << "<energy>" << tPlayer->character->attribute.energy << "</energy>" << std::endl;

        // Health
        saveFile << indent(iLevel) << "<health_current>" << tPlayer->character->attribute.health.current << "</health_current>" << std::endl;
        saveFile << indent(iLevel) << "<health_max>" << tPlayer->character->attribute.health.max << "</health_max>" << std::endl;
        saveFile << indent(iLevel) << "<health_regen>" << tPlayer->character->attribute.health.regen << "</health_regen>" << std::endl;

        // Mana
        saveFile << indent(iLevel) << "<mana_current>" << tPlayer->character->attribute.mana.current << "</mana_current>" << std::endl;
        saveFile << indent(iLevel) << "<mana_max>" << tPlayer->character->attribute.mana.max << "</mana_max>" << std::endl;
        saveFile << indent(iLevel) << "<mana_regen>" << tPlayer->character->attribute.mana.regen << "</mana_regen>" << std::endl;

        // Gold
        saveFile << indent(iLevel) << "<gold_current>" << tPlayer->character->gold << "</gold_current>" << std::endl;

        // Damage
        saveFile << indent(iLevel) << "<damage_physical_base>" << tPlayer->character->attribute.damagePhysical.base << "</damage_physical_base>" << std::endl;
        saveFile << indent(iLevel) << "<damage_physical_crit_chance>" << tPlayer->character->attribute.damagePhysical.critChance << "</damage_physical_crit_chance>" << std::endl;
        saveFile << indent(iLevel) << "<damage_physical_crit_multiplier>" << tPlayer->character->attribute.damagePhysical.critMultiplier << "</damage_physical_crit_multiplier>" << std::endl;
        saveFile << indent(iLevel) << "<damage_fire_base>" << tPlayer->character->attribute.damageFire.base << "</damage_fire_base>" << std::endl;
        saveFile << indent(iLevel) << "<damage_fire_crit_chance>" << tPlayer->character->attribute.damageFire.critChance << "</damage_fire_crit_chance>" << std::endl;
        saveFile << indent(iLevel) << "<damage_fire_crit_multiplier>" << tPlayer->character->attribute.damageFire.critMultiplier << "</damage_fire_crit_multiplier>" << std::endl;
        saveFile << indent(iLevel) << "<damage_frost_base>" << tPlayer->character->attribute.damageFrost.base << "</damage_frost_base>" << std::endl;
        saveFile << indent(iLevel) << "<damage_frost_crit_chance>" << tPlayer->character->attribute.damageFrost.critChance << "</damage_frost_crit_chance>" << std::endl;
        saveFile << indent(iLevel) << "<damage_frost_crit_multiplier>" << tPlayer->character->attribute.damageFrost.critMultiplier << "</damage_frost_crit_multiplier>" << std::endl;

        // Armor
        saveFile << indent(iLevel) << "<armor_physical_base>" << tPlayer->character->attribute.armorPhysical.base << "</armor_physical_base>" << std::endl;

        // Resistance
        saveFile << indent(iLevel) << "<resistance_fire_base>" << tPlayer->character->attribute.resistanceFire.base << "</resistance_fire_base>" << std::endl;
        saveFile << indent(iLevel) << "<resistance_frost_base>" << tPlayer->character->attribute.resistanceFrost.base << "</resistance_frost_base>" << std::endl;

        iLevel--;
        saveFile << indent(iLevel) << "</player>" << std::endl;
        saveFile << std::endl;

        // Action bar
        saveFile << indent(iLevel) << "<action_bar>" << std::endl;
        iLevel++;
        for (std::uint32_t i = 0; i < m_playerManager.getActionBarSize(); ++i)
        {
            sEntity* tEntity = m_playerManager.getActionBarEntity(i);
            if (tEntity != nullptr)
            {
                saveFile << indent(iLevel) << "<action_bar_slot>" << i << " " << tEntity->base.databaseName << " " << tEntity->base.databaseNumber << " " << tEntity->item->stackSize << "</action_bar_slot>" << std::endl;
            }
        }
        iLevel--;
        saveFile << indent(iLevel) << "</action_bar>" << std::endl;
        saveFile << std::endl;

        // Equipment
        saveFile << indent(iLevel) << "<equipment>" << std::endl;
        iLevel++;
        for (std::uint32_t i = 0; i < m_playerManager.getEquipmentSize(); ++i)
        {
            sEntity* tEntity = m_playerManager.getEquipmentEntity(i);
            if (tEntity != nullptr)
            {
                saveFile << indent(iLevel) << "<equipment_slot>" << i << " " << tEntity->base.databaseName << " " << tEntity->base.databaseNumber << " " << tEntity->item->stackSize << "</equipment_slot>" << std::endl;
            }
        }
        iLevel--;
        saveFile << indent(iLevel) << "</equipment>" << std::endl;
        saveFile << std::endl;

        // Inventory
        saveFile << indent(iLevel) << "<inventory>" << std::endl;
        iLevel++;
        for (std::uint32_t i = 0; i < m_playerManager.getInventorySize(); ++i)
        {
            sEntity* tEntity = m_playerManager.getInventoryEntity(i);
            if (tEntity != nullptr)
            {
                saveFile << indent(iLevel) << "<inventory_slot>" << i << " " << tEntity->base.databaseName << " " << tEntity->base.databaseNumber << " " << tEntity->item->stackSize << "</inventory_slot>" << std::endl;
            }
        }
        iLevel--;
        saveFile << indent(iLevel) << "</inventory>" << std::endl;
        saveFile << std::endl;

        // Vendor
        saveFile << indent(iLevel) << "<vendor>" << std::endl;
        iLevel++;
        for (std::uint32_t i = 0; i < m_playerManager.getVendorSize(); ++i)
        {
            sEntity* tEntity = m_playerManager.getVendorEntity(i);
            if (tEntity != nullptr)
            {
                saveFile << indent(iLevel) << "<vendor_slot>" << i << " " << tEntity->base.databaseName << " " << tEntity->base.databaseNumber << " " << tEntity->item->stackSize << "</vendor_slot>" << std::endl;
            }
        }
        iLevel--;
        saveFile << indent(iLevel) << "</vendor>" << std::endl;
        saveFile << std::endl;

        // Waypoints
        saveFile << indent(iLevel) << "<waypoints>" << std::endl;
        iLevel++;
        for (std::uint32_t i = 0; i < m_playerManager.getWaypointsSize(); ++i)
        {
            sEntity* tEntity = m_playerManager.getWaypointsEntity(i);
            if (tEntity != nullptr)
            {
                saveFile << indent(iLevel) << "<waypoints_slot>" << i << " " << tEntity->base.databaseName << " " << tEntity->base.databaseNumber << " " << tEntity->item->stackSize << "</waypoints_slot>" << std::endl;
            }
        }
        iLevel--;
        saveFile << indent(iLevel) << "</waypoints>" << std::endl;
        saveFile << std::endl;

        // Quest
        saveFile << indent(iLevel) << "<quests>" << std::endl;
        iLevel++;
        for (sQuest* tQuest = m_questManager.getHead(); tQuest != nullptr; tQuest = tQuest->next)
        {
            saveFile << indent(iLevel) << "<quest>" << tQuest->name << " " << tQuest->state << "</quest>" << std::endl;
        }
        iLevel--;
        saveFile << indent(iLevel) << "</quests>" << std::endl;
        saveFile << std::endl;

        // Map data
        saveFile << indent(iLevel) << "<map_data>" << std::endl;
        iLevel++;
        std::map<std::string, std::uint32_t>::iterator it;
        for (it = m_mapManager.mapList.begin(); it != m_mapManager.mapList.end(); it++)
        {
            saveFile << indent(iLevel) << "<map>" << it->first << " " << it->second << "</map>" << std::endl;
        }
        iLevel--;
        saveFile << indent(iLevel) << "</map_data>" << std::endl;
        saveFile << std::endl;

        // Save tag close
        iLevel--;
        saveFile << indent(iLevel) << "</save_file>" << std::endl;
        saveFile << std::endl;

        // Clean up
        saveFile.close();
    }
    else
    {
        // Log error, failed to save file
        gLogWrite(LOG_ERROR, "Failed to save file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    //Return save status
    return EXIT_SUCCESS;
}

