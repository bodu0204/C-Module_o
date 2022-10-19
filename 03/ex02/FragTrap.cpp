#include "FragTrap.hpp"

void FragTrap::attack(const std::string& target)
{
    if (this->ep <= 0 || this->hp <= 0)
        return ;
    this->ep--;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing "<< this->ad <<" points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (this->hp > amount)
    {
        std::cout << "FragTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
        this->hp -= amount;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " take " << this->hp << " points of damage!" << std::endl;
        this->hp = 0;
    }
    return ;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->ep <= 0)
        return ;
    this->ep--;
    this->hp += amount;
    std::cout << "FragTrap " << this->name << " take " << amount << " points of Hit point!" << std::endl;
    return ;
}

void FragTrap::highFivesGuys()
{
    std::cout << "HI🖐" << std::endl;
    return ;
}
FragTrap::FragTrap():ClapTrap("no-name", 100, 50, 20)
{
    std::cout << "FragTrap was made." << std::endl
    << "[WARNING] not initialized FragTrap class." << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name, int hp, int ep, int ad):ClapTrap(name, hp, ep, ad)
{
    std::cout << "FragTrap was made." << std::endl;
    return ;
}
 
FragTrap::FragTrap(const FragTrap &S):ClapTrap(static_cast<const ClapTrap>(S))
{
    std::cout << "FragTrap was made." << std::endl;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap was destroyed." << std::endl;
    return ;
}
