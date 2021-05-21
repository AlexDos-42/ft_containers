#ifndef LIST
# define LIST

# include <cstddef>
# include <limits>
# include <iostream>

# include "../utils/node.hpp"
#include "../iterators/BidirectionalIterator.hpp"

// To do:	relational operators
//			allocator
//			LIST OPERATIONS + MODIFIERS

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef	T												value_type;
			typedef	allocator_type::reference						reference;
			typedef Alloc											allocator_type;
			typedef BidirectIterator<value_type>					iterator;
			typedef ConstBidirectIterator<value_type>				const_iterator;
			typedef ReverseBidirectIterator<value_type>				reverse_iterator;
			typedef ConstReverseBidirectIterator<value_type>		const_reverse_iterator;
			typedef size_t											size_type;
		private:
			size_type m_length;
			Node<value_type> *racine;
			Node<value_type>	*creatNode(const value_type& val) {
				return new Node<value_type>(val);
			}
			Node<value_type>	target(const value_type*addr){
				Node<value_type>		*target = racine->m_next;

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
			void	add(const value_type& val, Node<value_type> *target){
				if (target == racine->m_next)
					push_front(val);
				else if (target == racine)
					push_back(val);
				else
				{
					if (!m_length)
						push_front(val);
					else {
						Node<value_type>		*add = creatNode(val);
						add->insert(target->prev, target);
						++m_length;
					}
				}
			}

		public:
			explicit list(const allocator_type& alloc = allocator_type()): m_length(0) {
				racine = new Node<value_type>();
				racine->m_next = racine;
				racine->m_back = racine;
			}
			explicit list (size_t n, const Node<value_type>*& val = Node<value_type>()) {
				racine = new Node<value_type>();
				racine->m_next = racine;
				racine->m_back = racine;
				for ( m_length = 0; m_length < n; m_length++)
					push_front(val->m_value);
			}
			template <class iterator >
			list (iterator first, iterator last, const value_type& alloc = value_type());
			list (const list& x): m_length(x.m_length) {
				racine = new Node<value_type>();
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
				return (std::numeric_limits<size_t>::max() / (sizeof(Node<value_type>)));
			}
			bool empty(void) const {
				return (this->m_length == 0);
			}
			void resize (size_t n, value_type val = value_type()){
				while (this->m_length > n) {
					pop_back();
				}
				while (this->m_length < n) {
					push_back(val);
				}
			}

			///////// ELEMENTS ACCESS /////////
			value_type &front() {
				return (racine->m_next->m_value);
			}
			const value_type &front() const {
				return (racine->m_next->m_value);
			}
			value_type &back() {
				return (racine->m_back->m_value);
			}
			const value_type &back() const {
				return (racine->m_back->m_value);
			}

			///////// MODIFIERS /////////
			template <class iterator>
			void assign (iterator first, iterator last){
				clear();
				while (first != last)
					push_back(*first++);
			}
			void assign (size_t n, const value_type& val) {
				clear();
				while (n--)
					push_front(val);
			}

			iterator insert (iterator position, const value_type& val){
				return iterator(add(val, target(position)));
			}
			void insert (iterator position, size_t n, const value_type& val);
			template <class iterator>
			void insert (iterator position, iterator first, iterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			
			void push_back (const value_type& val)
			{
				if (!m_length) {
					Node<value_type> *first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					Node<value_type> *other = creatNode(val);
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
					Node<value_type> *tmp = racine->m_back->m_back;
					tmp->m_next = racine;
					delete racine->m_back;
					racine->m_back = tmp;
					m_length--;
				}
			}
			void 	push_front (const value_type& val)
			{
				if (!m_length) {
					Node<value_type> *first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					Node<value_type> *other = creatNode(val);
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
					Node<value_type> *tmp = racine->m_next->m_next;
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

			void remove (const value_type& val);
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
	template <class value_type>
	bool operator== (const list<value_type>& lhs, const list<value_type>& rhs);
	template <class value_type>
	bool operator!= (const list<value_type>& lhs, const list<value_type>& rhs);
	template <class value_type>
	bool operator<  (const list<value_type>& lhs, const list<value_type>& rhs);
	template <class value_type>
	bool operator<= (const list<value_type>& lhs, const list<value_type>& rhs);
	template <class value_type>
	bool operator>  (const list<value_type>& lhs, const list<value_type>& rhs);
	template <class value_type>
	bool operator>= (const list<value_type>& lhs, const list<value_type>& rhs);
	template <class value_type>
	void swap (list<value_type>& x, list<value_type>& y);
}

#endif