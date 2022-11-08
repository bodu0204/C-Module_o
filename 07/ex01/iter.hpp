#ifndef ITER_HPP
#define ITER_HPP
#include <stddef.h>

template <typename T>
void iter(T *a, size_t l, void (*op)(T const &))
{
    for (size_t i = 0; i < l; ++i)
    {
        (*op)(a[i]);
    }
    return ;
}
#endif