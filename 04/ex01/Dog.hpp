#ifndef DOG_HPP
#define DOG_HPP 

#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

class Dog :public Animal
{
private:
    Brain *b;
public:
    virtual void makeSound() const;
    Brain const *get_brainp() const;
    Dog();
    Dog(Dog const &);
    Dog const &operator=(Dog const &);
    ~Dog();
};

#endif