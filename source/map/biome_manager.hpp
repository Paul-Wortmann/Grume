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

#ifndef BIOME_MANAGER_HPP
#define BIOME_MANAGER_HPP

#include "../entity/entity_manager.hpp"
#include "../includes.hpp"
#include "../linked_list.hpp"
#include "biome_define.hpp"

class cBiomeManager : public tcLinkedList<sMapBiome>
{
    public:
        void initialize(cEntityManager* _entityManager);
        void terminate(void);
        sMapBiome* load(const std::string& _fileName);

    protected:

    private:
        cEntityManager* entityManager = nullptr;
        
        void m_freeAll(void);
        void m_freeData(sMapBiome*& _biome);

        void m_load_musicSet(sMapBiome*& _biome);
        void m_load_npcSet(sMapBiome*& _biome);
        void m_load_objectSet(sMapBiome*& _biome);
        void m_load_soundSet(sMapBiome*& _biome);
        void m_load_wallSet(sMapBiome*& _biome);
};

#endif // BIOME_MANAGER_HPP

