/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:25 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/30 18:13:26 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Window.hpp"
#include "InitializationExecption.hpp"

gl42::Window::Window(int width, int height, const std::string &title, GLFWmonitor *monitor, GLFWwindow *share)
	: title(title), width(width), height(height)
{
	setWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	setWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	setWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	this->win_ptr = glfwCreateWindow(this->width, this->height, this->title.c_str(), monitor, share);
	if (this->win_ptr == nullptr)
	{
		const char *error;
		glfwGetError(&error);
		std::cout << "[GL42 Error]: Window: Window Initialization Failed: " << error << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(this->win_ptr);
	this->isActive = true;
}

gl42::Window::~Window()
{
	glfwDestroyWindow(this->win_ptr);
}

GLFWwindow* gl42::Window::getWinPtr() const
{
	return (this->win_ptr);
}

int gl42::Window::getWidth() const
{
	return (this->width);
}

int gl42::Window::getHeight() const
{
	return (this->height);
}

bool gl42::Window::getIsActive() const
{
	return (this->isActive);
}

bool gl42::Window::shouldClose()
{
	return (glfwWindowShouldClose(this->win_ptr));
}

void gl42::Window::setShouldClose()
{
	glfwSetWindowShouldClose(this->win_ptr, true);
}

void gl42::Window::attach()
{
	glfwMakeContextCurrent(this->win_ptr);
	this->isActive = true;
}

void gl42::Window::detach()
{
	glfwMakeContextCurrent(nullptr);
	this->isActive = false;
}

void gl42::Window::updateWindow()
{
	glfwSwapBuffers(this->win_ptr);
	glfwPollEvents();
}

void gl42::Window::setWindowHint(int hint, int value)
{
	glfwWindowHint(hint, value);
}