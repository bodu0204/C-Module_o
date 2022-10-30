#ifndef BASE_HPP
#define BASE_HPP

#include <inttypes.h>
#include <stddef.h>
#include <iostream>

class Base
{    
public:
    virtual void iam();
};

void Base::iam()
{
    std::cout<<"Base class" << std::endl;
}

#endif