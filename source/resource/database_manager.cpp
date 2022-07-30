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

#include "database_manager.hpp"

std::uint32_t cDatabaseManager::initialize(void)
{
    return EXIT_SUCCESS;
}


std::uint32_t cDatabaseManager::load(const std::string &_fileName)
{
    std::uint32_t exit_status = EXIT_SUCCESS;

    exit_status = (exit_status == EXIT_SUCCESS) ? m_load(_fileName) : exit_status;

    return exit_status;
}

void cDatabaseManager::terminate(void)
{
    // Free the biome database.
    if (m_biome_database.entry != nullptr)
    {
        delete[] m_biome_database.entry;
        m_biome_database.entry = nullptr;
        m_biome_database.numEntry = 0;
    }

    // Free the item database.
    if (m_item_database.entry != nullptr)
    {
        delete[] m_item_database.entry;
        m_item_database.entry = nullptr;
        m_item_database.numEntry = 0;
    }

    // Free the map database.
    if (m_map_database.entry != nullptr)
    {
        delete[] m_map_database.entry;
        m_map_database.entry = nullptr;
        m_map_database.numEntry = 0;
    }

    // Free the map_prefab database.
    if (m_map_prefab_database.entry != nullptr)
    {
        delete[] m_map_prefab_database.entry;
        m_map_prefab_database.entry = nullptr;
        m_map_prefab_database.numEntry = 0;
    }

    // Free the music database.
    if (m_music_database.entry != nullptr)
    {
        delete[] m_music_database.entry;
        m_music_database.entry = nullptr;
        m_music_database.numEntry = 0;
    }

    // Free the npc database.
    if (m_npc_database.entry != nullptr)
    {
        delete[] m_npc_database.entry;
        m_npc_database.entry = nullptr;
        m_npc_database.numEntry = 0;
    }

    // Free the object database.
    if (m_object_database.entry != nullptr)
    {
        delete[] m_object_database.entry;
        m_object_database.entry = nullptr;
        m_object_database.numEntry = 0;
    }

    // Free the particle database.
    if (m_particle_database.entry != nullptr)
    {
        delete[] m_particle_database.entry;
        m_particle_database.entry = nullptr;
        m_particle_database.numEntry = 0;
    }

    // Free the sound database.
    if (m_sound_database.entry != nullptr)
    {
        delete[] m_sound_database.entry;
        m_sound_database.entry = nullptr;
        m_sound_database.numEntry = 0;
    }

    // Free prefab database
    if (m_prefabData != nullptr)
    {
        delete[] m_prefabData;
        m_prefabData = nullptr;
        m_numPrefabData = 0;
    }
}

