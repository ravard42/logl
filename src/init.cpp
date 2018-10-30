#include "logl.hpp"

int			init_glfw(t_env *e) {
	if (!glfwInit()) {
		std::cout << "an error occured in glfwInit() ..." << std::endl;
		return (0);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(e->w = glfwCreateWindow(WINX, WINY, "LearnOpenGL", NULL, NULL))) {
		std::cout << "an error occured in glfwCreateWindow() ..." << std::endl;
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(e->w);
	glfwSetWindowUserPointer(e->w, e);
	glfwSetInputMode(e->w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	set_callback(e);
	return (1);
}

int			init_glad(void) {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "an error occured in gladLoadGLLoader() ..." << std::endl;
		glfwTerminate();
		return (-1);
	}
	return (1);
}
