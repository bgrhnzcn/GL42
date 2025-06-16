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

#include <fstream>
#include <iostream>

#include "OpenGLDecl.hpp"
#include "Error.hpp"
#include "Shader.hpp"

gl42::Shader::Shader(const std::string& sourcePath)
	: m_sourcePath(sourcePath)
{
	readSource();
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER);

	GLCall(m_shaderId = glCreateProgram());

	GLCall(glAttachShader(m_shaderId, vertexShader));
	GLCall(glAttachShader(m_shaderId, fragmentShader));

	GLCall(glLinkProgram(m_shaderId));

	GLCall(glValidateProgram(m_shaderId));

	GLCall(glDeleteShader(vertexShader));
	GLCall(glDeleteShader(fragmentShader));
}

gl42::Shader::~Shader()
{
	GLCall(glDeleteProgram(m_shaderId));
}

void gl42::Shader::readSource()
{
	std::ifstream source;
	source.open(m_sourcePath);
	if (!source.is_open())
	{
		std::cerr << "gl42: Shader: " << m_sourcePath << " could not be opened." << std::endl;
		return;
	}
	while (!source.eof())
		m_sourceCode += source.get();
}

unsigned int gl42::Shader::compileShader(unsigned int type)
{
	const char* code[3]{};
	int length = 0;
	int result;
	
	GLCall(unsigned int shader = glCreateShader(type));

	if (type == GL_VERTEX_SHADER)
	{
		code[0] = "#version 450 core\n";
		code[1] = "#define COMPILING_VERTEX_SHADER\n";
		code[2] = m_sourceCode.c_str();
	}
	else if (type == GL_FRAGMENT_SHADER)
	{
		code[0] = "#version 450 core\n";
		code[1] = "#define COMPILING_FRAGMENT_SHADER\n";
		code[2] = m_sourceCode.c_str();
	}

	GLCall(glShaderSource(shader, 3, code, NULL));
	GLCall(glCompileShader(shader));

	GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
	std::cout << result << std::endl;
	if (result == GL_NO_ERROR)
	{
		GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
		char* infoLog = new char[length];
		GLCall(glGetShaderInfoLog(shader, length, NULL, infoLog));
		delete[] infoLog;
		std::cerr
			<< "gl42: Shader: "
			<< m_sourcePath
			<< (type == GL_VERTEX_SHADER ? " vertex shader" : " fragment shader")
			<< " compilation failed."
			<< std::endl;
		std::cerr << infoLog << std::endl;
	}
	return shader;
}

void gl42::Shader::use() const
{
	GLCall(glUseProgram(m_shaderId));
}

unsigned int gl42::Shader::getShaderId() const
{
	return m_shaderId;
}
