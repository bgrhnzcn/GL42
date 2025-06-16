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

gl42::Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
	: m_vertexPath(vertexPath), m_fragmentPath(fragmentPath)
{
	readSource();
	unsigned int vertexShader = compileVertexShader();
	unsigned int fragmentShader = compileFragmentShader();

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
	
	for (auto& line : m_vertexSourceCode)
		delete[] line;

	for (auto& line : m_fragmentSourceCode)
		delete[] line;
}

void gl42::Shader::readSource()
{
	std::string line;
	std::ifstream source;

	// Vertex shader source code reading
	source.open(m_vertexPath);
	if (!source.is_open())
	{
		std::cerr << "gl42: Shader: " << m_vertexPath << " could not be opened." << std::endl;
		return;
	}
	while (std::getline(source, line))
	{
		GLchar* linePtr = new GLchar[line.size() + 2]{ 0 };
		std::copy(line.begin(), line.end(), linePtr);
		linePtr[line.size()] = '\n';
		m_vertexSourceCode.push_back(linePtr);
	}
	source.close();
	
	// Fragment shader source code reading
	source.open(m_fragmentPath);
	if (!source.is_open())
	{
		std::cerr << "gl42: Shader: " << m_fragmentPath << " could not be opened." << std::endl;
		return;
	}
	while (std::getline(source, line))
	{
		GLchar* linePtr = new GLchar[line.size() + 2] {0};
		std::copy(line.begin(), line.end(), linePtr);
		linePtr[line.size()] = '\n';
		m_fragmentSourceCode.push_back(linePtr);
	}
	source.close();
}

unsigned int gl42::Shader::compileVertexShader()
{
	GLCall(unsigned int shader = glCreateShader(GL_VERTEX_SHADER));

	GLCall(glShaderSource(shader, m_vertexSourceCode.size(), m_vertexSourceCode.data(), nullptr));
	GLCall(glCompileShader(shader));

	GLint result = GL_NO_ERROR;
	GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
	if (result == GL_NO_ERROR)
	{
		GLint length = 0;
		GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
		char* infoLog = new char[length];
		GLCall(glGetShaderInfoLog(shader, length, NULL, infoLog));
		delete[] infoLog;
		std::cerr
			<< "gl42: Shader: "
			<< m_vertexPath
			<< " vertex shader compilation failed.\n"
			<< std::endl;
		std::cerr << infoLog << std::endl;
	}
	return shader;
}

unsigned int gl42::Shader::compileFragmentShader()
{
	GLCall(unsigned int shader = glCreateShader(GL_FRAGMENT_SHADER));

	GLCall(glShaderSource(shader, m_fragmentSourceCode.size(), m_fragmentSourceCode.data(), nullptr));
	GLCall(glCompileShader(shader));

	GLint result = GL_NO_ERROR;
	GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
	if (result == GL_NO_ERROR)
	{
		GLint length = 0;
		GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
		char* infoLog = new char[length];
		GLCall(glGetShaderInfoLog(shader, length, NULL, infoLog));
		delete[] infoLog;
		std::cerr
			<< "gl42: Shader: "
			<< m_fragmentPath
			<< " fragment shader compilation failed.\n"
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
