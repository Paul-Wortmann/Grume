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

#include "effects.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------------------------------------------------
void  effect_class::init_effects(void) // Initialize hard-coded default effects, such as mod health etc...
{
    effect_type* temp_effect_pointer;
    //------------------------- Mod none --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_NONE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "EFFECT_NONE";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 0.0f;
    temp_effect_pointer->data.type     = EFFECT_NONE;
    temp_effect_pointer->data.sub_type = EFFECT_NONE;
    //------------------------- Mod Strength --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_STRENGTH);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Strength";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_STRENGTH;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_STRENGTH;
    //------------------------- Mod intellect --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_INTELLECT);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Intellect";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_INTELLECT;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_INTELLECT;
    //------------------------- Mod dexterity --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DEXTERITY);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Dexterity";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DEXTERITY;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DEXTERITY;
    //------------------------- Mod attributes --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_ALL_ATTRIBUTES);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "All attributes";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_ALL_ATTRIBUTES;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_ALL_ATTRIBUTES;
    //------------------------- Mod armor --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_ARMOR);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Armor";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_ARMOR;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_ARMOR;
    //------------------------- Mod damage --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE;
    //------------------------- Mod damage max --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_MAX);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Max damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE_MAX;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE_MAX;
    //------------------------- Mod damage min --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_MIN);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Min damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE_MIN;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE_MIN;
    //------------------------- Mod damage ice --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_ICE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Ice damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE_ICE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE_ICE;
    //------------------------- Mod damage fire --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_FIRE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Fire damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE_FIRE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE_FIRE;
    //------------------------- Mod damage lightning --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_LIGHTNING);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Lightning damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE_LIGHTNING;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE_LIGHTNING;
    //------------------------- Mod damage elemental --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_ELEMENTAL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Elemental damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_DAMAGE_ELEMENTAL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_DAMAGE_ELEMENTAL;
    //------------------------- Mod physical resistance --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_RESIST_PHYSICAL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Physical resistance";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_RESIST_PHYSICAL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_RESIST_PHYSICAL;
    //------------------------- Mod ice resistance --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_RESIST_ICE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Ice resistance";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_RESIST_ICE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_RESIST_ICE;
    //------------------------- Mod fire resistance --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_RESIST_FIRE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Fire resistance";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_RESIST_FIRE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_RESIST_FIRE;
    //------------------------- Mod lightning resistance --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_RESIST_LIGHTNING);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Lightning resistance";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_RESIST_LIGHTNING;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_RESIST_LIGHTNING;
    //------------------------- Mod all resistance --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_RESIST_ALL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Resist all";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_RESIST_ALL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_RESIST_ALL;
    //------------------------- Mod Health Effect --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Health";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_HEALTH;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_HEALTH;
    //-------------------------- Mod Health max --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH_MAX);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Max health";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 100.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_HEALTH_MAX;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_HEALTH;
    //-------------------------- Mod Health regen --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH_REGEN);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Health regeneration";
    temp_effect_pointer->data.passive  = true;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_HEALTH_REGEN;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_HEALTH;
    //------------------------- Mod player health on hit --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH_HIT);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Health on hit";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_HEALTH_HIT;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_HEALTH;
    //------------------------- Mod player health on kill --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH_KILL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Health on kill";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_HEALTH_KILL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_HEALTH;
    //------------------------- Mod Mana Effect --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mana";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MANA;
    //-------------------------- Mod Mana max --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA_MAX);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Max mana";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 100.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA_MAX;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MANA;
    //-------------------------- Mod Mana regen --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA_REGEN);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mana regeneration";
    temp_effect_pointer->data.passive  = true;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA_REGEN;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MANA;
    //-------------------------- Mod Mana on hit --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA_HIT);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mana on hit";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA_HIT;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MANA;
    //-------------------------- Mod Mana on kill --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA_KILL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mana on kill";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA_KILL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MANA;
    //-------------------------- Mod crit chance --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_CRIT_CHANCE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Crit chance";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_CRIT_CHANCE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_CRIT_CHANCE;
    //-------------------------- Mod crit damage --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_CRIT_DAMAGE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Crit damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_CRIT_DAMAGE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_CRIT_DAMAGE;
    //-------------------------- Mod movement speed --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MOVEMENT_SPEED);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Movement speed";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MOVEMENT_SPEED;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MOVEMENT_SPEED;
    //-------------------------- Mod light radius --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_LIGHT_RADIUS);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Light radius";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_LIGHT_RADIUS;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_LIGHT_RADIUS;
    //-------------------------- Mod magic find --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MAGIC_FIND);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Magic find";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MAGIC_FIND;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_MAGIC_FIND;
    //-------------------------- Mod gold find --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_GOLD_FIND);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Gold find";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_GOLD_FIND;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_GOLD_FIND;
    //-------------------------- Mod experience per kill --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_EXP_PER_KILL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Experience per kill";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_EXP_PER_KILL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_EXP_PER_KILL;
    //-------------------------- Mod spell --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "+1 to spell";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Mod spell type --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_TYPE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "+1 to spell type";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_TYPE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Mod spell all --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_ALL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "+1 to all spells";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_ALL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Mod spell cast on kill--------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_CAST_KILL);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Cast spell on kill";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_CAST_KILL;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Mod spell cast on hit --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_CAST_HIT);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Cast spell on hit";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_CAST_HIT;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Mod player spell cast on damage taken --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_CAST_DMG);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Cast spell when damage taken";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_CAST_DMG;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Mana cost reduction --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_MANA_COST);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mana cost reduction";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_MANA_COST;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Increased spell damage --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_DAMAGE);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Increased spell damage";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_DAMAGE;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Reduced spell cool down --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_COOLDOWN);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Reduced spell cool down";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_COOLDOWN;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //-------------------------- Increased spell duration --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_SPELL_DURATION);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Increased spell duration";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 1.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_SPELL_DURATION;
    temp_effect_pointer->data.sub_type = EFFECT_MOD_SPELL;
    //--------------------------------------------------------------------------------------------------------------------
    game.effect_manager.load_effects("data/scripts/effects.txt");
}

