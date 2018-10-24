#include "logl.hpp"

int	main()
{
	t_env		e;

	if (init_glfw(&e) == -1 || init_glad() == -1)
		return (-1);

	Shader		shad("./shader/vert.glsl", "./shader/frag.glsl");

	float 			vertices[] = {-0.5f, -0.5f, 0.0f,
									-0.5f, 0.5f, 0.0f,
									0.5f, -0.5f, 0.0f,
									0.5f, 0.5f, 0.0f};

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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(0);


	shad.use();
	shad.setUniform3f("col", 0.0f, 0.5f, 0.0f);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

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
