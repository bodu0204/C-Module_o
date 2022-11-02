#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string zombie_name)
{
    Zombie z("randomChump_zombie");
    std::cout<<"My name is "<< z.get_name() << std::endl;
    return ;
}
