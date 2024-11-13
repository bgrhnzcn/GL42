/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:11:00 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/13 23:23:45 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace gl42
{
	class Vertex
	{
		public:
			Vertex();
			Vertex(Vector3 position, Vector3 normal, Vector2 texture, Vector4 color);
		public:
			void print();
		public:
			Vector3 position;
			Vector3 normal;
			Vector2 texture;
			Vector4 color = 0;
	};

	class Face
	{
		public:
			void print();
		public:
			std::vector<int> positionIndices;
			std::vector<int> normalIndices;
			std::vector<int> textureIndices;
	};
} // namespace gl42
