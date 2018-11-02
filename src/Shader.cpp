#include "Shader.hpp"

Shader::Shader( std::string vertPath, std::string fragPath ) {
	GLuint	vertID;
	GLuint	fragID;

	std::cout << "Shader parametric constructor called" << std::endl;
	vertID = this->_compileShader(vertPath, GL_VERTEX_SHADER);
	fragID = this->_compileShader(fragPath, GL_FRAGMENT_SHADER);
	this->_linkProgram(vertID, fragID);
	glDeleteShader(vertID);
	glDeleteShader(fragID);
}

Shader::~Shader( void ) {
	std::cout << "Shader destructor called" << std::endl;
}

GLuint		Shader::_compileShader(std::string sourcePath, GLenum shaderType) const {
	std::ifstream		ifs(sourcePath);
	std::stringstream	ss;
	std::string			s;
	char const			*str;
	GLuint				shadID = glCreateShader(shaderType);
	GLint				status;
	char				c = (shaderType == GL_VERTEX_SHADER) ? 'v' : 'f';

	ss << ifs.rdbuf();
	s = ss.str();
	str = s.c_str();
	glShaderSource(shadID, 1, &str, NULL);
	glCompileShader(shadID);
	glGetShaderiv(shadID, GL_COMPILE_STATUS, &status);
	this->_debug(status, c, shadID);
	return (shadID);
}

void		Shader::_linkProgram( GLuint vertID, GLuint fragID ) {
	GLint		status;

	this->_progID = glCreateProgram();
	glAttachShader(this->_progID, vertID);
	glAttachShader(this->_progID, fragID);
	glLinkProgram(this->_progID);
	glGetProgramiv(this->_progID, GL_LINK_STATUS, &status);
	this->_debug(status, 'p', this->_progID);
}

void		Shader::_debug(GLint status, char c, GLuint ID) const {
	GLchar		infolog[1024];

	if (c == 'v') {
		if (status)
			std::cout << "compilation du vertexShader réussie" << std::endl;
		else {
			glGetShaderInfoLog(ID, sizeof(infolog), NULL, infolog);
			std::cout << "Error compiling vertexShader : '" << infolog << "'" << std::endl;
		}
	}
	else if ( c == 'f') {
		if (status)
			std::cout << "compilation de fragmentShader réussie" << std::endl;
		else {
			glGetShaderInfoLog(ID, sizeof(infolog), NULL, infolog);
			std::cout << "Error compiling fragmentShader : '" << infolog << "'" << std::endl;
		}
	}
	else if ( c == 'p') {
		if (status)
			std::cout << "compilation du programShader réussie" << std::endl;
		else {
			glGetProgramInfoLog(ID, sizeof(infolog), NULL, infolog);
			std::cout << "Error compiling programShader : '" << infolog << "'" << std::endl;
		}
	}
}

void		Shader::use( void ) const { 
	glUseProgram(this->_progID);
}

void 		Shader::setUVec3(const std::string &name, glm::vec3 v) const { 
	glUniform3f(glGetUniformLocation(this->_progID, name.c_str()), v.r, v.g, v.b); 
} 

void 		Shader::setUMat3(const std::string &name, glm::mat3 m) const { 
	glUniformMatrix3fv(glGetUniformLocation(this->_progID, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));
} 

void 		Shader::setUMat4(const std::string &name, glm::mat4 m) const { 
	glUniformMatrix4fv(glGetUniformLocation(this->_progID, name.c_str()), 1, GL_FALSE, glm::value_ptr(m));
} 
