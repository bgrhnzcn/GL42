#include "Matrix2x2.hpp"

gl42::Matrix2x2::Matrix2x2()
	: column1(Vector2()), column2(Vector2())
{
	//Do Nothing.
}

gl42::Matrix2x2::Matrix2x2(float a)
	: column1(Vector2(a, 0)), column2(Vector2(0, a))
{
	//Do Nothing.
}

gl42::Matrix2x2::Matrix2x2(Vector2 column1, Vector2 column2)
	: column1(column1), column2(column2)
{
	//Do Nothing.
}

gl42::Matrix2x2::~Matrix2x2()
{
	//Do Nothing.
}

gl42::Matrix2x2 gl42::Matrix2x2::operator+(const Matrix2x2 &other)
{
	return Matrix2x2(this->column1 + other.column1, this->column2 + other.column2);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator-(const Matrix2x2 &other)
{
	return Matrix2x2(this->column1 - other.column1, this->column2 - other.column2);
}

gl42::Matrix2x2 gl42::Matrix2x2::operator*(const float &scaler)
{
	return Matrix2x2(this->column1 * scaler, this->column2 * scaler);
}

gl42::Vector2 gl42::Matrix2x2::operator*(const Vector2 &vec)
{
	return Vector2
	(
		(vec.x * this->data[0]) + (vec.y * this->data[2]),
		(vec.x * this->data[1]) + (vec.y * this->data[3])
	);
}