std::uint32_t cDatabaseManager::m_load(const std::string &_fileName)
{
    // Get each database file name
    cXML databaseFile;
    databaseFile.load(std::string(FILE_PATH_CONFIG) + _fileName);
    if (databaseFile.isValid())
    {
        m_biome_database.fileName      = databaseFile.getString("<biome_database>");
        m_item_database.fileName       = databaseFile.getString("<item_database>");
        m_map_database.fileName        = databaseFile.getString("<map_database>");
        m_map_prefab_database.fileName = databaseFile.getString("<map_prefab_database>");
        m_music_database.fileName      = databaseFile.getString("<music_database>");
        m_npc_database.fileName        = databaseFile.getString("<npc_database>");
        m_object_database.fileName     = databaseFile.getString("<object_database>");
        m_particle_database.fileName   = databaseFile.getString("<particle_database>");
        m_sound_database.fileName      = databaseFile.getString("<sound_database>");
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    databaseFile.free();

    // Load the biome database
    cXML biome_databaseFile;
    biome_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_biome_database.fileName);
    if (biome_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_biome_database.numEntry = biome_databaseFile.getInstanceCount("<biome>");
        m_biome_database.entry    = new sDatabaseEntry[m_biome_database.numEntry];
        for (std::uint32_t i = 0; i < m_biome_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = biome_databaseFile.getString("<biome>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_biome_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_biome_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_biome_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    biome_databaseFile.free();

    // Load the item database
    cXML item_databaseFile;
    item_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_item_database.fileName);
    if (item_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_item_database.numEntry = item_databaseFile.getInstanceCount("<item>");
        m_item_database.entry    = new sDatabaseEntry[m_item_database.numEntry];
        for (std::uint32_t i = 0; i < m_item_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = item_databaseFile.getString("<item>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_item_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_item_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_item_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    item_databaseFile.free();

    // Load the map database
    cXML map_databaseFile;
    map_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_map_database.fileName);
    if (map_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_map_database.numEntry = map_databaseFile.getInstanceCount("<map>");
        m_map_database.entry    = new sDatabaseEntry[m_map_database.numEntry];
        for (std::uint32_t i = 0; i < m_map_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = map_databaseFile.getString("<map>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_map_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_map_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_map_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    map_databaseFile.free();

    // Load the map prefab database
    cXML map_prefab_databaseFile;
    map_prefab_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_map_prefab_database.fileName);
    if (map_prefab_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_map_prefab_database.numEntry = map_prefab_databaseFile.getInstanceCount("<map_prefab>");
        m_map_prefab_database.entry    = new sDatabaseEntry[m_map_prefab_database.numEntry];
        for (std::uint32_t i = 0; i < m_map_prefab_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = map_prefab_databaseFile.getString("<map_prefab>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_map_prefab_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_map_prefab_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_map_prefab_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    map_prefab_databaseFile.free();

    // Load the music database
    cXML music_databaseFile;
    music_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_music_database.fileName);
    if (music_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_music_database.numEntry = music_databaseFile.getInstanceCount("<music>");
        m_music_database.entry    = new sDatabaseEntry[m_music_database.numEntry];
        for (std::uint32_t i = 0; i < m_music_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = music_databaseFile.getString("<music>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_music_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_music_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_music_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    music_databaseFile.free();

    // Load the npc database
    cXML npc_databaseFile;
    npc_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_npc_database.fileName);
    if (npc_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_npc_database.numEntry = npc_databaseFile.getInstanceCount("<npc>");
        m_npc_database.entry    = new sDatabaseEntry[m_npc_database.numEntry];
        for (std::uint32_t i = 0; i < m_npc_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = npc_databaseFile.getString("<npc>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_npc_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_npc_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_npc_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    npc_databaseFile.free();

    // Load the object database
    cXML object_databaseFile;
    object_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_object_database.fileName);
    if (object_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_object_database.numEntry = object_databaseFile.getInstanceCount("<object>");
        m_object_database.entry    = new sDatabaseEntry[m_object_database.numEntry];
        for (std::uint32_t i = 0; i < m_object_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = object_databaseFile.getString("<object>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_object_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_object_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_object_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    object_databaseFile.free();

    // Load the particle database
    cXML particle_databaseFile;
    particle_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_particle_database.fileName);
    if (particle_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_particle_database.numEntry = particle_databaseFile.getInstanceCount("<particle>");
        m_particle_database.entry    = new sDatabaseEntry[m_particle_database.numEntry];
        for (std::uint32_t i = 0; i < m_particle_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = particle_databaseFile.getString("<particle>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_particle_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_particle_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_particle_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    particle_databaseFile.free();

    // Load the sound database
    cXML sound_databaseFile;
    sound_databaseFile.load(std::string(FILE_PATH_DATABASE) + m_sound_database.fileName);
    if (sound_databaseFile.isValid())
    {
        // Get instance count and allocate memory
        m_sound_database.numEntry = sound_databaseFile.getInstanceCount("<sound>");
        m_sound_database.entry    = new sDatabaseEntry[m_sound_database.numEntry];
        for (std::uint32_t i = 0; i < m_sound_database.numEntry; ++i)
        {
            // For each instance
            std::string tData = sound_databaseFile.getString("<sound>", i + 1);

            // Parse the temp string
            if (tData.length() > 2)
            {
                // Extract the data from the temp string
                tData += "    ";
                std::uint64_t tDataLength = tData.length();

                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDataLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDataLength; ++j)
                    {
                        if (tData[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                m_sound_database.entry[i].category = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                m_sound_database.entry[i].fileName = tString;
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tData[j];
                        }
                    }
                }
            }
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_sound_database.fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    sound_databaseFile.free();

    // Build prefab database
    m_buildPrefabDatabase();

    // Return
    return EXIT_SUCCESS;
}

std::string cDatabaseManager::getDatabaseEntryFileName(const std::string &_catagory, const std::uint32_t &_number, const eDatabaseType &_type)
{
    sDatabase* dataBase = nullptr;
    if (_type == eDatabaseType::databaseTypeBiome)
        dataBase = &m_biome_database;
    else if (_type == eDatabaseType::databaseTypeItem)
        dataBase = &m_item_database;
    else if (_type == eDatabaseType::databaseTypeMap)
        dataBase = &m_map_database;
    else if (_type == eDatabaseType::databaseTypeMapPrefab)
        dataBase = &m_map_prefab_database;
    else if (_type == eDatabaseType::databaseTypeMusic)
        dataBase = &m_music_database;
    else if (_type == eDatabaseType::databaseTypeNpc)
        dataBase = &m_npc_database;
    else if (_type == eDatabaseType::databaseTypeObject)
        dataBase = &m_object_database;
    else if (_type == eDatabaseType::databaseTypeParticle)
        dataBase = &m_particle_database;
    else if (_type == eDatabaseType::databaseTypeSound)
        dataBase = &m_sound_database;
    else
    {
        gLogWrite(LOG_ERROR, "Unknown database entry type: " + std::to_string(static_cast<std::uint32_t>(_type)), __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }

    // Get entry count
    std::uint32_t entryCount = 0;
    for (std::uint32_t i = 0; i < dataBase->numEntry; ++i)
    {
        if (dataBase->entry[i].category.compare(_catagory) == 0)
            entryCount++;
    }

    // Entry not found
    if (entryCount == 0)
    {
        gLogWrite(LOG_ERROR, "Failed to find database entry: " + std::string(_catagory), __FILE__, __LINE__, __FUNCTION__);
        return std::string("");
    }

    // Random entry
    std::uint32_t entryNumber = (_number == 0) ? rand() % entryCount : _number - 1;

    // Find and return entry
    entryCount = 0;
    for (std::uint32_t i = 0; i < dataBase->numEntry; ++i)
    {
        if (dataBase->entry[i].category.compare(_catagory) == 0)
        {
            if (entryNumber == entryCount)
                return dataBase->entry[i].fileName;
            entryCount++;
        }
    }

    // If error finding entry
    gLogWrite(LOG_ERROR, "Failed to find database entry: " + std::string(_catagory), __FILE__, __LINE__, __FUNCTION__);
    return std::string("");
}

std::uint32_t cDatabaseManager::getDatabaseEntryCount(const std::string &_catagory, const eDatabaseType &_type)
{
    sDatabase* dataBase = nullptr;
    if (_type == eDatabaseType::databaseTypeBiome)
        dataBase = &m_biome_database;
    else if (_type == eDatabaseType::databaseTypeItem)
        dataBase = &m_item_database;
    else if (_type == eDatabaseType::databaseTypeMap)
        dataBase = &m_map_database;
    else if (_type == eDatabaseType::databaseTypeMapPrefab)
        dataBase = &m_map_prefab_database;
    else if (_type == eDatabaseType::databaseTypeMusic)
        dataBase = &m_music_database;
    else if (_type == eDatabaseType::databaseTypeNpc)
        dataBase = &m_npc_database;
    else if (_type == eDatabaseType::databaseTypeObject)
        dataBase = &m_object_database;
    else if (_type == eDatabaseType::databaseTypeParticle)
        dataBase = &m_particle_database;
    else if (_type == eDatabaseType::databaseTypeSound)
        dataBase = &m_sound_database;

    // Get entry count
    std::uint32_t entryCount = 0;
    for (std::uint32_t i = 0; i < dataBase->numEntry; ++i)
    {
        if (dataBase->entry[i].category.compare(_catagory) == 0)
            entryCount++;
    }

    // Entry not found
    if (entryCount == 0)
    {
        gLogWrite(LOG_ERROR, "Failed to find database entry: " + std::string(_catagory), __FILE__, __LINE__, __FUNCTION__);
    }
    // return count
    return entryCount;
}

std::uint32_t cDatabaseManager::m_buildPrefabDatabase(void)
{
    m_numPrefabData = m_map_prefab_database.numEntry;
    m_prefabData = new sPrefabData[m_numPrefabData];
    for (std::uint32_t i = 0; i < m_numPrefabData; ++i)
    {
        // Load the prefab data
        cXML map_prefabFile;
        map_prefabFile.load(std::string(FILE_PATH_MAP_PREFAB) + m_map_prefab_database.entry[i].fileName);
        if (map_prefabFile.isValid())
        {
            m_prefabData[i].fileName = m_map_prefab_database.entry[i].fileName;
            m_prefabData[i].roomType = map_prefabFile.getInteger("<room_type>");
            m_prefabData[i].roomSize_x = map_prefabFile.getInteger("<map_tiles_x>");
            m_prefabData[i].roomSize_y = map_prefabFile.getInteger("<map_tiles_y>");
        }
        else
        {
            gLogWrite(LOG_ERROR, "Error - Failed to load file: " + m_map_prefab_database.entry[i].fileName, __FILE__, __LINE__, __FUNCTION__);
        }
        map_prefabFile.free();
    }
    return EXIT_SUCCESS;
}
