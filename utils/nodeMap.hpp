#ifndef NODEMAP
# define NODEMAP

namespace ft
{
	enum color {
		BLACK,
		RED
	};
	template<class T>
	class NodeMap
	{
		public:
			T			m_value;
			NodeMap		*parent;
			NodeMap		*left;
			NodeMap		*right;
			color		m_color;
		private:
			explicit NodeMap(T const& val = T(), color color = RED) : m_value(val), parent(0), left(0), right(0), colour(kleur) { }
			NodeMap(const NodeMap& x) : m_value(x.m_value), parent(x.parent), left(x.left), right(x.right), m_color(RED) {}
			~node() {}
			bool	operator==(const node& other) {
				return (m_value == other.m_value);
			}
			bool	operator!=(const node& other) {
				return (m_value != other.m_value);
			}
			bool	operator>(const node& other) {
				return (m_value > other.m_value);
			}
			bool	operator<(const node& other) {
				return (m_value < other.m_value);
			}
			bool 	operator<=(const node& other) {
				return (m_value <= other.m_value);
			}
			bool 	operator>=(const node& other) {
				return (m_value >= other.m_value);
			}
	};
}

#endif