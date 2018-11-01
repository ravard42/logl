#include "Camera.hpp"

Camera::Camera( void ) : _keyEvent(0), _speed(0.1), _firstMouse(true), _sensitivity(0.2f){
	std::cout << "Camera default constructor called" << std::endl;
}

Camera::~Camera( void ) {
	std::cout << "Camera destructor called" << std::endl;
}

void			Camera::_newTrans( void ) {
	glm::vec3	newTrans(0.0f, 0.0f, 0.0f);

	this->_speed = (this->_keyEvent & 64) ? 0.3f : 0.1f;
	newTrans += (float)((bool)(this->_keyEvent & 1) - (bool)(this->_keyEvent & 2)) * this->_base[0].xyz();
	newTrans += (float)((bool)(this->_keyEvent & 4) - (bool)(this->_keyEvent & 8)) * this->_base[1].xyz();
	newTrans += (float)((bool)(this->_keyEvent & 16) - (bool)(this->_keyEvent & 32)) * this->_base[2].xyz();
	if (!glm::isNull(newTrans, 0.5f))
		this->_trans = glm::translate(this->_trans, -this->_speed * glm::normalize(newTrans));
}

void			Camera::_newBase( void ) {
	glm::vec3	rot;

	
	rot = -this->_mouseVector.x * glm::vec3(0.0f, 1.0f, 0.0f);
	if (!glm::isNull(rot, 0.5f))
		this->_base = glm::rotate(glm::mat4(), glm::radians(this->_sensitivity) * glm::length(rot), glm::normalize(rot)) * this->_base;
	rot = this->_mouseVector.y * this->_base[0].xyz();
	if (!glm::isNull(rot, 0.5f))
		this->_base = glm::rotate(glm::mat4(), glm::radians(this->_sensitivity) * glm::length(rot), glm::normalize(rot)) * this->_base;
	this->_mouseVector = glm::vec2(0.0f, 0.0f);
}

void			Camera::_printV4(glm::vec4 v) const {
	std::cout <<"-------------VECTOR--------------------------" << std::endl;
	std::cout << v[0] << std::endl;
	std::cout << v[1] << std::endl;
	std::cout << v[2] << std::endl;
	std::cout << v[3] << std::endl;
	std::cout <<"--------------V_END--------------------------" << std::endl;
}

void			Camera::_printM4(glm::mat4 mat) const {
	int		i = -1;

	std::cout <<"------------------MATRICE----------------------" << std::endl;
	while (++i < 4)
		std::cout << mat[0][i] << "          |" << mat[1][i] << "          |" << mat[2][i] << "          |" << mat[3][i] << std::endl;
	std::cout <<"--------------------M_END-----------------------" << std::endl;
}

void			Camera::setKeyEvent( int key ) {
	int		i = -1;

	while (++i < NB_KEY) 
		if (key == Camera::_keyEntry[i])
			this->_keyEvent |= (char)glm::pow(2, i);
}

void			Camera::unsetKeyEvent( int key ) {
	int		i = -1;

	while (++i < NB_KEY)
		if (key == Camera::_keyEntry[i])
			this->_keyEvent &= ~(char)glm::pow(2, i);
}

void			Camera::mouseEvent( glm::vec2 pos) {
	if (this->_firstMouse && !(this->_firstMouse = false))
		this->_lastMousePos = pos;
	else {
		this->_mouseVector.x = pos.x - this->_lastMousePos.x;
		this->_mouseVector.y = -(pos.y - this->_lastMousePos.y);
		this->_lastMousePos = pos;
	}
}

glm::mat4		Camera::setView( void ) {
	glm::mat4	view;

	this->_newTrans();
	this->_newBase();
	view = glm::transpose(this->_base) * this->_trans;
	return (view);
}

short const		Camera::_keyEntry[] = {X_POS, X_NEG, Y_POS, Y_NEG, Z_POS, Z_NEG, TURBO};
