#include "Brain.hpp"

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
