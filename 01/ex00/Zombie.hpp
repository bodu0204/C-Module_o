#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
class Zombie
{
private:
    std::string name;
public:
    std::string get_name(void);
    Zombie(void);
    Zombie(std::string);
    ~Zombie();
    void announce(void);
};

void randomChump(std::string);
Zombie* newZombie(std::string);

#endif