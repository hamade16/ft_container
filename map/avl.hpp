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
            unsigned int											_size;
        private: 
            allocator_type _all;
            key_compare _compare;
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
               // node1->parent = NULL;
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

            node_type *right_rotate(node_type *y)
            {
                node_type *x = y->left;
                node_type *T2 = x->right;
                x->right = y;
                y->left = T2;
                y->height = max(height(y->left), height(y->right)) + 1;
                x->height = max(height(x->left), height(x->right)) + 1;
                return x;
            }

            node_type *left_rotate(node_type *x)
            {
                node_type *y = x->right;
                node_type *T2 = y->left;
                y->left = x;
                x->right = T2;
                x->height = max(height(x->left), height(x->right)) + 1;
                y->height = max(height(y->left), height(y->right)) + 1;
                return y;
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
                node_type *tmp = current;
			    while (current != NULL)
                {
                    tmp = current;
				    current = current->left;
                }
			    return tmp;
            }

            node_type *max_node(node_type *root)
            {
                node_type *current = root;
                node_type *tmp = current;
			    while (current != NULL)
                {
                    tmp = current;
				    current = current->right;
                }
			    return tmp;
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
                        return left_rotate(node);
                    else 
                    {
                         node->right = right_rotate(node->right);
                        return left_rotate(node);
                    }
                }
                else if(node->balance_factor > 1)
                {
                    if (node->left->balance_factor >= 0)
                    {
                        return right_rotate(node);
                    }
                    else
                    {
                        node->left = left_rotate(node->left);
                        return right_rotate(node);
                    }
                }
                return (node);
            }

            void    delete_node(key_type k)
            {
                _root = delete_node(_root, k);
            }

            Node *delete_node(node_type *root, key_type k)
            {
                if (root == NULL)
                    return root;
                if (_compare(k, root->data.first))
                        root->left = delete_node(root->left, k);
                else if (_compare(root->data.first, k))
                {
                        root->right = delete_node(root->right, k);
                }
                else
                {
                    if (root->left == NULL && root->right==NULL)
                    {
                            _node_allocator.destroy(root);
                            _node_allocator.deallocate(root, 1);
                            return NULL;
                    }
                    else if (root->left == NULL)
                    {
                        node_type* temp = root->right;
                        _node_allocator.destroy(root);
                        _node_allocator.deallocate(root, 1);
                        return temp;
                    }
                    else if (root->right == NULL)
                    {
                        node_type* temp = root->left;
                        _node_allocator.destroy(root);
                        _node_allocator.deallocate(root, 1);
                        return temp;
                    }
                    node_type* temp = min_node(root->right);
                    _all.destroy(&root->data);
                    _all.construct(&root->data, temp->data);
                    root->right = delete_node(root->right, temp->data.first);
                }
                if (root == NULL)
                    return root;
                root->height = 1 + max(height(root->left), height(root->right));
                root->balance_factor = getbalance(root);
                 if (root->balance_factor > 1 && root->left->balance_factor >= 0)
                         return right_rotate(root);
                if (root->balance_factor > 1 && root->left->balance_factor < 0)
                {
                        root->left = left_rotate(root->left);
                        return right_rotate(root);
                }
                if (root->balance_factor < -1 && root->right->balance_factor <= 0)
                        return left_rotate(root);
                if (root->balance_factor < -1 && root->right->balance_factor > 0)
                {
                        root->right = right_rotate(root->right);
                        return left_rotate(root);
                }
                return root;
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

            node_type *incrementation(node_type *root,  node_type *node)
			{
				if (node == max_node(this->_root) || node == NULL)
				{
					return NULL;
				}
				return (incrementation(root, node->data.first));
			}


            const node_type *incrementation(node_type *root, const node_type *node) const
			{
				if (node == max_node(this->_root) || node == NULL)
				{
					return NULL;
				}
				return (incrementation(root, node->data.first));
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
                {
					return max_node(this->_root);
                }
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

