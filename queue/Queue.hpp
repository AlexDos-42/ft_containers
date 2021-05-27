#ifndef QUEUE
# define QUEUE

# include "../list/List.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
		public:
			typedef	T									value_type;
			typedef	Container							container_type;
			typedef size_t  							size_type;
		public:
			Container q;

		public:
			explicit queue (const container_type& ctnr = container_type()): q(ctnr){}
			bool empty() const {
				return q.empty();
			}
			size_type size() const {
				return q.size();
			}
			value_type& front() {
				return q.front();
			}
			const value_type& front() const {
				return q.front();
			}
			value_type& back() {
				return q.back();
			}
			const value_type& back() const {
				return q.back();
			}
			void push (const value_type& val) {
				q.push_back(val);
			}
			void pop() {
				q.pop_front();
			}
	};
	template <class T, class Container>
	bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.q == rhs.q);
	}
	template <class T, class Container>
	bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.q != rhs.q);
	}
	template <class T, class Container>
	bool	operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.q < rhs.q);
	}
	template <class T, class Container>
	bool	operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.q <= rhs.q);
	}
	template <class T, class Container>
	bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.q > rhs.q);
	}
	template <class T, class Container>
	bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) {
		return (lhs.q >= rhs.q);
	}
};

#endif