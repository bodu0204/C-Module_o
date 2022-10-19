#ifndef CLAPTRAP 
#define CLAPTRAP 

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string name;
    unsigned int hp;
    unsigned int ep;
    unsigned int ad;
public:
    virtual void attack(const std::string& target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
    ClapTrap();
    ClapTrap(ClapTrap const &C);
    ClapTrap &operator=(ClapTrap const &C);
    ClapTrap(std::string name, int hp, int ep, int ap);
    ~ClapTrap();
};


#endif