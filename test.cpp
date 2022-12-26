#include <iostream>





int main()
{

    int a[5] = {0,1,2,3,4};

      for(int *it = a ;  it!= a+5 ; ++it)
            std::cout << *it << std::endl;  



}

