#ifndef NODEMAP
# define NODEMAP

namespace ft
{
	enum color {
		BLACK,
		RED
	};
	template<class T, class Compare>
	class NodeMap
	{
		public:
			T			m_value;
			NodeMap		*parent;
			NodeMap		*left;
			NodeMap		*right;
			color		m_color;
		public:
			explicit NodeMap(T const& val = T(), color color = RED) : m_value(val), parent(0), left(0), right(0), m_color(color) { }
			NodeMap(const NodeMap& x) : m_value(x.m_value), parent(x.parent), left(x.left), right(x.right), m_color(BLACK) {}
			~NodeMap() {}
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