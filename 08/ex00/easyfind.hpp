#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class easyfind_cant_find :public std::exception{
    const char* what() const _NOEXCEPT;
};
const char* easyfind_cant_find::what() const _NOEXCEPT{return "easyfind::cant_find";}


template <typename T>
typename T::iterator easyfind(T &a, int b);
#include "easyfind.tpp"

#endif
