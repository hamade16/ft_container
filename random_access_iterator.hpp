#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>

template<class Iter>
class random_access_iterator{
    public:
        typedef Iter                                                       iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename Iter::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename iterator_traits<iterator_type>::pointer           pointer;
        typedef typename iterator_traits<iterator_type>::reference         reference;
        private:
            pointer it;


        random_access_iterator(random_access_iterator const & src);
        random_access_iterator();


        random_access_iterator    &operator=(random_access_iterator const & src)
        {
           
        }
        bool    &operator==(random_access_iterator const & src);
        bool    &operator!=(random_access_iterator const & src);
        bool    &operator++(random_access_iterator const & src);
        bool    &operator--(random_access_iterator const & src);
        bool    &operator<(random_access_iterator const & src);
        bool    &operator<=(random_access_iterator const & src);
        bool    &operator>(random_access_iterator const & src);
        bool    &operator>=(random_access_iterator const & src);
        bool    &operator+=(random_access_iterator const & src);
        bool    &operator-=(random_access_iterator const & src);
        bool    &operator[](random_access_iterator const & src);
};


#endif