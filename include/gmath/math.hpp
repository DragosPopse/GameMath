#pragma once

#include <cmath>

#include <gmath/details/cmath/sqrt.hpp>

#include <gmath/details/cmath/sin.hpp>
#include <gmath/details/cmath/cos.hpp>
#include <gmath/details/cmath/tan.hpp>


namespace gm
{
	namespace detail
	{
		template <typename T>
		struct constval_pi
		{
			static_assert(std::is_floating_point_v<T>, "PI must have a floating point type.");
			static constexpr T value = T(0);
		};

		template <>
		struct constval_pi<float>  
		{
			static constexpr float value = 3.1415927f;
		};
		
		template <>
		struct constval_pi<double>
		{
			static constexpr double value = 3.141592653589793;
		};

		template <>
		struct constval_pi<long double> 
		{
			static constexpr long double value = 3.141592653589793238L;
		};
	}

	template <typename T>
	inline constexpr T pi = detail::constval_pi<T>::value;


	template <typename T>
	T deg2rad(T degrees)
	{
		return degrees * pi<T> / T(180);
	}

	
	template <typename T>
	T rad2deg(T rads)
	{
		return rads * T(180) / pi<T>;
	}
}