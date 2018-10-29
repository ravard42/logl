#include "Camera.hpp"

Camera::Camera( void ) : _transEvent(0), _rotEvent(0) {
	std::cout << "Camera default constructor called" << std::endl;
}

Camera::~Camera( void ) {
	std::cout << "Camera destructor called" << std::endl;
}

void			Camera::_newTrans( void ) {
	glm::vec3	newTrans(0.0f, 0.0f, 0.0f);

	newTrans += (float)((bool)(this->_transEvent & 1) - (bool)(this->_transEvent & 2)) * this->_base[0].xyz();
	newTrans += (float)((bool)(this->_transEvent & 4) - (bool)(this->_transEvent & 8)) * this->_base[1].xyz();
	newTrans += (float)((bool)(this->_transEvent & 16) - (bool)(this->_transEvent & 32)) * this->_base[2].xyz();
	if (!glm::isNull(newTrans, 0.005f))
		this->_trans = glm::translate(this->_trans, -0.1f * glm::normalize(newTrans));
}

glm::mat4		Camera::_myRotateMatrix(float rad, glm::vec3 n) {
	glm::mat4	tmp1;
	glm::mat4	tmp2;
	glm::mat4	rot;

	tmp1[0] = glm::vec4(glm::vec3(glm::pow(n.x, 2), n.x * n.y, n.x * n.z), 0.0f);
	tmp1[1] = glm::vec4(glm::vec3(n.x * n.y, glm::pow(n.y, 2), n.y * n.z), 0.0f);
	tmp1[2] = glm::vec4(glm::vec3(n.x * n.z, n.y * n.z, glm::pow(n.z, 2)), 0.0f);
	tmp2[0] = glm::vec4(glm::vec3(0.0f, n.z, -n.y), 0.0f);
	tmp2[1] = glm::vec4(glm::vec3(-n.z, 0.0f, n.x), 0.0f);
	tmp2[2] = glm::vec4(glm::vec3(n.y, -n.x, 0.0f), 0.0f);

	rot = cos(rad) * glm::mat4() + (1 - cos(rad)) * tmp1 + sin(rad) * tmp2;
	rot[3][3] = 1;
	return (rot);
}

void			Camera::_newBase( void ) {
	glm::vec3	rot(0.0f, 0.0f, 0.0f);

	rot += (float)((bool)(this->_rotEvent & 1) - (bool)(this->_rotEvent & 2)) * this->_base[0].xyz();
	rot += (float)((bool)(this->_rotEvent & 4) - (bool)(this->_rotEvent & 8)) * this->_base[1].xyz();
	rot += (float)((bool)(this->_rotEvent & 16) - (bool)(this->_rotEvent & 32)) * this->_base[2].xyz();
	if (!glm::isNull(rot, 0.005f))
		this->_base = this->_myRotateMatrix(glm::radians(1.0f), glm::normalize(rot)) * this->_base;
		//this->_base = glm::rotate(this->_base, glm::radians(1.0f), glm::normalize(rot));
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
	//std::cout << "BASE" << std::endl;
	//this->_printM4(this->_base);
	//std::cout << "BASE INVERSE" << std::endl;
	this->_printM4(glm::inverse(this->_base));
	std::cout << "BASE TRANSPOSE" << std::endl;
	this->_printM4(glm::transpose(this->_base));
	this->_newTrans();
	view = glm::inverse(this->_base) * this->_trans;
	return (view);
}

short const		Camera::_keyEntry[] = {D, A, E, Q, S, W, UP, DOWN, LEFT, RIGHT, BARREL_L, BARREL_R};
