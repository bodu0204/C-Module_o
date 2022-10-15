#include "MutantStack.hpp"

#include <iostream>

int main() {

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << '\n';
	mstack.pop();
	std::cout << mstack.top() << '\n';

	mstack.push(121);
	mstack.push(12);
	mstack.push(11111);
	mstack.push(135423);
	mstack.push(13441);
	mstack.push(3776);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite) {
		std::cout << *it << '\n';
		++it;
	}
}
