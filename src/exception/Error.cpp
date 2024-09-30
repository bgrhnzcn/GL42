/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:09:00 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/30 15:23:44 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

void gl42::ClearErr()
{
	while (glGetError() != GL_NO_ERROR)
	{
		// Do nothing
	}
}

static std::string GetGLErrorMessage(unsigned int errorVal)
{
	std::string errorMessage;
	switch (errorVal)
	{
	case GL_INVALID_ENUM:
		errorMessage = "GL_INVALID_ENUM";
		break;
	case GL_INVALID_VALUE:
		errorMessage = "GL_INVALID_VALUE";
		break;
	case GL_INVALID_OPERATION:
		errorMessage = "GL_INVALID_OPERATION";
		break;
	case GL_STACK_OVERFLOW:
		errorMessage = "GL_STACK_OVERFLOW";
		break;
	case GL_STACK_UNDERFLOW:
		errorMessage = "GL_STACK_UNDERFLOW";
		break;
	case GL_OUT_OF_MEMORY:
		errorMessage = "GL_OUT_OF_MEMORY";
		break;
	case GL_INVALID_FRAMEBUFFER_OPERATION:
		errorMessage = "GL_INVALID_FRAMEBUFFER_OPERATION";
		break;
	case GL_CONTEXT_LOST:
		errorMessage = "GL_CONTEXT_LOST";
		break;
	case GL_TABLE_TOO_LARGE:
		errorMessage = "GL_TABLE_TOO_LARGE";
		break;
	default:
		errorMessage = "UNKNOWN_ERROR";
		break;
	}
	return (errorMessage);
}

bool gl42::CheckErr(const char *function, const char *file, int line)
{
	unsigned int errorVal = glGetError();
	if (errorVal != GL_NO_ERROR)
	{
		std::cerr << "[GL42 Error] " << GetGLErrorMessage(errorVal) << ":" << function << " in file " << file << ":" << line << std::endl;
		return (false);
	}
	return (true);
}
