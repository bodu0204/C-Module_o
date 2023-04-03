#include "PmergeMe.hpp"
#include <iostream>
int main (int argc, char *argv[])
{
    PmergeMe pm(argc, argv);
    std::cout << pm.get_result() << std::endl;
}