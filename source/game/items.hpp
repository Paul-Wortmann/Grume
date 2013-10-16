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

#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include "../core/item_manager.hpp"
#include "../UI/UI_types.hpp"

class item_class
{
    public:
        void            init_items  (void);
};

#endif // ITEMS_H

/*
//---------------------------------------
+  Max mana
+  Mana after each kill
+  Mana after each hit
+  Mana regeneration
+  Mana steal
//---------------------------------------
+  Max health
+  Health after each kill
+  Health after each hit
+  Health regeneration
+  Health steal
//---------------------------------------
+  Magic find
+  Gold find
+  Light radius
+  Movement speed
+% Chance to cast level x spell when hit
+% Chance to cast level x spell on hit
+  x experience after each kill
+  x to spell y
+  x to y spell category
+  x to all spells
+  x to all attributes
+  x Strength
+  x Dexterity
+  x Intelligence
+  x Vitality
//---------------------------------------
+  x Physical damage
+  x Maximum damage
+  x Minimum damage
+  x Elemental damage
+  x Ice damage
+  x Fire damage
+  x Lightning damage
+  x Poison damage
//---------------------------------------
+  x Elemental resistance
+  x Physical resistance
+  x Ice resistance
+  x Fire resistance
+  x Lightning resistance
+  x Poison resistance
*/
