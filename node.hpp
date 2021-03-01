#ifndef NODE
# define NODE

namespace ft
{
	template<class T>
	class Node
	{
		public:
			Node<T>	*m_next;
			Node<T>	*m_back;
			T		m_value;
		public:
			Node(): m_value() {
				initLink(nullptr, nullptr);
			}
			Node(const T &val): m_value(val) {
				initLink(nullptr, nullptr);
			}
			~Node() {}
			Node(Node<T> &copy): m_back(copy.m_back), m_next(copy.m_next), m_value(copy.m_value) {}
			Node &operator=(Node const &copy) {
				m_back = copy.m_back;
				m_next = copy.m_next;
				m_value = copy.m_value;
				return (*this);
			}
			
			void	initLink(Node *back, Node *next) {
				m_back = back;
				m_next = next;
			}
			Node*	getNext() {
			return this->m_next;
			}
			Node*	getBack() {
				return this->m_back;
			}
			T	getValue(){
				return this->m_value;
			}
	};
}

#endif