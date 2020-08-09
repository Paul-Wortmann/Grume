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

#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_graphics.hpp"

class cGraphicsEngine
{
    private:
        sEntityGraphics *m_entityFirst = nullptr;
        sEntityGraphics *m_entityTemp  = nullptr;
        
    protected:
        
    public:
        cGraphicsEngine(void);
        ~cGraphicsEngine(void);
        
        void initialize(void);
        void terminate(void);
        void process(void);
        
        void setEntityHandle(sEntityGraphics *_entity);

};

#endif // GRAPHICS_ENGINE_HPP
