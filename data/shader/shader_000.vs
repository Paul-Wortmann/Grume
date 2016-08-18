
#version 130

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec2 vertexTextureCoords;
in vec4 vertexColor;

out vec2 fragmentPosition;
out vec4 fragmentColor;

void main()
{
    fragmentPosition = vertexPosition;
    fragmentColor = vertexColor;
    gl_Position.xy = vertexPosition;
    gl_Position.w = 1.0;
}
