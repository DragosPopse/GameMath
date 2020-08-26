#pragma once

#include <gmath/details/basic_vec.hpp>

namespace gm
{
	template <typename T>
	struct Vec<T, 2>
	{
		static constexpr size_t SIZE = 2;
	private:
		using MemberType = T Vec::*;
		
		static MemberType m_elements[2];

	public:
		T x = T(0);
		T y = T(0);


	public:
		constexpr Vec() = default;


		constexpr Vec(const Vec& other) = default;


		constexpr Vec(T theX, T theY) :
			x(theX),
			y(theY)
		{
		}
		

		constexpr Vec operator*(T scalar) const
		{
			return { x * scalar, y * scalar };
		}


		constexpr Vec operator/(T scalar) const
		{
			return { x / scalar, y / scalar };
		}


		/*
			Calculates the dot product between 2 vectors
		*/
		constexpr T operator*(const Vec& other) const
		{
			return x * other.x + y * other.y;
		}


		constexpr Vec operator+(const Vec& other) const
		{
			return { x + other.x, y + other.y };
		}


		constexpr Vec operator-(const Vec& other) const
		{
			return { x - other.x, y - other.y };
		}
		

		T& operator[](size_t index)
		{
			return this->*m_elements[index];
		}


		T operator[](size_t index) const
		{
			return this->*m_elements[index];
		}


		bool operator==(const Vec& other) const
		{
			return x == other.x && y == other.y;
		}


		bool operator!=(const Vec& other) const
		{
			return !(*this == other);
		}
	};


	template <typename T>
	typename Vec<T, 2>::MemberType Vec<T, 2>::m_elements[2] = {
		&Vec<T, 2>::x,
		&Vec<T, 2>::y
	};


	template <typename T>
	using Vec2 = Vec<T, 2>;

	using Vec2i = Vec2<int32_t>;
	using Vec2u = Vec2<uint32_t>;
	using Vec2f = Vec2<float>;
}