#ifndef NODEMAP_HPP
# define NODEMAP_HPP

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
			value_type		*pair;

		public:
			NodeMap(value_type newPair):
				pair(newPair), m_color(BLACK), parent(NULL), left(NULL), right(NULL) {}
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
				if (pair == nullptr)
					return (true);
				else
					return (false);
			}
	};
}

#endif