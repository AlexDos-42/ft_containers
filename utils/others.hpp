#ifndef OTHERS_HPP
# define OTHERS_HPP

#include <cstddef>

namespace ft
{
	template<class X>
	void	m_swap(X &x, X &y) {
			X _tmp = x;
			x = y;
			y = _tmp;
	};
	
	template<typename InputIterator>
	size_t distance(InputIterator first, InputIterator last) {
		size_t diff = 0;
		while (first != last) {
			++diff;
			++first;
		}
		return diff;
	}

	template<bool Cond, class en = void>
	struct enable_if {};

	template<class en> 
	struct enable_if<true, en> {
		typedef en type;
	};
	template <class en> struct is_integral { 
		static const bool value = false;
	};
	template <> struct is_integral<bool> { 
		static const bool value = true;
	};
	template <> struct is_integral<char> {
		static const bool value = true;
	};
	template <> struct is_integral<short int> {
		static const bool value = true;
	};
	template <> struct is_integral<int> {
		static const bool value = true;
	};
	template <> struct is_integral<long int> {
		static const bool value = true;
	};
	template <> struct is_integral<long long int> {
		static const bool value = true;
	};
	template <> struct is_integral<unsigned char> {
		static const bool value = true;
	};
	template <> struct is_integral<unsigned short int> {
		static const bool value = true;
	};
	template <> struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template <> struct is_integral<unsigned long int> {
		static const bool value = true;
	};
	template <> struct is_integral<unsigned long long int> {
		static const bool value = true;
	};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 lhs_begin, InputIterator1 lhs_end,
		InputIterator2 rhs_begin, InputIterator2 rhs_end) {
		while (lhs_begin != lhs_end && rhs_begin != rhs_end) {
			if (*rhs_begin < *lhs_begin)
				return false;
			if (*lhs_begin < *rhs_begin)
				return true;
			++lhs_begin;
			++rhs_begin;
		}
		return (lhs_begin == lhs_end && rhs_begin != rhs_end);
	}

	struct input_iterator_tag {};
	struct output_iterator_tag : public input_iterator_tag {};
	struct forward_iterator_tag : public output_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Iterator>
    struct iterator_traits
    {
		typedef typename Iterator::iterator_category	iterator_category;
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
    };

    template <class T>
    struct iterator_traits<T*>
    {
		typedef random_access_iterator_tag		iterator_category;
        typedef ptrdiff_t                       difference_type;
		typedef ptrdiff_t						distance_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
    };

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef Category						iterator_category;
		typedef T								value_type;
		typedef Distance						difference_type;
		typedef Pointer							pointer;
		typedef Reference						reference;
	};
}

#endif