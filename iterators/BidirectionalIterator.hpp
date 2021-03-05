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
			iterator(iterator const &ref) {
				*this = ref;
			}
			iterator(Node<T> *_ptr) : ptr(_ptr) {}
			~iterator() {}
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

	template <typename T>
	class constiterator
	{
		private:
			Node<T>		*ptr;
		public:
			constiterator() {}
			constiterator(constiterator const &ref) {
				*this = ref;
			}
			constiterator(Node<T> *_ptr) : ptr(_ptr) {}
			~constiterator() {}
			constiterator	&operator=(constiterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			constiterator	&operator++() {
				ptr = ptr->m_next;
				return *this;
			}
			constiterator	&operator--() {
				ptr = ptr->m_back;
				return *this;
			}
			constiterator	operator++(int) {
				constiterator	tmp(*this);
				++(*this);
				return tmp;
			}
			constiterator	operator--(int) {
				constiterator	tmp(*this);
				--(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(constiterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(constiterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class reverseiterator
	{
		private:
			Node<T>		*ptr;
		public:
			reverseiterator() {}
			reverseiterator(reverseiterator const &ref) {
				*this = ref;
			}
			reverseiterator(Node<T> *_ptr) : ptr(_ptr) {}
			~reverseiterator() {}
			reverseiterator	&operator=(reverseiterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			reverseiterator	&operator++() {
				ptr = ptr->m_back;
				return *this;
			}
			reverseiterator	&operator--() {
				ptr = ptr->m_next;
				return *this;
			}
			reverseiterator	operator++(int) {
				reverseiterator	tmp(*this);
				--(*this);
				return tmp;
			}
			reverseiterator	operator--(int) {
				reverseiterator	tmp(*this);
				++(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(reverseiterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(reverseiterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class reverseconstiterator
	{
		private:
			Node<T>		*ptr;
		public:
			reverseconstiterator() {}
			reverseconstiterator(reverseconstiterator const &ref) {
				*this = ref;
			}
			reverseconstiterator(Node<T> *_ptr) : ptr(_ptr) {}
			~reverseconstiterator() {}
			reverseconstiterator	&operator=(reverseconstiterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			reverseconstiterator	&operator++() {
				ptr = ptr->m_back;
				return *this;
			}
			reverseconstiterator	&operator--() {
				ptr = ptr->m_next;
				return *this;
			}
			reverseconstiterator	operator++(int) {
				reverseconstiterator	tmp(*this);
				--(*this);
				return tmp;
			}
			reverseconstiterator	operator--(int) {
				reverseconstiterator	tmp(*this);
				++(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(reverseconstiterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(reverseconstiterator const &ref) const {
				return !(*this == ref);
			}
	};
};

#endif