#version 410 core

uniform vec3 Col;

out vec4 outColor;

void	main()
{
	outColor = vec4(Col, 1);
}
