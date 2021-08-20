#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "../utils/others.hpp"

namespace ft
{
	template <typename T>
	class RandomAccessIterator
	{
		public:
			typedef RandomAccessIterator			iterator;
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef ptrdiff_t 						difference_type;
			typedef size_t							size_type;
		private:
			pointer		ptr;
		public:
			RandomAccessIterator(): ptr(nullptr) {}
			RandomAccessIterator(pointer newptr): ptr(newptr) {}
			RandomAccessIterator(iterator const &ref) {
				ptr = ref.ptr;
			}
			~RandomAccessIterator() {}
			iterator	&operator=(iterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			iterator	&operator++() {
				ptr = ptr + 1;
				return *this;
			}
			iterator	&operator--() {
				ptr = ptr - 1;
				return *this;
			}
			iterator	operator++(int) {
				iterator	tmp(*this);
				ptr++;
				return tmp;
			}
			iterator	operator--(int) {
				iterator	tmp(*this);
				ptr--;
				return tmp;
			}
			iterator		operator+(difference_type n) {
				iterator tmp(*this);
				tmp.ptr += n;
				return (tmp);
			};
			difference_type	operator+(iterator x) {
				return (ptr + x.ptr);
			}
			iterator		operator-(difference_type n) {
				iterator tmp(*this);
				tmp.ptr -= n;
				return (tmp);
			};
			difference_type	operator-(iterator x) {
				return (ptr - x._ptr);
			}
			iterator	&operator+=(difference_type n) {
				ptr += n;
				return (*this);
			}
			iterator	&operator-=(difference_type n) {
				ptr -= n;
				return (*this);
			};
			bool	operator<(const iterator &x) const {
				return ptr < x.ptr;
			};
			bool	operator>(const iterator &x) const {
				return ptr > x.ptr;
			};
			bool	operator<=(const iterator &x) const {
				return ptr <= x.ptr;
			};
			bool	operator>=(const iterator &x) const {
				return ptr >= x.ptr;
			};
			pointer operator->() const {
				return &(operator*());
			}
			reference operator*() const {
				return *ptr;
			}
			reference operator[](size_type n) const {
				return *(ptr + n);
			}
			
			bool	operator==(iterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(iterator const &ref) const {
				return !(*this == ref);
			}
	};

	template <typename T>
	class ReverseRandomAccess
	{
		public:
			typedef ReverseRandomAccess 			iterator;
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef ptrdiff_t 						difference_type;
			typedef size_t							size_type;
		private:
			pointer		ptr;
		public:
			ReverseRandomAccess(): ptr(nullptr) {}
			ReverseRandomAccess(pointer newptr) : ptr(newptr) {}
			ReverseRandomAccess(iterator const &ref) {
				ptr = ref.ptr;
			}
			~ReverseRandomAccess() {}
			iterator		&operator=(iterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
		
			iterator	&operator++() {
				ptr = ptr - 1;
				return *this;
			}
			iterator	&operator--() {
				ptr = ptr + 1;
				return *this;
			}
			iterator	operator++(int) {
				iterator	tmp(*this);
				ptr--;
				return tmp;
			}
			iterator	operator--(int) {
				iterator	tmp(*this);
				ptr++;
				return tmp;
			}
			iterator		operator+(difference_type x) {
				iterator tmp(*this);
				tmp.ptr -= x;
				return (tmp);
			};
			difference_type	operator+(iterator x) {
				return (ptr - x.ptr);
			}
			iterator		operator-(difference_type x) {
				iterator tmp(*this);
				tmp.ptr += x;
				return tmp;
			};
			difference_type	operator-(iterator x) {
				return ptr + x.ptr;
			}
			bool	operator<(const iterator &x) const {
				return ptr < x.ptr;
			};
			bool	operator>(const iterator &x) const {
				return ptr > x.ptr;
			};
			bool	operator<=(const iterator &x) const {
				return ptr <= x.ptr;
			};
			bool	operator>=(const iterator &x) const {
				return ptr >= x.ptr;
			};
			iterator	&operator+=(difference_type x) {
				ptr -= x;
				return *this;
			}
			iterator	&operator-=(difference_type x) {
				ptr += x;
				return *this;
			};
			pointer operator->() const {
				return &(operator*());
			}
			reference operator*() const {
				return *ptr;
			}
			reference operator[](size_type n) const {
				return *(ptr + n);
			}
			
			bool	operator==(iterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(iterator const &ref) const {
				return !(*this == ref);
			}
	};
}

#endif