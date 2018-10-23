/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 08:34:09 by ravard            #+#    #+#             */
/*   Updated: 2018/10/23 01:35:19 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shader.hpp"



//private member functions

GLuint		Shader::_compileShader(std::string sourcePath, GLenum shaderType) {
	GLuint				shadID;
	std::ifstream		ifs(sourcePath);
	std::string			tmp[2];
	char const			*str;
	GLint					status;

	shadID = glCreateShader(shaderType);
	while (getline(ifs, tmp[1]))
	{
		tmp[1] += "\n";
		tmp[0] += tmp[1];
	}
	ifs.close();
	str = tmp[0].c_str();
	glShaderSource(shadID, 1,
			(const GLchar *const *)&str, NULL);
	glCompileShader(shadID);
	glGetShaderiv(shadID, GL_COMPILE_STATUS, &status);
	this->_debug(status, 'v');
	return (shadID);
}

GLuint		Shader::_linkProgram( void ) {
	GLuint	progID;
	GLint		status;

	progID = glCreateProgram();
	glAttachShader(progID, this->_vert);
	glAttachShader(progID, this->_frag);
	glLinkProgram(progID);
	glGetProgramiv(progID, GL_LINK_STATUS, &status);
	this->_debug(status, 'p');

	glDetachShader(this->_prog, this->_vert);
	glDetachShader(this->_prog, this->_frag);
	glDeleteShader(this->_vert);
	glDeleteShader(this->_frag);
	
	
	return (progID);

}


// Construct, Destruct & coplien form

Shader::Shader( void ) {
	std::cout << "Shader default constructor called" << std::endl;
}

Shader::Shader( std::string vertPath, std::string fragPath ) {
	std::cout << "Shader parametric constructor called" << std::endl;
	this->_vert = this->_compileShader(vertPath, GL_VERTEX_SHADER);
	this->_frag = this->_compileShader(fragPath, GL_FRAGMENT_SHADER);
	this->_prog = this->_linkProgram();
}

Shader::Shader( Shader const & src) {
	std::cout << "Shader copy constructor called" << std::endl;
	*this = src;
}

Shader::~Shader( void ) {
	std::cout << "Shader destructor called" << std::endl;
}

Shader &			Shader::operator=( Shader const & src ) {
	
	this->_vert = src.getVertID();
	this->_frag = src.getFragID();
	this->_prog = src.getProgID();
	return *this;
}

GLuint			Shader::getVertID( void ) const {
	return this->_vert;
}

GLuint			Shader::getFragID( void ) const {
	return this->_frag;
}

GLuint			Shader::getProgID( void ) const {
	return this->_prog;
}

void				Shader::_debug(GLint status, char c)
{
	GLchar		infolog[1024];

	if (c == 'v') {
		if (status)
			std::cout << "compilation du vertexShader réussie" << std::endl;
		else {
			glGetShaderInfoLog(this->_vert, sizeof(infolog), NULL, infolog);
			std::cout << "Error compiling vertexShader : '" << infolog << "'" << std::endl;
		}
	}
	else if ( c == 'f') {
		if (status)
			std::cout << "compilation de fragmentShader réussie" << std::endl;
		else {
			glGetShaderInfoLog(this->_frag, sizeof(infolog), NULL, infolog);
			std::cout << "Error compiling fragmentShader : '" << infolog << "'" << std::endl;
		}
	}
	else if ( c == 'p') {
		if (status)
			std::cout << "compilation du programShader réussie" << std::endl;
		else {
			glGetProgramInfoLog(this->_prog, sizeof(infolog), NULL, infolog);
			std::cout << "Error compiling programShader : '" << infolog << "'" << std::endl;
		}
	}
}

std::ostream &		operator<<( std::ostream & o, Shader const & rhs ) {
    o << "vertex Id : " << rhs.getVertID() << std::endl;
    o << "fragment Id : " << rhs.getFragID() << std::endl;
    o << "program Id : " << rhs.getProgID() << std::endl;
    return o;
};
