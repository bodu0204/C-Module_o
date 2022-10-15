#include "Span.hpp"

#include <time.h>

__attribute__((destructor))
static void d(){
	std::cout << "=====leaks=====\n";
	system("leaks -q a.out");
}

int main() {
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp << '\n';
	std::cout << sp.shortestSpan() << '\n';
	std::cout << sp.longestSpan() << '\n';
}
std::cout << "\n==================\n\n";
{
	Span sp = Span(3);
	sp.addNumber(INT_MAX);
	sp.addNumber(INT_MIN);
	// sp.addNumber(0);
	std::cout << sp << '\n';

	std::cout << sp.longestSpan() << '\n';
	std::cout << sp.shortestSpan() << '\n';
}
std::cout << "\n==================\n\n";
{
	uint32 N = 10000;
	Span sp = Span(N);
	srand(time(NULL));
	std::vector<int> v;
	for (uint32 i=0; i < N; i++) v.push_back(rand());

	sp.addNumbers(v);
	std::cout << sp.longestSpan() << '\n';
	std::cout << sp.shortestSpan() << '\n';
}
std::cout << "\n==================\n\n";
{
	try
	{
		Span sp = Span(4);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		Span sp2(sp);

		std::cout << "sp: " << sp << '\n';
		std::cout << "sp2: " << sp2 << '\n';

		sp.addNumber(4);

		std::cout << "sp: " << sp << '\n';
		std::cout << "sp2: " << sp2 << '\n';

		sp.longestSpan();
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
}
