#pragma once

#include "./pair.hpp"
#include "./others.hpp"

namespace ft
{
	enum color {
		BLACK,
		RED
	};

	template<class T>
	class NodeMap {
		public:
			typedef T	value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef ft::bidirectional_iterator_tag	iterator_category;

			NodeMap		*parent;
			NodeMap		*left;
			NodeMap		*right;
			color		m_color;

		public:
			value_type		pair;
			NodeMap() {}
			NodeMap(value_type newPair):
				 parent(NULL), left(NULL), right(NULL), m_color(BLACK), pair(newPair) {}
			NodeMap		*grandparent() {
				if (parent == NULL)
					return NULL;
				return (parent->parent);
			}

			NodeMap		*sibling() {
				if (parent == NULL)
					return NULL;
				if (this == parent->left)
					return (parent->right);
				else
					return (parent->left);
			}

			NodeMap		*uncle() {
				if (parent == NULL)
					return NULL;
				if (grandparent() == NULL)
					return NULL;
				return (parent->sibling());
			}

			bool		leaf() {
				if (left == NULL && right == NULL)
					return (true);
				else
					return (false);
			}
	};
}