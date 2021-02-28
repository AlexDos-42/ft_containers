#include "List.hpp"
#include "Queue.hpp"
#include <iostream>
#include "BidirectionalIterator.hpp"

int main (void)
{
	std::cout << "////////// LIST //////////"  << std::endl;
	ft::list<int> test;

	test.push_front(4);
	test.push_back(100);
	std::cout << "Size = " << test.size() << std::endl;
	test.push_front(7);
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << "Size ? " << test.size() << std::endl;
	std::cout << "front = " << test.front() << std::endl;
	std::cout << "back = " << test.back() << std::endl;
	for (ft::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << " ";
	test.clear();
	std::cout << "Size = " << test.size() << std::endl;
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << test.max_size() << std::endl;

	std::cout << "////////// QUEUE //////////"  << std::endl;
	ft::queue<int> Qtest;

	std::cout << "Size = " << Qtest.size() << std::endl;

}