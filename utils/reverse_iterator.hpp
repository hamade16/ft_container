
#pragma once
#include "iterator_traits.hpp"
namespace ft
{
    template <class InputIterator>
    class reverse_iterator
    {
        public:
            typedef InputIterator                                                iterator_type;
            //typedef	typename iterator_traits<iterator>::iterator_category	iterator_category;
            //typedef	typename iterator_traits<iterator>::value_type			value_type;
            typedef	typename iterator_traits<InputIterator>::pointer				pointer;
            typedef	typename iterator_traits<InputIterator>::reference			reference;
            typedef	typename iterator_traits<InputIterator>::difference_type		difference_type;
        private:
            iterator_type base_it;
        public:
            reverse_iterator(){}
            explicit reverse_iterator(iterator_type it)
            {
                base_it = it;
            }
            template<class Iter>
                reverse_iterator(const reverse_iterator<Iter>& rev_it)
                {
                    base_it = rev_it.base();
                }
            iterator_type 	base() const { return base_it;}
            reference operator*() const
            {
                iterator_type tmp = base_it;
                return (*(--tmp));
            }
            pointer operator->() const
            {
                iterator_type tmp = base_it;

                return ((--tmp).operator->());
            }
            reverse_iterator operator--(){ return reverse_iterator(++base_it);}
            reverse_iterator operator++(){ return reverse_iterator(--base_it);}
            reverse_iterator operator--(int){ return reverse_iterator(base_it++);}
            reverse_iterator operator++(int){ return reverse_iterator(base_it--);}
            bool operator == (const reverse_iterator &rhs) const {return this->base() == rhs.base();}
            bool operator != (const reverse_iterator &rhs) const {return this->base() != rhs.base();}
            bool operator < (const reverse_iterator &rhs) const {return this->base() > rhs.base();}
            bool operator > (const reverse_iterator &rhs) const {return this->base() < rhs.base();}
            bool operator >= (const reverse_iterator &rhs) const {return this->base() <= rhs.base();}
            bool operator <= (const reverse_iterator &rhs) const {return this->base() >= rhs.base();}
    
            reverse_iterator operator+(difference_type n) const {return reverse_iterator(base_it - n);}
            reverse_iterator operator-(difference_type n) const {return reverse_iterator(base_it + n);}
            reverse_iterator operator+(const reverse_iterator &rhs) const {return reverse_iterator(this->base_it + rhs.base_it);}

            reverse_iterator operator+=(difference_type n)
            {
                this->base_it -= n;
                return *this;
            }
            reverse_iterator operator-=(difference_type n)
            {
                this->base_it += n;
                return *this;
            }
            reference operator[](difference_type n) const
            {
                const iterator_type	tmp = this->base_it - 1;

                return (tmp[-n]);
            }
    };
    template<class InputIterator>
        reverse_iterator<InputIterator> operator+(typename reverse_iterator<InputIterator>::difference_type n, reverse_iterator<InputIterator> &rhs){return rhs + n;}
    template <class InputIterator>
        typename reverse_iterator<InputIterator>::difference_type operator- (const reverse_iterator<InputIterator>& lhs,
    const reverse_iterator<InputIterator>& rhs)
    {
        return rhs.base() - lhs.base();
    }
}
