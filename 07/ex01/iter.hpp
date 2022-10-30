#ifndef ITER_HPP
#define ITER_HPP
#include <stddef.h>

template <typename T>
void iter(T *a, size_t l, T (*op)(T))
{
    for (size_t i = 0; i < l; ++i)
    {
        a[i] = (*op)(a[i]);
    }
    return ;
}
#endif