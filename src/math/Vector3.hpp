/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:12:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/30 23:22:56 by bgrhnzcn         ###   ########.fr       */
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
					/// @brief X value of the vector
					float x;
					/// @brief Y value of the vector
					float y;
					/// @brief Z value of the vector
					float z;
				};
				/// @brief Array representation of the vector
				float data[3];
			};
		public:
			/**
			 * @name Constructors and Destructor
			 * @{
			 */
			/**
			 * @brief Construct a new Vector3 object
			 * 
			 * @details Default constructor. Initializes the vector with 0.
			 */
			Vector3();
			/**
			 * @brief Construct a new Vector3 object
			 * 
			 * @details Initializes the vector with a single value.
			 * 
			 * @param[in] a Value to initialize the vector.
			 */
			Vector3(float a);
			/**
			 * @brief Construct a new Vector3 object
			 * 
			 * @details Initializes the vector with two values.
			 * 
			 * @param[in] x X value of the vector.
			 * @param[in] y Y value of the vector.
			 * @param[in] z Z value of the vector.
			 */
			Vector3(float x, float y, float z);
			/**
			 * @brief Destroy the Vector3 object
			 * 
			 * @details Default destructor.
			 */
			~Vector3();
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
			Vector3 operator*(const float &scaler);
			/**
			 * @brief Division operator.
			 * 
			 * Divides a vector with a scalar. Doesn't modify the original vector.
			 * Returns zero vector for zero division case.
			 * @return Return a new result Vector3.
			 */
			Vector3 operator/(const float &scaler);
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
			 * @brief 
			 * 
			 * @param vec 
			 * @return Vector3 
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
