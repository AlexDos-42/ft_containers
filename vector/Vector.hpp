#ifndef VECTOR
# define VECTOR

# include <cstddef>
# include <limits>
# include <iostream>
# include <iterator>

#include "../iterators/VectorIterator.hpp"
#include "../utils/others.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T										value_type;
			typedef VectorIterator<T>							iterator;
			typedef ConstVectorIterator<T>						const_iterator;
			typedef ReverseVectorIterator<T>					reverse_iterator;
			typedef ConstReverseVectorIterator<T>				const_reverse_iterator;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference  	const_reference;
		private:
			Alloc		_allocator;
			T*			m_ptr;
			size_t		m_length;
			size_t		m_capacity;
		public:
			explicit vector(const Alloc& alloc = Alloc()):
					_allocator(alloc), m_ptr(0), m_length(0), m_capacity(0) {}
			explicit vector (size_t n, const T& val = T(), const Alloc& alloc = Alloc()):
					_allocator(alloc), m_length(n), m_capacity(n) {
				m_ptr = _allocator.allocate(n);
				for (size_t i = 0; i < n; i++)
					_allocator.construct(&m_ptr[i], val);
			}
			template <class Iterator>
			vector (iterator first, iterator last, const Alloc& alloc = Alloc()):
					_allocator(alloc), m_ptr(0), m_length(0), m_capacity(0) {
				assign(first, last);
			}	
			vector (const vector& x): m_ptr(0), m_length(0), m_capacity(0) {
				*this = x;
			}
			~vector(){
				for (size_t i = 0; i < m_length; ++i)
					_allocator.destroy(&m_ptr[i]);
				_allocator.deallocate(m_ptr, m_capacity);
			}
			vector& operator= (const vector& x){
				for (size_t i = 0; i < m_length; ++i)
					_allocator.destroy(&m_ptr[i]);
				_allocator.deallocate(m_ptr, m_capacity);
				m_ptr = _allocator.allocate(x.m_capacity());
				m_length = x.m_length();
				for (size_t i = 0; i < m_length; ++i)
					m_ptr[i] = x.m_ptr[i];
				return *this;
			}

			///////// ITERATORS /////////
			iterator begin() {
				return iterator(m_ptr);
			}
			const_iterator begin() const {
			 	return const_iterator(m_ptr);
			}
			iterator end(){
				return iterator(&m_ptr[m_length]);
			}
			const_iterator end() const{
			 	return const_iterator(&m_ptr[m_length]);
			}
			reverse_iterator rbegin(){
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const{
				return const_iterator(end());
			}
			reverse_iterator rend(){
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(begin());
			}

			///////// CAPACITY /////////
			size_t size() const{
				return m_length;
			}
			size_t max_size() const{
				return _allocator.max_size();
			}
			void resize (size_t n, T val = T()){
				if (n < m_length){
					n = m_length - n;
					for (size_t i = 0; i < n; ++i)
					{
						_allocator.destroy(m_ptr + (m_length - i));
						--m_length;
					}
				}
				else if (n > m_length)
				{
					while (n > m_capacity)
						m_realloc();
					if (m_length)
					{
						typename allocator_type::pointer	src = m_ptr + m_length;
						typename allocator_type::pointer	dst = m_ptr + m_length + n;

						for (int i = m_length - index - 1; i >= 0; --i)
							_allocator.construct(dst + i, src[i]);
					}
					for (size_t i = 0; i < n - m_length; ++i)
						_allocator.construct(m_ptr + (m_length + i), val);
					m_length += n - m_length;
				}
			}
			size_t capacity() const{
				return m_capacity;
			}
			bool empty() const{
				return (!(m_length));
			}
			void reserve (size_t n);

			///////// ELEMENTS ACCESS /////////
			reference front(){
			 	return operator[](0);
			}
			const_reference front() const{
			 	return operator[](0);
			}
			reference back(){
			 	return operator[](m_length - 1);
			}
			const_reference back() const{
			 	return operator[](m_length - 1);
			}
			reference operator[] (size_t n){
				 return *(&m_ptr[n]);
			}
			const_reference operator[] (size_t n) const{
				 return *(&m_ptr[n]);
			}
			reference at (size_t n){
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}
			const_reference at (size_t n) const{
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}

			///////// MODIFIERS /////////
			template <class iterator>
			void assign (iterator first, iterator last){
				size_t	size = ft::distance(first, last);
				if (size > m_capacity)
					m_realloc();
				clear();
				for (size_t i = 0; i < size; ++i)
					push_back(first++);
			}	
			void assign (size_t n, const T &val){
				if (n > m_capacity)
					m_realloc();
				clear();
				for (size_t i = 0; i < n; ++i)
					push_back(val);
			}
			iterator insert (iterator position, const T& val){
				size_t n = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(&m_ptr[n]));
			}
			void insert (iterator position, size_t n, const T& val){
				vector tmp(position, end());
				m_length -= ft::distance(position, end());
				while (n) {
					push_back(val);
					--n;
				}
				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}
			}
			template <class iterator>
			void insert (iterator position, iterator first, iterator last){
				vector tmp(position, end());
				m_length -= ft::distance(position, end());
				while (first != last) {
					push_back(*first);
					++first;
				}
				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}
			}
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void push_back (const T& val){
				if (m_length == m_capacity)
					m_realloc();
				_allocator.construct(&m_ptr[m_length], val);
				++m_length;
			}
			void pop_back(){
				if (m_length){
					_allocator.destroy(&m_ptr[m_length - 1]);
					m_length--;
				}
			}
			void clear(){
				size_t i = 0;
				for ( ; i < m_length; i++)
					_allocator.destroy(&m_ptr[m_length - i]);
				m_length -= i;
			}
			void swap (vector& x) {
				m_swap(m_length, x.m_length);
				m_swap(m_capacity, x.m_capacity);
				m_swap(m_ptr, x.m_ptr);
			}
			private:
				void	m_realloc(size_t n = 0){
					T*		tmp;

					if (!n)
						n = !m_capacity ? 1 : m_capacity * 2;
					tmp = _allocator.allocate(n);
					for (size_t i = 0; i < m_length; ++i)
						_allocator.construct(&tmp[i], m_ptr[i]);
					for (size_t i = m_length; i < n; ++i)
						_allocator.construct(&tmp[i], T());
					for (size_t i = 0; i < m_length; ++i)
						_allocator.destroy(&m_ptr[i]);
					_allocator.deallocate(m_ptr, m_capacity);
					m_capacity = n;
					m_ptr = tmp;
				}
	};
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typename ft::vector<T>::const_iterator		lhs_it = lhs.begin();
		typename ft::vector<T>::const_iterator		rhs_it = rhs.begin();
		while (lhs_it != lhs.end())
			if (*lhs_it++ != *rhs_it++)
				return 0;
		if (rhs_it != rhs.end())
			return 0;
		return 1;
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typename ft::vector<T>::const_iterator	lhs_begin = lhs.begin();
		typename ft::vector<T>::const_iterator	lhs_end = lhs.end();
		typename ft::vector<T>::const_iterator	rhs_begin = rhs.begin();
		typename ft::vector<T>::const_iterator	rhs_end = rhs.end();

		while (lhs_begin != lhs_end)
		{
			if (rhs_begin == rhs_end || *rhs_begin < *lhs_begin)
				return false;
			else if (*lhs_begin < *rhs_begin)
				return true;
			++lhs_begin;
			++rhs_begin;
		}
		return (rhs_begin != rhs_end);
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		  x.swap(y);
	  }
}

#endif
