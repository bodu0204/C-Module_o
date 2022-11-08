#include <stdlib.h>
#include <iostream>
#include "Span.hpp"



int main(int argc, char *argv[]) {
    if (argc < 2)
        return (1);
std::cout<<"====addNumber"<<std::endl;  
    {
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
    }
std::cout<<"====addNumbers(int[])"<<std::endl;  
    {
        Span s(atoi(argv[1]));
        int arr[argc - 2];
        for (size_t i = 0; i < (size_t)argc - 2; i++)
        {
            arr[i] = atoi(argv[i + 2]);
        }
        try
        {
            s.addNumbers(arr, (size_t)argc - 2);
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
    }
std::cout<<"====addNumbers(vector<int>)"<<std::endl;  
    {
        Span s(atoi(argv[1]));
        std::vector<int> arr(argc - 2);
        for (size_t i = 0; i < (size_t)argc - 2; i++)
        {
            arr[i] = atoi(argv[i + 2]);
        }
        try
        {
            s.addNumbers(arr.begin(), (size_t)argc - 2);
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
    }
    return 0; 
}
