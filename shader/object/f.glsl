#version 410 core

uniform 	sampler2D		Texture;
in			vec2				TexCoord;
uniform 	vec3 				lightCol;
uniform	vec3				lightPos;
in			vec3				Normal;
in			vec3				FragPos;

out vec4 outColor;

void	main()
{
	float		ambientStrenght = 0.2f;
	vec3		ambient = ambientStrenght * lightCol;
	vec3		lightDir = normalize(lightPos - FragPos);
	float		diff = max(dot(lightDir, normalize(Normal)), 0.0f);
	vec3		diffuse = diff * lightCol;
	
	outColor = texture(Texture, TexCoord) * vec4(ambient + diffuse, 1);
}
