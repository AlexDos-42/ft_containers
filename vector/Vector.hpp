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
#include "../utils/Pairs.hpp"

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
				std::cout << "Ici 0 " << std::endl;
				m_ptr = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&m_ptr[i], val);
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0):
					_allocator(alloc), m_length(0) {
				std::cout << "Ici 1 " << std::endl;
				InputIterator tmp(first);
                while (tmp++ != last)
                    m_length++;
                m_capacity = m_length;
                m_ptr = _allocator.allocate(m_capacity);
                for (int i = 0; first != last; ++first, ++i)
                    _allocator.construct(&m_ptr[i], *first);
			}	
			vector (const vector& x): m_ptr(x.m_ptr), m_length(x.m_length), m_capacity(x.m_capacity) {
				m_ptr = _allocator.allocate(m_capacity);
                for (ft::pair<int, const_iterator> i(0, x.begin());
                        i.second != x.end(); ++i.first, ++i.second)
                _allocator.construct(&m_ptr[i.first], *i.second);
			}
			~vector(){
				for (size_type i = 0; i < m_length; ++i)
					_allocator.destroy(&m_ptr[i]);
				//_allocator.deallocate(m_ptr, m_capacity);
			}
			vector& operator= (const vector& x){
				vector tmp(x);
                swap(tmp);
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
			void assign (InputIterator first, InputIterator last,
				typename enable_if<!is_integral<InputIterator>::value>::type * = 0){
				clear();
				size_type n = static_cast<size_type>(last - first);
                if (n > m_capacity){
                    _allocator.deallocate(m_ptr, m_capacity);
                    m_ptr = _allocator.allocate(n);
                }
                size_type i = 0;
                for (; first != last; ++i, ++first)
                    _allocator.construct(&m_ptr[i], *first);
                m_length = i;
			}	
			void assign (size_type n, const value_type &val){
				clear();
				if (n > m_capacity){
                    _allocator.deallocate(m_ptr, m_capacity);
                    m_ptr = _allocator.allocate(n);
                }
                for (size_type i = 0; i < n; ++i)
                    _allocator.construct(&m_ptr[i], val);
                m_length = n;
			}
			void push_back (const value_type& val)
            {
				std::cout << "push_back 1 " << m_length << " : "  << m_capacity<< std::endl;
                if (m_length + 1 > m_capacity)
                    m_realloc(!m_capacity ? 1 : m_capacity * 2);
				//std::cout << "push_back 2 " << std::endl;
                _allocator.construct(&m_ptr[m_length++], val);
				//std::cout << "push_back 3 " << std::endl;
				++m_length;
            }
			void pop_back(){
				if (m_length){
					_allocator.destroy(&m_ptr[m_length - 1]);
					m_length--;
				}
			}
			iterator insert (iterator position, const value_type& val){
				std::cout << "test 1 " << std::endl;
				size_type n = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(&m_ptr[n]));
			}
			void insert (iterator position, size_type n, const value_type& val){
				std::cout << "test 2 " << std::endl;
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
			void insert (iterator position, InputIterator first, InputIterator last,
				typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0){
				std::cout << "test 3 " << std::endl;
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
			iterator erase (iterator position){
				return erase(position, position + 1);
			}
			iterator erase (iterator first, iterator last){
                if (first == end() || first == last)
                    return first;
                long int index = first - begin();
                if (last < end()) {
					for (; first != end(); ++first, ++last){
						_allocator.destroy(&(*first));
						if (last < end())
							_allocator.construct(&(*(first)), *last);
					}
                    m_length -= static_cast<size_type>(last - first);
                }
                else
                {
                    size_type newSize = m_length - static_cast<size_type>(last - first);
                    while (m_length != newSize)
                        pop_back();
                }
                return iterator(&m_ptr[index]);
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
			void	m_realloc(size_type newCapacity){
				value_type* tmp = _allocator.allocate(newCapacity);
				for (size_type i = 0; i < m_length; i++){
					_allocator.construct(&tmp[i], m_ptr[i]);
				}
				this->~vector();
				m_capacity = newCapacity;
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
		lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
