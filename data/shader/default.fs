#version 330

in vec3 Fnormal;
in vec2 Ftexcrd;

uniform sampler2D diffuse;
uniform sampler2D normal;
uniform sampler2D specular;

out vec4 fragmentColor;

void main(void)
{
    fragmentColor = texture2D(diffuse, Ftexcrd).rgba;

    //gl_FragColor = texture2D(diffuse, Ftexcrd) * clamp(dot(-vec3(0,0,1), Fnormal), 0.0, 1.0);
}


