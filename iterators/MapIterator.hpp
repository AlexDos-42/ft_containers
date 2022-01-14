#pragma once

# include <memory>
# include <cstddef>

#include "../utils/nodeMap.hpp"
#include "../utils/others.hpp"

namespace ft
{
	template < class Pair >
	class MapIterator: ft::iterator<ft::bidirectional_iterator_tag, Pair>
	{
		public:
			typedef Pair					value_type;
			typedef	Pair&					reference;
			typedef Pair*					pointer;
			typedef	ptrdiff_t				difference_type;
			typedef	size_t					size_type;

			NodeMap<value_type>	*m_node;
			NodeMap<value_type>	*m_parentNode;

			MapIterator(): m_node(nullptr), m_parentNode(nullptr)  {}
			MapIterator(NodeMap<value_type>	*n, NodeMap<value_type>	*pN): m_node(n), m_parentNode(pN)  {}
			MapIterator(const MapIterator& ref): m_node(ref.m_node), m_parentNode(ref.m_parentNode)  {}
			~MapIterator() {}
			MapIterator& operator=(const MapIterator& ref) {
				if (this == &ref)
					return *this;
				m_node = ref.m_node;
				m_parentNode = ref.m_parentNode;
				return *this;
			}
		
			MapIterator	&operator++() {
				if (m_node == m_parentNode->right)
					m_node = m_parentNode;
				else if (!(m_node->right->leaf())) {
					m_node = m_node->right;
					while (!(m_node->left->leaf()))
						m_node = m_node->left;
				}
				else {
					while (m_node->parent && m_node == m_node->parent->right)
						m_node = m_node->parent;
					if (m_node->parent)
						m_node = m_node->parent;
				}
				return (*this);
			}
			MapIterator	&operator--() {
				if (m_node == m_parentNode)
					m_node = m_parentNode->right;
				else if (!(m_node->left->leaf())) {
					m_node = m_node->left;
					while (!(m_node->right->leaf()))
						m_node = m_node ->right;
				}
				else {
					while (m_node->parent && m_node == m_node->parent->left)
						m_node = m_node->parent;
					if (m_node->parent)
						m_node = m_node->parent;
				}
				return(*this);
			}
			MapIterator	operator++(int) {
				MapIterator	tmp(*this);
				operator++();
				return tmp;
			}
			MapIterator	operator--(int) {
				MapIterator	tmp(*this);
				operator--();
				return tmp;
			}
			pointer operator->() const {
				return &(m_node->pair);
			}
			reference operator*() const {
				return (*&(m_node->pair));
			}
			
			friend bool	operator==(const MapIterator &it, const MapIterator &ite) {
				return (it.m_node == ite.m_node);
			}
			friend bool	operator!=(const MapIterator &it, const MapIterator &ite) {
				return (it.m_node != ite.m_node);
			}
	};

	template < class Pair >
	class ConstMapIterator
	{
		public:
			typedef Pair					value_type;
			typedef	const Pair&					reference;
			typedef const Pair*					pointer;
			typedef	ptrdiff_t				difference_type;
			typedef	size_t					size_type;
			
			NodeMap<value_type>	*m_node;
			NodeMap<value_type>	*m_parentNode;

			ConstMapIterator(): m_node(nullptr), m_parentNode(nullptr)  {}
			ConstMapIterator(NodeMap<value_type>	*n, NodeMap<value_type>	*pN): m_node(n), m_parentNode(pN)  {}
			ConstMapIterator(const MapIterator<value_type>& ref): m_node(ref.m_node), m_parentNode(ref.m_parentNode)  {}
			~ConstMapIterator() {}
			ConstMapIterator& operator=(ConstMapIterator const &ref) {
				if (this == &ref)
					return *this;
				m_node = ref.m_node;
				m_parentNode = ref.m_parentNode;
				return *this;
			}
		
