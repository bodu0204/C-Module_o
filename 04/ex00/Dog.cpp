#include "Dog.hpp"

void Dog::makeSound() const
{
    std::cout << "bowwow bowwow" << std::endl;
}

Dog const &Dog::operator=(Dog const &c)
{
    static_cast<Animal>(*this) = static_cast<Animal>(c);
    return (*this);
}

Dog::Dog(Dog const &c)
{
    std::cout << "Dog constructor was called." << std::endl;
    static_cast<Animal>(*this) = static_cast<Animal>(c);
}

Dog::Dog()
{
    std::cout << "Dog constructor was called." << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor was called." << std::endl;
}
