#pragma once

#include <cstdint>


namespace gm
{
	namespace meta
	{
		template <typename T>
		using unqualified_t = std::remove_cv_t<std::remove_reference_t>;
	}
}
