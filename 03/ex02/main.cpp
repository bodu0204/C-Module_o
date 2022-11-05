#include "FragTrap.hpp"

using namespace std;
int main(void)
{
    FragTrap s("F");

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
         else if (str == "hi")
        {
            s.highFivesGuys();
        }
        else
            break;
    }
}