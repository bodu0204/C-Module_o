#include <string>
#include "./HumanA.hpp"
#include "./HumanB.hpp"

#include "debug.h"

int main() {
    {
TEST STOP
        Weapon c;
TEST STOP
        c = Weapon("crude spiked club");
TEST STOP
        Weapon club(c);
TEST STOP
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    } 
    {
TEST STOP
        Weapon club;
TEST STOP
        club = Weapon("crude spiked club");
TEST STOP
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0; 
}