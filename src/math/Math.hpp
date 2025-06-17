/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:00:34 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 17:25:37 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include "Vector2.hpp"

namespace gl42
{
	/**
	 * @brief Math class for basic math functions.
	 * 
	 */
	class Math
	{
		public:
			/// @brief Very small number to assume equality.
			constexpr static const float epsilon = 1e-4f;
			constexpr static const float pi = 3.14159265359f;
			constexpr static const float e = 2.71828182846f;
		public:
			
			/**
			 * @brief Normalizes a value within a given range.
			 *
			 * @param val The value to normalize.
			 * @param min The minimum of the range.
			 * @param max The maximum of the range.
			 * @return Normalized value in the range [0, 1].
			 */
			static inline float normalize(float val, float min, float max)
			{
				if (min == max)
				{
					if (val < min)
						return 0.0f;
					else
						return 1.0f;
				}
				if (min > max)
				{
					float temp = max;
					max = min;
					min = temp;
				}
				return (val - min) / (max - min);
			}

			/**
			 * @brief Linearly interpolates between min and max by val.
			 *
			 * @param val Interpolation factor, typically in [0, 1].
			 * @param min Start value.
			 * @param max End value.
			 * @return Interpolated value.
			 */
			static inline float lerp(float val, float min, float max)
			{
				return (val * (max - min)) + min;
			}

			/**
			 * @brief Maps a value from one range to another using Vector2.
			 *
			 * @param val The value to map.
			 * @param in Input range as Vector2 (x: min, y: max).
			 * @param out Output range as Vector2 (x: min, y: max).
			 * @return Mapped value in the output range.
			 */
			static inline float map(float val, Vector2 in, Vector2 out)
			{
				return lerp(normalize(val, in.x, in.y), out.x, out.y);
			}

			/**
			 * @brief Maps a value from one range to another.
			 *
			 * @param val The value to map.
			 * @param inMin Input range minimum.
			 * @param inMax Input range maximum.
			 * @param outMin Output range minimum.
			 * @param outMax Output range maximum.
			 * @return Mapped value in the output range.
			 */
			static inline float map(float val, float inMin, float inMax, float outMin, float outMax)
			{
				return lerp(normalize(val, inMin, inMax), outMin, outMax);
			}

			/**
			 * @brief Converts radians to degrees.
			 *
			 * @param rad Angle in radians.
			 * @return Angle in degrees.
			 */
			static inline float toDegree(float rad)
			{
				return rad * (180 / pi);
			}

			/**
			 * @brief Converts degrees to radians.
			 *
			 * @param degree Angle in degrees.
			 * @return Angle in radians.
			 */
			static inline float toRadian(float degree)
			{
				return (degree / 180) * pi;
			}

			/**
			 * @brief Calculates the sine of an angle in radians.
			 *
			 * @param rad Angle in radians.
			 * @return Sine of the angle.
			 */
			static inline float sin(float rad)
			{
				// For now. I will write SIMD Instructed version.
				return ::sin(rad);
			}

			/**
			 * @brief Calculates the cosine of an angle in radians.
			 *
			 * @param rad Angle in radians.
			 * @return Cosine of the angle.
			 */
			static inline float cos(float rad)
			{
				// For now. I will write SIMD Instructed version.
				return ::cos(rad);
			}

			/**
			 * @brief Returns the absolute value of a float.
			 *
			 * @param val Input value.
			 * @return Absolute value.
			 */
			static inline float abs(float val)
			{
				return ::fabs(val);
			}

			/**
			 * @brief Calculates the square root of a value.
			 *
			 * @param val Input value.
			 * @return Square root of the value.
			 */
			static inline float sqrt(float val)
			{
				return ::sqrt(val);
			}
	};
}
