#version 410 core

uniform 	sampler2D		Texture;
in			vec2				TexCoord;
uniform 	vec3 				lightCol;
in			vec3				Normal;

out vec4 outColor;

void	main()
{
	float		ambientStrenght = 0.9f;
	vec3		ambient = ambientStrenght * lightCol;
	
	outColor = texture(Texture, TexCoord) * vec4(ambient, 1);
}
