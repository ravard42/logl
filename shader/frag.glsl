#version 410 core

//uniform sampler2D	tex;
//uniform float		transi;
//in 		vec2		Texcoord;

uniform vec3 col;
out vec4 outColor;

void	main()
{
	//outColor = texture(tex, Texcoord) * transi;
	outColor = vec4(col, 1.0);
}
