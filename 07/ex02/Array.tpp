#include "Array.hpp"

template <typename T>
size_t Array<T>::size() const
{
    return (this->len);
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
    if (i > this->len)
        throw (std::exception());
    return (this->arr[i]);
}

template <typename T>
T const &Array<T>::operator[](size_t i) const
{
    if (i > this->len)
        throw (std::exception());
    return (this->arr[i]);
}

template <typename T>
Array<T>::Array()
{
    this->arr = NULL;
    this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int l)
{
    this->arr = new T[l]();
    this->len = l;
}

template <typename T>
Array<T>::Array(Array<T> &a)
{
    this->arr = new T[a.size()]();
    this->len = a.size();
    for (size_t i = 0; i < this->len; i++)
        this->arr[i] = a[i];    
}

template <typename T>
Array<T> const & Array<T>::operator=(Array<T> &a)
{
    delete []this->arr;
    this->arr = new T[a.size()]();
    this->len = a.size();
    for (size_t i = 0; i < this->len; i++)
        this->arr[i] = a[i];    
    return(*this);
}

template <typename T>
Array<T>::~Array()
{
    delete []this->arr;
}
