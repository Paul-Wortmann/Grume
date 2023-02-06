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

#include "ui_manager.hpp"

std::uint32_t cUIManager::load(const std::string &_fileName)
{
    std::uint32_t return_value = EXIT_SUCCESS;
    // Load the ui database file
    cXML xmlUiFile;
    xmlUiFile.load(FILE_PATH_CONFIG + _fileName);

    // If ui database file contains data:
    if (xmlUiFile.lineCount() > 0)
    {
        // string parsing variables
        std::string   dataString       = "";
        std::uint64_t dataStringLength = 0;
        std::uint32_t tStringNum       = 0;
        std::string   tString          = "";

        // Load UI information
        if (xmlUiFile.getInstanceCount("<ui_resolution>") > 0)
        {
            m_UIResolution = xmlUiFile.getIVec2("<ui_resolution>");
            m_calculateScale();
        }

        // used to index into the xml file for menu components
        std::uint32_t componentNum = 0;

        // get a count of ui menus
        m_numMenu = xmlUiFile.getInstanceCount("<menu>");
        m_menu = new sUIMenu[m_numMenu];

        // load each ui menu
        for (std::uint32_t m = 0; m < m_numMenu; ++m)
        {
            // load menu data
            m_menu[m].name = xmlUiFile.getString("<menu_name>", m + 1);
            m_menu[m].enabled = (xmlUiFile.getInteger("<menu_enabled>", m + 1) != 0);
            m_menu[m].textureNormal = m_resourceManager->loadTexture(xmlUiFile.getString("<menu_texture_normal>", m + 1))->ID;
            m_menu[m].position = xmlUiFile.getVec3("<menu_position>", m + 1);
            m_menu[m].size = xmlUiFile.getVec2("<menu_size>", m + 1);

            // Menu audio
            // Get data
            dataString  = xmlUiFile.getString("<menu_sound_open>", m + 1);
            dataString += " "; // end of string marker
            dataStringLength = dataString.length();
            tStringNum  = 0;
            tString     = "";

            // Process data
            /// # database name, database number
            if (dataStringLength > 4)
            {
                for (std::uint64_t i = 0; i < dataStringLength; ++i)
                {
                    if (dataString[i] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            m_menu[m].audio_open.name = tString; // database name
                        }
                        else if (tStringNum == 1)
                        {
                            m_menu[m].audio_open.number = std::stoi(tString); // database number
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += dataString[i];
                    }
                }

                // Process data
                if (m_menu[m].audio_open.name.compare("NONE") != 0)
                {
                    std::string fileName = m_databaseManager->getDatabaseEntryFileName(m_menu[m].audio_open.name, m_menu[m].audio_open.number, eDatabaseType::databaseTypeSound);
                    m_menu[m].audio_open.sound = m_audioEngine->getNewSoundPointer();
                    m_audioEngine->loadSound(fileName, m_menu[m].audio_open.sound->data);
                }
            }

            // Get data
            dataString  = xmlUiFile.getString("<menu_sound_close>", m + 1);
            dataString += " "; // end of string marker
            dataStringLength = dataString.length();
            tStringNum  = 0;
            tString     = "";

            // Process data
            /// # database name, database number
            if (dataStringLength > 4)
            {
                for (std::uint64_t i = 0; i < dataStringLength; ++i)
                {
                    if (dataString[i] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            m_menu[m].audio_close.name = tString; // database name
                        }
                        else if (tStringNum == 1)
                        {
                            m_menu[m].audio_close.number = std::stoi(tString); // database number
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += dataString[i];
                    }
                }

                // Process data
                if (m_menu[m].audio_close.name.compare("NONE") != 0)
                {
                    std::string fileName = m_databaseManager->getDatabaseEntryFileName(m_menu[m].audio_close.name, m_menu[m].audio_close.number, eDatabaseType::databaseTypeSound);
                    m_menu[m].audio_close.sound = m_audioEngine->getNewSoundPointer();
                    m_audioEngine->loadSound(fileName, m_menu[m].audio_close.sound->data);
                }
            }

            // Menu type
            std::string menuType = xmlUiFile.getString("<menu_type>", m + 1);
            if (menuType.compare("TYPE_NONE") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeNone;
            }
            else if (menuType.compare("TYPE_ACTIONBAR") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeActionBar;
            }
            else if (menuType.compare("TYPE_CHARACTER") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeCharacter;
            }
            else if (menuType.compare("TYPE_EQUIPMENT") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeEquipment;
            }
            else if (menuType.compare("TYPE_INVENTORY") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeInventory;
            }
            else if (menuType.compare("TYPE_MAIN") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeMain;
            }
            else if (menuType.compare("TYPE_OPTIONS") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeOptions;
            }
            else if (menuType.compare("TYPE_SKILLS") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeSkills;
            }
            else if (menuType.compare("TYPE_VENDOR") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeVendor;
            }
            else if (menuType.compare("TYPE_WAYPOINTS") == 0)
            {
                m_menu[m].type = eMenuType::menuTypeWayPoints;
            }
            else
            {
                m_menu[m].type = eMenuType::menuTypeNone;
            }

            // Calculate menu bounds
            m_menu[m].positionMin.x = m_menu[m].position.x - m_menu[m].size.x;
            m_menu[m].positionMax.x = m_menu[m].position.x + m_menu[m].size.x;
            m_menu[m].positionMin.y = m_menu[m].position.y - m_menu[m].size.y;
            m_menu[m].positionMax.y = m_menu[m].position.y + m_menu[m].size.y;

            // get a count of ui components for the current menu
            m_menu[m].numComponent = xmlUiFile.getInteger("<menu_component_count>", m + 1);
            if (m_menu[m].numComponent > 0)
            {
                // Allocate memory
                m_menu[m].component = new sUIComponent[m_menu[m].numComponent];

                // load each ui component
                for (std::uint32_t c = 0; c < m_menu[m].numComponent; ++c)
                {
                    m_menu[m].component[c].name = xmlUiFile.getString("<component_name>", componentNum + 1);
                    m_menu[m].component[c].enabled = (xmlUiFile.getInteger("<component_enabled>", componentNum + 1) > 0);
                    m_menu[m].component[c].textureNormal = m_resourceManager->loadTexture(xmlUiFile.getString("<component_texture_normal>", componentNum + 1))->ID;
                    m_menu[m].component[c].textureHover  = m_resourceManager->loadTexture(xmlUiFile.getString("<component_texture_hover>", componentNum + 1))->ID;
                    m_menu[m].component[c].textureActive = m_resourceManager->loadTexture(xmlUiFile.getString("<component_texture_activated>", componentNum + 1))->ID;
                    m_menu[m].component[c].position = xmlUiFile.getVec3("<component_position>", componentNum + 1);
                    m_menu[m].component[c].position += glm::vec3(m_menu[m].position.x, m_menu[m].position.y, 0.0f);
                    m_menu[m].component[c].size = xmlUiFile.getVec2("<component_size>", componentNum + 1);

                    // Calculate Component bounds
                    m_menu[m].component[c].positionMin.x = m_menu[m].component[c].position.x - m_menu[m].component[c].size.x;
                    m_menu[m].component[c].positionMax.x = m_menu[m].component[c].position.x + m_menu[m].component[c].size.x;
                    m_menu[m].component[c].positionMin.y = m_menu[m].component[c].position.y - m_menu[m].component[c].size.y;
                    m_menu[m].component[c].positionMax.y = m_menu[m].component[c].position.y + m_menu[m].component[c].size.y;

                    // Component audio: hover
                    // Get data
                    dataString  = xmlUiFile.getString("<component_sound_hover>", componentNum + 1);
                    dataString += " "; // end of string marker
                    dataStringLength = dataString.length();
                    tStringNum  = 0;
                    tString     = "";

                    // Process data
                    /// # database name, database number
                    if (dataStringLength > 4)
                    {
                        for (std::uint64_t i = 0; i < dataStringLength; ++i)
                        {
                            if (dataString[i] == ' ')
                            {
                                if (tStringNum == 0)
                                {
                                    m_menu[m].component[c].audio_hover.name = tString; // database name
                                }
                                else if (tStringNum == 1)
                                {
                                    m_menu[m].component[c].audio_hover.number = std::stoi(tString); // database number
                                }
                                tStringNum++;
                                tString = "";
                            }
                            else
                            {
                                tString += dataString[i];
                            }
                        }

                        // Process data
                        if (m_menu[m].component[c].audio_hover.name.compare("NONE") != 0)
                        {
                            std::string fileName = m_databaseManager->getDatabaseEntryFileName(m_menu[m].component[c].audio_hover.name, m_menu[m].component[c].audio_hover.number, eDatabaseType::databaseTypeSound);
                            m_menu[m].component[c].audio_hover.sound = m_audioEngine->getNewSoundPointer();
                            m_audioEngine->loadSound(fileName, m_menu[m].component[c].audio_hover.sound->data);
                        }
                    }

                    // Component audio: activate
                    // Get data
                    dataString  = xmlUiFile.getString("<component_sound_activate>", componentNum + 1);
                    dataString += " "; // end of string marker
                    dataStringLength = dataString.length();
                    tStringNum  = 0;
                    tString     = "";

                    // Process data
                    /// # database name, database number
                    if (dataStringLength > 4)
                    {
                        for (std::uint64_t i = 0; i < dataStringLength; ++i)
                        {
                            if (dataString[i] == ' ')
                            {
                                if (tStringNum == 0)
                                {
                                    m_menu[m].component[c].audio_activate.name = tString; // database name
                                }
                                else if (tStringNum == 1)
                                {
                                    m_menu[m].component[c].audio_activate.number = std::stoi(tString); // database number
                                }
                                tStringNum++;
                                tString = "";
                            }
                            else
                            {
                                tString += dataString[i];
                            }
                        }

                        // Process data
                        if (m_menu[m].component[c].audio_activate.name.compare("NONE") != 0)
                        {
                            std::string fileName = m_databaseManager->getDatabaseEntryFileName(m_menu[m].component[c].audio_activate.name, m_menu[m].component[c].audio_activate.number, eDatabaseType::databaseTypeSound);
                            m_menu[m].component[c].audio_activate.sound = m_audioEngine->getNewSoundPointer();
                            m_audioEngine->loadSound(fileName, m_menu[m].component[c].audio_activate.sound->data);
                        }
                    }

                    // Component type
                    std::string componentType = xmlUiFile.getString("<component_type>", componentNum + 1);

                    if (componentType.compare("TYPE_NORMAL") == 0)
                    {
                        m_menu[m].component[c].type = eComponentType::componentTypeNormal;
                    }
                    else if (componentType.compare("TYPE_ITEM") == 0)
                    {
                        m_menu[m].component[c].type = eComponentType::componentTypeItem;
                    }
                    else if (componentType.compare("TYPE_TEXT") == 0)
                    {
                        m_menu[m].component[c].type = eComponentType::componentTypeText;
                    }

                    // Component function
                    std::string componentFunction = xmlUiFile.getString("<component_function>", componentNum + 1);

                    if (componentFunction.compare("MENU_CLOSE") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionCloseMenu;
                    }
                    else if (componentFunction.compare("GAME_QUIT") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionGameQuit;
                    }
                    else if (componentFunction.compare("GAME_NEW") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionGameNew;
                    }
                    else if (componentFunction.compare("GAME_SAVE") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionGameSave;
                    }
                    else if (componentFunction.compare("GAME_LOAD") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionGameLoad;
                    }
                    else if (componentFunction.compare("MENU_OPTIONS") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionMenuOptions;
                    }
                    else if (componentFunction.compare("HEALTH_BAR") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionBarHealth;
                    }
                    else if (componentFunction.compare("MANA_BAR") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionBarMana;
                    }
                    else if (componentFunction.compare("EXP_BAR") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionBarExp;
                    }
                    else if (componentFunction.compare("MUSIC_VOLUME_DOWN") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeMusicDown;
                    }
                    else if (componentFunction.compare("MUSIC_VOLUME_UP") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeMusicUp;
                    }
                    else if (componentFunction.compare("MUSIC_VOLUME_BAR") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeMusicBar;
                    }
                    else if (componentFunction.compare("SOUND_VOLUME_DOWN") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeSoundDown;
                    }
                    else if (componentFunction.compare("SOUND_VOLUME_UP") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeSoundUp;
                    }
                    else if (componentFunction.compare("SOUND_VOLUME_BAR") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeSoundBar;
                    }
                    else if (componentFunction.compare("MASTER_VOLUME_DOWN") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeMasterDown;
                    }
                    else if (componentFunction.compare("MASTER_VOLUME_UP") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeMasterUp;
                    }
                    else if (componentFunction.compare("MASTER_VOLUME_BAR") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVolumeMasterBar;
                    }
                    else if (componentFunction.compare("LOAD_MAP_TOWN_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionLoadMapTown_1;
                    }
                    else if (componentFunction.compare("LOAD_MAP_TOWN_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionLoadMapTown_2;
                    }
                    else if (componentFunction.compare("LOAD_MAP_TOWN_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionLoadMapTown_3;
                    }
                    else if (componentFunction.compare("LOAD_MAP_TOWN_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionLoadMapTown_4;
                    }
                    else if (componentFunction.compare("LOAD_MAP_TOWN_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionLoadMapTown_5;
                    }
                    else if (componentFunction.compare("LOAD_MAP_TOWN_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionLoadMapTown_6;
                    }

                    // Inventory slot
                    else if (componentFunction.compare("INVENTORY_SLOT_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_1;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_2;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_3;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_4;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_5;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_6;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_7;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_8;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_9;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_10;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_11;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_12;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_13") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_13;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_14") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_14;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_15") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_15;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_16") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_16;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_17") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_17;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_18") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_18;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_19") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_19;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_20") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_20;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_21") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_21;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_22") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_22;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_23") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_23;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_24") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_24;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_25") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_25;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_26") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_26;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_27") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_27;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_28") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_28;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_29") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_29;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_30") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_30;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_31") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_31;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_32") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_32;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_33") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_33;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_34") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_34;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_35") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_35;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_36") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_36;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_37") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_37;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_38") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_38;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_39") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_39;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_40") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_40;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_41") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_41;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_42") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_42;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_43") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_43;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_44") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_44;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_45") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_45;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_46") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_46;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_47") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_47;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_48") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_48;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_49") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_49;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_50") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_50;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_51") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_51;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_52") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_52;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_53") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_53;
                    }
                    else if (componentFunction.compare("INVENTORY_SLOT_54") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventorySlot_54;
                    }

                    // Inventory stack
                    else if (componentFunction.compare("INVENTORY_STACK_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_1;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_2;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_3;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_4;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_5;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_6;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_7;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_8;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_9;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_10;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_11;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_12;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_13") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_13;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_14") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_14;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_15") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_15;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_16") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_16;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_17") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_17;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_18") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_18;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_19") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_19;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_20") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_20;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_21") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_21;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_22") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_22;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_23") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_23;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_24") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_24;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_25") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_25;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_26") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_26;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_27") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_27;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_28") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_28;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_29") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_29;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_30") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_30;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_31") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_31;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_32") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_32;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_33") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_33;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_34") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_34;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_35") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_35;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_36") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_36;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_37") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_37;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_38") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_38;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_39") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_39;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_40") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_40;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_41") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_41;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_42") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_42;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_43") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_43;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_44") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_44;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_45") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_45;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_46") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_46;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_47") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_47;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_48") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_48;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_49") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_49;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_50") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_50;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_51") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_51;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_52") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_52;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_53") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_53;
                    }
                    else if (componentFunction.compare("INVENTORY_STACK_54") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionInventoryStack_54;
                    }

                    // Action bar slot
                    else if (componentFunction.compare("ACTION_BAR_SLOT_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_1;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_2;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_3;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_4;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_5;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_6;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_7;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_8;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_9;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_10;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_11;
                    }
                    else if (componentFunction.compare("ACTION_BAR_SLOT_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarSlot_12;
                    }

                    // Action bar stack
                    else if (componentFunction.compare("ACTION_BAR_STACK_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_1;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_2;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_3;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_4;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_5;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_6;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_7;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_8;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_9;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_10;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_11;
                    }
                    else if (componentFunction.compare("ACTION_BAR_STACK_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionActionBarStack_12;
                    }

                    // Vendor slot
                    else if (componentFunction.compare("VENDOR_SLOT_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_1;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_2;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_3;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_4;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_5;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_6;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_7;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_8;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_9;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_10;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_11;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_12;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_13") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_13;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_14") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_14;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_15") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_15;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_16") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_16;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_17") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_17;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_18") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_18;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_19") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_19;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_20") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_20;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_21") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_21;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_22") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_22;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_23") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_23;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_24") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_24;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_25") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_25;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_26") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_26;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_27") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_27;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_28") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_28;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_29") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_29;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_30") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_30;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_31") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_31;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_32") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_32;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_33") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_33;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_34") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_34;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_35") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_35;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_36") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_36;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_37") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_37;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_38") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_38;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_39") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_39;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_40") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_40;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_41") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_41;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_42") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_42;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_43") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_43;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_44") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_44;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_45") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_45;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_46") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_46;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_47") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_47;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_48") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_48;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_49") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_49;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_50") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_50;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_51") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_51;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_52") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_52;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_53") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_53;
                    }
                    else if (componentFunction.compare("VENDOR_SLOT_54") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorSlot_54;
                    }

                    // Vendor stack
                    else if (componentFunction.compare("VENDOR_STACK_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_1;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_2;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_3;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_4;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_5;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_6;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_7;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_8;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_9;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_10;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_11;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_12;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_13") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_13;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_14") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_14;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_15") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_15;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_16") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_16;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_17") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_17;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_18") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_18;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_19") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_19;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_20") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_20;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_21") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_21;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_22") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_22;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_23") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_23;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_24") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_24;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_25") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_25;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_26") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_26;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_27") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_27;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_28") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_28;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_29") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_29;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_30") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_30;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_31") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_31;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_32") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_32;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_33") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_33;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_34") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_34;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_35") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_35;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_36") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_36;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_37") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_37;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_38") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_38;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_39") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_39;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_40") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_40;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_41") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_41;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_42") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_42;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_43") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_43;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_44") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_44;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_45") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_45;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_46") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_46;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_47") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_47;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_48") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_48;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_49") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_49;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_50") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_50;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_51") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_51;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_52") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_52;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_53") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_53;
                    }
                    else if (componentFunction.compare("VENDOR_STACK_54") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionVendorStack_54;
                    }

                    // Equipment slot
                    else if (componentFunction.compare("EQUIPMENT_SLOT_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_1;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_2;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_3;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_4;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_5;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_6;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_7;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_8;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_9;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_10;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_11;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_12;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_13") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_13;
                    }
                    else if (componentFunction.compare("EQUIPMENT_SLOT_14") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentSlot_14;
                    }

                    // Equipment slot stack text
                    else if (componentFunction.compare("EQUIPMENT_STACK_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_1;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_2;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_3;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_4;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_5;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_6;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_7") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_7;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_8") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_8;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_9") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_9;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_10") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_10;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_11") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_11;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_12") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_12;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_13") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_13;
                    }
                    else if (componentFunction.compare("EQUIPMENT_STACK_14") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionEquipmentStack_14;
                    }

                    // Waypoints slot
                    else if (componentFunction.compare("WAYPOINTS_SLOT_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsSlot_1;
                    }
                    else if (componentFunction.compare("WAYPOINTS_SLOT_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsSlot_2;
                    }
                    else if (componentFunction.compare("WAYPOINTS_SLOT_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsSlot_3;
                    }
                    else if (componentFunction.compare("WAYPOINTS_SLOT_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsSlot_4;
                    }
                    else if (componentFunction.compare("WAYPOINTS_SLOT_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsSlot_5;
                    }
                    else if (componentFunction.compare("WAYPOINTS_SLOT_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsSlot_6;
                    }

                    // Waypoints slot stack text
                    else if (componentFunction.compare("WAYPOINTS_STACK_1") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsStack_1;
                    }
                    else if (componentFunction.compare("WAYPOINTS_STACK_2") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsStack_2;
                    }
                    else if (componentFunction.compare("WAYPOINTS_STACK_3") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsStack_3;
                    }
                    else if (componentFunction.compare("WAYPOINTS_STACK_4") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsStack_4;
                    }
                    else if (componentFunction.compare("WAYPOINTS_STACK_5") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsStack_5;
                    }
                    else if (componentFunction.compare("WAYPOINTS_STACK_6") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionWaypointsStack_6;
                    }

                    // Gold text
                    else if (componentFunction.compare("GOLD_TEXT") == 0)
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionTextGold;
                    }

                    else
                    {
                        m_menu[m].component[c].function = eComponentFunction::componentFunctionNone;
                    }

                    // Update the component index
                    componentNum++;
                }
            }

        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to load file: " + std::string(FILE_PATH_CONFIG) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return_value = EXIT_FAILURE;
    }

    // Cleanup
    xmlUiFile.free();
    return return_value;
}
