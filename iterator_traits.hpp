
///  Traits class defining properties of iterators.
//Note that any custom class will have a valid instantiation of iterator_traits if it publicly inherits the base class std::iterator.

# pragma once

namespace ft
{

template <class iterator>
struct iterator_traits {

	typedef typename iterator::value_type			value_type; // The type of the element the iterator can point to.
	typedef typename iterator::difference_type		difference_type; // Type to express the result of subtracting one iterator from another.
	typedef typename iterator::iterator_category	iterator_category; //  random_access_iterator_tag // 
	typedef typename iterator::pointer				pointer; // The type of a pointer to an element the iterator can point to.
	typedef typename iterator::reference			reference; // The type of a reference to an element the iterator can point to.

};

};
