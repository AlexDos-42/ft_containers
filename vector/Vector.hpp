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
			/* Constructor */
			explicit vector(const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_length(0), m_capacity(0) {
				m_ptr = _allocator.allocate(0);
			}
			/* Constructor: Need a size and a value */
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
					_allocator(alloc), m_length(n), m_capacity(n) {
				m_ptr = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(&m_ptr[i], val);
			}
			/* Constructor: Need two iterators */
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
			/* Constructor par copy: Need a vector */
			vector(const vector& copy): m_ptr(copy.m_ptr), m_length(copy.m_length), m_capacity(copy.m_capacity) {
				m_ptr = _allocator.allocate(m_capacity);
				for (ft::pair<int, const_iterator> i(0, copy.begin());
					i.second != copy.end(); ++i.first, ++i.second)
				_allocator.construct(&m_ptr[i.first], *i.second);
			}
			/* Destructor */
			~vector(){
				for (size_type i = 0; i < m_length; ++i)
					_allocator.destroy(&m_ptr[i]);
			}
			/* Operator= : Need a vector */
			vector &operator=(const vector& x){
				vector tmp(x);
				swap(tmp);
				return *this;
			}

			///////// ITERATORS /////////
			
			/* begin() : Return iterator to the first element of the vector */
			iterator begin() {
				return iterator(m_ptr);
			}
			/* begin() : Return const_iterator to the first element of the vector */
			const_iterator begin() const {
				return const_iterator(m_ptr);
			}
			/* end() : Return iterator to the last element of the vector */
			iterator end(){
				return iterator(m_ptr + m_length);
			}
			/* end() : Return const_iterator to the last element of the vector */
			const_iterator end() const{
				return const_iterator(m_ptr + m_length);
			}
			/* rbegin() : Return reverse_iterator to the last element of the vector */
			reverse_iterator rbegin(){
				return reverse_iterator(end());
			}
			/* rbegin() : Return const_reverse_iterator to the last element of the vector */
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(end());
			}
			/* rend() : Return reverse_iterator to the fisrt element of the vector */
			reverse_iterator rend(){
				return reverse_iterator(begin());
			}
			/* rend() : Return const_reverse_iterator to the fisrt element of the vector */
			const_reverse_iterator rend() const{
				return const_reverse_iterator(begin());
			}

			///////// CAPACITY /////////

			/* size() : Return the number of elements */
			size_type size() const {
				return m_length;
			}
			/* max_size() : Return the maxmimum of elements */
			size_type max_size() const {
				return _allocator.max_size();
			}
			void resize(size_type n, value_type val = value_type()) {
				if (n < m_length)
					m_length = n;
				else if (n > m_length)
				{
					reserve(n);
					for (size_t i = m_length; i < n; i++)
						push_back(val);
				}
			}
			size_type capacity() const {
				return m_capacity;
			}
			bool empty() const{
				return (!(m_length));
			}
			void reserve(size_type n){
				value_type	*tmp;
				if (n == 0)
					return ;
				if (n > max_size())
					throw (std::length_error("new capacity (which is " + std::to_string(n) \
					+ ") > max_size() (which is " + std::to_string(max_size()) + ")"));
				else if (n > m_capacity) {
					tmp = _allocator.allocate(n);
					if (m_capacity > 0) {
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
			reference operator[](size_type n){
				return *(&m_ptr[n]);
			}
			const_reference operator[](size_type n) const{
				return *(&m_ptr[n]);
			}
			reference at(size_type n){
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}
			const_reference at(size_type n) const{
				if (n >= m_length)
					throw std::out_of_range("vector");
				return *(&m_ptr[n]);
			}

			///////// MODIFIERS /////////

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename enable_if<!is_integral<InputIterator>::value>::type * = 0){
				std::cout << "\t capacity av clear: " << m_capacity << std::endl;
				clear();
				std::cout << "\t capacity ap clear: " << m_capacity << std::endl;
				while (first != last) {
					push_back(*first);
					first++;
				}
			}	
			void assign(size_type n, const value_type &val){
				clear();
				size_type i = -1;
				while (++i < n) {
					push_back(val);
				}
			}
			void push_back(const value_type& val) {
				if (!m_capacity)
					reserve(1);
				else if (m_length + 1 > m_capacity){
					reserve(m_capacity * 2);
				}
				_allocator.construct(&m_ptr[m_length++], val);
			}
			void pop_back(){
				if (m_length){
					_allocator.destroy(&m_ptr[m_length - 1]);
					m_length--;
				}
			}
			iterator insert(iterator position, const value_type& val){
				size_type n = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(&m_ptr[n]));
			}
			void insert(iterator position, size_type n, const value_type& val){
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
			void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0){
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
			iterator erase(iterator position){
				return erase(position, position + 1);
			}
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
			void clear(){
				size_type i = 0;
				for ( ; i < m_length; i++)
					_allocator.destroy(&m_ptr[m_length - i]);
				m_length -= i;
			}
			void swap(vector& x) {
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
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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

#endif
