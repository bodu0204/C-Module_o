#include "./HumanB.hpp"

void HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks" << std::endl;
    return ;
}

void HumanB::setWeapon(Weapon &w)
{
    this->weapon = &w;
    return ;
}


HumanB::HumanB(std::string name)
{
    this->weapon = NULL;
    this->name = name;
    return ;
}

HumanB::~HumanB()
{}


