#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <vector>

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
    template<class T, class Alloc = std::allocator<T>() >
    class vector {

        public:
            typedef T                                        value_type;
            typedef std::allocator<value_type>               allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef std::size_t                              size_type;
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator; 

        private:
            size_type _capacite;
            size_type _size;
            size_type _max_size;
            pointer _vector;
            allocator_type all;

        public:
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                all = alloc;
                _capacite = 0;
                _size = 0;
                _max_size = all.max_size();
                _vector  = NULL;
            }
            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
            {
                all = alloc;
                _capacite = n;
                _size = n;
                _max_size = all.max_size();
                _vector = all.allocate(n);
                for(int i = 0; i < n; i++)
                    all.construct(_vector+i, val);
            }

        //     template <class InputIterator>
        //  vector (InputIterator first, InputIterator last,
        //          const allocator_type& alloc = allocator_type())
        //         {
                   
        //         }

            vector (const vector& x)
            {
                this->all = x.all;
                this->_vector = all.allocate(x._capacite);
                this->_capacite = x._capacite;
                this->_size = x._size;
                this->_max_size = x._max_size;
                for(int i = 0; i < x._size; i++)
                    this->all.construct(this->_vector+i, x._vector[i]);
            }

            ~vector()
            {

            }

            vector& operator= (const vector& x)
            {
                //std::cout << "====>" << std::endl;
                /*if (this->_capacite > 0)*/
                this->all.deallocate(this->_vector, this->_capacite);
                this->all = x.all;

                this->_vector = all.allocate(x._capacite);
                this->_capacite = x._capacite;
                this->_size = x._size;
                this->_max_size = x._max_size;
                for(int i = 0; i < x._size; i++)
                    this->all.construct(this->_vector+i, x._vector[i]);
                return (*this);
            }

            reference operator[] (size_type n) const
            {
               return *(this->_vector+n);
            }

            reference at (size_type n) const
            {
               return *(this->_vector+n);
            }

            reference front()
            {
                return*(this->_vector+0);
            }

            reference back()
            {
                return*(this->_vector+(_size - 1));
            }

            size_type capacity() const
            {
                return _capacite;
            }
            size_type size() const
            {
                return (_size);
            }
            size_type max_size() const
            {
                return (_max_size);
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _size)
                    _size = n;
                else if (n > _size && n < _capacite)
                {
                    for(int i = _size; i < n; i++)
                        all.construct(_vector + i , val);

                    _size = n;
                }
                else if (n > _size && n > _capacite)
                {
                    _capacite *= 2;
                    if (_capacite < n)
                        _capacite = n;
                    pointer v;
                    v = all.allocate(_capacite);
                    for (size_t i = 0; i < _size; i++)
                        all.construct(v + i, _vector+i);
                    for(size_t i = _size; i < n; i++)
                      all.construct(v + i, val);
                    all.deallocate (_vector, _capacite);
                }
            }
            bool empty() const
            {
                if (_size == 0)
                    return true;
                else
                    return false;
            }
            void reserve (size_type n)
            {
                if (n > _capacite)
                {
                    pointer v;
                    v = all.allocate(n);
                    _capacite = n;
                    for(int i = 0; i < _size; i++)
                        all.construct(v + i, *(_vector+i));
                    this->_vector = v;
                }
            }
            
            void push_back (const value_type& val)
            {
                size_t old_capacity = 0;
                if (this->_size < this->_capacite)
                {
                    this->all.construct(this->_vector+_size, val);
                    this->_size += 1;
                }
                else
                {
                    old_capacity = _capacite;

                    if ( _capacite == _size)
                    {
                        if (_capacite == 0)
                            _capacite = 1;
                        else
                            _capacite *= 2;
                    }
                    pointer v;

                    v = all.allocate(this->_capacite);
                    int i;
                    for (i = 0; i < this->_size; i++)
                    {
                        all.construct(v+i, *(this->_vector+i));
                        all.destroy(this->_vector + i);
                    }
                    all.deallocate(this->_vector, old_capacity);
                    all.construct(v+i, val);
                    // old_vector
                    this->_vector = v;
                    this->_size += 1;
                    // new memory _vector
                }
            }
            void pop_back()
            {
                if (_size > 0)
                {
                    all.destroy(this->_vector+(_size - 1));
                    _size -= 1;

                }
            }

            void swap (vector& x)
            {
                // vector *v;
                // v = this;
                // this = x;
                // x = v;


                size_type _size_tmp;
                size_type _capacity_tmp;
                pointer   _vector_tmp;

                _vector_tmp = x._vector;
                _size_tmp = x._size;
                _capacity_tmp = x._capacite;

                x._vector = this->_vector;
                x._size = this->_size;
                x._capacite = this->_capacite;

                this->_size = _size_tmp;
                this->_capacite = _capacity_tmp;
                this->_vector = _vector_tmp;

                // vector tmp;
                // tmp = *this;
                // *this = x;
                // x = tmp;
                //tmp->all.deallocate(tmp->_vector, tmp->_capacite);
            }
            void clear()
            {
                for(int i = 0; i < this->_size; i++)
                    all.destroy(this->_vector+i);
                this->_size = 0;
            }

              iterator begin()
              {
                // iterator it;
                // it. = this->_vector;
                // return (it);
                return iterator(this->_vector);
              }

              iterator end()
              {
                return iterator(this->_vector+(_size));
              }
              reverse_iterator rbegin()
              {
                reverse_iterator rev_it(end());
                return (rev_it);
              }
              reverse_iterator  rend()
              {
                reverse_iterator rev_it(begin());
                return (rev_it);
              }

            iterator insert(iterator position, const value_type &val)
             {
                size_type i = 0;
                size_type o = position - this->begin();
                if (_size == 0)
                    push_back(val);
                else
                {
                    if (_size + 1 > _capacite)
                        reserve(_capacite * 2);
                    while (_size - i + 1 > 0)
                    {
                        if (_size - i == o) // 2 1 55 44 55 
                        {
                            all.construct(&_vector[_size - i] , val);
                            break;
                        }
                        else
                            all.construct(&_vector[_size - i] , _vector[_size - i - 1]);
                        i++;
                    }
                    _size++;
                }
                return iterator(_vector + o);
             }

              void insert (iterator position, size_type n, const value_type& val)
              {
                size_type i = 0;
                size_type o = position - this->begin();
                size_type m = n;
                if (_size + n > _capacite)
                {
                    if (_size + n < _capacite*2)
                        reserve(_capacite*2);
                    else
                    {
                        reserve(_size + n);
                        _capacite = _size + n;
                    }
                }
                while (_size - i  + n > 0)
                {
                    if (_size - i  == o)
                    {
                        while(m--)
                            all.construct(&_vector[_size - i + m] , val);
                        break;
                    }
                    else
                    {
                        all.construct(&_vector[_size - i - 1 + n] , _vector[_size - i - 1]);
                    }
                    i++;
                }
                    _size += n;
              }

              template <class InputIterator>
               void insert (iterator position, InputIterator first, typename ft::enable_if<ft::is_integral<InputIterator>::type> last)
               {
                    size_type o = position - this->begin();
                    size_type n = last - first;
                    size_type i = 0;
                    if (_size + n > _capacite)
                    {
                        if (_size + n < _capacite*2)
                            reserve(_capacite*2);
                        else
                        {
                            reserve(_size + n);
                            _capacite = _size + n;
                        }
                    }
                    while (_size - i + n > 0)
                    {
                        if ()
                    }

               }
    };
};



#endif