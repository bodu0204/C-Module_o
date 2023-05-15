#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const
{
    std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

WrongAnimal const &WrongAnimal::operator=(WrongAnimal const & a)
{
    this->type = a.getType();
    return (*this);
}

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor was called." << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &a)
{
    std::cout << "WrongAnimal constructor was called." << std::endl;
    this->type = a.getType();
}

WrongAnimal::WrongAnimal(std::string set)
{
    std::cout << "WrongAnimal constructor was called." << std::endl;
    this->type = set;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor was called." << std::endl;
}
