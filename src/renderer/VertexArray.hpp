/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexArray.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:00:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/10 02:27:04 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace gl42
{
	class VertexArray
	{
		private:
			unsigned int vertexArrayID;
		public:
			VertexArray();
			~VertexArray();
		public:
			void bind();
			void unbind();
	};
}
