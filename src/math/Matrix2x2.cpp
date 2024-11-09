/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix2x2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:36:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:03:00 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Matrix2x2.hpp"

gl42::Matrix2x2::Matrix2x2()
{
	data[0] = 0.0f;
	data[1] = 0.0f;
	data[2] = 0.0f;
	data[3] = 0.0f;
}

gl42::Matrix2x2::Matrix2x2(float a)
{
	data[0] = a;
	data[1] = 0.0f;
	data[2] = 0.0f;
	data[3] = a;
}

gl42::Matrix2x2::Matrix2x2(const Vector2 &col1, const Vector2 &col2)
{
	data[0] = col1.x;
	data[1] = col1.y;
	data[2] = col2.x;
	data[3] = col2.y;
}

gl42::Matrix2x2::Matrix2x2(const Matrix2x2 &other)
{
	data[0] = other.data[0];
	data[1] = other.data[1];
	data[2] = other.data[2];
	data[3] = other.data[3];
}

gl42::Matrix2x2::~Matrix2x2()
{
	//Do Nothing.
}

void gl42::Matrix2x2::operator=(const Matrix2x2 &other)
{
	data[0] = other.data[0];
	data[1] = other.data[1];
	data[2] = other.data[2];
	data[3] = other.data[3];
}

gl42::Matrix2x2 gl42::Matrix2x2::operator+(const Matrix2x2 &other)
{
	return Matrix2x2(
		Vector2(this->data[0] + other.data[0], this->data[1] + other.data[1]),
		Vector2(this->data[2] + other.data[2], this->data[3] + other.data[3])
		);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator-(const Matrix2x2 &other)
{
	return Matrix2x2(
		Vector2(this->data[0] - other.data[0], this->data[1] - other.data[1]),
		Vector2(this->data[2] - other.data[2], this->data[3] - other.data[3])
		);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator*(const float &scaler)
{
	return Matrix2x2(
		Vector2(this->data[0] * scaler, this->data[1] * scaler),
		Vector2(this->data[2] * scaler, this->data[3] * scaler)
		);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator/(const float &scaler)
{
	return Matrix2x2(
		Vector2(this->data[0] / scaler, this->data[1] / scaler),
		Vector2(this->data[2] / scaler, this->data[3] / scaler)
		);
}

gl42::Vector2 gl42::Matrix2x2::operator*(const Vector2 &vec)
{
	(void)vec;
	return Vector2();
}

gl42::Matrix2x2 gl42::Matrix2x2::operator*(const Matrix2x2 &mat)
{
	(void)mat;
	return Matrix2x2();
}

bool gl42::Matrix2x2::operator==(const Matrix2x2 &vec) const
{
	for (int i = 0; i < 4; i++)
		if (data[i] != vec.data[i])
			return false;
	return true;
}

const gl42::Vector2 &gl42::Matrix2x2::operator[](unsigned int index) const
{
	if (index > 1)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return *(reinterpret_cast<const gl42::Vector2 *>(&this->data[index * 2]));
}

gl42::Vector2 &gl42::Matrix2x2::operator[](unsigned int index)
{
	if (index > 3)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return *(reinterpret_cast<gl42::Vector2 *>(&this->data[index * 2]));
}

gl42::Vector2 gl42::Matrix2x2::GetColumn(unsigned char index)
{
	if (index > 1)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return Vector2(data[index], data[index + 2]);
}

gl42::Vector2 gl42::Matrix2x2::GetRow(unsigned char index)
{
	if (index > 1)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return Vector2(data[index * 2], data[(index * 2) + 1]);
}
