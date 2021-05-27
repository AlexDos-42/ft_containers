#ifndef LIST
# define LIST

# include <cstddef>
# include <limits>
# include <iostream>
# include "../utils/node.hpp"
#include "../iterators/BidirectionalIterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef	T										value_type;
			typedef	Alloc										allocator_type;
			typedef BidirectIterator<T, Alloc>						iterator;
			typedef BidirectIterator<const T, Alloc>				const_iterator;
			typedef ReverseBidirectIterator<T, Alloc>				reverse_iterator;
			typedef ReverseBidirectIterator<const T, Alloc>		const_reverse_iterator;
		private:
			size_t m_length;
			allocator_type		_allocator;
			Node<T, Alloc> *racine;

			Node<T, Alloc>	*creatNode(const T& val) {
				return new Node<T, Alloc>(val, _allocator);
			}
			Node<T, Alloc>	target(const T*addr){
				Node<T, Alloc>		*target = racine->m_next;

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
			void	add(const T& val, Node<T, Alloc> *target){
				if (target == racine->m_next)
					push_front(val);
				else if (target == racine)
					push_back(val);
				else
				{
					if (!m_length)
						push_front(val);
					else {
						Node<T, Alloc>		*add = creatNode(val);
						add->insert(target->prev, target);
						++m_length;
					}
				}
			}

		public:
			explicit list(): m_length(0) {
				racine = new Node<T, Alloc>(T(), _allocator);
				racine->m_next = racine;
				racine->m_back = racine;
			}
			explicit list (size_t n, const Node<T, Alloc>*& val = Node<T, Alloc>()) {
				racine = new Node<T, Alloc>(T(), _allocator);
				racine->m_next = racine;
				racine->m_back = racine;
				for ( m_length = 0; m_length < n; m_length++)
					push_front(val->m_value);
			}
			template <class iterator >
			list (iterator first, iterator last, const T& alloc = T());
			list (const list& x): m_length(x.m_length) {
				racine = new Node<T, Alloc>(T(), _allocator);
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
			iterator	begin() {
				return iterator(racine->m_next);
			}
			const_iterator	begin() const {
				return constiterator(racine->m_next);
			}
			iterator	end() {
				return iterator(racine);
			}
			const_iterator	end() const {
				return const_iterator(racine->m_next);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(racine->m_back);
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(racine->m_back);
			}
			reverse_iterator rend() {
				return reverse_iterator(racine);
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(racine);
			}

			///////// CAPACITY /////////
			size_t size(void) const {
				return (this->m_length);
			}
			size_t max_size() const {
				return (std::numeric_limits<size_t>::max() / (sizeof(Node<T, Alloc>)));
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
				return (*racine->m_next->m_value);
			}
			const T &front() const {
				return (*racine->m_next->m_value);
			}
			T &back() {
				return (*racine->m_back->m_value);
			}
			const T &back() const {
				return (*racine->m_back->m_value);
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

			iterator insert (iterator position, const T& val){
				return iterator(add(val, target(position)));
			}
			void insert (iterator position, size_t n, const T& val);
			template <class iterator>
			void insert (iterator position, iterator first, iterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			
			void push_back (const T& val)
			{
				if (!m_length) {
					Node<T, Alloc> *first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					Node<T, Alloc> *other = creatNode(val);
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
					Node<T, Alloc> *tmp = racine->m_back->m_back;
					tmp->m_next = racine;
					delete racine->m_back;
					racine->m_back = tmp;
					m_length--;
				}
			}
			void 	push_front (const T& val)
			{
				if (!m_length) {
					Node<T, Alloc> *first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					Node<T, Alloc> *other = creatNode(val);
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
					Node<T, Alloc> *tmp = racine->m_next->m_next;
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
			void swap (list& x);

			///////// LIST OPERATIONS /////////
			void splice (iterator position, list& x);
			void splice (iterator position, list& x, iterator i);
			void splice (iterator position, list& x, iterator first, iterator last);

			void remove (const T& val);
			template <class Predicate>
			void remove_if (Predicate pred);

			void unique();
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred);

			void merge (list& x);
			template <class Compare>
			void merge (list& x, Compare comp);

			void sort();
			template <class Compare>
			void sort (Compare comp);

			void reverse();
	};	
	template <class T>
	bool operator== (const list<T>& lhs, const list<T>& rhs);
	template <class T>
	bool operator!= (const list<T>& lhs, const list<T>& rhs);
	template <class T>
	bool operator<  (const list<T>& lhs, const list<T>& rhs);
	template <class T>
	bool operator<= (const list<T>& lhs, const list<T>& rhs);
	template <class T>
	bool operator>  (const list<T>& lhs, const list<T>& rhs);
	template <class T>
	bool operator>= (const list<T>& lhs, const list<T>& rhs);
	template <class T>
	void swap (list<T>& x, list<T>& y);
}

#endif