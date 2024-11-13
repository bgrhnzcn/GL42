/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssetLoader.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:30:14 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/14 02:22:50 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		private:
			std::vector<Vertex> vertices;
			std::vector<Face> faces;
		private:
			void getData(const std::string &filePath,
				std::vector<Vector3> &positions,
				std::vector<Vector3> &normals,
				std::vector<Vector2> &textures,
				std::vector<Face> &faces);
			void createVBO();
	};
} // namespace gl42
