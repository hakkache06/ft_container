
#include "random_access_iterator.hpp"

#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

using namespace std;

int main () {
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

  typedef std::vector<int>::iterator iter_type;



  return 0;
}