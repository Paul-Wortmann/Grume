#version 120

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

varying vec2 texCoordFs;
varying vec3 normalFs;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position, 1.0);
    texCoordFs = texCoord;
    normalFs = (transform * vec4(normal, 0.0)).xyz;
}
