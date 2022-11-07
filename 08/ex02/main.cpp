#include <stdlib.h>
#include <iostream>
#include "MutantStack.hpp"

int main(int argc, char *argv[]) {
    MutantStack<int> m;

    for (size_t i = 1; i < (size_t)argc; i++)
        m.push(atoi(argv[i]));
    if (argc > 2)
        std::cout<<"=======*"<<std::endl;
    {
        MutantStack<int>::iterator mi = m.begin();
        if (argc > 2)
            std::cout<<"*mi "<< *mi <<std::endl;
        if (argc > 3)
        {
            mi++;
            std::cout<<"*mi++;*mi "<< *mi <<std::endl;
        }
    }
    std::cout<<"=======begin()"<<std::endl;
    {
        MutantStack<int>::iterator mi = m.begin();
        for (size_t i = 0; i < m.size(); ++i)
        {
            std::cout<<"mi["<<i<<"] "<< mi[i] <<std::endl;
        }   
    }
    std::cout<<"=======end()"<<std::endl;
    {
        MutantStack<int>::iterator mi = m.end();
        for (ssize_t i = 0; i < (ssize_t)m.size(); ++i)
        {
            std::cout<<"mi["<<-i - 1<<"] "<< mi[-i - 1] <<std::endl;
        }   
    }
    std::cout<<"=======rbegin()"<<std::endl;
    {
        MutantStack<int>::reverse_iterator mr = m.rbegin();
        for (size_t i = 0; i < m.size(); ++i)
        {
            std::cout<<"mr["<<i<<"] "<< mr[i] << std::endl;
        }   
    }
    std::cout<<"=======rend()"<<std::endl;
    {
        MutantStack<int>::reverse_iterator mr = m.rend();
        for (ssize_t i = 0; i < (ssize_t)m.size(); ++i)
        {
            std::cout<<"mr["<<-i - 1<<"] "<< mr[-i - 1] << std::endl;
        }   
    }
}
