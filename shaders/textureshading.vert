#version 130

in vec3 vertexPosition;
in vec2 vertexUV;
in vec3 vertexNormal;

out vec3 fragmentPosition;
out vec2 fragmentUV;
out vec3 fragmentNormal;

uniform vec3 rotation;

void main()
{
    gl_Position.x = vertexPosition.x * cos(rotation.x) - vertexPosition.y * sin(rotation.x);
    gl_Position.y = vertexPosition.x * sin(rotation.y) + vertexPosition.y * cos(rotation.x);
    gl_Position.z = vertexPosition.z;
    gl_Position.w  = 1.0;
    fragmentPosition = gl_Position.xyz;
    fragmentUV = vertexUV;
}
