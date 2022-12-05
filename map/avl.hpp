#ifndef AVL_HPP
# define AVL_HPP


#include <iostream>
#include <functional>
#include "../utils/pair.hpp"

namespace ft
{
    template<class T, class key, class Compare = std::less<key>, class Alloc = std::allocator<ft::pair<key,T> > >
    class avl
    {
        public:
            typedef T mapped_type;
            typedef key key_type;
            typedef Alloc allocator_type;
            typedef Compare							key_compare;
            typedef ft::pair<key_type, mapped_type> value_type;
            typedef Node<value_type> Node;
            Node    *new_node_all;
        private: 
            allocator_type _all;
            key_compare _compare;
            Node    *_root;
            unsigned int											_size;
            typename allocator_type::template rebind<Node>::other	_node_allocator;
        public:
            avl(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _root(NULL), _compare(comp), _all(alloc), _size(0)
            {
                
            }
            ~avl()
            {

            }
            Node *new_node(const value_type &x)
            {
                //node* newNode(int key);
                Node * node1 = _all.allocate(1);
                new_node_all = node1;
                _all.construct(node1, x);
                node1->left = NULL;
                node1->right = NULL;
                node1->parent = NULL;
                node1->height = 1; // new node is initially
                                  // added at leaf
                node1->balance_factor = 0;
                _size++;                  
                return(node1);
            }

            size_t height(Node *node)
            {
                if (node == NULL)
                    return 0;
                else
                    return (node->height);
            }

            value_type max(value_type a, value_type b)
            {
                return (a > b ? a : b); 
            }

            size_t  getbalance(Node *node)
            {
                if (node == NULL)
                    return 0;
                else
                    return (height(node->left) - height(node->right));
            }

            Node*   lRrotate(Node* y)
            {
                Node *tmp = y->left;
                tmp = rightrotate(tmp);
                return leftrotate(y);
            }

            Node*   leftrotate(Node* y)
            {
                Node *tmp = y->left;
                y->left = tmp->right; 
                tmp->right = y;
                tmp->parent = y->parent;
                y->parent = tmp;
                return tmp;
            }

            Node* rightrotate(Node* y)
            {
               Node* tmp = y->right;
               y->right = tmp->left;
               tmp->left = y;
               tmp->parent = y->parent;
               y->parent = tmp;
               return (tmp);
            }

            Node* RLrotate(Node* y)
            {
                Node *tmp = y->right;
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

            Node *min_node()
            {
                Node *current = this->_root;
			    while (current->left != NULL)
				    current = current->left;
			    return current;
            }

            Node *max_node()
            {
                Node *current = this->_root;
			    while (current->right != NULL)
				    current = current->right;
			    return current;
            }

            Node* insert(Node* node, value_type x)
            {
                new_node_all = NULL;
                if (node == NULL)
                {
                  return (new_node(x));
                }
                if (x.first < node->data->first)
                    node->left = insert(node->left, x);
                else if (x.first > node->data->first)
                    node->right = insert(node->right, x);
                else 
                    return (node);
                node->height = 1 + max(height(node->left), height(node->right));
                node->balance_factor = getbalance(node);
                if (node->balance_factor < -1)
                {
                    if (node->right->balance_factor <= 0)
                        return (Rightrotate(node));
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

            void clear(Node *node)
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

            Node *incrementation(Node *node) const
			{
				if (node == max_node() || node == NULL)
				{
					return NULL;
				}
				return (incrementation(_root, node->data.first));
			}


            const Node *incrementation(const Node *node) const
			{
				if (node == max_node() || node == NULL)
				{
					return NULL;
				}
				return (incrementation(_root, node->data.first));
			}


            Node* incrementation(Node *root, key_type k) const
			{
				Node *succ = NULL;
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
							succ = min_value_node(root->right);
						break;
					}
				}
				if (succ == NULL)
					return max_node();
				return succ;
			}

            Node *decrementation(Node *node) const
			{
				if (node == max_node())
					return max_value_node(this->_root);
				return decrementation(_root, node->data.first);
			}

            const Node *decrementation(const Node *node) const
			{
				if (node == max_node())
					return max_value_node(this->_root);
				return decrementation(_root, node->data.first);
			}

            Node* decrementation(Node *rt, key_type k) const
		    {
		    	Node* pred = NULL;
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
		    				pred = max_value_node(rt->left);
		    			break;
		    		}
		    		if (rt == NULL)
		    			return NULL;
		    	}
		    	return pred;
		    }

            Node*   search(key_type k) const
            {
                return search(_root, k);
            }

            Node* search(Node *root, key_type k) const
            {
                if (root == NULL)
                        return NULL;
                else if (_compare(k, root->data->first))
                {
                        Node* rt = search(root->left, k);
                        return rt;
                }
                else if (_compare(root->data->first, k))
                {
                        Node* rt = search(root->right, k);
                        return rt;
                }
                else
                        return root;
            }
    };
}
#endif

