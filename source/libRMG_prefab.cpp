/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libRMG"
 *
 * "libRMG" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libRMG" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libRMG" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#include "libRMG_prefab.hpp"

static void _libRMG_prefab_stripSpaces(std::string &_string)
{
    std::string tempString = "";
    uint16_t stringLength = _string.length();
    for (uint16_t i = 0; i < stringLength; i++)
    {
        if (_string[i] != ' ')
            tempString += _string[i];
    }
    _string = tempString;
}

static int32_t _libRMG_prefab_xmlGetSingleInt(const std::string &_string)
{
    bool valueStart = false;
    bool valueEnd = false;
    std::string value = "";
    uint16_t stringLength = _string.length();
    for (uint16_t i = 0; i < stringLength; i++)
    {
        if (_string[i] == '<')
        {
            if (!valueEnd && valueStart)
                valueEnd = true;
        }
        if (_string[i] == '>')
        {
            if (!valueEnd && !valueStart)
                valueStart = true;
        }
        if (!valueEnd && valueStart && (_string[i] != '>'))
            value += _string[i];
    }
    return atol(value.c_str());
}

static int32_t _libRMG_prefab_xmlGetIntValueCount(const std::string &_string)
{
    uint16_t valueCount = 0;
    uint16_t stringLength = _string.length();
    for (uint16_t i = 0; i < stringLength; i++)
        if (_string[i] == ',')
            valueCount++;
    if (valueCount > 0)
        valueCount++;
    return valueCount;
}

static int32_t _libRMG_prefab_xmlGetIntValue(const std::string &_string, const uint16_t &_pos)
{
    bool valueStart = false;
    bool valueEnd = false;
    uint16_t valuePos = 0;
    std::string value = "";
    uint16_t stringLength = _string.length();
    for (uint16_t i = 0; i < stringLength; i++)
    {
        if (_string[i] == '<')
        {
            if (!valueEnd && valueStart)
                valueEnd = true;
        }
        if (_string[i] == '>')
        {
            if (!valueEnd && !valueStart)
                valueStart = true;
        }
        if (!valueEnd && valueStart && (_string[i] != '>'))
        {
            if (_string[i] == ',')
                valuePos++;
            else
            {
                if (_pos == valuePos)
                    value += _string[i];
            }
        }
    }
    return atol(value.c_str());
}

void _libRMG_prefab_freeAll(sLibRMGMapData &_data)
{
    while (_data.prefab != nullptr)
    {
        sLibRMGPrefab *prefabTempPrevious = _data.prefab;
        _data.prefab = _data.prefab->next;
        if (prefabTempPrevious->tile != nullptr)
        {
            delete[] prefabTempPrevious->tile;
            prefabTempPrevious->tile = nullptr;
        }
        if (prefabTempPrevious != nullptr)
        {
            delete prefabTempPrevious;
            prefabTempPrevious = nullptr;
        }
    }
}

void _libRMG_prefab_eventFreeAll(sLibRMGMapData &_data)
{
    while (_data.event != nullptr)
    {
        sLibRMGMapEvent *eventTempPrevious = _data.event;
        _data.event = _data.event->next;
        if (eventTempPrevious->triggerTileID != nullptr)
        {
            delete[] eventTempPrevious->triggerTileID;
            eventTempPrevious->triggerTileID = nullptr;
        }
        if (eventTempPrevious->targetTileID != nullptr)
        {
            delete[] eventTempPrevious->targetTileID;
            eventTempPrevious->targetTileID = nullptr;
        }
        if (eventTempPrevious != nullptr)
        {
            delete eventTempPrevious;
            eventTempPrevious = nullptr;
        }
    }
}

