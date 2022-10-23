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

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}

Cat const &Cat::operator=(Cat const &c)
{
    static_cast<Animal>(*this) = static_cast<Animal>(c);
    return (*this);
}

Cat::Cat(Cat const &c)
{
    std::cout << "Cat constructor was called." << std::endl;
    static_cast<Animal>(*this) = static_cast<Animal>(c);
}

Cat::Cat()
{
    std::cout << "Cat constructor was called." << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat destructor was called." << std::endl;
}


#endif