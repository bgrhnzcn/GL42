/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/09 21:00:55 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Math.hpp"
#include "Vector2.hpp"

gl42::Vector2::Vector2()
	: x(0), y(0)
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

gl42::Vector2& gl42::Vector2::operator=(const Vector2& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

gl42::Vector2 gl42::Vector2::operator+(const Vector2 &vec) const
{
	return Vector2(this->x + vec.x, this->y + vec.y);
}

gl42::Vector2 gl42::Vector2::operator-(const Vector2 &vec) const
{
	return Vector2(this->x - vec.x, this->y - vec.y);
}

gl42::Vector2 gl42::Vector2::operator*(float scaler) const
{
	return Vector2(this->x * scaler, this->y * scaler);
}

gl42::Vector2 gl42::Vector2::operator/(float scaler) const
{
	if (scaler == 0)
		return Vector2();
	return Vector2(this->x / scaler, this->y / scaler);
}

bool gl42::Vector2::operator==(const Vector2 &vec) const
{
	if (gl42::Math::abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (gl42::Math::abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	return (true);
}

float gl42::Vector2::dotProduct(const Vector2 &vec) const
{
	return (this->x * vec.x) + (this->y * vec.y);
}

float gl42::Vector2::magnitude() const
{
	return gl42::Math::sqrt(dotProduct(*this));
}

gl42::Vector2 gl42::Vector2::normalize() const
{
	return (*this) / magnitude();
}

float gl42::Vector2::distance(const Vector2 &to) const
{
	return ((*this) - to).magnitude();
}
