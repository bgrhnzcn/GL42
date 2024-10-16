/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix2x2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:12:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/13 15:06:10 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector2.hpp"
#include "mat2x2.hpp"

namespace gl42
{
	class Matrix2x2;
}

/**
 * @brief 2x2 Matrix Class
 * 
 * @details This class is used to represent 2x2 matrix.
 * This store matrixes as row based.
 * 
 * For detailed information about [Matrix](https://en.wikipedia.org/wiki/Matrix_(mathematics))
 */
class gl42::Matrix2x2
{
	private:
		/// @brief Array representation of matrix.
		float data[4];
	public:
		/**
		 * @name Constructors and Destructor
		 * @{
		 */
		/**
		 * @brief Construct a new Matrix2x2 object
		 * 
		 * @details Initializes the Matrix with two row.
		 * 
		 * @param[in] row1 first column value of the matrix.
		 * @param[in] row2 Y value of the matrix.
		 */
		Matrix2x2(const glm::mat2 &mat);
		/**
		 * @brief Construct a new Matrix2x2 object
		 * 
		 * @details Default constructor. Initializes the matrix with 0.
		 */
		Matrix2x2();
		/**
		 * @brief Construct a new Matrix2x2 object
		 * 
		 * @details Initializes the matrix with a diagonal value.
		 * 
		 * @param[in] a Value to initialize the matrix.
		 */
		Matrix2x2(float a);
		/**
		 * @brief Construct a new Matrix2x2 object
		 * 
		 * @details Initializes the Matrix with two row.
		 * 
		 * @param[in] row1 first column value of the matrix.
		 * @param[in] row2 Y value of the matrix.
		 */
		Matrix2x2(const Vector2 &row1, const Vector2 &row2);
		/**
		 * @brief Construct a new Matrix2x2 object
		 * 
		 * @details Copy Constructer.
		 * 
		 * @param[in] other Source matrix for copy.
		 */
		Matrix2x2(const Matrix2x2 &other);
		/**
		 * @brief Construct a new Matrix2x2 object
		 * 
		 * @details Initializes the Matrix with values.
		 * First index row, second index column.
		 * 
		 * @param[in] m00 First row, first column.
		 * @param[in] m01 First row, second column.
		 * @param[in] m10 Second row, first column.
		 * @param[in] m11 Second row, second column.
		 */
		Matrix2x2(float m00, float m01, float m10, float m11);
		/**
		 * @brief Destroy the Matrix2x2 object
		 * 
		 * @details Default destructor.
		 */
		~Matrix2x2();
		/**
		 * @}
		 */
	public:
		/**
		 * @name Operators
		 * @{
		 */
		operator glm::mat2() const;
		void operator=(const Matrix2x2 &other);
		/**
		 * @brief Addition operator.
		 * 
		 * Adds two matrix. Doesn't modify the original matrix.
		 * @return Return a new result Matrix2x2.
		 */
		Matrix2x2 operator+(const Matrix2x2 &other);
		/**
		 * @brief Subtraction operator.
		 * 
		 * Subtracts two matrix. Doesn't modify the original matrix.
		 * @return Return a new result Matrix2x2.
		 */
		Matrix2x2 operator-(const Matrix2x2 &other);
		/**
		 * @brief Mulipilication operator for matrix and scaler.
		 * 
		 * Multiplies a matrix with a scalar. Doesn't modify the original matrix.
		 * @return Return a new result Matrix2x2.
		 */
		Matrix2x2 operator*(const float &scaler);
		/**
		 * @brief Mulipilication operator for matrix to vector.
		 * 
		 * Multiplies a matrix with a vector. Doesn't modify the original vector.
		 * @return Return a new result Matrix2x2.
		 */
		Vector2 operator*(const Vector2 &vec);
		/**
		 * @brief Mulipilication operator for matrix to matrix.
		 * 
		 * Multiplies a matrix with a vector. Doesn't modify the original vector.
		 * @return Return a new result Matrix2x2.
		 */
		Matrix2x2 operator*(const Matrix2x2 &mat);
		/**
		 * @brief Division operator.
		 * 
		 * Divides a matrix with a scalar. Doesn't modify the original matrix.
		 * Returns zero matrix for zero division case.
		 * @return Return a new result Matrix2x2.
		 */
		Matrix2x2 operator/(const float &scaler);
		/**
		 * @brief Equal operator.
		 * 
		 * @return \b true if values inside matrix are same, false otherwise.
		 * Same means difference of each value smaller than \b EPSILON.
		 */
		bool operator==(const Matrix2x2 &vec) const;
		float operator[](unsigned int index) const;
		float &operator[](unsigned int index);
	public:
		Vector2 GetRow(unsigned char index);
		Vector2 GetColumn(unsigned char index);
		friend Vector2::Vector2(const glm::vec2 &vec);
};
