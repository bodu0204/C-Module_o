#include "Dog.hpp"

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
    this->type = c.getType();
    delete this->b;
    this->b = new Brain(*(c.b));
    return (*this);
}

Dog::Dog(Dog const &c)
{
    std::cout << "Dog constructor was called." << std::endl;
    this->type = c.getType();
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
