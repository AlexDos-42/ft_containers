#pragma once

#include "./Pairs.hpp"
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
				if (parent == nullptr)
					return nullptr;
				return (parent->parent);
			}

			NodeMap		*sibling() {
				if (parent == nullptr)
					return nullptr;
				if (this == parent->left)
					return (parent->right);
				else
					return (parent->left);
			}

			NodeMap		*uncle() {
				if (parent == nullptr)
					return nullptr;
				if (grandparent() == nullptr)
					return nullptr;
				return (parent->sibling());
			}

			bool		leaf() {
				if (left == nullptr && right == nullptr)
					return (true);
				else
					return (false);
			}
	};
}