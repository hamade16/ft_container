#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
# include <memory>
# include <vector>

namespace ft
{
    template<class T, class Alloc = std::allocator<T>() >
    class vector {
       /*typedef T value_type;
        typedef T* pointer;*/
        typedef Alloc allocator_type;
        typedef T                                        value_type;
        //typedef allocator                                allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef typename random_access_iterator<pointer>          iterator;
        typedef std::size_t size_type;
        //typedef ft::reverse_iterator<iterator>          reverse_iterator;
        //typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator; 



        //typedef typename Alloc::pointer pointer;
        //typedef typename Alloc::reference reference;
       // typedef Alloc       allocat_type;

        //allocat_type        my_alloc;
        private:
            size_type _capacite;
            size_type _size;
            size_type _max_size;
            pointer vector;
            allocator_type all;

        public:
            size_type capacity() const
            {
                return _capacite;
            }
            size_type size() const
            {
                return (_size);
            }
            size_type max_size() const;
            {
                return _max_size;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _size)
                    _size = n;
                else if (n > _size && n < _capacite)
                {
                    for(int i = _size, i < n, i++)
                        all.construct(vector + i , val);

                    _size = n;
                }
                else if (n > _size && n > _capacite)
                {
                    _capacite *= 2;
                    if (_capcite < n)
                        _capacite = n;
                    pointer v;
                    v = all.allocate(_capacite);
                    for (size_t i = 0; i < _size; i++)
                        all.construct(v + i, vector[i]);
                    for(size_t i = _size; i < n; i++)
                      all.construct(v + i, val);
                }
            }
            bool empty() const;
            {
                if (_size == 0)
                    return true;
                else
                    false;
            }
            
        /*vector(T a)
        {
            arr = all.allocate(10);
            all.constuct(arr+0, a);
        }*/
    };
};



#endif