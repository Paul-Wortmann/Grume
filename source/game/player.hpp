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

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../core/pathfinding.hpp"
#include "../core/texture_manager.hpp"

#define MAX_PLAYERS 4

#define MOVE_TO_TILE_NONE          0
#define MOVE_TO_TILE_MOVE          1
#define MOVE_TO_TILE_ATTACK        2
#define MOVE_TO_TILE_PICKUP_ITEM   3
#define MOVE_TO_TILE_USE_OBJECT    4

const int MAX_LEVELS = 100+1;

class level_class
{
    public:
        level_class(void);
       ~level_class(void);
        float                multiplier;
        int                  base;
        int                  current;
        unsigned long long   current_experience;
        unsigned long long   experience[MAX_LEVELS];
        void                 init(void);
        void                 process(void);
};

class stat_class
{
    public:
        stat_class(void);
       ~stat_class(void);
        float             width;
        float             height;
        float             pos_x;
        float             pos_y;
        float             pos_z;
        float             current;
        float             maximum;
        float             regeneration;
        void              process(void);
        void              draw(void);
};

struct player_stats_type
{
    int strength;
    int intellect;
    int dexterity;
    int armor;
    int damage;
    int damage_max;
    int damage_min;
    int damage_ice;
    int damage_fire;
    int damage_lightning;
    int resist_physical;
    int resist_ice;
    int resist_fire;
    int resist_lightning;
    int health_hit;
    int health_kill;
    int mana_hit;
    int mana_kill;
    int crit_chance;
    int crit_damage;
    int movement_speed;
    int light_radius;
    int magic_find;
    int gold_find;
    int exp_per_kill;
/*
Probably make an array to hold max_cast_effects here....
        case EFFECT_MOD_SPELL_CAST_KILL:
        break;
        case EFFECT_MOD_SPELL_CAST_HIT:
        break;
        case EFFECT_MOD_SPELL_CAST_DMG:
*/
};

struct player_spell_type
{
    int arrow_fire;
    int arrow_ice;
    int arrow_lightning;
    int arrow_elemental;
    int ball_fire;
    int ball_ice;
    int ball_lightning;
    int ball_elemental;

    int shield_fire;
    int shield_ice;
    int shield_lightning;
    int shield_elemental;
    int heal;
};

class player_class
{
    public:
        player_class(void);
       ~player_class(void);
        texture_type      *portrait;
        std::string        name;
        level_class        level;
        stat_class         health;
        stat_class         mana;
        unsigned long long gold;
        player_stats_type  stats;
        player_spell_type  spells;

        int                allocatable_points;
        bool               auto_allocate;
        float              pos_x;
        float              pos_y;
        float              pos_z;
        int                destination_tile;
        bool               destination_set;
        bool               path_set;
        int                movement_type;
        void               process(void);
        void               render(void);
        void               path_calculate(void);
        void               player_move(void);
        void               player_attack(void);
        void               player_pickup_item(void);
        void               player_use_object(void);
};

#endif // PLAYER_H

