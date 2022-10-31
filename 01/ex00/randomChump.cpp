#include "Zombie.hpp"
#include <iostream>

void Zombie::randomChump(std::string zombie_name)
{
    this->name = zombie_name;
    std::cout<<"My name is "<< this->name << std::endl;
    return ;
}
