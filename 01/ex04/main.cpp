#include <string>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include "debug.h"

int main() 
{
    std::string filename;
    std::string s1;
    std::string s2;

    std::cin >> filename >> s1 >> s2;
    if(std::cin.fail())
    {
        std::cout << "read error" << std::endl;
        return (0);
    }
    std::fstream f;
    f.open(filename, std::ios_base::in);
    std::string data;
    while (!f.fail() || !f.eof())
    {
        char c;
        f.get(c);
        if(!f.fail() || !f.eof())
            data += c;
        if (data.rfind(s1) != SIZE_T_MAX)
        {
            data = data.substr(0, data.length() - s1.length());
            data += s2;
        }
    }
    f.close();
    f.open(filename, std::ios_base::out);
    f << data;
    f.close();
    return 0; 
}