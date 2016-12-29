/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#include <fstream>
#include <string>
#include "re_loader_tmx.hpp"

namespace RoboEngine
{

    void re_tmxDelete(re_stmxData *&_tmxData)
    {
        if (_tmxData)
        {
            if (_tmxData->layer->tile)
                delete[] _tmxData->layer->tile;
            if (_tmxData->layer)
                delete[] _tmxData->layer;
            if (_tmxData->tileset)
                delete[] _tmxData->tileset;
            delete _tmxData;
            _tmxData = nullptr;
        }
    }

    void re_tmxLoad(const std::string &_fileName, re_stmxData *&_tmxData)
    {
        re_sxmlData* xml_data = nullptr;
        re_xml_parse(_fileName, xml_data);
        if (!_tmxData)
            _tmxData = new re_stmxData;
        if (xml_data != nullptr)
        {

        }
        re_xml_delete(xml_data);
    }

    void re_tmxSave(const std::string &_fileName, re_stmxData *&_tmxData)
    {

    }

}
