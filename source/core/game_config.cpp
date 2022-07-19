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

#include "game_config.hpp"

void cGameConfig::load(const std::string &_fileName)
{
    // Load game config file
    cXML xmlFile;
    xmlFile.load(FILE_PATH_CONFIG + _fileName);

    // Only contine if we load a file with data
    if (xmlFile.lineCount() > 0)
    {
        // Load the data
        gLogWrite(LOG_INFO, "Loading game config: " + std::string(FILE_PATH_CONFIG) + _fileName, __FILE__, __LINE__, __FUNCTION__);

        // Graphics
        m_resolution_x    = xmlFile.getInteger("<resolution_w>");
        m_resolution_y    = xmlFile.getInteger("<resolution_h>");
        m_fullscreen      = (xmlFile.getInteger("<fullscreen>") == 1);
        m_basicRenderer   = (xmlFile.getInteger("<basic_renderer>") == 1);
        m_wireframeRender = (xmlFile.getInteger("<wireframe_render>") == 1);

        // Audio
        m_volume_master   = xmlFile.getInteger("<volume_master>");
        m_volume_music    = xmlFile.getInteger("<volume_music>");
        m_volume_sfx      = xmlFile.getInteger("<volume_sfx>");

        // Verify the data is within reasonable limits
        m_volume_master   = (m_volume_master > 100) ? 100 : m_volume_master;
        m_volume_music    = (m_volume_music > 100)  ? 100 : m_volume_music;
        m_volume_sfx      = (m_volume_sfx > 100)    ? 100 : m_volume_sfx;

        // Clean up
        xmlFile.free();
    }
    else
    {
        gLogWrite(LOG_WARNING, "Unable to load game config, using defaults.", __FILE__, __LINE__, __FUNCTION__);
    }
}

void cGameConfig::save(const std::string &_fileName)
{
    // Open the file, truncate, close the file.
    std::ofstream configFile;
    configFile.open(FILE_PATH_CONFIG + _fileName, std::ofstream::out | std::ofstream::trunc);
    configFile.close();

    // Reopen to append data to the file.
    configFile.open(FILE_PATH_CONFIG + _fileName, std::ofstream::out | std::ios_base::app);

    // Write data to the file.
    configFile << "﻿<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;
    configFile << std::endl;
    configFile << "# This is the game configuration file." << std::endl;
    configFile << "# Delete it to have the game recreate it with safe defaults." << std::endl;
    configFile << std::endl;
    configFile << "<config>" << std::endl;
    configFile << std::endl;
    configFile << "    <graphics>" << std::endl;
    configFile << "        <resolution_w>" << m_resolution_x << "</resolution_w>" << std::endl;
    configFile << "        <resolution_h>" << m_resolution_y << "</resolution_h>" << std::endl;
    configFile << "        <fullscreen>" << ((m_fullscreen) ? "1" : "0") << "</fullscreen>" << std::endl;
    configFile << "        <basic_renderer>" << ((m_basicRenderer) ? "1" : "0") << "</basic_renderer>" << std::endl;
    configFile << "        <wireframe_render>" << ((m_wireframeRender) ? "1" : "0") << "</wireframe_render>" << std::endl;
    configFile << "    </graphics>" << std::endl;
    configFile << std::endl;
    configFile << "    <audio>" << std::endl;
    configFile << "        <volume_master>" << m_volume_master << "</volume_master>" << std::endl;
    configFile << "        <volume_music>" << m_volume_music << "</volume_music>" << std::endl;
    configFile << "        <volume_sfx>" << m_volume_sfx << "</volume_sfx>" << std::endl;
    configFile << "    </audio>" << std::endl;
    configFile << std::endl;
    configFile << "</config>" << std::endl;
    configFile << std::endl;

    // Clean up
    configFile.close();
}

