#ifndef CAT_HPP
#define CAT_HPP 

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat :public Animal
{    
public:
    virtual void makeSound() const;
    Cat();
    Cat(Cat const &);
    Cat const &operator=(Cat const &);
    ~Cat();
};

#endif