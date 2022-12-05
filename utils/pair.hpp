#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

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
                template<class U, class V> 
                pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
                {
                }

                pair (const first_type& a, const seconde_type& b) : first(a), second(b)
                {}

                pair& operator= (const pair& pr)
                {
                    this->first = pr.first;
                    this->second = pr.second;
                    return *this;
                }
 };
        template <class T1, class T2>
          bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first==rhs.first && lhs.second==rhs.second; }
    
        template <class T1, class T2>
          bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs==rhs); }
    
        template <class T1, class T2>
          bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
    
        template <class T1, class T2>
          bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(rhs<lhs); }
    
        template <class T1, class T2>
          bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return rhs<lhs; }
    
        template <class T1, class T2>
          bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs<rhs); }


    template <class T1,class T2>
    ft::pair<T1,T2> make_pair (T1 x, T2 y)
    {
      ft::pair<T1, T2> p(x,y);
      return(p);
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
                int  balance_factor;
        };

}

#endif // !PAIR_HPP#define PAIR_HPP