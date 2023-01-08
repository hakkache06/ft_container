
#include <iostream>
//#include<map>
#include "pair.hpp"
#include "map.hpp"
int main()
{
    ft::map<int,int> ito;

    ft::pair<int,int> f1;
    f1.first = 21;
    ito.insert(ft::make_pair(1,45)) ;
    ito.insert(ft::make_pair(2,12)) ;
    ito.insert(ft::make_pair(3,63)) ;
    ito.insert(ft::make_pair(4,12)) ;
    ito.insert(ft::make_pair(20,12)) ;
    ito.insert(ft::make_pair(21,12)) ;


    //ito.affiche2();

    ft::map<int,int>::iterator a = ito.lower_bound(20);
    std::cout << a->first << std::endl;
 
  



}