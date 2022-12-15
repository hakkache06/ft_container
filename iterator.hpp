
/// This is a base class template that can be used to derive iterator classes from it
// In C++, we can use multiple template parameters and even use default arguments for those parameters.

//An iterator is any object that, pointing to some element in a range of elements 
//(such as an array or a container), has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) and dereference (*) operators).


# pragma once
#include <cstddef>
namespace ft
{

template <
		class Category,  // Category to which the iterator belongs to. It must be one of the following iterator tags:
                 
        class T,    // Type of elements pointed by the iterator.       
        class Distance = std::ptrdiff_t,// Alias of one of the fundamental signed integer types  // Type to represent the difference between two iterators.
        class Pointer = T*,    // Type to represent a pointer to an element pointed by the iterator.           
        class Reference = T&   // Type to represent a reference to an element pointed by the iterator.
          
        >
class iterator
{

  public:
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
  };


};