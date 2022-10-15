#include "./Weapon.hpp"
#include "./debug.h"

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
TEST
    this->type = "no_type";
    return ;
}

Weapon::Weapon(std::string str)
{
TEST
    this->type = str;
    return ;
}
/* 
Weapon::Weapon(Weapon &w)
{
TEST
    this->type = w.getType();
    return ;
}
 */
Weapon::~Weapon()
{}
