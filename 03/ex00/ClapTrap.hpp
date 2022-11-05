#ifndef CLAPTRAP 
#define CLAPTRAP 

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string name;
    unsigned int hp;
    unsigned int ep;
    unsigned int ad;
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap();
    ClapTrap(ClapTrap const &C);
    ClapTrap &operator=(ClapTrap const &C);
    ClapTrap(std::string name, int hp, int ep, int ad);
    ~ClapTrap();
};


#endif