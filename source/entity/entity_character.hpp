/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef ENTITY_CHARACTER_HPP
#define ENTITY_CHARACTER_HPP

#include "../core/includes.hpp"
#include "../resource/material_define.hpp"
#include "entity_character_attributes.hpp"
#include "entity_character_level.hpp"
#include "entity_character_skills.hpp"
#include "entity_model.hpp"

enum eCharacterImportance : std::uint32_t { characterImportance_noob = 0,    // noob
                                            characterImportance_boss = 1 };  // boss

struct sEntityCharacter
{
    bool                 alive             = true;
    bool                 healthBarEnabled  = false;
    sEntityModel*        healthBarModel    = nullptr;
    sMaterial**          healthBarmaterial = nullptr;
    glm::vec2            healthBarScale    = glm::vec2(1.0f, 1.0f);
    float                healthBarOffset   = 0.0f;
    eCharacterImportance importance        = eCharacterImportance::characterImportance_noob;

    std::uint64_t        gold              = 0;
    sCharacterLevel      level             = {};
    sEntityCharAttrib    attribute         = {};
    sEntityCharSkill     skill             = {};


    // These need to be expanded
    float damage = 10.0f;
};

#endif // ENTITY_CHARACTER_HPP
