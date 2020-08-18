#pragma once

#include <gmath/details/basic_vec.hpp>

namespace gm
{
	template <typename T>
	struct Vec<T, 2>
	{
	private:
		using ElementType = T Vec::*;
		static constexpr size_t SIZE = 2;

		static ElementType  m_elements[2];

	public:
		T x;
		T y;


	public:
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
	typename Vec<T, 2>::ElementType Vec<T, 2>::m_elements[2] = {
		&Vec<T, 2>::x,
		&Vec<T, 2>::y
	};


	template <typename T>
	using Vec2 = Vec<T, 2>;

	using Vec2i = Vec2<int32_t>;
	using Vec2u = Vec2<uint32_t>;
	using Vec2f = Vec2<float>;
}