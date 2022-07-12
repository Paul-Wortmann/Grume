#version 330 core

// From the vertex shader
in vec2 vs_textcoord;

// To the frame buffer
out vec4 fragColor;

// Material
uniform sampler2D   diffuseMap;

void main()
{
    vec4 textureColor = texture(diffuseMap, vs_textcoord);
    if (textureColor.a < 0.1f)
    {
        discard; 
    }
    fragColor = textureColor;
}

