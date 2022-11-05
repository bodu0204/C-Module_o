#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys();
    FragTrap();
    FragTrap(std::string name, int hp = 100, int ep = 100, int ad = 30);
    FragTrap(const FragTrap &S);
    FragTrap &operator=(const FragTrap &S);
    ~FragTrap();
};
