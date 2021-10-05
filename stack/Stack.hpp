#ifndef STACK
# define STACK

# include "../vector/Vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container                                container_type;
			typedef typename container_type::value_type      value_type;
			typedef typename container_type::reference       reference;
			typedef typename container_type::const_reference const_reference;
			typedef typename container_type::size_type       size_type;
		private:
			Container s;

		public:
			explicit stack (const container_type& ctnr = container_type()): s(ctnr){}
			bool empty() const {
				return s.empty();
			}
			size_type size() const {
				return s.size();
			}
			value_type& top() {
				return s.back();
			}
			const value_type& top() const {
				return s.back();
			}
			void push (const value_type& val) {
				s.push_back(val);
			}
			void pop() {
				s.pop_back();
			}
			Container getS() const{
				return s;
			}
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.getS() == rhs.getS());
	}
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.getS() != rhs.getS());
	}
	template <class T, class Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.getS() < rhs.getS());
	}
	template <class T, class Container>
	bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.getS() <= rhs.getS());
	}
	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.getS() > rhs.getS());
	}
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.getS() >= rhs.getS());
	}
};

#endif