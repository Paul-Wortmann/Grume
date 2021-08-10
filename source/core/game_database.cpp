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

#include "game_database.hpp"

void cGameDatabase::load(const std::string &_fileName)
{
    // Load game config file
    cXML xmlFile;
    xmlFile.load(FILE_PATH_DATA + _fileName);
    
    // Only contine if we load a file with data
    if (xmlFile.lineCount() > 0)
    {
        // Load the data
        gLogWrite(LOG_INFO, "Loading game database master: " + std::string(FILE_PATH_DATA) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        
        // Data
        biome.fileName       = xmlFile.getString("<biome_database>");
        map.fileName         = xmlFile.getString("<map_database>");
        map_prefab.fileName  = xmlFile.getString("<map_prefab_database>");
        music.fileName       = xmlFile.getString("<music_database>");
        npc.fileName         = xmlFile.getString("<npc_database>");
        object.fileName      = xmlFile.getString("<object_database>");
        skills.fileName      = xmlFile.getString("<skills_database>");
        sound.fileName       = xmlFile.getString("<sound_database>");
        
        // Clean up
        xmlFile.free();
    }
    else
    {
        gLogWrite(LOG_WARNING, "Unable to load game database master file.", __FILE__, __LINE__, __FUNCTION__);
    }
}
