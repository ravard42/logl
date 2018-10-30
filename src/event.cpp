#include "logl.hpp"

static void		key_press(GLFWwindow *window, int key, t_env *e) {
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	e->cam.setKeyEvent(key);
}

static void		key_release(int key, t_env *e) {
	e->cam.unsetKeyEvent(key);
}

static void		my_key_callback(GLFWwindow *window, int key,
		int scancode, int action, int mods) {
	t_env	*e;

	std::cout << key << std::endl;
	(void)scancode;
	(void)mods;
	e = (t_env *)glfwGetWindowUserPointer(window);
	if (action == GLFW_PRESS)
		key_press(window, key, e);
	else if (action == GLFW_RELEASE)
		key_release(key, e);
}

void my_mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	(void)window;
	std::cout << "Cursor tracking => ("<< xpos << ", " << ypos << ")"<< std::endl;
}

void			set_callback(t_env *e) {
	glfwSetKeyCallback(e->w, my_key_callback);
	glfwSetCursorPosCallback(e->w, my_mouse_callback);
}
