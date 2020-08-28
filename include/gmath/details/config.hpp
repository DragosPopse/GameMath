#pragma once

#include <cstdint>
#include <type_traits>


namespace gm
{
	namespace meta
	{
		template <typename T>
		using unqualified_t = std::remove_cv_t<std::remove_reference_t<T>>;
	}
}
