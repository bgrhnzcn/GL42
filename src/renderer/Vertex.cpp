/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:15:34 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:27:57 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vertex.hpp"

gl42::Vertex::Vertex()
{
	//Do Nothing.
}

gl42::Vertex::Vertex(Vector3 position, Vector3 normal, Vector2 uv, Vector4 color)
{
	this->position = position;
	this->normal = normal;
	this->uv = uv;
	this->color = color;
}
