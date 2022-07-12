#version 330 core

// To the frame buffer
layout(location = 0) out vec4  fragColor;

in      vec2      vs_textcoord;
uniform sampler2D diffuse;

uniform int       collision;
uniform int       mouseOver;
uniform int       hasFunction;
uniform int       isText;
uniform vec4      textColor;

void main()
{
    vec4 finalColor;
    if (isText != 0)
    {
        finalColor = vec4(1.0, 1.0, 1.0, texture(diffuse, vs_textcoord).r);
        finalColor *= textColor;
    }
    else
    {
        finalColor = texture(diffuse, vs_textcoord);
    }
    if (collision != 0)
    {
        finalColor.r += 0.5f;
        if (finalColor.r > 1.0f)
            finalColor.r = 1.0f;
    }
    if (mouseOver != 0)
    {
        finalColor.g += 0.5f;
        if (finalColor.g > 1.0f)
            finalColor.g = 1.0f;
    }
    if (hasFunction != 0)
    {
        finalColor.b += 0.5f;
        if (finalColor.b > 1.0f)
            finalColor.b = 1.0f;
    }
    fragColor = finalColor;
}
