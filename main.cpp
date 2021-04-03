#include "list/List.hpp"
#include "queue/Queue.hpp"
#include "vector/Vector.hpp"
#include "stack/Stack.hpp"
#include "map/Map.hpp"
#include <iostream>
#include "iterators/BidirectionalIterator.hpp"
#include <algorithm>
#include "map/Map.hpp"
# include "utils/Pairs.hpp"

void next()
{
	std::string l;
	while (1)
	{
		std::cout << "\e[94mContinue ? (y/n)\e[0m" << std::endl;
		std::cout << "\t➜ ";
		std::cin >> l;
		if (l == "y")
			return;
	}
}

void map()
{
	std::cout << std::endl << "////////// MAP //////////"  << std::endl;
	ft::map<int, int> first;
	first.insert(ft::make_pair(14, 353));
	first.insert(ft::make_pair(5, 353));
	first.insert(ft::make_pair(6, 353));
	first.insert(ft::make_pair(4, 353));
	first.insert(ft::make_pair(16, 353));
	first.insert(ft::make_pair(17, 353));
	first.insert(ft::make_pair(108, 353));
	first.insert(ft::make_pair(12, 353));
	first.insert(ft::make_pair(1300, 353));
	first.insert(ft::make_pair(33, 353));
	first.insert(ft::make_pair(16, 353));
	first.insert(ft::make_pair(1, 353));
	first.insert(ft::make_pair(1, 353));
	first.print();
	std::cout << "////////// MAP //////////"  << std::endl << std::endl;
}

void stack()
{
	std::cout << std::endl << "////////// STACK //////////"  << std::endl;

	std::cout << "////////// STACK //////////"  << std::endl << std::endl;
}

void vector()
{
	std::cout << std::endl << "////////// VECTOR //////////"  << std::endl;
	ft::vector<int> first;
	ft::vector<int> second;
	first.push_back(1);
	first.push_back(3);
	first.push_back(5);
	first.push_back(7);
	second.push_back(2);
	second.push_back(4);
	second.push_back(6);
	second.push_back(8);
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	swap(first, second);
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	first.swap(second);
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	second.assign((size_t)10, 10);
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "first size ? " << first.size() << std::endl;
	std::cout << "front first ? " << first.front() << std::endl;
	std::cout << "back first ? " << first.back() << std::endl;
	first.pop_back();
	first.clear();
	std::cout << "first empty ? " << first.empty() << std::endl;
	std::cout << "first max size ? " << first.max_size() << std::endl;
	second.clear();
	std::cout << "////////// VECTOR //////////"  << std::endl << std::endl;
	next();
}

void queue()
{
	std::cout << std::endl << "////////// QUEUE //////////"  << std::endl;
	ft::queue<int> Qtest;

	std::cout << "Size = " << Qtest.size() << std::endl;
	std::cout << "////////// QUEUE //////////"  << std::endl << std::endl;
	next();
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
	for (ft::list<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	ft::list<std::string> second;
	second.assign(7, "Bonjour");
	for (ft::list<std::string>::iterator it = second.begin() ; it != second.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	second.resize(10, "BYE");
	for (ft::list<std::string>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << " ";
	test.clear();
	second.clear();
	std::cout << std::endl << "Size = " << test.size() << std::endl;
	std::cout << "Empty ? " << test.empty() << std::endl;
	std::cout << test.max_size() << std::endl;
	std::cout << "////////// LIST //////////"  << std::endl << std::endl;
	//next();
}

int main (void)
{
	std::string str;

	std::cout << "\e[94mWelcome, this is my FT_containers project:\e[0m" << std::endl;
	while (1)
	{
		std::cout << "\e[94mWhat container do you want ?" << std::endl;
		std::cout << "tape 1: List" << std::endl;
		std::cout << "tape 2: Vector" << std::endl;
		std::cout << "tape 3: Map" << std::endl;
		std::cout << "tape 4: Stack" << std::endl;
		std::cout << "tape 5: Queue" << std::endl;
		std::cout << "tape 6: exit\e[0m" << std::endl;
		std::cout << "\t➜ ";
		std::cin >> str;
		if (str == "1" || str == "list" || str == "List")
			list();
		else if (str == "2" || str == "vector" || str == "Vector")
			vector();
		else if (str == "3" || str == "map" || str == "Map")
			map();
		else if (str == "4" || str == "stack" || str == "Stack")
			stack();
		else if (str == "5" || str == "queue" || str == "Queue")
			queue();
		else if (str == "6" || str == "exit")
			break ;
	}
	return (0);
}