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
	T dot(const Vec<T, N>& a, const Vec<T, N>& b)
	{
		T result;
		for (int i = 0; i < N; i++)
		{
			result += a[i] * b[i];
		}
		return result;
	}


	template <typename T>
	T dot(const Vec<T, 2>& a, const Vec<T, 2>& b)
	{
		return a.x * b.x + a.y * b.y;
	}


	template <typename T>
	T dot(const Vec<T, 3>& a, const Vec<T, 3>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}


	template <typename T>
	T dot(const Vec<T, 4>& a, const Vec<T, 4>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}


	


	template <typename T, size_t N>
	Vec<T, N> operator*(T scalar, const Vec<T, N>& v)
	{
		return v * scalar;
	}


	template <typename T, size_t N>
	T magnitude(const Vec<T, N>& v)
	{
		return sqrt(dot(v, v));
	}


	template <typename T, size_t N>
	T sqr_magnitude(const Vec<T, N>& v)
	{
		return dot(v, v);
	}


	template <typename T, size_t N>
	Vec<T, N> normalize(const Vec<T, N>& v)
	{
		return v / magnitude(v);
	}
}