#pragma once

#include <gmath/details/basic_mat.hpp>

#include <array>

#include <gmath/details/vec4.hpp>



namespace gm
{
	template <typename T>
	struct Mat<T, 3, 3>
	{
		static constexpr size_t ROWS = 3;
		static constexpr size_t COLUMNS = 3;

		using RowType = Vec3<T>;
		using VecType = Vec3<T>;
		using ElementsType = std::array<RowType, COLUMNS>;

		ElementsType m_elements;

	public:
		constexpr Mat() = default;


		constexpr Mat(const Mat& other) = default;


		constexpr Mat(const ElementsType& elements) :
			m_elements(elements)
		{
		}


		explicit Mat(T scalar)
		{
			m_elements[0][0] = scalar;
			m_elements[1][1] = scalar;
			m_elements[2][2] = scalar;
		}


		Mat operator*(T scalar) const
		{
			Mat result;

			result[0].x = m_elements[0].x * scalar;
			result[0].y = m_elements[0].y * scalar;
			result[0].z = m_elements[0].z * scalar;

			result[1].x = m_elements[1].x * scalar;
			result[1].y = m_elements[1].y * scalar;
			result[1].z = m_elements[1].z * scalar;

			result[2].x = m_elements[2].x * scalar;
			result[2].y = m_elements[2].y * scalar;
			result[2].z = m_elements[2].z * scalar;

			result[3].x = m_elements[3].x * scalar;
			result[3].y = m_elements[3].y * scalar;
			result[3].z = m_elements[3].z * scalar;

			return result;
		}


		Mat operator*(const Mat& other) const
		{
			Mat result;

			result[0].x =
				m_elements[0].x * other[0].x +
				m_elements[0].y * other[1].x +
				m_elements[0].z * other[2].x;
			result[0].y =
				m_elements[0].x * other[0].y +
				m_elements[0].y * other[1].y +
				m_elements[0].z * other[2].y;
			result[0].z =
				m_elements[0].x * other[0].z +
				m_elements[0].y * other[1].z +
				m_elements[0].z * other[2].z;
			result[0].w =
				m_elements[0].x * other[0].w +
				m_elements[0].y * other[1].w +
				m_elements[0].z * other[2].w;


			result[1].x =
				m_elements[1].x * other[0].x +
				m_elements[1].y * other[1].x +
				m_elements[1].z * other[2].x;
			result[1].y =
				m_elements[1].x * other[0].y +
				m_elements[1].y * other[1].y +
				m_elements[1].z * other[2].y;
			result[1].z =
				m_elements[1].x * other[0].z +
				m_elements[1].y * other[1].z +
				m_elements[1].z * other[2].z;
			result[1].w =
				m_elements[1].x * other[0].w +
				m_elements[1].y * other[1].w +
				m_elements[1].z * other[2].w;


			result[2].x =
				m_elements[2].x * other[0].x +
				m_elements[2].y * other[1].x +
				m_elements[2].z * other[2].x;
			result[2].y =
				m_elements[2].x * other[0].y +
				m_elements[2].y * other[1].y +
				m_elements[2].z * other[2].y;
			result[2].z =
				m_elements[2].x * other[0].z +
				m_elements[2].y * other[1].z +
				m_elements[2].z * other[2].z;
			result[2].w =
				m_elements[2].x * other[0].w +
				m_elements[2].y * other[1].w +
				m_elements[2].z * other[2].w;


			return result;
		}


		Mat operator+(const Mat& other) const
		{
			Mat result;

			result[0].x = m_elements[0].x + other[0].x;
			result[0].y = m_elements[0].y + other[0].y;
			result[0].z = m_elements[0].z + other[0].z;

			result[1].x = m_elements[1].x + other[1].x;
			result[1].y = m_elements[1].y + other[1].y;
			result[1].z = m_elements[1].z + other[1].z;

			result[2].x = m_elements[2].x + other[2].x;
			result[2].y = m_elements[2].y + other[2].y;
			result[2].z = m_elements[2].z + other[2].z;

			return result;
		}


		VecType operator*(const VecType& v) const
		{
			VecType result;

			result.x =
				m_elements[0].x * v.x +
				m_elements[0].y * v.y +
				m_elements[0].z * v.z;

			result.y =
				m_elements[1].x * v.x +
				m_elements[1].y * v.y +
				m_elements[1].z * v.z;

			result.z =
				m_elements[2].x * v.x +
				m_elements[2].y * v.y +
				m_elements[2].z * v.z;

			return result;
		}


		RowType& operator[](size_t index)
		{
			return m_elements[index];
		}


		const RowType& operator[](size_t index) const
		{
			return m_elements[index];
		}


		const T* data() const
		{
			return &m_elements[0].x;
		}
	};


	template <typename T>
	using Mat3 = Mat<T, 3, 3>;

	using Mat3i = Mat3<int32_t>;
	using Mat3u = Mat3<uint32_t>;
	using Mat3f = Mat3<float>;
}