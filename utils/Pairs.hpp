#ifndef PAIRS
# define PAIRS
# include <utility>

namespace ft
{
	template<typename T1, typename T2>
	class pair {
		public:
		T1 first;
		T2 second;

		pair() : first(), second() {}
		pair(const pair& copy) : first(copy.first), second(copy.second) {}
		template<typename U, typename V>
		pair(const std::pair<U, V>& pr) : first(pr.first), second(pr.second) {}
		pair(const T1 &a, const T2 &b) : first(a), second(b) {}
		pair &operator=(const pair &copy) {
			if (this != &copy) {
				first = copy.first;
				second = copy.second;
			}
			return *this;
		}
		~pair() {}
	};
	template<typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}
}

#endif