#pragma once 


#include <iostream>

template<class T>
class Node
{
    public:
        T *val;
        Node *left;
        Node *right;
        size_t hight;
        Node   *parent;   
};

template<class T>
class avl
{
    typedef T value_type;
    Node<value_type> node;
    public:
    Node* new_node(value_type key)
    {
        Node* newNode(int key)
        Node* node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; // new node is initially
                          // added at leaf
        return(node);
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

    Node* insert(Node* node, value_type key)
    {
        if (node == NULL)
          return (new_node(key));
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else 
            return (node);
        node->height = 1 + max(node->left->height, node->right->height);
        

    }
};

