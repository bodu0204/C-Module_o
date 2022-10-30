#ifndef DATA_HPP
#define DATA_HPP

#include <inttypes.h>
#include <stddef.h>

class Data
{
private:
    int i;
public:
    int get_i() const;
    Data (int i);
    Data (Data const &);
    Data const & operator=(Data const &);
    Data ();
    ~Data ();
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif