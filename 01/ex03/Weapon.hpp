#ifndef WEAPONE_HPP
#define WEAPONE_HPP
#include <string>
class Weapon
{
private:
    std::string type;
public:
    const std::string &getType() const;
    void setType(std::string);
    Weapon &operator=(Weapon const&);
    Weapon(void);
    Weapon(std::string);
    Weapon(Weapon const &);
    ~Weapon();
};

#endif