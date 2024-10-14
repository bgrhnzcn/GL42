/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:04:38 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/15 01:46:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ILogable.hpp"
#include <string>

namespace gl42
{
	class Debug
	{
		public:
			enum Level
			{
				INFO,
				WARNING,
				ERROR,
			};
		public:
			static void Log(const gl42::ILogable &obj, gl42::Debug::Level level);
			static void Log(const std::string &message, gl42::Debug::Level level);
			static void Log(const int &val, gl42::Debug::Level level);
			static void Log(const float &val, gl42::Debug::Level level);
			static void DrawLine();
	};
}