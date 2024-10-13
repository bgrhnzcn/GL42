/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix2x2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:36:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/13 03:26:14 by bgrhnzcn         ###   ########.fr       */
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

gl42::Matrix2x2::Matrix2x2(const Vector2 &row1, const Vector2 &row2)
{
	data[0] = row1.x;
	data[1] = row1.y;
	data[2] = row2.x;
	data[3] = row2.y;
}

gl42::Matrix2x2::Matrix2x2(const Matrix2x2 &other)
{
	data[0] = other[0];
	data[1] = other[1];
	data[2] = other[2];
	data[3] = other[3];
}

gl42::Matrix2x2::Matrix2x2(const glm::mat2 &mat)
{
	data[0] = mat[0][0];
	data[1] = mat[1][0];
	data[2] = mat[0][1];
	data[3] = mat[1][1];
}

gl42::Matrix2x2::Matrix2x2(float m00, float m01, float m10, float m11)
{
	data[0] = m00;
	data[1] = m01;
	data[2] = m10;
	data[3] = m11;
}

gl42::Matrix2x2::~Matrix2x2()
{
	//Do Nothing.
}

gl42::Matrix2x2::operator glm::mat2() const
{
	return glm::mat2(data[0], data[2], data[1], data[3]);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator=(const Matrix2x2 &other)
{
	return Matrix2x2(other);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator+(const Matrix2x2 &other)
{
	return Matrix2x2(this->data[0] + other.data[0], this->data[1] + other.data[1]
					,this->data[2] + other.data[2], this->data[3] + other.data[3]);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator-(const Matrix2x2 &other)
{
	return Matrix2x2(this->data[0] - other.data[0], this->data[1] - other.data[1]
					,this->data[2] - other.data[2], this->data[3] - other.data[3]);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator*(const float &scaler)
{
	return Matrix2x2(this->data[0] * scaler, this->data[1] * scaler
					,this->data[2] * scaler, this->data[3] * scaler);
}

gl42::Vector2 gl42::Matrix2x2::operator*(const Vector2 &vec)
{
	return Vector2((glm::mat2)(*this) * (glm::vec2)(vec));
}

gl42::Matrix2x2 gl42::Matrix2x2::operator/(const float &scaler)
{
	return Matrix2x2(this->data[0] / scaler, this->data[1] / scaler
					,this->data[2] / scaler, this->data[3] / scaler);
}

bool gl42::Matrix2x2::operator==(const Matrix2x2 &vec) const
{
	for (int i = 0; i < 4; i++)
		if (data[i] != vec[i])
			return false;
	return true;
}

float gl42::Matrix2x2::operator[](unsigned int index) const
{
	if (index > 3)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return data[index];
}

float &gl42::Matrix2x2::operator[](unsigned int index)
{
	if (index > 3)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return data[index];
}

gl42::Vector2 gl42::Matrix2x2::GetRow(unsigned char index)
{
	if (index > 1)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return Vector2(data[index * 2], data[(index * 2) + 1]);
}

gl42::Vector2 gl42::Matrix2x2::GetColumn(unsigned char index)
{
	if (index > 1)
		std::cerr << "gl42::Matrix2x2::IndexOutOfRange." << std::endl;
	return Vector2(data[index], data[index + 2]);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator*(const Matrix2x2 &mat)
{
	return Matrix2x2((glm::mat2)(*this) * (glm::mat2)(mat));
}