			ConstMapIterator	&operator++() {
				if (m_node == m_parentNode->right)
					m_node = m_parentNode;
				else if (!(m_node->right->leaf())) {
					m_node = m_node->right;
					while (!(m_node->left->leaf()))
						m_node = m_node->left;
				}
				else {
					while (m_node->parent && m_node == m_node->parent->right)
						m_node = m_node->parent;
					if (m_node->parent)
						m_node = m_node->parent;
				}
				return (*this);
			}
			ConstMapIterator	&operator--() {
				if (m_node == m_parentNode)
					m_node = m_parentNode->right;
				else if (!(m_node->left->leaf())) {
					m_node = m_node->left;
					while (!(m_node->right->leaf()))
						m_node = m_node ->right;
				}
				else {
					while (m_node->parent && m_node == m_node->parent->left)
						m_node = m_node->parent;
					if (m_node->parent)
						m_node = m_node->parent;
				}
				return(*this);
			}
			ConstMapIterator	operator++(int) {
				ConstMapIterator	tmp(*this);
				operator++();
				return (tmp);
			}
			ConstMapIterator	operator--(int) {
				ConstMapIterator	tmp(*this);
				operator--();
				return tmp;
			}
			pointer operator->() const {
				return &(m_node->pair);
			}
			reference operator*() const {
				return (*&(m_node->pair));
			}
			
			friend bool	operator==(const ConstMapIterator &it, const ConstMapIterator &ite) {
				return (it.m_node == ite.m_node);
			}
			friend bool	operator!=(const ConstMapIterator &it, const ConstMapIterator &ite) {
				return (it.m_node != ite.m_node);
			}
	};

	template <class Iterator>
	class	reverse_iterator {
		public:
			typedef	Iterator						iterator_type;
			typedef typename Iterator::value_type		value_type;
			typedef typename Iterator::difference_type	difference_type;
			typedef typename Iterator::reference		reference;
			typedef typename Iterator::pointer			pointer;
			typedef typename Iterator::size_type		size_type;

			Iterator	m_it;

			reverse_iterator() : m_it() {};
			reverse_iterator(Iterator it) : m_it(it) {};
			template <class U>
			reverse_iterator(const reverse_iterator<U>& other) : m_it(other.m_it) {};
			~reverse_iterator() {};

			template<class U>
			reverse_iterator& operator=(const reverse_iterator<U> &other) {
				if (this == &other)
					return *this;
				m_it = other.m_it;
				return *this;
			};
			iterator_type	base() const{
				return m_it;
			};
			reference	operator*() const {
				iterator_type tmp = m_it;
				return *(--tmp);
			};
			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(m_it - n);
			};
			reverse_iterator&	operator++(void) {
				--m_it;
				return *this;
			};
			reverse_iterator	operator++(int)	{
				reverse_iterator	tmp = *this;
				++(*this);
				return tmp;
			};
			reverse_iterator	operator+=(difference_type n) {
				m_it -= n;
				return *this;
			};
			reverse_iterator	operator-(difference_type n) const {
				return reverse_iterator(m_it + n);
			};
			reverse_iterator&	operator--() {
				++m_it;
				return *this;
			};
			reverse_iterator	operator--(int) {
				reverse_iterator	tmp = *this;
				--(*this);
				return tmp;
			};
			reverse_iterator	operator-=(difference_type n) {
				m_it += n;
				return *this;
			};
			pointer		operator->(void) const {
				return &(operator*());
			};
			reference	operator[](difference_type n) const {
				return m_it[-n - 1];
			};
	};

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs,  const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	};
	template <class Iterator_L, class Iterator_R>
	bool operator!=(const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs) {
		return lhs.base() != rhs.base();
	};
	template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	};
	template <class Iterator_L, class Iterator_R>
	bool operator<(const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs) {
		return lhs.base() > rhs.base();
	};
	template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	};
	template <class Iterator_L, class Iterator_R>
    bool operator<=(const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs) {
		return lhs.base() >= rhs.base();
	};
	template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.bash();
	};
	template <class Iterator_L, class Iterator_R>
    bool operator>(const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs) {
		return lhs.base() < rhs.base();
	};
	template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();
	};
	template <class Iterator_L, class Iterator_R>
    bool operator>=(const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs) {
		return lhs.base() <= rhs.base();
	};
	template <class Iterator>
    reverse_iterator<Iterator>operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	};
	template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	};
};