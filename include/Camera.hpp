#ifndef CAMERA_HPP
# define CAMERA_HPP

//#include <glad.h>

# include <iostream>
# define GLM_FORCE_SWIZZLE
# include "glm.hpp"
# include "gtc/matrix_transform.hpp"
# include "gtc/type_ptr.hpp"
#include "gtx/vector_query.hpp"

# define X_POS 68
# define X_NEG 65
# define Y_POS 66
# define Y_NEG 86
# define Z_POS 83
# define Z_NEG 87
# define BAR_L 81
# define BAR_R 69

class Camera {

private:
	static char const	_keyEntry[];
	char					_keyEvent;
	glm::mat4			_trans;
	glm::mat4			_base;
	void				_newTrans( void );
	void				_newBase( void );
	void				_printV4(glm::vec4 v) const;
	void				_printM4(glm::mat4 mat) const;

public:

	Camera( void );
	~Camera( void );

	void				setKeyEvent( int key );
	void				unsetKeyEvent( int key );
	glm::mat4			setView( void );

};

#endif
