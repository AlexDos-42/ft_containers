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
	test.push_front(45);
	test.push_front(2);
	test.push_front(66);
	test.push_front(2);
	test.push_front(10023);
	test.push_front(42);
	test.push_front(53);
	test.push_front(13);
	test.push_front(7);
	for (ft::iterator<int> it = test.begin(); it != test.end(); it++)
		std::cout << *it << " ";
	test.clear();
	std::cout << std::endl << "Size = " << test.size() << std::endl;
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << test.max_size() << std::endl;

	std::cout << "////////// QUEUE //////////"  << std::endl;
	ft::queue<int> Qtest;

	std::cout << "Size = " << Qtest.size() << std::endl;

}