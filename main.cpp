#include "list/List.hpp"
#include "queue/Queue.hpp"
#include "vector/Vector.hpp"
#include "stack/Stack.hpp"
#include <iostream>
#include "iterators/BidirectionalIterator.hpp"

void queue()
{
	std::cout << std::endl << "////////// QUEUE //////////"  << std::endl;
	ft::queue<int> Qtest;

	std::cout << "Size = " << Qtest.size() << std::endl;
	std::cout << "////////// QUEUE //////////"  << std::endl << std::endl;
}

void list()
{
	std::cout << std::endl << "////////// LIST //////////"  << std::endl;
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
	std::cout << std::endl;
	ft::list<std::string> second;
	second.assign(7, "Bonjour");
	for (ft::iterator<std::string> it = second.begin() ; it != second.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	second.resize(10, "BYE");
	for (ft::iterator<std::string> it = second.begin(); it != second.end(); it++)
		std::cout << *it << " ";
	test.clear();
	second.clear();
	std::cout << std::endl << "Size = " << test.size() << std::endl;
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << test.max_size() << std::endl;
	std::cout << "////////// LIST //////////"  << std::endl << std::endl;
}

int main (void)
{
	std::string str;

	std::cout << "\e[94mWelcome, this is my FT_containers project:\e[0m" << std::endl;
	while (1)
	{
		std::cout << "\e[94mWhat container do you want ?" << std::endl;
		std::cout << "tape 1: List" << std::endl;
		std::cout << "tape 2: Queue" << std::endl;
		std::cout << "tape 3: exit\e[0m" << std::endl;
		std::cout << "\t➜ ";
		std::cin >> str;
		if (str == "1" || str == "list" || str == "List")
			list();
		else if (str == "2" || str == "queue" || str == "Queue")
			queue();   
		else if (str == "3" || str == "exit")
			break ;
	}
	return (0);
}