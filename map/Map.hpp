#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <cstddef>
# include <limits>
# include <iostream>
# include <functional>
# include "../iterators/MapIterator.hpp"
# include "../utils/Pairs.hpp"
# include "../utils/others.hpp"
# include "RBTree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map {
		public:
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Allocator									allocator_type;
			typedef Compare										key_compare;

			typedef	typename Allocator::reference				reference;
			typedef	typename Allocator::const_reference			const_reference;
			typedef	typename Allocator::pointer					pointer;
			typedef	typename Allocator::const_pointer			const_pointer;
 
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
			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : m_alloc(alloc), m_comp(comp), m_tree(comp, alloc) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator& alloc = Allocator()): m_alloc(alloc), m_comp(comp), m_tree(comp, alloc) {
				insert(first, last);
			}
			map(const map &other): m_alloc(other.m_alloc), m_comp(other.m_comp), m_tree(m_comp, m_alloc) {
				if (!(other.empty()))
					insert(other.begin(), other.end());
			}
			~map() {};
			map&	operator=(const map &other) {
				if (&other == this)
					return *this;
				clear();
				if (!(other.empty()))
					insert(other.begin(), other.end());
				return *this;
			}

			///////// ITERATORS /////////

			iterator		begin() {
				return m_tree.begin();
			}
			const_iterator		begin() const {
				return m_tree.begin();
			}
			iterator		end() {
				return m_tree.end();
			}
			const_iterator		end() const {
				return m_tree.end();
			}
			reverse_iterator	rbegin() {
				return reverse_iterator(end());
			}
			const_reverse_iterator	rbegin() const {
				return const_reverse_iterator(end());
			}
			reverse_iterator	rend() {
				return reverse_iterator(begin());
			}
			reverse_iterator	rend() const {
				return cont_reverse_iterator(begin());
			}

			///////// CAPACITY /////////

			bool			empty() const {
				return (m_tree.get_size() == 0);
			}
			size_type		size() const {
				return m_tree.get_size();
			}
			size_type		max_size() const {
				std::allocator<ft::NodeMap<value_type> >	node_alloc;
				return node_alloc.max_size();
			}

			///////// ELEMENTS ACCESS /////////

			mapped_type&		operator[](const key_type& key) {
				return insert(ft::make_pair(key, mapped_type())).first->second;
			}

			///////// MODIFIERS /////////

			pair<iterator, bool>	insert(const value_type& value) {
				return m_tree.insert(value);
			}
			iterator	insert(iterator hint, const value_type& value) {
				(void)hint;

				return insert(value).first;
			}
			template <class InputIterator>
			void 		insert(InputIterator first, InputIterator last) {
				while (first != last) {
					insert(*first);
					first++;
				}
			}
			void 		erase(iterator pos) {
				m_tree.delete_node(pos.m_node);
			}
			void 		erase(iterator first, iterator last) {
				NodeMap<value_type>	*to_delete;
				while (first != last) {
					to_delete = first.m_node;
					first++;
					m_tree.delete_node(to_delete);
				}
			}
			size_type	erase(const key_type& key) {
				NodeMap<value_type>	*to_delete = m_tree.search_node(key);
				if (to_delete == nullptr)
					return 0;
				else {
					m_tree.delete_node(to_delete);
					return 1;
				}
			}
			void 		swap(map& other) {
				m_tree.swap(other.m_tree);
			}
			void 	clear() {
				m_tree.clear();
			}

			///////// OBSERVERS /////////

			key_compare		key_comp() const {
				return key_compare();
			}
			value_compare	value_comp() const {
				return value_compare(key_compare());
			}

			///////// OPERATIONS /////////

			iterator		find(const key_type& k) {
				return m_tree.find(k);
			}
			const_iterator	find(const key_type& k) const {
				return m_tree.find(k);
			}
			size_type	count(const key_type& k) const {
				if (m_tree.search_node(k) == nullptr)
					return 0;
				else
					return 1;
			}
			pair<iterator,iterator>	equal_range(const key_type& k) {
				return make_pair(m_tree.lower_bound(k), m_tree.upper_bound(k));
			}
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
				return make_pair(m_tree.lower_bound(k), m_tree.upper_bound(k));
			}
			iterator	lower_bound(const key_type &k) {
				return m_tree.lower_bound(k);
			}
			const_iterator	lower_bound(const key_type &k) const {
				return m_tree.lower_bound(k);
			}
			iterator	upper_bound(const key_type &k) {
				return m_tree.upper_bound(k);
			}
			const_iterator	upper_bound(const key_type &k) const {
				return m_tree.upper_bound(k);
			}

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
		return !(lhs == rhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		ConstMapIterator<pair<const char, int> > lhs_begin = lhs.begin();
		ConstMapIterator<pair<const char, int> > lhs_end = lhs.end();
		ConstMapIterator<pair<const char, int> > rhs_begin = rhs.begin();
		ConstMapIterator<pair<const char, int> > rhs_end = rhs.end();
		//int n = 0;
		while (lhs_begin != lhs_end) {
			if (rhs_begin == lhs_end || *rhs_begin < *lhs_begin)
				return false;
			if (*lhs_begin < *rhs_begin)
				return true;
			++lhs_begin;
			++rhs_begin;
		}
		std::cout << "la" << std::endl;
		return (rhs_begin != rhs_end);
		//return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
		x.swap(y);
	};
};

#endif