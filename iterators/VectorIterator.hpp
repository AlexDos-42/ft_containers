#ifndef VECTORITERATOR
# define VECTORITERATOR

namespace ft
{
	template <typename T>
	class iterator
	{
		private:
			T*		ptr;
		public:
			iterator() {}
			iterator(iterator const &ref) {*this = ref;}
			iterator(T* *_ptr) : ptr(_ptr) {}
			~iterator() {}
			iterator			&operator=(iterator const &ref) { ptr = ref.ptr; return *this; }
		
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
		T* operator->() const {
			return ptr->m_value;
		}
		T operator*() const {
			return ptr->m_value;
		}
		
		bool	operator==(iterator const &ref) const {
			return ptr->m_value == ref.ptr->m_value;
		}
		bool	operator!=(iterator const &ref) const {
			return !(*this == ref);
		}
	};
}

#endif