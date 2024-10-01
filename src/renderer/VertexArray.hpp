/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexArray.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:00:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/10/02 00:53:27 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace gl42
{
	class VertexArray
	{
		private:
			unsigned int vbId;
		public:
			VertexArray();
			~VertexArray();
		public:
			void bind();
			void unbind();
	};
}
