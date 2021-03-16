#ifndef MAPITERATOR
# define MAPITERATOR

# include <memory>
# include <cstddef>

namespace ft
{
	template < typename T, typename Pointer, typename Reference, class Compare >
	class MapIterator
	{
		public:
			typedef MapIterator<T, Pointer, Reference, Compare >	this_type;
			typedef NodeMap<T, Compare>*							NodeMap;
			typedef MapIterator<T, T*, T&, Compare >				iterator;
			typedef MapIterator<T, const T*, const T&, Compare >	const_iterator;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef T			value_type;

			NodeMap		m_it;
			
			MapIterator(): m_it(NULL) {}
			MapIterator(const NodeMap it) : m_it(it) {}
			MapIterator(const iterator& ref): 
				m_it(const_cast<NodeMap>(ref.m_it)) {}
			~MapIterator() {}
			this_type& operator=(const_iterator const &ref) {
				m_it = ref.ptr;
				return *this;
			}
		
			MapIterator	&operator++() {
				m_it = m_it->getnext();
				return *this;
			}
			MapIterator	&operator--() {
				m_it = m_it->m_back;
				return *this;
			}
			MapIterator	operator++(int) {
				MapIterator	tmp(*this);
				++(*this);
				return tmp;
			}
			MapIterator	operator--(int) {
				MapIterator	tmp(*this);
				--(*this);
				return tmp;
			}
			pointer operator->() const {
				return m_it->m_value;
			}
			reference operator*() const {
				return m_it->m_value;
			}
			
			bool	operator==(MapIterator const &ref) const {
				return m_it->m_value == ref.m_it->m_value;
			}
			bool	operator!=(MapIterator const &ref) const {
				return !(*this == ref);
			}
	};
};

#endif