#ifndef VECTOR
# define VECTOR

# include <cstddef>
# include <limits>
# include <iostream>
#include "../iterators/VectorIterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		typedef VectorIterator<T>					iterator;
		typedef ConstVectorIterator<T>				const_iterator;
		typedef ReverseVectorIterator<T>			reverse_iterator;
		typedef ConstReverseVectorIterator<T>		const_reverse_iterator;

		private:
			T*			m_ptr;
			size_t		m_length;
			size_t		m_capacity;
			Alloc		_allocator;
		public:
			explicit vector(const Alloc& alloc = Alloc()):
					_allocator(alloc), m_ptr(0), m_length(0), m_capacity(0) {}
			explicit vector (size_t n, const T& val = T(), const Alloc& alloc = Alloc()):
					_allocator(alloc), m_length(n), m_capacity(n) {
				m_ptr = _allocator.allocate(n);
				for (size_t i = 0; i < n; i++)
					_allocator.construct(m_ptr[i], val);
			}
			template <class Iterator>
			//vector (Iterator first, Iterator last, const Alloc& alloc = Alloc()):
			//		: _allocator(alloc), m_ptr(0), m_length(0), m_capacity(0) {
				//assign(first, last);
			//}	
			vector (const vector& x):
					m_ptr(0), m_length(0), m_capacity(0) {
				*this = x;
			}
			~vector(){
				for (size_t i = 0; i < m_length; ++i)
					_allocator.destroy(m_ptr[i]);
				_allocator.deallocate(m_ptr, m_capacity);
			}
			// vector& operator= (const vector& x);

			///////// ITERATORS /////////
			iterator begin() {
				return iterator(m_ptr);
			}
			// const_iterator begin() const {
			// 	return constiterator(m_ptr);
			// }
			iterator end(){
				return iterator(m_ptr[m_length]);
			}
			// const_iterator end() const{
			// 	return constiterator(m_ptr[m_length]);
			// }
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			///////// CAPACITY /////////
			size_t size() const{
				return m_length;
			}
			size_t max_size() const{
				return _allocator.max_size();
			}
			//void resize (size_t n, T val = T()){}
			size_t capacity() const{
				return m_capacity;
			}
			bool empty() const{
				return (!(m_length));
			}
			//void reserve (size_t n);

			///////// ELEMENTS ACCESS /////////
			// reference front();
			// const_reference front() const;
			// reference back();
			// const_reference back() const;
			// reference operator[] (size_t n);
			// const_reference operator[] (size_t n) const;
			// reference at (size_t n);
			// const_reference at (size_t n) const;

			///////// MODIFIERS /////////
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);	
			// void assign (size_type n, const value_type& val);	
			// iterator insert (iterator position, const value_type& val);	
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			void push_back (const T& val){
				if (m_length == m_capacity)
					m_realloc();
				_allocator.construct(m_ptr[m_length], val);
				++m_length;
			}
			void pop_back(){
				if (m_length){
					_allocator.destroy(m_ptr[m_length - 1]);
					m_length--;
				}
			}
			void clear(){
				while (m_length--)
					_allocator.destroy(m_ptr[m_length]);
			}
			// void swap (vector& x);
			private:
				void	m_realloc(size_t n = 0){
					T*		tmp;

					if (!n)
						n = !m_capacity ? 1 : m_capacity * 2;
					tmp = _allocator.allocate(n);
					for (size_t i = 0; i < m_length; ++i)
						_allocator.construct(tmp[i], m_ptr[i]);
					for (size_t i = m_length; i < n; ++i)
						_allocator.construct(tmp[i], T());
					for (size_t i = 0; i < m_length; ++i)
						_allocator.destroy(m_ptr[i]);
					_allocator.deallocate(m_ptr, m_capacity);
					m_capacity = n;
					m_ptr = tmp;
				}
	};
	// template <class T, class Alloc>
	// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	// template <class T, class Alloc>
	// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
}

#endif