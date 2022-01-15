#include "../vector/vector.hpp"
#include "../stack/Stack.hpp"
#include "../map/Map.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include "../utils/pair.hpp"

void mapTest();

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


void fct_map()
{
	std::cout << std::endl << "////////// MAP //////////"  << std::endl;
	mapTest();
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

void Stack()
{
	std::cout << std::endl << "////////// STACK //////////"  << std::endl;
	std::cout << "////////// STACK //////////"  << std::endl << std::endl;
	next();
}



int main (void)
{
	std::string str;

	std::cout << "\e[94mWelcome, this is my FT_containers project:\e[0m" << std::endl;
	while (1)
	{
		std::cout << "\e[94mWhat container do you want ?" << std::endl;
		std::cout << "tape 1: Vector" << std::endl;
		std::cout << "tape 2: Map" << std::endl;
		std::cout << "tape 3: Stack" << std::endl;
		std::cout << "tape 4: exit\e[0m" << std::endl;
		std::cout << "\t➜ ";
		std::cin >> str;
		if (str == "1" || str == "vector" || str == "Vector")
			vector();
		else if (str == "2" || str == "map" || str == "Map")
			fct_map();
		else if (str == "3" || str == "stack" || str == "Stack")
			stack();
		else if (str == "4" || str == "exit")
			break ;
	}
	return (0);
}