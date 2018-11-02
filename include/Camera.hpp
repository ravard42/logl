#ifndef CAMERA_HPP
# define CAMERA_HPP

//#include <glad.h>

# include <iostream>
# define GLM_FORCE_SWIZZLE
# include "glm.hpp"
# include "gtc/matrix_transform.hpp"
# include "gtc/type_ptr.hpp"
#include "gtx/vector_query.hpp"

# define WINX 800
# define WINY 640

# define X_POS 68
# define X_NEG 65
# define Y_POS 86
# define Y_NEG 67
# define Z_POS 83
# define Z_NEG 87
# define TURBO 340

#define NB_KEY 7

#define SPEED	0.03

class Camera {

private:
	static short const	_keyEntry[];
	char						_keyEvent;

	float					_speed;
	glm::mat4			_trans;
	glm::mat4			_base;
	bool					_firstMouse;	
	glm::vec2			_lastMousePos;
	float					_sensitivity;
	glm::vec2			_mouseVector;
	float					_fov;

	void				_newTrans( void );
	void				_newBase( void );

	void				_printV4(glm::vec4 v) const;
	void				_printM4(glm::mat4 mat) const;

public:

	Camera( void );
	~Camera( void );

	void				setKeyEvent( int key );
	void				unsetKeyEvent( int key );
	void				mouseEvent( glm::vec2 pos );
	void				scrollEvent( double offset );
	glm::mat4		setProjViewModel( glm::mat4 model );
	glm::vec3		sendViewPos( void ) const;
};

#endif
