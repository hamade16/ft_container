#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>

template<class T>
class random_access_iterator{
    public:
        random_access_iterator(random_access_iterator const & src);
        random_access_iterator();


        random_access_iterator    &operator=(random_access_iterator const & src);
        random_access_iterator    &operator==(random_access_iterator const & src);
        random_access_iterator    &operator!=(random_access_iterator const & src);
        random_access_iterator    &operator++(random_access_iterator const & src);
        random_access_iterator    &operator--(random_access_iterator const & src);
        random_access_iterator    &operator<(random_access_iterator const & src);
        random_access_iterator    &operator<=(random_access_iterator const & src);
        random_access_iterator    &operator>(random_access_iterator const & src);
        random_access_iterator    &operator>=(random_access_iterator const & src);
        random_access_iterator    &operator+=(random_access_iterator const & src);
        random_access_iterator    &operator-=(random_access_iterator const & src);
        random_access_iterator    &operator[](random_access_iterator const & src);
};


#endif