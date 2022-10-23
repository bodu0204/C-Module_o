#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    virtual void makeSound() const = 0;
    std::string getType() const;
    Animal const &operator=(Animal const &);
    Animal();
    Animal(Animal const &);
    Animal(std::string);
    virtual ~Animal();
};

void Animal::makeSound() const
{
    std::cout << "..." << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

Animal const &Animal::operator=(Animal const & a)
{
    this->type = a.getType();
    return (*this);
}

Animal::Animal()
{
    std::cout << "Animal constructor was called." << std::endl;
    this->type = "Animal";
}

Animal::Animal(Animal const &a)
{
    std::cout << "Animal constructor was called." << std::endl;
    this->type = a.getType();
}

Animal::Animal(std::string set)
{
    std::cout << "Animal constructor was called." << std::endl;
    this->type = set;
}

Animal::~Animal()
{
    std::cout << "Animal destructor was called." << std::endl;
}


#endif