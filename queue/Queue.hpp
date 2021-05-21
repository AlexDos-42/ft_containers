#ifndef QUEUE
# define QUEUE

# include "../list/List.hpp"

// To do: relational operators

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
		public:
		Container q;

		public:
        explicit queue (const Container& ctnr = Container()): q(ctnr){}
		bool empty() const {
			return q.empty();
		}
		size_t size() const {
			return q.size();
		}
		T& front() {
			return q.front();
		}
		const T& front() const {
			return q.front();
		}
		T& back() {
			return q.back();
		}
		const T& back() const {
			return q.back();
		}
		void push (const T& val) {
			q.push_back(val);
		}
		void pop() {
			q.pop_front();
		}
	};
	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
};

#endif