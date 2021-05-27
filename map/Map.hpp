#ifndef MAP
# define MAP

# include <cstddef>
# include <limits>
# include <iostream>
# include <functional>
# include "../utils/nodeMap.hpp"
# include "../utils/Pairs.hpp"
# include "../iterators/Maplterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef pair<const key_type,mapped_type>			value_type;
			typedef Alloc										allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef	value_type*									pointer;
			typedef const value_type*							const_pointer;
			typedef NodeMap<value_type, Compare>				NodeMap;
			typedef MapIterator<value_type, pointer, reference, Compare >			iterator;

			
		private:
			NodeMap			*racine;
			Alloc			_allocator;
			Compare			m_comp;
			size_t			m_lenght;
		public:
			explicit map(const Compare& m_comp = Compare(), const Alloc& _allocator = Alloc())
				: _allocator(_allocator), m_comp(m_comp), m_lenght(0){
				new_root();
				racine->m_color = BLACK;
			}
			//template <class InputIterator>
			//map (iterator first, iterator last, const Compare& comp = Compare(), const Alloc& _allocator = Alloc());
			map (const map& x);
			~map() {
				clear(racine);
			}
			map& operator= (const map& x);

			///////// ITERATORS /////////
			iterator begin(){ 
				return iterator(racine);
			}
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
			ft::pair<iterator, bool>	insert(const value_type& val) {
				if (m_lenght == 0){
					return (ft::make_pair(iterator(new_root(val)), true));
				}
				NodeMap	*it(racine);
				while (it) {
					if (Compare()(val.first, it->m_value.first)) {
						if (it->left)
							it = it->left;
						else return ft::make_pair(iterator(insert_left(it, val)), true);
					}
					else if (Compare()(it->m_value.first, val.first)) {
						if (it->right)
							it = it->right;
						else return ft::make_pair(iterator(insert_right(it, val)), true);
					}
					else break ;
				}	
				return ft::make_pair(iterator(it), false);
			}
			// iterator insert (iterator position, const value_type& val);
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);
			// void erase (iterator position);
			// size_t erase (const key_type& k);
			// void erase (iterator first, iterator last);
			void swap (map& x);
			void	clear(NodeMap *pos) {
				if (!pos)
					return ;
				clear(pos->left);
				clear(pos->right);
				delete pos;
				--m_lenght;
			}

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
				racine = new NodeMap(ft::make_pair(10, 353));
				return racine;
			}

			NodeMap	*new_root(const value_type& val) {
				racine = new NodeMap(val, BLACK);
				++m_lenght;
				return racine;
			}

			NodeMap	*insert_left(NodeMap *it, const value_type& val = value_type()) {
				NodeMap *insert = new NodeMap(val);
				insert->parent = it;
				insert->left = it->left;
				if (it->left)
					it->left->parent = insert;
				it->left = insert;
				++m_lenght;
				insertrules(insert);
				return insert;
			}
			NodeMap	*insert_right(NodeMap *it, const value_type& val = value_type()) {
				NodeMap *insert = new NodeMap(val);
				insert->parent = it;
				insert->right = it->right;
				if (it->right)
					it->right->parent = insert;
				it->right = insert;
				++m_lenght;
				insertrules(insert);
				return insert;
			}

			void print() const {
				print("", racine, false);
				std::cout << std::endl;
			}

			void print(const std::string& display, const NodeMap* node, bool Left) const {
				if (node) {
					std::cout	<< display \
								<< (Left ? "├L─" : "└R-" );
					if (node->m_color == RED)
						std::cout << "\x1b[47m" << "\x1b[31m";
					else if (node->m_color == BLACK)
						std::cout << "\x1b[47m" << "\x1b[30m";
					std::cout << node->m_value.first << "\x1b[0m" << std::endl ;
					print(display + (Left ? "│   " : "    "), node->left, true);
					print(display + (Left ? "│   " : "    "), node->right, false);
				}
			}

			void	left_rotation(NodeMap *x) {
				NodeMap *y = x->right;
				x->right = y->left;
				if (x->right)
					x->right->parent = x;
				y->parent = x->parent;
				if (y->parent == 0)
					racine = y;
				else if (x == y->parent->left)
					y->parent->left = y;
				else
					y->parent->right = y;
				y->left = x;
				x->parent = y;
			}
			void	right_rotation(NodeMap *x) {
				NodeMap *y = x->left;
				x->left = y->right;
				if (x->left)
					x->left->parent = x;
				y->parent = x->parent;
				if (y->parent == 0)
					racine = y;
				else if (x == y->parent->left)
					y->parent->left = y;
				else 
					y->parent->right = y;
				y->right = x;
				x->parent = y;
			}

			void	insertrules(NodeMap *z) {
				print();
				while (z != racine && z->m_color == RED && z->parent->m_color == RED) {
					NodeMap *parent = z->parent;
					NodeMap *grandpa = parent->parent;
					if (parent == grandpa->left) {
						NodeMap *uncle = grandpa->right;
						if (uncle && uncle->m_color == RED) {
							grandpa->m_color = RED;
							parent->m_color = BLACK;
							uncle->m_color = BLACK;
							z = grandpa;
						}
						else if (z == parent->right) {
							left_rotation(parent);
							z = parent;
							parent = z->parent;
						}
						else {
							right_rotation(grandpa);
							ft::m_swap(parent->m_color, grandpa->m_color);
						}
					}
					else if (parent == grandpa->right) {
						NodeMap *uncle = grandpa->left;
						if (uncle && uncle->m_color == RED) { 
							grandpa->m_color = RED;
							parent->m_color = BLACK;
							uncle->m_color = BLACK;
							z = grandpa;
						}
						else if (z == parent->left) { 
							right_rotation(parent);
							z = parent;
							parent = z->parent;
						}
						else {
							left_rotation(grandpa);
							ft::m_swap(parent->m_color, grandpa->m_color);
							z = parent;
						}
					}
				}
				racine->m_color = BLACK;
			}
	};
}

#endif