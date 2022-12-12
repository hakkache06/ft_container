# pragma once

# include <memory>
# include <stdexcept>

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector
{
    private:
    // les attrubites
        value_type		*_v;
	    size_type		_capacity;
	    size_type		_size;
	    allocator_type	_alloc;
    public:
    // Member types


};


}
