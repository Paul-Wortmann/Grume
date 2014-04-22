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

#ifndef SPELL_MANAGER_H
#define SPELL_MANAGER_H

#include <string>
#include "../core/texture_manager.hpp"
#include "../core/sound_manager.hpp"

#define MAX_SPELL_LEVEL          30

struct spell_sound_type
{
    sound_type*    on_use;
    sound_type*    on_move;
};

struct spell_image_type
{
    int              number;
    texture_type*    level_0;
    texture_type*    level_1;
    texture_type*    level_2;
};

struct spell_cooldown_type
{
    float            maximum;
    float            current;
    float            rate;
};

struct spell_level_type
{
    int              maximum;
    int              current;
    float            experience;
    int              next;
};

struct spell_data_type
{
    bool                active;
    spell_cooldown_type cooldown;
    spell_cooldown_type duration;
    spell_image_type    image;
    spell_level_type    level;
    std::string         name;
    float               mana_cost;
    bool                passive;
    int                 projectile_number;
    spell_sound_type    sound;
    int                 UID;
};

struct spell_type
{
    spell_data_type  data;
    spell_type      *next;
};

class spell_manager_class
{
    public:
        spell_manager_class(void);
       ~spell_manager_class(void);
        int                 number_of_spells;
        spell_type         *root;
        spell_type         *last;
        spell_type         *spell;
        spell_type         *add_spell(int spell_UID);
        bool                use_spell(int  spell_UID, float value);
        void                process_spells(void);
};

#endif // SPELL_MANAGER_H

