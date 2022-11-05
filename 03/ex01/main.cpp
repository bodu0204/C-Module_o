#include "ScavTrap.hpp"

using namespace std;
int main(void)
{
    ScavTrap s("A");

    while (true)
    {
        string str;
        cin >> str;
        if(str == "attack")
        {
            cin >> str;
            s.attack(str);
        }
        else if (str == "damage")
        {
            int i;
            cin >> i;
            s.takeDamage(i);
        }
        else if (str == "repaired")
        {
            int i;
            cin >> i;
            s.beRepaired(i);
        }
         else if (str == "gate")
        {
            s.guardGate();
        }
        else
            break;
    }
}