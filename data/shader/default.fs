#version 330 core

in vec3 Fnormal;
in vec2 Ftexcrd;

uniform sampler2D diffuse;
uniform sampler2D normal;
uniform sampler2D specular;

out vec4 fragmentColor;

void main(void)
{
    vec4 ambientLight = vec4(1.00f, 1.00f, 1.00f, 1.0f);
    fragmentColor = ambientLight * texture2D(diffuse, Ftexcrd).rgba;

    //gl_FragColor = texture2D(diffuse, Ftexcrd) * clamp(dot(-vec3(0,0,1), Fnormal), 0.0, 1.0);
}


