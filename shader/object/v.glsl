#version 410 core

layout (location = 0) in vec3	position;
layout (location = 1) in vec2	texCoord;
layout (location = 2) in vec3	normal;

uniform 	mat4 	projView;
uniform	mat4	model;

out		vec2	TexCoord;
out		vec3	Normal;
out		vec3	FragPos;

void	main()
{
	gl_Position = projView * model * vec4(position, 1.0);
	TexCoord = texCoord;
	Normal = normal;
	FragPos = vec3(model * vec4(position, 1.0)); 
}

