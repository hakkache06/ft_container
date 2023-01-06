#include "map.hpp"
#include "pair.hpp"
#include <iostream>
#include<map>

int main()
{
    //ft::map<int,int> ito;

    // ft::pair<int,int> f1;
    // f1 = ft::make_pair(1,44);
    // ito.insertmap(ft::make_pair(1,12)) ;
    // ito.insertmap(ft::make_pair(2,44)) ;
    // ito.insertmap(ft::make_pair(3,44)) ;
    // ito.insertmap(ft::make_pair(4,44)) ;
    // ito.insertmap(ft::make_pair(5,44)) ;

    // ito.insertmap(ft::make_pair(0,44)) ;

    
    // ito.affiche2();

    
    // ft::map<int,int>::iterator ita=ito.begin();
    // std::cout << ita->first << " => " << ita->second << '\n';
    //   ita--;
    // std::cout << ita->first << " p => " << ita->second << '\n';
    //   ita++;
    // std::cout << ita->first << " p => " << ita->second << '\n';
      
  

  // pair<iterator,bool> insert (const value_type& val);
    // mymap.insert ( std::pair<char,int>('a',100) );
  // first insert function version (single parameter):
    // mymap.insert ( std::pair<char,int>('z',200) );
    // std::pair<std::map<char,int>::iterator,bool> ret;
    // ret = mymap.insert ( std::pair<char,int>('o',500) );
    // if (ret.second==false)
    // {
    //   std::cout << "element 'z' already existed";
    //   std::cout << " with a value of " << ret.second << '\n';
    // }
    // else
    // {
    // std::cout << ret.second << '\n';
    // }
  /////////////////////////////////////////////////////
  // iterator insert (iterator position, const value_type& val);

  ft::map<int,int> mymap;
  ft::map<int ,int >::iterator it = mymap.begin();
  mymap.insert(it,ft::make_pair(3,20));
  mymap.insert(it,ft::make_pair(1,20));
  mymap.insert(it,ft::make_pair(2,20));

  mymap.affiche2();
    // mymap.insert(it,std::pair<char,int>('s',300));
    // mymap.insert(it,std::pair<char,int>('d',300));
    // mymap.insert(it,std::pair<char,int>('g',300));
    // mymap.insert(it,std::pair<char,int>('h',300));
    // mymap.insert(it,std::pair<char,int>('l',300));
    // mymap.insert(it,std::pair<char,int>('k',300));
    // std::cout << it->first <<  std::endl;
  /// kayd7ko 3lina lah yhdihom
}