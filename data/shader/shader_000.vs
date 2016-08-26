
#version 330

in vec3 Vvertex;
in vec3 Vnormal;
in vec2 Vtexcrd;

out vec3 Fnormal;
out vec2 Ftexcrd;

uniform mat4 MVP;

void main(void)
{
    gl_Position = MVP * vec4(Vvertex, 1.0);
    Fnormal = Vnormal;
    Ftexcrd = Vtexcrd;
}

