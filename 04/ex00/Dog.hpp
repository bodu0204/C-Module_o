#ifndef DOG_HPP
#define DOG_HPP 

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog :public Animal
{    
public:
    virtual void makeSound() const;
    Dog();
    Dog(Dog const &);
    Dog const &operator=(Dog const &);
    ~Dog();
};

#endif