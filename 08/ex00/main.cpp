#include <iostream>
#include <vector>
#include <stdlib.h>
#include "easyfind.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2)
        return (1);
    (void)argv;
    std::vector<int> vi(argc - 2);
    for (size_t i = 0; i < (size_t)argc - 2; i++)
        vi.at(i) = atoi(argv[i + 1]);
    try
    {
        std::vector<int>::iterator vii = easyfind(vi, atoi(argv[argc - 1]));
        std::cout << *vii <<std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0; 
}
