
#version 330 core

layout (location = 0) in vec3 Vvertex;
layout (location = 1) in vec3 Vnormal;
layout (location = 2) in vec2 Vtexcrd;

out vec3 Fnormal;
out vec2 Ftexcrd;

uniform mat4 MVP;

void main(void)
{
    gl_Position = MVP * vec4(Vvertex, 1.0);
    Fnormal = Vnormal;
    Ftexcrd = Vtexcrd;
}

