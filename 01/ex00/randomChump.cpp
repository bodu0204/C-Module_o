#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string zombie_name)
{
    Zombie z(zombie_name);
    std::cout<<"My name is "<< z.get_name() << std::endl;
    return ;
}
