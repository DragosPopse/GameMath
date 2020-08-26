#include <iostream>
#include <gmath/vec.hpp>
#include <gmath/mat.hpp>
#include <gmath/transform.hpp>


template <typename MatType>
void PrintMat(const MatType& m)
{
	for (int i = 0; i < MatType::ROWS; i++)
	{
		for (int j = 0; j < MatType::COLUMNS; j++)
		{
			std::cout << m[i][j] << ' ';
		}
		std::cout << '\n';
	}
}


int main()
{
	gm::Vec2f vec;
	gm::Vec3f v;
	vec[0] = 32;

	v - v;

	normalize(v);
	gm::Mat4f m;
	std::cout << m.data();
	m[0][0] = 2;
	if (v == v)
	{

	}
	PrintMat(gm::translate(gm::Mat4f(1.f), { 2.f, 3.f, 4.f }));

	return 0;
}