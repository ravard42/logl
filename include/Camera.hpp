#ifndef CAMERA_HPP
# define CAMERA_HPP

//#include <glad.h>

# include <iostream>
# define GLM_FORCE_SWIZZLE
# include "glm/glm.hpp"
# include "glm/gtc/matrix_transform.hpp"
# include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/vector_query.hpp"

# define D 68
# define A 65
# define E 69
# define Q 81
# define S 83
# define W 87

# define UP 264
# define DOWN 265
# define LEFT 263
# define RIGHT 262
# define BARREL_L 345
# define BARREL_R 320

class Camera {

private:
	static short const	_keyEntry[];
	char				_transEvent;
	char				_rotEvent;
	glm::mat4			_trans;
	glm::mat4			_base;
	void				_newTrans( void );
	glm::mat4			_myRotateMatrix(float rad, glm::vec3 n);
	void				_newBase( void );
	void				_printV4(glm::vec4 v) const;
	void				_printM4(glm::mat4 mat) const;

public:

	Camera( void );
	~Camera( void );

	void				setEvent( int key );
	void				unsetEvent( int key );
	glm::mat4			setView( void );

};

#endif
