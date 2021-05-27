#ifndef LIST_HPP
# define LIST_HPP

# include <cstddef>
# include <limits>
# include <iostream>
# include <memory>
# include "../utils/node.hpp"
#include "../iterators/BidirectionalIterator.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	size_t										size_type;
			typedef Node<value_type, allocator_type>*			node;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef BidirectIterator<T, Alloc>					iterator;
			typedef BidirectIterator<const T, Alloc>			const_iterator;
			typedef ReverseBidirectIterator<T, Alloc>			reverse_iterator;
			typedef ReverseBidirectIterator<const T, Alloc>		const_reverse_iterator;
		private:
			size_type 			m_length;
			allocator_type		m_allocator;
			node 				racine;
			std::allocator<Node<value_type, allocator_type> >     m_allocNode;

			node creatNode(const value_type& val = value_type()) {
				node tmpNode = m_allocNode.allocate(1);
                m_allocNode.construct(&tmpNode->m_data, val);
                return tmpNode;
			}
			node	target(const T*addr){
				node target = racine->m_next;

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
			void	add(const T& val, node target){
				if (target == racine->m_next)
					push_front(val);
				else if (target == racine)
					push_back(val);
				else
				{
					if (!m_length)
						push_front(val);
					else {
						node add = creatNode(val);
						add->insert(target->prev, target);
						++m_length;
					}
				}
			}

		public:
			explicit list(const allocator_type& alloc = allocator_type()): m_length(0), m_allocator(alloc) {
				racine = m_allocNode.allocate(1);
				racine->m_next = racine;
				racine->m_back = racine;
			}
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				m_allocator = alloc;
				racine = m_allocNode.allocate(1);
				racine->m_next = racine;
				racine->m_back = racine;
				for ( m_length = 0; m_length < n; m_length++)
					push_front(val->m_value);
			}
			template <class InputIterator >
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			list (const list& x): m_length(x.m_length) {
				racine = m_allocNode.allocate(1);
				racine->m_next = x.racine->m_next;
				racine->m_back = x.racine->m_back;
			}
			~list() {
				clear();
				m_allocNode.deallocate(racine, 1);
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
			size_type size(void) const {
				return (this->m_length);
			}
			size_type max_size() const {
				return (std::numeric_limits<size_type>::max() / (sizeof(Node<T, Alloc>)));
			}
			bool empty(void) const {
				return (this->m_length == 0);
			}
			void resize (size_type n, T val = T()){
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
					node first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					node other = creatNode(val);
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
					node tmp = racine->m_back->m_back;
					tmp->m_next = racine;
					delete racine->m_back;
					racine->m_back = tmp;
					m_length--;
				}
			}
			void 	push_front (const value_type& val)
			{
				if (!m_length) {
					node first = creatNode(val);
					racine->m_next = first;
					racine->m_back = first;
					first->m_next = racine;
					first->m_back = racine;
				}
				else {
					node other = creatNode(val);
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
					node tmp = racine->m_next->m_next;
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
};

#endif