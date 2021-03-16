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
			typedef NodeMap<T, Compare>	*							NodeMap;
			typedef MapIterator<T, T*, T&, Compare >				iterator;
		//private:
			NodeMap		m_it;
		public:
			MapIterator(): m_it(NULL) {}
			MapIterator(const NodeMap it) : m_it(it) {}
			//MapIterator(const iterator const &ref): m_it(ref) {}
			~MapIterator() {}
			MapIterator<T, Pointer, Reference, Compare > &operator=(MapIterator<T, const T*, const T&, Compare > const &ref) {
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
			T* operator->() const {
				return m_it->m_value;
			}
			T operator*() const {
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