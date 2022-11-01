#ifndef CAT_HPP
#define CAT_HPP 

#include <iostream>
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat :public Animal
{
private:
    Brain *b;
public:
    virtual void makeSound() const;
    Brain const *get_brainp() const;
    Cat();
    Cat(Cat const &);
    Cat const &operator=(Cat const &);
    ~Cat();
};

#endif
