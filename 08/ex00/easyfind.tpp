#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
    typename T::iterator i = std::find(a.begin(), a.end(), b);
    if (i!=a.end())
        return i;
    else
        throw easyfind_cant_find();
}
