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
            seconde_type second;
            pair(): first(), second()
            {

            }

            pair(pair<T1,T2> &pr)
            {
                this->first = pr.first;
                this->second = pr.second;

            }
            pair(first_type x, seconde_type y)
            {
                
            }
            pair& operator= (const pair& pr)
            {
                this->first = pr.first;
                this->second = pr.second;
                return *this;
            }

    };

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        pair<T1,T2> p;
      return (p);
    }

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
                return (node);
            }
    };
}
#endif

