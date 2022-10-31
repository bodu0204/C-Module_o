#include <iostream>
#include "./Harl.hpp"

int main() {

    std::string str;
    Harl h;
    std::cin >> str;    
    while (!std::cin.eof())
    {
        h.complain(str);
        std::cin >> str;
    }
    return 0; 
}