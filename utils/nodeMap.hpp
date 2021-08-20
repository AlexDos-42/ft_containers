#ifndef NODEMAP_HPP
# define NODEMAP_HPP

namespace ft
{
	enum color {
		BLACK,
		RED
	};

	template<class Pair>
	class NodeMap
	{
		public:
			NodeMap		*parent;
			NodeMap		*left;
			NodeMap		*right;
			color		m_color;
			Pair		*pair;

		public:
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