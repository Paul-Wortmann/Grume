#version 330 core
out vec4 FragColor;

in vec2 f_texCoord;

uniform int collision;
uniform int mouseOver;
uniform sampler2D diffuseTexture;

void main()
{
    vec4 finalColor = texture(diffuseTexture, f_texCoord);
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
    FragColor = finalColor;
}
