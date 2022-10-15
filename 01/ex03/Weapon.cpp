#include "./Weapon.hpp"

const std::string &Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string str)
{
    this->type = str;
    return ;
}

Weapon &Weapon::operator=(Weapon w)
{
    this->type = w.getType();
    return *this;
}

Weapon::Weapon(void)
{
    this->type = "no_type";
    return ;
}

Weapon::Weapon(std::string str)
{
    this->type = str;
    return ;
}
/* 
Weapon::Weapon(Weapon &w)
{
    this->type = w.getType();
    return ;
}
 */
Weapon::~Weapon()
{}
