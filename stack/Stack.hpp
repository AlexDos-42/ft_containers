#ifndef STACK
# define STACK

# include "../vector/Vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef	T									value_type;
			typedef	Container							container_type;
			typedef size_t  							size_type;
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
				s.push_front(val);
			}
			void pop() {
				s.pop_back();
			}
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.s == rhs.s);
	}
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.s != rhs.s);
	}
	template <class T, class Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.s < rhs.s);
	}
	template <class T, class Container>
	bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.s <= rhs.s);
	}
	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.s > rhs.s);
	}
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.s >= rhs.s);
	}
};

#endif