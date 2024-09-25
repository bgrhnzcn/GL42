/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitializationExecption.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:44:26 by buozcan           #+#    #+#             */
/*   Updated: 2024/09/25 01:38:31 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

namespace gl42
{
	class InitializationExecption : public std::exception
	{
		public:
			virtual const char *what() const noexcept override;
	};
}
