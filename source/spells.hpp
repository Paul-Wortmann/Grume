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

#ifndef SPELLS_H
#define SPELLS_H

#include <string>

const int MAX_SPELLS = 24;

class spell_class
{
    public:
        std::string name;
        int         item_type;
        int         level;
        int         image_level_1;
        int         image_level_2;
        int         image_level_3;
        int         experience_level_1;
        int         experience_level_2;
        int         experience_level_3;
        int         experience;
        float       cooldown_speed;
        float       cooldown_count;
        float       mana_cost_level_1;
        float       mana_cost_level_2;
        float       mana_cost_level_3;
        float       cooldown_level_1;
        float       cooldown_level_2;
        float       cooldown_level_3;
        spell_class(void);
       ~spell_class(void);
};

void    init_spells(void);

#endif // SPELLS_H

