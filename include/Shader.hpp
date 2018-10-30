#ifndef SHADER_HPP
#define	SHADER_HPP


#include <glad.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class Shader {

private:

	GLuint	_progID;

	GLuint	_compileShader(std::string sourcePath, GLenum shaderType) const;
	void	_linkProgram( GLuint vertID, GLuint fragID );
	void	_debug( GLint status, char c, GLuint ID) const;

public:

	Shader( std::string vertPath, std::string fragPath );
	~Shader( void );

	void	use( void ) const;
	void	setUniform3f( const std::string &name, glm::vec3 v ) const;
	void	setUniformMatrix4fv( const std::string &name, glm::mat4 m ) const;
	
};

#endif
