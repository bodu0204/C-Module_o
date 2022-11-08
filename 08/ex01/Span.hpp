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
    template <typename iterator_int> void addNumbers(iterator_int, size_t);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    ~Span();
};

template <typename iterator_int>
void Span::addNumbers(iterator_int arr, size_t len){
    for (size_t i = 0; i < len; i++)
    {
        if (this->use_size >= this->max_size)
            throw add_over();
        this->vi[use_size] = arr[i];
        use_size++;
    }
}

#endif
