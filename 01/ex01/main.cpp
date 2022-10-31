#include <string>
#include "./Zombie.hpp"

int main()
{
    Zombie* z = Zombie::zombieHorde(32, "zombie");
    
    for (size_t i = 0; i < 32; i++)
        z[i].announce();
    delete []z;
    system("leaks Moar_brainz");
    return 0;
}