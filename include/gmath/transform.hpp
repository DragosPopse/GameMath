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
		const auto s = sin(radians);
		const auto c = cos(radians);
		const auto val = 1 - c;
		
		const auto axisn = normalize(axis);


		result[0][0] = c + axisn.x * axisn.x * (1 - c);
		result[0][1] = axisn.x * axisn.y * (1 - c) - axisn.z * s;
		result[0][2] = axisn.x * axisn.z * (1 - c) + axisn.y * s;

		result[1][0] = axisn.y * axisn.x * (1 - c) + axisn.z * s;
		result[1][1] = c + axisn.y * axisn.y * (1 - c);
		result[1][2] = axisn.y * axisn.z * (1 - c) - axisn.x * s;

		result[2][0] = axisn.z * axisn.x * (1 - c) - axisn.y * s;
		result[2][1] = axisn.z * axisn.y * (1 - c) + axisn.x * s;
		result[2][2] = c + axisn.z * axisn.z * (1 - c);

		return m * result;
	}


	template <typename T>
	Mat4<T> perspective(T fovTheta, T aspectRatio, T zNear, T zFar)
	{
		Mat4<T> result;

		T fov = T(1) / tan(fovTheta / T(2));
		T q = zFar / (zFar - zNear);

		result[0][0] = aspectRatio * fov;
		result[1][1] = fov;
		result[2][2] = q;
		result[3][2] = -zNear * q;
		result[2][3] = T(1);

		return result;
	}
}