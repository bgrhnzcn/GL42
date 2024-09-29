/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:09:03 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/29 23:49:52 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GL_SILENCE_DEPRECATION
#define GL_GLEXT_PROTOTYPES

#include <fstream>
#include <iostream>
#include <GL/gl.h>

#include "Shader.hpp"

gl42::Shader::Shader(const std::string& sourcePath)
	: sourcePath(sourcePath)
{
	readSource(sourcePath);
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER);

	this->shaderId = glCreateProgram();

	glAttachShader(this->shaderId, vertexShader);
	glAttachShader(this->shaderId, fragmentShader);

	glLinkProgram(this->shaderId);

	glValidateProgram(this->shaderId);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

gl42::Shader::~Shader()
{
	glDeleteProgram(this->shaderId);
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
	
	unsigned int shader = glCreateShader(type);

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

	glShaderSource(shader, 3, code, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	std::cout << result << std::endl;
	if (result == GL_NO_ERROR)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char log[length];
		glGetShaderInfoLog(shader, length, NULL, log);
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
	glUseProgram(this->shaderId);
}
