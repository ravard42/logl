#include "Camera.hpp"

Camera::Camera( void ) : _transEvent(0), _rotEvent(0) {
	std::cout << "Camera default constructor called" << std::endl;
}

Camera::~Camera( void ) {
	std::cout << "Camera destructor called" << std::endl;
}

void			Camera::_newTrans( void ) {
	glm::vec3	newTrans(0.0f, 0.0f, 0.0f);

	std::cout << this->_transEvent << std::endl;
	newTrans += (float)((bool)(this->_transEvent & 1) - (bool)(this->_transEvent & 2)) * this->_base[0].xyz();
	newTrans += (float)((bool)(this->_transEvent & 4) - (bool)(this->_transEvent & 8)) * this->_base[1].xyz();
	newTrans += (float)((bool)(this->_transEvent & 16) - (bool)(this->_transEvent & 32)) * this->_base[2].xyz();
if (!glm::isNull(newTrans, 0.005f))
	this->_trans = glm::translate(this->_trans, -0.1f * glm::normalize(newTrans));
}

void			Camera::_newBase( void ) {
	glm::vec3	rot(0.0f, 0.0f, 0.0f);

	rot += (float)((bool)(this->_rotEvent & 1) - (bool)(this->_rotEvent & 2)) * this->_base[0].xyz();
	rot += (float)((bool)(this->_rotEvent & 4) - (bool)(this->_rotEvent & 8)) * this->_base[1].xyz();
	rot += (float)((bool)(this->_rotEvent & 16) - (bool)(this->_rotEvent & 32)) * this->_base[2].xyz();
if (!glm::isNull(rot, 0.005f))
	this->_base = glm::rotate(this->_base, glm::radians(1.0f), glm::normalize(rot));
}

void			Camera::_printV4(glm::vec4 v) const {
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	std::cout << v[2] << std::endl;
	std::cout << v[3] << std::endl;
}

void			Camera::_printM4(glm::mat4 mat) const {
	int		i = -1;

	std::cout <<"--------------------------------------------" << std::endl;
	while (++i < 4)
		std::cout << mat[0][i] << "          |" << mat[1][i] << "          |" << mat[2][i] << "          |" << mat[3][i] << std::endl;
	std::cout <<"--------------------------------------------" << std::endl;
}

void			Camera::setEvent( int key ) {
	int		i = -1;

	while (++i < 6) {
		if (key == Camera::_keyEntry[i])
			this->_transEvent |= (char)glm::pow(2, i);
		else if (key == Camera::_keyEntry[6 + i])
			this->_rotEvent |= (char)glm::pow(2, i);
	}
}

void			Camera::unsetEvent( int key ) {
	int		i = -1;

	while (++i < 6) {
		if (key == Camera::_keyEntry[i])
			this->_transEvent &= ~(char)glm::pow(2, i);
		else if (key == Camera::_keyEntry[6 + i])
			this->_rotEvent &= ~(char)glm::pow(2, i);
	}
}

glm::mat4		Camera::setView( void ) {
	glm::mat4	view;

	this->_newBase();
	this->_printM4(this->_base);
	this->_newTrans();
	view = glm::inverse(this->_base) * this->_trans;
	return (view);
}

short const		Camera::_keyEntry[] = {D, A, E, Q, S, W, UP, DOWN, LEFT, RIGHT, BARREL_L, BARREL_R};
