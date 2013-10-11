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

#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <string>
#include "../core/texture_manager.hpp"
#include "../core/sound_manager.hpp"

#define EFFECT_NONE             0
#define EFFECT_SPELL            1
#define EFFECT_MOD_HEALTH       2
#define EFFECT_MOD_MANA         3
#define EFFECT_MOD_CRIT_CHANCE  4
#define EFFECT_MOD_CRIT_DAMMAGE 5
#define EFFECT_MOD_WALK_SPEED   6
#define EFFECT_MOD_LIGHT_RADIUS 7

/*
defense                           = 0
add_defense                       = 0
sub_defense                       = 0
min_damage                        = 0
max_damage                        = 0
add_min_damage                    = 0
add_max_damage                    = 0
sub_min_damage                    = 0
sub_max_damage                    = 0
add_max_health                    = 0
sub_max_health                    = 0
add_max_mana                      = 0
sub_max_mana                      = 0
add_health_regeneration           = 0
sub_health_regeneration           = 0
add_mana_regeneration             = 0
sub_mana_regeneration             = 0
add_crit_chance                   = 0
sub_crit_chance                   = 0
add_walk_speed                    = 0
sub_walk_speed                    = 0
add_light_radius                  = 0
sub_light_radius                  = 0
add_spell                         = 0
spell_type                        = 0
add_health                        = 10
add_mana                          = 0
*/



struct effect_data_type
{
    bool             passive;
    int              type;
    int              value;
    bool             active;
    std::string      name;
    int              sub_type;
    int              UID;
};

struct effect_type
{
    effect_data_type  data;
    effect_type      *next;
};


class effect_manager_class
{
    public:
        effect_manager_class(void);
       ~effect_manager_class(void);
        int                 number_of_effects;
        effect_type        *root;
        effect_type        *last;
        effect_type        *effect;
        effect_type        *add_effect(int effect_UID);
};

#endif // EFFECT_MANAGER_H

