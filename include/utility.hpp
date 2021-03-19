#pragma once

#include <string_view>
#include <algorithm>
#include <string>

static bool ends_with(const std::string& str, const std::string& suffix);

inline static bool ends_with(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}


template<typename T>
T abs_diff(T a, T b) {
  return a > b ? a - b : b - a;
}

template<class I>
auto prefix_length
(
    I abegin, I aend,
    I bbegin, I bend
)
{
    return std::distance(abegin, std::mismatch(abegin, aend, bbegin, bend).first);
}

static inline
auto reduce
(
    std::string_view& a,
    std::string_view& b
)
    -> void
{
    auto prefix = prefix_length(a.begin(), a.end(), b.begin(), b.end());
    a.remove_prefix(prefix);
    b.remove_prefix(prefix);

    auto suffix = prefix_length(a.rbegin(), a.rend(), b.rbegin(), b.rend());
    a.remove_suffix(suffix);
    b.remove_suffix(suffix);
}
