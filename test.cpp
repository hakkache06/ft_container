#include "map.hpp"
#include "pair.hpp"
#include <iostream>
#include<map>

int main()
{
    ft::map<int,int> ito;

    // ft::pair<int,int> f1;
    // f1 = ft::make_pair(1,44);
    ito.insertmap(ft::make_pair(1,12)) ;
    ito.insertmap(ft::make_pair(2,44)) ;
    ito.insertmap(ft::make_pair(3,44)) ;
    ito.insertmap(ft::make_pair(4,44)) ;
    ito.insertmap(ft::make_pair(5,44)) ;

    ito.insertmap(ft::make_pair(0,44)) ;

    
    ito.affiche2();

    
     ft::map<int,int>::iterator ita=ito.begin();
    std::cout << ita->first << " => " << ita->second << '\n';
      ita++;
      ita++;
      ita++;
      ita++;

    ita--;
    ita--;
    ita--;
    ita--;
    std::cout << ita->first << " p => " << ita->second << '\n';

        

  std::map<int,int> mymap;
  mymap[1] = 100;
  mymap[2] = 200;
  mymap[3] = 300;
  mymap[4] = 300;
  mymap[5] = 300;
  mymap[0] = 300;


  // show content:
   std::map<int,int>::iterator it = mymap.begin();
    std::cout << it->first<< '\n';
    it++;
    it++;
    it++;
    it++;

    it--;
    it--;
    it--;
    it--;
  
    //it--;
   std::cout << it->first<< '\n';
  
}