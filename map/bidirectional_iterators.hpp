#ifndef BIDIRECTIONAL_ITERATORS_HPP
#define BIDIRECTIONAL_ITERATORS_HPP
#include <iostream>
#include <map>
#include "./avl.hpp"
#include "../utils/pair.hpp"

namespace ft
{
    template <typename T, typename Node, typename Avl>
	class iterator // bidirectional_iterator
	{
		public:
			typedef	iterator						iterator_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef	value_type*						pointer;
			typedef const pointer					const_pointer;
			typedef	value_type&						reference;

		public:
			Avl		_avl;
			Node*	_node;
			Node*	_root;

		public:
			// construct && destruct
			iterator() : _avl(), _node(NULL), _root(NULL) {};
			iterator(Node* node, Node* root) : _avl(), _node(node), _root(root) {};
			~iterator() {};
			iterator	operator = (const iterator &x)
			{
				this->_node = x._node;
				this->_root = x._root;
				return (*this);
			}

			// overload
			bool operator == ( const iterator& x ) {
				return (this->_node == x._node);
			}
			bool operator != ( const iterator& x ) {
				return (this->_node != x._node);
			}
			reference operator * () {
				return (this->_node->data);
			}
			pointer operator -> () {
				return (&this->_node->data);
			}
			const_pointer operator -> () const {
				return (&this->_node->data);
			}
			iterator& operator ++ () {
				this->_node = _avl.incrementation(_root, _node);
				return (*this);
			}
			iterator operator ++ (int) {
				
				iterator _old = *this;
				this->_node = _avl.incrementation(_root, _node);
				return _old;
			}
			iterator operator--()
            {
                this->_node = _avl.decrementation(_root, _node);
                return (*this);
            }
			iterator operator-- (int) {
				iterator _old = *this;
				operator--();
				return _old;
			}
	};
};


#endif