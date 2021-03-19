#pragma once
#include <string_view>
#include <vector>

//! \mainpage Iosifovitch
//!
//! Iosifovitch is a library that implements edit distance functions such as the
//! Levenshtein distance function and the Damerau-Levenshtein distance function.
//!
//! The aim is to provide the fastest implementations, both in real world
//! performance and asymptotically.
//!
//! The current implementaiton of the Levenshtein distance function in
//! asymptotically terms, is the fastest know to the author. As far as is know,
//! it is also the fastest real life implementation.
//!

namespace iosifovitch
{

//! \brief The iosifovitch::parallel namespace contains multi-threaded versions
//!        of the functions in the main namespace.
//!
//! The single threaded functions and the parallel functions are separated in
//! namespaces to avoid cluttering the function names with redundant
//! information.
namespace parallel
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
//! \remark This function uses multiple threads to do the calculations.
//! \remark This function is thread safe *iff* the buffer is not shared between
//! threads.
//!
//! \bug The current implementation does not use more than one thread.
//!
//! \return The number of insertions, deletions or replacements required to
//!         transform one string to the other.
//!
//! \authors Frederik Hertzum <frederik.hertzum@gmail.com>
//!
//! \see iosifovitch::levenshtein_distance
auto levenshtein_distance(
	std::string_view first,
	std::string_view second,
	std::vector<size_t>& buffer
)
	-> size_t;
//!
//! \brief Calculate the edit distance between two strings, according to the
//! Levenshtein distance function.
//!
//! This functions uses more than one thread and may run each thread in
//! parallel.
//!
//! \param first a string
//! \param second a string
//!
//! \bug The current implementation calculates the levenshtein distance.
//!
//! \bug The current implementation does not use more than one thread.
//!
//! \see iosifovitch::levenshtein_distance
//!
//! \return The number of insertions, deletions or replacements required to
//!         transform one string to the other.
//!
static inline
auto levenshtein_distance(
	std::string_view first,
	std::string_view second
)
	-> size_t
{
	std::vector<size_t> buffer;
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
//! \remark This function uses multiple threads to do the calculations.
//! \remark This function is thread safe *iff* the buffer is not shared between
//! threads.
//!
//! \bug The current implementation calculates the levenshtein distance.
//!
//! \bug The current implementation does not use more than one thread.
//!
//! \return The number of insertions, rotations, deletions or replacements
//!         required to transform one string to the other.
//!
//! \authors Frederik Hertzum <frederik.hertzum@gmail.com>
//!
//! \see iosifovitch::damerau_levenshtein_distance
//!
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
//! \remark This function is always thread safe.
//!
//! \bug The current implementation calculates the levenshtein distance.
//! \bug The current implementation does not use more than one thread.
//!
//! \overload auto damerau_levenshtein_distance(std::string_view, std::string_view, std::vector<std::size>&) -> size_t
//!
static inline
auto damerau_levenshtein_distance(
	std::string_view first,
	std::string_view second
)
	-> size_t
{
	std::vector<size_t> buffer;
	buffer.reserve(std::max(first.size(), second.size()));
	return damerau_levenshtein_distance(first, second, buffer);
}
}
}
