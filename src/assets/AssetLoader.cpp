/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssetLoader.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:54:04 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/18 01:13:05 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <iostream>

#include "AssetLoader.hpp"

gl42::ObjAsset::ObjAsset(const std::string &filePath)
{
	std::vector<Vector3> positions;
	std::vector<Vector3> normals;
	std::vector<Vector2> textures;
	std::vector<Face> faces;
	getData(filePath, positions, normals, textures, faces);

	for (size_t j = 0; j < faces.size(); j++)
	{
		Face face = faces[j];
		Face tempFace;
		if (face.positionIndices.size() > 3)
		{
			;
		}
	}

	Vertex temp;
	for (size_t i = 0; i < positions.size(); i++)
	{
		temp.position = positions[i];
	}
}

void gl42::ObjAsset::printAsset()
{
	for (Vertex vertex : vertices)
		vertex.print();
	for (Face face : faces)
		face.print();
}

void gl42::ObjAsset::getData(const std::string &filePath,
	std::vector<Vector3> &positions,
	std::vector<Vector3> &normals,
	std::vector<Vector2> &textures,
	std::vector<Face> &faces)
{
	std::fstream file(filePath);

	std::string line;
	if (!file.is_open())
		throw std::runtime_error("Asset Loading failed.");
	while (std::getline(file, line))
	{
		std::string prefix;
		std::stringstream str(line);
		str >> prefix;
		if (prefix == "v")
		{
			Vector3 pos;
			str >> pos.x >> pos.y >> pos.z;
			positions.push_back(pos);
		}
		else if (prefix == "vn")
		{
			Vector3 norm;
			str >> norm.x >> norm.y >> norm.z;
			normals.push_back(norm);
		}
		else if (prefix == "vt")
		{
			Vector2 uv;
			str >> uv.x >> uv.y;
			textures.push_back(uv);
		}
		else if (prefix == "f")
		{
			Face face;
			std::string faceEntry;
			while (str >> faceEntry)
			{
				std::stringstream vertexStr(faceEntry);
				if (faceEntry.find("//") != std::size_t(-1))
				{
					std::string val;
					if (std::getline(vertexStr, val, '/'))
						face.positionIndices.push_back(std::stoi(val));
					if (std::getline(vertexStr, val, '/'))
						face.normalIndices.push_back(std::stoi(val));
				}
				else
				{
					std::string val;
					if (std::getline(vertexStr, val, '/'))
						face.positionIndices.push_back(std::stoi(val));
					if (std::getline(vertexStr, val, '/'))
						face.textureIndices.push_back(std::stoi(val));
					if (std::getline(vertexStr, val, '/'))
						face.normalIndices.push_back(std::stoi(val));
				}
			}
			face.print();
			faces.push_back(face);
		}
	}
}
