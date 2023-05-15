#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongDog :public WrongAnimal
{
public:
    virtual void makeSound() const;
    WrongDog();
    WrongDog(WrongDog const &);
    WrongDog const &operator=(WrongDog const &);
    ~WrongDog();
};

#endif