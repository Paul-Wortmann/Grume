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

#ifndef GRAPHICS_ENGINE_PIPELINE_HPP
#define GRAPHICS_ENGINE_PIPELINE_HPP

#include "includes.hpp"
#include "entity.hpp"
#include "graphics_engine_shader.hpp"

class cGraphicsEnginePipeline
{
    private:

    public:
        cGraphicsEnginePipeline(void) {}
        ~cGraphicsEnginePipeline(void) {}
        uint32_t initialize(void);
        void     terminate(void);
        void     setShader(const std::string &_fileName);
        void     setProjection(void);

    protected:

    private:
        cShader m_shader = {};
};

#endif //GRAPHICS_ENGINE_PIPELINE_HPP
