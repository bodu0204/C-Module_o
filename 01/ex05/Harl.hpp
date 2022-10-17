#ifndef HARL_HPP
#define HARL_HPP
#include <string>
class Harl
{
private:
    static void rtn();
    static void debug();
    static void info();
    static void warning();
    static void error();
    void (* cop[5])(void);
public:
    void complain(std::string level);
    Harl();
    ~Harl();
};

#endif