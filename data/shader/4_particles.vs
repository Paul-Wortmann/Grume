#version 330 core

layout(location = 0) in vec3 squareVertices;
layout(location = 1) in vec4 xyzs;
layout(location = 2) in vec4 color;

out vec2 UV;
out vec4 particlecolor;

uniform vec3 cameraRight;
uniform vec3 cameraUp;
uniform mat4 VP;

void main()
{
	float particleSize = xyzs.w;
	vec3 particleCenter_wordspace = xyzs.xyz;
	
	vec3 vertexPosition_worldspace = 
		particleCenter_wordspace
		+ cameraRight * squareVertices.x * particleSize
		+ cameraUp * squareVertices.y * particleSize;

	gl_Position = VP * vec4(vertexPosition_worldspace, 1.0f);

	UV = squareVertices.xy + vec2(0.5, 0.5);
	particlecolor = color;
}
