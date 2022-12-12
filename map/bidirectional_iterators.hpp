#ifndef BIDIRECTIONAL_ITERATORS_HPP
#define BIDIRECTIONAL_ITERATORS_HPP
#include <iostream>
#include <map>
#include "./avl.hpp"
#include "../utils/pair.hpp"

namespace ft
{
	template<typename T, typename Node, typename Avl>
	class const_iterator;
    template <typename T, typename Node, typename Avl>
	class iterator // bidirectional_iterator
	{
		public:
			typedef	iterator						iterator_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;

		public:
			Avl		*_avl;
			Node*	_node;
			Node*	_root;

		public:
			// construct && destruct
			iterator() : _node(NULL), _root(NULL), _avl() {};
			iterator( Node* node, Node* root, Avl *avl) : _node(node), _root(root), _avl(avl) {};
			~iterator() {};
			iterator	operator = (const iterator &x)
			{
				this->_node = x._node;
				this->_root = x._root;
				this->_avl = x._avl;
				return (*this);
			}

				operator const_iterator<value_type,Node, Avl>(){

            return const_iterator<value_type,Node, Avl>(this->_node, this->_root, this->_avl);
        }

			// overload
			bool operator == ( const iterator& x ) const
			{
				return (this->_node == x._node);
			}
			bool operator != ( const iterator& x ) const
			{
				return (this->_node != x._node);
			}
			reference operator * () const
			{
				return (this->_node->data);
			}
			pointer operator -> () {
				return (&this->_node->data);
			}
			iterator& operator ++ () {
				this->_node = _avl->incrementation(_root, _node);
				return (*this);
			}
			iterator operator ++ (int) {
				
				iterator _old = *this;
				this->_node = _avl->incrementation(_root, _node);
				return _old;
			}
			iterator operator--()
            {
                this->_node = _avl->decrementation(_root, _node);
                return (*this);
            }
			iterator operator-- (int) {
				iterator _old = *this;
				operator--();
				return _old;
			}
	};

	template <typename T, typename Node, typename Avl>
	class const_iterator // bidirectional_iterator
	{
		public:
			typedef	const_iterator						iterator_type;
			typedef	std::bidirectional_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef	const value_type*						pointer;
			typedef	const value_type&						reference;

		public:
			const Avl		*_avl;
			const Node* 	_node;
			Node* 	_root;

		public:
			// construct && destruct
			const_iterator() : _node(NULL), _root(NULL), _avl() {};
			const_iterator(const Node* node, Node* root, Avl *avl) : _node(node), _root(root), _avl(avl) {};
			~const_iterator() {};
			const_iterator	operator = (const const_iterator &x)
			{
				this->_node = x._node;
				this->_root = x._root;
				this->_avl = x._avl;
				return (*this);
			}

			// overload
			bool operator == ( const const_iterator& x ) const 
			{
				return (this->_node == x._node);
			}
			bool operator != ( const const_iterator& x )  const
			{
				return (this->_node != x._node);
			}
			reference operator * () const
			{
				return (this->_node->data);
			}
			pointer operator -> () const
			{
				return (&this->_node->data);
			}
			
			const_iterator& operator ++ () 
			{
				this->_node = _avl->incrementation(_root, _node);
				return (*this);
			}
			const_iterator operator ++ (int)
			{
				const_iterator _old = *this;
				this->_node = _avl->incrementation(_root, _node);
				return _old;
			}
			const_iterator operator--() 
            {
                this->_node = _avl->decrementation(_root, _node);
                return (*this);
            }
			const_iterator operator-- (int)
			{
				const_iterator _old = *this;
				operator--();
				return _old;
			}
	};
};


#endif