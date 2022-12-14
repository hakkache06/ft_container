# pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"
namespace ft
{

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
        value_type *pointer;

    public:
        random_access_iterator(pointer ptr = nullptr) : pointer(ptr)
        {
            // default-constructible
        }

        explicit random_access_iterator(value_type &ptr) : pointer(&ptr)
        {
        }

        random_access_iterator(random_access_iterator const &rhs)
        {
            (*this) = rhs;
        }

        operator random_access_iterator<const value_type> ()
        {
            return (random_access_iterator<const value_type>(pointer));
        }

        value_type *p() const
        {
            return (this->pointer);
        }

///////////
    public:
        random_access_iterator &operator=(random_access_iterator const &rhs)
        {
            this->pointer = rhs._iter;

            return (*this);
        }

        reference operator*(void) const
        {
            return ((*this->pointer));
        }

        pointer operator->(void) const
        {
            return (&(this->operator*()));
        }

        random_access_iterator &operator++(void)
        {
            ++this->pointer;

            return (*this);
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator tmp(*this);

            ++this->pointerr;
            return (tmp);
        }

        random_access_iterator &operator--(void)
        {
            --this->pointer;

            return (*this);
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator tmp(*this);

            --this->pointer;
            return (tmp);
        }

        random_access_iterator operator+(difference_type n) const
        {
            random_access_iterator tmp((*this));

            tmp.pointer += n;
            return (tmp);
        }

        random_access_iterator operator-(difference_type n) const
        {
            random_access_iterator tmp((*this));

            tmp.pointerr -= n;
            return (tmp);
        }

        template <typename Type>
        difference_type operator-(random_access_iterator<Type> const & src) const
        {
            return (this->pointer - src.pointer);
        }

        template <typename Type>
        difference_type operator+(random_access_iterator<Type> const & src) const
        {
            return (this->pointer + src.pointer);
        }

        random_access_iterator operator+=(difference_type n)
        {
            this->pointer += n;

            return (*this);
        }
        
        random_access_iterator operator-=(difference_type n)
        {
            this->pointer -= n;

            return (*this);
        }

        reference operator[] (difference_type n)
		{
			return (*(this->_iter + n));
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
random_access_iterator<Iterator> operator- (
	typename random_access_iterator<Iterator>::difference_type n,
	const random_access_iterator<Iterator>& it)
{
	return (it - n);
}

template <class Iterator>
bool operator==(
	const random_access_iterator<Iterator>& lhs,
	const random_access_iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!= (
	const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool operator< (
	const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator>
bool operator<= (
	const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
bool operator> (
	const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool operator>= (
	const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}

};