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
        //typedef ft::reverse_iterator<iterator>          reverse_iterator;
        //typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;



        //typedef typename Alloc::pointer pointer;
        //typedef typename Alloc::reference reference;
       // typedef Alloc       allocat_type;

        //allocat_type        my_alloc;
        public:
            pointer arr;
            allocator all;
        vector(T a)
        {
            arr = all.allocate(10);
            all.constuct(arr+0, a);
        }
    };
};



#endif