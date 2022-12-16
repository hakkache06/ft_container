
#include "reverse_iterator.hpp"

#include <iostream>
#include <vector> 
using namespace std;
int main()
{

	std::vector<int> myvector;
  		for (int i=0; i<10; i++) myvector.push_back(i);

      ft::reverse_iterator<std::vector<int>::iterator> from,until;
        from = myvector.rbegin();
         until = myvector.rend();
}