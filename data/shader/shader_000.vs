
#version 130

in vec2 vertexPosition;
in vec4 vertexColor;

out vec2 fragmentPosition;
out vec4 fragmentColor;

void main()
{
    fragmentPosition = vertexPosition;
    fragmentColor = vertexColor;
    gl_Position.xy = vertexPosition;
    gl_Position.z = 0.0;
    gl_Position.w = 1.0;
}
