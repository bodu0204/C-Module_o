#ifndef WEAPONE_HPP
#define WEAPONE_HPP
#include <string>
class Weapon
{
private:
    std::string type;
public:
    const std::string &getType();
    void setType(std::string);
    Weapon &operator=(Weapon);
    Weapon(void);
    Weapon(std::string);
    //Weapon(Weapon &);
    ~Weapon();
};

#endif