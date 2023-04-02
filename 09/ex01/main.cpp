#include "RPN.hpp"
#include <iostream>
int main (int argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        RPN r(argv[i]);
        std::cout << r.get_answer()<<std::endl;
        
    }
}