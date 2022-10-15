#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

typedef unsigned int uint32;
typedef unsigned long uint64;
typedef long int64;

class Span {
	private:
		std::vector<int>*	data_;
		uint32				N_;
	public:
		Span();
		Span(const uint32 n);
		Span(const Span& copy);
		Span& operator = (const Span& a);
		~Span();

		void addNumber(const int n);
		void addNumbers(const std::vector<int> v);
		uint32 shortestSpan() const;
		int64 longestSpan() const;
		void put(std::ostream& ost) const;
};

std::ostream& operator << (std::ostream& ost, const Span& s);

#endif
