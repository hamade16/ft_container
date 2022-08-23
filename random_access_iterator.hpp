#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
namespace ft{
    template<class Iter>
    class random_access_iterator{

        public:
            typedef Iter                                                            iterator_type;
            typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename std::iterator_traits<iterator_type>::reference         reference;

            private:
                pointer it;

            public:
                random_access_iterator()
                {
                    it = NULL;
                }
                random_access_iterator(pointer p)
                {
                    it = p;
                }
                random_access_iterator(random_access_iterator const & src)
                {
                    this->it = src.it;
                }

                iterator_type base() const
                {
                    return it;
                }

                random_access_iterator    &operator=(random_access_iterator const & src)
                {
                    this->it = src.it;
                    return(*this);
                }
                bool    operator==(random_access_iterator const & src)
                {
                    if (this->it == src.it)
                        return true;
                    else
                        return false;
                }


                bool    operator!=(random_access_iterator const & src)
                {
                    if (this->it != src.it)
                        return true;
                    else
                        return false;
                }
                reference    operator*() const
                {
                    return *it;
                }
                void operator->()
                {
                    operator*();
                }
                random_access_iterator& operator++()
                {
                    this->it++;
                    return(*this);
                }

                random_access_iterator&  operator++(int)
                {
                    random_access_iterator *tmp = this;
                    ++this->it;
                    return (*tmp);
                }
                random_access_iterator operator+ (difference_type n) const
                {
                    return(this->it + n);
                }

                random_access_iterator& operator--()
                {
                    this->it--;
                    return (*this);
                }

                random_access_iterator&  operator--(int)
                {
                    random_access_iterator *tmp = this;
                    this->it--;
                    return (*tmp);
                }

                random_access_iterator operator- (difference_type n) const
                {
                    return(this->it - n);
                }

                random_access_iterator& operator+= (difference_type n)
                {
                    this->it += n;
                    return(*this);
                }

                random_access_iterator& operator-= (difference_type n)
                {
                    this->it -= n;
                    return(*this);
                }

                reference operator[] (difference_type n) const
                {
                    return *(this->it + n);
                }
                //bool    operator<(random_access_iterator const & src);
                //bool    operator<=(random_access_iterator const & src);
                //bool    operator>(random_access_iterator const & src);
                //bool    operator>=(random_access_iterator const & src);
    };
    template <class Iterator>
    random_access_iterator<Iterator> operator+ (
            typename random_access_iterator<Iterator>::difference_type n,
            const random_access_iterator<Iterator>& it)
            {
            //    return(it.base() + n);
                return (it + n);
            }
    template <class Iterator>
    typename random_access_iterator<Iterator>::difference_type operator- (
    const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() < rhs.base())
                        return true;
                    else
                        return false;
                   }

     bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() > rhs.base())
                        return true;
                    else
                        return false;
                   }

    template <class Iterator>
     bool operator>= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() >= rhs.base())
                         return true;
                     else
                         return false;
                    }

    template <class Iterator>
     bool operator<= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() <= rhs.base())
                         return true;
                     else
                         return false;
                    }

    
};

#endif