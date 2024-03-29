#pragma once

# include <memory>
# include <cstddef>
# include <limits>
# include <iostream>
# include <functional>
# include "../iterators/MapIterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/others.hpp"
# include "RBTree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef Allocator									allocator_type;
			typedef Compare										key_compare;

			typedef	typename Allocator::reference				reference;
			typedef	typename Allocator::const_reference			const_reference;
			typedef	typename Allocator::pointer					pointer;
			typedef	typename Allocator::const_pointer			const_pointer;
			typedef typename Allocator::value_type				value_type;

			typedef	RBTree<Key, T, Compare, Allocator>			tree;
			
			typedef	typename tree::iterator						iterator;
			typedef	typename tree::const_iterator				const_iterator;
			typedef	typename tree::size_type					size_type;
			typedef	typename tree::difference_type				difference_type;
			typedef	typename tree::reverse_iterator				reverse_iterator;
			typedef	typename tree::const_reverse_iterator		const_reverse_iterator;

			class value_compare {
				friend class 									map<Key, T, Compare, Allocator>;
				typedef bool									result_type;
				typedef value_type								first_argument_type;
				typedef value_type								second_argument_type;
				protected:
					Compare										comp;
					value_compare(Compare c) : 					comp(c) {}
				public:
					bool	operator()(const value_type& lhs, const value_type& rhs) const {
						return comp(lhs.first, rhs.first);
					}
			};
			
		private:
			allocator_type										m_alloc;
			key_compare											m_comp;
			RBTree<Key, T, Compare, Allocator>					m_tree;

		public:
			/* Constructor default */
			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : m_alloc(alloc), m_comp(comp), m_tree(comp, alloc) {}
			/* Constructor range */
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator& alloc = Allocator()): m_alloc(alloc), m_comp(comp), m_tree(comp, alloc) {
				insert(first, last);
			}
			/* Constructor copy */
			map(const map &other): m_alloc(other.m_alloc), m_comp(other.m_comp), m_tree(m_comp, m_alloc) {
				if (!(other.empty()))
					insert(other.begin(), other.end());
			}
			/* Map destructor */
			~map() {};
			/* Assign content */
			map&	operator=(const map &other) {
				if (&other == this)
					return *this;
				clear();
				if (!(other.empty()))
					insert(other.begin(), other.end());
				return *this;
			}

			///////// ITERATORS /////////

			/* Returns an iterator pointing to the first element in the Map. */
			iterator		begin() {
				return m_tree.begin();
			}
			/* Returns an iterator pointing to the first element in the Map. */
			const_iterator		begin() const {
				return m_tree.begin();
			}
			/* Return iterator to end */
			iterator		end() {
				return m_tree.end();
			}
			/* Return iterator to end */
			const_iterator		end() const {
				return m_tree.end();
			}
			/* Return reverse iterator to reverse beginning */
			reverse_iterator	rbegin() {
				return reverse_iterator(end());
			}
			/* Return reverse iterator to reverse beginning */
			const_reverse_iterator	rbegin() const {
				return const_reverse_iterator(end());
			}
			/* Return reverse iterator to reverse end */
			reverse_iterator	rend() {
				return reverse_iterator(begin());
			}
			/* Return reverse iterator to reverse end */
			const_reverse_iterator	rend() const {
				return cont_reverse_iterator(begin());
			}

			///////// CAPACITY /////////

			/* Test whether map is empty */
			bool			empty() const {
				return (m_tree.get_size() == 0);
			}
			/* Return size */
			size_type		size() const {
				return m_tree.get_size();
			}
			/* Return maximum size */
			size_type		max_size() const {
				return m_tree.max_size();
			}

			///////// ELEMENTS ACCESS /////////

			/* Access element */
			mapped_type&		operator[](const key_type& key) {
				return insert(ft::make_pair(key, mapped_type())).first->second;
			}

			///////// MODIFIERS /////////

			/* Insert elements single element */
			pair<iterator, bool>	insert(const value_type& value) {
				return m_tree.insert(value);
			}
			/* Insert elements single element with hint*/
			iterator	insert(iterator hint, const value_type& value) {
				(void)hint;

				return insert(value).first;
			}
			/* Insert elements range*/
			template <class InputIterator>
			void 		insert(InputIterator first, InputIterator last) {
				while (first != last) {
					insert(*first);
					first++;
				}
			}
			/* Erase element */
			void 		erase(iterator pos) {
				m_tree.delete_node(pos.m_node);
			}
			/* Erase elements */
			void 		erase(iterator first, iterator last) {
				NodeMap<value_type>	*to_delete;
				while (first != last) {
					to_delete = first.m_node;
					first++;
					m_tree.delete_node(to_delete);
				}
			}
			/* Erase element */
			size_type	erase(const key_type& key) {
				NodeMap<value_type>	*to_delete = m_tree.search_node(key);
				if (to_delete == NULL)
					return 0;
				else {
					m_tree.delete_node(to_delete);
					return 1;
				}
			}
			/* Swap content */
			void 		swap(map& other) {
				m_tree.swap(other.m_tree);
			}
			/* Clear content */
			void 	clear() {
				m_tree.clear();
			}

			///////// OBSERVERS /////////

			/* Return key comparison object */
			key_compare		key_comp() const {
				return key_compare();
			}
			/* Return value comparison object */
			value_compare	value_comp() const {
				return value_compare(key_compare());
			}

			///////// OPERATIONS /////////

			/* Get iterator to element */
			iterator		find(const key_type& k) {
				return m_tree.find(k);
			}
			/* Get iterator to element */
			const_iterator	find(const key_type& k) const {
				return m_tree.find(k);
			}
			/* Count elements with a specific key */
			size_type	count(const key_type& k) const {
				if (m_tree.search_node(k) == NULL)
					return 0;
				else
					return 1;
			}
			/* Get range of equal elements */
			pair<iterator,iterator>	equal_range(const key_type& k) {
				return make_pair(m_tree.lower_bound(k), m_tree.upper_bound(k));
			}
			/* Get range of equal elements */
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
				return make_pair(m_tree.lower_bound(k), m_tree.upper_bound(k));
			}
			/* Return iterator to lower bound */
			iterator	lower_bound(const key_type &k) {
				return m_tree.lower_bound(k);
			}
			/* Return iterator to lower bound */
			const_iterator	lower_bound(const key_type &k) const {
				return m_tree.lower_bound(k);
			}
			/* Return iterator to upper bound */
			iterator	upper_bound(const key_type &k) {
				return m_tree.upper_bound(k);
			}
			/* Return iterator to upper bound */
			const_iterator	upper_bound(const key_type &k) const {
				return m_tree.upper_bound(k);
			}

			///////// ALLOCATOR /////////

			/* Returns a copy of the allocator  */
			allocator_type	get_allocator() const {
				return m_tree.get_allocator();
			}

		private:
			///////// PRINT /////////

			void 		print(void) {
				m_tree.print_tree();
				std::cout << "_____________________________________________________"  << std::endl << std::endl;
			}
	};

	///////// NON-MEMBER FONCTION OVERLOADS /////////

	template< class Key, class T, class Compare, class Alloc >
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		if (rhs < lhs || rhs > lhs)
			return false;
		return true;
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (!(lhs == rhs));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(rhs < lhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(lhs < rhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return rhs < lhs;
	}
	template< class Key, class T, class Compare, class Alloc >
	void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
		x.swap(y);
	};
};
