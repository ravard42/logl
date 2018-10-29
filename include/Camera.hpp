#ifndef CAMERA_HPP
# define CAMERA_HPP

//#include <glad.h>

# include <iostream>
# define GLM_FORCE_SWIZZLE
# include "glm/glm.hpp"
# include "glm/gtc/matrix_transform.hpp"
# include "glm/gtc/type_ptr.hpp"

# define D 68
# define A 65
# define E 69
# define Q 81
# define W 87
# define S 83

# define RIGHT 262
# define LEFT 263
# define DOWN 264
# define UP 265
# define BARREL_R 320
# define BARREL_L 345

class Camera {

private:
	static short const	_keyEntry[];
	char				_transEvent;
	char				_rotEvent;
	glm::mat4			_trans;
	glm::mat4			_base;
	void				_newTrans( void );
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
