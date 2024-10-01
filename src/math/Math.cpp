#include "Math.hpp"

float gl42::Math::normalize(float val, float min, float max)
{
	if (min == max)
	{
		if (val < min)
			return 0.0f;
		else
			return 1.0f;
	}
	if (min > max)
	{
		float temp = max;
		max = min;
		min = temp;
	}
	return (val - min) / (max - min);
}

float gl42::Math::lerp(float val, float min, float max)
{
	return (val * (max - min)) + min;
}

float gl42::Math::map(float val, Vector2 in, Vector2 out)
{
	return lerp(normalize(val, in.x, in.y), out.x, out.y);
}

float gl42::Math::map(float val, float inMin, float inMax, float outMin, float outMax)
{
	return lerp(normalize(val, inMin, inMax), outMin, outMax);
}

float gl42::Math::toDegree(float rad)
{
	return rad * (180 / pi);
}

float gl42::Math::toRadian(float degree)
{
	return (degree / 180) * pi;
}

float gl42::Math::sin(float rad)
{
	return ::sin(rad);
}

float gl42::Math::cos(float rad)
{
	return ::cos(rad);
}
