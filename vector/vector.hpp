#pragma once

# include <cstddef>
# include <limits>
# include <iostream>
# include <iterator>
# include <memory>
# include <string>
# include <sstream>

#include "../iterators/VectorIterator.hpp"
#include "../utils/others.hpp"
#include "../utils/pair.hpp"

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

			typedef ft::VectorIterator<pointer>					iterator;
			typedef ft::VectorIterator<const_pointer>			const_iterator;
			typedef ft::ReverseVectorIterator<iterator>			reverse_iterator;
			typedef ft::ReverseVectorIterator<const_iterator>	const_reverse_iterator;
			typedef	size_t										size_type;
		private:
			Alloc			_allocator;
			value_type*		m_ptr;
			size_type		m_length;
			size_type		m_capacity;

		public:
			/* Constructor default */
			explicit vector(const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_length(0), m_capacity(0) {
				m_ptr = NULL;
			}
			/* Constructor fill */
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_length(n), m_capacity(n) {
				m_ptr = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&m_ptr[i], val);
			}
			/* Constructor range */
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0):
					_allocator(alloc), m_length(0) {
				InputIterator tmp(first);
				while (tmp++ != last)
					m_length++;
				m_capacity = m_length;
				m_ptr = _allocator.allocate(m_capacity);
				for (int i = 0; first != last; ++first, ++i)
					_allocator.construct(&m_ptr[i], *first);
			}
			/* Constructor copy */
			vector(const vector& copy): m_ptr(copy.m_ptr), m_length(copy.m_length), m_capacity(copy.m_capacity) {
				if (this == &copy)
					return;
				m_ptr = _allocator.allocate(m_capacity);
				for (ft::pair<int, const_iterator> i(0, copy.begin()); i.second != copy.end(); ++i.first, ++i.second)
					_allocator.construct(&m_ptr[i.first], *i.second);
			}
			/* Vector destructor */
			~vector(){
				for (size_type i = m_length; i < m_length; --i){
					_allocator.destroy(&m_ptr[i]);
				}
				_allocator.deallocate(m_ptr, m_capacity);
			}
			/* Assign content */
			vector &operator=(const vector& x){
				if (this == &x)
					return *this;
				vector tmp(x);
				if (this->capacity() > tmp.capacity())
					tmp.reserve(this->capacity());
				else
					tmp.justReserve(tmp.size());
				swap(tmp);
				return *this;
			}

			///////// ITERATORS /////////
			
			/* Returns an iterator pointing to the first element in the vector. */
			iterator begin() {
				return iterator(m_ptr);
			}
			/* Returns an iterator pointing to the first element in the vector. */
			const_iterator begin() const {
				return const_iterator(m_ptr);
			}
			/* Return iterator to end */
			iterator end(){
				return iterator(m_ptr + m_length);
			}
			/* Return iterator to end */
			const_iterator end() const{
				return const_iterator(m_ptr + m_length);
			}
			/* Return reverse iterator to reverse beginning */
			reverse_iterator rbegin(){
				return reverse_iterator(end());
			}
			/* Return reverse iterator to reverse beginning */
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(end());
			}
			/* Return reverse iterator to reverse end */
			reverse_iterator rend(){
				return reverse_iterator(begin());
			}
			/* Return reverse iterator to reverse end */
			const_reverse_iterator rend() const{
				return const_reverse_iterator(begin());
			}

			///////// CAPACITY /////////

			/* Return size */
			size_type size() const {
				return m_length;
			}
			/* Return maximum size */
			size_type max_size() const {
				return _allocator.max_size();
			}
			/* Change size */
			void resize(size_type n, value_type val = value_type()) {
				if (n < m_length){
					for (; n < m_length;)
						pop_back();
				}
				else if (n > m_length)
				{
					for (size_t i = m_length; i < n; i++)
						push_back(val);
				}
			}
			/* Return size of allocated storage capacity */
			size_type capacity() const {
				return m_capacity;
			}
			/* Test whether vector is empty */
			bool empty() const{
				return (!(m_length));
			}
			/* Request a change in capacity */
			void reserve(size_type n){
				value_type	*tmp;
				if (n == 0)
					return ;
				if (n > max_size()){
					std::ostringstream oss;
					std::ostringstream oss2;
					oss << n;
					oss2 << max_size();
					throw (std::length_error("new capacity (which is " + oss.str() \
					 + ") > max_size() (which is " + oss2.str() + ")"));
				}
				else if (n > m_capacity) {
					tmp = _allocator.allocate(n);
					if (m_capacity > 0) {
						for (size_t i = 0; i < m_length; i++){
							_allocator.construct(&tmp[i], m_ptr[i]);
							_allocator.destroy(m_ptr + i);
						}
						_allocator.deallocate(m_ptr, m_capacity);
					}
					m_capacity = n;
					m_ptr = tmp;
				}
			}

			///////// ELEMENTS ACCESS /////////

			/* Access first element */
			reference front(){
				return operator[](0);
			}
			/* Access first element */
			const_reference front() const{
				return operator[](0);
			}
			/* Access last element */
			reference back(){
				return operator[](m_length - 1);
			}
			/* Access last element */
			const_reference back() const{
				return operator[](m_length - 1);
			}
			/* Access element */
			reference operator[](size_type n){
				return *(&m_ptr[n]);
			}
			/* Access element */
			const_reference operator[](size_type n) const{
				return *(&m_ptr[n]);
			}
			/* Access element */
			reference at(size_type n){
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}
			/* Access element */
			const_reference at(size_type n) const{
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}

			///////// MODIFIERS /////////

			/* Assign vector content range */
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename enable_if<!is_integral<InputIterator>::value>::type * = 0){
				size_t i = 0;
				for (InputIterator it = first; it != last; ++it)
					i++;
				reserve(i);
				while (first != last) {
					push_back(*first);
					first++;
				}
			}
			/* Assign vector content fill */
			void assign(size_type n, const value_type &val){
				reserve(n);
				size_type i = -1;
				while (++i < n) {
					push_back(val);
				}
			}
			/* Add element at the end */
			void push_back(const value_type& val) {
				if (!m_capacity)
					reserve(1);
				else if (m_length >= m_capacity){
					reserve(m_capacity * 2);
				}
				_allocator.construct(&m_ptr[m_length++], val);
			}
			/* Delete last element */
			void pop_back(){
				if (m_length){
					_allocator.destroy(&m_ptr[m_length - 1]);
					m_length--;
				}
			}
			/* Insert elements single element */
			iterator insert(iterator position, const value_type& val){
				size_type n = ft::distance(begin(), position);
				vector tmp(position, end());
				size_t a = size() + 1;
				m_length -= ft::distance(position, end());
				for (iterator supp = position; supp != end() ; supp++)
					erase(supp);
				if (capacity() == a)
					reserve(a * 2);
				push_back(val);
				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}
				return (iterator(&m_ptr[n]));
			}
			/* Insert elements fill */
			void insert(iterator position, size_type n, const value_type& val){
				vector tmp(position, end());
				int a = size() + n;
				m_length -= ft::distance(position, end());
				for (iterator supp = position; supp != end() ; supp++)
					erase(supp);
				reserve(a);
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
			/* Insert elements range */
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0){
				vector tmp(position, end());
				InputIterator tmpIterator = first;
				size_t n = size();
				while (tmpIterator != last) {
					n++;
					++tmpIterator;
				}
				if (!(n > 2 * capacity() || !size()))
					n = 0;
				m_length -= ft::distance(position, end());
				for (iterator supp = position; supp != end() ; supp++)
					erase(supp);
				if (n)
					reserve(n);
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
			/* Erase element */
			iterator erase(iterator position){
				return erase(position, position + 1);
			}
			/* Erase elements */
			iterator erase(iterator first, iterator last){
				if (first == end() || first == last)
					return first;
				long int index = first - begin();
				if (last < end()) {
					for (; first != end(); ++first, ++last){
						_allocator.destroy(&(*first));
						if (last < end())
							_allocator.construct(&(*(first)), *last);
					}
					m_length -= ft::distance(first, last);
				}
				else {
					size_type newSize = m_length - ft::distance(first, last);
					while (m_length != newSize)
						pop_back();
				}
				return iterator(&m_ptr[index]);
			}
			/* Clear content */
			void clear(){
				size_type i = 0;
				for ( ; i < m_length; i++)
					_allocator.destroy(&m_ptr[m_length - i]);
					
				m_length -= i;
			}
			/* Swap content */
			void swap(vector& x) {
				m_swap(m_length, x.m_length);
				m_swap(m_capacity, x.m_capacity);
				m_swap(m_ptr, x.m_ptr);
			}
			
			///////// ALLOCATOR /////////

			/* Returns a copy of the allocator  */
			allocator_type get_allocator() const {
				return allocator_type();
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
			void justReserve(size_type n){
				value_type	*tmp;
				if (n == 0)
					return ;
				if (n > max_size()) {
					std::ostringstream oss;
					std::ostringstream oss2;
					oss << n;
					oss2 << max_size();
					throw (std::length_error("new capacity (which is " + oss.str() \
					 + ") > max_size() (which is " + oss2.str() + ")"));
				}
				else if (n > m_capacity) {
					tmp = _allocator.allocate(n);
					if (m_capacity > 0) {
						for (size_t i = 0; i < m_length; i++){
							_allocator.construct(&tmp[i], m_ptr[i]);
							_allocator.destroy(m_ptr + i);
						}
						_allocator.deallocate(m_ptr, m_capacity);
					}
					m_capacity = n;
					m_ptr = tmp;
				}
				else if (n < m_capacity) {
					tmp = _allocator.allocate(n);
					if (m_capacity > 0) {
						for (size_t i = 0; i < m_length; i++){
							_allocator.construct(&tmp[i], m_ptr[i]);
							_allocator.destroy(m_ptr + i);
						}
						_allocator.deallocate(m_ptr, m_capacity);
					}
					m_capacity = n;
					m_ptr = tmp;
				}
			}
	};

	///////// Relational operators for vector /////////
	
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (rhs < lhs || rhs > lhs)
			return false;
		return true;
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}
}
