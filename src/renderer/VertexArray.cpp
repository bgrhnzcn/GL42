/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexArray.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:05:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:45 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenGLDecl.hpp"
#include "Error.hpp"
#include "VertexArray.hpp"

gl42::VertexArray::VertexArray()
	: vertexArrayID(0)
{
	GLCall(glGenVertexArrays(1, &this->vertexArrayID));
	GLCall(glBindVertexArray(this->vertexArrayID));
}

gl42::VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &this->vertexArrayID));
}

void gl42::VertexArray::bind()
{
	GLCall(glBindVertexArray(this->vertexArrayID));
}

void gl42::VertexArray::unbind()
{
	GLCall(glBindVertexArray(0));
}
