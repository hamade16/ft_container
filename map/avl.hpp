#ifndef AVL_HPP
# define AVL_HPP


#include <iostream>
#include <functional>
#include "../utils/pair.hpp"

namespace ft
{
    template<class Node, class T, class key, class Compare = std::less<key>, class Alloc = std::allocator<ft::pair<key,T> > >
    class avl
    {
        public:
            typedef T mapped_type;
            typedef key key_type;
            typedef Alloc allocator_type;
            typedef Compare							key_compare;
            typedef ft::pair<key_type, mapped_type> value_type;
            typedef Node node_type;
            node_type    *new_node_all;
            node_type    *_root;
        private: 
            allocator_type _all;
            key_compare _compare;
            unsigned int											_size;
            typename Alloc::template rebind<node_type>::other	_node_allocator;
        public:
            avl(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _root(NULL), _compare(comp), _all(alloc), _size(0)
            {
                
            }
            ~avl()
            {

            }
            node_type *new_node(value_type x)
            {
                //node* newNode(int key);
                node_type * node1 = _node_allocator.allocate(1);
                _node_allocator.construct(node1, x);
                new_node_all = node1;
                node1->left = NULL;
                node1->right = NULL;
                node1->parent = NULL;
                node1->height = 1; // new node is initially
                                  // added at leaf
                node1->balance_factor = 0;
                _size++;                  
                return(node1);
            }

            size_t height(node_type *node)
            {
                if (node == NULL)
                    return 0;
                else
                    return (node->height);
            }

            size_t max(size_t a, size_t b)
            {
                return (a > b ? a : b); 
            }

            size_t  getbalance(node_type *node)
            {
                if (node == NULL)
                    return 0;
                else
                    return (height(node->left) - height(node->right));
            }

            node_type*   lRrotate(node_type* y)
            {
                node_type *tmp = y->left;
                tmp = rightrotate(tmp);
                return leftrotate(y);
            }

            node_type*   leftrotate(node_type* y)
            {
                node_type *tmp = y->left;
                y->left = tmp->right; 
                tmp->right = y;
                tmp->parent = y->parent;
                y->parent = tmp;
                return tmp;
            }

            node_type* rightrotate(node_type* y)
            {
               node_type* tmp = y->right;
               y->right = tmp->left;
               tmp->left = y;
               tmp->parent = y->parent;
               y->parent = tmp;
               return (tmp);
            }

            node_type* RLrotate(node_type* y)
            {
                node_type *tmp = y->right;
                tmp = leftrotate(tmp);
                return (rightrotate(y));
            }

            void	insert(const value_type &data)
		    {
		    	_root = insert(_root, data);
		    }

            unsigned int size() const
            {
                return (_size);
            }

            node_type *min_node(node_type *root)
            {
                node_type *current = root;
			    while (current != NULL)
				    current = current->left;
			    return current->parent;
            }

            node_type *max_node(node_type *root)
            {
                node_type *current = root;
			    while (current != NULL)
				    current = current->right;
			    return current;
            }

            node_type* insert(node_type* node, value_type x)
            {
                new_node_all = NULL;
                if (node == NULL)
                {
                  return (new_node(x));
                }
                if (x.first < node->data.first)
                    node->left = insert(node->left, x);
                else if (x.first > node->data.first)
                    node->right = insert(node->right, x);
                else 
                    return (node);
                node->height = 1 + max(height(node->left), height(node->right));
                node->balance_factor = getbalance(node);
                if (node->balance_factor < -1)
                {
                    if (node->right->balance_factor <= 0)
                        return (rightrotate(node));
                    else
                        return (RLrotate(node));
                }
                else if(node->balance_factor > 1)
                {
                    if (node->left->balance_factor >= 0)
                        return (leftrotate(node));
                    else
                        return (lRrotate(node));
                }
                return (node);
            }

            void    swap(avl &other)
            {
                std::swap(this->_all, other._all);
                std::swap(this->_compare, other._compare);
                std::swap(this->_size, other._size);
                std::swap(this->_root, other._root);
            }

            void clear(node_type *node)
		    {
		    	if (node == NULL)
		    		return;
		    	clear(node->left);
		    	clear(node->right);
		    	_node_allocator.destroy(node);
		    	_node_allocator.deallocate(node, 1);
		    }

            void    clear()
            {
                clear(this->_root);
                _root = NULL;
            }

            node_type *incrementation(node_type *node)
			{
				if (node == max_node(this->_root) || node == NULL)
				{
					return NULL;
				}
				return (incrementation(_root, node->data.first));
			}


            const node_type *incrementation(const node_type *node) const
			{
				if (node == max_node(this->_root) || node == NULL)
				{
					return NULL;
				}
				return (incrementation(_root, node->data.first));
			}


            node_type* incrementation(node_type *root, key_type k) 
			{
				node_type *succ = NULL;
				while (true)
				{
					if (_compare(k, root->data.first))
					{
						succ = root;
						root = root->left;
					}
					else if (_compare(root->data.first, k))
						root = root->right;
					else
					{
						if (root->right != NULL)
							succ = min_node(root->right);
						break;
					}
				}
				if (succ == NULL)
					return max_node(this->_root);
				return succ;
			}

            node_type *decrementation(node_type *node) const
			{
				if (node == max_node(this->_root))
					return max_node(this->_root);
				return decrementation(_root, node->data.first);
			}

            const node_type *decrementation(const node_type *node) const
			{
				if (node == max_node(this->_root))
					return max_node(this->_root);
				return decrementation(_root, node->data.first);
			}

            node_type* decrementation(node_type *rt, key_type k) const
		    {
		    	node_type* pred = NULL;
		    	while (true)
		    	{
		    		if (_compare(k, rt->data.first))
		    			rt = rt->left;
		    		else if (_compare(rt->data.first, k))
		    		{
		    			pred = rt;
		    			rt = rt->right;
		    		}
		    		else
		    		{
		    			if (rt->left!= NULL)
		    				pred = max_node(rt->left);
		    			break;
		    		}
		    		if (rt == NULL)
		    			return NULL;
		    	}
		    	return pred;
		    }

            node_type*   search(key_type k) const
            {
                return search(_root, k);
            }

            node_type* search(node_type *root, key_type k) const
            {
                if (root == NULL)
                        return NULL;
                else if (_compare(k, root->data.first))
                {
                        node_type* rt = search(root->left, k);
                        return rt;
                }
                else if (_compare(root->data.first, k))
                {
                        node_type* rt = search(root->right, k);
                        return rt;
                }
                else
                        return root;
            }
    };
}
#endif

