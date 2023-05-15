#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal
{
public:
    virtual void makeSound() const;
    WrongCat();
    WrongCat(WrongCat const &);
    WrongCat const &operator=(WrongCat const &);
    ~WrongCat();
};

#endif