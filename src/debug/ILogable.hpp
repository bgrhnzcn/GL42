/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILogable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:02:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/15 01:40:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace gl42
{
	class ILogable
	{
		public:
			virtual ~ILogable() = 0;
		public:
			virtual void PrintLog() const = 0;
	};
}