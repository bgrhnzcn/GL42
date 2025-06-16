#include <iostream>

#include "Debug.hpp"

void gl42::Debug::Log(const ILogable &obj, Debug::Level level)
{
	if (level == Error)
		std::cout << "\e[1;91m[ERROR]: ";
	else if (level == Warning)
		std::cout << "\e[1;93m[WARNING]: ";
	else
		std::cout << "[INFO]: ";
	obj.PrintLog();
	std::cout << "\e[0m" << std::endl;
}

void gl42::Debug::Log(const std::string &message, gl42::Debug::Level level)
{
	if (level == Error)
		std::cout << "\e[1;91m[ERROR]: ";
	else if (level == Warning)
		std::cout << "\e[1;93m[WARNING]: ";
	else
		std::cout << "[INFO]: ";
	std::cout << message;
	std::cout << "\e[0m" << std::endl;
}

void gl42::Debug::Log(const int &val, gl42::Debug::Level level)
{
	if (level == Error)
		std::cout << "\e[1;91m[ERROR]: ";
	else if (level == Warning)
		std::cout << "\e[1;93m[WARNING]: ";
	else
		std::cout << "[INFO]: ";
	std::cout << val;
	std::cout << "\e[0m" << std::endl;
}

void gl42::Debug::Log(const float &val, gl42::Debug::Level level)
{
	if (level == Error)
		std::cout << "\e[1;91m[ERROR]: ";
	else if (level == Warning)
		std::cout << "\e[1;93m[WARNING]: ";
	else
		std::cout << "[INFO]: ";
	std::cout << val;
	std::cout << "\e[0m" << std::endl;
}