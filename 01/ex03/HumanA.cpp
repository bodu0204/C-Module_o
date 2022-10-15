#include "./HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
    return ;
}

HumanA::HumanA(std::string name, Weapon &w):weapon(w)
{
    this->name = name;
    return ;
}

HumanA::~HumanA()
{}


