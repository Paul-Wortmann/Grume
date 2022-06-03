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

#include "map_manager.hpp"

void cBiomeManager::initialize(cEntityManager* _entityManager)
{
    entityManager = _entityManager;
}

void cBiomeManager::terminate(void)
{
    freeAll();
}

void cBiomeManager::freeData(sMapBiome*& _biome)
{
}

sMapBiome* cBiomeManager::load(const std::string &_fileName)
{
    // Don't load the biome file if it is already loaded, return a pointer to it
    for (sMapBiome* tBiome = getHead(); tBiome != nullptr; tBiome = tBiome->next)
    {
        if (tBiome->fileName.compare(_fileName) == 0)
        {
            return tBiome;
        }
    }
    
    // Load the biome from file
    cXML xmlFile;
    xmlFile.load(FILE_PATH_BIOME + _fileName);
    if (xmlFile.lineCount() > 0)
    {
        gLogWrite(LOG_INFO, "Loading Biome: " + xmlFile.getString("<name>"), __FILE__, __LINE__, __FUNCTION__);
        
        // Create and populate a new biome struct with the XML data
        sMapBiome* tBiome = getNew();
        tBiome->fileName = _fileName;

        // Get the data from the XML file

        // Info
        tBiome->name                      = xmlFile.getString ("<name>");

        // Data
        tBiome->musicTag.name             = xmlFile.getString ("<music_tag>");
        tBiome->musicTrack.no             = xmlFile.getInteger("<music_track>");
        tBiome->wallSet.fileName          = xmlFile.getString ("<wall_set>");
        tBiome->floorSpritesheet.fileName = xmlFile.getString ("<floor_spritesheet>");

        // Clean up
        xmlFile.free();
        return tBiome;
    }
    return nullptr;
}