bool _libRMG_prefab_find(sLibRMGMapData &_data)
{
    _libRMG_prefab_freeAll(_data);
    _libRMG_prefab_eventFreeAll(_data);
    _data.prefabCount = 0;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (_data.prefabPath.c_str())) != nullptr)
    {
        while ((ent = readdir (dir)) != nullptr)
        {
            if (ent->d_type == DT_REG)
            {
                _data.prefabCount++;
                _libRMG_prefab_load(_data, ent->d_name);
            }
        }
        closedir (dir);
    }
    else
    {
        std::cout << "librmg -> Error could not open prefab directory." << std::endl;
        //logWrite("librmg -> Error could not open prefab directory: " + std::string(_data.prefabPath.c_str()), __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    return (_data.prefabCount > 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void _libRMG_prefab_load(sLibRMGMapData &_data, const std::string &_fileName)
{
    // first make sure the prefab has not yeat already been loaded!
    if (_data.prefab != nullptr)
    {
        sLibRMGPrefab *prefabTemp = _data.prefab;
        for (prefabTemp = _data.prefab; prefabTemp->next != nullptr; prefabTemp = prefabTemp->next)
        {
            if (prefabTemp != nullptr)
            {
                if (prefabTemp->filename.compare(_fileName) == 0)
                {
                    return;
                }
            }
        }
    }

    // read file and parse
    std::string fileAndPath = _data.prefabPath;
    fileAndPath += "/";
    fileAndPath += _fileName;
    std::ifstream tFstream(fileAndPath.c_str(), std::ifstream::in);
    if (tFstream.is_open())
    {
        uint16_t eventCount = _data.event_count;
        sLibRMGPrefab *prefabTemp = _data.prefab;
        if (_data.prefab == nullptr)
        {
            _data.prefab = new sLibRMGPrefab;
            prefabTemp = _data.prefab;
        }
        else
        {
            for (prefabTemp = _data.prefab; prefabTemp->next != nullptr; prefabTemp = prefabTemp->next);
            prefabTemp->next = new sLibRMGPrefab;
            prefabTemp = prefabTemp->next;
        }
        prefabTemp->next = nullptr;
        prefabTemp->filename = _fileName;
        eLayer currentLayer = eLayer::layerNone;
        bool eventSection = false;
        std::string tData = "";
        uint32_t tLength = 0;
        uint32_t tLine = 0;
        sLibRMGMapEvent *tEvent = nullptr;
        while (tFstream.good())
        {
            tData = "";
            std::getline(tFstream, tData);
            _libRMG_prefab_stripSpaces(tData);
            tLength = tData.length();
            if (tLength > 3)
            {
                if (tData.find("<width>") != std::string::npos)
                    prefabTemp->w = _libRMG_prefab_xmlGetSingleInt(tData);
                if (tData.find("<height>") != std::string::npos)
                    prefabTemp->h = _libRMG_prefab_xmlGetSingleInt(tData);
                if (tData.find("<layer_base>") != std::string::npos)
                {
                    prefabTemp->tileCount = prefabTemp->w * prefabTemp->h;
                    if (prefabTemp->tile == nullptr)
                        prefabTemp->tile = new sLibRMGPrefabTile[prefabTemp->tileCount];
                    tLine = 0;
                    currentLayer = eLayer::layerBase;
                }
                if (tData.find("<layer_object>") != std::string::npos)
                {
                    prefabTemp->tileCount = prefabTemp->w * prefabTemp->h;
                    if (prefabTemp->tile == nullptr)
                        prefabTemp->tile = new sLibRMGPrefabTile[prefabTemp->tileCount];
                    tLine = 0;
                    currentLayer = eLayer::layerObject;
                }
                if (tData.find("<layer_event>") != std::string::npos)
                {
                    prefabTemp->tileCount = prefabTemp->w * prefabTemp->h;
                    if (prefabTemp->tile == nullptr)
                        prefabTemp->tile = new sLibRMGPrefabTile[prefabTemp->tileCount];
                    tLine = 0;
                    currentLayer = eLayer::layerEvent;
                }
                if (tData.find("<tiles>") != std::string::npos)
                {
                    uint16_t valueCount = _libRMG_prefab_xmlGetIntValueCount(tData);
                    for (uint16_t i = 0; i< valueCount; i++)
                    {
                        if (currentLayer == eLayer::layerBase)
                            prefabTemp->tile[(tLine * prefabTemp->w) + i].base = static_cast<eBase>(_libRMG_prefab_xmlGetIntValue(tData, i));
                        if (currentLayer == eLayer::layerObject)
                            prefabTemp->tile[(tLine * prefabTemp->w) + i].object = _libRMG_prefab_xmlGetIntValue(tData, i);
                        if (currentLayer == eLayer::layerEvent)
                            prefabTemp->tile[(tLine * prefabTemp->w) + i].event = _libRMG_prefab_xmlGetIntValue(tData, i) + eventCount;
                    }
                    tLine++;
                }
                if (tData.find("<event>") != std::string::npos)
                {
                    currentLayer = eLayer::layerNone;
                    eventSection = true;
                }
                if (tData.find("</event>") != std::string::npos)
                    eventSection = false;
                if (eventSection)
                {
                    if (tData.find("<ID>") != std::string::npos)
                    {
                        if (_data.event == nullptr)
                        {
                            _data.event = new sLibRMGMapEvent;
                            tEvent = _data.event;
                        }
                        else
                        {
                            for (tEvent = _data.event; tEvent->next != nullptr; tEvent = tEvent->next);
                            tEvent->next = new sLibRMGMapEvent;
                            tEvent = tEvent->next;
                        }
                        tEvent->next = nullptr;
                        tEvent->ID = eventCount + _libRMG_prefab_xmlGetSingleInt(tData);
                    }
                    if (tData.find("<enabled>") != std::string::npos)
                        tEvent->enabled = (_libRMG_prefab_xmlGetSingleInt(tData) == 1);
                    if (tData.find("<type>") != std::string::npos)
                        tEvent->type = static_cast<eEvent>(_libRMG_prefab_xmlGetSingleInt(tData));
                    if (tData.find("<state>") != std::string::npos)
                        tEvent->state = static_cast<eEventState>(_libRMG_prefab_xmlGetSingleInt(tData));
                    if (tData.find("<reTriggerable>") != std::string::npos)
                        tEvent->reTriggerable = (_libRMG_prefab_xmlGetSingleInt(tData) == 1);
                    if (tData.find("<triggerTileID>") != std::string::npos)
                    {
                        tEvent->triggerTileCount = _libRMG_prefab_xmlGetIntValueCount(tData);
                        for (uint16_t i = 0; i< tEvent->triggerTileCount; i++)
                            tEvent->triggerTileID[i] = _libRMG_prefab_xmlGetIntValue(tData, i);
                    }
                    if (tData.find("<targetTileID>") != std::string::npos)
                    {
                        tEvent->targetTileCount = _libRMG_prefab_xmlGetIntValueCount(tData);
                        for (uint16_t i = 0; i< tEvent->targetTileCount; i++)
                            tEvent->targetTileID[i] = _libRMG_prefab_xmlGetIntValue(tData, i);
                    }
                    if (tData.find("<timer>") != std::string::npos)
                        tEvent->timer = _libRMG_prefab_xmlGetSingleInt(tData);
                }
            }
        }
        tFstream.close();
        //std::cout << "Loaded prefab: " << fileAndPath << std::endl;
    }
    else
    {
        std::cout << "Error - Failed to open file: " << fileAndPath << std::endl;
    }
}

// should find how many prefabs of the same size and randomly select one.... TODO
void _libRMG_prefab_rooms(sLibRMGMapData &_data)
{
    for (uint16_t i = 0; i < _data.room_count; i++)
    {
        sLibRMGPrefab * tempPrefab = _data.prefab;
        for (tempPrefab = _data.prefab; tempPrefab != nullptr; )
        {
            if ((_data.room[i].w == tempPrefab->w) && (_data.room[i].h == tempPrefab->h))
            {
                std::cout << "Applying prefab: " << tempPrefab->filename << std::endl;
                _libRMG_prefab_rotateR90(*tempPrefab);
                uint16_t sX = _data.room[i].x - (_data.room[i].w / 2);
                uint16_t sY = _data.room[i].y - (_data.room[i].h / 2);
                for (uint16_t k = 0; k < tempPrefab->h; k++)
                {
                    for (uint16_t l = 0; l < tempPrefab->w; l++)
                    {
                        _data.tile[(_data.tile_x * (k+sY)) + (l+sX)].base = tempPrefab->tile[(tempPrefab->w * k) + l].base;
                        _data.tile[(_data.tile_x * (k+sY)) + (l+sX)].objectID = tempPrefab->tile[(tempPrefab->w * k) + l].object;
                        _data.tile[(_data.tile_x * (k+sY)) + (l+sX)].eventID = tempPrefab->tile[(tempPrefab->w * k) + l].event;
                    }
                }
                tempPrefab = nullptr;
            }
            if (tempPrefab != nullptr)
                tempPrefab = tempPrefab->next;
        }
    }
}

void _libRMG_prefab_roomFlipV(sLibRMGPrefab &_prefab)
{
    sLibRMGPrefabTile *tile = new sLibRMGPrefabTile[_prefab.tileCount];
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        tile[i].base = _prefab.tile[i].base;
        tile[i].object = _prefab.tile[i].object;
        tile[i].event = _prefab.tile[i].event;
    }
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        _prefab.tile[(_prefab.tileCount-1)-i].base = tile[i].base;
        _prefab.tile[(_prefab.tileCount-1)-i].object = tile[i].object;
        _prefab.tile[(_prefab.tileCount-1)-i].event = tile[i].event;
    }
    delete[] tile;
}

