//#include "vector/Vector.hpp"
//#include "stack/Stack.hpp"
#include "map/Map.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include "common.hpp"
#include "utils/Pairs.hpp"

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

#define T1 int
#define T2 foo<int>

typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator ft_iterator;
typedef ft::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	TESTED_NAMESPACE::pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}
void fct_map()
{
	std::cout << std::endl << "////////// MAP //////////"  << std::endl;
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i + 1, (i + 1) * 3));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);
	ft_const_bound(mp, -10);
	ft_const_bound(mp, 1);
	ft_const_bound(mp, 5);
	ft_const_bound(mp, 10);
	ft_const_bound(mp, 50);

	printSize(mp);

	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	ft_bound(mp, 5);
	ft_bound(mp, 7);

	printSize(mp);
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
	// ft::vector<int> first;
	// ft::vector<int> second;
	// first.push_back(1);
	// first.push_back(3);
	// first.push_back(5);
	// first.push_back(7);
	// second.push_back(2);
	// second.push_back(4);
	// second.push_back(6);
	// second.push_back(8);
	// for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// swap(first, second);
	// for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// first.swap(second);
	// for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// second.assign((size_t)10, 10);
	// for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "first size ? " << first.size() << std::endl;
	// std::cout << "front first ? " << first.front() << std::endl;
	// std::cout << "back first ? " << first.back() << std::endl;
	// first.pop_back();
	// first.clear();
	// std::cout << "first empty ? " << first.empty() << std::endl;
	// std::cout << "first max size ? " << first.max_size() << std::endl;
	// second.clear();
	// std::cout << "////////// VECTOR //////////"  << std::endl << std::endl;
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