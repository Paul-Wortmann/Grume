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

std::uint32_t cGameEngine::m_game_load(void)
{
    std::string fileName = "game_001.txt";

    std::uint32_t return_value = EXIT_SUCCESS;

    cXML xmlGameFile;
    xmlGameFile.load(std::string(FILE_PATH_CONFIG) + fileName);
    if (xmlGameFile.isValid())
    {
        // Load miscellaneous UI
        m_graphicsEngine.setLoadTextureID(m_resourceManager.loadTexture(xmlGameFile.getString("<loading_screen>"))->ID);
        m_graphicsEngine.setMouseCursor(m_resourceManager.loadGLFWImage(xmlGameFile.getString("<mouse_cursor>")));
        m_graphicsEngine.setWindowIcon(m_resourceManager.loadGLFWImage(xmlGameFile.getString("<window_icon>")));
        m_graphicsEngine.setLoading(true);
        m_graphicsEngine.process(0);

        return_value = (return_value == EXIT_SUCCESS) ? m_databaseManager.load(xmlGameFile.getString("<database>")) : return_value;
        return_value = (return_value == EXIT_SUCCESS) ? m_lootManager.loadLootTable(xmlGameFile.getString("<loot_table>")) : return_value;
        return_value = (return_value == EXIT_SUCCESS) ? m_playerManager.load(xmlGameFile.getString("<player>")) : return_value;
        return_value = (return_value == EXIT_SUCCESS) ? m_uiManager.load(xmlGameFile.getString("<ui>")) : return_value;
        return_value = (return_value == EXIT_SUCCESS) ? m_mapManager.load(xmlGameFile.getString("<map>")) : return_value;
        return_value = (return_value == EXIT_SUCCESS) ? m_questManager.load(xmlGameFile.getString("<quests>")) : return_value;
        m_mapManager.mapTown = xmlGameFile.getString("<map_town>");

        // Setup and initialize
        if (return_value == EXIT_SUCCESS)
        {
            // Setup
            m_playerManager.setMapPlayer();
            glm::vec3 position = m_playerManager.getPosition();
            m_graphicsEngine.moveCamera(position);
            m_npcManager.setEntityPlayer(m_playerManager.getEntityPlayer());
            m_npcManager.setMapPointer(m_mapManager.getMapPointer());
            m_objectManager.setEntityPlayer(m_playerManager.getEntityPlayer());
            m_objectManager.setMapPointer(m_mapManager.getMapPointer());
            m_mapManager.setEntityPlayer(m_playerManager.getEntityPlayer());
            m_graphicsEngine.setEntityPlayer(m_playerManager.getEntityPlayer());

            // Initialize data
            m_graphicsEngine.initializeEntities();
            m_animationEngine.initializeEntities();

            // Map process after placing entities
            m_mapManager.process(16); // 60 fps, 1 frame

            // Load finished
            m_graphicsEngine.setLoading(false);
        }

    }
    else
    {
        return_value = EXIT_FAILURE;
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    xmlGameFile.free();

    return return_value;
}

std::uint32_t cGameEngine::m_game_load(const std::uint32_t &_slotNum)
{
    // return value
    std::uint32_t return_value = EXIT_SUCCESS;

    // player entity pointer
    sEntity* tPlayer = m_playerManager.getEntityPlayer();

    // Load start
    m_graphicsEngine.setLoading(true);
    m_graphicsEngine.process(0);

    // Load the game startup file
    cXML xmlSaveGameFile;
    std::string fileName = std::string("save_00") + std::to_string(_slotNum) + std::string(".txt");
    xmlSaveGameFile.load(std::string(FILE_PATH_SAVE) + fileName);

    // Only continue if we can load the game startup file
    if (xmlSaveGameFile.lineCount() > 0)
    {
        // Information
        std::string   currentMap      = xmlSaveGameFile.getString("<current_map>");
        std::uint32_t currentPosition = xmlSaveGameFile.getInteger("<current_position>");
        float         currentRotation = xmlSaveGameFile.getFloat("<current_rotation>");
        std::string   currentTown     = xmlSaveGameFile.getString("<current_town>");

        m_mapManager.mapTown = currentTown;
        //currentMap = currentTown; // Re-spawn in town

        // Player

        // Experience + level
        tPlayer->character->level.current = xmlSaveGameFile.getInteger("<level_current>");
        tPlayer->character->level.exp     = xmlSaveGameFile.getInteger64("<exp_current>");
        tPlayer->character->level.expNext = xmlSaveGameFile.getInteger64("<exp_next>");

        // Health
        tPlayer->character->attribute.health.current = xmlSaveGameFile.getFloat("<health_current>");
        tPlayer->character->attribute.health.max     = xmlSaveGameFile.getFloat("<health_max>");
        tPlayer->character->attribute.health.regen   = xmlSaveGameFile.getFloat("<health_regen>");

        // Mana
        tPlayer->character->attribute.mana.current = xmlSaveGameFile.getFloat("<mana_current>");
        tPlayer->character->attribute.mana.max     = xmlSaveGameFile.getFloat("<mana_max>");
        tPlayer->character->attribute.mana.regen   = xmlSaveGameFile.getFloat("<mana_regen>");

        // Gold
        if (xmlSaveGameFile.getInstanceCount("<gold_current>") > 0)
            tPlayer->character->gold = xmlSaveGameFile.getInteger64("<gold_current>");
        m_uiManager.setGold(tPlayer->character->gold);

        // Damage
        tPlayer->character->attribute.damagePhysical.base           = xmlSaveGameFile.getFloat("<damage_physical_base>");
        tPlayer->character->attribute.damagePhysical.critChance     = xmlSaveGameFile.getFloat("<damage_physical_crit_chance>");
        tPlayer->character->attribute.damagePhysical.critMultiplier = xmlSaveGameFile.getFloat("<damage_physical_crit_multiplier>");
        tPlayer->character->attribute.damageFire.base               = xmlSaveGameFile.getFloat("<damage_fire_base>");
        tPlayer->character->attribute.damageFire.critChance         = xmlSaveGameFile.getFloat("<damage_fire_crit_chance>");
        tPlayer->character->attribute.damageFire.critMultiplier     = xmlSaveGameFile.getFloat("<damage_fire_crit_multiplier>");
        tPlayer->character->attribute.damageFrost.base              = xmlSaveGameFile.getFloat("<damage_frost_base>");
        tPlayer->character->attribute.damageFrost.critChance        = xmlSaveGameFile.getFloat("<damage_frost_crit_chance>");
        tPlayer->character->attribute.damageFrost.critMultiplier    = xmlSaveGameFile.getFloat("<damage_frost_crit_multiplier>");

        // Armor
        tPlayer->character->attribute.armorPhysical.base            = xmlSaveGameFile.getFloat("<armor_physical_base>");

        // Resistance
        tPlayer->character->attribute.resistanceFire.base           = xmlSaveGameFile.getFloat("<resistance_fire_base>");
        tPlayer->character->attribute.resistanceFrost.base          = xmlSaveGameFile.getFloat("<resistance_frost_base>");

        // Quest
        std::uint32_t questCount = xmlSaveGameFile.getInstanceCount("<quest>");
        for (std::uint32_t i = 0; i < questCount; ++i)
        {
            std::string tQuestData = xmlSaveGameFile.getString("<quest>", 1 + i);
            tQuestData += "    ";
            std::uint64_t tQuestDataLength = tQuestData.length();
            std::string tQuestName       = "";
            std::uint32_t tQuestState    = 0;
            std::uint32_t tStringNum = 0;
            std::string tString = "";
            if (tQuestDataLength > 6)
            {
                for (std::uint64_t j = 0; j < tQuestDataLength; ++j)
                {
                    if (tQuestData[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tQuestName = tString;
                        }
                        else if (tStringNum == 1)
                        {
                            tQuestState = std::stoi(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tQuestData[j];
                    }
                }
                m_questManager.setQuest(tQuestName, tQuestState);
            }
        }

        // Map data
        m_mapManager.mapList.clear();
        std::uint32_t mapSeedCount = xmlSaveGameFile.getInstanceCount("<map>");
        for (std::uint32_t i = 0; i < mapSeedCount; ++i)
        {
            std::string tmapData = xmlSaveGameFile.getString("<map>", 1 + i);
            tmapData += "    ";
            std::uint64_t tmapDataLength = tmapData.length();
            std::string tmapName       = "";
            std::uint32_t tmapSeed       = 0;
            std::uint32_t tStringNum = 0;
            std::string tString = "";
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
                m_mapManager.mapList[tmapName] = tmapSeed;
            }
        }

        // Load map
        std::string filenName = m_databaseManager.getDatabaseEntryFileName(currentMap, 1, eDatabaseType::databaseTypeMap);

        return_value = (return_value == EXIT_SUCCESS) ? m_mapManager.load(filenName) : return_value;

        // Setup and initialize
        if (return_value == EXIT_SUCCESS)
        {
            // Get cold start position from the map
            /*
            cXML mapFile;
            mapFile.load(std::string(FILE_PATH_MAP) + filenName);
            if (mapFile.isValid())
            {
                glm::ivec2 tVec = mapFile.getIVec2("<player_start_tile>");
                sMap* map = m_mapManager.getMapPointer();
                currentPosition = (map->info.size_x * tVec.y) + tVec.x;
                currentRotation = mapFile.getFloat("<player_start_rotation>");
            }

            // Cleanup
            mapFile.free();
            */

            // Setup
            //tPlayer->base.position = gMapTileToPosition(tMap, currentPosition);
            //tPlayer->base.rotation.y = currentRotation;
            sMap* map = m_mapManager.getMapPointer();
            m_playerManager.setPlayerPosition(gClosestFreeTile(map ,currentPosition), currentRotation);

            m_playerManager.setMapPlayer();
            m_graphicsEngine.moveCamera(tPlayer->base.position);

            // Initialize data
            m_graphicsEngine.initializeEntities();
            m_animationEngine.initializeEntities();
        }

        // Initialize systems
        m_graphicsEngine.initializeEntities();
        m_animationEngine.initializeEntities();

    }
    else
    {
        // Log error, failed to load file
        gLogWrite(LOG_ERROR, "Failed to load file: " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }

    // Load finished
    m_graphicsEngine.setLoading(false);

    // Clean up
    xmlSaveGameFile.free();
    return return_value;
}

