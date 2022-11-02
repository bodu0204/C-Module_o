#include <string>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>

int main(int argc, char *argv[]) 
{
    if (argc != 4)
    {
        std::cout << "arg error" << std::endl;
        return 0;
    }
    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    std::fstream f;
    f.open(filename, std::ios_base::in);
    std::string data = "";
    char c;
    f.get(c);
    while (!f.fail() && !f.eof())
    {
        if(!f.fail() && !f.eof())
            data += c;
        if (data.rfind(s1) == data.length() - s1.length())
        {
            data = data.substr(0, data.length() - s1.length());
            data += s2;
        }
        f.get(c);
    }
    f.close();
    f.open(filename + ".replace", std::ios_base::out);
    f << data;
    f.close();
    return 0; 
}