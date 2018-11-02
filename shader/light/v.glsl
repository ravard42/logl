#version 410 core

layout (location = 0) in vec3	position;

uniform mat4 projViewModel;
uniform mat4 model;


void	main()
{
	gl_Position = projViewModel * vec4(position, 1.0);
}

