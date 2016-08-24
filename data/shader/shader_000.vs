
#version 330

in vec3 Vvertex;
in vec3 Vnormal;
in vec2 Vtexcrd;

out vec3 Fnormal;
out vec2 Ftexcrd;

void main(void)
{
    gl_Position = vec4(Vvertex, 1.0);
    Fnormal = Vnormal;
    Ftexcrd = Vtexcrd;

    //gl_Position = transform * vec4(Vvertex, 1.0);
    //Ftexcrd = Vtexcrd;
    //Fnormal = (transform * vec4(Vnormal, 0.0)).xyz;
}

