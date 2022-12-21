#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <stack>
#include "../vector/vector.hpp"
namespace ft
{

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

            bool empty() const
            {
                return (container.empty());
            }
            size_type size() const
            {
                return container.size();
            }

            value_type& top()
            {
              return container.back();
            }

            const value_type& top() const
            {
                return container.back();
            }

            void push (const value_type& val)
            {
                return container.push_back(val);
            }

            void pop()
            {
                return container.pop_back();
            }

        private: 
            template <class T1, class Cont>
                friend bool operator== (const stack<T1,Cont>& lhs, const stack<T1,Cont>& rhs);
            template <class T1, class Cont>
                friend bool operator!= (const stack<T1,Cont>& lhs, const stack<T1,Cont>& rhs);
            template <class T1, class Cont>
                friend bool operator< (const stack<T1,Cont>& lhs, const stack<T1,Cont>& rhs);
            template <class T1, class Cont>
                friend bool operator<= (const stack<T1,Cont>& lhs, const stack<T1,Cont>& rhs);
            template <class T1, class Cont>
                friend bool operator> (const stack<T1,Cont>& lhs, const stack<T1,Cont>& rhs);
            template <class T1, class Cont>
                friend bool operator>= (const stack<T1,Cont>& lhs, const stack<T1,Cont>& rhs);

    };
    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.container == rhs.container);
    }
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.container != rhs.container);
    }
    template <class T, class Container>
    bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.container < rhs.container);
    }
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.container <= rhs.container);
    }
    template <class T, class Container>
    bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.container > rhs.container);
    }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.container >= rhs.container);
    }

};

#endif