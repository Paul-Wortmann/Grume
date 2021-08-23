#version 330 core

// To the frame buffer
layout(location = 0) out vec4 fragColor;

in vec2 UV;
in vec4 particlecolor;

uniform sampler2D textureParticle;

void main()
{
	//fragColor = texture( textureParticle, UV ) * particlecolor;
}
