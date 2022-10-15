#include <iostream>
#include <ctype.h>
#include "PhoneBook.hpp"
int main (void)
{
    PhoneBook p;
    while (1)
    {
        std::string s;
        std::cout << "select(ADD/SEARCH):";
        std::cin >> s;
        if (s == "ADD")
            p.add();
        else if (s == "SEARCH")
            p.search();        
    }
    return 0;
}