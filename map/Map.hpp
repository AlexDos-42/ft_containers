#ifndef MAP
# define MAP

# include <cstddef>
# include <limits>
# include <iostream>
# include <functional>
# include "../utils/nodeMap.hpp"
# include "../utils/Pairs.hpp"
# include "../iterators/Maplterator.hpp"

# define _RED			"\x1b[31m"
# define _GREY			"\x1b[30m"
# define _END			"\x1b[0m"
# define _IWHITE		"\x1b[47m"

namespace ft
{
	template < class Key, class T, class Node, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef	T											value_type;
			typedef MapIterator<Key, T, Compare, Alloc>			iterator;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef NodeMap<T, Compare>							NodeMap;
			//typedef ft::pair									pair;
			
		private:
			NodeMap			*racine;
			Alloc			_allocator;
			Compare			m_comp;
			size_t			m_lenght;
		public:
			explicit map(const Compare& m_comp = Compare(), const Alloc& _allocator = Alloc())
				: _allocator(_allocator), m_comp(m_comp), m_lenght(0){
				new_root();
				racine->left = NULL;
				racine->right = NULL;
				racine->parent = NULL;
				racine->m_color = BLACK;
			}
			//template <class InputIterator>
			//map (iterator first, iterator last, const Compare& comp = Compare(), const Alloc& _allocator = Alloc());
			map (const map& x);
			~map() {
				delete racine;
			}
			map& operator= (const map& x);

			///////// ITERATORS /////////
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;	

			///////// CAPACITY /////////
			bool empty() const {
				return(!m_lenght);
			}
			size_t size() const{
				return (m_lenght);
			}
			size_t max_size() const;

			///////// ELEMENTS ACCESS /////////
			// mapped_type& operator[] (const key_type& k);
			// mapped_type& at (const key_type& k);
			// const mapped_type& at (const key_type& k) const;

			///////// MODIFIERS /////////
			ft::pair<iterator, bool>	insert(const T& val) {
				if (m_lenght == 0){
					new_root(val);
					iterator(new_root(val));
					return (ft::make_pair(iterator(new_root(val)), true));
				}
			// NodeMap	*it(racine);
			// while (it) {
			// 	if (Compare()(val.first, it->data.first)) {
			// 		if (it->left && it->left != this->_first)
			// 			it = it->left;
			// 		else return ft::make_pair(iterator(insert_left(it, val)), true);
			// 	}
			// 	else if (Compare()(it->data.first, val.first)) {
			// 		if (it->right && it->right != this->_last)
			// 			it = it->right;
			// 		else return ft::make_pair(iterator(insert_right(it, val)), true);
			// 	}
			// 	else break ;
			// }
			// return ft::make_pair(iterator(it), false);
			}
			// iterator insert (iterator position, const value_type& val);
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);
			// void erase (iterator position);
			// size_t erase (const key_type& k);
			// void erase (iterator first, iterator last);
			void swap (map& x);
			void clear();

			///////// OBSERVERS /////////
			// key_compare key_comp() const;
			// value_compare value_comp() const;

			///////// OPERATIONS /////////
			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;
			// size_t count (const key_type& k) const;
			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;
			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;
			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);
			
			NodeMap	*new_root() {
				racine = new NodeMap();
				return racine;
			}

			NodeMap	*new_root(const Node& val) {
				racine = new NodeMap(val, BLACK);
				++m_lenght;
				return racine;
			}

			void print() const {
				print("", racine, false);
				std::cout << std::endl;
			}

			void print(const std::string& display, const NodeMap* node, bool isLeft) const {
				if (node) {
					std::cout	<< display \
								<< (isLeft ? "├L─" : "└R-" );
					if (node->m_color == RED)
						std::cout << _RED;
					else if (node->m_color == BLACK)
						std::cout << _IWHITE << _GREY;
					std::cout << node->m_value << _END << std::endl ;
					print(display + (isLeft ? "│   " : "    "), node->left, true);
					print(display + (isLeft ? "│   " : "    "), node->right, false);
				}
			}

	};
}

#endif