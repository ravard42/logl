#version 410 core

uniform 	sampler2D		Texture;
in			vec2			TexCoord;
uniform 	vec3 			lightCol;

out vec4 outColor;

void	main()
{
	outColor = texture(Texture, TexCoord) * vec4(lightCol, 1);
}
