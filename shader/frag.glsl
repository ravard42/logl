#version 410 core

uniform sampler2D	Texture;
in 		vec2		TexCoord;
uniform vec3 col;

out vec4 outColor;

void	main()
{
	outColor = texture(Texture, TexCoord) * vec4(col, 1);
}
