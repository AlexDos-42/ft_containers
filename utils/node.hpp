#ifndef NODE
# define NODE

namespace ft
{
	template<class T,  class Alloc = std::allocator<T> >
	class Node
	{
		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef Node<value_type, Alloc>*		node;
			typedef typename allocator_type::pointer 	pointer;
			typedef typename allocator_type::reference	reference;
		public:
			node m_next;
			node m_back;
			pointer		m_value;
		public:
			Node(const value_type &val, allocator_type& alloc = allocator_type()) {
				m_value = alloc.allocate(1);
				alloc.construct(m_value, val);
				initLink(nullptr, nullptr);
			}
			~Node() {
				allocator_type		alloc;
				alloc.destroy(m_value);
				alloc.deallocate(m_value, 1);
			}
			
			void	initLink(node back, node next) {
				m_back = back;
				m_next = next;
			}
			node	getNext() {
				return this->m_next;
			}
			node	getBack() {
				return this->m_back;
			}
			value_type	getValue(){
				return this->m_value;
			}
			node	insert(node m_back, node m_next){
				m_next = m_back->m_next;
				m_back->m_next = this;
				m_back = m_next->m_back;
				m_next->m_back = this;
				return this;
			}
	};
}

#endif