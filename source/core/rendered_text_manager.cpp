/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "core.hpp"
#include "../game/game.hpp"
#include "rendered_text_manager.hpp""

extern game_class game;

rendered_text_manager_class::rendered_text_manager_class(void)
{
    rendered_text_manager_class::number_of_rendered_texts = 0;
};

rendered_text_manager_class::~rendered_text_manager_class(void)
{

};

texture_type* rendered_text_manager_class::render_text_add(std::string text_string, int text_size)
{
    if (rendered_text_manager_class::number_of_rendered_texts == 0)
    {
        rendered_text_manager_class::root = new texture_type;
        rendered_text_manager_class::root->next = NULL;
        rendered_text_manager_class::last = new texture_type;
        rendered_text_manager_class::last = root;
        rendered_text_manager_class::last->next = NULL;
    }
    else
    {
        texture_type* temp_pointer;
        temp_pointer = new texture_type;
        temp_pointer = rendered_text_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(text_string.c_str(),temp_pointer->path.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        rendered_text_manager_class::last->next = new texture_type;
        rendered_text_manager_class::last = rendered_text_manager_class::last->next;
        rendered_text_manager_class::last->next = new texture_type;
        rendered_text_manager_class::last->next = NULL;
    }
    rendered_text_manager_class::last->path = text_string.c_str();
    //rendered_text_manager_class::last->loaded = rendered_text_manager_class::load_font(last);
    //if (rendered_text_manager_class::last->loaded)
    rendered_text_manager_class::number_of_rendered_texts++;
    return(rendered_text_manager_class::last);
};
