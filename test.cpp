
#include <iostream>
//#include<map>
#include "pair.hpp"
#include "map.hpp"
int main()
{
    ft::map<int,int> ito;


    ft::map<int,int>::iterator it=ito.begin() ;
    ito.insert(ft::make_pair(1,44)) ;
    ito.insert(ft::make_pair(2,44)) ;
    ito.insert(ft::make_pair(3,44)) ;
    ito.insert(ft::make_pair(4,44)) ;


    ito.affiche2();


  //  if(ito.empty())
  //     std::cout << "hena"<<std::endl;
  //   else
  //     std::cout << "lhehih"<<"\n";


  



}