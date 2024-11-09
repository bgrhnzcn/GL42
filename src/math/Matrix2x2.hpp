/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix2x2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:12:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:03:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector2.hpp"

/**
 * @brief 2x2 Matrix Class
 * 
 * @details This class is used to represent 2x2 matrix.
 * This store matrixes as colums based.
 * 
 * For detailed information about [Matrix](https://en.wikipedia.org/wiki/Matrix_(mathematics))
 */
namespace gl42
{
	class Matrix2x2
	{
		private:
			float data[4];
		public:
			/**
			 * @name Constructors and Destructor
			 * @{
			 */
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
			 * @details Initializes the Matrix with two column.
			 * 
			 * @param[in] col1 First column value of the matrix.
			 * @param[in] col1 Second column value of the matrix.
			 */
			Matrix2x2(const Vector2 &col1, const Vector2 &col2);
			/**
			 * @brief Construct a new Matrix2x2 object
			 * 
			 * @details Copy Constructer.
			 * 
			 * @param[in] other Source matrix for copy.
			 */
			Matrix2x2(const Matrix2x2 &other);
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
			const Vector2 &operator[](unsigned int index) const;
			Vector2 &operator[](unsigned int index);
		public:
			Vector2 GetRow(unsigned char index);
			Vector2 GetColumn(unsigned char index);
	};
}
