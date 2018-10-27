#include "Camera.hpp"

Camera::Camera( void ) : _pos(glm::vec3(0, 0, 5)), mouv(0) {
	std::cout << "Camera default constructor called" << std::endl;
}

Camera::~Camera( void ) {
	std::cout << "Camera destructor called" << std::endl;
}

void			Camera::transMat( glm::mat4 & trans ) {
	if (this->mouv & 1)
		this->_pos[0] += 0.1;
	if (this->mouv & 2)
		this->_pos[0] -= 0.1;
	if (this->mouv & 4)
		this->_pos[1] += 0.1;
	if (this->mouv & 8)
		this->_pos[1] -= 0.1;
	if (this->mouv & 16)
		this->_pos[2] -= 0.1;
	if (this->mouv & 32)
		this->_pos[2] += 0.1;
	int	i = -1;
	while (++i < 3)
		trans[3][i] = -this->_pos[i];
}

char const		Camera::keyEntry[] = {D, A, E, Q, W, S};
