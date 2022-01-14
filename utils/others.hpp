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
	template <> struct is_integral<const bool> { 
		static const bool value = true;
	};
	template <> struct is_integral<const char> {
		static const bool value = true;
	};
	template <> struct is_integral<const short int> {
		static const bool value = true;
	};
	template <> struct is_integral<const int> {
		static const bool value = true;
	};
	template <> struct is_integral<const long int> {
		static const bool value = true;
	};
	template <> struct is_integral<const long long int> {
		static const bool value = true;
	};
	template <> struct is_integral<const unsigned char> {
		static const bool value = true;
	};
	template <> struct is_integral<const unsigned short int> {
		static const bool value = true;
	};
	template <> struct is_integral<const unsigned int> {
		static const bool value = true;
	};
	template <> struct is_integral<const unsigned long int> {
		static const bool value = true;
	};
	template <> struct is_integral<const unsigned long long int> {
		static const bool value = true;
	};
	
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); first1++, first2++ ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1))	return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
           InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
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