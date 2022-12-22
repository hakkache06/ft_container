
#include "random_access_iterator.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

using namespace std;


struct B { 
  using value_type = int; 
  using type = int;
};

template<class T>
void foo(typename T::type value)
{
  std::cout << "type";
}

template<class T>
void foo(typename T::value_type value)
{
    std::cout << "value_type";

}

int main () {
  
  foo<B>(3);
  return 0;
}