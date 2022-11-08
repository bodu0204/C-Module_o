#include <string>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        std::cout << "arg error" << std::endl;
        return 1;
    }
    bool isn = true;
    bool isf = false;
    for (size_t i = 0; i < strlen(argv[1]); ++i)
    {
        if (!isdigit(argv[1][i]) \
        && !(i && i == strlen(argv[1]) - 1 && (argv[1][i] == 'f' || argv[1][i] == 'F')))
            isn = false;
        if (argv[1][i] == '.')
        {
            isn = true;
            if (isf)
                isn = false;
            else
                isf = true;
        }
        if (!isn)
            break;
    }
    if (!strcmp(argv[1], "nan"))
        isf = true;
    double d = atof(argv[1]);

    std::cout << "char: ";
    if (isn)
    {
        if (d > CHAR_MAX || d < CHAR_MIN)
            std::cout << "overflows" << std::endl;
        else if (isprint(static_cast<char>(d)))
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (isn)
    {
        if (d > INT_MAX || d < INT_MIN)
            std::cout << "overflows" << std::endl;
        else
        {
            std::cout << static_cast<int>(d) << std::endl;
            if (static_cast<double>(static_cast<int>(d)) == d)
            {
                size_t i = 0;
                for (; argv[1][i] && argv[1][i] != '.'; ++i);
                std::cout.precision(i + 1);
            }
        }
    }
    else
        std::cout << "impossible" << std::endl;
        
    std::cout << "float: ";
    if (isn || isf)
        std::cout << std::showpoint << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: ";
    if (isn || isf)
        std::cout << std::showpoint << d << std::endl;
    else
        std::cout << "impossible" << std::endl;
    return 0;
}