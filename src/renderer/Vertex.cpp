/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:15:34 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/13 21:54:28 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Vertex.hpp"

gl42::Vertex::Vertex()
{
	//Do Nothing.
}

gl42::Vertex::Vertex(Vector3 position, Vector3 normal, Vector2 texture, Vector4 color)
{
	this->position = position;
	this->normal = normal;
	this->texture = texture;
	this->color = color;
}

void gl42::Vertex::print()
{
	std::cout << "Position: {"
			  << position.x << ", "
			  << position.y << ", "
			  << position.z << "}" << std::endl;
	std::cout << "Textures: {"
			  << texture.x << ", "
			  << texture.y << "}" << std::endl;
	std::cout << "Normal: {"
			  << normal.x << ", "
			  << normal.y << ", "
			  << normal.z << "}" << std::endl;
}

void gl42::Face::print()
{
	std::cout << "Face:\n" << "\tPositionInd: ";
	for (int index : positionIndices)
		std::cout << index << " ";
	std::cout << std::endl << "\tNormalInd: ";
	for (int index : normalIndices)
		std::cout << index << " ";
	std::cout << std::endl << "\tTextureInd: ";
	for (int index : textureIndices)
		std::cout << index << " ";
	std::cout << std::endl;
}
