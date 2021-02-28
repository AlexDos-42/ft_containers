#ifndef BIDIRECTIONALITERATOR
# define BIDIRECTIONALITERATOR

namespace ft
{
	template <typename T>
	class iterator
	{
		private:
			Node<T>		*ptr;
		public:
			iterator() {}
			iterator(iterator const &ref) {*this = ref;}
			iterator(Node<T> *_ptr) : ptr(_ptr) {}
			~iterator() {}
			iterator			&operator=(iterator const &ref) { ptr = ref.ptr; return *this; }
		
		iterator	&operator++() {
			ptr = ptr->next;
			return *this;
		}
		iterator	&operator--() {
			ptr = ptr->prev;
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
		T &operator*() const {
			return *ptr->m_value;
		}
		T *operator->() const {
			return ptr->m_value;
		}
	};
};

#endif