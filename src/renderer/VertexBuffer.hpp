/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexBuffer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:04:20 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:44:27 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "Vertex.hpp"

namespace gl42
{
	class VertexBuffer
	{
		private:
			unsigned int m_vertexBufferID;
		public:
			VertexBuffer(std::vector<Vertex> &vertices);
			~VertexBuffer();
		public:
			void bind();
			void unbind();
	};
}