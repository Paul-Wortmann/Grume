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

#version 330 core

layout (location = 0) in vec3  position;
layout (location = 1) in vec3  normal;
layout (location = 2) in vec3  tangent;
layout (location = 3) in vec3  bitangent;
layout (location = 4) in vec2  texcoord;
layout (location = 5) in vec4  boneWeights;
layout (location = 6) in ivec4 boneID;

const int MAX_BONES = 64; // This has to match defines.hpp !!!!

uniform int  animationEnabled;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 boneMatrix[MAX_BONES];

out vec2 v_texCoord;
out vec3 v_normal;
out vec3 v_modelPos;

void main()
{
    mat4 boneTransform = mat4(1);
    if (animationEnabled > 0)
    {
        boneTransform  = boneMatrix[boneID[0]] * boneWeights[0];
        boneTransform += boneMatrix[boneID[1]] * boneWeights[1];
        boneTransform += boneMatrix[boneID[2]] * boneWeights[2];
        boneTransform += boneMatrix[boneID[3]] * boneWeights[3];
    }

    vec4 tPosition = boneTransform * vec4(position, 1.0);

    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(tPosition.xyz, 1.0);
    v_texCoord = texcoord;
    v_normal = (modelMatrix * (boneTransform * vec4(normal, 0.0))).xyz;
    v_modelPos = (modelMatrix * (boneTransform * vec4(position, 1.0))).xyz;
}

