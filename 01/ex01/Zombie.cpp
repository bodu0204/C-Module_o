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
#include <iostream>

Zombie::~Zombie()
{}

void Zombie::set_name(std::string name)
{
    this->name = name;
    return ;
}


void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
