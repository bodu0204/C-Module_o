#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate();
    ScavTrap();
    ScavTrap(std::string name, int hp, int ep, int ad);
    ScavTrap(const ScavTrap &S);
    ScavTrap &operator=(const ScavTrap &S);
    ~ScavTrap();
};
