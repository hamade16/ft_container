#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <map>
#include "avl.hpp"
# include "../utils/pair.hpp"
# include "./bidirectional_iterators.hpp"
# include "../vector/vector.hpp"
# include "../utils/reverse_iterator.hpp"

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
            typedef ft::iterator<const value_type, node, tree> const_iterator;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;

        private:
            tree    _tree;
            key_compare _compare;
            allocator_type  _alloc;
        public: 
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(comp, alloc), _compare(comp), _alloc(alloc)
            {
        
            };

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
                clear();
                this->_alloc = x._alloc;
                this->_compare = x._compare;
                this->insert(x.begin(), x.end());
                return (*this);
            }

            /*-----------------------------iterators-------------------------------------------------------------------------------*/
            iterator    begin()
            {
                iterator it(_tree.min_node(_tree._root), _tree._root);
                return(it);
            }

            const_iterator begin() const
            {
                const_iterator it(_tree.min_node(_tree._root), _tree._root);
                return it;
            }

            iterator end()
            {
                iterator it(NULL,  _tree._root);
                return(it);
            }

            const_iterator end() const
            {
                const_iterator it(NULL, _tree._root);
                return (it);
            }

            reverse_iterator rbegin()
            {
              reverse_iterator rev_it(end());
              return (rev_it);
            }
            const_reverse_iterator rbegin() const
            {
                const_reverse_iterator rev_it(end());
                return (rev_it);
            }
            reverse_iterator  rend()
            {
              reverse_iterator rev_it(begin());
              return (rev_it);
            }

            const_reverse_iterator rend() const
            {
                const_reverse_iterator rev_it(begin());
                return (rev_it);
            }

/*------------------------------------------------capacity----------------------------------------------*/

        size_type size() const
        {
            return (_tree.size());
        }

         bool empty() const
        {
            return !(_tree.size());
        }



        /*------------------------------------------------element acces----------------------------------------------------------------*/
        mapped_type& operator[] (const key_type& k)
        {
            iterator it = find(k);
            if (it != end())
                return it->second;
            insert(ft::make_pair(k, mapped_type()));
            return (find(k)->second);
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
            }

            iterator insert (iterator position, const value_type& val)
            {
                insert(val);
                return position;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    this->insert(*first);
                    first++;
                }
            }
            void clear()
            {
                _tree.clear();
            }

            void swap (map& x)
            {
                _tree.swap(x._tree);
            }

            size_type erase (const key_type& k)
            {
                if (_tree.search(k))
                {
                    _tree.delete_node(k);
                    _tree._size--;
                    return (1);
                }
                return (0);
            }

            void erase (iterator position)
            {
                value_type a = *(position);
                _tree.delete_node(a.first);
            }

            void erase (iterator first, iterator last)
            {
                ft::vector<key_type> vect;
                while (first != last)
                {
                    vect.push_back(first->first);
                    first++;
                }
                typename ft::vector<key_type>::iterator it = vect.begin();
                while (it != vect.end())
                {
                    erase(*it);
                    it++;
                }
            }
/*----------------------------------------------Operations-----------------------------------------------------------*/
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

            size_type count (const key_type& k) const
            {
                node *tmp = _tree.search(k);
                if (tmp == NULL)
                    return (0);
                return 1;
            }

            iterator lower_bound (const key_type& k)
            {
                return (iterator(_tree.lower_bound(k), _tree._root));
            }

            const_iterator lower_bound (const key_type& k) const
            {
                return (const_iterator(_tree.lower_bound(k), _tree._root));
            }

            iterator upper_bound (const key_type& k)
            {
                return (iterator(_tree.upper_bound(k), _tree._root));
            }
            const_iterator upper_bound (const key_type& k) const
            {
                return (const_iterator(_tree.upper_bound(k), _tree._root));
            }

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                pair<const_iterator, const_iterator> p = make_pair(lower_bound(k), upper_bound(k));
                return(p);
            }

            pair<iterator,iterator> equal_range (const key_type& k)
            {
                pair<iterator, iterator> p = make_pair(lower_bound(k), upper_bound(k));
                return(p);
            }

/*---------------------------------------Observers:------------------------------------------------------*/
            key_compare key_comp() const
            {
                return (_compare);
            }

            // value_compare value_comp() const
            // {
            //     return (value_comp(_compare));
            // }
    };
};
#endif


