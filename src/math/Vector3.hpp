/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:12:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/09 20:00:21 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace gl42
{
	/**
	 * @brief 3D Vector Class
	 * 
	 * @details This class is used to represent 3D vectors.
	 * For detailed information about [Vectors](https://en.wikipedia.org/wiki/Vector_(mathematics_and_physics))
	 */
	class Vector3
	{
		public:
			union
			{
				struct
				{
					/// @brief X value of the vector.
					float x;
					/// @brief Y value of the vector.
					float y;
					/// @brief Z value of the vector.
					float z;
				};
				float data[3];
			};
			/**
			 * @name Constructors and Destructor
			 * @{
			 */
		public:
			/**
			 * @brief Default constructor.
			 * 
			 * @details Construct a new Vector3 object. Initializes the vector with 0.
			 */
			Vector3();
			/**
			 * @brief Copy constructor.
			 *
			 * @details Initializes the Vector3 with another Vector3.
			 *
			 * @param vec Vector3 to copy.
			 */
			Vector3(const Vector3& vec) = default;
			/**
			 * @brief Move constructor.
			 *
			 * @details Initializes the Vector3 with another Vector3.
			 *
			 * @param vec Vector3 to move.
			 */
			Vector3(Vector3&& vec) = default;
			/**
			 * @brief Default destructor.
			 *
			 * @details Destroy the Vector3 object.
			 */
			~Vector3() = default;
			/**
			 * @brief Construct a new Vector3 object.
			 * 
			 * @details Initializes the vector with a single value.
			 * 
			 * @param[in] a Value to initialize the vector.
			 */
			Vector3(float a);
			/**
			 * @brief Construct a new Vector3 object.
			 * 
			 * @details Initializes the vector with two values.
			 * 
			 * @param[in] x X value of the vector.
			 * @param[in] y Y value of the vector.
			 * @param[in] z Z value of the vector.
			 */
			Vector3(float x, float y, float z);
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
			 * @details Assigns the values of another Vector3 to this Vector3.
			 * @param other Vector3 to assign.
			 * @return Reference to this Vector3.
			 */
			Vector3& operator=(const Vector3& other);
			/**
			 * @brief Addition operator.
			 * 
			 * Adds two vectors. Doesn't modify the original vectors.
			 * @return Return a new result Vector3.
			 */
			Vector3 operator+(const Vector3 &vec);
			/**
			 * @brief Subtraction operator.
			 * 
			 * Subtracts two vectors. Doesn't modify the original vectors.
			 * @return Return a new result Vector3.
			 */
			Vector3 operator-(const Vector3 &vec);
			/**
			 * @brief Mulipilication operator.
			 * 
			 * Multiplies a vector with a scalar. Doesn't modify the original vector.
			 * @return Return a new result Vector3.
			 */
			Vector3 operator*(float scaler);
			/**
			 * @brief Division operator.
			 * 
			 * Divides a vector with a scalar. Doesn't modify the original vector.
			 * Returns zero vector for zero division case.
			 * @return Return a new result Vector3.
			 */
			Vector3 operator/(float scaler);
			/**
			 * @brief Equal operator.
			 * 
			 * @return \b true if values inside vectors are same, false otherwise.
			 * Same means difference of each value smaller than \b EPSILON.
			 */
			bool operator==(const Vector3 &vec) const;
			/**
			 * @brief Dot product of two vector.
			 * 
			 * Dot product is a commutative operation. (Order doesn't affect the result.)
			 * @return Return a scaler result.
			 */
			float dotProdcut(const Vector3 &vec);
			/**
			 * @brief Cross product of two vector.
			 *
			 * Cross product is not a commutative operation. (Order affects the result.)
			 * @return Return a new Vector3 result.
			 */
			Vector3 crossProduct(const Vector3 &vec);
			/**
			 * @brief Magnitude (Size or length) of this vector.
			 * 
			 * Can't return value smaller than zero.
			 * @return Return a magnitude of this vector.
			 */
			float magnitude();
			/**
			 * @brief Normalize this vector.
			 * 
			 * @return Return normalized version of this vector.
			 */
			Vector3 normalize();
			/**
			 * @brief Distance of two vector.
			 * 
			 * @param vec Target vector to calculate distance.
			 * @return Distance betwen this vector and given vector.
			 */
			float distance(const Vector3 &vec);
			/**
			 * @}
			 */
	};
}
