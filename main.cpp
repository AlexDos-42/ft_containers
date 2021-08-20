//#include "vector/Vector.hpp"
//#include "stack/Stack.hpp"
#include "map/Map.hpp"
#include <iostream>
#include <algorithm>

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
	first.print();
	first[4] = 200;
	first.print();
	first[6] = 200;
	first.print();
	first[9] = 200;
	first.print();
	first[1] = 200;
	first.print();
	first[16] = 200;
	first.print();
	first[78] = 200;
	first.print();
	first[2] = 200;
	first.print();
	first[400] = 200;
	first.print();
	first[7] = 200;
	first.print();
	first[24] = 200;
	first.print();
	first[56] = 200;
	first.print();
	first[1] = 250;
	first.print();
	first[77] = 200;
	first.print();
	std::cout << "////////// MAP //////////"  << std::endl << std::endl;
}

void stack()
{
	std::cout << std::endl << "////////// STACK //////////"  << std::endl;

	std::cout << "////////// STACK //////////"  << std::endl << std::endl;
}

// void vector()
// {
// 	std::cout << std::endl << "////////// VECTOR //////////"  << std::endl;
// 	ft::vector<int> first;
// 	ft::vector<int> second;
// 	first.push_back(1);
// 	first.push_back(3);
// 	first.push_back(5);
// 	first.push_back(7);
// 	second.push_back(2);
// 	second.push_back(4);
// 	second.push_back(6);
// 	second.push_back(8);
// 	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	swap(first, second);
// 	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	first.swap(second);
// 	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	second.assign((size_t)10, 10);
// 	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// 	std::cout << "first size ? " << first.size() << std::endl;
// 	std::cout << "front first ? " << first.front() << std::endl;
// 	std::cout << "back first ? " << first.back() << std::endl;
// 	first.pop_back();
// 	first.clear();
// 	std::cout << "first empty ? " << first.empty() << std::endl;
// 	std::cout << "first max size ? " << first.max_size() << std::endl;
// 	second.clear();
// 	std::cout << "////////// VECTOR //////////"  << std::endl << std::endl;
// 	next();
// }

void queue()
{
	std::cout << std::endl << "////////// QUEUE //////////"  << std::endl;
	std::cout << "////////// QUEUE //////////"  << std::endl << std::endl;
	next();
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
		if (str == "1" || str == "vector" || str == "Vector")
			;
//			vector();
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