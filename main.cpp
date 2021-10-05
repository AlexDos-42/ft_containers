#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	std::cout << "VCT capacity: " << vct.capacity() << std::endl;
	//printSize(vct);
	std::cout << "vct_two capacity: " << vct_two.capacity() << std::endl;
	//printSize(vct_two);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	//printSize(vct);
	std::cout << "VCT capacity: " << vct.capacity() << std::endl;
	//printSize(vct_two);
	std::cout << "vct_two capacity: " << vct_two.capacity() << std::endl;
	//printSize(vct_three);
	std::cout << "vct_three capacity: " << vct_three.capacity() << std::endl;
	//printSize(vct_four);
	std::cout << "vct_four capacity: " << vct_four.capacity() << std::endl;

	vct_four.assign(6, 84);
	//printSize(vct_four);
	std::cout << "vct_four capacity: " << vct_four.capacity() << std::endl;

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	//printSize(vct);
	std::cout << "VCT capacity: " << vct.capacity() << std::endl;
	//printSize(vct_two);
	std::cout << "vct_two capacity: " << vct_two.capacity() << std::endl;

	return (0);
}
