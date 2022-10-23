#ifndef BRAIN_HPP
#define BRAIN_HPP

#define arr_len 100

#include <string>

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

std::string const *Brain::get_ideap() const
{
    return (idea);
}

Brain::Brain()
{
    std::cout << "Brain constructor was called." << std::endl;
}

Brain::Brain(Brain const & b)
{
    std::cout << "Brain constructor was called." << std::endl;
    std::string const * s = b.get_ideap();
    for (size_t i = 0; i < arr_len; i++)
        this->idea[i] = s[i];
}

Brain const &Brain::operator=(Brain const & b)
{
    std::string const * s = b.get_ideap();
    for (size_t i = 0; i < arr_len; i++)
        this->idea[i] = s[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor was called." << std::endl;
}

#endif
