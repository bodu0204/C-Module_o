#include <iostream>
#include <ctype.h>
int main (int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
        return 0;        
    }
    for (size_t i = 1; i < (size_t)argc; i++)
    {
        for (size_t ii  = 0; argv[i][ii]; ii ++)
            std::cout<<(char)toupper(argv[i][ii]);
    }
    std::cout<<std::endl;
    return 0;
}