#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include <iostream>
# include <memory>

namespace ft
{
    template<class T, class Alloc = std::allocator<T>() >
    class vector {
        typedef T value_type;
        typedef T* pointer;
        typedef Alloc allocator;

        //typedef typename Alloc::pointer pointer;
        //typedef typename Alloc::reference reference;
       // typedef Alloc       allocat_type;

        //allocat_type        my_alloc;
        private:
            pointer arr;
            allocator all;
        vector()
        {
            arr = all.allocate(10);
            all.constuct(arr+0, 1337);
        }
    }
};



#endif