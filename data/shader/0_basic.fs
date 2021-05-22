#version 330 core

out vec4  fragColor;
in  vec2  vs_textcoord;
uniform sampler2D diffuse;

void main()
{
    fragColor = texture(diffuse, vs_textcoord);
}
