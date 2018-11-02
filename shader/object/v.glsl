#version 410 core

layout (location = 0) in vec3	position;
layout (location = 1) in vec2	texCoord;
layout (location = 2) in vec3	normal;

uniform 	mat4 	projViewModel;
uniform	mat4	model;
uniform	mat3	normalMatrix;

out		vec2	TexCoord;
out		vec3	Normal;
out		vec3	FragPos;

void	main()
{
	gl_Position = projViewModel * vec4(position, 1.0);
	TexCoord = texCoord;
	Normal = normalMatrix * normal;
	FragPos = vec3(model * vec4(position, 1.0)); 
}

