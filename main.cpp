#include "List.hpp"
#include <iostream>

int main (void)
{
	ft::list<int> test;

	test.push_front(4);
	test.push_back(100);
	std::cout << "Size = " << test.size() << std::endl;
	test.push_front(7);
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << "Size ? " << test.size() << std::endl;
	std::cout << "front = " << test.front() << std::endl;
	std::cout << "back = " << test.back() << std::endl;
	test.clear();
	std::cout << "Size = " << test.size() << std::endl;
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << test.max_size() << std::endl;
}