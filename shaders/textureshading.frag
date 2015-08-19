#version 130

in vec3 fragmentPosition;
in vec2 fragmentUV;
in vec3 fragmentNormal;

out vec4 color;

uniform sampler2D textureDiffuse;

void main()
{
    vec4 textureColor = texture(textureDiffuse, fragmentUV);
    color = textureColor;
}

