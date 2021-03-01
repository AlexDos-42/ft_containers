#ifndef STACK
# define STACK

# include "List.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class stack
	{
		public:
		Container s;

		public:
        explicit stack (const Container& ctnr = Container()): q(ctnr){}
		bool empty() const {
			return s.empty();
		}
		size_t size() const {
			return s.size();
		}
		T& front() {
			return s.front();
		}
		const T& front() const {
			return s.front();
		}
		T& back() {
			return s.back();
		}
		const T& back() const {
			return s.back();
		}
		void push (const T& val) {
			s.push_front(val);
		}
		// template <class... Args> void emplace (Args&&... args);
		void pop() {
			s.pop_back();
		}
		// void swap (queue& x) noexcept(/*see below*/);
	};
};

#endif