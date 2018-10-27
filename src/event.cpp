#include "logl.hpp"

static void		key_press(GLFWwindow *window, int key, t_env *e) {
	int		i = -1;

	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	while (++i < 6)
		if (key == Camera::keyEntry[i])
			e->cam.mouv |= (char)glm::pow(2, i);
}

static void		key_release(int key, t_env *e) {
	int		i = -1;

	while (++i < 6)
		if (key == Camera::keyEntry[i])
			e->cam.mouv &= ~(char)glm::pow(2, i);
}

static void		key_callback(GLFWwindow *window, int key,
		int scancode, int action, int mods)
{
	t_env	*e;

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
