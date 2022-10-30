#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stddef.h>

template <typename T>
class Array
{
private:
    T *arr;
    size_t len;
public:
    size_t size() const;
    T &operator[](size_t);
    Array();
    Array(unsigned int);
    Array(Array<T> &);
    Array<T> const & operator=(Array<T> &);
    ~Array();
};
#include "Array.tpp"
#endif