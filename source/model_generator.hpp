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

#ifndef MODEL_GENERATOR_HPP
#define MODEL_GENERATOR_HPP

#include "includes.hpp"
#include "entity_component_model.hpp"

enum eModelType:uint16_t    { cube = 1, plane = 1 };

struct sEntityModeleGeneratorInfo
{
    eModelType type    = eModelType::plane;
    uint16_t   units_x = 10;
    uint16_t   units_y = 10;
    uint16_t   units_z = 10;
    float      size_x  = 1.0f;
    float      size_y  = 1.0f;
    float      size_z  = 1.0f;
};

class cModelGenerator
{
    public:
        cModelGenerator(void) = default;
        ~cModelGenerator(void) = default;
        void generateMesh(sEntityModel* _model, const sEntityModeleGeneratorInfo &_info);

    protected:

    private:
        glm::vec3 m_generateNormal(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c);
};

#endif //MODEL_GENERATOR_HPP

