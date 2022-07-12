#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;

out vec2 vs_textcoord;

uniform mat4 modelMatrix;

void main()
{
    vs_textcoord = texcoord;
    gl_Position = modelMatrix * vec4(position, 1.0);
}
