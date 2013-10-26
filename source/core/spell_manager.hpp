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

#ifndef SPELL_MANAGER_H
#define SPELL_MANAGER_H

#include <string>
#include "../core/texture_manager.hpp"
#include "../core/sound_manager.hpp"

#define SPELL_NONE                 0
#define SPELL_FIRE_ARROW           1
#define SPELL_ICE_ARROW            2
#define SPELL_LIGHTNING_ARROW      3
#define SPELL_ELEMENTAL_ARROW      4

struct spell_data_type
{
    bool             active;
    std::string      name;
    bool             passive;
    int              sub_type;
    int              type;
    int              UID;
    int              value;
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
};

#endif // SPELL_MANAGER_H

