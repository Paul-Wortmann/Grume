/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <string>
#include "map.hpp"

//-----------------------------------------------------------------------------------------------------------------

layer_class::layer_class(void)
{
    layer_class::name       = "";
    layer_class::width      = 0;
    layer_class::height     = 0;
};

layer_class::~layer_class(void)
{
};

//-----------------------------------------------------------------------------------------------------------------

tileset_class::tileset_class(void)
{
    tileset_class::tilewidth  = 0;
    tileset_class::tileheight = 0;
    tileset_class::firstgid   = 0;
    tileset_class::name       = "";
};

tileset_class::~tileset_class(void)
{
};

//-----------------------------------------------------------------------------------------------------------------

void draw(void)
{

};

void process(void)
{

};

void map_class::load(std::string file_name, int reference_id)
{
    map_class::reference_id = reference_id;
};

map_class::map_class(void)
{
    map_class::width      = 0;
    map_class::height     = 0;
    map_class::tilewidth  = 0;
    map_class::tileheight = 0;
};

map_class::~map_class(void)
{
};


//-----------------------------------------------------------------------------------------------------------------

/*
<?xml version="1.0" encoding="UTF-8"?>
<map version="1.0" orientation="isometric" width="100" height="100" tilewidth="64" tileheight="32">
 <tileset firstgid="1" name="grass_and_water" tilewidth="64" tileheight="64">
  <image source="../tilesets/grass_and_water.png" width="256" height="384"/>
 </tileset>
 <tileset firstgid="25" name="bridge" tilewidth="64" tileheight="151">
  <image source="../tilesets/bridge.png" width="3776" height="151"/>
 </tileset>
 <layer name="Tile Layer 1" width="100" height="100">
  <data>
   <tile gid="4"/>
  </data>
 </layer>
</map>
*/
