#include <iostream>
#include <gmath/vec.hpp>
#include <gmath/mat.hpp>


int main()
{
	gm::Vec2f vec;
	vec[0] = 32;

	std::cout << vec.x;

	return 0;
}