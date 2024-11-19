/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexBuffer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:04:18 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/19 20:30:47 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <vector>

#include "Error.hpp"
#include "VertexBuffer.hpp"
#include "AssetLoader.hpp"

gl42::VertexBuffer::VertexBuffer(ObjAsset &asset)
{
	GLCall(glGenBuffers(1, &m_vertexBufferID));
	//Bind buffer to array buffer. Array buffer is a type of buffer that stores vertex data.
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID));
	//Copy data to buffer. GL_STATIC_DRAW is a type of draw that tells OpenGL that we are not going to change the data.
	GLCall(glBufferData(GL_ARRAY_BUFFER, asset.vertices.size() * sizeof(gl42::Vertex), asset.vertices.data(), GL_STATIC_DRAW));
}

gl42::VertexBuffer::~VertexBuffer()
{
	
}
