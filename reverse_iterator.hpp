
# pragma once

#include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator
{
	public:
    // Member types
		typedef	Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
	private:
		iterator_type	pointer_it;

    public:
    // Member functions
        		reverse_iterator() : pointer_it() {}
                /*
                    Constructs a reverse iterator that points to no object.
                */
               explicit	reverse_iterator (iterator_type it) : pointer_it(it)
		       {
		       }
               // Copy
            template <class U>
  		    reverse_iterator (const reverse_iterator<U>& u) : pointer_it(u.base())
		    {
		    }
            // return copy of the base iterator
            iterator_type base() const
		    {
			return (this->pointer_it);
		    }

            // Returns a reference to the element pointed to by the iterator.
			// Member type reference is an alias of the base iterator's own reference type.
			// Dereference iterator
            reference operator*() const
		    {
			    iterator_type it(this->pointer_it);
			    return (*(--it));
		    }

            // Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to.
			// An iterator pointing to the element n positions away.

            reverse_iterator operator+(difference_type n) const
		    {
			    return (reverse_iterator(this->pointer_it - n));
		    }
			// Increment iterator position
			// 1 - post-increment returns *this.
			// 2 - pre-increment returns the value *this had before the call

			// post-increment
			reverse_iterator  operator++(int)
			{
				reverse_iterator it(*this);
				--this->pointer_it;
				return (it);
			}
			// pre-increment
			reverse_iterator& operator++()
			{
			--this->pointer_it;
			return (*this);
			}
			// Advances the reverse_iterator by n element positions.
			// return The reverse iterator itself (*this).
			reverse_iterator& operator+= (difference_type n)
			{
				this->pointer_it -= n;
				return (*this);
			}

			// Subtraction operator
			// Returns a reverse iterator pointing to the element located n positions before the element the iterator currently points to.
			reverse_iterator operator- (difference_type n) const
			{
				return (reverse_iterator(this->pointer_it + n));
			}

			reverse_iterator &operator=(reverse_iterator const &rhs)
			{
				this->pointer_it = rhs.base();
				return (*this);
			}

			// Decreases the reverse_iterator by one position.
			// The pre-decrement version (1) returns *this.
			// The post-decrement version (2) returns the value *this had before the call.
				// post-increment
			reverse_iterator  operator--(int)
			{
				reverse_iterator it (*this);
				++this->pointer_it;
				return (it);
			}
			// pre-increment
			reverse_iterator& operator--()
			{
				++this->pointer_itr;
				return (*this);
			}
			// Retrocede iterator
			// Descreases the reverse_iterator by n element positions.
			// The reverse iterator itself (*this).
			reverse_iterator& operator-= (difference_type n)
			{
				this->pointer_it += n;
				return (*this);
			}
			// Dereference iterator
			// Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
			// Internally, the function calls operator* and returns its address, as if implemented as:
			pointer operator->() const
			{
				return (&this->operator*());
			}
			// Dereference iterator with offset
			//Accesses the element located n positions away from the element currently pointed to by the iterator.
			// If such an element does not exist, it causes undefined behavior.
			// A reference to the element n positions away from the element currently pointed by the iterator.
			//Member type reference is an alias of the base iterator's own reference type.	
			reference operator[] (difference_type n) const
			{
				return (this->base()[-n - 1]);
			}

	

};

//relational operators (reverse_iterator)
/*
operator on
reverse iterators	equivalent used onbase iterators
==						==
!=						!=
<						>
<=						>=
>						<
>=						<=

*/
	template <class Iterator>
	bool operator==(
	const reverse_iterator<Iterator>& x,
	const reverse_iterator<Iterator>& y)
	{
		return (x.base() == y.base());
	}

	template <class Iterator>
	bool operator!= (
		const reverse_iterator<Iterator>& x,
    	const reverse_iterator<Iterator>& y)
	{
		return (x.base() != y.base());
	}

	template <class Iterator>
	bool operator< (
		const reverse_iterator<Iterator>& x,
    	const reverse_iterator<Iterator>& y)
	{
		return (x.base() > y.base());
	}

	template <class Iterator>
	bool operator<= (
		const reverse_iterator<Iterator>& x,
    	const reverse_iterator<Iterator>& y)
	{
		return (x.base() >= y.base());
	}

	template <class Iterator>
	bool operator> (
		const reverse_iterator<Iterator>& x,
    	const reverse_iterator<Iterator>& y)
	{
		return (x.base() < y.base());
	}

	template <class Iterator>
	bool operator>= (
		const reverse_iterator<Iterator>& x,
    const reverse_iterator<Iterator>& y)
	{
		return (x.base() <= y.base());
	}

	// addition operator template function
	//Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it.

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

///Returns the distance between lhs and rhs.

	template <class Iterator>
	reverse_iterator<Iterator> operator- (
	const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rev_it)
	{
		return (lhs - rev_it);
	}

	
};

/*

member	definition in reverse_iterator	description
iterator_type	Iterator	Iterator's type
iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
value_type	iterator_traits<Iterator>::value_type	Preserves Iterator's value type
difference_type	iterator_traits<Iterator>::difference_type	Preserves Iterator's difference type
pointer	iterator_traits<Iterator>::pointer	Preserves Iterator's pointer type
reference	iterator_traits<Iterator>::reference	Preserves Iterator's reference type

*/
