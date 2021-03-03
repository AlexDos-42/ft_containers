#ifndef LIST
# define LIST

# include <cstddef>
# include <limits>
# include <iostream>
# include "../utils/node.hpp"
#include "../iterators/BidirectionalIterator.hpp"

namespace ft
{
	template < class T>
	class list
	{
		private:
			size_t m_length;
			Node<T> *racine;
			Node<T>	*creatNode(const T& val) {
				return new Node<T>(val);
			}
			Node<T>	target(const T*addr){
				Node<T>		*target = racine->m_next;

				while (target != racine)
				{
					if (target->m_value == addr)
						return target;
					target = target->m_next;
				}
				if (target->m_value == addr)
					return target;
				return NULL;
			}
			void	add(const T& val, Node<T> *target){
				if (target == racine->m_next)
					push_front(val);
				else if (target == racine)
					push_back(val);
				else
				{
					if (!m_length)
						push_front(val);
					else {
						Node<T>		*add = creatNode(val);
						add->insert(target->prev, target);
						++m_length;
					}
				}
			}

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
			template <class iterator >
			list (iterator first, iterator last, const T& alloc = T());
			list (const list& x): m_length(x.m_length) {
				racine = new Node<T>();
				racine->m_next = x.racine->m_next;
				racine->m_back = x.racine->m_back;
			}
			~list() {
				clear();
				delete racine;
			}
			list& operator= (const list& x){
				clear();
				racine = x->racine;
				m_length = x->m_length;
				assign(x.begin, x.end);
				return (*this);
			}

			///////// ITERATORS /////////
			iterator<T>	begin() {
				return iterator<T>(racine->m_next);
			}
			constiterator<T>	begin() const {
				return constiterator<T>(racine->m_next);
			}
			iterator<T>	end() {
				return iterator<T>(racine);
			}
			constiterator<T>	end() const {
				return constiterator<T>(racine->m_next);
			}
			reverseiterator<T> rbegin() {
				return reverseiterator<T>(racine->m_back);
			}
			reverseconstiterator<T> rbegin() const {
				return reverseconstiterator<T>(racine->m_back);
			}
			reverseiterator<T> rend() {
				return reverseiterator<T>(racine);
			}
			reverseconstiterator<T> rend() const {
				return reverseconstiterator<T>(racine);
			}

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
			template <class iterator>
			void assign (iterator first, iterator last){
				clear();
				while (first != last)
					push_back(*first++);
			}
			void assign (size_t n, const T& val) {
				clear();
				while (n--)
					push_front(val);
			}

			iterator<T> insert (iterator<T> position, const T& val){
				return iterator<T>(add(val, target(position)));
			}
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class iterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			
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
	};	
	// template <class T, class Alloc>
	// bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	// void swap (list<T,Alloc>& x, list<T,Alloc>& y);
}

#endif