/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:15:54 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 01:50:08 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Math.hpp"

#include "Color.hpp"

gl42::Color::Color()
	: r(0), g(0), b(0), a(0)
{
	//Do Nothing.
}

gl42::Color::Color(float r, float g, float b, float a)
	: r(r), g(g), b(b), a(a)
{
	//Do Nothing
}

gl42::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	this->r = Math::normalize(r, 0, 255);
	this->g = Math::normalize(g, 0, 255);
	this->b = Math::normalize(b, 0, 255);
	this->a = Math::normalize(a, 0, 255);
}

gl42::Color gl42::Color::lerp(float val, Color &min, Color &max)
{
	return Color(Math::lerp(val, min.r, max.r),
				 Math::lerp(val, min.g, max.g),
				 Math::lerp(val, min.b, max.b),
				 Math::lerp(val, min.a, max.a));
}
