#ifndef BIDIRECTIONALITERATOR
# define BIDIRECTIONALITERATOR

namespace ft
{
	template <typename T>
	class BidirectIterator
	{
		private:
			Node<T>		*ptr;
		public:
			BidirectIterator() {}
			BidirectIterator(BidirectIterator const &ref) {
				*this = ref;
			}
			BidirectIterator(Node<T> *_ptr) : ptr(_ptr) {}
			~BidirectIterator() {}
			BidirectIterator			&operator=(BidirectIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			BidirectIterator	&operator++() {
				ptr = ptr->m_next;
				return *this;
			}
			BidirectIterator	&operator--() {
				ptr = ptr->m_back;
				return *this;
			}
			BidirectIterator	operator++(int) {
				BidirectIterator	tmp(*this);
				++(*this);
				return tmp;
			}
			BidirectIterator	operator--(int) {
				BidirectIterator	tmp(*this);
				--(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(BidirectIterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(BidirectIterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ConstBidirectIterator
	{
		private:
			Node<T>		*ptr;
		public:
			ConstBidirectIterator() {}
			ConstBidirectIterator(ConstBidirectIterator const &ref) {
				*this = ref;
			}
			ConstBidirectIterator(Node<T> *_ptr) : ptr(_ptr) {}
			~ConstBidirectIterator() {}
			ConstBidirectIterator	&operator=(ConstBidirectIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			ConstBidirectIterator	&operator++() {
				ptr = ptr->m_next;
				return *this;
			}
			ConstBidirectIterator	&operator--() {
				ptr = ptr->m_back;
				return *this;
			}
			ConstBidirectIterator	operator++(int) {
				ConstBidirectIterator	tmp(*this);
				++(*this);
				return tmp;
			}
			ConstBidirectIterator	operator--(int) {
				ConstBidirectIterator	tmp(*this);
				--(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(ConstBidirectIterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(ConstBidirectIterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ReverseBidirectIterator
	{
		private:
			Node<T>		*ptr;
		public:
			ReverseBidirectIterator() {}
			ReverseBidirectIterator(ReverseBidirectIterator const &ref) {
				*this = ref;
			}
			ReverseBidirectIterator(Node<T> *_ptr) : ptr(_ptr) {}
			~ReverseBidirectIterator() {}
			ReverseBidirectIterator	&operator=(ReverseBidirectIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			ReverseBidirectIterator	&operator++() {
				ptr = ptr->m_back;
				return *this;
			}
			ReverseBidirectIterator	&operator--() {
				ptr = ptr->m_next;
				return *this;
			}
			ReverseBidirectIterator	operator++(int) {
				ReverseBidirectIterator	tmp(*this);
				--(*this);
				return tmp;
			}
			ReverseBidirectIterator	operator--(int) {
				ReverseBidirectIterator	tmp(*this);
				++(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(ReverseBidirectIterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(ReverseBidirectIterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ConstReverseBidirectIterator
	{
		private:
			Node<T>		*ptr;
		public:
			ConstReverseBidirectIterator() {}
			ConstReverseBidirectIterator(ConstReverseBidirectIterator const &ref) {
				*this = ref;
			}
			ConstReverseBidirectIterator(Node<T> *_ptr) : ptr(_ptr) {}
			~ConstReverseBidirectIterator() {}
			ConstReverseBidirectIterator	&operator=(ConstReverseBidirectIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			ConstReverseBidirectIterator	&operator++() {
				ptr = ptr->m_back;
				return *this;
			}
			ConstReverseBidirectIterator	&operator--() {
				ptr = ptr->m_next;
				return *this;
			}
			ConstReverseBidirectIterator	operator++(int) {
				ConstReverseBidirectIterator	tmp(*this);
				--(*this);
				return tmp;
			}
			ConstReverseBidirectIterator	operator--(int) {
				ConstReverseBidirectIterator	tmp(*this);
				++(*this);
				return tmp;
			}
			T* operator->() const {
				return ptr->m_value;
			}
			T operator*() const {
				return ptr->m_value;
			}
			
			bool	operator==(ConstReverseBidirectIterator const &ref) const {
				return ptr->m_value == ref.ptr->m_value;
			}
			bool	operator!=(ConstReverseBidirectIterator const &ref) const {
				return !(*this == ref);
			}
	};
};

#endif