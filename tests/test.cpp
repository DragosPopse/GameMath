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
	vec[0] = 32;

	PrintMat(gm::translate(gm::Mat4f(1.f), { 2.f, 3.f, 4.f }));

	return 0;
}