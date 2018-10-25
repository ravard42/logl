#include "logl.hpp"

int	main()
{
	t_env		e;

	if (init_glfw(&e) == -1 || init_glad() == -1)
		return (-1);

	Shader		shad("./shader/vert.glsl", "./shader/frag.glsl");

	float 			vertices[] = {-0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
									-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 
									0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
									0.5f, 0.5f, 0.0f, 1.0f, 0.0f};

	unsigned int	indices[] = {0, 1, 2, 1, 2, 3};
	

	GLuint	vao, vbo, ebo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glBindVertexArray(0);


	GLuint	tex;
	glGenTextures(1, &tex);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int				width, height, nbChannels;
	unsigned char	*data = stbi_load("texture_files/triforce.jpg", &width, &height, &nbChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		std::cout << "Failed to load texture" << std::endl;
	stbi_image_free(data);
	


	glClearColor(0.25f, 0.0f, 0.25f, 1.0f);
	shad.use();
	shad.setUniform3f("col", 0.0f, 0.5f, 0.0f);

	while(!glfwWindowShouldClose(e.w))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		
		glfwSwapBuffers(e.w);
		glfwPollEvents();    
	}

	glfwTerminate();
	return 0;
}
