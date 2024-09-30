/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:00:34 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 01:15:21 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			constexpr static const float epsilon = 1e-5;
			constexpr static const float pi = M_PI;
			constexpr static const float e = M_E;
		public:
			/**
			 * @brief 
			 * 
			 * @param val Value to normalize. For correct normalization use value between min and max.
			 * @param min 
			 * @param max 
			 * @return float 
			 */
			inline static float normalize(float val, float min, float max);
			inline static float lerp(float val, float min, float max);
			inline static float map(float val, Vector2 in, Vector2 out);
			inline static float map(float val, float inMin, float inMax, float outMin, float outMax);
			inline static float toDegree(float rad);
			inline static float toRadian(float degree);
			inline static float sin(float rad);
			inline static float cos(float rad);
	};
}
