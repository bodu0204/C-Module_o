#include "WrongDog.hpp"

void WrongDog::makeSound() const
{
    std::cout << "bowwow bowwow" << std::endl;
}

WrongDog const &WrongDog::operator=(WrongDog const &c)
{
    static_cast<WrongAnimal>(*this) = static_cast<WrongAnimal>(c);
    return (*this);
}

WrongDog::WrongDog(WrongDog const &c)
{
    std::cout << "WrongDog constructor was called." << std::endl;
    static_cast<WrongAnimal>(*this) = static_cast<WrongAnimal>(c);
}

WrongDog::WrongDog()
{
    std::cout << "WrongDog constructor was called." << std::endl;
    this->type = "WrongDog";
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor was called." << std::endl;
}
