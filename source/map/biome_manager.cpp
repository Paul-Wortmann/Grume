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

        m_load_wallSet(tBiome);

        // Clean up
        xmlFile.free();
        return tBiome;
    }
    return nullptr;
}

void cBiomeManager::m_load_wallSet(sMapBiome*& _biome)
{
    cXML xmlFile;
    xmlFile.load(FILE_PATH_BIOME + _biome->wallSet.fileName);
    if (xmlFile.lineCount() > 0)
    {
        // Get the data from the XML file
        _biome->wallSet.name          = xmlFile.getString("<name>");
        _biome->wallSet.wall_wp_count = xmlFile.getInteger("<wall_wp_count>");
        _biome->wallSet.wall_we_count = xmlFile.getInteger("<wall_we_count>");
        _biome->wallSet.wall_ws_count = xmlFile.getInteger("<wall_ws_count>");
        _biome->wallSet.wall_wd_count = xmlFile.getInteger("<wall_wd_count>");
        _biome->wallSet.wall_wc_count = xmlFile.getInteger("<wall_wc_count>");
        _biome->wallSet.wall_wt_count = xmlFile.getInteger("<wall_wt_count>");
        _biome->wallSet.wall_tp_count = xmlFile.getInteger("<wall_tp_count>");
        _biome->wallSet.wall_te_count = xmlFile.getInteger("<wall_te_count>");
        _biome->wallSet.wall_ts_count = xmlFile.getInteger("<wall_ts_count>");
        _biome->wallSet.wall_tc_count = xmlFile.getInteger("<wall_tc_count>");
        _biome->wallSet.wall_tt_count = xmlFile.getInteger("<wall_tt_count>");
        _biome->wallSet.wall_tx_count = xmlFile.getInteger("<wall_tx_count>");
        _biome->wallSet.wall_td_count = xmlFile.getInteger("<wall_td_count>");
        _biome->wallSet.wall_tl_count = xmlFile.getInteger("<wall_tl_count>");

        // Clean up
        xmlFile.free();
    }
}
