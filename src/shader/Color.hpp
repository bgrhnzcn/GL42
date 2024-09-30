/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:23:46 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 01:49:59 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace gl42
{
	class Color
	{
		private:
			float r;
			float g;
			float b;
			float a;
		public:
			Color();
			Color(float r, float g, float b, float a);
			Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
			~Color() = default;
		public:
			Color lerp(float val, Color &min, Color &max);
	};
}