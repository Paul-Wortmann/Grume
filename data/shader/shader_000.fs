#version 150

in vec3 Fnormal;
in vec2 Ftexcrd;

//uniform sampler2D diffuse;

out vec4 fragmentColor;

void main(void)
{
    fragmentColor = vec4(1.0, 0.0, 0.0, 1.0);

    //gl_FragColor = texture2D(diffuse, Ftexcrd) * clamp(dot(-vec3(0,0,1), Fnormal), 0.0, 1.0);
}


