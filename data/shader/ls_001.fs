#version 330 core

// From the vertex shader
in vec2 vs_textcoord;

// To the frame buffer
out vec4 fragColor;

// Material
uniform sampler2D   diffuseMap;

void main()
{
    fragColor = texture(diffuseMap, vs_textcoord);
}

