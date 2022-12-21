#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include "../vector/vector.hpp"

template <class T, class Container = ft::vector<T> >
class stack
{
    public:
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;
    private: 
        container_type container;
    public:

        explicit stack (const container_type& ctnr = container_type()) : container(ctnr)
        {
            
        }
        
}

#endif