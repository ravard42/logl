#include "logl.hpp"

static void		key_press(GLFWwindow *window, int key, t_env *e) {
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	e->cam.setEvent(key);
}

static void		key_release(int key, t_env *e) {
	e->cam.unsetEvent(key);
}

static void		key_callback(GLFWwindow *window, int key,
		int scancode, int action, int mods)
{
	t_env	*e;

	//std::cout << key << std::endl;
	(void)scancode;
	(void)mods;
	e = (t_env *)glfwGetWindowUserPointer(window);
	if (action == GLFW_PRESS)
		key_press(window, key, e);
	else if (action == GLFW_RELEASE)
		key_release(key, e);
}

void			set_callback(t_env *e)
{
	glfwSetKeyCallback(e->w, key_callback);
}
