#include "WrongCat.hpp"

void WrongCat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}

WrongCat const &WrongCat::operator=(WrongCat const &c)
{
    static_cast<WrongAnimal>(*this) = static_cast<WrongAnimal>(c);
    return (*this);
}

WrongCat::WrongCat(WrongCat const &c)
{
    std::cout << "WrongCat constructor was called." << std::endl;
    static_cast<WrongAnimal>(*this) = static_cast<WrongAnimal>(c);
}

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor was called." << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor was called." << std::endl;
}
