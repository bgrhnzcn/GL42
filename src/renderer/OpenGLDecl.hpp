/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGLDecl.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:53:13 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/15 00:40:47 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GL_SILENCE_DEPRECATION
#define GL_GLEXT_PROTOTYPES

#ifdef __APPLE__
#	include <OpenGL/gl3.h>
#	include <OpenGL/glu.h>
#	include <GLFW/glfw3.h>
#endif

#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#endif