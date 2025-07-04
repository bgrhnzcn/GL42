/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:12:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/09 21:00:59 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace gl42
{
	/**
	 * @brief 2D Vector Class
	 * 
	 * @details This class is used to represent 2D vectors.
	 * For detailed information about [Vectors](https://en.wikipedia.org/wiki/Vector_(mathematics_and_physics))
	 */
	class Vector2
	{
		public:
			union
			{
				struct
				{
					/// @brief X value of the vector
					float x;
					/// @brief Y value of the vector
					float y;
				};
				float data[2];
			};
		public:
			/**
			 * @name Constructors and Destructor
			 * @{
			 */
			/**
			 * @brief Construct a new Vector2 object
			 * 
			 * @details Default constructor. Initializes the vector with 0.
			 */
			Vector2();
			/**
			 * @brief Copy constructor.
			 *
			 * @details Initializes the Vector2 with another Vector2.
			 *
			 * @param vec Vector2 to copy.
			 */
			Vector2(const Vector2& other) = default;
			/**
			 * @brief Move constructor.
			 *
			 * @details Initializes the Vector2 with another Vector2.
			 *
			 * @param vec Vector2 to move.
			 */
			Vector2(Vector2&& other) = default;
			/**
			 * @brief Destroy the Vector2 object
			 *
			 * @details Default destructor.
			 */
			~Vector2() = default;
			/**
			 * @brief Construct a new Vector2 object
			 * 
			 * @details Initializes the vector with a single value.
			 * 
			 * @param[in] a Value to initialize the vector.
			 */
			Vector2(float a);
			/**
			 * @brief Construct a new Vector2 object
			 * 
			 * @details Initializes the vector with two values.
			 * 
			 * @param[in] x X value of the vector.
			 * @param[in] y Y value of the vector.
			 */
			Vector2(float x, float y);
			/**
			 * @}
			 */
		public:
			/**
			 * @name Operators
			 * @{
			 */
			/**
			 * @brief Assignment operator.
			 *
			 * @details Assigns the values of another Vector2 to this Vector2.
			 * @param other Vector2 to assign.
			 * @return Reference to this Vector2.
			 */
			Vector2& operator=(const Vector2& other);
			/**
			 * @brief Addition operator.
			 * 
			 * Adds two vectors. Doesn't modify the original vectors.
			 * @return Return a new result Vector2.
			 */
			Vector2 operator+(const Vector2 &vec) const;
			/**
			 * @brief Subtraction operator.
			 * 
			 * Subtracts two vectors. Doesn't modify the original vectors.
			 * @return Return a new result Vector2.
			 */
			Vector2 operator-(const Vector2 &vec) const;
			/**
			 * @brief Mulipilication operator.
			 * 
			 * Multiplies a vector with a scalar. Doesn't modify the original vector.
			 * @return Return a new result Vector2.
			 */
			Vector2 operator*(float scaler) const;
			/**
			 * @brief Division operator.
			 * 
			 * Divides a vector with a scalar. Doesn't modify the original vector.
			 * Returns zero vector for zero division case.
			 * @return Return a new result Vector2.
			 */
			Vector2 operator/(float scaler) const;
			/**
			 * @brief Equal operator.
			 * 
			 * @return \b true if values inside vectors are same, false otherwise.
			 * Same means difference of each value smaller than \b EPSILON.
			 */
			bool operator==(const Vector2& vec) const;
		public:
			/**
			 * @brief Dot product of two vector.
			 * 
			 * Dot product is a commutative operation. (Order doesn't affect the result.)
			 * @return Return a scaler result.
			 */
			float dotProduct(const Vector2& vec) const;
			/**
			 * @brief Magnitude (Length) of this vector.
			 * 
			 * Can't return value smaller than zero.
			 * @return Return a magnitude of this vector.
			 */
			float magnitude() const;
			/**
			 * @brief Normalize this vector.
			 * 
			 * @return Return normalized version of this vector.
			 */
			Vector2 normalize() const;
			/**
			 * @brief Distance of two vector.
			 * 
			 * @param to Target vector to calculate distance.
			 * @return Distance betwen this vector and given vector.
			 */
			float distance(const Vector2 &to) const;
			/**
			 * @}
			 */
	};
}
