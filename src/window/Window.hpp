/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:59:51 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/30 18:06:12 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace gl42
{
	/**
	 * @brief Window class to create and manipulate windows.
	 * @details This class is a wrapper for GLFWwindow.
	*/
	class Window
	{
		private:
			/// @brief Pointer to the GLFWwindow.
			GLFWwindow* win_ptr;
			/// @brief Title of the window.
			const std::string &title;
			/// @brief Width of the window as pixel.
			int width;
			/// @brief Height of the window as pixel.
			int height;
			/// @brief Flag to store if is the window current context of OpenGL.
			bool isActive;
		public:
			/**
			 * @name Constructors and Destructors
			 * @{
			 */
			/**
			 * @brief Construct a new Window object.
			 * 
			 * Creates a window with given width, height and title.
			 * @param[in] width Width of the window.
			 * @param[in] height Height of the window.
			 * @param[in] title Title of the window.
			 * @param[in] monitor Specify monitor pointer to fullscreen window. Use nullptr for windowed mode.
			 * @param[in] share The window whose context to share resources with. Use nullptr to not share resources.
			 */
			Window(int width, int height, const std::string &title, GLFWmonitor *monitor, GLFWwindow *share);
			/**
			 * @brief Destroy the Window object
			 * 
			 * Destroys the window and frees the memory.
			 */
			~Window();
			/**
			 * @}
			 */
		public:
			GLFWwindow* getWinPtr() const;
			/**
			 * @name Getters
			 * @{
			 */
			/**
			 * @brief Get the width of the window.
			 * 
			 * @return width of the window.
			 */
			int getWidth() const;
			/**
			 * @brief Get the height of the window.
			 * 
			 * @return height of the window.
			 */
			int getHeight() const;
			/**
			 * @brief Get the is active flag.
			 * 
			 * @return If window is the current OpenGL context returns \b true
			 * @return otherwise \b false
			 */
			bool getIsActive() const;
			/**
			 * @}
			 */
		public:
			/**
			 * @brief Check if the window should close.
			 * 
			 * @return \b true if the window should close, \b false otherwise.
			 */
			bool shouldClose();
			/**
			 * @brief Set the window to close.
			 * 
			 * This function sets the window to close.
			 */
			void setShouldClose();
			/**
			 * @brief Attach the window.
			 * 
			 * This function attach the window and makes it the current OpenGL context.
			 */
			void attach();
			/**
			 * @brief detach the window.
			 * 
			 * This function detach the window and makes it not the current OpenGL context.
			 */
			void detach();
			/**
			 * @brief Swaps buffers and poll callbacks to update window.
			 * 
			 * @details
			 */
			void updateWindow();
		public:
			/**
			 * @brief Set the window hint.
			 * 
			 * @param[in] hint Hint to set.
			 * @param[in] value Value of the hint.
			 */
			static void setWindowHint(int hint, int value);
	};
}
