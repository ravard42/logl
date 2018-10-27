#ifndef CAMERA_HPP
# define CAMERA_HPP

//#include <glad.h>

# include <iostream>
# include "glm/glm.hpp"
# include "glm/gtc/matrix_transform.hpp"
# include "glm/gtc/type_ptr.hpp"

# define D 68
# define A 65
# define E 69
# define Q 81
# define W 87
# define S 83

class Camera {

private:
	glm::vec3	_pos;
	glm::mat4	_base;

public:

	Camera( void );
	~Camera( void );

	static char const	keyEntry[];
	char				mouv;
	void				transMat( glm::mat4 & trans );

};

#endif
