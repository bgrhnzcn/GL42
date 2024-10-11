/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix2x2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:12:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/12 01:22:02 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector2.hpp"

namespace gl42
{
	/**
	 * @brief 2x2 Matrix Class
	 * 
	 * @details This class is used to represent 2x2 matrix.
	 * This store matrixes as columns based.
	 * 
	 * For detailed information about [Matrix](https://en.wikipedia.org/wiki/Matrix_(mathematics))
	 */
	class Matrix2x2
	{
		public:
			union
			{
				struct
				{
					/// @brief First column of the matrix
					Vector2 column1;
					/// @brief Second column of the matrix
					Vector2 column2;
				};
				/// @brief Array representation of the matrix
				float data[4];
			};
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
			 * @param[in] column1 first column value of the matrix.
			 * @param[in] column2 Y value of the matrix.
			 */
			Matrix2x2(Vector2 column1, Vector2 column2);
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
			/**
			 * @brief Dot product of two matrix.
			 * 
			 * Dot product is a commutative operation. (Order doesn't affect the result.)
			 * @return Return a scaler result.
			 */
	};
}
