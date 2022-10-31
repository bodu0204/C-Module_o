#include "./Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    if(n <= 0)
        return NULL;

    Zombie *z = new Zombie[n];

    for (size_t i = 0; i < (size_t)n; i++)
    {
        z[i].set_name(name);
    }
    return z;
}
