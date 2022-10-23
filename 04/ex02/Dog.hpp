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

void Dog::makeSound() const
{
    std::cout << "bowwow" << std::endl;
}

Brain const *Dog::get_brainp() const
{
    return b;
}

Dog const &Dog::operator=(Dog const &c)
{
    static_cast<Animal>(*this) = static_cast<Animal>(c);
    delete this->b;
    this->b = new Brain(*(c.b));
    return (*this);
}

Dog::Dog(Dog const &c)
{
    std::cout << "Dog constructor was called." << std::endl;
    static_cast<Animal>(*this) = static_cast<Animal>(c);
    this->b = new Brain(*(c.b));
}

Dog::Dog()
{
    std::cout << "Dog constructor was called." << std::endl;
    this->type = "Dog";
    this->b = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor was called." << std::endl;
    delete this->b;
}

#endif