/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector4.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/13 00:37:38 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Math.hpp"
#include "Vector4.hpp"
#include "geometric.hpp"
#include "exponential.hpp"

gl42::Vector4::Vector4()
	: data(glm::vec4(0)), x(data.x), y(data.y), z(data.z), w(data.w)
{
	//Do nothing
}

gl42::Vector4::Vector4(float a)
	: data(glm::vec4(a)), x(data.x), y(data.y), z(data.z), w(data.w)
{
	//Do nothing
}

gl42::Vector4::Vector4(float x, float y, float z, float w)
	: data(glm::vec4(x, y, z, w)), x(data.x), y(data.y), z(data.z), w(data.w)
{
	//Do nothing
}

gl42::Vector4::Vector4(const glm::vec4 &vec)
	: data(vec), x(data.x), y(data.y), z(data.z), w(data.w)
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
	if (glm::abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (glm::abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	if (glm::abs(this->z - vec.z) > gl42::Math::epsilon)
		return false;
	if (glm::abs(this->w - vec.w) > gl42::Math::epsilon)
		return false;
	return true;
}

float gl42::Vector4::dotProdcut(const Vector4 &vec)
{
	return (this->data.x * vec.x) + (this->data.y * vec.y)
		 + (this->data.z * vec.z) + (this->data.w * vec.w);
}

float gl42::Vector4::magnitude()
{
	return glm::sqrt(this->dotProdcut(*this));
}

gl42::Vector4 gl42::Vector4::normalize()
{
	return (*this) / this->magnitude();
}

float gl42::Vector4::distance(const Vector4 &vec)
{
	return ((*this) - vec).magnitude();
}
