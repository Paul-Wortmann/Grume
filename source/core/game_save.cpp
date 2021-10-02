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

void cGameEngine::save(const std::uint32_t &_slotNum)
{
    // Create a new save file, or overwrite its content if it does not exist
    std::string   fileName = std::string("save_00") + std::to_string(_slotNum) + std::string(".txt");
    std::ofstream saveFile;
    saveFile.open (FILE_PATH_SAVE + fileName, std::ios::trunc); 

    // Only proceed if there is map data
    if (saveFile.is_open())
    {
        std::uint32_t indent_width = 4;
        std::uint32_t indent_level = 0;
        
        // XML information
        saveFile << "<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;

        // Save tag open
        saveFile << "<save_file>" << std::endl;
        saveFile << std::endl;
        
        // Information
        indent_level++;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<information>" << std::endl;
        indent_level++;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<current_map>" << mapManager.getCurrentMapName() << "</current_map>" << std::endl;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<current_position>" << playerManager.getCurrentTile() << "</current_position>" << std::endl;
        indent_level--;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "</information>" << std::endl;
        saveFile << std::endl;
        
        // Player
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<player>" << std::endl;
        indent_level++;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<level>" << "0" << "</level>" << std::endl;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<experience>" << "0" << "</experience>" << std::endl;
        indent_level--;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "</player>" << std::endl;
        saveFile << std::endl;
        
        // Quest
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<quest>" << std::endl;
        indent_level++;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<001>" << "0" << "</001>" << std::endl;
        indent_level--;
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "</quest>" << std::endl;
        saveFile << std::endl;
        
        // Map data
        saveFile << std::string(indent_width * indent_level, ' ');
        saveFile << "<map_data>" << std::endl;
        indent_level++;
        std::map<std::string, std::uint32_t>::iterator it;
        for (it = mapManager.mapList.begin(); it != mapManager.mapList.end(); it++)
        {
            saveFile << std::string(indent_width * indent_level, ' ');
            saveFile << "<map>" << it->first << " " << it->second << "</map>" << std::endl;
        }
        indent_level--;
        saveFile << std::string(indent_width * indent_level, ' ');
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
