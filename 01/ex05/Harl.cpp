#include "./Harl.hpp"
#include <iostream>

void Harl::complain(std::string level)
{
    size_t i = 0;

    i += ((size_t)(level == "debug")) * 1;
    i += ((size_t)(level == "info")) * 2;
    i += ((size_t)(level == "warning")) * 3;
    i += ((size_t)(level == "error")) * 4;
    this->cop[i]();
    return ;
}

void Harl::rtn(void)
{
    return ;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, Harl::I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
    cop[0] = rtn;
    cop[1] = debug;
    cop[2] = info;
    cop[3] = warning;
    cop[4] = error;
}

Harl::~Harl()
{}