void _libRMG_prefab_roomFlipH(sLibRMGPrefab &_prefab)
{
    sLibRMGPrefabTile *tile = new sLibRMGPrefabTile[_prefab.tileCount];
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        tile[i].base= _prefab.tile[i].base;
        tile[i].object= _prefab.tile[i].object;
        tile[i].event= _prefab.tile[i].event;
    }
    for (uint32_t i = 0; i < _prefab.h; i++)
    {
        for (uint32_t j = 0; j < _prefab.w; j++)
        {
            _prefab.tile[(i * _prefab.w) + j].base= tile[(i * _prefab.w) + ((_prefab.w-1)-j)].base;
            _prefab.tile[(i * _prefab.w) + j].object= tile[(i * _prefab.w) + ((_prefab.w-1)-j)].object;
            _prefab.tile[(i * _prefab.w) + j].event= tile[(i * _prefab.w) + ((_prefab.w-1)-j)].event;
        }
    }
    delete[] tile;
}

void _libRMG_prefab_rotateR90(sLibRMGPrefab &_prefab)
{
    sLibRMGPrefabTile *tile = new sLibRMGPrefabTile[_prefab.tileCount];
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        tile[i].base= _prefab.tile[i].base;
        tile[i].object= _prefab.tile[i].object;
        tile[i].event= _prefab.tile[i].event;
    }
    for (uint32_t i = 0; i < _prefab.h; i++)
    {
        for (uint32_t j = 0; j < _prefab.w; j++)
        {
            _prefab.tile[(i * _prefab.w) + j].base= tile[(j * _prefab.w) + ((_prefab.w-1)-i)].base;
            _prefab.tile[(i * _prefab.w) + j].object= tile[(j * _prefab.w) + ((_prefab.w-1)-i)].object;
            _prefab.tile[(i * _prefab.w) + j].event= tile[(j * _prefab.w) + ((_prefab.w-1)-i)].event;
        }
    }
    delete[] tile;
}

