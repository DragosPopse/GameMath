#pragma once


#include <gmath/details/basic_vec.hpp>


namespace gm
{
	template <typename T>
	struct Vec<T, 4>
	{
		static constexpr size_t SIZE = 4;

	private:
		using MemberType = T Vec::*;

		static MemberType m_elements[4];

	public:
		T x = T(0);
		T y = T(0);
		T z = T(0);
		T w = T(0);

		constexpr Vec() = default;


		constexpr Vec(const Vec& other) = default;

		
		constexpr Vec(T theX, T theY, T theZ, T theW) :
			x(theX),
			y(theY),
			z(theZ),
			w(theW)
		{
		}


		constexpr Vec operator*(T scalar)
		{
			return { x * scalar, y * scalar, z * scalar, w * scalar };
		}


		constexpr Vec operator/(T scalar)
		{
			return { x / scalar, y / scalar, z / scalar, w / scalar };
		}


		constexpr Vec operator+(const Vec& other)
		{
			return { x + other.x, y + other.y, z + other.z, w + other.w };
		}


		T& operator[](size_t index)
		{
			return this->*m_elements[index];
		}


		T operator[](size_t index) const
		{
			return this->*m_elements[index];
		}
	};


	template <typename T>
	typename Vec<T, 4>::MemberType Vec<T, 4>::m_elements[4] = {
		&Vec<T, 4>::x,
		&Vec<T, 4>::y,
		&Vec<T, 4>::z,
		&Vec<T, 4>::w
	};


	template <typename T>
	using Vec4 = Vec<T, 4>;

	using Vec4i = Vec4<int32_t>;
	using Vec4u = Vec4<uint32_t>;
	using Vec4f = Vec4<float>;
}