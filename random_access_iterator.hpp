# pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"
# include <iterator>

namespace ft
{
/*
Random-access iterators are iterators that can be used to access 
elements at an arbitrary offset position relative to the element they point to, offering the same functionality as pointers.
*/
template <typename T>
class random_access_iterator : public ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >
{
    public:
    /// Membre Type
        typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::value_type value_type;
        typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::difference_type difference_type;
        typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::pointer pointer;
        typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::reference reference;
        typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::iterator_category iterator_category;

    private:
        value_type *pointer_it;

    public:
        random_access_iterator(pointer ptr = nullptr) : pointer_it(ptr)
        {
            // default-constructible
        }

        explicit random_access_iterator(value_type &ptr) : pointer_it(&ptr)
        {
        }

        random_access_iterator(random_access_iterator const &rhs)
        {
            (*this) = rhs;
        }

        operator random_access_iterator<const value_type> ()
        {
            return (random_access_iterator<const value_type>(pointer_it));
        }

        value_type *p() const
        {
            return (this->pointer_it);
        }

        random_access_iterator &operator=(random_access_iterator const &rhs)
        {
            this->pointer_it = rhs.pointer_it;

            return (*this);
        }

        reference operator*(void) const
        {
            return ((*this->pointer_it));
        }

        pointer operator->(void) const
        {
            return (&(this->operator*()));
        }

        random_access_iterator &operator++(void)
        {
            ++this->pointer_it;

            return (*this);
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator tmp = *this;

            ++this->pointer_it;
            return (tmp);
        }

        random_access_iterator &operator--(void)
        {
            --this->pointer;

            return (*this);
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator tmp = *this ;

            --this->pointer_it;
            return (tmp);
        }

        random_access_iterator operator+(difference_type n) const
        {
            random_access_iterator tmp = *this;

            tmp.pointer_it += n;
            return (tmp);
        }

        random_access_iterator operator-(difference_type n) const
        {
            random_access_iterator tmp = *this ;

            tmp.pointer_it -= n;
            return (tmp);
        }

        template <typename Type>
        difference_type operator-(random_access_iterator<Type> const & src) const
        {
            return (this->pointer_it - src.pointer_it);
        }

        template <typename Type>
        difference_type operator+(random_access_iterator<Type> const & src) const
        {
            return (this->pointer_it + src.pointer_it);
        }

        random_access_iterator operator+=(difference_type n)
        {
            this->pointer_itr += n;

            return (*this);
        }
        
        random_access_iterator operator-=(difference_type n)
        {
            this->pointer_it -= n;

            return (*this);
        }

        reference operator[] (difference_type n)
		{
			return (*(this->pointer_it + n));
		}
};

// template <class Iterator>
// random_access_iterator<Iterator> operator+ (
// 	typename random_access_iterator<Iterator>::difference_type n,
// 	const random_access_iterator<Iterator>& it)
// {
// 	return (it + n);
// }

// template <class Iterator>
// random_access_iterator<Iterator> operator- (
// 	typename random_access_iterator<Iterator>::difference_type n,
// 	const random_access_iterator<Iterator>& it)
// {
// 	return (it - n);
// }

// template <class Iterator>
// bool operator==(
// 	const random_access_iterator<Iterator>& lhs,
// 	const random_access_iterator<Iterator>& rhs)
// {
// 	return (lhs.base() == rhs.base());
// }

// template <class Iterator>
// bool operator!= (
// 	const random_access_iterator<Iterator>& lhs,
//     const random_access_iterator<Iterator>& rhs)
// {
// 	return (lhs.base() != rhs.base());
// }

// template <class Iterator>
// bool operator< (
// 	const random_access_iterator<Iterator>& lhs,
//     const random_access_iterator<Iterator>& rhs)
// {
// 	return (lhs.base() < rhs.base());
// }

// template <class Iterator>
// bool operator<= (
// 	const random_access_iterator<Iterator>& lhs,
//     const random_access_iterator<Iterator>& rhs)
// {
// 	return (lhs.base() <= rhs.base());
// }

// template <class Iterator>
// bool operator> (
// 	const random_access_iterator<Iterator>& lhs,
//     const random_access_iterator<Iterator>& rhs)
// {
// 	return (lhs.base() > rhs.base());
// }

// template <class Iterator>
// bool operator>= (
// 	const random_access_iterator<Iterator>& lhs,
//     const random_access_iterator<Iterator>& rhs)
// {
// 	return (lhs.base() >= rhs.base());
// }

};