#ifndef BIDIRECTIONALITERATOR
# define BIDIRECTIONALITERATOR

namespace ft
{
	template <typename T, class Alloc>
	class BidirectIterator
	{
		public:
			typedef BidirectIterator			iterator;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef Node<value_type, Alloc>*		node;
			typedef size_t						size_type;
		private:
			node	ptr;
		public:
			BidirectIterator() {}
			BidirectIterator(iterator const &ref) {
				*this = ref;
			}
			BidirectIterator(node ref) : ptr(ref) {}
			~BidirectIterator() {}
			iterator			&operator=(iterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			iterator	&operator++() {
				ptr = ptr->m_next;
				return *this;
			}
			iterator	&operator--() {
				ptr = ptr->m_back;
				return *this;
			}
			iterator	operator++(int) {
				iterator	tmp(*this);
				++(*this);
				return tmp;
			}
			iterator	operator--(int) {
				iterator	tmp(*this);
				--(*this);
				return tmp;
			}
			pointer operator->() const {
				return ptr->m_value;
			}
			reference operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(iterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(iterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T, class Alloc>
	class ReverseBidirectIterator
	{
		public:
			typedef ReverseBidirectIterator		iterator;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef Node<value_type, Alloc>*		node;
			typedef size_t						size_type;
		private:
			node 	ptr;
		public:
			ReverseBidirectIterator() {}
			ReverseBidirectIterator(iterator const &ref) {
				*this = ref;
			}
			ReverseBidirectIterator(node ref) : ptr(ref) {}
			~ReverseBidirectIterator() {}
			iterator	&operator=(iterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			iterator	&operator++() {
				ptr = ptr->m_back;
				return *this;
			}
			iterator	&operator--() {
				ptr = ptr->m_next;
				return *this;
			}
			iterator	operator++(int) {
				iterator	tmp(*this);
				--(*this);
				return tmp;
			}
			iterator	operator--(int) {
				iterator	tmp(*this);
				++(*this);
				return tmp;
			}
			pointer operator->() const {
				return ptr->m_value;
			}
			reference operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(iterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(iterator const &ref) const {
				return !(*this == ref);
			}
	};
};

#endif