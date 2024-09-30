/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 00:32:47 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Math.hpp"
#include "Vector3.hpp"

gl42::Vector3::Vector3()
	: x(0.0f), y(0.0f)
{
	//Do nothing
}

gl42::Vector3::Vector3(float a)
	: x(a), y(a)
{
	//Do nothing
}

gl42::Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
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
	if (abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	if (abs(this->z - vec.z) > gl42::Math::epsilon)
		return false;
	return true;
}

float gl42::Vector3::dotProdcut(const Vector3 &vec)
{
	return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.y);
}

gl42::Vector3 gl42::Vector3::crossProduct(const Vector3 &vec)
{
	return Vector3(
		(this->y * vec.z) - (this->z * vec.y),
		(this->z * vec.x) - (this->x * vec.z),
		(this->x * vec.y) - (this->y * vec.x));
}

float gl42::Vector3::magnitude()
{
	return sqrtf(this->dotProdcut(*this));
}

gl42::Vector3 gl42::Vector3::normalize()
{
	return (*this) / this->magnitude();
}

float gl42::Vector3::distance(const Vector3 &vec)
{
	return ((*this) - vec).magnitude();
}
