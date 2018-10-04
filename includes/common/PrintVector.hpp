/*
** EPITECH PROJECT, 2021
** CPP_babel_2018
** File description:
** Created by asianpw,
*/

#ifndef CPP_BABEL_2018_PRINTVECTOR_HPP
#define CPP_BABEL_2018_PRINTVECTOR_HPP

#include <ostream>
#include <vector>

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T, std::allocator<T>> &v);

#endif //CPP_BABEL_2018_PRINTVECTOR_HPP
