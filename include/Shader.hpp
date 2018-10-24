#ifndef SHADER_HPP
#define	SHADER_HPP


#include <glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

class Shader {

private:

	GLuint	_progID;

	GLuint	_compileShader(std::string sourcePath, GLenum shaderType) const;
	void	_linkProgram( GLuint vertID, GLuint fragID );
	void	_debug( GLint status, char c, GLuint ID) const;

public:

	Shader( void );
	Shader( std::string vertPath, std::string fragPath );
	~Shader( void );

	void	use( void ) const;
	void	setUniform3f( const std::string &name, float r, float g, float b ) const;
	
};

#endif
