
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
		iterator_type	pointer;

    public:
    // Member functions
        		reverse_iterator() : pointer() {}
                /*
                    Constructs a reverse iterator that points to no object.
                */
               explicit	reverse_iterator (iterator_type it) : pointer(it)
		       {
		       }
               // Copy
            template <class U>
  		    reverse_iterator (const reverse_iterator<U>& u) : pointer(u.base())
		    {
		    }
            // return copy of the base iterator
            iterator_type base() const
		    {
			return (this->_iter);
		    }
            // Returns a reference to the element pointed to by the iterator.
            reference operator*() const
		    {
			    iterator_type it(this->pointer);
			return (*(--it));
		    }
            // Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to.
            reverse_iterator operator+(difference_type n) const
		    {
			    return (reverse_iterator(this->pointer - n));
		    }
            // Increment iterator position
            reverse_iterator& operator++()
		    {
			    --this->_iter;
			    return (*this);
		    }




};



}