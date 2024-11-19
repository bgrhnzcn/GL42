/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssetLoader.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:30:14 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/19 20:34:58 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>

#include "Vertex.hpp"

namespace gl42
{
	class ObjAsset
	{
		public:
			ObjAsset(const std::string &filePath);
		public:
			void printAsset();
		public:
			std::vector<Vertex> vertices;
		private:
			std::vector<Face> faces;
		private:
			void getData(const std::string &filePath,
				std::vector<Vector3> &positions,
				std::vector<Vector3> &normals,
				std::vector<Vector2> &textures,
				std::vector<Face> &faces);
	};
} // namespace gl42
