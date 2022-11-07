#include <stdlib.h>
#include <iostream>
#include "Span.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2)
        return (1);
    (void)argv;
    Span s(atoi(argv[1]));
    try
    {
        for (size_t i = 2; i < (size_t)argc; i++)
            s.addNumber(atoi(argv[i]));

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    unsigned sp = s.shortestSpan();
    unsigned lp = s.longestSpan();
    std::cout << "shortestSpan: " << sp << std::endl;
    std::cout << "longestSpan: " << lp << std::endl;
    return 0; 
}
