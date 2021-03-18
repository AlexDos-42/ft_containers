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
				racine->left = NULL;
				racine->right = NULL;
				racine->parent = NULL;
				racine->m_color = BLACK;
			}
			//template <class InputIterator>
			//map (iterator first, iterator last, const Compare& comp = Compare(), const Alloc& _allocator = Alloc());
			map (const map& x);
			~map() {
				clear(racine);
			//	delete racine;
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
				racine = new NodeMap();
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
				// fixRedBlackViolations(insert);
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
				// fixRedBlackViolations(insert);
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

	};
}

#endif