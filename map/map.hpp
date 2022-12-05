#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <map>
#include "avl.hpp"
# include "../utils/pair.hpp"
# include "./bidirectional_iterators.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                      key_type;
            typedef T                                        mapped_type;
            typedef ft::pair<const key_type, mapped_type>        value_type;
            typedef Compare                                  key_compare;
            typedef Allocator                                allocator_type;
            typedef ft::Node<value_type>                         node;
            typedef ft::avl<node, mapped_type, key_type, key_compare, allocator_type> tree;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef ft::iterator<value_type, node, tree> iterator;
            // typedef typename std::map<Key, T>::iterator     iterator;
            // typedef ft::bidirectional_iterators<const value_type, tree> const_iterator;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;

        private:
            tree    _tree;
            key_compare _compare;
            allocator_type  _alloc;
        public: 
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(comp, alloc), _compare(comp), _alloc(alloc){};

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _compare(comp), _alloc(alloc)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
            }
        
            map (const map& x)
            {
                this = x;
            }

            map& operator= (const map& x)
            {
                _tree.clear();
                this->_alloc = x._alloc;
                this->_compare = x._compare;
                iterator it = x.begin();
                while (it++)
                {
                    this->insert(*it);
                }
                return (*this);
            }

            /*-----------------------------iterators-------------------------------------------------------------------------------*/
            iterator    begin()
            {
                return(iterator(_tree.min_node()));
            }

            // const_iterator begin() const
            // {
            //     return(iterator(_tree.min_node()));
            // }

            iterator end()
            {
                // node* root = NULL;
                iterator it(_tree.max_node(), _tree._root);
                // return (it);
                return (it);
            }

            // const_iterator end() const
            // {
            //     return (iterator(_tree.max_node()));
            // }

/*------------------------------------------------capacity----------------------------------------------*/

        size_type size() const
        {
            return (_tree.size());
        }

         bool empty() const
        {
            return !(_tree.size);
        }

        /*------------------------------------------------element acces----------------------------------------------------------------*/
        mapped_type& operator[] (const key_type& k)
        {
            value_type tmp = ft::make_pair(k,mapped_type());
            insert(tmp);
            return (_tree.search(k)->data.second);
        }
/*-----------------------------modifiers-----------------------------------------------------------------------------------------------*/
            ft::pair<iterator,bool> insert (const value_type& val)
            {
                iterator it = find(val.first);
                if (it != end())
                    return ft::make_pair(it, false);
                else
                {
                    _tree.insert(val);
                    return (ft::make_pair(find(val.first), true));
                }
                // unsigned int old_size = _tree.size();
                // _tree.insert(val);
                // if (_tree.size() == old_size)
                //     return(ft::make_pair(iterator(), false));
                // return(ft::make_pair(iterator(), true));
                //return (ft::make_pair(iterator(), false));
            }

            iterator find(const key_type &k)
            {
                node* tmp = size() ? _tree._root : NULL;
                while (tmp != NULL)
                {
                    if (_compare(k, tmp->data.first))
                    {
                        tmp = tmp->left;
                    }
                    else if (_compare(tmp->data.first, k))
                        tmp = tmp->right;
                    else
                        return (iterator(tmp, _tree._root));
                }
                return (end());
            }

            iterator insert (iterator position, const value_type& val)
            {
                insert(val);
                return position;
            }
            // template <class InputIterator>
            // void insert (InputIterator first, InputIterator last)
            // {
            //     while (first != last)
            //     {
            //         this->insert(*first);
            //         first++;
            //     }
            // }



    };
};
#endif


