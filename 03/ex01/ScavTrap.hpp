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
    ScavTrap(std::string name, int hp = 100, int ep = 50, int ad = 20);
    ScavTrap(const ScavTrap &S);
    ScavTrap &operator=(const ScavTrap &S);
    ~ScavTrap();
};
