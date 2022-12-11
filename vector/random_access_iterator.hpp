#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
namespace ft{
    template<class Iter>
    class random_access_iterator{

        public:
            typedef Iter                iterator_type;
            typedef Iter*                pointer;
            typedef Iter&                reference;
            typedef std::ptrdiff_t       difference_type;
            //typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;

            private:
                pointer it;

            public:
                random_access_iterator()
                {
                    it = NULL;
                }
                explicit random_access_iterator(pointer p)
                {
                    it = p;
                }
                template<class TT>
                random_access_iterator(random_access_iterator<TT> const & src)
                {
                    this->it = src.base();
                }

                random_access_iterator(const random_access_iterator &it)
                {
                    *this = it;
                }

                pointer base() const
                {
                    return it;
                }

                random_access_iterator    &operator=(random_access_iterator const & src)
                {
                    this->it = src.base();
                    return(*this);
                }
                bool    operator==(random_access_iterator const & src)
                {
                    if (this->it == src.it)
                        return true;
                    else
                        return false;
                }

                bool    operator>(random_access_iterator const & src)
                {
                    if (this->it > src.it)
                        return true;
                    else
                        return false;
                }

                 bool    operator<(random_access_iterator const & src)
                {
                    if (this->it < src.it)
                        return true;
                    else
                        return false;
                }


                 bool    operator>=(random_access_iterator const & src)
                {
                    if (this->it >= src.it)
                        return true;
                    else
                        return false;
                }


                 bool    operator<=(random_access_iterator const & src)
                {
                    if (this->it <= src.it)
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
                    return (*it);
                }
                pointer operator->() const
                {
                    return &(operator*());
                }
                random_access_iterator& operator++()
                {
                    ++this->it;
                    return(*this);
                }

                random_access_iterator  operator++(int)
                {
                    random_access_iterator tmp = *this;
                    ++this->it;
                    return (tmp);
                }
                random_access_iterator operator+ (difference_type n) const
                {
                    return(random_access_iterator(this->it + n));
                }

                random_access_iterator& operator--()
                {
                    --this->it;
                    return (*this);
                }

                random_access_iterator  operator--(int)
                {
                    random_access_iterator tmp = *this;
                    --this->it;
                    return (tmp);
                }

                random_access_iterator operator- (difference_type n) const
                {
                    return(random_access_iterator(this->it - n));
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
    };
    template <class Iterator>
    random_access_iterator<Iterator> operator+ (
            typename random_access_iterator<Iterator>::difference_type n,
            const random_access_iterator<Iterator>& it)
            {
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
  bool operator<  (const random_access_iterator<Iterator>& lhs,
                   const random_access_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() < rhs.base())
                        return true;
                    else
                        return false;
                   }
      template <class Iterator>
     bool operator>  (const random_access_iterator<Iterator>& lhs,
                   const    random_access_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() > rhs.base())
                        return true;
                    else
                        return false;
                   }

    template <class Iterator>
     bool operator>= (const random_access_iterator<Iterator>& lhs,
                    const   random_access_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() >= rhs.base())
                         return true;
                     else
                         return false;
                    }

    template <class Iterator>
     bool operator<= (const random_access_iterator<Iterator>& lhs,
                    const   random_access_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() <= rhs.base())
                         return true;
                     else
                         return false;
                    }

    
};

#endif