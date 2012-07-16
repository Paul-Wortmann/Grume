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

#include <math.h>
#include "core/misc.hpp"
#include "balls.hpp"
#include "game.hpp"

extern game_class game;

void balls_class::initialize(void)
{
    for(int ball_count = 0; ball_count < NUMBER_OF_BALL_OBJECTS; ball_count++)
    {
        balls_class::ball_object[ball_count].body_type      = CIRCLE;
        balls_class::ball_object[ball_count].position.x     = random_GLcoord();
        balls_class::ball_object[ball_count].position.y     = random_GLcoord();
        balls_class::ball_object[ball_count].radius         = random_int(50,99)/1000.0f;
        balls_class::ball_object[ball_count].velocity.x     = 0.0f;
        balls_class::ball_object[ball_count].velocity.y     = 0.0f;
        balls_class::ball_object[ball_count].velocity_max   = random_int(50,99)/10000.0f;
        balls_class::ball_object[ball_count].acceleration.x = random_int(50,99)/100000.0f;
        balls_class::ball_object[ball_count].acceleration.y = random_int(50,99)/100000.0f;
        balls_class::ball_object[ball_count].mass           = random_int(25,75)/100000.0f;
    }
    balls_class::world.gravity_x  = 0.0f;
    balls_class::world.gravity_y  = random_int(25,75)/100000.0f;
};

void balls_class::process(void)
{
    for(int ball_count_1 = 0; ball_count_1 < NUMBER_OF_BALL_OBJECTS; ball_count_1++)
    {
        balls_class::ball_object[ball_count_1] = game.core.physics.process_body(balls_class::ball_object[ball_count_1]);
        // world collision detection
        if(!game.core.physics.collision_detection(balls_class::ball_object[ball_count_1],balls_class::world))
            balls_class::ball_object[ball_count_1] = game.core.physics.collision_responce(balls_class::ball_object[ball_count_1],balls_class::world);
        // other ball collision detection
        for(int ball_count_2 = 0; ball_count_2 < NUMBER_OF_BALL_OBJECTS; ball_count_2++)
        {
        if(game.core.physics.collision_detection(balls_class::ball_object[ball_count_1],balls_class::ball_object[ball_count_2]))
            game.core.physics.collision_responce(balls_class::ball_object[ball_count_1],balls_class::ball_object[ball_count_2]);
        }
    }
};

void balls_class::render(void)
{
    float radius = 2.0f;
    game.resource.texture.test_background.draw(true,0.0f,0.0f,0.0f,radius,radius);
    for(int ball_count = 0; ball_count < NUMBER_OF_BALL_OBJECTS; ball_count++)
    {
        game.resource.texture.test_ball.draw( true
                                                ,balls_class::ball_object[ball_count].position.x
                                                ,balls_class::ball_object[ball_count].position.y
                                                ,0.01f
                                                ,balls_class::ball_object[ball_count].radius*2.0f
                                                ,balls_class::ball_object[ball_count].radius*2.0f
                                                ,balls_class::ball_object[ball_count].velocity.angle_deg()
                                                );
    game.resource.font.font_1.Write(255,255,255,64,-0.98f,-0.98f,2,16,"Direction -> ",balls_class::ball_object[ball_count].velocity.angle_deg());
    }
};



/*
That's been discussed 100's of time :)

circle [pos, vel, rad, mass] (position, velocity, radius, mass).


bool collide(Circle& a, Circle& b)
{
    // separation vector
    Vector d(b.pos - a.pos);

    // distance between circle centres, squared
    float distance_squared = d.DotProduct(d);

    // combined radius squared
    float radius = b.rad + a.rad;
    float radius_squared = radius * radius;

    // circles too far apart
    if(distance_squared > radius_squared)
        return false;

    // distance between circle centres
    float distance = (float) sqrt(distance_squared);

    // normal of collision
    Vector ncoll = (d / distance);

    // penetration distance
    float dcoll = (radius - d);

    // inverse masses (0 means, infinite mass, object is static).
    float ima = (a.mass > 0.0f)? 1.0f / a.mass : 0.0f;
    float imb = (b.mass > 0.0f)? 1.0f / b.mass : 0.0f;

    // separation vector
    Vector separation_vector = ncoll * (dcoll / (ima + imb));

    // separate the circles
    a.pos -= separation_vector * ima;
    b.pos += separation_vector * imb;

    // combines velocity
    Vector vcoll = (b.vel - a.vel);

    // impact speed
    vector vn = vcoll.DotProduct(ncoll);

    // obejcts are moving away. dont reflect velocity
    if(vn > 0.0f)
        return true; // we did collide

    // coefficient of restitution in range [0, 1].
    const float cor = 0.95f; // air hockey -> high cor

    // collision impulse
    float j = -(1.0f + cor) * (vn) / (ima + imb);

    // collision impusle vector
    Vector impulse = j * ncoll;

    // change momentum of the circles
    a.vel -= impulse * ima;
    b.vel += impulse * imb;

    // collision reported
    return true;
}
*/











