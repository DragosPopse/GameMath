#pragma once


#include <gmath/details/basic_vec.hpp>


namespace gm
{
	template <typename T>
	struct Vec<T, 3>
	{
		static constexpr size_t SIZE = 3;

	private:
		using MemberType = T Vec::*;

		static MemberType m_elements[3];

	public:
		T x = T(0);
		T y = T(0);
		T z = T(0);

		constexpr Vec() = default;


		constexpr Vec(const Vec& other) = default;


		constexpr Vec(T theX, T theY, T theZ) :
			x(theX),
			y(theY),
			z(theZ)
		{
		}


		constexpr Vec operator*(T scalar) const
		{
			return { x * scalar, y * scalar, z * scalar };
		}
		 

		constexpr Vec operator/(T scalar) const
		{
			return { x / scalar, y / scalar, z / scalar };
		}


		/*
			Calculates the dot product between 2 vectors
		*/
		constexpr T operator*(const Vec& other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}


		constexpr Vec operator+(const Vec& other) const
		{
			return { x + other.x, y + other.y, z + other.z };
		}


		constexpr Vec operator-(const Vec& other) const
		{
			return { x - other.x, y - other.y, z - other.z };
		}


		constexpr Vec operator-() const
		{
			return { -x, -y, -z };
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
			return x == other.x && y == other.y && z == other.z;
		}


		bool operator!=(const Vec& other) const
		{
			return !(*this == other);
		}
	};


	template <typename T>
	typename Vec<T, 3>::MemberType Vec<T, 3>::m_elements[3] = {
		&Vec<T, 3>::x,
		&Vec<T, 3>::y,
		&Vec<T, 3>::z
	};


	template <typename T>
	using Vec3 = Vec<T, 3>;

	using Vec3i = Vec3<int32_t>;
	using Vec3u = Vec3<uint32_t>;
	using Vec3f = Vec3<float>;



	template <typename T>
	constexpr Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b)
	{
		return {
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}
}