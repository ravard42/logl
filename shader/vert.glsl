#version 410 core

//uniform	mat4 	transfo;
layout (location = 0) in vec3	position;
//in		vec2	texcoord;
//in		vec3	normal;

//out		vec2	Texcoord;

void	main()
{
	gl_Position = vec4(position, 1.0);
	//gl_Position = transfo * vec4(position, 1.0);
	//Texcoord = texcoord;
	//Texcoord.y *= -1;
	//Texcoord.y += 1;
}

