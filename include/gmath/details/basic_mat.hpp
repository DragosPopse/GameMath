#pragma once

#include <gmath/details/config.hpp>


namespace gm
{
	template <typename T, size_t R, size_t C>
	struct Mat
	{

	};


	namespace meta
	{
		template <typename T>
		struct is_mat : std::false_type
		{
		};


		template <typename T, size_t R, size_t C>
		struct is_mat<Mat<T, R, C>> : std::true_type
		{
		};
	}
}