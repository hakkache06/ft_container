
///  Traits class defining properties of iterators.
# pragma once

namespace ft
{

template <class iterator>
struct iterator_traits {

	typedef typename iterator::value_type			value_type;
	typedef typename iterator::difference_type		difference_type;
	typedef typename iterator::iterator_category	iterator_category;
	typedef typename iterator::pointer				pointer;
	typedef typename iterator::reference			reference;
};

};
