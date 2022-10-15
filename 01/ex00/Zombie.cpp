#include "./Zombie.hpp"
Zombie::Zombie(void)
{
    this->name = "zombie";
    return ;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    return ;
}

Zombie::~Zombie()
{
    std::cout << this->name << " destructor called." << std::endl;
    return ;
}

#include <iostream>

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
