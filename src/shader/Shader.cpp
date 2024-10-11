/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:09:03 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/11 17:12:43 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GL_SILENCE_DEPRECATION
#define GL_GLEXT_PROTOTYPES

#include <fstream>
#include <iostream>
#include <GL/gl.h>

#include "Error.hpp"
#include "Shader.hpp"

gl42::Shader::Shader(const std::string& sourcePath)
	: sourcePath(sourcePath)
{
	readSource(sourcePath);
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER);

	GLCall(this->shaderId = glCreateProgram());

	GLCall(glAttachShader(this->shaderId, vertexShader));
	GLCall(glAttachShader(this->shaderId, fragmentShader));

	GLCall(glLinkProgram(this->shaderId));

	GLCall(glValidateProgram(this->shaderId));

	GLCall(glDeleteShader(vertexShader));
	GLCall(glDeleteShader(fragmentShader));
}

gl42::Shader::~Shader()
{
	GLCall(glDeleteProgram(this->shaderId));
}

void gl42::Shader::readSource(const std::string& sourcePath)
{
	std::ifstream source;
	source.open(sourcePath);
	if (!source.is_open())
	{
		std::cerr << "gl42: Shader: " << sourcePath << " could not be opened." << std::endl;
		return;
	}
	while (!source.eof())
		this->sourceCode += source.get();
}

unsigned int gl42::Shader::compileShader(unsigned int type)
{
	const char *code[3];
	int length;
	int result;
	
	GLCall(unsigned int shader = glCreateShader(type));

	if (type == GL_VERTEX_SHADER)
	{
		code[0] = "#version 450 core\n";
		code[1] = "#define COMPILING_VERTEX_SHADER\n";
		code[2] = this->sourceCode.c_str();
	}
	else if (type == GL_FRAGMENT_SHADER)
	{
		code[0] = "#version 450 core\n";
		code[1] = "#define COMPILING_FRAGMENT_SHADER\n";
		code[2] = this->sourceCode.c_str();
	}

	GLCall(glShaderSource(shader, 3, code, NULL));
	GLCall(glCompileShader(shader));

	GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
	std::cout << result << std::endl;
	if (result == GL_NO_ERROR)
	{
		GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
		char log[length];
		GLCall(glGetShaderInfoLog(shader, length, NULL, log));
		std::cerr
			<< "gl42: Shader: "
			<< this->sourcePath
			<< (type == GL_VERTEX_SHADER ? " vertex shader" : " fragment shader")
			<< " compilation failed."
			<< std::endl;
		std::cerr << log << std::endl;
	}
	return shader;
}
//
//void gl42::Shader::combineShader()
//{
//	
//}
//
void gl42::Shader::use()
{
	GLCall(glUseProgram(this->shaderId));
}

unsigned int gl42::Shader::getShaderId()
{
	return this->shaderId;
}
