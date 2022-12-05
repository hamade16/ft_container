#ifndef BIDIRECTIONAL_ITERATORS_HPP
#define BIDIRECTIONAL_ITERATORS_HPP
#include <iostream>
#include <map>
#include "./avl.hpp"
#include "../utils/pair.hpp"

namespace ft
{
    template<typename pair, typename avl, typename Node>
    class bidirectional_iterators
    {
        public:
            typedef Node*                      node_pointer;
            typedef pair                      *pointer;
            typedef pair                      &reference;
            typedef std::ptrdiff_t       difference_type;
            avl             *_avl;
        private:
            node_pointer    _node;
        public:
            bidirectional_iterators()
            {
                _node = NULL;
            }

            bidirectional_iterators(Node* node) : _node(node)
            {
            }

            // template<typename p, typename av>
            // bidirectional_iterators(bidirectional_iterators<pair, av> const & src)
            // {
            //     this->_node = src._node;
            // }

            explicit bidirectional_iterators(bidirectional_iterators const & p)
            {
                this->_node = p._node;
            }

            bidirectional_iterators    &operator=(bidirectional_iterators const & src)
            {
                this->_node = src._node;
                return(*this);
            }
            ~bidirectional_iterators()
            {

            }

            bool    operator==(bidirectional_iterators const & src)
            {
                if (this->_node == src._node)
                    return true;
                else
                    return false;
            }

            bool    operator!=(bidirectional_iterators const & src)
            {
                 if (this->_node != src._node)
                    return true;
                else
                    return false;
            }

            reference   operator*() const
            {
                return *(_node->data);
            }

            pointer operator->() const
            {
                return (_node->data);
            }

            bidirectional_iterators operator++()
            {
                this->_node = _avl->incrementation(_node);
                return (*this);
            }

            bidirectional_iterators operator++(int)
            {
                bidirectional_iterators tmp = this;
                this->_node = _avl->incrementation(_node);
                return (*tmp);
            }

            bidirectional_iterators operator--()
            {
                this->_node = _avl->decrementation(_node);
                return (*this);
            }

            bidirectional_iterators operator--(int)
            {
                bidirectional_iterators tmp = this;
                this->_node = _avl->decrementation(_node);
                return (*tmp);
            }

    };
};


#endif