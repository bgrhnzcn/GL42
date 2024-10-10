#pragma once

#include "Color.hpp"

namespace gl42
{
	class Material
	{
		public:
			Color baseColor;
			float roughness;
			float metalic;
	};
}