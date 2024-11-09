/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:11:00 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:44:30 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace gl42
{
	class Vertex
	{
		public:
			Vector3 position;
			Vector3 normal;
			Vector2 uv;
			Vector4 color;
		public:
			Vertex();
			Vertex(Vector3 position, Vector3 normal, Vector2 uv, Vector4 color);
	};
} // namespace gl42
