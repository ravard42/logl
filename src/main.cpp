#include "logl.hpp"

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
	Shader		liShad("./shader/light/v.glsl", "./shader/light/f.glsl");
	Shader		objShad("./shader/object/v.glsl", "./shader/object/f.glsl");

	float vertices[] = {
		    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
		     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  0.0f, -1.0f, 
		     0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, -1.0f, 
		     0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, -1.0f, 
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  0.0f, -1.0f, 
		    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, -1.0f, 
		
		    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		     0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		     0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		     0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		     0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		     0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f
		};

	GLuint	vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
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


	GLuint	liVao;
	glGenVertexArrays(1, &liVao);
	glBindVertexArray(liVao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(0);


	float			t;
	glm::vec2	vt;


	glm::vec3	liCol;
	glm::vec3	liPos;
	glm::mat4	liModel;

	

	
	glm::vec3	objPos(0.0f, 0.0f, 0.0f);
	glm::mat4	objModel;
	glm::mat3	objNormalMatrix;
//	objModel = glm::translate(objModel, objPos);
//	objModel = glm::rotate(objModel, glm::radians(45.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	objNormalMatrix = glm::transpose(glm::inverse(glm::mat3(objModel)));
	objShad.use();
	objShad.setUMat4("model", objModel);
	objShad.setUMat3("normalMatrix", objNormalMatrix);

	
	//glClearColor(0.25f, 0.0f, 0.25f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	while(!glfwWindowShouldClose(e.w))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		t = (float)glfwGetTime();	
		vt = glm::vec2(cos(t), sin(t));
	
		std::cout << t << std::endl;
	
		liCol = glm::vec3(abs(vt.x), vt.x + vt.y, abs(vt.y));
		liPos = glm::vec3(vt.y * 3.0f, 1.0f, vt.x * 3.0f);
		liModel = glm::mat4();
		liModel = glm::translate(liModel, liPos);
		liModel = glm::rotate(liModel, glm::radians(t * 42), glm::vec3(0.0f, 0.0f, 1.0f));
		liModel = glm::scale(liModel, glm::vec3(0.2f));
		liShad.use();
		liShad.setUVec3("Col", liCol);
		liShad.setUMat4("projViewModel", e.cam.setProjViewModel(liModel));
		glBindVertexArray(liVao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		
		objShad.use();
		objShad.setUVec3("lightCol", liCol);
		objShad.setUVec3("lightPos", liPos);
		objShad.setUVec3("viewPos", e.cam.sendViewPos());
		objShad.setUMat4("projViewModel", e.cam.setProjViewModel(objModel));
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		
		glfwSwapBuffers(e.w);
		glfwPollEvents();

	}

	glDeleteVertexArrays(1, &liVao);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteTextures(1, &tex);
	glfwTerminate();
	return 0;
}
