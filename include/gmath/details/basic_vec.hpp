#pragma once

#include <gmath/details/config.hpp>


namespace gm
{
	template <typename T, size_t N>
	struct Vec
	{

	};


	namespace meta
	{
		template <typename T>
		struct is_vec : std::false_type
		{
		};


		template <typename T, size_t N>
		struct is_vec<Vec<T, N>> : std::true_type
		{
		};
	}


	template <typename T, size_t N>
	Vec<T, N> operator*(T scalar, const Vec<T, N>& v)
	{
		return v * scalar;
	}


	template <typename T, size_t N>
	T magnitude(const Vec<T, N>& v)
	{
		return sqrt(v * v);
	}


	template <typename T, size_t N>
	T sqr_magnitude(const Vec<T, N>& v)
	{
		return v * v;
	}


	template <typename T, size_t N>
	Vec<T, N> normalize(const Vec<T, N>& v)
	{
		return v / magnitude(v);
	}
}