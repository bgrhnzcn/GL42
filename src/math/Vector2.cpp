/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:33:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/13 03:12:17 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Math.hpp"
#include "Vector2.hpp"
#include "geometric.hpp"
#include "exponential.hpp"

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

gl42::Vector2::Vector2(const glm::vec2 &vec)
	: x(vec.x), y(vec.y)
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
	if (glm::abs(this->x - vec.x) > gl42::Math::epsilon)
		return false;
	if (glm::abs(this->y - vec.y) > gl42::Math::epsilon)
		return false;
	return (true);
}

gl42::Vector2::operator glm::vec2() const
{
	return glm::vec2(x, y);
}

float gl42::Vector2::dotProduct(const Vector2 &vec) const
{
	return glm::dot((glm::vec2)(*this), (glm::vec2)vec);
}

float gl42::Vector2::magnitude() const
{
	return glm::sqrt(this->dotProduct(*this));
}

gl42::Vector2 gl42::Vector2::normalize() const
{
	return (*this) / this->magnitude();
}

float gl42::Vector2::distance(const Vector2 &vec) const
{
	return ((*this) - vec).magnitude();
}
