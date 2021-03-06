#ifndef VECTORITERATOR
# define VECTORITERATOR

namespace ft
{
	template <typename T>
	class VectorIterator
	{
		private:
			T*		ptr;
		public:
			VectorIterator() {}
			VectorIterator(VectorIterator const &ref) {
				*this = ref;
			}
			VectorIterator(T *_ptr): ptr(_ptr) {}
			~VectorIterator() {}
			VectorIterator	&operator=(VectorIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			VectorIterator	&operator++() {
				ptr = ptr + 1;
				return *this;
			}
			VectorIterator	&operator--() {
				ptr = ptr - 1;
				return *this;
			}
			VectorIterator	operator++(int) {
				VectorIterator	tmp(*this);
				operator++();
				return tmp;
			}
			VectorIterator	operator--(int) {
				VectorIterator	tmp(*this);
				operator--();
				return tmp;
			}
			T* operator->() const {
				return ptr;
			}
			T operator*() const {
				return *ptr;
			}
			
			bool	operator==(VectorIterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(VectorIterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ConstVectorIterator
	{
		private:
			T*		ptr;
		public:
			ConstVectorIterator() {}
			ConstVectorIterator(ConstVectorIterator const &ref) {
				*this = ref;
			}
			ConstVectorIterator(T* _ptr) : ptr(_ptr) {}
			~ConstVectorIterator() {}
			ConstVectorIterator		&operator=(ConstVectorIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			ConstVectorIterator	&operator++() {
				ptr = ptr + 1;
				return *this;
			}
			ConstVectorIterator	&operator--() {
				ptr = ptr - 1;
				return *this;
			}
			ConstVectorIterator	operator++(int) {
				ConstVectorIterator	tmp(*this);
				operator++();
				return tmp;
			}
			ConstVectorIterator	operator--(int) {
				ConstVectorIterator	tmp(*this);
				operator--();
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(ConstVectorIterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(ConstVectorIterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ReverseVectorIterator
	{
		private:
			T*		ptr;
		public:
			ReverseVectorIterator() {}
			ReverseVectorIterator(ReverseVectorIterator const &ref) {
				*this = ref;
			}
			ReverseVectorIterator(T* _ptr) : ptr(_ptr) {}
			~ReverseVectorIterator() {}
			ReverseVectorIterator		&operator=(ReverseVectorIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			ReverseVectorIterator	&operator++() {
				ptr = ptr + 1;
				return *this;
			}
			ReverseVectorIterator	&operator--() {
				ptr = ptr - 1;
				return *this;
			}
			ReverseVectorIterator	operator++(int) {
				ReverseVectorIterator	tmp(*this);
				operator++();
				return tmp;
			}
			ReverseVectorIterator	operator--(int) {
				ReverseVectorIterator	tmp(*this);
				operator--();
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(ReverseVectorIterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(ReverseVectorIterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ConstReverseVectorIterator
	{
		private:
			T*		ptr;
		public:
			ConstReverseVectorIterator() {}
			ConstReverseVectorIterator(ConstReverseVectorIterator const &ref) {
				*this = ref;
			}
			ConstReverseVectorIterator(T* _ptr) : ptr(_ptr) {}
			~ConstReverseVectorIterator() {}
			ConstReverseVectorIterator		&operator=(ConstReverseVectorIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			ConstReverseVectorIterator	&operator++() {
				ptr = ptr + 1;
				return *this;
			}
			ConstReverseVectorIterator	&operator--() {
				ptr = ptr - 1;
				return *this;
			}
			ConstReverseVectorIterator	operator++(int) {
				ConstReverseVectorIterator	tmp(*this);
				operator++();
				return tmp;
			}
			ConstReverseVectorIterator	operator--(int) {
				ConstReverseVectorIterator	tmp(*this);
				operator--();
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(ConstReverseVectorIterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(ConstReverseVectorIterator const &ref) const {
				return !(*this == ref);
			}
	};
}

#endif