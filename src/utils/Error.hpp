/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:46:21 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:05:19 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <GL/gl.h>
#include <iostream>

namespace gl42
{
	void ClearErr();
	bool CheckErr(const char *function, const char *file, int line);
}

#define assert(x) if (!(x)) {exit(1);}
#define GLCall(x) gl42::ClearErr();\
	x;\
	assert(gl42::CheckErr(#x, __FILE__, __LINE__));
