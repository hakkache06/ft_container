
#include "random_access_iterator.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

using namespace std;


struct A { using type = int; };

struct C
{
  using value_type = int;
  //using type = int;
};


template<class T>
void foo(typename T::type value)
{
   std::cout << "value " << std::endl;
}

template<class T>
void foo(typename T::value_type value)
{

   std::cout << "value_type " << std::endl;
}

int main () {
  
  foo<C>(3);
  return 0;
}