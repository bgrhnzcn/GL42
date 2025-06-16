/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:09:09 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/01 01:39:38 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

namespace gl42
{
	/**
	 * @brief Shader class to generate shader programs and manipulate them.
	 * @details In this class \ref shaderId used as program ID in OpenGL.
	 * \ref compileShader returns real shader ID from OpenGL but this ID
	 * is represent vertex or fragment shader. So we need to attach,
	 * link and validate them to create a program. This is done in the constructor.
	*/
	class Shader
	{
		private:
			/// @brief Shader ID from OpenGL.
			unsigned int m_shaderId;
			/// @brief Source path used to generate shader.
			std::string m_sourcePath;
			/// @brief Source code of the shader.
			std::string m_sourceCode;
		public:
			/**
			 * @name Constructors and Destructors
			 * @{
			 */
			/**
			 * @brief Construct a new Shader object.
			 * 
			 * Accepts a shader path to single file shader.
			 * You must provide a path to a file that contains both vertex and fragment shader.
			 * @param[in] sourcePath Path to the shader file.
			 */
			Shader(const std::string& sourcePath);
			
			/**
			 * @brief Destroy the Shader object.
			 * 
			 * Deletes shader Program from OpenGL context.
			 */
			~Shader();
			/**
			 * @}
			 */
		private:
			/**
			 * @brief Read the source code from the file.
			 * @param[in] sourcePath Path to the shader file.
			 */
			void readSource();
			/**
			 * @brief 
			 * 
			 * @param[in] type \b GL_VERTEX_SHADER or \b GL_FRAGMENT_SHADER.
			 * @return Returns the ID of the compiled shader.
			 * 
			 * This ID not the same as class field shaderId.
			 * See detailed description of the class for better information.
			 */
			unsigned int compileShader(unsigned int type);
			//void combineShader();
		public:
			/**
			 * @brief Use the shader program.
			 */
			void use() const;
			unsigned int getShaderId() const;
	};
}

#endif // SHADER_HPP
