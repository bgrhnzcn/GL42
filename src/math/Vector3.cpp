/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/13 00:33:12 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Math.hpp"
#include "Vector3.hpp"
#include "geometric.hpp"
#include "exponential.hpp"

gl42::Vector3::Vector3()
	: data(glm::vec3(0)), x(data.x), y(data.y), z(data.z)
{
	//Do nothing
}

gl42::Vector3::Vector3(float a)
	: data(glm::vec3(a)), x(data.x), y(data.y), z(data.z)
{
	//Do nothing
}

gl42::Vector3::Vector3(float x, float y, float z)
	: data(glm::vec3(x, y, z)), x(data.x), y(data.y), z(data.z)
{
	//Do nothing
}

gl42::Vector3::Vector3(const glm::vec3 &vec)
	: data(vec), x(data.x), y(data.y), z(data.z)
{
	//Do nothing
}

gl42::Vector3::~Vector3()
{
	//Do nothing
}

gl42::Vector3 gl42::Vector3::operator+(const Vector3 &vec)
{
	return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

gl42::Vector3 gl42::Vector3::operator-(const Vector3 &vec)
{
	return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

gl42::Vector3 gl42::Vector3::operator*(const float &scaler)
{
	return Vector3(this->x * scaler, this->y * scaler, this->z * scaler);
}

gl42::Vector3 gl42::Vector3::operator/(const float &scaler)
{
	if (scaler == 0)
		return Vector3();
	return Vector3(this->x / scaler, this->y / scaler, this->z / scaler);
}

bool gl42::Vector3::operator==(const Vector3 &vec) const
{
	if (glm::abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (glm::abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	if (glm::abs(this->z - vec.z) > gl42::Math::epsilon)
		return false;
	return true;
}

float gl42::Vector3::dotProdcut(const Vector3 &vec)
{
	return glm::dot(this->data, vec.data);
}

gl42::Vector3 gl42::Vector3::crossProduct(const Vector3 &vec)
{
	return glm::cross(this->data, vec.data);
}

float gl42::Vector3::magnitude()
{
	return glm::sqrt(this->dotProdcut(*this));
}

gl42::Vector3 gl42::Vector3::normalize()
{
	return (*this) / this->magnitude();
}

float gl42::Vector3::distance(const Vector3 &vec)
{
	return ((*this) - vec).magnitude();
}
