/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl42.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:46:26 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/13 15:55:45 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define USER_BUOZCAN 1
#define USER_BGRHNZCN 2

#if USER == USER_BUOZCAN
#	define WIDTH 1800
#	define HEIGHT 1600
#else
#	define WIDTH 800
#	define HEIGHT 600
#endif

//#include "OpenGLDecl.hpp"
#include "Window.hpp"
#include "Shader.hpp"
#include "Error.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Vertex.hpp"
#include "Matrix2x2.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "Math.hpp"
#include "Debug.hpp"
#include "AssetLoader.hpp"
