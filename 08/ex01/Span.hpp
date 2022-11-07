#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
private:
    std::vector<int> vi;
    const size_t max_size;
    size_t use_size;
    Span();
public:
    class add_over : public std::exception{
        const char* what() const _NOEXCEPT;
    };
    Span(size_t);
    void addNumber(int);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    ~Span();
};

const char* Span::add_over::what() const _NOEXCEPT{return "Span::add_over";}

void Span::addNumber(int i){
    if (use_size >= max_size)
        throw Span::add_over();
    vi[use_size] = i;
    ++use_size;
    return ;
}

unsigned int Span::shortestSpan(){
    if (use_size < 2)
        return (0);
    unsigned int sp = (vi[0] > vi[1])?(vi[0] - vi[1]) : (vi[1] - vi[0]);
    for (size_t i = 1; i < use_size; ++i)
    {
        unsigned int spp = (vi[i - 1] > vi[i]) ? (vi[i - 1] - vi[i]) : (vi[i] - vi[i - 1]);
        if (spp < sp)
            sp = spp;
    }
    return sp;
}

unsigned int Span::longestSpan(){
    if (use_size < 2)
        return (0);
    unsigned int lp = (vi[0] > vi[1])?(vi[0] - vi[1]) : (vi[1] - vi[0]);
    for (size_t i = 1; i < use_size; ++i)
    {
        unsigned int lpp = (vi[i - 1] > vi[i]) ? (vi[i - 1] - vi[i]) : (vi[i] - vi[i - 1]);
        if (lpp > lp)
            lp = lpp;
    }
    return lp;
}


Span::Span()            :vi(0), max_size(0),use_size(0){}
Span::Span(size_t size) :vi(size), max_size(size),use_size(0){}
Span::~Span(){}


#endif
