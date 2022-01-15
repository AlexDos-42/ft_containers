#pragma once

#include "../utils/others.hpp"

namespace ft
{
	template <class Pointer>
	class VectorIterator
	{
		public:
			typedef Pointer															class_type;
			typedef typename iterator_traits<class_type>::iterator_category		iterator_category;
			typedef typename iterator_traits<class_type>::value_type        	value_type;
			typedef typename iterator_traits<class_type>::difference_type   	difference_type;
			typedef typename iterator_traits<class_type>::pointer           	pointer;
			typedef typename iterator_traits<class_type>::reference         	reference;
		protected:
			class_type		ptr;
		public:
			explicit VectorIterator(): ptr(NULL) {}
			explicit VectorIterator(class_type newptr): ptr(newptr) {}
			template<class Iter>
			VectorIterator(VectorIterator<Iter> const &ref) {
				*this = ref;
			}
			~VectorIterator() {}
			
			template <class Iter>
			VectorIterator	&operator=(VectorIterator<Iter> const &ref) {
				ptr = ref.base();
				return *this;
			}
			pointer base() const{
				return ptr;
			}
			VectorIterator	&operator++() {
				ptr++;
				return *this;
			}
			VectorIterator	&operator--() {
				ptr--;
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
			VectorIterator		operator+(difference_type n) const {
				return VectorIterator(ptr + n);
			}
			VectorIterator		operator-(difference_type n) const {
				return VectorIterator(ptr - n);
			}
			friend VectorIterator operator+(difference_type n, const VectorIterator& ref) {
				return (ref.operator+(n));
			}
			friend VectorIterator operator-(difference_type n, const VectorIterator& ref) {
				return (ref.operator-(n));
			}
			pointer	&operator+=(int n) {
				ptr += n;
				return ptr;
			}
			pointer	&operator-=(int n) {
				ptr -= n;
				return ptr;
			}
			bool	operator<(const VectorIterator &x) const {
				return ptr < x.ptr;
			}
			bool	operator>(const VectorIterator &x) const {
				return ptr > x.ptr;
			}
			bool	operator<=(const VectorIterator &x) const {
				return ptr <= x.ptr;
			}
			bool	operator>=(const VectorIterator &x) const {
				return ptr >= x.ptr;
			}
			pointer operator->() const {
				return ptr;
			}
			reference operator*() const {
				return *ptr;
			}
			reference operator[](difference_type n) const {
				return *(ptr + n);
			}
			difference_type operator+(const VectorIterator &it) const {
                return this->ptr + it.ptr;
            }
			difference_type operator-(const VectorIterator &it) const {
                return this->ptr - it.ptr;
            }
			bool	operator==(VectorIterator const &ref) const {
				return ptr == ref.base();
			}
			bool	operator!=(VectorIterator const &ref) const {
				return ptr != ref.base();
			}
	};
	template <class T, class U>
	ptrdiff_t operator-(const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return lhs.base() - rhs.base();
	}
	template <class T, class U>
	ptrdiff_t operator+(const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return lhs.base() + rhs.base();
	}
	template <class T, class U>
	VectorIterator<U> operator+(T lhs, const VectorIterator<U> &rhs) {
		return rhs + lhs;
	}
	template <class T, class U>
	bool operator== (const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class T, class U>
	bool operator!= (const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return !(lhs == rhs);
	}
	template <class T, class U>
	bool operator< (const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return (lhs.base() < rhs.base());
	}
	template <class T, class U>
	bool operator<= (const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return lhs.base() <= rhs.base();
	}
	template <class T, class U>
	bool operator> (const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return (lhs.base() > rhs.base());
	}
	template <class T, class U>
	bool operator>= (const VectorIterator<T> &lhs,const VectorIterator<U> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	class ReverseVectorIterator
	{
		public:
			typedef Iterator		class_type;
			typedef typename iterator_traits<class_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<class_type>::value_type        	value_type;
			typedef typename iterator_traits<class_type>::difference_type   	difference_type;
			typedef typename iterator_traits<class_type>::pointer           	pointer;
			typedef typename iterator_traits<class_type>::reference         	reference;

		protected:
			class_type		ptr;
		public:
			explicit ReverseVectorIterator(): ptr(NULL) {}
			ReverseVectorIterator(typename Iterator::value_type *newptr) { 
				ptr = Iterator(newptr);
			}
			ReverseVectorIterator(const Iterator &i) {
				ptr = i;
				--ptr;
			}
			template<class Iter2>
			ReverseVectorIterator(ReverseVectorIterator<Iter2> const &ref) {
				*this = ref;
			}
			~ReverseVectorIterator() {}
			
			template <class Iter2>
			ReverseVectorIterator	&operator=(const ReverseVectorIterator<Iter2> &ref) {
				ptr = ref.getPtr();
				return *this;
			}
			class_type base() const{
				return ++Iterator(ptr);
			}
			class_type getPtr() const {
				return ptr;
			}
			ReverseVectorIterator	&operator++() {
				--ptr;
				return *this;
			}
			ReverseVectorIterator	&operator--() {
				++ptr;
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
			ReverseVectorIterator		operator+(difference_type n) {
				return ptr - n + 1;
			}
			ReverseVectorIterator		operator-(difference_type n) {
				return ptr + n + 1;
			}
			bool	operator<(const ReverseVectorIterator &x) const {
				return ptr > x.ptr;
			}
			bool	operator>(const ReverseVectorIterator &x) const {
				return ptr < x.ptr;
			}
			bool	operator<=(const ReverseVectorIterator &x) const {
				return ptr >= x.ptr;
			}
			bool	operator>=(const ReverseVectorIterator &x) const {
				return ptr <= x.ptr;
			}
			ReverseVectorIterator	&operator+=(difference_type n) {
				ptr -= n;
				return *this;
			}
			ReverseVectorIterator	&operator-=(difference_type n) {
				ptr += n;
				return *this;
			}
			difference_type operator+(const ReverseVectorIterator &n) {
				return ptr - n.ptr;
			}
            difference_type operator-(const ReverseVectorIterator &n){
		    	return ptr + n.ptr;
            }
			pointer operator->() const {
				return &(*ptr.operator->());;
			}
			reference operator*() const {
				return *ptr;
			}
			reference operator[](const difference_type n) {
				return *(ptr - n);
			}
	};
	template <class T, class U>
	typename ReverseVectorIterator<T>::difference_type
	operator-(ReverseVectorIterator<T> lhs, const ReverseVectorIterator<U> &rhs) {
		return rhs.base() - lhs.base();
	}
	template <class T>
	ReverseVectorIterator<T> operator+(typename ReverseVectorIterator<T>::difference_type n, const ReverseVectorIterator<T> &rhs) {
		return ReverseVectorIterator<T>(rhs.base() - n);
	}
	template <class T>
	bool operator==(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<T> &rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class T, class U>
	bool operator==(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<U> &rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class T>
	bool operator!=(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<T> &rhs) {
		return (lhs.base() != rhs.base());
	}
	template <class T, class U>
	bool operator!=(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<U> &rhs) {
		return (lhs.base() != rhs.base());
	}
	template <class T, class U>
	bool operator<(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<U> &rhs) {
		return (lhs.base() > rhs.base());
	}
	template <class T, class U>
	bool operator<=(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<U> &rhs) {
		return lhs.base() >= rhs.base();
	}
	template <class T, class U>
	bool operator>(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<U> &rhs) {
		return (lhs.base() < rhs.base());
	}
	template <class T, class U>
	bool operator>=(const ReverseVectorIterator<T> &lhs,const ReverseVectorIterator<U> &rhs) {
		return (lhs.base() <= rhs.base());
	}

};