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
#	include <glew.h>
#	include <OpenGL/gl3.h>
#	include <OpenGL/glu.h>
#endif

#ifdef __linux__
#	include <glad.h>
#	include <GL/gl.h>
#	include <GL/glu.h>
#endif

#ifdef _WIN32
#	include <windows.h>
#	include <glad.h>
#	include <gl/GL.h>
#	include <gl/GLU.h>

#endif

