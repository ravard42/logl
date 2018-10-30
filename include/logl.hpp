#ifndef LOGL_HPP
# define LOGL_HPP

# include <iostream>

# include "glad.h"
# include "glfw3.h"
# include "stb_image.h"
# include "glm.hpp"
# include "gtc/matrix_transform.hpp"
# include "gtc/type_ptr.hpp"



# include "Shader.hpp"
# include "Camera.hpp"


# define WINX 800
# define WINY 640



typedef struct		s_env {

	GLFWwindow		*w;
	Camera			cam;

}					t_env;


int			init_glfw(t_env *e);
int			init_glad(void);
void		set_callback(t_env *e);

#endif
