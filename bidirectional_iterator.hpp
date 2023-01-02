# pragma once
//# include "./iterator.hpp"
# include "./iterator_traits.hpp"
# include <iterator>
# include <iostream>

namespace ft
{

template<typename U, typename T>
class bidirectional_iterator : public ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >
{
	public:
        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::value_type			value_type;
        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::difference_type	difference_type;
        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::pointer			pointer;
        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::reference			reference;
        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::iterator_category	iterator_category;
	private:
		U	*pointer_iter;

	public:
		bidirectional_iterator(U *ptr = NULL) : pointer_iter(ptr)
		{
		}

		bidirectional_iterator(bidirectional_iterator const &rhs) : pointer_iter(rhs._iter)
		{
		}

		operator bidirectional_iterator<U, const value_type>()
		{
			return (bidirectional_iterator<U, const value_type>(this->pointer_iter));
		}

		value_type *base()
		{
			return (this->pointer_iter);
		}
	
		bool operator==(bidirectional_iterator const &rhs)
		{
			return (this->pointer_iter == rhs.pointer_iter);
		}

		bool operator!=(bidirectional_iterator const &rhs)
		{
			return (this->pointer_iter != rhs._iter);
		}

		reference	operator*() const
		{
			return (this->pointer_iter->operator*());
		}
		
		pointer	operator->() const
		{
			return &(this->operator*());
		}

		bidirectional_iterator &operator=(bidirectional_iterator const &rhs)
		{
			this->pointer_iter = rhs.pointer_iter;

			return ((*this));
		}

		bidirectional_iterator &operator++()
		{
			this->pointer_iter = this->pointer_iter->operator++();

			return (*this);
		}
		
		bidirectional_iterator operator++(int)
		{
			bidirectional_iterator tmp = *this;

			++(*this);
			return (tmp);
		}
		
		bidirectional_iterator &operator--()
		{
			this->pointer_iter = this->pointer_iter->operator--();

			return (*this);
		}

		bidirectional_iterator operator--(int)
		{
			bidirectional_iterator tmp = *this;

			--(*this);
			return (tmp);
		}
};

};