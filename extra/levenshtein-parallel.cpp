#include <numeric>
#include <vector>
#include "../include/iosifovitch.hpp"
#include "../include/utility.hpp"

namespace iosifovitch::parallel {

auto levenshtein_distance
(
	std::string_view a,
	std::string_view b,
	std::vector<std::size_t>& buffer_vector
)
	-> size_t
{
    if (a.length() > b.length()) std::swap(a,b);
    reduce(a, b);

	size_t buffer_length = b.length() + 1;
	buffer_vector.resize(
	    std::max(buffer_vector.size(), buffer_length)
    );

	auto buffer = buffer_vector.data();

	std::iota(buffer, buffer + buffer_length, 0);
	for (size_t i = 1; i < a.length() + 1; ++i)
	{
		auto temp = buffer[0]++;
		for (size_t j = 1; j < buffer_length; ++j)
		{
			auto p = buffer[j - 1];
			auto r = buffer[j];
			temp = std::min(
			    std::min(r, p) + 1,
			    temp + (a[i - 1] == b[j - 1] ? 0 : 1)
			);
			std::swap(buffer[j], temp);
		}
	}

	return buffer[buffer_length - 1];
}

}