void _libRMG_prefab_rotateL90(sLibRMGPrefab &_prefab)
{
    sLibRMGPrefabTile *tile = new sLibRMGPrefabTile[_prefab.tileCount];
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        tile[i].base= _prefab.tile[i].base;
        tile[i].object= _prefab.tile[i].object;
        tile[i].event= _prefab.tile[i].event;
    }
    for (uint32_t i = 0; i < _prefab.h; i++)
    {
        for (uint32_t j = 0; j < _prefab.w; j++)
        {
            _prefab.tile[(i * _prefab.w) + j].base= tile[(((_prefab.h-1)-j) * _prefab.w) + ((_prefab.w-1)-i)].base;
            _prefab.tile[(i * _prefab.w) + j].object= tile[(((_prefab.h-1)-j) * _prefab.w) + ((_prefab.w-1)-i)].object;
            _prefab.tile[(i * _prefab.w) + j].event= tile[(((_prefab.h-1)-j) * _prefab.w) + ((_prefab.w-1)-i)].event;
        }
    }
    delete[] tile;
}

void _libRMG_prefab_rotate180(sLibRMGPrefab &_prefab)
{
    sLibRMGPrefabTile *tile = new sLibRMGPrefabTile[_prefab.tileCount];
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        tile[i].base= _prefab.tile[i].base;
        tile[i].object= _prefab.tile[i].object;
        tile[i].event= _prefab.tile[i].event;
    }
    for (uint32_t i = 0; i < _prefab.tileCount; i++)
    {
        _prefab.tile[(_prefab.tileCount-1)-i].base= tile[i].base;
        _prefab.tile[(_prefab.tileCount-1)-i].object= tile[i].object;
        _prefab.tile[(_prefab.tileCount-1)-i].event= tile[i].event;
    }
    delete[] tile;
}
