/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexBuffer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:04:20 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:01 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AssetLoader.hpp"

namespace gl42
{
	class VertexBuffer
	{
		private:
			unsigned int m_vertexBufferID;
		public:
			VertexBuffer(gl42::ObjAsset &asset);
			~VertexBuffer();
		public:
			void bind();
			void unbind();
	};
}