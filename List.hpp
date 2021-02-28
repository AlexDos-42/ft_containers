#ifndef LIST
# define LIST

# include <cstddef>
# include <limits>
# include <iostream>
# include "node.hpp"
#include "BidirectionalIterator.hpp"

namespace ft
{
	template < class T>
	class list
	{
		private:
			size_t m_length;
			Node<T> *racine;
		public:
			//explicit list (const allocator_type& alloc = allocator_type());
			list(): m_length(0) {
				racine = new Node<T>();
				racine->m_next = racine;
				racine->m_back = racine;
			}
			explicit list (size_t n, const Node<T>*& val = Node<T>()) {
				racine = new Node<T>();
				racine->m_next = racine;
				racine->m_back = racine;
				for ( m_length = 0; m_length < n; m_length++)
					push_front(val->m_value);
			}
			//template <class InputIterator>
			//list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			list (const list& x): m_length(x.m_length) {
				racine = new Node<T>();
				racine->m_next = x.racine->m_next;
				racine->m_back = x.racine->m_back;
			}
			~list() {
				clear();
				delete racine;
			}
			
			//list& operator= (const list& x);{
			//	m_begin = x->m_begin;
			//	m_end = x->m_end;
			//	m_length = x->m_length;
			// 	return (*this);
			//}

			///////// ITERATORS /////////
			iterator<T>	begin() {
			return iterator<T>(racine->m_next);
			}
			// const_iterator	begin() const {
			// 	return const_iterator(this->head->next);
			// }
			iterator<T>	end() {
				return iterator<T>(racine->m_back);
			}
			// const_iterator	end() const {
			// 	return const_iterator(this->tail);
			// }
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			///////// CAPACITY /////////
			size_t size(void) const {
				return (this->m_length);
			}
			size_t max_size() const {
				return (std::numeric_limits<size_t>::max() / (sizeof(Node<T>)));
			}
			bool empty(void) const {
				return (this->m_length == 0);
			}
			void resize (size_t n, T val = T()){
				while (this->m_length > n) {
					pop_back();
				}
				while (this->m_length < n) {
					push_back(val);
				}
			}

			///////// ELEMENTS ACCESS /////////
			T &front() {
				return (racine->m_next->m_value);
			}
			const T &front() const {
				return (racine->m_next->m_value);
			}
			T &back() {
				return (racine->m_back->m_value);
			}
			const T &back() const {
				return (racine->m_back->m_value);
			}

			///////// MODIFIERS /////////
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last);
			void assign (size_t n, const T& val) {
				clear();
				while (n--)
					push_front(val);
			}

			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);

			Node<T>*	creatNode(const T& val) {
				return new Node<T>(val);
			}
			
			void push_back (const T& val)
			{
				if (!m_length) {
					Node<T> *first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					Node<T> *other = creatNode(val);
					racine->m_back->m_next = other;
					other->m_back = racine->m_back;
					other->m_next = racine;
					racine->m_back = other;
				}
				m_length++;
			}
			void pop_back(){
				if (this->m_length)
				{
					Node<T> *tmp = racine->m_back->m_back;
					tmp->m_next = racine;
					delete racine->m_back;
					racine->m_back = tmp;
					m_length--;
				}
			}
			void 	push_front (const T& val)
			{
				if (!m_length) {
					Node<T> *first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					Node<T> *other = creatNode(val);
					racine->m_next->m_back = other;
					other->m_next = racine->m_next;
					other->m_back = racine;
					racine->m_next = other;
				}
				m_length++;
			}
			void pop_front(){
				if (this->m_length)
				{
					Node<T> *tmp = racine->m_next->m_next;
					tmp->m_back = racine;
					delete racine->m_next;
					racine->m_next = tmp;
					m_length--;
				}
			}
			void clear() {
				while(m_length)
					pop_front();
			}
			// void swap (list& x);
			///////// LIST OPERATIONS /////////
			// void splice (iterator position, list& x);
			// void splice (iterator position, list& x, iterator i);
			// void splice (iterator position, list& x, iterator first, iterator last);

			// void remove (const value_type& val);
			// template <class Predicate>
			// void remove_if (Predicate pred);

			// void unique();
			// template <class BinaryPredicate>
			// void unique (BinaryPredicate binary_pred);

			// void merge (list& x);
			// template <class Compare>
			// void merge (list& x, Compare comp);

			// void sort();
			// template <class Compare>
			// void sort (Compare comp);

			// void reverse();

			///////// OBSERVERS /////////
			// allocator_type get_allocator() const;
	};
}

#endif