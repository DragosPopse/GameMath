#include <iostream>
#include <gmath/vec.hpp>


int main()
{
	gm::Vec2f vec;
	vec[0] = 32;

	std::cout << vec.x;

	return 0;
}