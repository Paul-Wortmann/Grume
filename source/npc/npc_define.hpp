/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef NPC_DEFINE_HPP
#define NPC_DEFINE_HPP

#include "../core/includes.hpp"

enum class eNPCClass : std::uint16_t 
    { 
        NPCClassNone   = 0, // None
        NPCClassMeele  = 1, // Meele
        NPCClassMage   = 2, // Mage
        NPCClassRanged = 3  // Ranged
    };

struct sNPC
{
    // Linked list management
    sNPC*     next     = nullptr;
    
    // Data
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    
    // Charactaristics
    std::uint32_t type    = 0;

    // Traits
    eNPCClass    cClass   = eNPCClass::NPCClassMeele;
};

#endif //NPC_DEFINE_HPP
