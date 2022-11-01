#ifndef BRAIN_HPP
#define BRAIN_HPP

#define arr_len 100

#include <string>
#include <iostream>

class Brain
{
private:
    std::string idea[arr_len];
public:
    std::string const *get_ideap() const;
    Brain();
    Brain(Brain const &);
    Brain const &operator=(Brain const &);
    virtual ~Brain();
};

#endif
