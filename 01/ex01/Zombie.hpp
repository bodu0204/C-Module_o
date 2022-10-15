#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
class Zombie
{
private:
    std::string name;
public:
    Zombie(void);
    Zombie(std::string);
    ~Zombie();
    void set_name(std::string);
    void announce(void);
    static Zombie* zombieHorde(int, std::string);
};

#endif