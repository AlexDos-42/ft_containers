#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <limits>
# include <iostream>
# include <iterator>
# include <memory>
# include <string>

#include "../iterators/VectorIterator.hpp"
#include "../utils/others.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef RandomAccessIterator<value_type>					iterator;
			typedef RandomAccessIterator<const value_type>			const_iterator;
			typedef ReverseRandomAccess<value_type>			reverse_iterator;
			typedef ReverseRandomAccess<const value_type>		const_reverse_iterator;
			typedef	size_t										size_type;
		private:
			Alloc			_allocator;
			value_type*		m_ptr;
			size_type		m_length;
			size_type		m_capacity;
		public:
			explicit vector(const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_ptr(0), m_length(0), m_capacity(0) {}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_length(n), m_capacity(n) {
				m_ptr = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&m_ptr[i], val);
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_ptr(0), m_length(0), m_capacity(0) {
				assign(first, last);
			}	
			vector (const vector& x): m_ptr(0), m_length(0), m_capacity(0) {
				*this = x;
			}
			~vector(){
				for (size_type i = 0; i < m_length; ++i)
					_allocator.destroy(&m_ptr[i]);
				_allocator.deallocate(m_ptr, m_capacity);
			}
			vector& operator= (const vector& x){
				for (size_type i = 0; i < m_length; ++i)
					_allocator.destroy(&m_ptr[i]);
				_allocator.deallocate(m_ptr, m_capacity);
				m_ptr = _allocator.allocate(x.m_capacity);
				m_length = x.m_length;
				for (size_type i = 0; i < m_length; ++i)
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
				return iterator(m_ptr + m_length);
			}
			const_iterator end() const{
				return const_iterator(m_ptr + m_length);
			}
			reverse_iterator rbegin(){
				return reverse_iterator(m_ptr + m_length - 1);
			}
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(m_ptr + m_length - 1);
			}
			reverse_iterator rend(){
				return reverse_iterator(m_ptr - 1);
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(m_ptr - 1);
			}

			///////// CAPACITY /////////
			size_type size() const{
				return m_length;
			}
			size_type max_size() const{
				return _allocator.max_size();
			}
			void resize (size_type n, value_type val = value_type()){
				if (n < m_length)
					m_length = n;
				else if (n > m_length)
				{
					reserve(n);
					for (size_t i = m_length; i < n; i++)
						push_back(val);
				}
			}
			size_type capacity() const{
				return m_capacity;
			}
			bool empty() const{
				return (!(m_length));
			}
			void reserve (size_type n){
				value_type	*tmp;
				if (n == 0)
					return ;
				if (n > max_size())
					throw (std::length_error("new capacity (which is " + std::to_string(n) \
					+ ") > max_size() (which is " + std::to_string(max_size()) + ")"));
				if (n > m_capacity)
				{
					tmp = _allocator.allocate(n);
					if (m_capacity > 0)
					{
						for (size_t i = 0; i < m_length; i++)
							_allocator.construct(&tmp[i], m_ptr[i]);
						_allocator.deallocate(m_ptr, m_capacity);
					}
					m_capacity = n;
					m_ptr = tmp;
				}
			}

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
			reference operator[] (size_type n){
				return *(&m_ptr[n]);
			}
			const_reference operator[] (size_type n) const{
				return *(&m_ptr[n]);
			}
			reference at (size_type n){
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}
			const_reference at (size_type n) const{
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}

			///////// MODIFIERS /////////
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last){
				size_type	size = ft::distance(first, last);
				if (size > m_capacity)
					m_realloc();
				clear();
				size_type i = 0;
				for (; first != last; ++i, ++first)
					_allocator.construct(&m_ptr[i], *first);
				m_length = i;
			}	
			void assign (size_type n, const value_type &val){
				if (n > m_capacity)
					m_realloc();
				clear();
				for (size_type i = 0; i < n; ++i)
					push_back(val);
			}
			iterator insert (iterator position, const value_type& val){
				size_type n = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(&m_ptr[n]));
			}
			void insert (iterator position, size_type n, const value_type& val){
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
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last){
				vector tmp(position, end());
				m_length -= ft::distance(position, end());
				while (first != last) {
				//	push_back(*first);
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
			void push_back (const value_type& val){
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
				size_type i = 0;
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
				void	m_realloc(size_type n = 0){
					value_type*		tmp;

					if (!n)
						n = !m_capacity ? 1 : m_capacity * 2;
					tmp = _allocator.allocate(n);
					for (size_type i = 0; i < m_length; ++i)
						_allocator.construct(&tmp[i], m_ptr[i]);
					for (size_type i = m_length; i < n; ++i)
						_allocator.construct(&tmp[i], T());
					for (size_type i = 0; i < m_length; ++i)
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
