#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "../utils/others.hpp"

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
		protected:
			pointer		ptr;
		public:
			VectorIterator(): ptr(nullptr) {}
			VectorIterator(pointer newptr): ptr(newptr) {}
			VectorIterator(VectorIterator const &ref) {
				ptr = ref.ptr;
			}
			~VectorIterator() {}
			pointer getPtr(){
				return ptr;
			}
			VectorIterator	&operator=(VectorIterator const &ref) {
				ptr = ref.ptr;
				return *this;
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
			VectorIterator		operator+(int n) const {
				VectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			VectorIterator		operator-(int n) const {
				VectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			VectorIterator	&operator+=(int n) {
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
				return (*this);
			}
			VectorIterator	&operator-=(int n) {
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
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
			reference operator[](int n) const {
				return (*(*this + n));
			}
			int operator-(VectorIterator it) const
            {
                return this->ptr - it.ptr;
            }
			bool	operator==(VectorIterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(VectorIterator const &ref) const {
				return !(*this == ref);
			}
	};
	template <class T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		public:
			ConstVectorIterator() {}
			ConstVectorIterator(pointer newptr) {
				this->ptr = newptr;
			}
			ConstVectorIterator(ft::VectorIterator<T> &ref) {
				this->ptr = ref.getPtr();
			}
			ConstVectorIterator(const ConstVectorIterator &ref) {
				this->ptr = ref.ptr;
			}
			~ConstVectorIterator() {}
			ConstVectorIterator	&operator=(const ConstVectorIterator &ref) {
				this->ptr = ref.ptr;
				return *this;
			}
			const value_type &operator*() {
				return (*this->ptr);
			}
			const value_type &operator[](int n) const {
				return (*(*this + n));
			}
	};
	template <class T>
	class ReverseVectorIterator
	{
		public:
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef ptrdiff_t 						difference_type;
			typedef size_t							size_type;
		protected:
			pointer		ptr;
		public:
			ReverseVectorIterator(): ptr(nullptr) {}
			ReverseVectorIterator(pointer newptr) : ptr(newptr) {}
			ReverseVectorIterator(ReverseVectorIterator const &ref) {
				ptr = ref.ptr;
			}
			~ReverseVectorIterator() {}
			ReverseVectorIterator		&operator=(ReverseVectorIterator const &ref) {
				ptr = ref.ptr;
				return *this;
			}
			pointer getPtr(){
				return ptr;
			}
			ReverseVectorIterator	&operator++() {
				ptr--;
				return *this;
			}
			ReverseVectorIterator	&operator--() {
				ptr++;
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
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			ReverseVectorIterator		operator-(difference_type n) {
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			bool	operator<(const ReverseVectorIterator &x) const {
				return ptr < x.ptr;
			}
			bool	operator>(const ReverseVectorIterator &x) const {
				return ptr > x.ptr;
			}
			bool	operator<=(const ReverseVectorIterator &x) const {
				return ptr <= x.ptr;
			}
			bool	operator>=(const ReverseVectorIterator &x) const {
				return ptr >= x.ptr;
			}
			ReverseVectorIterator	&operator+=(difference_type n) {
				while (n > 0) {
					operator++();
					n--;
				}
				while (n < 0) {
					operator--();
					n++;
				}
				return (*this);
			}
			ReverseVectorIterator	&operator-=(difference_type n) {
				while (n > 0) {
					operator--();
					n--;
				}
				while (n < 0)  {
					operator++();
					n++;
				}
				return (*this);
			}
			ReverseVectorIterator operator+(int n) const {
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			ReverseVectorIterator operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			pointer operator->() const {
				return ptr;
			}
			reference operator*() const {
				return *ptr;
			}
			reference operator[](size_type n) const {
				return *(ptr + n);
			}
			int operator-(ReverseVectorIterator it) const
            {
                return ptr - it.ptr;
            }
			bool	operator==(ReverseVectorIterator const &ref) const {
				return ptr == ref.ptr;
			}
			bool	operator!=(ReverseVectorIterator const &ref) const {
				return !(*this == ref);
			}
	};
	template <class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		public:
			ConstReverseVectorIterator() {}
			ConstReverseVectorIterator(pointer newptr) {
				this->ptr = newptr;
			}
			ConstReverseVectorIterator(ConstReverseVectorIterator const &ref) {
				this->ptr = ref.getPtr();
			}
			ConstReverseVectorIterator(ReverseVectorIterator<T> const &ref) {
				this->ptr = ref.ptr;
			}
			~ConstReverseVectorIterator() {}
			ConstReverseVectorIterator	&operator=(ConstReverseVectorIterator const &ref) {
				this->ptr = ref.ptr;
				return *this;
			}
			const value_type &operator*() {
				return (*this->_ptr);
			}
			const value_type &operator[](int n) const {
				return (*(*this - n));
			}
	};
}

#endif