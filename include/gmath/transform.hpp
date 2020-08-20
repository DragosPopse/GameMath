#pragma once


#include <gmath/details/config.hpp>

#include <gmath/mat.hpp>
#include <gmath/vec.hpp>
#include <gmath/math.hpp>


namespace gm
{
	template <typename T>
	Mat4<T> translate(const Mat4<T>& m, const Vec3<T>& translation)
	{
		Mat4<T> result(T(1));
		result[0].w = translation.x;
		result[1].w = translation.y;
		result[2].w = translation.z;
		return  m * result;
	}


	template <typename T>
	Mat4<T> scale(const Mat4<T>& m, const Vec3<T>& scaling)
	{
		Mat4<T> result;
		result[0][0] = scaling[0];
		result[1][1] = scaling[1];
		result[2][2] = scaling[2];
		result[3][3] = 1;

		return m * result;
	}


	template <typename T>
	Mat4<T> rotate(const Mat4<T>& m, std::conditional_t<std::is_floating_point_v<T>, T, float> radians, const Vec3<T>& axis)
	{
		Mat4<T> result(1.f);
		auto s = sin(radians);
		auto c = cos(radians);
		auto val = 1 - c; //to be used after benchmark


		result[0][0] = c + axis.x * axis.x * (1 - c);
		result[0][1] = axis.x * axis.y * (1 - c) - axis.z * s;
		result[0][2] = axis.x * axis.z * (1 - c) + axis.y * s;

		result[1][0] = axis.y * axis.x * (1 - c) + axis.z * s;
		result[1][1] = c + axis.y * axis.y * (1 - c);
		result[1][2] = axis.y * axis.z * (1 - c) - axis.x * s;

		result[2][0] = axis.z * axis.x * (1 - c) - axis.y * s;
		result[2][1] = axis.z * axis.y * (1 - c) + axis.x * s;
		result[2][2] = c = axis.z * axis.z * (1 - c);

		return result;
	}
}