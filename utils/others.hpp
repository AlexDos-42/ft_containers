#ifndef OTHERS_HPP
# define OTHERS_HPP

#include <cstddef>

namespace ft
{
	template<class X>
	void	m_swap(X &x, X &y)
	{
			X			_tmp = x;
			x = y;
			y = _tmp;
	};
	
	template<typename InputIterator>
	size_t distance(InputIterator first, InputIterator last) {
		size_t diff = 0;
		while (first != last) {
			++diff;
			++first;
		}
		return diff;
	}
}

#endif