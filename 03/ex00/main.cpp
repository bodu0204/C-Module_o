#include "ClapTrap.hpp"

using namespace std;
int main(void)
{
    ClapTrap c("A", 10, 10, 0);

    while (true)
    {
        string str;
        cin >> str;
        if(str == "attack")
        {
            cin >> str;
            c.attack(str);
        }
        else if (str == "damage")
        {
            int i;
            cin >> i;
            c.takeDamage(i);
        }
        else if (str == "repaired")
        {
            int i;
            cin >> i;
            c.beRepaired(i);
        }
        else
            break;
    }
    
}