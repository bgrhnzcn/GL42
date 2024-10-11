/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector4.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/11 17:19:31 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Math.hpp"
#include "Vector4.hpp"

gl42::Vector4::Vector4()
	: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
	//Do nothing
}

gl42::Vector4::Vector4(float a)
	: x(a), y(a), z(a), w(a)
{
	//Do nothing
}

gl42::Vector4::Vector4(float x, float y, float z, float w)
	: x(x), y(y), z(z), w(w)
{
	//Do nothing
}

gl42::Vector4::~Vector4()
{
	//Do nothing
}

gl42::Vector4 gl42::Vector4::operator+(const Vector4 &vec)
{
	return Vector4(this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w);
}

gl42::Vector4 gl42::Vector4::operator-(const Vector4 &vec)
{
	return Vector4(this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w);
}

gl42::Vector4 gl42::Vector4::operator*(const float &scaler)
{
	return Vector4(this->x * scaler, this->y * scaler, this->z * scaler, this->w * scaler);
}

gl42::Vector4 gl42::Vector4::operator/(const float &scaler)
{
	if (scaler == 0)
		return Vector4();
	return Vector4(this->x / scaler, this->y / scaler, this->z / scaler, this->w / scaler);
}

bool gl42::Vector4::operator==(const Vector4 &vec) const
{
	if (abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	if (abs(this->z - vec.z) > gl42::Math::epsilon)
		return false;
	if (abs(this->w - vec.w) > gl42::Math::epsilon)
		return false;
	return true;
}

float gl42::Vector4::dotProdcut(const Vector4 &vec)
{
	return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z) + (this->w * vec.w);
}

float gl42::Vector4::magnitude()
{
	return sqrtf(this->dotProdcut(*this));
}

gl42::Vector4 gl42::Vector4::normalize()
{
	return (*this) / this->magnitude();
}

float gl42::Vector4::distance(const Vector4 &vec)
{
	return ((*this) - vec).magnitude();
}
