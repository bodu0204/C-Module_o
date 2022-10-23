#include <iostream>
#include <ctype.h>
#include "PhoneBook.hpp"
#include "../../debug.h"
int main (void)
{
    PhoneBook p;
    while (1)
    {
        if (std::cin.eof())
            return 1;
        std::string s;
        std::cout << "select(ADD/SEARCH/EXIT):";
        std::cin >> s;
        if (s == "ADD")
            p.add();
        else if (s == "SEARCH")
            p.search();        
        else if (s == "EXIT")
            return 0;      
    }
    return 0;
}