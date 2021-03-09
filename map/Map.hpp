#ifndef MAP
# define MAP

# include <cstddef>
# include <limits>
# include <iostream>
# include <functional>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
	class map
	{
		public:
            typedef	T											value_type;
			// typedef MapIterator<T>					            iterator;
			// typedef ConstMapIterator<T>			                const_iterator;
			// typedef ReverseMapIterator<T>			            reverse_iterator;
			// typedef ConstReverseMapIterator<T>		            const_reverse_iterator;
            typedef Alloc										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference  	const_reference;
		private:

		public:

			///////// ITERATORS /////////
			

			///////// CAPACITY /////////
			

			///////// ELEMENTS ACCESS /////////
			

			///////// MODIFIERS /////////
			
			

			///////// LIST OPERATIONS /////////
			
	};	
}

#endif