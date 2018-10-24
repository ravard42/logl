#ifndef SHADER_HPP
#define	SHADER_HPP


#include <glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

class Shader {

private:

	GLuint	_vert;
	GLuint	_frag;
	GLuint	_prog;

	GLuint	_compileShader(std::string sourcePath, GLenum shaderType);
	GLuint	_linkProgram( void );
	void	_debug( GLint status, char c);

public:


	Shader( void );
	Shader( std::string vertPath, std::string fragPath );
	Shader( Shader const & src );
	~Shader( void );
	Shader	&		operator=( Shader const & src );

	GLuint	getVertID( void ) const;
	GLuint	getFragID( void ) const;
	GLuint	getProgID( void ) const;

	
};

std::ostream &		operator<<( std::ostream & o, Shader const & rhs );

#endif
