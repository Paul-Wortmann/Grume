#version 330 core
layout (location = 0) in vec3 v_position;
layout (location = 1) in vec3 v_normal;
layout (location = 2) in vec2 v_texCoord;

uniform mat4 MVP;

out vec2 f_texCoord;

void main()
{
    gl_Position = MVP * vec4(v_position, 1.0);
    f_texCoord = v_texCoord;
}

