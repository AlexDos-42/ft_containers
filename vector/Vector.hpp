#ifndef VECTOR
# define VECTOR

# include <cstddef>
# include <limits>
# include <iostream>

namespace ft
{
	template < class T>
	class vector
	{
		private:
        size_t n;
		public:
// explicit vector (const allocator_type& alloc = allocator_type());	
// explicit vector (size_type n, const value_type& val = value_type(),
// const allocator_type& alloc = allocator_type());
// template <class InputIterator>
// vector (InputIterator first, InputIterator last,
// const allocator_type& alloc = allocator_type());	
// vector (const vector& x);
// ~vector();
// vector& operator= (const vector& x);

///////// ITERATORS /////////
// iterator begin() noexcept;
// const_iterator begin() const noexcept;
// iterator end();
// const_iterator end() const;
// reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
// reverse_iterator rend();
// const_reverse_iterator rend() const;

// ///////// CAPACITY /////////
// size_type size() const;
// size_type max_size() const;
// void resize (size_type n, value_type val = value_type());
// size_type capacity() const;
// bool empty() const;
// void reserve (size_type n);

// ///////// ELEMENTS ACCESS /////////
// reference front();
// const_reference front() const;
// reference back();
// const_reference back() const;
// reference operator[] (size_type n);
// const_reference operator[] (size_type n) const;
// reference at (size_type n);
// const_reference at (size_type n) const;

// ///////// MODIFIERS /////////
// template <class InputIterator>
// void assign (InputIterator first, InputIterator last);	
// void assign (size_type n, const value_type& val);	
// iterator insert (iterator position, const value_type& val);	
// void insert (iterator position, size_type n, const value_type& val);
// template <class InputIterator>
// void insert (iterator position, InputIterator first, InputIterator last);
// iterator erase (iterator position);
// iterator erase (iterator first, iterator last);
// void push_back (const value_type& val);
// void pop_back();
// void clear();
// void swap (vector& x);
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