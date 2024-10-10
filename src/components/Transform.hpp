#pragma once

#include "Vector3.hpp"
#include "Component.hpp"

namespace gl42
{
	class Transform : Component
	{
		public:
			Vector3 position;
			Vector3 rotation;
			Vector3 scale;
		public:
			void Update() override;
	};
}
