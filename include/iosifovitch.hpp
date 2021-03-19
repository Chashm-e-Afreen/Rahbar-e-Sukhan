#pragma once
#include <numeric>
#include <vector>
#include <iostream>
#include <cmath>
#include <string_view>
#include <vector>

//! \brief The iosifovitch namespace is the main namespace of the iosifovitch
//!        libary.
namespace iosifovitch
{

//! \brief Calculate the edit distance between two strings, according to the
//! rules of the Levenshtein distance function.
//!
//! The levenshtein distance is a metric that measures the number of changes
//! needed to translate one string to the other. The operations allowed are
//! replacement, insertion and deletion, with each operation has a cost of 1.
//!
//! The following guarantees are given by the function:
//! * The distance between two strings does not depend on the order
//! * The distance between two strings is non-negative
//! * The distance between identical strings is 0.
//! * The distance between two strings is at least the difference in their
//!   lengths.
//!
//! \param first a string
//! \param second a string
//! \param buffer A preallocated buffer to store the calculations in. This may
//!        be resized and its elements may be changed.
//!
//! \remark This function is thread safe *iff* the buffer is not shared between
//! threads.
//!
//! \return The number of insertions, deletions or replacements required to
//!         transform one string to the other.
//!
//! \authors Frederik Hertzum <frederik.hertzum@gmail.com>
//!
//! \see iosifovitch::parallel::levenshtein_distance
//!
//! \ingroup iosifovitch
auto levenshtein_distance(
	std::string_view first,
	std::string_view second,
	std::vector<size_t>& buffer
)
	-> size_t;

//! \brief Calculate the edit distance between two strings, according to the
//! rules of the Levenshtein distance function.
//!
//! This is a convenience function that reduces local namespace pollution, by
//! not requireing a buffer to be already defined and passed as an argument.
//!
//! \param first a string
//! \param second a string
//!
//! \remark This function is always thread safe.
//!
//! \overload auto levenshtein_distance(std::string_view, std::string_view, std::vector<std::size>&) -> size_t
//!
//! \ingroup iosifovitch
static inline
auto levenshtein_distance(
	std::string_view first,
	std::string_view second
)
	-> size_t
{
	thread_local std::vector<size_t> buffer;
	buffer.reserve(std::max(first.size(), second.size()));
	return levenshtein_distance(first, second, buffer);
}


//! \brief Calculate the edit distance between two strings, according to the
//! rules of the Damerau-Levenshtein distance function.
//!
//! The Damerau-Levenshtein is a metric that measures the number of changes
//! needed to translate one string to the other. The operations allowed are
//! replacement, rotation, insertion and deletion, with each operation has a
//! cost of 1.
//!
//! The following guarantees are given by the function:
//! * The distance between two strings does not depend on the order
//! * The distance between two strings is non-negative
//! * The distance between identical strings is 0.
//! * The distance between two strings is at least the difference in their
//!   lengths.
//!
//! \param first a string
//! \param second a string
//! \param buffer A preallocated buffer to store the calculations in. This may
//!        be resized and its elements may be changed.
//!
//! \remark This function is thread safe *iff* the buffer is not shared between
//! threads.
//!
//! \bug The current implementation calculates the levenshtein distance.
//!
//! \return The number of insertions, rotations, deletions or replacements
//!         required to transform one string to the other.
//!
//! \authors Frederik Hertzum <frederik.hertzum@gmail.com>
//!
//! \see iosifovitch::parallel::damerau_levenshtein_distance
//!
//! \ingroup iosifovitch
auto damerau_levenshtein_distance(
	std::string_view first,
	std::string_view second,
	std::vector<size_t>& buffer
)
	-> size_t;

//! \brief Calculate the edit distance between two strings, according to the
//! rules of the Damerau-Levenshtein distance function.
//!
//! This is a convenience function that reduces local namespace pollution, by
//! not requireing a buffer to be already defined and passed as an argument.
//!
//! \param first a string
//! \param second a string
//!
//! \bug The current implementation calculates the levenshtein distance.
//!
//! \remark This function is always thread safe.
//!
//! \overload auto damerau_levenshtein_distance(std::string_view, std::string_view, std::vector<std::size>&) -> size_t
//!
//! \ingroup iosifovitch
static inline
auto damerau_levenshtein_distance(
	std::string_view first,
	std::string_view second
)
	-> size_t
{
	thread_local std::vector<size_t> buffer;
	buffer.reserve(std::max(first.size(), second.size()));
	return damerau_levenshtein_distance(first, second, buffer);
}



}



