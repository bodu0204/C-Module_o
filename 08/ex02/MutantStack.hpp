#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <stddef.h>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    MutantStack();
    MutantStack const & operator=(MutantStack const &);
    MutantStack(MutantStack<T> const &);
    ~MutantStack();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){return this->c.begin();}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){return this->c.end();}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){return this->c.rbegin();}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(){return this->c.rend();}


template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T> const & MutantStack<T>::operator=(MutantStack<T> const &m){
    static_cast<std::stack<T> >(*this) = static_cast<std::stack<T> >(m);
    return *this;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &m){
    *this = m;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

#endif