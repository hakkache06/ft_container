
#include "random_access_iterator.hpp"

#include <iostream>     // std::cout
#include "iterator.hpp"    // std::reverse_iterator
#include "Vector.hpp"       // std::vector

using namespace std;



int main () {

   ft::Vector <int> v1;

   v1.push_back( 10 );
   v1.push_back( 20 );

   const int &i = v1.at( 0 );
   int &j = v1.at( 1 );
   cout << "The first element is " << i << endl;
   cout << "The second element is " << j << endl;
}