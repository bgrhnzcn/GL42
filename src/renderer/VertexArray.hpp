/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VertexArray.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:00:41 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:38 by buozcan          ###   ########.fr       */
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
