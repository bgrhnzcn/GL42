/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexBuffer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:04:18 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:27:17 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <vector>

#include "Error.hpp"
#include "VertexBuffer.hpp"
#include "Vertex.hpp"

gl42::VertexBuffer::VertexBuffer(std::vector<Vertex> &vertices)
{
	(void)vertices;
	GLCall(glGenBuffers(1, &m_vertexBufferID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID));
}

gl42::VertexBuffer::~VertexBuffer()
{
	
}
