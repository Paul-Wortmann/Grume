#version 120

varying vec2 texCoordFs;
varying vec3 normalFs;

uniform sampler2D diffuse;

void main()
{
    gl_FragColor = texture2D(diffuse, texCoordFs)
        * clamp(dot(-vec3(0,0,1), normalFs), 0.0, 1.0);
}
