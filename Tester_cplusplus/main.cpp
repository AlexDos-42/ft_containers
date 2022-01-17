#include <iostream>
#include <algorithm>
#include <list>

void mapTest();
void vectorTest();
void stackTest();

void next()
{
	std::string l;
	while (1)
	{
		std::cout << std::endl << "\e[94mContinue ? (y/n)\e[0m" << std::endl;
		std::cout << "\t➜ ";
		std::cin >> l;
		if (l == "y")
			break;
	}
	std::cout << std::endl;
}


void map()
{
	std::cout << std::endl << "////////// MAP //////////"  << std::endl;
	mapTest();
	std::cout << "////////// MAP //////////"  << std::endl << std::endl;
}

void stack()
{
	std::cout << std::endl << "////////// STACK //////////"  << std::endl;
	stackTest();
	std::cout << "////////// STACK //////////"  << std::endl << std::endl;
}

void vector()
{
	std::cout << std::endl << "////////// VECTOR //////////"  << std::endl;
	vectorTest();
	std::cout << "////////// VECTOR //////////"  << std::endl << std::endl;
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
			map();
		else if (str == "3" || str == "stack" || str == "Stack")
			stack();
		else if (str == "4" || str == "exit")
			break ;
	}
	return (0);
}