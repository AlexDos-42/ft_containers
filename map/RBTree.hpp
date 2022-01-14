#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include <cstdio>
#include "../utils/nodeMap.hpp"
#include "../utils/Pairs.hpp"
#include "../iterators/MapIterator.hpp"

namespace	ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class	RBTree
	{
		public:

			typedef	Key									key_type;
			typedef	T									mapped_type;
			typedef pair<const Key, T>					value_type;
			typedef	size_t								size_type;
			typedef	ptrdiff_t							difference_type;
			typedef Compare								key_compare;
			typedef	Allocator							allocator_type;
			typedef	typename Allocator::reference		reference;
			typedef	typename Allocator::const_reference	const_reference;
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer	const_pointer;
			typedef	MapIterator<value_type>					iterator;
			typedef ConstMapIterator<value_type>			const_iterator;
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	NodeMap<value_type>						node;
			typedef typename Allocator::template rebind<node>::other alloc;

		private:
			key_compare		m_comp;
			node			*m_parentNode;
			size_type		m_count;
			alloc			_alloc;

			node 	*m_root(void) const {
				return (m_parentNode->parent);
			}
			node	*m_left(void) const {
				return (m_parentNode->left);
			}
			node	*m_right(void) const {
				return (m_parentNode->right);
			}

		public:
		
			RBTree(const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type())
				: m_comp(comp), m_count(0) {
				(void)alloc;
				m_parentNode = _alloc.allocate(1);
				_alloc.construct(m_parentNode, value_type());
				m_parentNode->m_color = RED;
				m_parentNode->parent = NULL;
				m_parentNode->left = m_parentNode;
				m_parentNode->right = m_parentNode;
			}
			~RBTree(void) {
				destructor_helper(m_root());
				_alloc.destroy(m_parentNode);
				_alloc.deallocate(m_parentNode, 1);
			}

			node	*newNode(const value_type &p, color c) {
				node	*res = _alloc.allocate(1);
				node	*nodeleft = _alloc.allocate(1);
				node	*noderight = _alloc.allocate(1);

				_alloc.construct(res, p);
				_alloc.construct(nodeleft, value_type());
				_alloc.construct(noderight, value_type());

				res->parent = NULL;
				nodeleft->parent = res;
				noderight->parent = res;

				res->left = nodeleft;
				res->right = noderight;
				//nodeleft->left = NULL;
				//nodeleft->right = NULL;
				// noderight->left = NULL;
				// noderight->right = NULL;

				res->m_color = c;
				nodeleft->m_color = BLACK;
				noderight->m_color = BLACK;

				return (res);
			}

			node	*search_node(const key_type k) const {
				node	*n = m_root();
				while (!n->leaf()) {
					int	comp_result = m_comp(k, n->pair.first);
					if (comp_result == false && !m_comp(n->pair.first, k))
						return (n);
					else if (comp_result == true)
						n = n->left;
					else
						n = n->right;
				}
				return (NULL);
			}

			void 	replace_node(node *oldn, node *newn) {
				if (oldn->parent == NULL)
					m_parentNode->parent = newn;
				else
					if (oldn == oldn->parent->left)
						oldn->parent->left = newn;
					else
						oldn->parent->right = newn;
				newn->parent = oldn->parent;
			}

			void 	left_rotate(node *n) {
				node	*r = n->right;
				replace_node(n, r);
				n->right = r->left;
				if (r->left != NULL)
					r->left->parent = n;
				r->left = n;
				n->parent = r;
			}

			void 	right_rotate(node *n) {
				node	*L = n->left;
				replace_node(n, L);
				n->left = L->right;
				if (L->right != NULL)
					L->right->parent = n;
				L->right = n;
				n->parent = L;
			}

		/*Insertion: https://iq.opengenus.org/red-black-tree-insertion/ */

			pair<iterator, bool> 	insert(const value_type &p) {
				node	*inserted_node = newNode(p, RED);
				if (m_root() == NULL) {
					m_parentNode->parent = inserted_node;
					m_parentNode->right = inserted_node;
					m_parentNode->left = inserted_node;
				}
				else {
					node	*n = m_root();
					while (1) {
						int		result = m_comp(p.first, n->pair.first);
						if (result == false && !m_comp(n->pair.first, p.first)) {
							destructor_helper(inserted_node);
							return (ft::make_pair(iterator(n, m_parentNode), false));
						}
						else if (result == true) {
							if (n->left->leaf()) {
								_alloc.destroy(n->left);
								_alloc.deallocate(n->left, 1);
								n->left = inserted_node;
								break ;
							}
							else
								n = n->left;
						}
						else {
							if (n->right->leaf()) {
								_alloc.destroy(n->right);
								_alloc.deallocate(n->right, 1);
								n->right = inserted_node;
								break ;
							}
							else
								n = n->right;
						}
					}
					inserted_node->parent = n;
					if (n == m_right() && inserted_node == n->right)
						m_parentNode->right = inserted_node;
					else if (n == m_left() && inserted_node == n->left)
						m_parentNode->left = inserted_node;
				}
				insert_case1(inserted_node);
				m_count++;
				return (ft::make_pair(iterator(inserted_node, m_parentNode), true));
			}

			void 	insert_case1(node *n) {
				if (n->parent == NULL)
					n->m_color = BLACK;
				else
					insert_case2(n);
			}

			void 	insert_case2(node *n) {
				if (n->parent->m_color == BLACK)
					return ;
				else
					insert_case3(n);
			}

			void 	insert_case3(node *n) {
				if (n->uncle() != NULL && n->uncle()->m_color == RED) {
					n->parent->m_color = BLACK;
					n->uncle()->m_color = BLACK;
					n->grandparent()->m_color = RED;
					insert_case1(n->grandparent());
				}
				else
					insert_case4(n);
			}

			void 	insert_case4(node *n) {
				if (n == n->parent->right && n->parent == n->grandparent()->left) {
					left_rotate(n->parent);
					n = n->left;
				}
				else if (n == n->parent->left && n->parent == n->grandparent()->right) {
					right_rotate(n->parent);
					n = n->right;
				}
				insert_case5(n);
			}

			void 	insert_case5(node *n) {
				n->parent->m_color = BLACK;
				n->grandparent()->m_color = RED;
				if (n == n->parent->left && n->parent == n->grandparent()->left)
					right_rotate(n->grandparent());
				else if (n == n->parent->right && n->parent == n->grandparent()->right)
					left_rotate(n->grandparent());
			}

		/* Deletion: https://www.youtube.com/watch?v=eO3GzpCCUSg */

			void 	delete_node(node *n) {
				if (n == NULL || n->leaf())
					return ;
				color	n_color = n->m_color;
				node	*replacement;
				node	*x;

				if (m_count == 1) {
					delete_last(n);
					return ;
				}
				if (n == m_left()) {
					m_parentNode->left = n->parent;
					if (n == m_root())
						m_parentNode->left = n->right;
				}
				else if (n == m_right()) {
					m_parentNode->right = n->parent;
					if (n == m_root())
						m_parentNode->right = n->left;
				}

				if (n->left->leaf() && n->right->leaf()) {
					replacement = x = n->right;
					_alloc.destroy(n->left);
					_alloc.deallocate(n->left, 1);
				}
				else if (!n->left->leaf() && n->right->leaf()) {
					replacement = x = n->left;
					_alloc.destroy(n->right);
					_alloc.deallocate(n->right, 1);
				}
				else if (!n->right->leaf() && n->left->leaf()) {
					replacement = x = n->right;
					_alloc.destroy(n->left);
					_alloc.deallocate(n->left, 1);
				}
				else {
					replacement = n->right;
					while (!replacement->left->leaf())
						replacement = replacement->left;
					x = replacement->right;
				}
				delete_and_replace(n, replacement, x);
				initial_step2(replacement, x, n_color);
				m_count--;
				if (m_count == 0) {
					m_parentNode->left = m_parentNode;
					m_parentNode->right = m_parentNode;
				}
			}

			
			void	delete_last(node *n) {
				_alloc.destroy(n->left);
				_alloc.deallocate(n->left, 1);
				_alloc.destroy(n->right);
				_alloc.deallocate(n->right, 1);
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
				m_parentNode->parent = NULL;
				m_parentNode->left = m_parentNode;
				m_parentNode->right = m_parentNode;
				m_count--;
			}

			void 	delete_and_replace(node *n, node *replacement, node *x) {
				if (replacement->leaf() && x->leaf())
					replace_node(n, replacement);
				else if (replacement == x)
					replace_node(n, replacement);
				else {
					replace_node(replacement, x);
					replace_node(n, replacement);
					_alloc.destroy(replacement->left);
					_alloc.deallocate(replacement->left, 1);
					replacement->left = n->left;
					replacement->right = n->right;
					replacement->left->parent = replacement;
					replacement->right->parent = replacement;
				}
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
			}

			void 	initial_step2(node *replacement, node *x, color n_color) {
				if (n_color == RED) {
					if (replacement->leaf() || replacement->m_color == RED)
						return ;
					else
						replacement->m_color = RED;
				}
				else if (n_color == BLACK && (!replacement->leaf() && replacement->m_color == RED)) {
					replacement->m_color = BLACK;
					return ;
				}
				choose_case(x);
			}

			void 	choose_case(node *x) {
				node	*w = x->sibling();
				if (x->m_color == RED)
					delete_case0(x);
				else if (w != NULL) {
					if (w->m_color == RED)
						delete_case1(x, w);
					else {
						if (w->left->m_color == BLACK && w->right->m_color == BLACK)
							delete_case2(x, w);
						else if ((x == x->parent->left && w->right->m_color == RED)
							|| (x == x->parent->right && w->left->m_color == RED))
							delete_case4(x, w);
						else
							delete_case3(x, w);
					}
				}
			}

			void 	delete_case0(node *x) {
				x->m_color = BLACK;
			}

			void 	delete_case1(node *x, node *w) {
				w->m_color = BLACK;
				x->parent->m_color = RED;
				if (x == x->parent->left)
					left_rotate(x->parent);
				else
					right_rotate(x->parent);
				choose_case(x);
			}

			void 	delete_case2(node *x, node *w) {
				w->m_color = RED;
				x = x->parent;
				if (x->m_color == RED)
					x->m_color = BLACK;
				else
					choose_case(x);
			}

			void 	delete_case3(node *x, node *w) {
				w->m_color = RED;
				if (x == x->parent->left) {
					w->left->m_color = BLACK;
					right_rotate(w);
				}
				else {
					w->right->m_color = BLACK;
					left_rotate(w);
				}
				w = x->sibling();
				delete_case4(x, w);
			}

			void 	delete_case4(node *x, node *w) {
				w->m_color = x->parent->m_color;
				x->parent->m_color = BLACK;
				if (x == x->parent->left)
				{
					w->right->m_color = BLACK;
					left_rotate(x->parent);
				}
				else
				{
					w->left->m_color = BLACK;
					right_rotate(x->parent);
				}
			}

			iterator		begin() {
				return (iterator(m_left(), m_parentNode));
			}

			const_iterator	begin() const {
				return (const_iterator(m_left(), m_parentNode));
			}

			iterator		end() {
				return(iterator(m_parentNode, m_parentNode));
			}

			const_iterator	end() const {
				return(const_iterator(m_parentNode, m_parentNode));
			}

			void 	clear() {
				destructor_helper(m_root());
				m_parentNode->right = m_parentNode;
				m_parentNode->left = m_parentNode;
				m_parentNode->parent = NULL;
				m_count = 0;
			}

			void 	destructor_helper(node *n) {
				if (n == NULL)
					return ;
				if (n->right != NULL)
					destructor_helper(n->right);
				if (n->left != NULL)
					destructor_helper(n->left);
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
			}

			void 	swap(RBTree& other) {
				size_type		tmp_m_count;
				node			*tmp_m_parentNode;

				tmp_m_count = other.m_count;
				other.m_count = m_count;
				m_count = tmp_m_count;

				tmp_m_parentNode = other.m_parentNode;
				other.m_parentNode = m_parentNode;
				m_parentNode = tmp_m_parentNode;
			}

			iterator	find(const Key &key) {
				node *n = search_node(key);

				if (n == NULL)
					return (end());
				else
					return (iterator(n, m_parentNode));
			}

			const_iterator	find(const Key& key) const {
				node *n = search_node(key);

				if (n == NULL)
					return (end());
				else
					return (const_iterator(n, m_parentNode));
			}

			iterator		lower_bound(const Key& key) {
				for (iterator it = begin(); it != end(); it++)
					if (m_comp((*it).first, key) == false)
						return (it);
				return (end());
			}

			const_iterator	lower_bound(const Key& key) const {
				for (const_iterator it = begin(); it != end(); it++)
					if (m_comp((*it).first, key) == false)
						return (it);
				return (end());
			}

			iterator		upper_bound(const Key& key) {
				for (iterator it = begin(); it != end(); it++)
					if (m_comp((*it).first, key) == false) {
						if (m_comp(key, (*it).first) == false)
							return (++it);
						else
							return (it);
					}
				return (end());
			}

			const_iterator		upper_bound(const Key& key) const {
				for (const_iterator it = begin(); it != end(); it++)
					if (m_comp((*it).first, key) == false) {
						if (m_comp(key, (*it).first) == false)
							return (++it);
						else
							return (it);
					}
				return (end());
			}

			size_type		max_size() const {
				return _alloc.max_size();
			}

			allocator_type	get_allocator() const 	{
				return allocator_type();
			}

			void print_tree_helper(node *n, int indent) {
				int i;
				if (n == NULL) {
					fputs("<empty tree>", stdout);
					return;
				}
				if (n->right != NULL) 
					print_tree_helper(n->right, indent + 4);
				for(i = 0; i < indent; i++) {
					fputs(" ", stdout);
				}
				if (n->leaf())
					std::cout << "L" << std::endl;
				else if (n->m_color == BLACK)
					std::cout << "\x1b[47m" << "\x1b[30m" << n->pair->first;
				else
					std::cout << "\x1b[47m" << "\x1b[31m" << n->pair->first;
				std::cout << "\x1b[0m" << std::endl;
				if (n->left != NULL)
					print_tree_helper(n->left, indent + 4);
			}

			void print_tree() {
				print_tree_helper(m_root(), 0);
				puts("");
			}

			size_type		get_size(void) const {
				return (m_count);
			}
	};
};

#endif