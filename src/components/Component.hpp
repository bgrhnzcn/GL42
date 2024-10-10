#pragma once

namespace gl42
{
	class Component
	{
		public:
			unsigned int id;
		public:
			virtual void Update() = 0;
	};
}