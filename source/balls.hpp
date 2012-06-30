/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef BALLS_H
#define BALLS_H

#include "core/physics.hpp"

#define NUMBER_OF_BALL_OBJECTS 10

class world_2D_class
{
    private:
    protected:
    public:
        vertex_3f_class vertex[4];
        float position_x;
        float position_y;
        float gravity_x;  // 0.0f to 1.0f
        float gravity_y;  // 0.0f to 1.0f
        float radius;
 };

class ball_object_class
{
    private:
    protected:
    public:
        float position_x;
        float position_y;
        float radius;
        int   direction;
        float velocity_max;
        float velocity;
        float acceleration;
        float mass;         // 0.0f to 1.0f
        float restitution;  // 0.0f to 1.0f
 };

class balls_class
{
    private:
    protected:
    public:
        world_2D_class    world_2D;
        body_2D_class     ball_object[NUMBER_OF_BALL_OBJECTS];
        void initialize(void);
        void process(void);
        void render(void);
};

#endif //BALLS_H

