﻿#include "logl.hpp"

void	printM4(glm::mat4 mat)
{
	int		i = -1;

	std::cout <<"--------------" << std::endl;
	while (++i < 4)
		std::cout << mat[0][i] << " | " << mat[1][i] << " | " << mat[2][i] << " | " << mat[3][i] << std::endl;
	std::cout <<"--------------" << std::endl;
}


int	main()
{
	t_env		e;

	if (init_glfw(&e) == -1 || init_glad() == -1)
		return (-1);

	glEnable(GL_DEPTH_TEST);
	Shader		basicShad("./shader/basic/vert.glsl", "./shader/basic/frag.glsl");
	Shader		lightShad("./shader/lighting/vert.glsl", "./shader/lighting/frag.glsl");

	float 			vertices[] = {-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
									-0.5f, 0.5f, -0.5f, 0.0f, 0.0f,
									0.5f, 0.5f, -0.5f, 1.0f, 0.0f,
									0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
									-0.5f, -0.5f, 0.5f, 0.0f, 1.0f,
									-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
									0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
									0.5f, -0.5f, 0.5f, 1.0f, 1.0f};

	unsigned int	indices[] = {0,1,2, 0,2,3, 4,5,6, 4,6,7, 4,5,1, 4,0,1, 3,7,2, 2,6,7, 1,5,6, 1,6,2, 0,3,7, 0,4,7};
	

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


	GLuint	lightVao;
	glGenVertexArrays(1, &lightVao);
	glBindVertexArray(lightVao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(0);

	
	

	
	glm::vec3	lightCol(0.0f, 1.0f, 0.0f);
	glm::vec3	lightPos(1.0f, 0.0f, 0.0f);
	glm::mat4	lightModel;

	lightModel = glm::translate(lightModel, lightPos);
	lightModel = glm::rotate(lightModel, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	lightModel = glm::scale(lightModel, glm::vec3(0.2f));
	basicShad.use();
	basicShad.setUVec3("lightCol", lightCol);
	basicShad.setUMat4("model", lightModel);

	lightShad.use();
	lightShad.setUVec3("lightCol", lightCol);

	
	glClearColor(0.25f, 0.0f, 0.25f, 1.0f);
	while(!glfwWindowShouldClose(e.w))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		basicShad.use();
		basicShad.setUMat4("projView", e.cam.setProjView());
		glBindVertexArray(lightVao);
		glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		
		lightShad.use();
		lightShad.setUMat4("projView", e.cam.setProjView());
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		
		glfwSwapBuffers(e.w);
		glfwPollEvents();

	}

	glDeleteVertexArrays(1, &lightVao);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glDeleteTextures(1, &tex);
	glfwTerminate();
	return 0;
}
