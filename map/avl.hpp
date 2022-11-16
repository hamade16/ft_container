#ifndef AVL_HPP
# define AVL_HPP


#include <iostream>
#include <functional>
namespace ft
{

    template<class T1, class T2>
    class pair 
    {
        public: 
            typedef T1 first_type;
            typedef T2 seconde_type;
        public: 
            first_type first;
            seconde_type seconde;
            pair(): first(), seconde()
            {

            }
            pair(pair<T1,T2> &pr): first(pr.first), seconde(pr.seconde)
            {

            }
            pair(first_type x, seconde_type y) : first(x), seconde(y)
            {

            }
    };

    template<typename pair>
    class Node
    {
        public:
            Node(){

            };
            ~Node(){

            };
            pair *data;
            Node<pair> *left;
            Node<pair> *right;
            Node<pair> *parent;
            size_t height;
            int balance_factor;
    };

    template<class T, class key, class Compare = std::less<key>, class Alloc = std::allocator<ft::pair<key,T> > >
    class avl
    {
        public:
            typedef T mapped_type;
            typedef key key_type;
            typedef Alloc allocator_type;
            typedef ft::pair<key_type, mapped_type> value_type;
            typedef Node<value_type> Node;
        private: 
            allocator_type _all;
            Compare _compare;
        public:
            Node *a;
            avl(){
                a = NULL;
            }
            ~avl()
            {

            }
            Node *new_node(value_type x)
            {
                //node* newNode(int key);
                Node* node1;
                node1->data = _all.allocate(1);
                _all.construct(node1->data, x);
                node1->left = NULL;
                node1->right = NULL;
                node1->parent = NULL;
                node1->height = 1; // new node is initially
                                  // added at leaf
                node1->balance_fator = 0;                  
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
                tmp = leftrotate(tmp);
                return Rightrotate(y);
            }

            Node*   leftrotate(Node* y)
            {
                Node *tmp = y->left;
                tmp->right = y;
                tmp->parent = y->parent;
                y->parent = tmp;
                return tmp;
            }

            Node* rightrotate(Node* y)
            {
               Node* tmp = y->right;
               tmp->left = y;
               tmp->parent = y->parent;
               y->parent = tmp;
               return (tmp);
            }

            Node* RLrotate(Node* y)
            {
                Node *tmp = y->right;
                tmp = leftrotate(tmp);
                return (rightrotate);
            }

            Node* insert(Node* node, value_type x)
            {
                if (node == NULL)
                {
                  return (new_node(x));
                }
                if (x.first < node->data->first)
                    node->left = insert(node->left, x);
                else if (x.first > node->data->key)
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

                // if (node->balance_factor < -1 && x < node->right->key)
                //     return(RLrotate(node));
                // if (node->balance_factor < -1 && x > node->right->key)
                //     return (RRrotate(node));
                // if (node->balance_factor > 1 && x < node->left->key)
                //     return (llrotate(node));
                // if (node->balance_factor > 1 && x > node->left->key)
                //     return (lRrotate(node));

                return (node);
            }
    };
}
#endif

