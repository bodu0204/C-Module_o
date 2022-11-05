#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
    if (this->ep <= 0 || this->hp <= 0)
        return ;
    this->ep--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "<< this->ad <<" points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->hp > amount)
    {
        std::cout << "ScavTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
        this->hp -= amount;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " take " << this->hp << " points of damage!" << std::endl;
        this->hp = 0;
    }
    return ;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->ep <= 0)
        return ;
    this->ep--;
    this->hp += amount;
    std::cout << "ScavTrap " << this->name << " take " << amount << " points of Hit point!" << std::endl;
    return ;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
    return ;
}
ScavTrap::ScavTrap():ClapTrap("no-name", 100, 50, 20)
{
    std::cout << "ScavTrap was made." << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name, int hp, int ep, int ad):ClapTrap(name, hp, ep, ad)
{
    std::cout << "ScavTrap was made." << std::endl;
    return ;
}
 
ScavTrap::ScavTrap(const ScavTrap &S):ClapTrap(static_cast<const ClapTrap>(S))
{
    std::cout << "ScavTrap was made." << std::endl;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap was destroyed." << std::endl;
    return ;
}
