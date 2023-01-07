
#include <iostream>
//#include<map>
#include "pair.hpp"
#include "map.hpp"
int main()
{
    ft::map<int,int> ito;
    ft::map<int,int>::iterator it = ito.begin();

    ft::pair<int,int> f1;
    f1.first = 3;


    ito.insert(ft::make_pair(1,45)) ;
    ito.insert(ft::make_pair(2,12)) ;
    ito.insert(ft::make_pair(3,63)) ;
    ito.insert(ft::make_pair(4,12)) ;

    ito.affiche2();

    ft::map<int,int>::iterator a = ito.find(f1.first);
    std::cout << ito.count(f1.first) << "\n";
    ito.affiche2();
 
  



}