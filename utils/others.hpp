#ifndef OTHERS
# define OTHERS

namespace ft
{
	template<class X>
	void	m_swap(X &x, X &y)
	{
			X			_tmp = x;
			x = y;
			y = _tmp;
	};
	
	template<typename Iterator>
	ptrdiff_t distance(Iterator first, Iterator last) {
		ptrdiff_t diff = 0;
		while (first != last) {
			++diff;
			++first;
		}
		return diff;
	}
}

#endif