/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 00:33:00 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Math.hpp"
#include "Vector2.hpp"

gl42::Vector2::Vector2()
	: x(0.0f), y(0.0f)
{
	//Do nothing
}

gl42::Vector2::Vector2(float a)
	: x(a), y(a)
{
	//Do nothing
}

gl42::Vector2::Vector2(float x, float y)
	: x(x), y(y)
{
	//Do nothing
}

gl42::Vector2::~Vector2()
{
	//Do nothing
}

gl42::Vector2 gl42::Vector2::operator+(const Vector2 &vec) const
{
	return Vector2(this->x + vec.x, this->y + vec.y);
}

gl42::Vector2 gl42::Vector2::operator-(const Vector2 &vec) const
{
	return Vector2(this->x - vec.x, this->y - vec.y);
}

gl42::Vector2 gl42::Vector2::operator*(const float &scaler) const
{
	return Vector2(this->x * scaler, this->y * scaler);
}

gl42::Vector2 gl42::Vector2::operator/(const float &scaler) const
{
	if (scaler == 0)
		return Vector2();
	return Vector2(this->x / scaler, this->y / scaler);
}

bool gl42::Vector2::operator==(const Vector2 &vec) const
{
	if (abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	return (true);
}

float gl42::Vector2::dotProdcut(const Vector2 &vec) const
{
	return (this->x * vec.x) + (this->y * vec.y);
}

float gl42::Vector2::magnitude() const
{
	return sqrtf(this->dotProdcut(*this));
}

gl42::Vector2 gl42::Vector2::normalize() const
{
	return (*this) / this->magnitude();
}

float gl42::Vector2::distance(const Vector2 &vec) const
{
	return ((*this) - vec).magnitude();
}
