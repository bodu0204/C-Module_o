#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
    if (this->ep <= 0 || this->hp <= 0)
        return ;
    this->ep--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "<< this->ad <<" points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hp > amount)
    {
        std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
        this->hp -= amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " take " << this->hp << " points of damage!" << std::endl;
        this->hp = 0;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->ep <= 0)
        return ;
    this->ep--;
    this->hp += amount;
    std::cout << "ClapTrap " << this->name << " take " << amount << " points of Hit point!" << std::endl;
    return ;
}

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap was made." << std::endl
    << "[WARNING] not initialized ClapTrap class." << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &C)
{
    std::cout << "ClapTrap was copied." << std::endl;
    this->name = C.name;
    this->hp = C.hp;
    this->ep = C.ep;
    this->ad = C.ad;
    return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &C)
{
    std::cout << "ClapTrap was made." << std::endl;
    this->name = C.name;
    this->hp = C.hp;
    this->ep = C.ep;
    this->ad = C.ad;
    return (*this);
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad)
{
    std::cout << "ClapTrap was made." << std::endl;
    this->name = name;
    this->hp = hp;
    this->ep = ep;
    this->ad = ad;
    return ;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap was destroyed." << std::endl;
}

