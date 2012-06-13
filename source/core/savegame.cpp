/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include "savegame.hpp"
#include "../game.hpp"
#include "../save_data.hpp"

extern game_class      game;
extern save_data_type save_data;

save_game_class::save_game_class(void)
{

};

save_game_class::~save_game_class(void)
{

};

bool save_game_class::Assign_File(std::string file_name)
{
    save_game_class::save_file_name = file_name;
    return(true);
};

bool save_game_class::Save(void)
{
    update_save_data();
    std::fstream savegamefile(save_game_class::save_file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (savegamefile.is_open())
    {
        savegamefile.write(reinterpret_cast<char*>(&save_data), sizeof(save_data));
        savegamefile.close();
    }
    else return(false);
    return(true);
};

bool save_game_class::Load(void)
{
    std::fstream savegamefile(save_game_class::save_file_name.c_str(),std::ios::in|std::ios::binary);
    if (savegamefile.is_open())
    {
        savegamefile.read(reinterpret_cast<char*>(&save_data), sizeof(save_data));
        savegamefile.close();
        update_game_data();
    }
    else return(false);
    return(true);
};

bool  save_game_class::Delete(void)
{
  if( remove(save_game_class::save_file_name.c_str()) != 0 ) return(false);
  else return(true);
};

bool save_game_class::File_Exists(void)
{
  std::ifstream ifile(save_game_class::save_file_name.c_str());
  return ifile;
};




