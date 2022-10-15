#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(int ac, char** argv) {

	if (ac != 2)
		return 1;

	std::vector<int> v1(100);

	for (uint i=0; i < 100; i++)
		v1.at(i) = i + 200;

	for (uint i=0; i < v1.size(); i++) {
		std::cout << v1.at(i);
		std::cout << ", ";
	}

	std::cout << "\n=====\n\n";
	if (ac != 2)
		return 1;

	std::vector<int>::iterator it = easyfind(v1, atoi(argv[1]));

	if (*it)
		std::cout << *it << " found !\n";
}
