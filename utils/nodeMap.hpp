#ifndef NODEMAP
# define NODEMAP

namespace ft
{
	enum color {
		BLACK,
		RED
	};
	template<typename T, class Compare>
	class NodeMap
	{
		public:
		typedef T			value_type;
		typedef	T&			reference;
		public:
			value_type	m_value;
			NodeMap		*parent;
			NodeMap		*left;
			NodeMap		*right;
			color		m_color;
		public:
			explicit NodeMap(value_type const& val = value_type(), color color = RED):
				m_value(val), parent(0), left(0), right(0), m_color(color) { }
			NodeMap(const NodeMap& x):
				m_value(x.m_value), parent(x.parent), left(x.left), right(x.right), m_color(BLACK) {}
			~NodeMap() {}

			NodeMap*   getnext() {
        		NodeMap* next(this);
				if (next->right) {
					next = next->right;
					while (next->left)
						next = next->left;
				}
				else {
					NodeMap* tmp = next;
					next = next->parent;
					while (next->left != tmp) {
						tmp = next;
						next = next->parent;
					}
				}
				return (next);
        	}
			// NodeMap*   getprevious() {
			// 	setreferencenodes();
			// 	if (this == this->first_node || this == this->last_node)
			// 		return this->parent;
			// 	node* it(this);

			// 	if (it->left) {
			// 		it = it->left;
			// 		while (it->right)
			// 			it = it->right;
			// 	}
			// 	else
			// 		while (it->data >= this->data)
			// 			it = it->parent;
			// 	return (it);
			// }


			bool	operator==(const NodeMap& other) {
				return (m_value == other.m_value);
			}
			bool	operator!=(const NodeMap& other) {
				return (m_value != other.m_value);
			}
			bool	operator>(const NodeMap& other) {
				return (m_value > other.m_value);
			}
			bool	operator<(const NodeMap& other) {
				return (m_value < other.m_value);
			}
			bool 	operator<=(const NodeMap& other) {
				return (m_value <= other.m_value);
			}
			bool 	operator>=(const NodeMap& other) {
				return (m_value >= other.m_value);
			}
	};
}

#endif