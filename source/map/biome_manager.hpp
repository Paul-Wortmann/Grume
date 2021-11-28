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

#ifndef BIOME_MANAGER_HPP
#define BIOME_MANAGER_HPP

#include "../entity/entity_manager.hpp"
#include "../core/includes.hpp"
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
        
        void freeData(sMapBiome*& _biome);

        // Wall set load
        void m_load_wallSet(sMapBiome*& _biome);
};

#endif // BIOME_MANAGER_HPP

