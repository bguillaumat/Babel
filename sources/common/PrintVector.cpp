/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#include <iterator>
#include "includes/common/PrintVector.hpp"

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T, std::allocator<T>> &v)
{
	if (!v.empty()) {
		out << '[';
		std::copy(v.begin(), v.end(),
			  std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}
