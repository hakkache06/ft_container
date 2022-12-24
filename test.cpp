



#include "vector.hpp"
#include "iterator.hpp"    
#include "random_access_iterator.hpp" 
#include "reverse_iterator.hpp"
#include <iostream>

int main( )
{
    ft::vector<int> v1 = { 10, 20, 30, 40, 50 };
 
    // Declaring an iterator
    ft::vector<int>::iterator i1;
 
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
        // Assigning values to locations pointed by iterator
        *i1 = 7;
    }
 
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
        // Accessing values at locations pointed by iterator
        std::cout << (*i1) << " ";
    }


}