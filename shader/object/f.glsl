#version 410 core

uniform 	sampler2D		Texture;
in			vec2				TexCoord;
uniform 	vec3 				lightCol;
uniform	vec3				lightPos;
in			vec3				Normal;
in			vec3				FragPos;
uniform	vec3				viewPos;

out vec4 outColor;

void	main()
{
	float		ambientStrenght = 0.2f;
	vec3		ambient = ambientStrenght * lightCol;
	vec3		lightDir = normalize(lightPos - FragPos);
	vec3		norm = normalize(Normal);
	float		diff = max(dot(lightDir, norm), 0.0f);
	vec3		diffuse = diff * lightCol;
	float		specularStrength = 0.5;
	vec3		viewDir = normalize(viewPos - FragPos);
	vec3		reflectDir = reflect(-lightDir, norm);
	float		spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3		specular = specularStrength * spec * lightCol;
	
	outColor = texture(Texture, TexCoord) * vec4(ambient + diffuse + specular, 1);
}
