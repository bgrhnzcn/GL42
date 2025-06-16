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

#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <vector>

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
			/// @brief Source path used to generate vertex shader.
			std::string m_vertexPath;
			/// @brief Source path used to generate fragment shader.
			std::string m_fragmentPath;
			/// @brief Source code of the vertex shader.
			std::vector<GLchar*> m_vertexSourceCode;
			/// @brief Source code of the fragment shader.
			std::vector<GLchar*> m_fragmentSourceCode;
		public:
			/**
			 * @name Constructors and Destructors
			 * @{
			 */
			/**
			 * @brief Construct a new Shader object.
			 * @param[in] vertexPath Path to the vertex shader file.
			 * @param[in] fragmentPath Path to the fragment shader file.
			 *
			 * Reads the source code from the files, compiles the shaders,
			 * attaches them to a program, links and validates the program.
			 */
			Shader(const std::string& vertexPath, const std::string& fragmentPath);
			
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
			 * @brief Compile the fragment shader.
			 * @return unsigned int Shader ID from OpenGL.
			 */
			unsigned int compileFragmentShader();

			/**
			 * @brief Compile the vertex shader.
			 * @return unsigned int Shader ID from OpenGL.
			 */
			unsigned int compileVertexShader();
		public:
			/**
			 * @brief Use the shader program.
			 */
			void use() const;
			unsigned int getShaderId() const;
	};
}

#endif // SHADER_HPP
