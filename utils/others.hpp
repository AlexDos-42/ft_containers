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
}

#endif