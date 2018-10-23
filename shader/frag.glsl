#version 410 core

//uniform sampler2D	tex;
//uniform float		transi;
//in 		vec2		Texcoord;

out vec4 outColor;

void	main()
{
	//outColor = texture(tex, Texcoord) * transi;
	outColor = vec4(1.0,0.5,0.2,1.0);
}
